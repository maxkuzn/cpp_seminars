#include <iostream>


struct Person {
  /*
     0: age
     1:
     2: height
     3: height
     4:
     5:
     6:
     7:
     8: name
     ...
     31: name
     ...
     32: sex
     ...
     39:
  */

  uint8_t age;
  uint16_t height;
  std::string name;
  char sex;
};

struct PersonOrdered {
  /*
     0: age
     1: sex
     2: height
     3: height
     4:
     5:
     6:
     7:
     8: name
     ...
     31: name
  */
  uint8_t age;
  char sex;
  uint16_t height;
  std::string name;
};

/*
struct Student {
  uint32_t id;
  std::string name;
  double gpa;
};

Student get_student() {
  return {4, "Tolya", 3.43};
}
*/

auto GetStudent() {
  uint64_t id = 3;
  std::string name = "Tolya";
  double gpa = 3.43;
  return std::make_tuple(id, name, gpa);
}

int main() {
  /*
  Person alex;
  alex.age = 25;
  alex.height = 180;
  alex.name = "Alex";
  alex.sex = 'M';
  // std::cout << alex << '\n';  // Won't compile

  Person nina_{
    23,
    171,
    "Nina",
    'F',
  };
  Person nina{
    .age = 23,
    .name = "Nina",
    .sex = 'F',
    .height = 171,
  };
  std::cout << nina.name << '\n';
  std::cout << static_cast<int>(nina.age) << '\n';
  ++nina.age;
  std::cout << static_cast<int>(nina.age) << '\n';
  */


  /*
  size_t total_size = sizeof(uint8_t) + sizeof(uint16_t) +
                      sizeof(std::string) + sizeof(char);
  std::cout << total_size << '\n';

  std::cout << sizeof(Person) << '\n';
  std::cout << sizeof(PersonOrdered) << '\n';

  Person p;

  std::cout << (reinterpret_cast<char*>(&p.age) - reinterpret_cast<char*>(&p)) << '\n';
  std::cout << reinterpret_cast<char*>(&p.height) - reinterpret_cast<char*>(&p) << '\n';
  std::cout << reinterpret_cast<char*>(&p.name) - reinterpret_cast<char*>(&p) << '\n';
  std::cout << reinterpret_cast<char*>(&p.sex) - reinterpret_cast<char*>(&p) << '\n';
  */

  /*
  std::pair<int, std::string> p;
  // struct Pair {
  //   int first;
  //   std::string second;
  // };
  pair.first = 5;
  pair.second = "Some string";
  */

  // std::tuple<> zero;
  std::tuple<uint32_t, std::string, double> t{8, "Vika", 4.5};
  uint32_t t0;
  std::string t1;
  double t2;

  std::tuple<int, int> x{1, 2};
  std::cout << std::get<0>(x) << '\n';
  std::get<0>(x) = 5;
  std::cout << std::get<0>(x) << '\n';
  std::cout << '\n';

  std::cout << "Group: " << std::get<0>(t) << '\n';
  std::cout << "Name: " << std::get<std::string>(t) << '\n';
  std::cout << "GPA: " << std::get<2>(t) << '\n';
  std::cout << '\n';

  t = GetStudent();
  auto y = GetStudent();
  std::cout << "Group: " << std::get<0>(t) << '\n';
  std::cout << "Name: " << std::get<std::string>(t) << '\n';
  std::cout << "GPA: " << std::get<2>(t) << '\n';
  std::cout << '\n';

  /*
  uint32_t group;
  std::string name;
  double gpa;
  //                           tuple
  std::tie(group, name, gpa) = GetStudent();
  std::cout << "Group: " << group << '\n';
  std::cout << "Name: " << name << '\n';
  std::cout << "GPA: " << gpa << '\n';
  std::cout << '\n';
  */

  auto [group, name, gpa] = GetStudent();
  std::cout << "Group: " << group << '\n';
  std::cout << "Name: " << name << '\n';
  std::cout << "GPA: " << gpa << '\n';
  std::cout << '\n';
}

