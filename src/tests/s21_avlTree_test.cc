#include "tests.h"
#include <iostream>
template <typename KeyValue>
bool IsTypeConst() {
  return std::is_const<KeyValue>::value;
}

TEST(TreeTest, Constructor_branch_test_1) {
  BinaryTree<int, int> root;
    auto  iter = root.begin();
    EXPECT_EQ(iter.getCurrNode(), nullptr);
}

TEST(TreeTest, Constructor_branch_test_2_const) {
    const int a_key = 1;
    const char b_value = 't';
    BinaryTree<int, char> root;
    root.insert(a_key, b_value);
    auto iter = root.begin();
    auto curr_node = iter.getCurrNode();
    EXPECT_EQ(curr_node->_val, 't');
    EXPECT_EQ(curr_node->_key, 1);
    EXPECT_EQ(curr_node->_left, nullptr);
    EXPECT_EQ(curr_node->_right, nullptr);
    EXPECT_EQ(curr_node->_parent, nullptr);
    EXPECT_EQ(curr_node->_height, 0);
    EXPECT_EQ(root.size(), 1);

}



TEST(TreeTest, Constructor_Iterator_test_1_normal) {
  BinaryTree<int, int> test_tree;
  test_tree.insert(10, 0);
  test_tree.insert(6, 0);
  auto bebra = test_tree.begin();
  EXPECT_EQ(*bebra, 6);
  EXPECT_EQ(bebra.getCurrNode()->_val, 0);
}

TEST(TreeTest, Constructor_Iterator_test_1_const) {
  const int a_key = 10;
  const int b_value = 0;
  BinaryTree<int, int> test_tree;
  test_tree.insert(a_key, b_value);
  auto bebra = test_tree.begin();
  EXPECT_EQ(*bebra, 10);
  EXPECT_EQ( bebra.getCurrNode()->_val, 0);
}

TEST(TreeTest, Constructor_Iterator_copy_test_1) {
  BinaryTree<int, int> tree;
  tree.insert(10, 20);
  tree.insert(5, 10);
  auto original = tree.begin();
  auto copy = original;
  EXPECT_EQ(copy.getCurrNode(), original.getCurrNode());
  ++original;
  EXPECT_NE(copy.getCurrNode(), original.getCurrNode());
}

TEST(TreeTest, Constructor_Iterator_copy_pris_test_1) {
  BinaryTree<int, int> tree;
  BinaryTree<int, int> tree_1;
  tree.insert(10, 20);
  tree.insert(5, 10);
  tree_1.insert(20, 20);
  tree_1.insert(15, 10);
  auto original = tree.begin();
  auto copy = tree_1.begin();
  copy = original;
  EXPECT_EQ(copy.getCurrNode(), original.getCurrNode());
  ++original;
  EXPECT_NE(copy.getCurrNode(), original.getCurrNode());
}

TEST(TreeTest, Constructor_Iterator_destructor_test_1) {
  BinaryTree<int, int> test_tree;
  test_tree.insert(10, 20);
  test_tree.insert(5, 10);
  test_tree.~BinaryTree();
  EXPECT_TRUE(test_tree.empty());
}

TEST(TreeTest, CIterator_move_multi_test_1) {
  BinaryTree<int, int> test_tree;
  test_tree.insert(10, 0);
  test_tree.insert(6, 0);
  test_tree.insert(15, 0);
  test_tree.insert(7, 0);
  test_tree.insert(11, 0);
  test_tree.insert(20, 0);
  test_tree.insert(4, 0);
  auto bebra = test_tree.begin();
  bebra++;
  bebra++;
  EXPECT_EQ(*bebra, 7);
}

TEST(TreeTest, Iterator_move_one_test_1) {
  BinaryTree<int, int> test_tree;
  test_tree.insert(10, 0);
  test_tree.insert(6, 0);
  test_tree.insert(15, 0);
  test_tree.insert(7, 0);
  auto bebra = test_tree.begin();
  bebra++;
  EXPECT_EQ(*bebra, 7);
}

