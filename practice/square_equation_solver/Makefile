CC=g++
CFLAGS=-D _DEBUG -ggdb3 -std=c++17 -O0 -Wall -Wextra -Weffc++ -Waggressive-loop-optimizations -Wc++14-compat \
-Wmissing-declarations -Wcast-align -Wcast-qual -Wchar-subscripts -Wconditionally-supported -Wconversion -Wctor-dtor-privacy \
-Wempty-body -Wfloat-equal -Wformat-nonliteral -Wformat-security -Wformat-signedness -Wformat=2 -Winline -Wlogical-op \
-Wnon-virtual-dtor -Wopenmp-simd -Woverloaded-virtual -Wpacked -Wpointer-arith -Winit-self -Wredundant-decls -Wshadow \
-Wsign-conversion -Wsign-promo -Wstrict-null-sentinel -Wstrict-overflow=2 -Wsuggest-attribute=noreturn \
-Wsuggest-final-methods -Wsuggest-final-types -Wsuggest-override -Wswitch-default -Wswitch-enum -Wsync-nand -Wundef \
-Wunreachable-code -Wunused -Wuseless-cast -Wvariadic-macros -Wno-literal-suffix -Wno-missing-field-initializers \
-Wno-narrowing -Wno-old-style-cast -Wno-varargs -Wstack-protector -fcheck-new -fsized-deallocation -fstack-protector \
-fstrict-overflow -flto-odr-type-merging -fno-omit-frame-pointer -Wlarger-than=8192 -Wstack-usage=8192 -pie -fPIE -Werror=vla -MMD

INC=tests .
INC_PARAMS=$(foreach d, $(INC), -I$d)

MAIN_SOURCES=colors.cpp user_interface.cpp cli.cpp double_operations.cpp equation_solvers.cpp main.cpp number_of_equation_roots_str_enum.cpp
MAIN_OBJECTS=$(MAIN_SOURCES:.cpp=.o)

TEST_SOURCES=tests/all_tests.cpp tests/test_double_operations.cpp tests/test_equation_solvers.cpp
TEST_OBJECTS=$(TEST_SOURCES:.cpp=.o)

MAIN_EXECUTABLE=main
MAIN_EXECUTABLE_TEST_MODE=main_test

TEST_EXECUTABLE=tests/main

.PHONY: debug

all: $(MAIN_EXECUTABLE)

test_mode: CDEBUG=-DTEST_MODE
test_mode: $(TEST_EXECUTABLE) $(MAIN_EXECUTABLE_TEST_MODE) 

clean:
	rm *.o || true
	rm $(MAIN_EXECUTABLE) || true
	rm tests/*.o || true
	rm $(TEST_EXECUTABLE) || true
	rm *.d || true
	rm tests/*.d || true


$(TEST_EXECUTABLE): $(TEST_OBJECTS) $(MAIN_OBJECTS)
	$(CC) $(TEST_OBJECTS) $(MAIN_OBJECTS) -o $@

$(MAIN_EXECUTABLE): $(MAIN_EXECUTABLE_OBJECTS) $(MAIN_OBJECTS)
	$(CC) $(MAIN_EXECUTABLE_OBJECTS) $(MAIN_OBJECTS) -o $@

$(MAIN_EXECUTABLE_TEST_MODE): $(MAIN_EXECUTABLE_OBJECTS) $(MAIN_OBJECTS) $(TEST_OBJECTS)
	$(CC) $(MAIN_EXECUTABLE_OBJECTS) $(MAIN_OBJECTS) $(TEST_OBJECTS) -o $@
.cpp.o:
	$(CC) $(CFLAGS) $(CDEBUG) $(INC_PARAMS) $< -c -o $@

-include *.d, */*.d