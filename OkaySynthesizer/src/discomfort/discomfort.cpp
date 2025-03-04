#include "../plugin.hpp"
#include "discomfort/Discomfort.h"


struct Discomfort : Module {
	enum ParamId {
		IN_GAIN_PARAM,
		FOLD_MIX_KNOB_PARAM,
		DIST_MIX_KNOB_PARAM,
		OUT_GAIN_PARAM,
		FOLD_A_KNOB_PARAM,
		DIST_A_KNOB_PARAM,
		ENV_GAIN_PARAM,
		FOLD_B_KNOB_PARAM,
		DIST_B_KNOB_PARAM,
		ENV_ATTACK_PARAM,
		FOLD_C_KNOB_PARAM,
		DIST_C_KNOB_PARAM,
		ENV_DECAY_PARAM,
		FOLD_ENV_CV_PARAM,
		DIST_ENV_CV_PARAM,
		PARAMS_LEN
	};
	enum InputId {
		IN_L_INPUT,
		IN_R_INPUT,
		FOLD_MIX_CV_INPUT,
		DIST_MIX_CV_INPUT,
		OUT_L_INPUT,
		OUT_R_INPUT,
		FOLD_A_CV_INPUT,
		DIST_A_CV_INPUT,
		FOLD_B_CV_INPUT,
		DIST_B_CV_INPUT,
		FOLD_C_CV_INPUT,
		DIST_C_CV_INPUT,
		INPUTS_LEN
	};
	enum OutputId {
		ENV_OUT_OUTPUT,
		OUTPUTS_LEN
	};
	enum LightId {
		LIGHTS_LEN
	};

	Discomfort() {
		config(PARAMS_LEN, INPUTS_LEN, OUTPUTS_LEN, LIGHTS_LEN);
		configParam(IN_GAIN_PARAM, 0.f, 1.f, 0.f, "");
		configParam(FOLD_MIX_KNOB_PARAM, 0.f, 1.f, 0.f, "");
		configParam(DIST_MIX_KNOB_PARAM, 0.f, 1.f, 0.f, "");
		configParam(OUT_GAIN_PARAM, 0.f, 1.f, 0.f, "");
		configParam(FOLD_A_KNOB_PARAM, 0.f, 1.f, 0.f, "");
		configParam(DIST_A_KNOB_PARAM, 0.f, 1.f, 0.f, "");
		configParam(ENV_GAIN_PARAM, 0.f, 1.f, 0.f, "");
		configParam(FOLD_B_KNOB_PARAM, 0.f, 1.f, 0.f, "");
		configParam(DIST_B_KNOB_PARAM, 0.f, 1.f, 0.f, "");
		configParam(ENV_ATTACK_PARAM, 0.f, 1.f, 0.f, "");
		configParam(FOLD_C_KNOB_PARAM, 0.f, 1.f, 0.f, "");
		configParam(DIST_C_KNOB_PARAM, 0.f, 1.f, 0.f, "");
		configParam(ENV_DECAY_PARAM, 0.f, 1.f, 0.f, "");
		configParam(FOLD_ENV_CV_PARAM, 0.f, 1.f, 0.f, "");
		configParam(DIST_ENV_CV_PARAM, 0.f, 1.f, 0.f, "");
		configInput(IN_L_INPUT, "");
		configInput(IN_R_INPUT, "");
		configInput(FOLD_MIX_CV_INPUT, "");
		configInput(DIST_MIX_CV_INPUT, "");
		configInput(OUT_L_INPUT, "");
		configInput(OUT_R_INPUT, "");
		configInput(FOLD_A_CV_INPUT, "");
		configInput(DIST_A_CV_INPUT, "");
		configInput(FOLD_B_CV_INPUT, "");
		configInput(DIST_B_CV_INPUT, "");
		configInput(FOLD_C_CV_INPUT, "");
		configInput(DIST_C_CV_INPUT, "");
		configOutput(ENV_OUT_OUTPUT, "");
	}

	void process(const ProcessArgs& args) override {
	}
};


