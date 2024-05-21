#include "list.hpp"

namespace s21 {

template <typename value_type>
list<value_type>::list() : size_(0), head(nullptr), back_(nullptr){};

template <typename value_type>
list<value_type>::list(size_t size_n) {
  size_ = 0;
  head = nullptr;
  back_ = nullptr;
  while (size_ != size_n) {
    push_back(0);
  }
};

template <typename value_type>
list<value_type>::list(std::initializer_list<value_type> const &items)
    : size_(0), head(nullptr), back_(nullptr) {
  for (auto &item : items) {
    push_back(item);
  }
};

template <typename value_type>
list<value_type>::list(const list &l) : size_(l.size_), head(nullptr) {
  if (size_ > 0) {
    // Если размер списка больше нуля
    head = new Node<value_type>(l.head->data);
    Node<value_type> *temp = head;
    Node<value_type> *back_temp = head;
    Node<value_type> *orig_temp = l.head->pNext;
    while (orig_temp != nullptr) {
      temp->pNext = new Node<value_type>(orig_temp->data);
      temp = temp->pNext;
      temp->pLast = back_temp;
      back_temp = back_temp->pNext;
      orig_temp = orig_temp->pNext;
    }
    back_ = temp;
  } else {
    throw invalid_argument("Error: list size is zero.");
  }
};

template <typename value_type>
list<value_type>::~list() {
  clear();
};

template <typename value_type>
void list<value_type>::push_back(value_type data) {
  Node<value_type> *new_node = new Node<value_type>(data);
  if (head == nullptr) {
    head = new_node;
    back_ = new_node;
  } else {
    back_->pNext = new_node;
    new_node->pLast = back_;
    back_ = new_node;
  }
  size_++;
};

template <typename value_type>
void list<value_type>::delete_(const int index){

};

template <typename value_type>
void list<value_type>::pop_front() {
  if (head != nullptr) {
    Node<value_type> *temp = head;
    head = head->pNext;
    if (head != nullptr) {
      head->pLast = nullptr;
    }
    delete temp;
    size_--;
  }
};

template <typename value_type>
void list<value_type>::clear() {
  while (size_) {
    pop_front();
  }
};

template <typename T>
typename list<T>::size_type list<T>::max_size() {
  return std::numeric_limits<size_type>::max() / sizeof(Node<T>);
}

template <typename value_type>
value_type &list<value_type>::operator[](const int index) {
  Node<value_type> *current = this->head;
  int count = 0;
  while (current != nullptr) {
    if (count == index) {
      return current->data;
    }
    current = current->pNext;
    count++;
  }
  throw invalid_argument("Invalid_ WTF");
};

template <typename value_type>
bool list<value_type>::empty() {
  return head == nullptr;
};

template <typename value_type>
void list<value_type>::push_front(value_type data) {
  if (head == nullptr) {
    head = new Node<value_type>(data);
  } else {
    Node<value_type> *current = new Node<value_type>(data);
    current->pNext = head;
    head = current;
  }
  size_++;
};

template <typename value_type>
void list<value_type>::pop_back() {
  if (!empty()) {
    Node<value_type> *temp = back_;
    if (size_ == 1) {
      // В списке остался только один элемент, обновляем указатели head и back
      head = nullptr;
      back_ = nullptr;
    } else {
      // В списке осталось больше одного элемента, обновляем указатель back
      back_ = back_->pLast;
      back_->pNext = nullptr;
    }
    delete temp;
    size_--;
  }
};

template <typename value_type>
void list<value_type>::print_b() {
  Node<value_type> *current = back_;

  // cout<<"проверка back'a ="<<this->back->data<<endl;
  while (current != nullptr) {
    cout << current->data << endl;
    current = current->pLast;
  }
  // cout<<"проверка back'a ="<<this->back->data<<endl;
};

template <typename value_type>
void list<value_type>::print_h() {
  Node<value_type> *current = head;
  while (current != nullptr) {
    cout << current->data << endl;
    current = current->pNext;
  }
};
template <typename value_type>
void list<value_type>::reverse() {
  Node<value_type> *current = head;
  Node<value_type> *temp = nullptr;
  // Обмен указаелями между началом и концом списка до тех пор, пока они не
  // встретятся или не пересекутся
  while (current != nullptr) {
    temp = current->pNext;
    current->pNext = current->pLast;
    current->pLast = temp;
    current = current->pLast;  // Переход к следующему узлу
  }
  // Переопределение указателя начала списка
  temp = head;
  head = back_;
  back_ = temp;
};

template <typename value_type>
typename list<value_type>::const_iterator list<value_type>::cbegin() {
  return const_iterator(head);
}

template <typename value_type>
typename list<value_type>::const_iterator list<value_type>::cend() {
  return const_iterator(back_);
}

template <typename value_type>
void list<value_type>::erase(iterator pos) {
  // Проверка, что итератор не равен end()
  if (pos == end()) return;

  // Указатель на текущий узел
  Node<value_type> *pos_curr = pos.get_node();

  if (pos_curr == head) {
    // Удаление первого элемента
    pop_front();
  } else if (pos_curr == back_) {
    // Удаление последнего элемента
    pop_back();
  } else {
    // Указатель на предыдущий и следующий узлы
    Node<value_type> *pos_curr_last = pos_curr->pLast;
    Node<value_type> *pos_curr_next = pos_curr->pNext;

    // Обновление указателей соседних узлов
    pos_curr_last->pNext = pos_curr_next;
    pos_curr_next->pLast = pos_curr_last;

    // Удаление текущего узла
    delete pos_curr;

    // Уменьшение размера списка
    size_--;
  }
}

template <typename value_type>
void list<value_type>::unique() {
  iterator it(begin());
  iterator it_next(head->pNext);
  while (it_next.get_node_next() != back_->pNext) {
    if (it == it_next) {
      erase(it_next);
    }
    it++;
    it_next = it;
    it_next++;
  }
}

template <typename value_type>
const value_type &list<value_type>::front() {
  return head->data;
}

template <typename value_type>
const value_type &list<value_type>::back() {
  return back_->data;
}

template <typename value_type>
typename list<value_type>::iterator list<value_type>::begin() {
  return iterator(head);
}

template <typename value_type>
typename list<value_type>::iterator list<value_type>::insert(
    iterator pos, const_reference value) {
  Node<value_type> *current = new Node<value_type>(value);
  Node<value_type> *pos_node = pos.get_node();

  if (pos_node == nullptr) {
    // Вставка в конец списка
    if (back_ == nullptr) {
      // Вставка в пустой список
      head = current;
      back_ = current;
    } else {
      back_->pNext = current;
      current->pLast = back_;
      back_ = current;
    }
  } else {
    if (pos_node->pLast == nullptr) {
      // Вставка в начало списка
      current->pNext = head;
      head->pLast = current;
      head = current;
    } else {
      // Вставка в середину списка
      Node<value_type> *prev_node = pos_node->pLast;
      prev_node->pNext = current;
      current->pLast = prev_node;
      current->pNext = pos_node;
      pos_node->pLast = current;
    }
  }

  size_++;
  return iterator(current);
}

template <typename value_type>
typename list<value_type>::iterator list<value_type>::end() {
  return iterator(back_);
}

template <typename value_type>
void list<value_type>::swap(list &other) {
  std::swap(this->head, other.head);
  std::swap(this->back_, other.back_);
  std::swap(this->size_, other.size_);
}

template <typename value_type>
void list<value_type>::merge(list &other) {
  if (this->back_ == nullptr) {
    this->head = other.head;
  }
  iterator it_1(begin());
  iterator it_2(other.begin());
  while (it_2 != nullptr) {
    if ((it_1 != nullptr && it_2 != nullptr) && it_1 <= it_2) {
      if (it_1.get_node_next() != nullptr) it_1++;
    }
    if ((it_1 != nullptr && it_2 != nullptr) && it_2 <= it_1) {
      insert(it_1, *it_2);
      it_2++;
    }
    if ((it_1.get_node_next() == nullptr) && it_2 != nullptr) {
      push_back(*it_2);
      it_2++;
    }
  }
}
template <typename value_type>
void list<value_type>::splice(const_iterator pos, list &other) {
  if (other.empty()) return;
  Node<value_type> *other_head = other.head;
  Node<value_type> *other_back = other.back_;
  Node<value_type> *pos_node = pos.get_node();
  Node<value_type> *pos_node_last = pos.get_node_last();

  if (pos_node == nullptr && pos_node->pLast != nullptr) {
    pos_node = other_head;
    other_head->pLast = pos_node_last;
    back_ = other_back;
  } else if (pos_node != nullptr && pos_node->pLast != nullptr) {
    pos_node_last->pNext = other_head;
    other_head->pLast = pos_node_last;
    other_back->pNext = pos_node;
    pos_node->pLast = other_back;
  } else if (pos_node != nullptr && pos_node->pLast == nullptr) {
    other_back->pNext = pos_node;
    pos_node->pLast = other_back;
    head = other_head;
  }
  size_ += other.size_;
  other.head = nullptr;
  other.back_ = nullptr;
  other.size_ = 0;
}

template <typename value_type>
typename list<value_type>::iterator list<value_type>::swap_it(iterator first,
                                                              iterator sec) {
  value_type temp = first.get_node()->data;
  first.get_node()->data = sec.get_node()->data;
  sec.get_node()->data = temp;
  return sec;
}

template <typename value_type>
void list<value_type>::sort() {
  iterator left(begin());
  left++;
  iterator next(left);
  left--;
  int change = 1;
  while (change) {
    change = 0;
    while (next.get_node() != back_) {
      if (left > next) {
        swap_it(left, next);
        change++;
      }
      left++;
      next++;
      if (left > next) {
        swap_it(left, next);
        change++;
      }
    }
    left = end();
    next = end();
    next--;

    while (next.get_node() != head) {
      if (left < next) {
        swap_it(left, next);
        change++;
      }
      left--;
      next--;
      if (left < next) {
        swap_it(left, next);
        change++;
      }
    }
    left = begin();
    next = begin();
    next++;
  }
}

};  // namespace s21
