#include <array>
#include <deque>
#include <iostream>
#include <list>
#include <queue>
#include <forward_list>


int foo() {
  return 5;
}

#include <stack>

int main() {
  std::cout << "deque:\n";
  std::deque<int> d{5, 6, 7};
  std::cout << d.front() << ' ' << d.back() << '\n';
  d.pop_front();
  d.pop_back();
  d.push_front(0);
  d.push_back(10);
  for (size_t i = 0; i != d.size(); ++i) {
    std::cout << d[i] << ' ';
  }
  std::cout << '\n';
  std::cout << '\n';

  std::cout << "queue:\n";
  // std::queue<int> q{5, 6, 7};
  std::queue<int> q;
  q.push(5);
  q.push(6);
  q.push(7);
  std::cout << q.front() << ' ' << q.back() << '\n';
  q.pop();
  q.push(10);
  while (!q.empty()) {
    std::cout << q.front() << ' ';
    q.pop();
  }
  // for (int x : q) {
  //   std::cout << x << ' ';
  // }
  std::cout << '\n';
  std::cout << '\n';

  std::cout << "stack:\n";
  // std::stack<int> s{5, 6, 7};
  std::stack<int> s;
  s.push(5);
  s.push(6);
  s.push(7);
  // std::cout << s.front() << ' ' << s.back() << '\n';
  std::cout << s.top() << '\n';
  s.pop();
  s.push(10);
  // for (int x : s) {
  //   std::cout << x << ' ';
  // }
  while (!s.empty()) {
    std::cout << s.top() << ' ';
    s.pop();
  }
  std::cout << '\n';
  std::cout << '\n';


  struct Node {
    int value;
    // Node* prev;
    Node* next;
  };

  struct List {
    Node* begin;
    Node* end;
  };

  std::cout << "list:\n";
  std::list<int> l{5, 6, 7};
  std::cout << l.front() << ' ' << l.back() << '\n';
  l.pop_front();
  l.pop_back();
  l.push_front(0);
  l.push_back(10);
  for (int x : l) {
    std::cout << x << ' ';
  }
  std::cout << '\n';

  //   0 1 2 3 4 5
  //   ^           ^
  //   |           |
  // begin        end

  // auto it = l.begin() + 2;  // won't compile
  auto it = ++l.begin();
  l.erase(it);
  it = --l.end();
  l.insert(it, 1000);
  for (int x : l) {
    std::cout << x << ' ';
  }
  std::cout << '\n';
  std::cout << '\n';


  std::cout << "array:\n";
  size_t n;
  std::cin >> n;
  const size_t N = n;
  constexpr size_t NN = 4;
  constexpr std::array<int, NN> a{1, 2, 3};

  std::vector<int> v1;
  std::vector<int> v2 = v1;
  std::sort(v2.begin(), v2.end());

  // a[0] = 5;
  // a[1] = 6;
  // a[2] = 7;
  // a.push_back(10);
  std::cout << a.size() << '\n';
  for (int x : a) {
    std::cout << x << ' ';
  }
  std::cout << '\n';
}

