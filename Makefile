TARGET ?= ipswtool

SRC_DIR ?= ./src

SRCS := $(shell find $(SRC_DIR) -name *.cpp)
OBJS := $(addsuffix .o,$(basename $(SRCS)))

CPPFLAGS ?= -g -std=c++11
LDFLAGS ?=

$(TARGET): $(OBJS) $(BUILD_NUMBER_FILE)
	$(CXX) $(OBJS) -o $@ $(LDFLAGS)

.PHONY: clean
clean:
	rm -f $(OBJS) $(TARGET)