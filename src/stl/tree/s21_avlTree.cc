//
// Created by digit_roach on 5/11/24.
//

#include "s21_avlTree.h"

#include <limits>

// constructors tree
template <typename Key, typename Value>
BinaryTree<Key, Value>::BinaryTree() {
  this->_root = nullptr;
}

template <typename Key, typename Value>
BinaryTree<Key, Value>::BinaryTree(const BinaryTree &other) {
  _root = CopyTree(other._root, nullptr);
}

template <typename Key, typename Value>
BinaryTree<Key, Value>::BinaryTree(BinaryTree &&other) noexcept {
  _root = other._root;
  other._root = nullptr;
}

template <typename Key, typename Value>
BinaryTree<Key, Value>::~BinaryTree() {
  this->clear();
}

template <typename Key, typename Value>
BinaryTree<Key, Value> &BinaryTree<Key, Value>::operator=(
    BinaryTree &&other) noexcept {
  if (this != &other) {
    _root = other._root;
    other._root = nullptr;
  }
  return *this;
}

template <typename Key, typename Value>
BinaryTree<Key, Value> &BinaryTree<Key, Value>::operator=(
    const BinaryTree &other) {
  if (this != &other) {
    BinaryTree tmp(other);
    FreeNode(_root);
    *this = std::move(tmp);
  }
  return *this;
}

// Iterator begin & end
template <typename Key, typename Value>
typename BinaryTree<Key, Value>::Iterator BinaryTree<Key, Value>::end() {
  if (_root == nullptr) return begin();

  Node *last_node = getMax(_root);
  Iterator test(nullptr, last_node);
  return test;
}

template <typename Key, typename Value>
typename BinaryTree<Key, Value>::Iterator BinaryTree<Key, Value>::begin() {
  return BinaryTree::Iterator(getMin(_root));
}

// Getters Iterator

template <typename Key, typename Value>
typename BinaryTree<Key, Value>::Node *
BinaryTree<Key, Value>::Iterator::getCurrNode() {
  if (this->_iter_node != nullptr) {
    return _iter_node;
  } else
    return _iter_last_node;
}

// Size

template <typename Key, typename Value>
bool BinaryTree<Key, Value>::empty() {
  return _root == nullptr;
}

template <typename Key, typename Value>
size_t BinaryTree<Key, Value>::size() {
  return recursiveSize(_root);
}

template <typename Key, typename Value>
size_t BinaryTree<Key, Value>::max_size() {
  return std::numeric_limits<size_t>::max() /
         sizeof(typename BinaryTree<Key, Value>::Node);
}

// INSERT and DELETE and CLEAR

template <typename Key, typename Value>
std::pair<typename BinaryTree<Key, Value>::Iterator, bool>
BinaryTree<Key, Value>::insert(const key_t &key, val_t val) {
  std::pair<Iterator, bool> return_value;
  if (_root == nullptr) {
    _root = new Node(key, val);
    return_value.first = Iterator(_root);
    return_value.second = true;

  } else {
    bool state_insert = recursiveInsert(_root, key, val);
    return_value.first = Find(key);
    return_value.second = state_insert;
  }
  return return_value;
}

template <typename Key, typename Value>
std::pair<typename BinaryTree<Key, Value>::Iterator, bool>
BinaryTree<Key, Value>::insert(const key_t &key) {
  std::pair<Iterator, bool> return_value = insert(key, key);
  return return_value;
}

template <typename Key, typename Value>
void BinaryTree<Key, Value>::erase(BinaryTree::Iterator pos) {
  if (_root == nullptr or pos._iter_node == nullptr) return;
  _root = recursiveDelete(_root, *pos);
}

template <typename Key, typename Value>
void BinaryTree<Key, Value>::clear() {
  if (this->_root != nullptr) FreeNode(_root);
  _root = nullptr;
}
// SWAP AND MERGE

