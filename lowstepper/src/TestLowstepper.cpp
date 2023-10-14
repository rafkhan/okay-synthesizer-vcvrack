#include "plugin.hpp"
#include "lowstepper/LowStepperLfo.h"

LowStepperOutput lastOutputA; // Default constructed to all fields as 0
LowStepperLfo* lfoA = nullptr;

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
		}
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