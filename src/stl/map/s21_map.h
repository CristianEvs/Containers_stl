#ifndef MAP_H
#define MAP_H

#include <initializer_list>
#include <iostream>
#include <vector>

#include "../tree/s21_avlTree.h"
namespace s21 {
template <typename Key, typename T>
class map : public BinaryTree<Key, T> {
 public:
  class MapIterator;
  class ConstMapIterator;

  using key_type = Key;
  using mapped_type = T;
  using value_type = std::pair<const key_type, mapped_type>;

  map() : BinaryTree<Key, T>(){};
  map(std::initializer_list<value_type> const &items);
  map(const map &other) : BinaryTree<Key, T>(other){};
  map(map &&other) noexcept : BinaryTree<Key, T>(std::move(other)){};
  map &operator=(map &&other) noexcept;
  map &operator=(const map &other);
  ~map() = default;

  T &at(const Key &key);
  T &operator[](const Key &key);
  std::pair<MapIterator, bool> insert(const value_type &value);
  std::pair<MapIterator, bool> insert(const Key &key, const T &obj);
  std::pair<MapIterator, bool> insert_or_assign(const Key &key, const T &obj);

  MapIterator begin();
  MapIterator end();
  ConstMapIterator cbegin() const;
  ConstMapIterator cend() const;
  void merge(map &other);
  void erase(MapIterator pos);
  class MapIterator : public BinaryTree<Key, T>::Iterator {
   public:
    friend class map;
    MapIterator() : BinaryTree<Key, T>::Iterator(){};
    MapIterator(typename BinaryTree<Key, T>::Node *node,
                typename BinaryTree<Key, T>::Node *last_node = nullptr)
        : BinaryTree<Key, T>::Iterator(node, last_node = nullptr){};
    value_type operator*();

   protected:
    T &return_value();
  };
  class ConstMapIterator : public MapIterator {
   public:
    friend class map;
    ConstMapIterator() : MapIterator(){};
    ConstMapIterator(typename BinaryTree<Key, T>::Node *node,
                     typename BinaryTree<Key, T>::Node *past_node = nullptr)
        : MapIterator(node, past_node = nullptr){};
    const value_type &operator*() const { return MapIterator::operator*(); };
  };

 private:
  MapIterator find(const Key &key);
};

}  // namespace s21

#endif  // MAP_H