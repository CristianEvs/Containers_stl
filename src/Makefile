#===========================================================================
CC = g++
FLAGS = -std=c++17 -pedantic -Wall -Werror -Wextra -lm
#===========================================================================
TARGET = s21_vector.a
#===========================================================================
TEST_FLAGS = -lgtest -lgmock -pthread -lgtest_main
#===========================================================================
FILE = stl/list/s21_list.cc stl/map/s21_map.cc stl/queue/s21_queue.cc \
	stl/set/s21_set.h stl/stack/s21_stack.cc stl/tree/s21_avlTree.cc stl/vector/s21_vector.cc
FILE_H = stl/list/list.hpp stl/map/s21_map.h stl/queue/s21_queue.h \
	stl/stack/s21_stack.h stl/tree/s21_avlTree.h stl/vector/s21_vector.h
#===========================================================================
all: $(TARGET)

$(TARGET):
	$(CC) $(FLAGS) -c $(FILE)
	ar rcs $(TARGET) *.o
	ranlib $(TARGET)
	rm -rf *.o

test: $(TARGET)
	$(CC) tests/*.cc $(TARGET) $(FLAGS) $(TEST_FLAGS) -o test.out
	./test.out

gcov_report: clean
	$(CC) $(FILE) tests/*.cc $(FLAGS) $(TEST_FLAGS) --coverage -o coverage.out
	./coverage.out
	lcov -c -d ./ -o coverage.info
	# Захватываем только нужные файлы
	lcov -e coverage.info "*$(FILE)" -o filtered_coverage.info
	genhtml -o coverage_html coverage.info 
	open coverage_html/index.html

valgrind: clean test
	valgrind --tool=memcheck --leak-check=yes  ./test.out

clang_i:
	clang-format -i -style=Google $(FILE) $(FILE_H)

clang_n:
	clang-format -n -style=Google $(FILE) $(FILE_H)

clean:
	rm -rf coverage_html *.gcno *.gcda *.out *.info *.a *.o

rebuild: clean all
#===========================================================================
