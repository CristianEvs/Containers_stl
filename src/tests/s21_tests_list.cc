#include <gtest/gtest.h>
#include <list>
#include "tests.h"


TEST(VectorMethods, Reserve_IncreaseCapacity) {
 s21::list<int> lst(1);
lst.push_front(5);
 EXPECT_EQ(lst.front(),5);
}

TEST(ListTest, DefaultConstructor) {
  s21::list<int> our_list;
  std::list<int> std_list;
  EXPECT_EQ(our_list.empty(), std_list.empty());
}

TEST(ListTest, SizeConstructor) {
  s21::list<int> our_list(5);
  std::list<int> std_list(5);
  EXPECT_EQ(our_list.size(), std_list.size());
}

TEST(ListTest, InitializerListConstructor) {
  s21::list<int> our_list = {1, 2, 3};
  std::list<int> std_list = {1, 2, 3};
  EXPECT_EQ(our_list.size(), std_list.size());
  EXPECT_EQ(our_list.front(), std_list.front());
  EXPECT_EQ(our_list.back(), std_list.back());
}

TEST(ListTest, ConstructorMove) {
  s21::list<int> our_list = {1, 2, 3};
  std::list<int> std_list = {1, 2, 3};
  s21::list<int> our_copy(std::move(our_list));
  std::list<int> std_copy(std::move(std_list));
  EXPECT_EQ(our_copy.size(), std_copy.size());
  EXPECT_EQ(our_copy.back(), std_copy.back());
}


TEST(ListTest, Size) {
  s21::list<int> our_list = {1, 2, 3};
  std::list<int> std_list = {1, 2, 3};
  EXPECT_EQ(our_list.size(), std_list.size());
}

TEST(ListTest, PushFront) {
  s21::list<int> our_list;
  std::list<int> std_list;
  our_list.push_front(1);
  std_list.push_front(1);
  EXPECT_EQ(our_list.front(), std_list.front());
  our_list.push_front(2);
  std_list.push_front(2);
  EXPECT_EQ(our_list.front(), std_list.front());
  our_list.push_front(3);
  std_list.push_front(3);
  EXPECT_EQ(our_list.front(), std_list.front());
}

TEST(ListTest, PushBack) {
  s21::list<int> our_list;
  std::list<int> std_list;
  our_list.push_back(1);
  std_list.push_back(1);
  EXPECT_EQ(our_list.front(), std_list.front());
  our_list.push_back(2);
  std_list.push_back(2);
  EXPECT_EQ(our_list.front(), std_list.front());
  our_list.push_back(3);
  std_list.push_back(3);
  EXPECT_EQ(our_list.front(), std_list.front());
}

TEST(ListTest, PopFront) {
  s21::list<int> our_list;
  std::list<int> std_list;
  our_list.push_back(1);
  std_list.push_back(1);
  EXPECT_EQ(our_list.front(), std_list.front());
  EXPECT_EQ(our_list.back(), std_list.back());
  our_list.push_back(2);
  std_list.push_back(2);
  EXPECT_EQ(our_list.front(), std_list.front());
  our_list.push_back(3);
  std_list.push_back(3);
  EXPECT_EQ(our_list.front(), std_list.front());
  our_list.pop_front();
  std_list.pop_front();
  EXPECT_EQ(our_list.front(), std_list.front());

}

TEST(ListTest, PopBack) {
  s21::list<int> our_list;
  std::list<int> std_list;
  our_list.push_back(1);
  std_list.push_back(1);
  EXPECT_EQ(our_list.front(), std_list.front());
  EXPECT_EQ(our_list.back(), std_list.back());
  our_list.push_back(2);
  std_list.push_back(2);
  EXPECT_EQ(our_list.front(), std_list.front());
  EXPECT_EQ(our_list.back(), std_list.back());
  our_list.push_back(3);
  std_list.push_back(3);
  EXPECT_EQ(our_list.front(), std_list.front());
  our_list.pop_back();
  std_list.pop_back();
  EXPECT_EQ(our_list.front(), std_list.front());
}



TEST(ListTest, Swap) {
  s21::list<int> our_list_first = {1};
  s21::list<int> our_list_second = {2, 3, 4, 5};
  std::list<int> std_list_first = {1};
  std::list<int> std_list_second = {2, 3, 4, 5};
  our_list_first.swap(our_list_second);
  std_list_first.swap(std_list_second);
  EXPECT_EQ(our_list_first.front(), std_list_first.front());
}


TEST(ListTest, IteratorBegin) {
  s21::list<int> our_list = {1, 2, 3};
  std::list<int> std_list = {1, 2, 3};
  s21::list<int>::iterator our_it(our_list.begin());
  std::list<int>::iterator std_it(std_list.begin());
  EXPECT_EQ(*our_it, *std_it);
}


TEST(ListTest, IteratorBeginPlusAndMinus) {
  s21::list<int> our_list = {1, 2, 3};
  std::list<int> std_list = {1, 2, 3};
  s21::list<int>::iterator our_it;
  our_it = our_list.begin();
  ++our_it;
  std::list<int>::iterator std_it;
  std_it = std_list.begin();
  ++std_it;
  EXPECT_EQ(*our_it, *std_it);
  --our_it;
  --std_it;
  EXPECT_EQ(*our_it, *std_it);
}

