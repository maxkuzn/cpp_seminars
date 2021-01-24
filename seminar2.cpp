#include <iostream>
#include <string>
#include <vector>

int main() {
  /*
  std::string str("Hello");  // The best
  str = "Hello";

  std::cout << str.size() << '\n';
  std::cout << str[2] << '\n';
  std::cout << str[0] << str.front() << '\n';
  std::cout << str.back() << '\n';

  for (size_t i = 0; i < str.size(); ++i) {
    std::cout << str[i];
  }
  std::cout << '\n';

  std::cout << str.substr(1) << '\n';
  std::cout << std::boolalpha << str.starts_with("He") << '\n';
  std::cout << std::noboolalpha;
  std::cout << str.ends_with("lk") << '\n';

  str = "Bla bla";
  size_t n = str.rfind("la");
  std::cout << n << '\n';
  */

  /*
  std::string str(2, 'b');
  str.push_back('x');
  str.push_back('y');
  str.push_back('z');
  str += 'y';
  str += " str";
  str.pop_back();

  std::cout << str << '\n';
  */

  /*
  size_t n;
  std::cin >> n;

  int sum = 0;
  for (size_t i = 0; i != n; ++i) {
    int x;
    std::cin >> x;
    sum += x;
  }

  std::cout << "Sum: " << sum << '\n';
  */

  /*
  // int x;
  int sum = 0;
  // while (std::cin >> x) {
  for (int x; std::cin >> x; ) {
    sum += x;
  }

  std::cout << "Sum: " << sum << '\n';
  */

  /*
  // std::string number;
  int sum = 0;
  for (std::string number; std::getline(std::cin, number); ) {
  // while (std::getline(std::cin, number)) {
    sum += std::stoi(number);
  }

  std::cout << "Sum: " << sum << '\n';
  */

  /*
  // list
  // std::vector<int16_t> vec;
  std::vector<int16_t> vec(5, 42);

  vec.pop_back();
  vec.push_back(10);

  vec.resize(8, -6);


  std::cout << vec.size() << '\n';
  for (size_t i = 0; i != vec.size(); ++i) {
    std::cout << vec[i] << ' ';
  }
  std::cout << '\n';
  */

  /*
  size_t n;
  std::cin >> n;

  // std::vector<int> vec(n);
  // std::vector<int> vec;
  // vec.resize(n);
  std::vector<int> vec;
  vec.reserve(n);
  std::cout << vec.size() << '\n';
  for (size_t i = 0; i != n; ++i) {
    int x;
    std::cin >> x;
    vec.push_back(x);
    // vec[i] = x;
  }
  */


  /*
  std::vector<int> vec;
  for (int i = 0; i != 10; ++i) {
    vec.push_back(i);
  }

  for (auto it = vec.begin(); it != vec.end(); ++it) {
    if (it == vec.begin() + 3) {
      *it = 20;
    }
    std::cout << *it << '\n';
  }

  for (int x : vec) {
    std::cout << x << ' ';
  }
  std::cout << '\n';
  */


  /*
  std::vector<std::string> vec{"abc", "x", "", " ba", "acb"};
  for (auto x : vec) {
    std::cout << x << ' ';
  }
  std::cout << '\n';

  std::sort(vec.begin(), vec.end());

  // vec[0], vec[1], ...
  for (auto x : vec) {
    std::cout << x << ' ';
  }
  std::cout << '\n';
  */

  /*
  int n = 10;
  int m = 20;

  std::vector<std::vector<int>> mat(n, std::vector<int>(m, 0));
  */

  // 0*******
  // 110***** 10******
  // 1110**** 10****** 10******
  // 11110*** 10****** 10****** 10******

  std::string str = "Привет";
  std::cout << str.substr(0, 5) << '\n';
  std::cout << str << '\n';
  std::cout << str.size() << '\n';
}

