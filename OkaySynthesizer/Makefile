# If RACK_DIR is not defined when calling the Makefile, default to two directories above
RACK_DIR ?= ../..

# FLAGS will be passed to both the C and C++ compiler
FLAGS +=
LIB_DAISY_INC_DIR = ../DaisySP/Source
CFLAGS +=
CXXFLAGS += -I$(LIB_DAISY_INC_DIR)

LIB_DAISY_PATH = ../DaisySP/build
LIB_DAISY_NAME = libdaisysp.a

# Careful about linking to shared libraries, since you can't assume much about the user's environment and library search path.
# Static libraries are fine, but they should be added to this plugin's build system.
LDFLAGS += -L$(LIB_DAISY_PATH) -I$(LIB_DAISY_NAME)

# Add .cpp files to the build
SOURCES += $(wildcard src/*.cpp)

SOURCES += src/lowstepper/lowstepper/AverageBuffer.cpp
SOURCES += src/lowstepper/lowstepper/LowStepperLfo.cpp
SOURCES += src/lowstepper/lowstepper/SyncManager.cpp
SOURCES += src/lowstepper/lowstepper/util.cpp

SOURCES += src/lowstepper/lowstepper_rack/LowstepperChannel.cpp
SOURCES += src/lowstepper/lowstepper_rack/LowstepperRack.cpp
SOURCES += src/lowstepper/lowstepper_rack/Names.cpp
SOURCES += src/lowstepper/lowstepper_rack/RackIORef.cpp
SOURCES += src/lowstepper/lowstepper_module.cpp

# SOURCES += src/discomfort/discomfort.cpp

# Add files to the ZIP package when running `make dist`
# The compiled plugin and "plugin.json" are automatically added.
DISTRIBUTABLES += res
DISTRIBUTABLES += $(wildcard LICENSE*)
DISTRIBUTABLES += $(wildcard presets)

# Include the Rack plugin Makefile framework
include $(RACK_DIR)/plugin.mk
