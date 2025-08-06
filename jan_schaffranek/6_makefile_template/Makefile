DEBUG = 1

INCLUDE_DIR = include
SOURCES_DIR = src
BUILD_DIR = build

RM = rm -rf
CXX_STANDARD = c++11
CXX_WARNINGS = -Wall -Wextra -Wpedantic
CXX = g++
CPPFLAGS = -I $(INCLUDE_DIR)
CXXFLAGS = $(CXX_WARNINGS) -std=$(CXX_STANDARD)

COMPILER_CALL = $(CXX) $(CXXFLAGS) -I $(INCLUDE_DIR)

EXECUTABLE_NAME = mainDebug
CPP_SOURCES = $(wildcard $(SOURCES_DIR)/*.cc)
OBJECTS = $(patsubst $(SOURCES_DIR)/%.cc,$(BUILD_DIR)/%.o,$(CPP_SOURCES))


ifeq ($(DEBUG),1)
	CXXFLAGS += -g -O0
	EXECUTABLE_NAME = mainDebug
else
	CXXFLAGS += -O3
	EXECUTABLE_NAME = mainRelease
endif

create:
	@mkdir build

build: create $(OBJECTS)
	$(COMPILER_CALL) $(OBJECTS) -o $(BUILD_DIR)/$(EXECUTABLE_NAME)

$(BUILD_DIR)/%.o: $(SOURCES_DIR)/%.cc
	$(COMPILER_CALL) -c $< -o $@

execute:
	@./$(BUILD_DIR)/$(EXECUTABLE_NAME)

clean:
	$(RM) $(BUILD_DIR)

