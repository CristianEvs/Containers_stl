#include <gtest/gtest.h>

#include <vector>

#include "../stl/vector/s21_vector.cc"

TEST(VectorTest, DefaultConstructor) {
  s21::vector<double> s21_vector;
  std::vector<double> std_vector;
  EXPECT_TRUE(s21_vector.empty());
  EXPECT_EQ(s21_vector.size(), 0);
  EXPECT_EQ(s21_vector.size(), std_vector.size());
}

TEST(VectorTest, SizeConstructor1) {
  s21::vector<double> s21_vector(10);
  std::vector<double> std_vector(10);
  EXPECT_EQ(s21_vector.size(), 10);
  EXPECT_EQ(s21_vector.size(), std_vector.size());
}

TEST(VectorTest, SizeConstructor2) {
  s21::vector<double> s21_vector(0);
  std::vector<double> std_vector(0);
  EXPECT_EQ(s21_vector.size(), 0);
  EXPECT_EQ(s21_vector.size(), std_vector.size());
}

TEST(VectorTest, InitializerListConstructor) {
  s21::vector<std::string> s21_vector = {"hello", "world"};
  std::vector<std::string> std_vector = {"hello", "world"};
  EXPECT_EQ(s21_vector.front(), "hello");
  EXPECT_EQ(s21_vector.back(), "world");
  EXPECT_EQ(s21_vector.size(), std_vector.size());
}

TEST(VectorTest, CopyConstructor) {
  s21::vector<char> s21_vector = {'a', 'b', 'c'};
  std::vector<char> std_vector = {'a', 'b', 'c'};
  s21::vector<char> s21_copy(s21_vector);
  std::vector<char> std_copy(std_vector);
  EXPECT_EQ(s21_copy.front(), std_copy.front());
  EXPECT_EQ(s21_copy.back(), std_copy.back());
  EXPECT_EQ(s21_copy.size(), std_copy.size());
}

TEST(VectorTest, MoveConstructor) {
  s21::vector<int> s21_vector = {10, 20, 30};
  std::vector<int> std_vector = {10, 20, 30};
  s21::vector<int> s21_moved(std::move(s21_vector));
  std::vector<int> std_moved(std::move(std_vector));
  EXPECT_EQ(s21_moved.front(), std_moved.front());
  EXPECT_EQ(s21_moved.back(), std_moved.back());
  EXPECT_TRUE(s21_vector.empty());
  EXPECT_TRUE(std_vector.empty());
}

TEST(VectorTest, MoveAssignment) {
  s21::vector<int> s21_vector = {100, 200, 300};
  std::vector<int> std_vector = {100, 200, 300};
  s21::vector<int> s21_assigned;
  std::vector<int> std_assigned;
  s21_assigned = std::move(s21_vector);
  std_assigned = std::move(std_vector);
  EXPECT_EQ(s21_assigned.front(), std_assigned.front());
  EXPECT_EQ(s21_assigned.back(), std_assigned.back());
  EXPECT_TRUE(s21_vector.empty());
  EXPECT_TRUE(std_vector.empty());
}

TEST(VectorTest, AccessOperator1) {
  s21::vector<int> s21_vector = {1, 2, 3, 4, 5};
  std::vector<int> std_vector = {1, 2, 3, 4, 5};
  EXPECT_EQ(s21_vector[2], std_vector[2]);
  EXPECT_EQ(s21_vector.at(4), std_vector.at(4));
}

TEST(VectorTest, AccessOperator2) {
  s21::vector<int> s21_vector = {1, 2, 3, 4, 5};
  std::vector<int> std_vector = {1, 2, 3, 4, 5};
  EXPECT_THROW(s21_vector.at(6), std::out_of_range);
  EXPECT_THROW(std_vector.at(6), std::out_of_range);
}

TEST(VectorTest, PushBackPopBack) {
  s21::vector<float> s21_vector;
  std::vector<float> std_vector;
  s21_vector.push_back(1.5);
  std_vector.push_back(1.5);
  EXPECT_EQ(s21_vector.back(), std_vector.back());
  s21_vector.push_back(2.5);
  std_vector.push_back(2.5);
  EXPECT_EQ(s21_vector.back(), std_vector.back());
  s21_vector.pop_back();
  std_vector.pop_back();
  EXPECT_EQ(s21_vector.back(), std_vector.back());
}

