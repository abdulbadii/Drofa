CXX ?= g++

SRC_DIR = $(shell pwd)/src

CPP_FILES = $(wildcard src/*.cc)
TEST_CPP_FILES = $(filter-out src/main.cc, $(sort $(CPP_FILES) $(wildcard test/*.cc)))

OBJ_FILES = $(addprefix obj/,$(notdir $(CPP_FILES:.cc=.o)))
TEST_OBJ_FILES = $(addprefix obj/,$(notdir $(TEST_CPP_FILES:.cc=.o)))

LD_FLAGS ?= -pthread -flto
CC_FLAGS ?= -Wall -std=c++11 -O3 -march=native -flto -pthread -fno-exceptions

# Catch makes use of C++ exceptions, so remove -fno-exceptions when making a test build
test: CC_FLAGS = -Wall -std=c++11 -O3 -march=native -flto -pthread

# Debug compile and linker flags (remove optimizations and add debugging symbols)
debug debug-test: CC_FLAGS = -Wall -std=c++11 -g -D__DEBUG__
debug debug-test: LD_FLAGS = -pthread
tune: CC_FLAGS  = -Wall -std=c++11 -O3 -march=native -flto -pthread -fno-exceptions -D_TUNE_
tune: LD_FLAGS  = -pthread -flto

OBJ_DIR = obj

BIN_NAME = Drofa_dev
TEST_BIN_NAME = DrofaTest
TUNE_BIN_NAME =Drofa_tune

all: $(OBJ_DIR) $(BIN_NAME)

debug: all

tune: $(OBJ_DIR) $(TUNE_BIN_NAME)

debug-test: $(OBJ_DIR) $(TEST_BIN_NAME)

test: $(OBJ_DIR) $(TEST_BIN_NAME)

$(TUNE_BIN_NAME): $(OBJ_FILES)
	$(CXX) $(LD_FLAGS) -o $@ $^

$(BIN_NAME): $(OBJ_FILES)
	$(CXX) $(LD_FLAGS) -o $@ $^

$(TEST_BIN_NAME): $(TEST_OBJ_FILES)
	$(CXX) $(LD_FLAGS) -o $@ $^

obj/%.o: src/%.cc
	$(CXX) $(CC_FLAGS) -c -o $@ $<

obj/%.o: test/%.cc
	$(CXX) $(CC_FLAGS) -I $(SRC_DIR) -c -o $@ $<

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)
	rm -f $(TEST_BIN_NAME)
	rm -f $(TUNE_BIN_NAME)
	rm -f $(BIN_NAME)
