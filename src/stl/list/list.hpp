#include <math.h>

#include <initializer_list>
#include <iostream>

using namespace std;

namespace s21 {
template <typename T>
class list {
 private:
  template <typename>
  class Node {
   public:
    Node *pNext;
    Node *pLast;
    T data;
    Node(T data = T(), Node *pNext = nullptr, Node *pLast = nullptr) {
      this->pLast = pLast;
      this->data = data;
      this->pNext = pNext;
    };
    Node &real() { Node *nep = nullptr; }
  };

  size_t size_;
  Node<T> *head;
  Node<T> *back_;

 public:
  using value_type = T;
  using reference = T &;
  using size_type = size_t;
  using const_reference = const T &;
  using pointer = T *;

  list();
  list(size_t size_n);
  list(std::initializer_list<T> const &items);
  ~list();
  list(const list &l);
  T &operator[](const int index);

  list &operator=(list &&other) noexcept {
    if (this != &other) {
      clear();
      size_ = other.size_;
      head = other.head;
      back_ = other.back_;

      other.head = nullptr;
      other.back_ = nullptr;
      other.size_ = 0;
    }
    return *this;
  }
  size_type size() { return size_; };
  size_type max_size();
  void support_swaping(list &other, int size1, int size2);
  void push_back(T data);
  void delete_(const int index);
  void pop_front();
  void clear();
  bool empty();
  void push_front(T data);
  void pop_back();
  void print_b();
  void print_h();
  void reverse();
  void swap(list &other);

  const const_reference front();
  const const_reference back();

  void merge(list &other);
  void unique();
  void sort();

  template <bool Const>
  class ListIterator {
   public:
    // using node_pointer =
    //     std::conditional_t<Const, Node<value_type> const *, Node<value_type>
    //     *>;

    ListIterator() : noded(nullptr) {}
    ListIterator(const ListIterator &other) : noded(other.noded) {}
    explicit ListIterator(Node<value_type> *node) : noded(node) {}
    reference operator*() { return noded->data; }
    pointer operator->() { return &(operator*()); }
    Node<value_type> *get_node() { return noded; };
    Node<value_type> *get_node_next() { return noded->pNext; };
    Node<value_type> *get_node_last() { return noded->pLast; };

    ListIterator &operator++() {
      noded = noded->pNext;

      return *this;
    }
    // ListIterator &operator=(ListIterator &other) {
    //   noded->data = other.noded->data;
    //   noded = other.noded;
    //   noded->pLast = other.noded->pLast;
    //   noded->pNext = other.noded->pNext;
    //   return *this;
    // }

    // ListIterator &operator=(Node<value_type> *&other) {
    //   noded->data = other->data;
    //   return *this;
    // }

    ListIterator &operator=(ListIterator &other) {
      noded = other.noded;
      return *this;
    }

    ListIterator &operator=(const ListIterator &other) {
      noded = other.noded;
      return *this;
    }
    ListIterator &operator=(Node<value_type> *&other) {
      noded = other;
      return *this;
    }

    ListIterator operator=(list &&other) {
      this->noded = other.head;
      return *this;
    }

    ListIterator operator++(int) {
      ListIterator lst(*this);
      operator++();
      return lst;
    }

    ListIterator &operator--() {
      noded = noded->pLast;
      return *this;
    }

    ListIterator operator--(int) {
      ListIterator lst(*this);
      operator--();
      return lst;
    }

    bool operator==(const ListIterator &other) {
      return noded->data == other.noded->data;
    }

    bool operator!=(ListIterator &other) {
      return noded->data != other.noded->data;
    }
    bool operator>=(ListIterator &other) {
      return noded->data >= other.noded->data;
    }

    bool operator<=(ListIterator &other) {
      return noded->data <= other.noded->data;
    }

    bool operator>(ListIterator &other) {
      return noded->data > other.noded->data;
    }

    bool operator<(ListIterator &other) {
      return noded->data < other.noded->data;
    }

    bool operator!=(pointer h) { return noded != h; }

