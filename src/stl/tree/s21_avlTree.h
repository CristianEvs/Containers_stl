//
// Created by digit_roach on 5/11/24.
//

#ifndef STL_S21_AVLTREE_H
#define STL_S21_AVLTREE_H

#include <iostream>
#include <utility>

template <typename Key, typename Value>
class BinaryTree {
 protected:
  struct Node;

 public:
  class Iterator;
  class ConstIterator;
  using key_t = Key;
  using val_t = Value;

  class Iterator {
   public:
    Iterator();
    Iterator(Node* node, Node* last_node = nullptr);
    Iterator& operator++();
    Iterator operator++(int);
    Iterator& operator--();
    Iterator operator--(int);
    val_t operator*();
    bool operator==(const Iterator& iter);
    bool operator!=(const Iterator& iter);
    friend class BinaryTree<Key, Value>;
    Node* getCurrNode();

   protected:
    Node* _iter_node;
    Node* _iter_last_node;
    Node* _moveForward(Node* node);
    Node* _moveBack(Node* node);
  };
  class ConstIterator : Iterator {
    ConstIterator() : Iterator(){};
    const val_t operator*() const { return Iterator::operator*(); }
  };

  BinaryTree();
  BinaryTree(const BinaryTree& other);
  BinaryTree(BinaryTree&& other) noexcept;
  ~BinaryTree();

  BinaryTree<Key, Value>& operator=(BinaryTree&& other) noexcept;
  BinaryTree<Key, Value>& operator=(const BinaryTree& other);
  Iterator begin();
  Iterator end();
  bool empty();
  size_t size();
  size_t max_size();
  void clear();
  std::pair<Iterator, bool> insert(const key_t& key, val_t val);
  std::pair<Iterator, bool> insert(const key_t& key);
  void erase(Iterator pos);
  void swap(BinaryTree& other);
  void merge(BinaryTree& other);
  bool contains(const key_t key);
  Iterator Find(const key_t key);

 protected:
  struct Node {
    Node(key_t key, val_t val);
    Node(key_t key, val_t val, Node* parent);
    key_t _key;
    val_t _val;
    Node* _left = nullptr;
    Node* _right = nullptr;
    Node* _parent = nullptr;
    int _height = 0;
    friend BinaryTree<key_t, val_t>;
  };
  Node* _root;
  // SUPPORT FOR CONSTRUCTORS
  void FreeNode(Node* node);
  Node* CopyTree(Node* node, Node* parent);
  // AVL BALANCE
  void swapVal(Node* a, Node* b);
  void rightRotate(Node* node);
  void leftRotate(Node* node);
  int getBalance(Node* node);
  int getHeight(Node* node);
  void setHeight(Node* node);
  // Min & Max
  static Node* getMin(Node* node);
  static Node* getMax(Node* node);
  void balance(Node* node);
  // Recursive
  bool recursiveInsert(Node* node, const key_t key, val_t val);
  Node* recursiveDelete(Node* node, key_t key);
  size_t recursiveSize(Node* node);
  Node* recursiveFind(Node* node, const key_t key);
};

#endif  // STL_S21_AVLTREE_H
