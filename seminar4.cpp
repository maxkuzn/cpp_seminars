#include <iostream>
#include <vector>

struct Ref {
  int& x;
};



void PrintVector(const std::vector<int>& vec) {
  for (int x : vec) {
    std::cout << x << ' ';
  }
  std::cout << '\n';
}

void PushBack(const std::vector<int>& a, std::vector<int>& b) {
  b.push_back(-11);
  std::cout << "a: ";
  PrintVector(a);
  std::cout << "b: ";
  PrintVector(b);
  std::cout << '\n';
}



int main() {
  int x = 1;
  int y = 2;

  int* p = &x;
  p = &y;
  *p = 3;

  const int* const_p = &x;
  const_p = &y;
  // *const_p = 3;

  int* const p_const = &x;
  // p_const = &y;
  *p_const = 5;

  const int* const const_p_const = &x;
  // const_p_const = &y;
  // *const_p_const = 5;




  /*
  std::vector<int> original{14, 0, 23, 1};
  std::vector<int>& ref = original;
  std::vector<int>* pointer = &original;
  std::vector<int> copy = original;

  original.push_back(123);
  ref.push_back(456);
  // (*pointer).push_back(789);
  pointer->push_back(789);
  copy.push_back(987654321);

  PrintVector(original);
  PrintVector(ref);
  PrintVector(*pointer);
  PrintVector(copy);
  std::cout << '\n';



  const std::vector<int>& const_ref = original;
  const_ref.size();
  const_ref[1];
  // const_ref.push_back(10);  // Won't compile
  // const_ref[2] = 5;

  const std::vector<int>* const_pointer = &original;
  std::vector<int> another;
  const_pointer->size();
  (*const_pointer)[1];
  // const_pointer->push_back(10);  // Won't compile
  const_pointer = &another;
  const_pointer->size();
  const_pointer = nullptr;  // 0
  // const_pointer->size();  // SEGFALT
  //
  std::vector<int>* const pointer_const = &original;
  (*pointer_const)[0] = 1;
  // pointer_const = &another;




  PushBack(original, original);
  */


  /*
  int original = 42;
  int copy = original;
  int& reference = original;
  int* pointer = &original;

  Ref r{
    .x = original,
    .y = 5,
  };
  Ref t{original};
  r.y == 5;
  r.t == -1;

  std::cout << "sizeof(copy) = " << sizeof(copy) << '\n';
  std::cout << "sizeof(reference) = " << sizeof(reference) << '\n';
  std::cout << "sizeof(Ref) = " << sizeof(Ref) << '\n';
  std::cout << "sizeof(pointer) = " << sizeof(pointer) << '\n';
  std::cout << '\n';

  std::cout << "copy: " << copy << '\n';
  std::cout << "reference: " << reference << '\n';
  std::cout << "pointer: " << *pointer << '\n' << '\n';
  std::cout << '\n';

  original = 123;
  std::cout << "copy: " << copy << '\n';
  std::cout << "reference: " << reference << '\n';
  std::cout << "pointer: " << *pointer << '\n';
  std::cout << '\n';
  */


  std::vector<int> a{0, 1, 2};
  std::vector<std::string> b{"Hello", ",", " ", "World", "!"};

  for (int x : a) {
    // int x = a[i]
    std::cout << x;
  }
  std::cout << '\n';

  // for (std::string s : b) {
  for (const std::string& s : b) {
    // const std::string& s = b[i]
    std::cout << s;
  }
  std::cout << '\n';
  std::cout << '\n';


  for (auto it = b.begin(); it != b.end(); ++it) {
    const std::string& s = *it;
    //...
  }



  std::string_view view = "Some string";
  std::cout << view << '\n';

  {
    std::string str;
    str.push_back('a');
    str.push_back('b');
    str.push_back('c');
    str.push_back('d');
    str.push_back('e');
    str.push_back('f');

    view = str;
    view.remove_prefix(2);
    std::cout << str << '\n';
    std::cout << view << '\n';
    str[3] = ' ';
    std::cout << view << '\n';
    // str.push_back('g');
    str.reserve(1000);
    str[4] = ' ';
    // std::cout << view << '\n';
  }
  // std::cout << view << '\n';
  std::cout << '\n';


  std::vector<int> v;
  for (int i = 0; i < 15; ++i) {
    v.push_back(i);
  }

  auto it = v.begin();
  std::cout << *it << ' ' << *(it + 5) << '\n';
  it += 2;
  *it = -2;
  int* data = v.data();
  // int* data = &v[0];
  data += 3;
  std::cout << *data << '\n';
  *data = -3;
  PrintVector(v);

  //->    0 1 2 3 4 5

  v.push_back(15);
  data += 1;
  *data = -4;
  PrintVector(v);

  v.push_back(16);
  data += 1;
  *data = -5;
  it -= 1;
  *it = -1;
  PrintVector(v);





  char c;
  if ('0' <= c && c <= '9') {
    //...
  } else if (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z')) {
    //...
  }

  if (std::isdigit(c)) {
  } else if (std::isalpha(c)) {
  }



  // std::string_view ~ std::string&
  const size_t SIZE = 10;
  int arr[SIZE];
  //int* arr
  // arr[2] ~ *(arr + 2)

  for (int x : arr) {
    std::cout << x << ' ';
  }
  std::cout << '\n';

  int num = 10;
  auto comp = [&num](int x, int y) {
    if (x <= num) {
      --num;
    }
    if (y <= num) {
      --num;
    }
    if (x > num && y <= num) {
      return true;
    }
    if (x <= num && y > num) {
      return false;
    }
    return x < y;
  };
  std::sort(v.begin(), v.end(), comp);
  PrintVector(v);
}

