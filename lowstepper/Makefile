# If RACK_DIR is not defined when calling the Makefile, default to two directories above
RACK_DIR ?= ../..

# FLAGS will be passed to both the C and C++ compiler
FLAGS +=
CFLAGS +=
CXXFLAGS +=

# Careful about linking to shared libraries, since you can't assume much about the user's environment and library search path.
# Static libraries are fine, but they should be added to this plugin's build system.
LDFLAGS +=

# Add .cpp files to the build
SOURCES += $(wildcard src/*.cpp)

SOURCES += src/lowstepper/AverageBuffer.cpp
SOURCES += src/lowstepper/LowStepperLfo.cpp
SOURCES += src/lowstepper/SyncManager.cpp
SOURCES += src/lowstepper/util.cpp

SOURCES += src/lowstepper_rack/LowstepperChannel.cpp
SOURCES += src/lowstepper_rack/LowstepperRack.cpp
SOURCES += src/lowstepper_rack/Names.cpp
SOURCES += src/lowstepper_rack/RackIORef.cpp

# Add files to the ZIP package when running `make dist`
# The compiled plugin and "plugin.json" are automatically added.
DISTRIBUTABLES += res
DISTRIBUTABLES += $(wildcard LICENSE*)
DISTRIBUTABLES += $(wildcard presets)

# Include the Rack plugin Makefile framework
include $(RACK_DIR)/plugin.mk
