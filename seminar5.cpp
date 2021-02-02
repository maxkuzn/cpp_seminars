#include <iostream>
#include <set>
#include <map>
#include <string>

#include <unordered_set>
#include <unordered_map>


struct Student {
  std::string name;
  uint32_t age;

  Student(const std::string& first_name, const std::string& surname, int age_) {
    name = first_name + " " + surname;
    age = age_;
  }

  Student(const std::string& name_, int age_) {
    name = name_;
    age = age_;
  }
};

std::ostream& operator<<(std::ostream& os, const Student& s) {
  os << s.name << ' ' << s.age;
  return os;
}





// For set/map
bool operator<(const Student& lhs, const Student& rhs) {
  return lhs.name < rhs.name;
}

// For unordered_set/map
bool operator==(const Student& lhs, const Student& rhs) {
  return lhs.name == rhs.name && lhs.age == rhs.age;
}

// For unordered_set/map
struct StudentHash {
  size_t operator()(Student const& s) const {
    size_t h = 0;
    for (size_t i = 0; i != s.name.size(); ++i) {
      h += s.name[i];
    }
    h += s.age;
    return h;
  }
};


int main() {
  Student student{"name", 0};
  Student another("first_name", "surname", 0);
  std::cout << another << '\n';

  std::set<int> s;
  s.insert(1);
  s.insert(2);
  s.insert(3);
  s.insert(4);
  s.insert(5);
  s.erase(3);



  /*

          2
        /  \
      1     4
             \
              5

  */


  for (auto it = s.begin(); it != s.end(); ++it) {
    std::cout << *it << '\n';
  }

  for (int x : s) {
    std::cout << x << '\n';
  }

  std::map<int, int> m;
  m[1] = 2;
  m[5] = 6;
  for (auto it = m.begin(); it != m.end(); ++it) {
    std::cout << it->first << ' ' << it->second << '\n';
  }

  m[5] = m[1] + 1;

  for (std::pair<int, int> p : m) {
    std::cout << p.first << ' ' << p.second << '\n';
  }

  std::set<Student> students;
  students.insert({"Max", 21});

  std::multiset<int> ms;
  std::multimap<int, int> mm;
  s.clear();
  s.insert(1);
  s.insert(1);
  s.insert(1);
  ms.insert(1);
  ms.insert(1);
  ms.insert(1);

  std::cout << '\n';
  for (int x : s) {
    std::cout << x << ' ';
  }
  std::cout << '\n';
  for (int x : ms) {
    std::cout << x << ' ';
  }
  std::cout << '\n';

  // multiset ~ map
  m.clear();
  m[1] = 1;
  m[1] += 1;
  if (--m[1] == 0) {
    m.erase(1);
  }

  s.clear();
  s.insert(1);
  s.insert(3);
  s.insert(5);
  s.insert(7);

  for (auto it = s.rbegin(); it != s.rend(); ++it) {
    std::cout << *it << ' ';
  }
  std::cout << '\n';


  // std::set/map: O(log n)

  // std::unordered_set/unordered_map: O(1) - average
  // std::unordered_set/unordered_map: O(n) - worst
  std::unordered_set<int> us;
  us.insert(1);
  us.insert(2);
  us.insert(3);
  us.insert(4);
  us.insert(200);
  us.insert(2165);
  for (int x : us) {
    std::cout << x << ' ';
  }
  std::cout << '\n';

  std::unordered_set<Student, StudentHash> unordered_students;
  unordered_students.insert({"Pasha", 43});

  std::unordered_map<int, std::string> um;
  um[6] = "a";
  um[-5] = "b";


  s.clear();
  s.insert(1);
  s.insert(3);
  auto s_begin = s.begin();
  s.insert(-4);
  s.insert(0);
  s.insert(100);
  s.erase(3);
  std::cout << *s_begin << ' ' << *s.begin() << '\n';


  us.clear();
  us.insert(1);
  us.insert(3);
  auto us_begin = us.begin();
  us.insert(-4);
  us.insert(0);
  us.insert(100);
  for (size_t i = 0; i != 10000; ++i) {
    us.insert(i);
  }
  us.erase(3);
  std::cout << *us_begin << ' ' << *us.begin() << '\n';
}