TEST(TreeTest, Iterator_move_one_post_fix_test_1) {
  BinaryTree<int, int> test_tree;
  test_tree.insert(10, 0);
  test_tree.insert(6, 0);
  test_tree.insert(15, 0);
  test_tree.insert(7, 0);
  auto bebra = test_tree.begin();
  ++bebra;
  EXPECT_EQ(*bebra, 7);
}
TEST(TreeTest, Iterator_decrement_move_one_test_1) {
    BinaryTree<int, int> test_tree;
    test_tree.insert(10, 0);
    test_tree.insert(6, 0);
    test_tree.insert(15, 0);
    test_tree.insert(7, 0);
    auto bebra = test_tree.end();
    EXPECT_EQ(bebra.getCurrNode()->_key, 15);
    bebra--;
    EXPECT_EQ(bebra.getCurrNode()->_key, 10);
    bebra--;
    EXPECT_EQ(bebra.getCurrNode()->_key, 7);

}

TEST(TreeTest, Iterator_decrement_move_one_pre_fix_test_1) {
  BinaryTree<int, int> test_tree;
  test_tree.insert(10, 0);
  test_tree.insert(6, 0);
  test_tree.insert(15, 0);
  test_tree.insert(7, 0);
  auto bebra = test_tree.end();
  EXPECT_EQ(bebra.getCurrNode()->_key, 15);
  --bebra;
  EXPECT_EQ(bebra.getCurrNode()->_key, 10);
  --bebra;
  EXPECT_EQ(bebra.getCurrNode()->_key, 7);
}

TEST(TreeTest, Iterator_compare_test_1) {
  BinaryTree<int, int> test_tree;
  BinaryTree<int, int> test_tree_1;
  test_tree.insert(10, 0);
  test_tree.insert(6, 0);
  test_tree.insert(15, 0);
  test_tree.insert(7, 0);
  auto bebra = test_tree.begin();
  auto bebra_1 = test_tree.begin();
  bebra++;
  bebra_1++;
  EXPECT_TRUE(bebra == bebra_1);
}

TEST(TreeTest, Iterator_not_compare_test_1) {
  BinaryTree<int, int> test_tree;
  BinaryTree<int, int> test_tree_1;
  test_tree.insert(10, 0);
  test_tree.insert(6, 0);
  test_tree.insert(15, 0);
  test_tree.insert(7, 0);
  auto bebra = test_tree.begin();
  auto bebra_1 = test_tree.begin();
  bebra++;
  EXPECT_FALSE(bebra == bebra_1);
}

TEST(TreeTest, Iterator_raziemen_test_1) {
  BinaryTree<int, int> test_tree;
  test_tree.insert(10, 0);
  auto bebra = test_tree.begin();
//  auto val = *bebra;
  EXPECT_EQ(*bebra, 10);
}

TEST(TreeTest, Iterator_strelochka_test_1) {
  BinaryTree<int, int> test_tree;
  test_tree.insert(10, 20);
  auto bebra = test_tree.begin();
  EXPECT_EQ(*bebra, 10);
  EXPECT_EQ( bebra.getCurrNode()->_val, 20);
}

TEST(TreeTest, Constructor_Iterator_strelochka_test_1) {
  BinaryTree<int, int> test_tree;
  test_tree.insert(10, 20);
  auto bebra = test_tree.begin();
  EXPECT_EQ(*bebra, 10);
  EXPECT_EQ( bebra.getCurrNode()->_val, 20);
}


TEST(TreeTest, get_current_test_1) {
  BinaryTree<int, int> test_tree;
  test_tree.insert(10, 1);
  auto bebra = test_tree.begin();
  EXPECT_EQ(*bebra, 10);
}

TEST(TreeTest, const_iter_test_1) {
  const int a_key = 1;
  const int b_key = 2;
  BinaryTree<int, int> test_tree;
  test_tree.insert(a_key, b_key);
  auto bebra = test_tree.begin();
  EXPECT_EQ(*bebra, 1);
}

TEST(TreeTest, Constructor_tree_test_1) {
  BinaryTree<int, int> test_tree;
  EXPECT_TRUE(test_tree.empty());
}