    bool operator!=(std::nullptr_t) { return noded != nullptr; }

    ListIterator &operator+=(int i) {
      int it = 0;
      while (it < i && noded->pNext != nullptr) {
        noded = noded->pNext;
        it++;
      }
      return *this;
    }

    ListIterator &operator-=(int i) {
      int it = 0;
      while (it < i && noded->pLast != nullptr) {
        noded = noded->pLast;
        it++;
      }
      return *this;
    }

    ListIterator swap_it(ListIterator first, ListIterator sec) {
      Node<value_type> *curr = first.noded;
      first.noded = sec.noded;
      return *this;
    }

    // Вот тут изменен аргумент ListIterator, должен использоваться алиас
    // iterator

   private:
    Node<value_type> *noded;
  };

  template <typename value_type, bool Const>
  class ListConstIterator {
   public:
    using reference = std::conditional_t<Const, const T &, T &>;
    using pointer = std::conditional_t<Const, const T *, T *>;
    using NodeType =
        std::conditional_t<Const, const Node<value_type>, Node<value_type>>;

    ListConstIterator() : noded(nullptr) {}
    explicit ListConstIterator(Node<value_type> *node) : noded(node) {}
    reference operator*() const { return noded->data; }
    pointer operator->() const { return &(operator*()); }
    Node<value_type> *get_node() const { return noded; };
    Node<value_type> *get_node_next() const { return noded->pNext; };
    Node<value_type> *get_node_last() const { return noded->pLast; };

    template <bool OtherConst>
    constexpr ListConstIterator(
        const ListConstIterator<T, OtherConst> &other) noexcept
        : noded(other.get_node()) {}

    ListConstIterator &operator++() {
      noded = noded->pNext;
      return *this;
    }

    ListConstIterator operator++(int) {
      ListConstIterator lst(*this);
      operator++();
      return lst;
    }

    ListConstIterator &operator--() {
      noded = noded->pLast;
      return *this;
    }

    ListConstIterator operator--(int) {
      ListConstIterator lst(*this);
      operator--();
      return lst;
    }

    ListConstIterator &operator=(ListConstIterator &other) {
      noded->data = other.noded->data;
      noded = other.noded;
      noded->pLast = other.noded->pLast;
      noded->pNext = other.noded->pNext;
      return *this;
    }

    ListConstIterator &operator=(Node<value_type> *&other) {
      noded->data = other->data;
      return *this;
    }

    bool operator==(const ListConstIterator &other) const {
      return noded->data == other.noded->data;
    }

    bool operator!=(const ListConstIterator &other) const {
      return noded->data != other.noded->data;
    }

    bool operator>(ListConstIterator &other) const {
      return noded->data > other.noded->data;
    }

    bool operator>=(ListConstIterator &other) const {
      return noded->data >= other.noded->data;
    }

    bool operator<=(ListConstIterator &other) const {
      return noded->data <= other.noded->data;
    }

    bool operator<(ListConstIterator &other) const {
      return noded->data < other.noded->data;
    }

    bool operator!=(pointer h) const { return noded != h; }

    bool operator!=(std::nullptr_t) const { return noded != nullptr; }

    ListConstIterator &operator+=(int i) {
      int it = 0;
      while (it < i && noded->pNext != nullptr) {
        noded = noded->pNext;
        it++;
      }
      return *this;
    }

    ListConstIterator &operator-=(int i) {
      int it = 0;
      while (it < i && noded->pLast != nullptr) {
        noded = noded->pLast;
        it++;
      }
      return *this;
    }

   private:
    Node<value_type> *noded;
  };
  using iterator = ListIterator<false>;
  using const_iterator = ListIterator<true>;

  iterator begin();
  const_iterator cbegin();
  iterator insert(iterator pos, const_reference value);
  iterator end();
  const_iterator cend();
  iterator swap_it(iterator first, iterator sec);

  void quickSort(iterator begin, iterator end);
  void erase(iterator pos);
  void splice(const_iterator pos, list &other);
};

}  // namespace s21