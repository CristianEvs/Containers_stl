#ifndef QUEUE_H
#define QUEUE_H

#include <initializer_list>
#include <iostream>
#include <list>

namespace s21 {
template <typename T, class Container = std::list<T>>
class queue {
 public:
  // Queue Member type
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = size_t;

  // Queue Member functions
  queue();
  queue(std::initializer_list<value_type> const &items);
  queue(const queue &q);
  queue(queue &&q);
  ~queue();
  queue &operator=(queue &&q);

  // Queue Element access
  const_reference front();
  const_reference back();

  // Queue Capacity
  bool empty();
  size_type size();

  // Queue Modifiers
  void push(const_reference value);
  void pop();
  void swap(queue &other);

 private:
  Container queue_;
};

}  // namespace s21

#endif  // QUEUE_H