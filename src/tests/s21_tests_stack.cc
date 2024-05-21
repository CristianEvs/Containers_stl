#include <gtest/gtest.h>
// #include "../s21_container.h"
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>

#include "tests.h"

// stack

TEST(stack, Constructor1) {
    s21::stack<int> a;
    std::stack<int> b;
    EXPECT_EQ(a.empty(), b.empty());
}

TEST(stack, Constructor2) {
    s21::stack<int> a = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::stack<int> b;
    b.push(1);
    b.push(2);
    b.push(3);
    b.push(4);
    b.push(5);
    b.push(6);
    b.push(7);
    b.push(8);
    b.push(9);
    b.push(10);
    EXPECT_EQ(a.top(), b.top());
}

TEST(stack, ConstructorCopy) {
    s21::stack<int> a = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    s21::stack<int> a_copy(a);
    std::stack<int> b;
    b.push(1);
    b.push(2);
    b.push(3);
    b.push(4);
    b.push(5);
    b.push(6);
    b.push(7);
    b.push(8);
    b.push(9);
    b.push(10);
    std::stack<int> b_copy(b);
    EXPECT_EQ(a_copy.top(), b_copy.top());
}

TEST(stack, ConstructorMove) {
    s21::stack<int> a = {1, 2, 3, 4, 5};
    std::stack<int> b;
    b.push(1);
    b.push(2);
    b.push(3);
    b.push(4);
    b.push(5);
    s21::stack<int> a_move(std::move(a));
    std::stack<int> b_move(std::move(b));
    ASSERT_EQ(a.empty(), b.empty());
    ASSERT_EQ(a_move.empty(), b_move.empty());
    ASSERT_EQ(a_move.size(), b_move.size());
    ASSERT_EQ(a_move.top(), b_move.top());
}

TEST(stack, OperatorMove) {
    s21::stack<int> a = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::stack<int> b;
    b.push(1);
    b.push(2);
    b.push(3);
    b.push(4);
    b.push(5);
    b.push(6);
    b.push(7);
    b.push(8);
    b.push(9);
    b.push(10);
    s21::stack<int> a_empty;
    std::stack<int> b_empty;
    a_empty = std::move(a);
    b_empty = std::move(b);
    EXPECT_EQ(a_empty.top(), b_empty.top());
}

TEST(stack, Top) {
    s21::stack<int> a = {1, 2, 3, 4, 5, 6};
    EXPECT_EQ(a.top(), 6);
}

TEST(stack, Empty) {
    s21::stack<int> a = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::stack<int> b;
    b.push(1);
    b.push(2);
    b.push(3);
    b.push(4);
    b.push(5);
    b.push(6);
    b.push(7);
    b.push(8);
    b.push(9);
    b.push(10);
    EXPECT_EQ(a.empty(), b.empty());
    s21::stack<int> a_empty;
    std::stack<int> b_empty;
    EXPECT_EQ(a_empty.empty(), b_empty.empty());
}

TEST(stack, Size) {
    s21::stack<int> a = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::stack<int> b;
    b.push(1);
    b.push(2);
    b.push(3);
    b.push(4);
    b.push(5);
    b.push(6);
    b.push(7);
    b.push(8);
    b.push(9);
    b.push(10);
    EXPECT_EQ(a.size(), b.size());
    s21::stack<int> a_empty;
    std::stack<int> b_empty;
    EXPECT_EQ(a_empty.size(), b_empty.size());
}

TEST(stack, PushPop) {
    s21::stack<int> a;
    a.push(1);
    a.push(2);
    a.push(3);
    a.push(4);
    a.push(5);
    a.push(6);
    a.push(7);
    a.push(8);
    a.push(9);
    a.push(10);
    std::stack<int> b;
    b.push(1);
    b.push(2);
    b.push(3);
    b.push(4);
    b.push(5);
    b.push(6);
    b.push(7);
    b.push(8);
    b.push(9);
    b.push(10);
    EXPECT_EQ(a.size(), b.size());
    a.pop();
    b.pop();
    EXPECT_EQ(a.size(), b.size());
    EXPECT_EQ(a.top(), b.top());
    a.pop();
    a.pop();
    b.pop();
    b.pop();
    EXPECT_EQ(a.size(), b.size());
    EXPECT_EQ(a.top(), b.top());
}

TEST(stack, Swap) {
    s21::stack<int> a = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::stack<int> b;
    b.push(1);
    b.push(2);
    b.push(3);
    b.push(4);
    b.push(5);
    b.push(6);
    b.push(7);
    b.push(8);
    b.push(9);
    b.push(10);
    s21::stack<int> a_empty;
    std::stack<int> b_empty;
    a_empty.swap(a);
    b_empty.swap(b);
    EXPECT_EQ(a_empty.top(), b_empty.top());
    EXPECT_EQ(a.empty(), b.empty());
}

