#orderi429@gmail.com
COMPILER = g++
FLAGS = -std=c++17 -Wall -Wextra -g

Main: main.cpp MyContainer.hpp
	$(COMPILER) $(FLAGS) main.cpp -o main

test: test.cpp MyContainer.hpp
	$(COMPILER) $(FLAGS) test.cpp -o test

valgrind_test: test
	valgrind --leak-check=full ./test

valgrind_main: main
	valgrind --leak-check=full ./main
	
clean:
	rm -f main test