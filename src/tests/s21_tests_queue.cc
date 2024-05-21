#include <queue>
#include <string>
#include "tests.h"


TEST(Queue, Constructor_Default) {
  s21::queue<int> our_queue;
  std::queue<int> std_queue;
  EXPECT_EQ(our_queue.empty(), std_queue.empty());
  EXPECT_EQ(our_queue.size(), std_queue.size());
}

TEST(Queue, Constructor_List) {
  s21::queue<std::string> our_queue = {"apple", "banana", "cherry"};
  std::queue<std::string> std_queue;
  std_queue.push("apple");
  std_queue.push("banana");
  std_queue.push("cherry");
  EXPECT_EQ(our_queue.front(), std_queue.front());
  EXPECT_EQ(our_queue.back(), std_queue.back());
}

TEST(Queue, Constructor_Copy) {
  s21::queue<double> our_queue = {1.1, 2.2, 3.3};
  s21::queue<double> our_copy(our_queue);
  std::queue<double> std_queue;
  std_queue.push(1.1);
  std_queue.push(2.2);
  std_queue.push(3.3);
  std::queue<double> std_copy(std_queue);
  EXPECT_EQ(our_copy.front(), std_copy.front());
  EXPECT_EQ(our_copy.back(), std_copy.back());
}

TEST(Queue, Constructor_Move) {
  s21::queue<char> our_queue = {'a', 'b', 'c'};
  s21::queue<char> our_move(std::move(our_queue));
  std::queue<char> std_queue;
  std_queue.push('a');
  std_queue.push('b');
  std_queue.push('c');
  std::queue<char> std_move(std::move(std_queue));
  EXPECT_EQ(our_move.front(), std_move.front());
  EXPECT_EQ(our_move.back(), std_move.back());
  EXPECT_EQ(our_queue.empty(), std_queue.empty());
}

TEST(Queue, Operator_Move) {
  s21::queue<std::string> our_queue = {"one", "two", "three"};
  std::queue<std::string> std_queue;
  std_queue.push("one");
  std_queue.push("two");
  std_queue.push("three");
  s21::queue<std::string> our_queue_empty;
  std::queue<std::string> std_queue_empty;
  our_queue_empty = std::move(our_queue);
  std_queue_empty = std::move(std_queue);
  EXPECT_EQ(our_queue_empty.front(), std_queue_empty.front());
  EXPECT_EQ(our_queue_empty.back(), std_queue_empty.back());
  EXPECT_EQ(our_queue.empty(), std_queue.empty());
}

TEST(Queue, FrontAndBack) {
  s21::queue<float> our_queue = {1.1f, 2.2f, 3.3f};
  std::queue<float> std_queue;
  std_queue.push(1.1f);
  std_queue.push(2.2f);
  std_queue.push(3.3f);
  EXPECT_EQ(our_queue.front(), std_queue.front());
  EXPECT_EQ(our_queue.back(), std_queue.back());
}

TEST(Queue, Empty) {
  s21::queue<int> our_queue = {10, 20, 30};
  std::queue<int> std_queue;
  std_queue.push(10);
  std_queue.push(20);
  std_queue.push(30);
  EXPECT_EQ(our_queue.empty(), std_queue.empty());
  s21::queue<int> our_queue_empty;
  std::queue<int> std_queue_empty;
  EXPECT_EQ(our_queue_empty.empty(), std_queue_empty.empty());
}

TEST(Queue, Size) {
  s21::queue<double> our_queue = {1.5, 2.5, 3.5};
  std::queue<double> std_queue;
  std_queue.push(1.5);
  std_queue.push(2.5);
  std_queue.push(3.5);
  EXPECT_EQ(our_queue.size(), std_queue.size());
  s21::queue<double> our_queue_empty;
  std::queue<double> std_queue_empty;
  EXPECT_EQ(our_queue_empty.size(), std_queue_empty.size());
}

TEST(Queue, Push) {
  s21::queue<std::string> our_queue;
  our_queue.push("first");
  our_queue.push("second");
  our_queue.push("third");
  std::queue<std::string> std_queue;
  std_queue.push("first");
  std_queue.push("second");
  std_queue.push("third");
  EXPECT_EQ(our_queue.front(), std_queue.front());
  EXPECT_EQ(our_queue.back(), std_queue.back());
}

TEST(Queue, Pop) {
  s21::queue<int> our_queue = {5, 10, 15};
  std::queue<int> std_queue;
  std_queue.push(5);
  std_queue.push(10);
  std_queue.push(15);
  our_queue.pop();
  std_queue.pop();
  EXPECT_EQ(our_queue.front(), std_queue.front());
  our_queue.pop();
  std_queue.pop();
  EXPECT_EQ(our_queue.front(), std_queue.front());
}

TEST(Queue, Swap) {
  s21::queue<int> our_queue1 = {1, 2, 3};
  s21::queue<int> our_queue2 = {4, 5, 6};
  std::queue<int> std_queue1;
  std::queue<int> std_queue2;
  std_queue1.push(1);
  std_queue1.push(2);
  std_queue1.push(3);
  std_queue2.push(4);
  std_queue2.push(5);
  std_queue2.push(6);
  our_queue1.swap(our_queue2);
  std_queue1.swap(std_queue2);
  EXPECT_EQ(our_queue1.front(), std_queue1.front());
  EXPECT_EQ(our_queue2.front(), std_queue2.front());
}