template <typename Key, typename Value>
void BinaryTree<Key, Value>::merge(BinaryTree &other) {
  BinaryTree const_tree(other);
  Iterator const_iter = const_tree.begin();
  while (const_iter != const_tree.end()) {
    std::pair<Iterator, bool> pr = insert(*const_iter);
    if (pr.second) other.erase(pr.first);
    ++const_iter;
  }
}

template <typename Key, typename Value>
void BinaryTree<Key, Value>::swap(BinaryTree &other) {
  std::swap(_root, other._root);
}

// FIND AND CONTAINS

template <typename Key, typename Value>
typename BinaryTree<Key, Value>::Iterator BinaryTree<Key, Value>::Find(
    const key_t key) {
  Node *exact_node = recursiveFind(_root, key);
  return Iterator(exact_node);
}

template <typename Key, typename Value>
bool BinaryTree<Key, Value>::contains(const key_t key) {
  Node *contain_node = recursiveFind(_root, key);
  return contain_node != nullptr;
}

// Iterator

template <typename Key, typename Value>
typename BinaryTree<Key, Value>::Node *
BinaryTree<Key, Value>::Iterator::_moveForward(BinaryTree::Node *node) {
  if (node->_right != nullptr) {
    return getMin(node->_right);
  }
  Node *parent = node->_parent;
  while (parent != nullptr && node == parent->_right) {
    node = parent;
    parent = parent->_parent;
  }
  return parent;
}

template <typename Key, typename Value>
typename BinaryTree<Key, Value>::Node *
BinaryTree<Key, Value>::Iterator::_moveBack(BinaryTree::Node *node) {
  if (node->_left != nullptr) {
    return getMax(node->_left);
  }
  Node *parent = node->_parent;
  while (parent != nullptr && node == parent->_left) {
    node = parent;
    parent = node->_parent;
  }
  return parent;
}

template <typename Key, typename Value>
BinaryTree<Key, Value>::Iterator::Iterator() {
  _iter_node = nullptr;
  _iter_last_node = nullptr;
}

template <typename Key, typename Value>
BinaryTree<Key, Value>::Iterator::Iterator(Node *node, Node *last_node) {
  _iter_node = node;
  _iter_last_node = last_node;
}

template <typename Key, typename Value>
typename BinaryTree<Key, Value>::Iterator &
BinaryTree<Key, Value>::Iterator::operator++() {
  Node *tmp = nullptr;
  if (_iter_node == nullptr) {
    throw std::exception_ptr();
  }
  _iter_node = _moveForward(_iter_node);
  if (_iter_node == nullptr) {
    _iter_last_node = tmp;
  }
  return *this;
}

template <typename Key, typename Value>
typename BinaryTree<Key, Value>::Iterator
BinaryTree<Key, Value>::Iterator::operator++(int) {
  Iterator temp = *this;
  operator++();
  return temp;
}

template <typename Key, typename Value>
typename BinaryTree<Key, Value>::Iterator &
BinaryTree<Key, Value>::Iterator::operator--() {
  if (_iter_node == nullptr && _iter_last_node != nullptr) {
    *this = _moveBack(_iter_last_node);
    return *this;
  }
  _iter_node = _moveBack(_iter_node);
  return *this;
}

template <typename Key, typename Value>
typename BinaryTree<Key, Value>::Iterator
BinaryTree<Key, Value>::Iterator::operator--(int) {
  Iterator temp = *this;
  operator--();
  return temp;
}

template <typename Key, typename Value>
bool BinaryTree<Key, Value>::Iterator::operator==(
    const BinaryTree::Iterator &iter) {
  return _iter_node == iter._iter_node;
}

template <typename Key, typename Value>
bool BinaryTree<Key, Value>::Iterator::operator!=(
    const BinaryTree::Iterator &iter) {
  return _iter_node != iter._iter_node;
}

// SUPPORT

// Node

template <typename Key, typename Value>
BinaryTree<Key, Value>::Node::Node(Key key, val_t value) {
  _key = key;
  _val = value;
}

