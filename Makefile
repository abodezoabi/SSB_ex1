CXX=clang++
CXXFLAGS=-std=c++11 -Werror

VALGRIND_FLAGS=-v --leak-check=full --show-leak-kinds=all --error-exitcode=99

SOURCES=Graph.cpp Algorithms.cpp TestCounter.cpp
OBJECTS=$(subst .cpp,.o,$(SOURCES))

DEMO_OBJECTS = main.o $(OBJECTS)
TEST_OBJECTS = TestCounter.o myTest.o $(OBJECTS)

run: main
	./main

main: $(DEMO_OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o main

test: $(TEST_OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o myTest

tidy:
	clang-tidy $(SOURCES) -checks=bugprone-*,clang-analyzer-*,cppcoreguidelines-*,performance-*,portability-*,readability-*,-cppcoreguidelines-pro-bounds-pointer-arithmetic,-cppcoreguidelines-owning-memory --warnings-as-errors=-* --

valgrind: main myTest
	valgrind --tool=memcheck $(VALGRIND_FLAGS) ./main 2>&1 | { egrep "lost| at " || true; }
	valgrind --tool=memcheck $(VALGRIND_FLAGS) ./myTest 2>&1 | { egrep "lost| at " || true; }

%.o: %.cpp
	$(CXX) $(CXXFLAGS) --compile $< -o $@

clean:
	rm -f *.o main myTest