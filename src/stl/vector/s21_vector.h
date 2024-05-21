#ifndef VECTOR_H
#define VECTOR_H

#include <initializer_list>
#include <iostream>

namespace s21 {
template <typename T>
class vector {
 public:
  // Vector Member type
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using iterator = T *;
  using const_iterator = const T *;
  using size_type = size_t;

  // Vector Member functions
  vector();
  vector(size_type n);
  vector(std::initializer_list<value_type> const &items);
  vector(const vector &v);
  vector(vector &&v);
  ~vector();
  vector &operator=(vector &&v);

  // Vector Element access
  reference at(size_type pos);
  reference operator[](size_type pos);
  const_reference front();
  const_reference back();
  T *data();

  // Vector Iterators
  iterator begin();
  iterator end();

  // Vector Capacity
  bool empty();
  size_type size();
  size_type max_size();
  void reserve(size_type size);
  size_type capacity();
  void shrink_to_fit();

  // Vector Modifiers
  void clear();
  iterator insert(iterator pos, const_reference value);
  void erase(iterator pos);
  void push_back(const_reference value);
  void pop_back();
  void swap(vector &other);

 private:
  size_t size_;
  size_t capacity_;
  value_type *array_;
};

}  // namespace s21

#endif  // VECTOR_H