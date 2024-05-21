#include "s21_queue.h"

namespace s21 {

template <typename value_type, class Container>
queue<value_type, Container>::queue() : queue_() {}

template <typename value_type, class Container>
queue<value_type, Container>::queue(
    std::initializer_list<value_type> const &items)
    : queue_(items) {}

template <typename value_type, class Container>
queue<value_type, Container>::queue(const queue &q) : queue_(q.queue_) {}

template <typename value_type, class Container>
queue<value_type, Container>::queue(queue &&q) : queue_(std::move(q.queue_)) {}

template <typename value_type, class Container>
queue<value_type, Container>::~queue() {}

template <typename value_type, class Container>
queue<value_type, Container> &queue<value_type, Container>::operator=(
    queue &&q) {
  if (this != &q) {
    queue_ = std::move(q.queue_);
  }
  return *this;
}

template <typename value_type, class Container>
typename queue<value_type, Container>::const_reference
queue<value_type, Container>::front() {
  return queue_.front();
}

template <typename value_type, class Container>
typename queue<value_type, Container>::const_reference
queue<value_type, Container>::back() {
  return queue_.back();
}

template <typename value_type, class Container>
bool queue<value_type, Container>::empty() {
  return queue_.empty();
}

template <typename value_type, class Container>
typename queue<value_type, Container>::size_type
queue<value_type, Container>::size() {
  return queue_.size();
}

template <typename value_type, class Container>
void queue<value_type, Container>::push(const_reference value) {
  queue_.push_back(value);
}

template <typename value_type, class Container>
void queue<value_type, Container>::pop() {
  queue_.pop_front();
}

template <typename value_type, class Container>
void queue<value_type, Container>::swap(queue &other) {
  queue_.swap(other.queue_);
}

}  // namespace s21