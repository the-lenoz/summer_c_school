CC=g++
CFLAGS=-D _DEBUG -ggdb3 -std=c++17 -O0 -Wall -Wextra -Weffc++ -Waggressive-loop-optimizations -Wc++14-compat \
-Wmissing-declarations -Wcast-align -Wcast-qual -Wchar-subscripts -Wconditionally-supported -Wconversion -Wctor-dtor-privacy \
-Wempty-body -Wfloat-equal -Wformat-nonliteral -Wformat-security -Wformat-signedness -Wformat=2 -Winline -Wlogical-op \
-Wnon-virtual-dtor -Wopenmp-simd -Woverloaded-virtual -Wpacked -Wpointer-arith -Winit-self -Wredundant-decls -Wshadow \
-Wsign-conversion -Wsign-promo -Wstrict-null-sentinel -Wstrict-overflow=2 -Wsuggest-attribute=noreturn \
-Wsuggest-final-methods -Wsuggest-final-types -Wsuggest-override -Wswitch-default -Wswitch-enum -Wsync-nand -Wundef \
-Wunreachable-code -Wunused -Wuseless-cast -Wvariadic-macros -Wno-literal-suffix -Wno-missing-field-initializers \
-Wno-narrowing -Wno-old-style-cast -Wno-varargs -Wstack-protector -fcheck-new -fsized-deallocation -fstack-protector \
-fstrict-overflow -flto-odr-type-merging -fno-omit-frame-pointer -Wlarger-than=8192 -Wstack-usage=8192 -pie -fPIE -Werror=vla
LDFLAGS=

INC=tests .
INC_PARAMS=$(foreach d, $(INC), -I$d)

LIB_SOURCES=user_interface.cpp cli.cpp double_operations.cpp equation_solvers.cpp tests/all_tests.cpp tests/test_double_operations.cpp tests/test_equation_solvers.cpp 
LIB_OBJECTS=$(LIB_SOURCES:.cpp=.o)

EXECUTABLE_SOURCES=main.cpp
EXECUTABLE_OBJECTS=$(EXECUTABLE_SOURCES:.cpp=.o)
EXECUTABLE=main


TEST_SOURCES=tests/main.cpp

TEST_OBJECTS=$(TEST_SOURCES:.cpp=.o)
TEST_EXECUTABLE=tests/main


all: $(EXECUTABLE) test

test: $(TEST_EXECUTABLE)

clean:
	rm *.o || true
	rm $(EXECUTABLE) || true
	rm tests/*.o || true
	rm $(TEST_EXECUTABLE) || true


$(EXECUTABLE): $(EXECUTABLE_OBJECTS) $(LIB_OBJECTS)
	$(CC) $(LDFLAGS) $(EXECUTABLE_OBJECTS) $(LIB_OBJECTS) -o $@

$(TEST_EXECUTABLE): $(TEST_OBJECTS) $(LIB_OBJECTS)
	$(CC) $(LDFLAGS) $(TEST_OBJECTS) $(LIB_OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $(INC_PARAMS) $< -c -o $@

