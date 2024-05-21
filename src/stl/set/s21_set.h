#include "../tree/s21_avlTree.h"

namespace s21 {

template <typename T>
class set : public BinaryTree<T, T> {
 public:
  using iterator = typename BinaryTree<T, T>::Iterator;
  using Key = T;
  set() : BinaryTree<T, T>(){};
  set(std::initializer_list<T> const &items) {
    for (auto i = items.begin(); i != items.end(); ++i) this->insert(*i);
  };
  set(const set &other) : BinaryTree<T, T>(other) {}
  set(set &&other) : BinaryTree<T, T>(std::move(other)) {}
  ~set() = default;
  set &operator=(set &&other) noexcept {
    if (this != &other) BinaryTree<Key, Key>::operator=(std::move(other));
    return *this;
  };
  set &operator=(const set &other) {
    if (this != &other) BinaryTree<Key, Key>::operator=(other);
    return *this;
  };
};
}  // namespace s21