TEST(VectorTest, Swap) {
  s21::vector<int> s21_vector1 = {10, 20, 30};
  s21::vector<int> s21_vector2 = {40, 50, 60};
  std::vector<int> std_vector1 = {10, 20, 30};
  std::vector<int> std_vector2 = {40, 50, 60};
  s21_vector1.swap(s21_vector2);
  std_vector1.swap(std_vector2);
  EXPECT_EQ(s21_vector1.front(), std_vector1.front());
  EXPECT_EQ(s21_vector2.back(), std_vector2.back());
  EXPECT_EQ(s21_vector1.size(), std_vector1.size());
  EXPECT_EQ(s21_vector2.size(), std_vector2.size());
}

TEST(VectorTest, ReserveCapacity) {
  s21::vector<int> s21_vector = {1, 2, 3};
  std::vector<int> std_vector = {1, 2, 3};
  size_t newCapacity = s21_vector.capacity() + 5;
  s21_vector.reserve(newCapacity);
  std_vector.reserve(newCapacity);
  EXPECT_GE(s21_vector.capacity(), newCapacity);
  EXPECT_EQ(s21_vector.capacity(), std_vector.capacity());
}

TEST(VectorTest, ShrinkToFit1) {
  s21::vector<int> s21_vector = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::vector<int> std_vector = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  s21_vector.shrink_to_fit();
  std_vector.shrink_to_fit();
  EXPECT_EQ(s21_vector.capacity(), std_vector.capacity());
  EXPECT_EQ(s21_vector.size(), std_vector.size());
}

TEST(VectorTest, ShrinkToFit2) {
  s21::vector<int> s21_vector;
  s21_vector.shrink_to_fit();
  EXPECT_EQ(s21_vector.capacity(), 0U);
}

TEST(VectorTest, ShrinkToFit3) {
  s21::vector<int> s21_vector = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  s21_vector.pop_back();
  s21_vector.shrink_to_fit();
  EXPECT_EQ(s21_vector.capacity(), s21_vector.size());
  EXPECT_EQ(s21_vector.capacity(), 9U);
}

TEST(VectorTest, Insert1) {
  s21::vector<std::string> s21_vector = {"alpha", "beta", "gamma"};
  std::vector<std::string> std_vector = {"alpha", "beta", "gamma"};
  s21::vector<std::string>::iterator s21_it = s21_vector.begin() + 1;
  std::vector<std::string>::iterator std_it = std_vector.begin() + 1;
  s21_vector.insert(s21_it, "delta");
  std_vector.insert(std_it, "delta");
  EXPECT_EQ(s21_vector.size(), std_vector.size());
  EXPECT_EQ(s21_vector[1], std_vector[1]);
}

TEST(VectorTest, Insert2) {
  s21::vector<int> s21vector{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::vector<int> stdvector{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  s21::vector<int>::iterator s21iter1 = s21vector.begin();
  std::vector<int>::iterator stditer1 = stdvector.begin();
  s21vector.insert(s21iter1, 4);
  stdvector.insert(stditer1, 4);
  s21::vector<int>::iterator s21iter2 = s21vector.end();
  std::vector<int>::iterator stditer2 = stdvector.end();
  s21vector.insert(s21iter2, 7);
  stdvector.insert(stditer2, 7);
  ASSERT_EQ(s21vector.size(), stdvector.size());
}

TEST(VectorTest, Erase) {
  s21::vector<std::string> s21_vector = {"one", "two", "three", "four"};
  std::vector<std::string> std_vector = {"one", "two", "three", "four"};
  s21::vector<std::string>::iterator s21_it = s21_vector.begin() + 2;
  std::vector<std::string>::iterator std_it = std_vector.begin() + 2;
  s21_vector.erase(s21_it);
  std_vector.erase(std_it);
  EXPECT_EQ(s21_vector.size(), std_vector.size());
  EXPECT_EQ(s21_vector[2], std_vector[2]);
}

TEST(VectorTest, Maxsize) {
  s21::vector<int> s21_vector;
  EXPECT_GT(s21_vector.max_size(), 0U);
}

TEST(VectorTest, DataPointer) {
  s21::vector<int> s21_vector = {5, 10, 15};
  std::vector<int> std_vector = {5, 10, 15};
  int* s21_data = s21_vector.data();
  int* std_data = std_vector.data();
  for (size_t i = 0; i < s21_vector.size(); ++i) {
    EXPECT_EQ(s21_data[i], std_data[i]);
  }
}

TEST(VectorTest, Clear) {
  s21::vector<int> s21_vector = {1, 2, 3, 4, 5};
  std::vector<int> std_vector = {1, 2, 3, 4, 5};
  s21_vector.clear();
  std_vector.clear();
  EXPECT_TRUE(s21_vector.empty());
  EXPECT_TRUE(std_vector.empty());
  EXPECT_EQ(s21_vector.size(), std_vector.size());
}