template <typename Key, typename Value>
BinaryTree<Key, Value>::Node::Node(Key key, val_t value, Node *node) {
  _key = key;
  _val = value;
  _parent = node;
}

// RECURSIVE SUPPORT FOR AVL_TREE CONSTRUCTORS

template <typename Key, typename Value>
typename BinaryTree<Key, Value>::Node *BinaryTree<Key, Value>::CopyTree(
    BinaryTree::Node *node, BinaryTree::Node *parent) {
  if (node == nullptr) return nullptr;
  Node *new_node = new Node(node->_key, node->_val, parent);
  new_node->_left = CopyTree(node->_left, new_node);
  new_node->_right = CopyTree(node->_right, new_node);
  return new_node;
}

template <typename Key, typename Value>
void BinaryTree<Key, Value>::FreeNode(Node *node) {  // Delete Nods
  if (node == nullptr) return;
  FreeNode(node->_left);  //Рекурсивная удаление меньших наследника
  FreeNode(node->_right);  // Рекурсивная удаление больших наследника
  delete node;  // Удаление родителя
}

// AVL BALANCE

template <typename Key, typename Value>
int BinaryTree<Key, Value>::getHeight(BinaryTree::Node *node) {
  return node == nullptr ? -1 : node->_height;  // У ноды у которой нет
                                                // наследников высота равна -1
  // Иначе мы передадим ноду, которая имеет ввысоту
}

template <typename Key, typename Value>
int BinaryTree<Key, Value>::getBalance(BinaryTree::Node *node) {
  return node == nullptr
             ? 0
             : getHeight(node->_right) -
                   getHeight(node->_left);  // У несуществуюшей ноды баланс 0
  // Считаем баланс дерева по формуле
}

template <typename Key, typename Value>
void BinaryTree<Key, Value>::setHeight(BinaryTree::Node *node) {
  int height_left, height_right;
  height_left = getHeight(node->_left);
  height_right = getHeight(node->_right);
  node->_height = std::max(height_left, height_right) +
                  1;  // Вычисление высоты текушей ноды
}

template <typename Key, typename Value>
void BinaryTree<Key, Value>::swapVal(
    BinaryTree::Node *a,
    BinaryTree::Node *b) {  // Свап значений узлов дерева
  std::swap(a->_key, b->_key);
  std::swap(a->_val, b->_val);
}

template <typename Key, typename Value>
void BinaryTree<Key, Value>::rightRotate(
    BinaryTree::Node *node) {  // Правый поворот дерева
  Node *new_left = node->_left->_left;
  Node *new_right_right = node->_right;
  Node *new_right_left = node->_left->_right;

  swapVal(node, node->_left);
  node->_right = node->_left;

  node->_left = new_left;
  if (node->_left) {
    node->_left->_parent = node;
  }

  node->_right->_left = new_right_left;
  if (node->_right->_left) {
    node->_right->_left->_parent = node->_right;
  }

  node->_right->_right = new_right_right;
  if (node->_right->_right) {
    node->_right->_right->_parent = node->_right;
  }

  setHeight(node->_right);
  setHeight(node);
}

template <typename Key, typename Value>
void BinaryTree<Key, Value>::leftRotate(BinaryTree::Node *node) {
  Node *new_right = node->_right->_right;
  Node *new_left_left = node->_left;
  Node *new_left_right = node->_right->_left;

  swapVal(node, node->_right);
  node->_left = node->_right;

  node->_right = new_right;
  if (node->_right) {
    node->_right->_parent = node;
  }

  node->_left->_right = new_left_right;
  if (node->_left->_right) {
    node->_left->_right->_parent = node->_left;
  }

  node->_left->_left = new_left_left;
  if (node->_left->_left) {
    node->_left->_left->_parent = node->_left;
  }

  setHeight(node->_left);
  setHeight(node);
}