struct DiscomfortWidget : ModuleWidget {
	DiscomfortWidget(Discomfort* module) {
		setModule(module);
		setPanel(createPanel(asset::plugin(pluginInstance, "res/discomfort.svg")));

		addChild(createWidget<ScrewSilver>(Vec(RACK_GRID_WIDTH, 0)));
		addChild(createWidget<ScrewSilver>(Vec(box.size.x - 2 * RACK_GRID_WIDTH, 0)));
		addChild(createWidget<ScrewSilver>(Vec(RACK_GRID_WIDTH, RACK_GRID_HEIGHT - RACK_GRID_WIDTH)));
		addChild(createWidget<ScrewSilver>(Vec(box.size.x - 2 * RACK_GRID_WIDTH, RACK_GRID_HEIGHT - RACK_GRID_WIDTH)));

		addParam(createParamCentered<RoundBlackKnob>(mm2px(Vec(10.46, 43.078)), module, Discomfort::IN_GAIN_PARAM));
		addParam(createParamCentered<RoundBlackKnob>(mm2px(Vec(33.056, 43.078)), module, Discomfort::FOLD_MIX_KNOB_PARAM));
		addParam(createParamCentered<RoundBlackKnob>(mm2px(Vec(47.761, 43.078)), module, Discomfort::DIST_MIX_KNOB_PARAM));
		addParam(createParamCentered<RoundBlackKnob>(mm2px(Vec(81.219, 43.078)), module, Discomfort::OUT_GAIN_PARAM));
		addParam(createParamCentered<RoundBlackKnob>(mm2px(Vec(6.828, 59.304)), module, Discomfort::FOLD_A_KNOB_PARAM));
		addParam(createParamCentered<RoundBlackKnob>(mm2px(Vec(82.403, 58.666)), module, Discomfort::DIST_A_KNOB_PARAM));
		addParam(createParamCentered<RoundBlackKnob>(mm2px(Vec(43.565, 73.938)), module, Discomfort::ENV_GAIN_PARAM));
		addParam(createParamCentered<RoundBlackKnob>(mm2px(Vec(6.798, 75.247)), module, Discomfort::FOLD_B_KNOB_PARAM));
		addParam(createParamCentered<RoundBlackKnob>(mm2px(Vec(82.714, 74.513)), module, Discomfort::DIST_B_KNOB_PARAM));
		addParam(createParamCentered<RoundBlackKnob>(mm2px(Vec(43.876, 89.786)), module, Discomfort::ENV_ATTACK_PARAM));
		addParam(createParamCentered<RoundBlackKnob>(mm2px(Vec(6.764, 92.805)), module, Discomfort::FOLD_C_KNOB_PARAM));
		addParam(createParamCentered<RoundBlackKnob>(mm2px(Vec(82.774, 92.13)), module, Discomfort::DIST_C_KNOB_PARAM));
		addParam(createParamCentered<RoundBlackKnob>(mm2px(Vec(43.936, 107.402)), module, Discomfort::ENV_DECAY_PARAM));
		addParam(createParamCentered<RoundBlackKnob>(mm2px(Vec(9.035, 110.014)), module, Discomfort::FOLD_ENV_CV_PARAM));
		addParam(createParamCentered<RoundBlackKnob>(mm2px(Vec(81.876, 109.776)), module, Discomfort::DIST_ENV_CV_PARAM));

		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(10.46, 22.415)), module, Discomfort::IN_L_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(22.334, 22.415)), module, Discomfort::IN_R_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(34.209, 22.415)), module, Discomfort::FOLD_MIX_CV_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(46.084, 22.415)), module, Discomfort::DIST_MIX_CV_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(69.833, 22.415)), module, Discomfort::OUT_L_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(81.708, 22.415)), module, Discomfort::OUT_R_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(19.197, 59.023)), module, Discomfort::FOLD_A_CV_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(70.815, 58.563)), module, Discomfort::DIST_A_CV_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(19.078, 74.965)), module, Discomfort::FOLD_B_CV_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(70.809, 74.589)), module, Discomfort::DIST_B_CV_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(18.813, 92.59)), module, Discomfort::FOLD_C_CV_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(70.741, 92.078)), module, Discomfort::DIST_C_CV_INPUT));

		addOutput(createOutputCentered<PJ301MPort>(mm2px(Vec(57.958, 22.415)), module, Discomfort::ENV_OUT_OUTPUT));
	}
};


Model* modelDiscomfort = createModel<Discomfort, DiscomfortWidget>("discomfort");