TEST(ListTest, IteratorEnd_Last) {
  s21::list<int> our_list = {1, 2, 3};
  std::list<int> std_list = {1, 2, 3};
  s21::list<int>::iterator our_it;
  our_it = our_list.end();
  std::list<int>::iterator std_it;
  std_it = std_list.end();
  --std_it;
  EXPECT_EQ(*our_it, *std_it);
}

TEST(ListTest, IteratorEquals) {
  s21::list<int> first_list = {1, 2, 3};
  s21::list<int>::iterator our_it_first;
  our_it_first = first_list.begin();
  s21::list<int>::iterator our_it_second;
  our_it_second = first_list.begin();
  EXPECT_TRUE(our_it_first == our_it_second);
  EXPECT_TRUE(our_it_first >= our_it_second);
  EXPECT_TRUE(our_it_first <= our_it_second);
  ++our_it_second;
  EXPECT_TRUE(our_it_first != our_it_second);
  EXPECT_TRUE(our_it_second > our_it_first);
  EXPECT_TRUE(our_it_second >= our_it_first);
  EXPECT_TRUE(our_it_first < our_it_second);
  EXPECT_TRUE(our_it_first <= our_it_second);
}


// //РУгается санитайз

TEST(ListTest, Insert) {
  s21::list<int> our_list;
  std::list<int> std_list;
  s21::list<int>::iterator our_it;
  our_it = our_list.begin();
  std::list<int>::iterator std_it;
  std_it = std_list.begin();
  our_list.insert(our_it, 5);
  std_list.insert(std_it, 5);
  EXPECT_EQ(our_list.front(), std_list.front());
  EXPECT_EQ(our_list.back(), std_list.back());
  our_list.insert(our_it, 7);
  std_list.insert(std_it, 7);
  our_list.insert(our_it, 9);
  std_list.insert(std_it, 9);
  EXPECT_EQ(our_list.front(), std_list.front());
  EXPECT_EQ(our_list.back(), std_list.back());
}
// -------------------------------------------------------------------------- Последнее изменение
//  РУгается санитайз
TEST(ListTest, Erase) {
  s21::list<int> our_list(5);
  our_list[0]=1;
  our_list[1]=2;
  our_list[2]=3;
  our_list[3]=4;
  our_list[4]=5;
  std::list<int> std_list = {1, 2, 3, 4, 5};
  our_list.erase(our_list.begin());
  std_list.erase(std_list.begin());
  EXPECT_EQ(our_list.front(), std_list.front());
  EXPECT_EQ(our_list.back(), std_list.back());
  s21::list<int>::iterator our_it;
  our_it = our_list.begin();
  ++our_it;
  std::list<int>::iterator std_it;
  std_it = std_list.begin();
  ++std_it;
  EXPECT_EQ(our_list.front(), std_list.front());
  EXPECT_EQ(our_list.back(), std_list.back());
}

TEST(ListTest, Splice) {
  s21::list<int> our_list_first = {1};
  s21::list<int> our_list_second = {2, 3, 4, 5};
  std::list<int> std_list_first = {1};
  std::list<int> std_list_second = {2, 3, 4, 5};
  s21::list<int>::const_iterator our_it(our_list_first.cbegin());
  std::list<int>::const_iterator std_it = std_list_first.begin();
  our_list_first.splice(our_it, our_list_second);
  std_list_first.splice(std_it, std_list_second);
  EXPECT_EQ(our_list_first.front(), std_list_first.front());
  EXPECT_EQ(our_list_first.back(), std_list_first.back());
}



TEST(ListTest, Merge) {
  s21::list<int> our_list_first = {1};
  s21::list<int> our_list_second = {2, 3, 4, 5};
  std::list<int> std_list_first = {1};
  std::list<int> std_list_second = {2, 3, 4, 5};
  our_list_first.merge(our_list_second);
  std_list_first.merge(std_list_second);
  EXPECT_EQ(our_list_first.front(), std_list_first.front());
  EXPECT_EQ(our_list_first.back(), std_list_first.back());
  // EXPECT_EQ(our_list_second.empty(), std_list_second.empty());
} 
// ------------------------------------------------------------------------------

TEST(ListTest, Reverse) {
  s21::list<int> our_list = {1, 2, 3, 4, 5};
  std::list<int> std_list = {1, 2, 3, 4, 5};
  our_list.reverse();
  std_list.reverse();
  EXPECT_EQ(our_list.front(), std_list.front());
  EXPECT_EQ(our_list.back(), std_list.back());
}

TEST(ListTest, Unique) {
  s21::list<int> our_list = {1, 2, 2, 3, 3};
  std::list<int> std_list = {1, 2, 2, 3, 3};
  s21::list<int>::iterator our_it;
  std::list<int>::iterator std_it;
  our_list.unique();
  std_list.unique();
  our_it = our_list.begin();
  std_it = std_list.begin();
  EXPECT_EQ(*our_it, *std_it);
  ++our_it;
  ++std_it;
  EXPECT_EQ(*our_it, *std_it);
  ++our_it;
  ++std_it;
  EXPECT_EQ(*our_it, *std_it);
}

