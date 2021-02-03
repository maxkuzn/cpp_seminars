#include <iostream>
#include <array>
#include <vector>
#include <map>
#include <list>
#include <queue>
#include <tuple>

template <typename T>
T MyMax(T a, T b) {
  if (a > b) {
    return a;
  }
  return b;
}

template <typename T>
double foo(double arg1, double arg2) {
  return static_cast<T>(arg1) * arg2;
}



template <typename T>
void print_argument_type(T /*arg1*/, T arg2 = T()) {
  std::cout << __PRETTY_FUNCTION__ << '\n';
}

template <typename T>
void print_vector_subtype(const std::vector<T>& /*arg*/) {
  std::cout << __PRETTY_FUNCTION__ << '\n';
}

template <int N>
int get_N() {
  return N;
}



struct MyStruct {
  int a;
  double b;
};

bool operator>(const MyStruct& lhs, const MyStruct& rhs) {
  return lhs.a > rhs.a;
}



template <typename T>
T sum(T a, T b) {
  return a + b;
}

template <typename SubT>
std::vector<SubT> sum(std::vector<SubT> a, std::vector<SubT> b) {
  a.insert(a.end(), b.begin(), b.end());
  return a;
}

template <>
std::list<int> sum(std::list<int> a, std::list<int> b) {
  a.insert(a.end(), b.begin(), b.end());
  return a;
}



template <typename First, typename Second>
struct Pair {
  First first;
  Second second;
};


template <class InputIt, class UnitaryOperator>
InputIt FindIf(InputIt begin, InputIt end, UnitaryOperator p) {
  for (; begin != end; ++begin) {
    if (p(*begin)) {
      return begin;
    }
  }
  return end;
}



struct MyIter {
  int x;

  int operator*() {
    return x;
  }

  // ++x
  MyIter& operator++() {
    x += 1;
    return *this;
  }

  // x++
  MyIter operator++(int) {
    MyIter tmp{x};
    x += 1;
    return tmp;
  }
};

bool operator==(const MyIter& lhs, const MyIter& rhs) {
  return lhs.x == rhs.x;
}

bool operator!=(const MyIter& lhs, const MyIter& rhs) {
  return !(lhs == rhs);
}



int main() {
  int ia = 1;
  int ib = 2;
  std::cout << typeid(MyMax<int>(ia, ib)).name() << '\n';

  double da = 1.1;
  double db = 1.6;
  std::cout << typeid(MyMax<double>(da, db)).name() << '\n';

  MyStruct msa, msb;
  auto l = MyMax<MyStruct>(msa, msb);

  if (ia > 0) {
    print_argument_type<int>(ia);
  } else {
    print_argument_type<double>(ia);
  }
  print_argument_type<double>(ia);

  std::vector<int> simple_vector;
  print_argument_type(simple_vector);

  std::vector<std::map<std::pair<int, bool>, std::tuple<std::queue<uint64_t>, unsigned>>> some_complex_type;
  // print_argument_type(some_complex_type);
  std::cout << '\n';

  // print_vector_subtype(simple_vector);
  // print_vector_subtype(some_complex_type);
  std::cout << '\n';

  unsigned ua;
  print_argument_type<int>(ia, da);
  print_argument_type<unsigned>(ia, ua);

  std::cout << foo<int>(1.1, 0.2) << '\n';

  const int N = 16;
  std::cout << get_N<20>() << '\n';
  std::cout << get_N<N>() << '\n';
  // std::cout << get_N<ia>() << '\n';
  std::array<int, 3> arr;


  std::cout << sum(ia, ib) << '\n';
  std::vector<int> va{1, 2};
  std::vector<int> vb{3, 4};
  std::vector<int> vc = sum(va, vb);
  for (int x : vc) {
    std::cout << x << ' ';
  }
  std::cout << '\n';

  Pair<int, double> p;
  p.first = 1;
  p.second = -6.5;


  std::vector<int> v;
  std::list<double> ll;
  std::map<std::queue<bool>, std::pair<std::string, short>> m;
  FindIf(m.begin(), m.end(), [] (const std::pair<std::queue<bool>, std::pair<std::string, short>>& p) {
      return true;
  });


  MyIter a{3};
  MyIter b{6};
  auto found = FindIf(a, b, [] (int x) {
      return x == 8;
  });
  std::cout << found.x << '\n';

  int x = 5;
  int y = ++x;
  int z = x++;
  std::cout << x << ' ' << y << ' ' << z << '\n';
}








