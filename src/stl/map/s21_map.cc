#include "s21_map.h"

//
// Created by Oznak Banshee on 7/31/23.
//

namespace s21 {

template <typename Key, typename T>
map<Key, T>::map(const std::initializer_list<value_type> &items) {
  for (auto i = items.begin(); i != items.end(); ++i) {
    insert(*i);
  }
}

template <typename Key, typename T>
map<Key, T> &map<Key, T>::operator=(map &&other) noexcept {
  if (this != &other) {
    BinaryTree<Key, T>::operator=(std::move(other));
  }
  return *this;
}

template <typename Key, typename T>
map<Key, T> &map<Key, T>::operator=(const map &other) {
  if (this != &other) {
    BinaryTree<Key, T>::operator=(other);
  }
  return *this;
}

template <typename Key, typename T>
std::pair<typename map<Key, T>::MapIterator, bool> map<Key, T>::insert(
    const value_type &value) {
  return insert(value.first, value.second);
}

template <typename Key, typename T>
std::pair<typename map<Key, T>::MapIterator, bool> map<Key, T>::insert(
    const Key &key, const T &obj) {
  std::pair<MapIterator, bool> return_value;
  if (this->_root == nullptr) {
    this->_root = new typename BinaryTree<Key, T>::Node(key, obj);
    return_value.first = MapIterator(this->_root);
    return_value.second = true;
  } else {
    bool check_insert = this->recursiveInsert(this->_root, key, obj);
    return_value.first = find(key);
    return_value.second = check_insert;
  }
  return return_value;
}

template <typename Key, typename T>
typename map<Key, T>::value_type map<Key, T>::MapIterator::operator*() {
  if (BinaryTree<Key, T>::Iterator::_iter_node == nullptr) {
    throw std::exception_ptr(nullptr);
  }
  value_type r_val =
      std::make_pair(this->_iter_node->_key, this->_iter_node->_val);
  return r_val;
}

template <typename Key, typename T>
T &map<Key, T>::MapIterator::return_value() {
  if (BinaryTree<Key, T>::Iterator::_iter_node == nullptr) {
    throw std::exception_ptr(nullptr);
  }
  return BinaryTree<Key, T>::Iterator::_iter_node->_val;
}

template <typename Key, typename T>
typename map<Key, T>::MapIterator map<Key, T>::find(const Key &key) {
  typename BinaryTree<Key, T>::Node *node =
      BinaryTree<Key, T>::recursiveFind(BinaryTree<Key, T>::_root, key);
  return MapIterator(node);
}

template <typename Key, typename T>
std::pair<typename map<Key, T>::MapIterator, bool>
map<Key, T>::insert_or_assign(const Key &key, const T &obj) {
  auto it = find(key);
  if (it != this->end()) {
    erase(it);
    auto pr = insert(key, obj);
    pr.second = false;
    return pr;
  }
  return insert(key, obj);
}

template <typename key_type, typename mapped_type>
mapped_type &map<key_type, mapped_type>::at(const key_type &key) {
  auto iter = find(key);
  if (iter == nullptr) {
    throw std::out_of_range("there is no element for this key");
  }
  return iter.return_value();
}

template <typename Key, typename T>
T &map<Key, T>::operator[](const Key &key) {
  auto it = find(key);
  if (it == nullptr) {
    auto pr = insert(std::make_pair(key, T()));
    it = pr.first;
  }
  return it.return_value();
}

template <typename Key, typename T>
typename map<Key, T>::MapIterator map<Key, T>::begin() {
  return map<Key, T>::MapIterator(this->getMin(this->_root));
}

template <typename Key, typename T>
typename map<Key, T>::MapIterator map<Key, T>::end() {
  if (this->_root == nullptr) return begin();
  typename BinaryTree<Key, T>::Node *last_node = this->getMax(this->_root);
  MapIterator test(nullptr, last_node);
  return test;
}

template <typename Key, typename T>
typename map<Key, T>::ConstMapIterator map<Key, T>::cbegin() const {
  return map<Key, T>::ConstMapIterator(this->getMin(this->_root));
}

template <typename Key, typename T>
typename map<Key, T>::ConstMapIterator map<Key, T>::cend() const {
  if (this->_root == nullptr) return cbegin();
  typename BinaryTree<Key, T>::Node *last_node = this->getMax(this->_root);
  ConstMapIterator test(nullptr, last_node);
  return test;
}

template <typename Key, typename T>
void map<Key, T>::merge(map &other) {
  map const_tree(other);
  MapIterator const_it = const_tree.begin();
  for (; const_it != const_tree.end(); ++const_it) {
    auto key = (*const_it).first;
    auto obj = (*const_it).second;
    std::pair<MapIterator, bool> pr = insert(key, obj);
    if (pr.second) other.erase(pr.first);
  }
}

template <typename Key, typename T>
void map<Key, T>::erase(map::MapIterator pos) {
  if (this->_root == nullptr || pos._iter_node == nullptr) return;
  this->_root = this->recursiveDelete(this->_root, (*pos).first);
}

}  // namespace s21