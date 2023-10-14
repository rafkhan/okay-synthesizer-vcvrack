#include "plugin.hpp"
#include "lowstepper/LowStepperLfo.h"

LowStepperOutput lastOutputA; // Default constructed to all fields as 0
LowStepperLfo* lfoA = nullptr;
float phase = 0.f;

struct TestLowstepper : Module {
	enum ParamId {
		PITCH_PARAM,
		PARAMS_LEN
	};
	enum InputId {
		PITCH_INPUT,
		INPUTS_LEN
	};
	enum OutputId {
		SINE_OUTPUT,
		OUTPUTS_LEN
	};
	enum LightId {
		BLINK_LIGHT,
		LIGHTS_LEN
	};

	TestLowstepper() {
		config(PARAMS_LEN, INPUTS_LEN, OUTPUTS_LEN, LIGHTS_LEN);
		configParam(PITCH_PARAM, 0.f, 1.f, 0.f, "Morph");
		configInput(PITCH_INPUT, "Morph Input");
		configOutput(SINE_OUTPUT, "Output");
	}

	void process(const ProcessArgs& args) override {
		if(lfoA == nullptr) {
			INFO("Initializing lowstepper with sample rate of %fhz", args.sampleRate);
			lfoA = new LowStepperLfo(args.sampleRate);
		}		const float morphPot = getInput(PITCH_INPUT).getVoltage();

		// Below here is all temporary.

		// When cv is not plugged in, it has a default value of 0.5. Value must be 
		float morphCv = getInput(PITCH_INPUT).isConnected() ? getInput(PITCH_INPUT).getVoltage() : 0.5;
		if(morphCv > 1 || morphCv < 0) {
			INFO("morph cv is out of range %f", morphCv);
			morphCv = 0.5;
		}

		LowStepperInput inputA;
		inputA.phase = lastOutputA.phase;
		inputA.frequency = LowStepperLfo::mapRateInputToFrequency(1, false, LowStepperLfoMode::MEDIUM, 120);
		inputA.morph = LowStepperLfo::mapMorphInput(combinePotAndCv(morphPot, morphCv));
		inputA.start = 0;
		inputA.end = 0;
		inputA.shouldReset = false;

		lastOutputA = lfoA->tick(inputA);
		
		float freq = dsp::FREQ_C4 * std::pow(2.f, inputA.morph);

		// Accumulate the phase
		phase += freq * args.sampleTime / 4.f;
		if (phase >= 1.f)
			phase -= 1.f;

		// Compute the sine output
		float sine = std::sin(2.f * M_PI * phase);
		getOutput(SINE_OUTPUT).setVoltage(5.f * sine);
	}
};


struct TestLowstepperWidget : ModuleWidget {
	TestLowstepperWidget(TestLowstepper* module) {
		setModule(module);
		setPanel(createPanel(asset::plugin(pluginInstance, "res/TestLowstepper.svg")));

		addChild(createWidget<ScrewSilver>(Vec(RACK_GRID_WIDTH, 0)));
		addChild(createWidget<ScrewSilver>(Vec(box.size.x - 2 * RACK_GRID_WIDTH, 0)));
		addChild(createWidget<ScrewSilver>(Vec(RACK_GRID_WIDTH, RACK_GRID_HEIGHT - RACK_GRID_WIDTH)));
		addChild(createWidget<ScrewSilver>(Vec(box.size.x - 2 * RACK_GRID_WIDTH, RACK_GRID_HEIGHT - RACK_GRID_WIDTH)));

		addParam(createParamCentered<RoundBlackKnob>(mm2px(Vec(15.24, 46.063)), module, TestLowstepper::PITCH_PARAM));

		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(15.24, 77.478)), module, TestLowstepper::PITCH_INPUT));

		addOutput(createOutputCentered<PJ301MPort>(mm2px(Vec(15.24, 108.713)), module, TestLowstepper::SINE_OUTPUT));

		addChild(createLightCentered<MediumLight<RedLight>>(mm2px(Vec(15.24, 25.81)), module, TestLowstepper::BLINK_LIGHT));
	}
};


Model* modelTestLowstepper = createModel<TestLowstepper, TestLowstepperWidget>("TestLowstepper");