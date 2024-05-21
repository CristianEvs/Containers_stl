#include "s21_vector.h"

namespace s21 {

template <typename value_type>
vector<value_type>::vector() : size_(0), capacity_(0), array_(nullptr) {}

template <typename value_type>
vector<value_type>::vector(size_type n) : size_(n), capacity_(n) {
  if (n > 0) {
    array_ = new value_type[n]();
  } else {
    array_ = nullptr;
  }
}

template <typename value_type>
vector<value_type>::vector(std::initializer_list<value_type> const& items) {
  size_ = items.size();
  capacity_ = items.size();
  array_ = new value_type[items.size()]();
  for (size_type i = 0; i < size_; i++) {
    array_[i] = items.begin()[i];
  }
}

template <typename value_type>
vector<value_type>::vector(const vector& v)
    : size_(v.size_), capacity_(v.capacity_) {
  array_ = new value_type[capacity_]();
  for (size_type i = 0; i < size_; i++) {
    array_[i] = v.array_[i];
  }
}

template <typename value_type>
vector<value_type>::vector(vector&& v)
    : size_(v.size_), capacity_(v.capacity_), array_(v.array_) {
  v.size_ = 0;
  v.capacity_ = 0;
  v.array_ = nullptr;
}

template <typename value_type>
vector<value_type>::~vector() {
  delete[] array_;
  size_ = 0;
  capacity_ = 0;
  array_ = nullptr;
}

template <typename value_type>
vector<value_type>& vector<value_type>::operator=(vector&& v) {
  if (this != &v) {
    delete[] array_;
    array_ = v.array_;
    size_ = v.size_;
    capacity_ = v.capacity_;
    v.size_ = 0;
    v.capacity_ = 0;
    v.array_ = nullptr;
  }
  return *this;
}

template <typename value_type>
typename vector<value_type>::reference vector<value_type>::at(size_type pos) {
  if (pos > (size_ - 1))
    throw std::out_of_range("overflow of allocated memory");
  return array_[pos];
}

template <typename value_type>
typename vector<value_type>::reference vector<value_type>::operator[](
    size_type pos) {
  return array_[pos];
}

template <typename value_type>
typename vector<value_type>::const_reference vector<value_type>::front() {
  return array_[0];
}

template <typename value_type>
typename vector<value_type>::const_reference vector<value_type>::back() {
  return array_[size_ - 1];
}

template <typename value_type>
value_type* vector<value_type>::data() {
  return array_;
}

template <typename value_type>
typename vector<value_type>::iterator vector<value_type>::begin() {
  return array_;
}

template <typename value_type>
typename vector<value_type>::iterator vector<value_type>::end() {
  return array_ + size_;
}

template <typename value_type>
bool vector<value_type>::empty() {
  return size_ == 0;
}

template <typename value_type>
typename vector<value_type>::size_type vector<value_type>::size() {
  return size_;
}

template <typename value_type>
typename vector<value_type>::size_type vector<value_type>::max_size() {
  return (SIZE_MAX / sizeof(value_type) / 2);
}

template <typename value_type>
void vector<value_type>::reserve(size_type size) {
  if (size > capacity_) {
    value_type* new_array = new value_type[size]();
    for (size_type i = 0; i < size_; i++) {
      new_array[i] = array_[i];
    }
    delete[] array_;
    array_ = new_array;
    capacity_ = size;
  }
}

template <typename value_type>
typename vector<value_type>::size_type vector<value_type>::capacity() {
  return capacity_;
}

template <typename value_type>
void vector<value_type>::shrink_to_fit() {
  if (capacity_ > size_) {
    value_type* new_array = new value_type[size_]();
    for (size_type i = 0; i < size_; i++) {
      new_array[i] = array_[i];
    }
    delete[] array_;
    array_ = new_array;
    capacity_ = size_;
  }
}

template <typename value_type>
void vector<value_type>::clear() {
  delete[] array_;
  size_ = 0;
  capacity_ = 0;
  array_ = nullptr;
}

template <typename value_type>
typename vector<value_type>::iterator vector<value_type>::insert(
    iterator pos, const_reference value) {
  size_type index = pos - array_;

  reserve(size_ + 1);
  for (size_type i = size_; i > index; --i) {
    array_[i] = array_[i - 1];
  }
  array_[index] = value;
  size_++;

  return &(array_[index]);
}

template <typename value_type>
void vector<value_type>::erase(iterator pos) {
  size_type index = pos - array_;
  if (pos >= array_ && pos < array_ + size_) {
    for (size_type i = index; i < size_ - 1; ++i) {
      array_[i] = array_[i + 1];
    }
    size_--;
  }
}

template <typename value_type>
void vector<value_type>::push_back(const_reference value) {
  reserve(size_ + 1);
  array_[size_] = value;
  size_++;
}

template <typename value_type>
void vector<value_type>::pop_back() {
  if (size_ > 0) {
    value_type* new_array = new value_type[size_ - 1]();
    for (size_type i = 0; i < size_ - 1; i++) {
      new_array[i] = array_[i];
    }
    delete[] array_;
    array_ = new_array;
    size_--;
  }
}

template <typename value_type>
void vector<value_type>::swap(vector& other) {
  std::swap(array_, other.array_);
  std::swap(size_, other.size_);
  std::swap(capacity_, other.capacity_);
}

}  // namespace s21