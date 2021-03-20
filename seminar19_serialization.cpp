#include <iostream>
#include <sstream>
#include <vector>

template <typename T>
void Serialize(std::ostream& os, T elem);


template <typename T>
void SerializeVector(std::ostream& os, std::vector<T> v) {
  size_t size;
  os.write(reinterpret_cast<char*>(&size), sizeof(size));
  for (auto& x : v) {
    Serialize(os, x);
  }
}




int main() {
  // [][][][][][][][]
  double x = 3.14 + 1e-10;
  // char x[8];
  std::stringstream ss;

  // char*, size_t
  ss.write(reinterpret_cast<char*>(&x), sizeof(x));

  std::cout << ss.str() << '\n';

  int64_t y;
  ss.read(reinterpret_cast<char*>(&y), sizeof(y));

  // std::cout << x << ' ' << (x == 3.14) << '\n';
  // std::cout << y << '\n';
  //
  //
  //

  struct string {
    char* data;
    size_t size;
    size_t cap;

    char small_str[16];
  };

  std::string str = "Hello! some long long long long long long long string";
  // std::string str = "Hello!";
  ss.clear();

  // char*, size_t
  ss.write(reinterpret_cast<char*>(&str), sizeof(str));

  str.clear();
  str[1] = ' ';
  std::string another_string;

  ss.read(reinterpret_cast<char*>(&str), sizeof(str));

  std::cout << str << '\n';



  str = "Hello again";

  ss.clear();
  ss.write(str.data(), str.size());

  another_string.clear();
  another_string.resize(str.size());
  ss.read(another_string.data(), str.size());

  std::cout << another_string << '\n';




  str = "Good example";
  size_t size = str.size();
  ss.write(reinterpret_cast<char*>(&size), sizeof(size));
  ss.write(str.data(), size);
  size = 0;
  str.clear();


  ss.read(reinterpret_cast<char*>(&size), sizeof(size));
  another_string.resize(size);
  ss.read(another_string.data(), size);
  std::cout << another_string << '\n';





  // 2^8 = 256
  // UTF-16, UTF-32
  //
  // UTF-8
  // 0******* - ASCII
  // 110***** 10******
  // 1110**** 10****** 10******
  // 11110*** 10****** 10****** 10******

  str = "Привет";
  std::cout << str.size() << '\n';
  str[1] = ' ';
  std::cout << str << '\n';


  ss.clear();
  std::vector<int> v{1, 2, 3};

  size = v.size();
  ss.write(reinterpret_cast<char*>(&size), sizeof(size));
  ss.write(reinterpret_cast<char*>(v.data()), size * sizeof(*v.data()));
  /*
  for (int num : v) {
    ss.write(reinterpret_cast<char*>(&num), sizeof(num));
  }
  */

  v.clear();

  // Read
  ss.read(reinterpret_cast<char*>(&size), sizeof(size));
  v.resize(size);
  /*
  for (int& num : v) {
    ss.read(reinterpret_cast<char*>(&num), sizeof(num));
  }
  */
  ss.read(reinterpret_cast<char*>(v.data()), size * sizeof(*v.data()));

  for (auto num : v) {
    std::cout << num << ' ';
  }
  std::cout << '\n';
}

