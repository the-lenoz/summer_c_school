CXX=g++
CFLAGS=-D _DEBUG -ggdb3 -std=c++17 -O0 -Wall -Wextra -Weffc++ -Waggressive-loop-optimizations -Wc++14-compat \
-Wmissing-declarations -Wcast-align -Wcast-qual -Wchar-subscripts -Wconditionally-supported -Wconversion -Wctor-dtor-privacy \
-Wempty-body -Wfloat-equal -Wformat-nonliteral -Wformat-security -Wformat-signedness -Wformat=2 -Winline -Wlogical-op \
-Wnon-virtual-dtor -Wopenmp-simd -Woverloaded-virtual -Wpacked -Wpointer-arith -Winit-self -Wredundant-decls -Wshadow \
-Wsign-conversion -Wsign-promo -Wstrict-null-sentinel -Wstrict-overflow=2 -Wsuggest-attribute=noreturn \
-Wsuggest-final-methods -Wsuggest-final-types -Wsuggest-override -Wswitch-default -Wswitch-enum -Wsync-nand -Wundef \
-Wunreachable-code -Wunused -Wuseless-cast -Wvariadic-macros -Wno-literal-suffix -Wno-missing-field-initializers \
-Wno-narrowing -Wno-old-style-cast -Wno-varargs -Wstack-protector -fcheck-new -fsized-deallocation -fstack-protector \
-fstrict-overflow -flto-odr-type-merging -fno-omit-frame-pointer -Wlarger-than=8192 -Wstack-usage=8192 -pie -fPIE -Werror=vla -MMD

BUILD_DIR=build
TEST_DIR=tests


INC=tests ./
INC_PARAMS=$(foreach d, $(INC), -I$d)

MAIN_SOURCES=str_operations.cpp terminal_decorator.cpp user_interface.cpp cli.cpp double_operations.cpp equation_solvers.cpp number_of_equation_roots_str_enum.cpp errors.cpp signal_handlers.cpp logger.cpp
MAIN_OBJECTS_WITHOUT_PREFIX=$(MAIN_SOURCES:.cpp=.o)
MAIN_OBJECTS=$(addprefix $(BUILD_DIR)/, $(MAIN_OBJECTS_WITHOUT_PREFIX))

MAIN_MAIN_SOURCES=main.cpp
MAIN_MAIN_OBJECTS_WITHOUT_PREFIX=$(MAIN_MAIN_SOURCES:.cpp=.o)
MAIN_MAIN_OBJECTS=$(addprefix $(BUILD_DIR)/, $(MAIN_MAIN_OBJECTS_WITHOUT_PREFIX))

TEST_SOURCES=$(TEST_DIR)/all_tests.cpp $(TEST_DIR)/test_double_operations.cpp $(TEST_DIR)/test_equation_solvers.cpp
TEST_OBJECTS_WITHOUT_PREFIX=$(TEST_SOURCES:.cpp=.o)
TEST_OBJECTS=$(addprefix $(BUILD_DIR)/, $(TEST_OBJECTS_WITHOUT_PREFIX))

TEST_MAIN_SOURCES=$(TEST_DIR)/main.cpp
TEST_MAIN_OBJECTS_WITHOUT_PREFIX=$(TEST_MAIN_SOURCES:.cpp=.o)
TEST_MAIN_OBJECTS=$(addprefix $(BUILD_DIR)/, $(TEST_MAIN_OBJECTS_WITHOUT_PREFIX))

MAIN_EXECUTABLE=$(BUILD_DIR)/main
MAIN_EXECUTABLE_TEST_MODE=$(BUILD_DIR)/main_test

TEST_EXECUTABLE=$(BUILD_DIR)/$(TEST_DIR)/main

.PHONY: docs all clean


%:
	mkdir -p $(BUILD_DIR)
	mkdir -p $(BUILD_DIR)/$(TEST_DIR)

all: $(MAIN_EXECUTABLE)

test_mode: CDEBUG=-DTEST_MODE
test_mode: $(TEST_EXECUTABLE) $(MAIN_EXECUTABLE_TEST_MODE) 

clean:
	rm $(BUILD_DIR)/$(TEST_DIR)/* || true
	rm $(BUILD_DIR)/* -rf || true


docs: 
	doxygen


$(TEST_EXECUTABLE): $(TEST_OBJECTS) $(MAIN_OBJECTS) $(TEST_MAIN_OBJECTS)
	@echo "$<   $@"
	$(CXX) $^ -o $@

$(MAIN_EXECUTABLE): $(MAIN_EXECUTABLE_OBJECTS) $(MAIN_OBJECTS) $(MAIN_MAIN_OBJECTS)
	@echo "$<   $@"
	$(CXX) $^ -o $@

$(MAIN_EXECUTABLE_TEST_MODE): $(MAIN_EXECUTABLE_OBJECTS) $(MAIN_OBJECTS) $(TEST_OBJECTS) $(MAIN_MAIN_OBJECTS)
	echo "$<   $@"
	$(CXX) $^ -o $@


$(BUILD_DIR)/%.o: ./%.cpp
	$(CXX) $(CFLAGS) $(CDEBUG) $(INC_PARAMS) $< -c -o $@

$(BUILD_DIR)/$(TEST_DIR)/%.o: $(TEST_DIR)/%.o
	$(CXX) $(CFLAGS) $(CDEBUG) $(INC_PARAMS) $< -c -o $@


-include $(BUILD_DIR)/*.d, $(BUILD_DIR)/$(TEST_DIR)/*.d