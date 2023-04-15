CXX = g++
CXXFLAGS = -Wall -Wextra -O3 -std=c++17
LIBS =
INC = -I./src/core -I./src/utils
SRCDIR = src
OBJDIR = obj
BINDIR = bin

SOURCES = $(wildcard $(SRCDIR)/**/*.cpp $(SRCDIR)/*.cpp)
OBJECTS = $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(SOURCES))

TARGET = $(BINDIR)/fdtd_solver

TESTSDIR = tests
TESTOBJDIR = obj_tests
TESTBINDIR = bin_tests

TESTSOURCES = $(wildcard $(TESTSDIR)/**/*.cpp $(TESTSDIR)/*.cpp)
TESTOBJECTS = $(patsubst $(TESTSDIR)/%.cpp, $(TESTOBJDIR)/%.o, $(TESTSOURCES))

TESTTARGET = $(TESTBINDIR)/run_tests

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJECTS)
	mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(INC) -o $@ $^ $(LIBS)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(INC) -c $< -o $@

tests: $(TESTTARGET)

$(TESTTARGET): $(TESTOBJECTS) $(filter-out $(OBJDIR)/main.o, $(OBJECTS))
	mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(INC) -o $@ $^ $(LIBS) -lgtest -lgtest_main -pthread

$(TESTOBJDIR)/%.o: $(TESTSDIR)/%.cpp
	mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -I./src -c $< -o $@

.PHONY: clean-tests

clean-tests:
	rm -rf $(TESTOBJDIR) $(TESTBINDIR)

clean:
	rm -rf $(OBJDIR) $(BINDIR)

# Google Test flags
GTEST_CXXFLAGS = -I/usr/local/include/gtest -I/usr/local/include/gtest/internal
GTEST_LDFLAGS = -L/usr/local/lib -lgtest -lgtest_main -pthread

# Test object files
TEST_OBJS = $(patsubst $(TEST_SRC_DIR)/%.cpp,$(TEST_OBJ_DIR)/%.o,$(wildcard $(TEST_SRC_DIR)/*.cpp))

# Compile tests
$(TEST_OBJ_DIR)/%.o: $(TEST_SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	@$(CXX) $(CXXFLAGS) $(GTEST_CXXFLAGS) -c $< -o $@

# Link tests
$(TEST_BINARY): $(TEST_OBJS) $(OBJS)
	@mkdir -p $(TEST_BIN_DIR)
	@$(CXX) $(CXXFLAGS) $(GTEST_CXXFLAGS) $(LDFLAGS) $(GTEST_LDFLAGS) $^ -o $@


# Test target
test: $(TEST_BINARY)
    $(TEST_BINARY)