TEST(TreeTest, Copy_tree_test_1) {
  BinaryTree<int, int> test_tree_1;
  test_tree_1.insert(10, 100);
  test_tree_1.insert(20, 200);
    test_tree_1.insert(30, 300);
  BinaryTree<int, int> copied_tree = test_tree_1;
  BinaryTree<int, int> copied_tree1(test_tree_1);
  auto iter_copied_tree = copied_tree.begin();
  auto iter_copied_tree2 = copied_tree1.begin();

  EXPECT_EQ(iter_copied_tree.getCurrNode()->_key, 10);
  EXPECT_EQ(iter_copied_tree.getCurrNode()->_val, 100);
    EXPECT_EQ(iter_copied_tree2.getCurrNode()->_key, 10);
    EXPECT_EQ(iter_copied_tree2.getCurrNode()->_val, 100);
  iter_copied_tree++;
  iter_copied_tree2++;
  EXPECT_EQ(iter_copied_tree.getCurrNode()->_key, 20);
  EXPECT_EQ(iter_copied_tree.getCurrNode()->_val, 200);
    EXPECT_EQ(iter_copied_tree2.getCurrNode()->_key, 20);
    EXPECT_EQ(iter_copied_tree2.getCurrNode()->_val, 200);
    iter_copied_tree++;
    iter_copied_tree2++;
    EXPECT_EQ(iter_copied_tree.getCurrNode()->_key, 30);
    EXPECT_EQ(iter_copied_tree.getCurrNode()->_val, 300);
    EXPECT_EQ(iter_copied_tree2.getCurrNode()->_key, 30);
    EXPECT_EQ(iter_copied_tree2.getCurrNode()->_val, 300);
}

TEST(TreeTest, Destructor_tree_test_1) {
  BinaryTree<int, int> test_tree_1;
  test_tree_1.insert(10, 100);
  test_tree_1.insert(20, 200);
  test_tree_1.~BinaryTree();
  EXPECT_TRUE(test_tree_1.empty());
}

TEST(TreeTest, Copy_oper_tree_test_1) {
  BinaryTree<int, int> test_tree_1;
  test_tree_1.insert(10, 100);
  test_tree_1.insert(20, 200);
  test_tree_1.insert(30, 100);
  test_tree_1.insert(40, 200);

  BinaryTree<int, int> copied_tree(test_tree_1);
  auto iter_copied_tree = copied_tree.begin();
  EXPECT_EQ(iter_copied_tree.getCurrNode()->_key, 10);
  EXPECT_EQ(iter_copied_tree.getCurrNode()->_val, 100);
  iter_copied_tree++;
  EXPECT_EQ((iter_copied_tree).getCurrNode()->_key, 20);
  EXPECT_EQ(iter_copied_tree.getCurrNode()->_val, 200);
}

TEST(TreeTest, CopyMove_tree_test_1) {
  BinaryTree<int, int> tree1;
  tree1.insert(1, 100);
  BinaryTree<int, int> tree2;
  tree2 = std::move(tree1);
  auto  aboba = tree2.begin();
  EXPECT_EQ(aboba.getCurrNode()->_key, 1);
  EXPECT_EQ(aboba.getCurrNode()->_val, 100);
}

TEST(TreeTest, insert_tree_test_1) {
  BinaryTree<int, int> test_tree;
  int answer_list[6] = {6, 19, 10, 17, 15, 23};
  int counter = 0;
  test_tree.insert(10, 17);
  test_tree.insert(6, 19);
  test_tree.insert(15, 23);
  auto bebra = test_tree.begin();
  for (int i = 0; i < 3; i++) {
    EXPECT_EQ(*bebra, answer_list[counter]);
    counter++;
    EXPECT_EQ( bebra.getCurrNode()->_val, answer_list[counter]);
    bebra++;
    counter++;
  }
}

TEST(TreeTest, Get_root_tree_test_1) {
  BinaryTree<int, int> test_tree;
  test_tree.insert(10, 17);
  auto iter = test_tree.begin();
  EXPECT_EQ(iter.getCurrNode()->_key, 10);
  EXPECT_EQ(iter.getCurrNode()->_val, 17);
}

TEST(TreeTest, swap_tree_test_1) {
  BinaryTree<int, int> tree1;
  tree1.insert(1, 2);
  tree1.insert(3, 4);
  BinaryTree<int, int> tree2;
  tree2.insert(5, 6);
  tree2.insert(7, 8);
  tree1.swap(tree2);
  auto bebra_1 = tree1.begin();
  auto bebra_2 = tree2.begin();
  EXPECT_EQ(bebra_1.getCurrNode()->_key, 5);
  EXPECT_EQ(bebra_1.getCurrNode()->_val, 6);
  EXPECT_EQ(bebra_2.getCurrNode()->_key, 1);
  EXPECT_EQ(bebra_2.getCurrNode()->_val, 2);
  bebra_1++;
  bebra_2++;
  EXPECT_EQ(bebra_1.getCurrNode()->_key, 7);
  EXPECT_EQ(bebra_1.getCurrNode()->_val, 8);
  EXPECT_EQ(bebra_2.getCurrNode()->_key, 3);
  EXPECT_EQ(bebra_2.getCurrNode()->_val, 4);
}