TEST(ListTest, MaxSize) {
    s21::list<int> my_list;
    ASSERT_EQ(my_list.max_size(), 768614336404564650);
}

TEST(ListTest, Sort) {
  s21::list<int> our_list = {2, 4, 1, 3, 5};
  std::list<int> std_list = {2, 4, 1, 3, 5};
  s21::list<int>::iterator our_it;
  std::list<int>::iterator std_it;
  our_list.sort();
  std_list.sort();
  our_it = our_list.begin();
  std_it = std_list.begin();
  EXPECT_EQ(*our_it, *std_it);
  ++our_it;
  ++std_it;
  EXPECT_EQ(*our_it, *std_it);
  ++our_it;
  ++std_it;
  EXPECT_EQ(*our_it, *std_it);
  ++our_it;
  ++std_it;
  EXPECT_EQ(*our_it, *std_it);
  ++our_it;
  ++std_it;
  EXPECT_EQ(*our_it, *std_it);
}


TEST(ListTest, Reverse_4) {
  s21::list<int> our_list = {1, 2, 3, 4, 5};
  std::list<int> std_list = {1, 2, 3, 4, 5};
  our_list.reverse();
  std_list.reverse();
  EXPECT_EQ(our_list.front(), std_list.front());
  EXPECT_EQ(our_list.back(), std_list.back());
}


TEST(ListTest, OperatorMove) {
  s21::list<int> our_list = {1, 2, 3};
  std::list<int> std_list = {1, 2, 3};
  s21::list<int> our_copy;
  our_copy = std::move(our_list);
  std::list<int> std_copy;
  std_copy = std::move(std_list);
  EXPECT_EQ(our_copy.front(), std_copy.front());
  EXPECT_EQ(our_copy.back(), std_copy.back());
}

TEST(ListTest_12, Insert_2) {
    s21::list<int> our_list;
    std::list<int> std_list;
    s21::list<int>::iterator our_it = our_list.begin();
    std::list<int>::iterator std_it = std_list.begin();
    our_list.insert(our_it, 5);
    std_list.insert(std_it, 5);
    EXPECT_EQ(our_list.front(), std_list.front());
    EXPECT_EQ(our_list.back(), std_list.back());
    our_it = our_list.begin();
    std_it = std_list.begin();
    our_list.insert(our_it, 7);
    std_list.insert(std_it, 7);
    EXPECT_EQ(our_list.front(), std_list.front());
    EXPECT_EQ(our_list.back(), std_list.back());

    our_it = ++our_list.begin();
    std_it = ++std_list.begin();
    our_list.insert(our_it, 11);
    std_list.insert(std_it, 11);
    EXPECT_EQ(our_list.front(), std_list.front());
    EXPECT_EQ(our_list.back(), std_list.back());
}


TEST(ListTest_4, Splice_4) {
    {
        s21::list<int> our_list_first = {1};
        s21::list<int> our_list_second = {2, 3, 4, 5};
        std::list<int> std_list_first = {1};
        std::list<int> std_list_second = {2, 3, 4, 5};
        s21::list<int>::const_iterator our_it = our_list_first.cbegin();
        std::list<int>::const_iterator std_it = std_list_first.begin();
        our_list_first.splice(our_it, our_list_second);
        std_list_first.splice(std_it, std_list_second);
        EXPECT_EQ(our_list_first.front(), std_list_first.front());
        EXPECT_EQ(our_list_first.back(), std_list_first.back());
    }
    {
        s21::list<int> our_list_first = {1};
        s21::list<int> our_list_second = {2, 3, 4, 5};
        std::list<int> std_list_first = {1};
        std::list<int> std_list_second = {2, 3, 4, 5};
        s21::list<int>::const_iterator our_it = our_list_first.cend();
        std::list<int>::const_iterator std_it = std_list_first.end();
        std_it--;
        our_list_first.splice(our_it, our_list_second);
        std_list_first.splice(std_it, std_list_second);
        EXPECT_EQ(our_list_first.front(), std_list_first.front());
        EXPECT_EQ(our_list_first.back(), std_list_first.back());
    }
    {
        s21::list<int> our_list_first = {1, 6};
        s21::list<int> our_list_second = {2, 3, 4, 5};
        std::list<int> std_list_first = {1, 6};
        std::list<int> std_list_second = {2, 3, 4, 5};
        s21::list<int>::const_iterator our_it = ++our_list_first.cbegin();
        std::list<int>::const_iterator std_it = ++std_list_first.begin();
        our_list_first.splice(our_it, our_list_second);
        std_list_first.splice(std_it, std_list_second);
        EXPECT_EQ(our_list_first.front(), std_list_first.front());
        EXPECT_EQ(our_list_first.back(), std_list_first.back());
    }
}

//int main(int argc, char **argv) {
//  ::testing::InitGoogleTest(&argc, argv);
//  return RUN_ALL_TESTS();
//}