#include "s21_stack.h"

namespace s21 {
template <class T, class Container>
stack<T, Container>::stack() : cont_vector() {}
// initializer list constructor
template <class T, class Container>
stack<T, Container>::stack(std::initializer_list<value_type> const &items)
    : cont_vector(items) {}
// copy constructor
template <class T, class Container>
stack<T, Container>::stack(const stack &other)
    : cont_vector(other.cont_vector) {}
// move constructor
template <class T, class Container>
stack<T, Container>::stack(stack &&other)
    : cont_vector(std::move(other.cont_vector)) {}

template <class T, class Container>
stack<T, Container>::~stack() {}

template <class T, class Container>
stack<T, Container> &stack<T, Container>::operator=(stack &&other) {
  this->cont_vector = std::move(other.cont_vector);
  return *this;
}

template <class T, class Container>
typename stack<T, Container>::const_reference stack<T, Container>::top() {
  return cont_vector.back();
}

template <class T, class Container>
bool stack<T, Container>::empty() {
  return cont_vector.empty();
}

template <class T, class Container>
typename stack<T, Container>::size_type stack<T, Container>::size() {
  return cont_vector.size();
}

template <class T, class Container>
void stack<T, Container>::push(const_reference value) {
  this->cont_vector.push_back(value);
}

template <class T, class Container>
void stack<T, Container>::pop() {
  this->cont_vector.pop_back();
}

template <class T, class Container>
void stack<T, Container>::swap(stack &other) {
  this->cont_vector.swap(other.cont_vector);
}

}  // namespace s21
