#include <iostream>
#include <vector>

class A {
 public:
  A(int id) : id_(id) {
    std::cout << "A() [id = " << id_ << "]\n";
  }

  A() = default;

  A(const A& other) {
    id_ = other.id_;
    std::cout << "A(const A&) [id = " << id_ << "]\n";
  }

  A(A&& other) {
    id_ = other.id_;
    std::cout << "A(A&&) [id = " << id_ << "]\n";
  }

  A& operator=(const A& other) {
    id_ = other.id_;
    std::cout << "operator=(const A&) [id = " << id_ << "]\n";
    return *this;
  }

  A& operator=(A&& other) {
    id_ = other.id_;
    std::cout << "operator=(A&&) [id = " << id_ << "]\n";
    return *this;
  }

  ~A() {
    std::cout << "~A() [id = " << id_ << "]\n";
  }

  void SetId(int new_id) {
    id_ = new_id;
  }

  int GetId() const {
    return id_;
  }

  A Incr() const {
    A a(id_);
    return a.Incr();
  }

  A& Incr() {
    ++id_;
    return *this;
  }


  friend bool operator<(const A& lhs, const A& rhs);
  friend bool operator==(const A& lhs, const A& rhs);

 private:
  int id_;
};


bool operator<(const A& lhs, const A& rhs) {
  return lhs.id_ < rhs.id_;
}

bool operator==(const A& lhs, const A& rhs) {
  return lhs.id_ == rhs.id_;
}

bool operator!=(const A& lhs, const A& rhs) {
  return !(lhs == rhs);
}

bool operator>=(const A& lhs, const A& rhs) {
  return !(lhs < rhs);
}

bool operator>(const A& lhs, const A& rhs) {
  return !(lhs < rhs || lhs == rhs);
}

bool operator<=(const A& lhs, const A& rhs) {
  return (lhs < rhs || lhs == rhs);
}

void foo(std::vector<A>& v, int id) {
  v.emplace_back(id);
}


std::vector<A> create_A_vector() {
  std::vector<A> v;
  v.reserve(5);
  for (size_t i = 0; i != 5; ++i) {
    v.emplace_back(i);
  }
  return v;
}

A create_A(int id) {
  A a(id);
  A b(id + 1);
  return b;
}

union U {
  int x;
  std::string str;
  A a;
};

struct S {
  int x;
  std::string str;
  A a;
};


void SetId(A& a, int id) {
  a.SetId(id);
}

void foo(const int& x, const int& y) {
  std::cout << "foo(const, const)\n";
}

void foo(int& x, const int& y) {
  std::cout << "foo(int, const)\n";
}

void foo(const int& x, int& y) {
  std::cout << "foo(const, int)\n";
}
/*
void foo(int& x, int& y) {
  std::cout << "foo(int, int)\n";
}
*/

int main() {
  /*
  A a = create_A(0);
  A c(3);
  */

  /*
  std::vector<A> v;
  v.reserve(8);
  for (int i = 0; i != 16; ++i) {
    v.emplace_back(i);
  }
  // A A ... A
  //
  //    |
  //    v
  //
  // A A ... A ____________

  // r-value reference
  // std::vector<A>&&
  std::vector<A> another = std::move(v);
  */
  /*
  std::vector<A> v = create_A_vector();
  std::cout << v.size() << '\n';
  */
  /*
  A a(0);
  const A b(10);

  a.SetId(1);
  SetId(a, 2);
  std::cout << a.GetId() << '\n';
  std::cout << a.Incr().GetId() << ' ' << a.GetId() << '\n';
  std::cout << b.Incr().GetId() << ' ' << b.GetId() << '\n';
  */

  const int const_x = 1;
  const int const_y = 2;
  int x = 3;
  int y = 4;

  foo(x, y);
  foo(const_x, y);
  foo(x, const_y);
  foo(const_x, const_y);
}