template <typename Key, typename Value>
void BinaryTree<Key, Value>::balance(
    Node *node) {  // правила балансировки чтобы понять какой вид поворота нужен
  int balance = getBalance(node);
  if (balance == -2) {
    if (getBalance(node->_left) == 1) leftRotate(node->_left);
    rightRotate(node);
  } else if (balance == 2) {
    if (getBalance(node->_right) == -1) rightRotate(node->_right);
    leftRotate(node);
  }
}

// MIN AND MAX IN TREE

template <typename Key, typename Value>
typename BinaryTree<Key, Value>::Node *BinaryTree<Key, Value>::getMin(
    BinaryTree<Key, Value>::Node *node) {
  if (node == nullptr) return nullptr;
  if (node->_left == nullptr) return node;
  return getMin(node->_left);
}

template <typename Key, typename Value>
typename BinaryTree<Key, Value>::Node *BinaryTree<Key, Value>::getMax(
    BinaryTree<Key, Value>::Node *node) {
  if (node == nullptr) return nullptr;
  if (node->_right == nullptr) return node;
  return getMax(node->_right);
}

// RECURSIVE SUPPORT FUNCTIONS

template <typename Key, typename Value>
size_t BinaryTree<Key, Value>::recursiveSize(BinaryTree::Node *node) {
  if (node == nullptr) return 0;
  size_t left_size = recursiveSize(node->_left);
  size_t right_size = recursiveSize(node->_right);
  return 1 + left_size + right_size;
}

template <typename Key, typename Value>
bool BinaryTree<Key, Value>::recursiveInsert(BinaryTree::Node *node,
                                             const BinaryTree::key_t key,
                                             BinaryTree::val_t val) {
  bool state_insert = false;
  if (key < node->_key) {
    if (node->_left == nullptr) {
      node->_left = new Node(key, val, node);
      state_insert = true;
    } else {
      state_insert = recursiveInsert(node->_left, key, val);
    }
  } else if (key > node->_key) {
    if (node->_right == nullptr) {
      node->_right = new Node(key, val, node);
      state_insert = true;
    } else {
      state_insert = recursiveInsert(node->_right, key, val);
    }
  } else if (key == node->_key) {
    return state_insert;  // инсерт не произошел потому что такой ключ был в
                          // дереве
  }
  setHeight(node);
  balance(node);
  return state_insert;
}

template <typename Key, typename Value>
typename BinaryTree<Key, Value>::Node *BinaryTree<Key, Value>::recursiveDelete(
    BinaryTree::Node *node, BinaryTree::key_t key) {
  if (node == nullptr) return nullptr;
  if (key < node->_key) {
    node->_left = recursiveDelete(node->_left, key);
  } else if (key > node->_key) {
    node->_right = recursiveDelete(node->_right, key);
  } else {
    if (node->_left == nullptr || node->_right == nullptr) {
      Node *node_right = node->_right;
      Node *node_left = node->_left;
      Node *node_parent = node->_parent;
      delete node;
      if (node_left == nullptr) {
        node = node_right;
      } else {
        node = node_left;
      }
      if (node != nullptr) node->_parent = node_parent;
    } else {
      Node *min_in_right = getMin(node->_right);
      node->_key = min_in_right->_key;
      node->_val = min_in_right->_val;
      node->_right = recursiveDelete(node->_right, min_in_right->_key);
    }
  }
  if (node != nullptr) {
    setHeight(node);
    balance(node);
  }
  return node;
}

template <typename Key, typename Value>
typename BinaryTree<Key, Value>::Node *BinaryTree<Key, Value>::recursiveFind(
    BinaryTree::Node *node, const BinaryTree::key_t key) {
  if (node == nullptr || node->_key == key) return node;
  if (key > node->_key) {
    return recursiveFind(node->_right, key);
  } else {
    return recursiveFind(node->_left, key);
  }
}

template <typename Key, typename Value>
Value BinaryTree<Key, Value>::Iterator::operator*() {
  if (_iter_node == nullptr) throw std::exception_ptr();
  return _iter_node->_key;
}
