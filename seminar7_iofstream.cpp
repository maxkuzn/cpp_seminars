#include <iostream>
#include <fstream>
#include <sstream>
#include <utility>
#include <string>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);


  int x;
  std::string str;
  std::ifstream input("input");
  input >> x >> str;
  std::cout << x << ' ' << str << '\n';

  std::ofstream output("output");
  output << "Hello!\n";


  std::stringstream ss_from("sdsdfds\n6 7.5 x\nafsdfsd\n");
  std::getline(ss_from, str);
  std::cout << str << '\n';
  double d;
  ss_from >> x >> d >> str;
  std::cout << x << ' ' << d << ' ' << str << '\n';

  std::stringstream ss_to;
  ss_to << 5 << ' ' << true << " bla-bla";
  str = ss_to.str();
  std::cout << str << '\n';
}

