#include <iostream>
#include <memory>

class A {
 public:
  A() {
    id_ = sequence_number_++;
    std::cout << "Constructor A " << id_ << "\n";
  }

  ~A() {
    std::cout << "Destructor A " << id_ << "\n";
  }

  /*
  static void* operator new(size_t size) {
    std::cout << "operator new A\n";
    return ::operator new(size);
  }

  static void* operator new[](size_t size) {
    std::cout << "operator new[] A\n";
    return ::operator new[](size);
  }
  */
 private:
  size_t id_;
  static size_t sequence_number_;
};

size_t A::sequence_number_ = 0;


class Guard {
 public:
  Guard(std::function<void(void)> f) : f_(f) {
  }

  ~Guard() {
    f_();
  }

 private:
  std::function<void(void)> f_;
};



A* createA() {
  A a;
  return &a;
  // return new A;
}

void deleteA(A* p) {
  delete p;
}


void func() {
  A* a = new A;

  Guard guard([&]() {
      delete a;
  });
}


// C-style
bool SomeFuncCStyle(bool first, bool second) {
  bool result;
  int* a = nullptr;
  int* b = nullptr;

  a = new int;
  //...
  if (first) {
    result = true;
    goto free;
  }

  b = new int;
  //...
  if (second) {
    result = false;
    goto free;
  }
  //...

  result = false;

free:
  delete a;
  delete b;
  return result;
}

class SmartPointer {
 public:
  SmartPointer(int* p_) : p(p_) {
  }

  ~SmartPointer() {
    delete p;
  }

  int& operator*() {
    return *p;
  }

  int* operator->() {
    return p;
  }

  int* p;
};


// C++-style
bool SomeFuncCPPStyle(bool first, bool second) {
  SmartPointer a(new int);
  //...
  if (first) {
    return true;
  }

  SmartPointer b(new int);
  //...
  if (second) {
    return false;
  }
  //...

  return false;
}


int main() {
  int x = 5;
  int* x_pointer = &x;
  *x_pointer = 10;
  std::cout << x << '\n';

  int* pointer = new int(7);
  std::cout << *pointer << '\n';
  int* another_pointer = pointer;
  *another_pointer = 42;
  std::cout << *pointer << '\n';

  delete pointer;
  // delete pointer;
  // delete another_pointer;
  pointer = nullptr;
  delete pointer;

  A* p = new A;
  delete p;

  A* arr_A = new A[3];
  // delete[] arr_A;
  delete[] arr_A;

  int* arr = new int[10];

  arr[4] = 5;
  std::cout << arr[4] << '\n';

  delete[] arr;


  std::unique_ptr<int> up(new int);
  // std::unique_ptr<int> another_up = std::move(up); // std::unique_ptr&&
  std::unique_ptr<int> another_up(new int(*up));
  // *up = 5;
  // std::cout << *up << '\n';

  std::unique_ptr<A> up_A(new A);




  std::shared_ptr<int> sp(new int);
  std::shared_ptr<int> another_sp = sp;

  *sp = 5;
  std::cout << *another_sp << '\n';
  *another_sp = 20;
  std::cout << *sp << '\n';


  std::weak_ptr<A> wp_A;
  {
    std::shared_ptr<A> sp_A(new A);
    std::cout << "Use count: " << sp_A.use_count() << '\n';
    std::shared_ptr<A> another_sp_A = sp_A;
    std::cout << "Use count: " << sp_A.use_count() << '\n';

    // wp_A = sh_A;
  }






  std::weak_ptr<int> wp;
  std::shared_ptr<int> sp_from_wp;
  {
    std::cout << "\nWeak:\n";
    std::shared_ptr<int> tmp(new int(5));
    wp = tmp;
    std::cout << wp.expired() << '\n';

  }
  sp_from_wp = wp.lock();
  std::cout << *sp_from_wp << '\n';
  std::cout << wp.expired() << '\n';




  /*
  func();
  */
}

