#include <iostream>

template <typename T>
class SharedPtr {
 public:
  SharedPtr(T* ptr = nullptr) : ptr_(ptr) {
    if (ptr_) {
      count_ = new size_t(1);
    }
  }

  SharedPtr(const SharedPtr& other) {
    ptr_ = other.ptr;
    count_ = other.count_;
    *count_ += 1;
  }

  ~SharedPtr() {
    reset();
  }

  SharedPtr& operator=(const SharedPtr& other) {
    if (other.ptr_ == ptr_) {
      return *this;
    }
    reset();

    ptr_ = other.ptr;
    count_ = other.count_;
    *count_ += 1;

    return *this;
  }

  T& operator*();
  const T& operator*() const;

  T* get();
  const T* get() const;

  void reset(T* ptr = nullptr) {
    if (ptr == ptr_) {
      return;
    }

    if (count_) {
      *count_ -= 1;
      if (*count_ == 0) {
        delete count_;
        delete ptr_;
      }
    }

    ptr_ = ptr;
    if (ptr_) {
      count_ = new size_t(1);
    }
  }

  T* release();


 private:
  T* ptr_;
  size_t* shared_count_;
  size_t* all_count_;
};

class WeakPtr {
 public:
  SharedPtr get_shared();

 private:
  T* ptr_;
  size_t* shared_count_;
  size_t* all_count_;
}

// size_t
// size_t
// A
// A
// A
// A
//

template <typename T>
class Optional {
  Optional(const T& elem) {
    new (get_T_ptr()) T(elem);
    live_ = true;
  }

  ~Optional() {
    if (live_) {
      get_T_ptr()->~T();
    }
  }


 private:
  T* get_T_ptr() {
    return reinterpret_cast<T*>(data_);
  }

  char data_[sizeof(T)];
  bool live_;
};


class A : public std::shared_from_this {
};

int main() {
  SharedPtr<A> a;
  a.get();
  SharedPtr<A> b(a.get());
}