TEST(TreeTest, begin_tree_test_1) {
  BinaryTree<int, int> test_tree;
  test_tree.insert(10, 17);
  EXPECT_EQ(test_tree.begin().getCurrNode()->_key, 10);
  EXPECT_EQ(test_tree.begin().getCurrNode()->_val, 17);
}

TEST(TreeTest, end_tree_test_1) {
  BinaryTree<int, int> test_tree;
  test_tree.insert(10, 17);
  EXPECT_EQ(test_tree.end().getCurrNode()->_key, 10);
  EXPECT_EQ(test_tree.end().getCurrNode()->_val, 17);
}

TEST(TreeTest, Iterator_move_one_dop_test_2) {
  BinaryTree<int, int> test_tree;
  test_tree.insert(11, 0);
  test_tree.insert(20, 0);
  test_tree.insert(4, 0);
  test_tree.insert(10, 0);
  test_tree.insert(6, 0);
  test_tree.insert(15, 0);
  test_tree.insert(7, 0);
  auto bebra = test_tree.begin();
  bebra++;
  EXPECT_EQ(*bebra, 6);
}

TEST(TreeTest, Iterator_razomin_test_2) {
  BinaryTree<int, int> test_tree;
  auto bebra = test_tree.begin();
  EXPECT_ANY_THROW(*bebra);
}

TEST(TreeTest, decrement_helper_test_1) {
  BinaryTree<int, int> test_tree;
  auto bebra = test_tree.begin();
  EXPECT_ANY_THROW(*bebra);
}

TEST(TreeTest, rotate_iter_test_2) {
  BinaryTree<int, int> test_tree;
  test_tree.insert(11, 0);
  test_tree.insert(20, 0);
  test_tree.insert(15, 0);
  test_tree.insert(22, 0);
  test_tree.insert(18, 0);

  test_tree.insert(24, 0);
  test_tree.insert(10, 0);
  test_tree.insert(6, 0);
  auto bebra = test_tree.begin();
  EXPECT_EQ(*bebra, 6);
}

TEST(TreeTest, right_left_test_2) {
  BinaryTree<int, int> test_tree;
  test_tree.insert(5, 0);
  test_tree.insert(3, 0);
  test_tree.insert(4, 0);
  auto bebra = test_tree.begin();
  EXPECT_EQ(*bebra, 3);
}

TEST(TreeTest, left_right_test_2) {
  BinaryTree<int, int> test_tree;
  test_tree.insert(5, 0);
  test_tree.insert(8, 0);
  test_tree.insert(6, 0);
  auto bebra = test_tree.begin();
  EXPECT_EQ(*bebra, 5);
}

TEST(TreeTest, decrementdoper_test_2) {
  BinaryTree<int, int> test_tree;
  test_tree.insert(10, 0);
  test_tree.insert(8, 0);
  test_tree.insert(9, 0);
  test_tree.insert(12, 0);
  test_tree.insert(1, 0);
  auto bebra = test_tree.begin();
  bebra++;
  bebra++;
  bebra++;
  EXPECT_EQ(*bebra, 10);
}


TEST(TreeTest, remove_test_new_new_test_1) {
  BinaryTree<int, int> test_tree;
  test_tree.insert(5, 0);
  test_tree.insert(10, 0);
  test_tree.insert(8, 0);
  test_tree.insert(3, 0);
  test_tree.insert(6, 0);
  test_tree.insert(12, 0);
  test_tree.insert(11, 0);
  test_tree.insert(9, 0);
  test_tree.insert(-1, 0);
  test_tree.insert(-30, 0);
  test_tree.insert(-15, 0);
  test_tree.insert(245, 0);
  test_tree.insert(7, 0);
  test_tree.insert(0, 0);
  auto bebra = test_tree.begin();
  EXPECT_EQ(*bebra, -30);
}
//
//TEST(TreeTest, NullException) {
//    BinaryTree<int, int> test_tree;
//    auto iter = test_tree.begin();
//    auto iter_end = test_tree.end();
//    EXPECT_ANY_THROW(iter++);
//    EXPECT_ANY_THROW(iter_end--);
//}

