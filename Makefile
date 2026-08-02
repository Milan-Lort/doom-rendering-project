TARGET_EXEC := Doom_Like

CXX := g++
LIBFLAGS := -lSDL3

SRC_DIRS := ./src
BUILD_DIRS := ./Build
INC_DIRS := ./src/headers

# Gets the names of all c++ files in the source directory
SRCS := $(shell find $(SRC_DIRS) -name '*.cpp')

# Use the name of the sources to create a list of object files to create
OBJS := $(SRCS:%=$(BUILD_DIRS)/%.o)

$(BUILD_DIRS)/$(TARGET_EXEC): $(OBJS)
	$(CXX) $(OBJS) -o $@ $(LIBFLAGS)

$(BUILD_DIRS)/%.cpp.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) -c $< -o $@

.PHONY: clean
clean:
	rm -r $(BUILD_DIRS)

run:
	$(BUILD_DIRS)/$(TARGET_EXEC)