#Prject Info
TARGET  = state-test
INC_DIR += src gmock
LIB_DIR += src
SRC_DIR = src test gmock
LIB     += -lpthread

#Makefile Template For Application
TARGET  := $(strip $(TARGET))
CROSS	= $(RASPI_CROSS_PREFIX)
CC      = $(CROSS)gcc
CXX     = $(CROSS)g++
CPP     = $(CROSS)cpp
CFLAGS  += $(C_INC) -fPIC $(shell ./gmock/cmock/cmock-config --cflags) -std=c99 -fprofile-arcs -ftest-coverage
CXXFLAGS += $(C_INC) -fprofile-arcs -ftest-coverage 
LDFLAGS  += $(shell ./gmock/cmock/cmock-config --libs)

C_INC   = $(INC_DIR:%=-I%) $(INC)
C_LIB   = $(LIB_DIR:%=-L%) $(LIB)

C_SRC   = $(wildcard $(SRC_DIR:%=%/*.c))
CXX_SRC = $(wildcard $(SRC_DIR:%=%/*.cpp))
C_OBJ   = $(C_SRC:%.c=%.o)
C_SO		= $(patsubst %.o,src/lib%.so,$(notdir $(C_OBJ)))
LIB			+= $(patsubst %.o,-l%,$(notdir $(C_OBJ)))
CXX_OBJ = $(CXX_SRC:%.cpp=%.o)
CXX_DEP = $(CXX_SRC:%.cpp=%.d)

ALL_OBJ = $(C_OBJ) $(CXX_OBJ)
ALL_DEP = $(CXX_DEP)

ifeq ($(debug), 1)
CFLAGS   += -g -DLOCAL_DEBUG -O0
CXXFLAGS += -g -DLOCAL_DEBUG -O0
endif


.PHONY: all clean test

all: $(TARGET)

clean:
	rm -f $(ALL_OBJ) $(ALL_DEP) $(TARGET) $(C_SO)

test: $(TARGET)
	./$(TARGET)

$(C_DEP): %.d : %.c
	$(CPP) $(C_INC) -MM $< > $@

$(CXX_DEP): %.d : %.cpp
	$(CPP) $(C_INC) -MM $< > $@

$(C_SO): $(C_OBJ)
	$(CC) -shared -Wl,-soname,$@ -o $@ $(patsubst %.so,%.o,$(subst src/lib,src/,$@)) -fprofile-arcs -ftest-coverage 

ifneq ($(MAKECMDGOALS), clean)
-include $(ALL_DEP)
endif

$(TARGET): $(CXX_OBJ) $(C_SO)
	$(CXX) -o $@ $^ $(LDFLAGS) -pthread $(C_LIB) -lgcov -fprofile-arcs -ftest-coverage
