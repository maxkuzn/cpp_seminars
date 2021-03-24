#include <iostream>
#include <vector>

class A {
 public:
  A() {
    ++count_;
    std::cout << "Constructor A\n";
  }

  A(const A& other) {
    if (count_ > 10) {
      // throw //...;
    }
    ++count_;
    std::cout << "Constructor A(A&)\n";
  }

  A(A&& other) {
    ++count_;
    std::cout << "Constructor A(A&&)\n";
  }

  ~A() {
    --count_;
    std::cout << "Destructor A\n";
  }

  static size_t count() {
    return count_;
  }

 private:
  static size_t count_;
};

size_t A::count_ = 0;


template <typename T>
class Vector {
 public:
  Vector() {
  }

  ~Vector() {
    clear();
    reallocate(0);
  }

  void push_back(const T& elem) {
    if (size_ == cap_) {
      reallocate(cap_ ? 2 * cap_ : 1);
    }

    new (data_ + size_) T(elem);
    ++size_;
  }

  void pop_back() {
    back().~T();
    --size_;
  }

  void shrink_to_fit() {
    reallocate(size());
  }

  T& back() {
    return data_[size_ - 1];
  }

  const T& back() const {
    return data_[size_ - 1];
  }

  T& operator[](size_t idx) {
    return data_[idx];
  }

  const T& operator[](size_t idx) const {
    return data_[idx];
  }

  void clear() {
    while (size() != 0) {
      pop_back();
    }
  }

  void resize(size_t new_size, const T& elem = T()) {
    while (new_size < size()) {
      pop_back();
    }
    // if (new_size > cap()) {
    reallocate(new_size);
    // }
    while (new_size > size()) {
      push_back(elem);
    }
  }

  size_t size() const {
    return size_;
  }

  size_t cap() const {
    return cap_;
  }

 private:
  // new_cap > 0 && new_cap >= size
  void reallocate(size_t new_cap) {
    if (new_cap == cap_) {
      return;
    }

    T* new_data = nullptr;
    if (new_cap) {
      new_data = reinterpret_cast<T*>(
        ::operator new(sizeof(T) * new_cap)
      );
    }

    if (data_) {
      for (size_t i = 0; i != std::min(size(), new_cap); ++i) {
        new (new_data + i) T(data_[i]);
      }
      for (size_t i = 0; i != size(); ++i) {
        data_[i].~T();
      }
      ::operator delete(data_);
    }

    data_ = new_data;
    cap_ = new_cap;
  }

  T* data_ = nullptr;
  size_t size_ = 0;
  size_t cap_ = 0;
};



int main() {
  /*
  A* a = reinterpret_cast<A*>(new char[sizeof(A)]);

  new (a) A();
  a->~A();

  delete[] reinterpret_cast<char*>(a);

  a = reinterpret_cast<A*>(::operator new(sizeof(A)));

  new (a) A();
  a->~A();

  ::operator delete(a);
  */

  // Test 1 (Constructor)
  {
    Vector<A> v;
  }

  // Test 2 (Push back)
  {
    Vector<A> v;
    v.push_back(A());
    if (A::count() != 1) {
      std::cerr << "A::count (" << A::count() << ") != 1\n";
    }
  }

  if (A::count() != 0) {
    std::cerr << "A::count (" << A::count() << ") != 0\n";
  }

  {
    Vector<A> v;
    std::vector<size_t> caps{0, 1, 2, 4, 4, 8};
    for (size_t i = 0; i != 5; ++i) {
      if (v.cap() != caps[i]) {
        std::cerr << "Error\n";
      }
      if (v.size() != i) {
        std::cerr << "Error\n";
      }
      v.push_back(A());
      if (v.cap() != caps[i + 1]) {
        std::cerr << "Error\n";
      }
      if (v.size() != i + 1) {
        std::cerr << "Error\n";
      }
    }
  }

  std::cerr << "Error\n";
}

