#include <iostream>
#include <vector>


class Empty {
 public:
  Empty(int) {
  }
};


struct RationalNumberStruct {
  int num;
  int den;
};


class RationalNumber {
 public:
  // __init__(self, num, den)
  RationalNumber() : num_(0), den_(1) {
    Relax();
  }

  explicit RationalNumber(int num, int den = 1) : num_(num), den_(den)
  {
    Relax();
  }

  RationalNumber(const RationalNumber& other)
    : num_{other.num_}
    , den_{other.den_}
  {
  }

  RationalNumber& operator=(const RationalNumber& other) {
    num_ = other.num_;
    den_ = other.den_;
    return *this;
  }

  RationalNumber& operator=(int x) {
    num_ = x;
    den_ = 1;
    return *this;
  }

  RationalNumber& operator+=(const RationalNumber& other) {
    num_ = num_ * other.den_ + other.num_ * den_;
    den_ = den_ * other.den_;
    return *this;
  }

  RationalNumber operator+() const {
    return *this;
  }

  RationalNumber operator-() const {
    return RationalNumber(-num_, den_);
  }

  // RationalNumber& operator-=(const RationalNumber& other);
  // RationalNumber& operator*=(const RationalNumber& other);
  // RationalNumber& operator/=(const RationalNumber& other);
  // RationalNumber& operator%=(const RationalNumber& other);

  // ++x;
  RationalNumber& operator++() {
    num_ += den_;
    return *this;
  }

  // x++;
  RationalNumber operator++(int x) {
    RationalNumber tmp(*this);
    num_ += den_;
    return tmp;
  }

  // RationalNumber& operator--();
  // RationalNumber operator--(int);


  std::string ToString() const {
    return std::to_string(num_) + "/" + std::to_string(den_);
  }

  double ToDouble() const {
    return static_cast<double>(num_) / den_;
  }

  void SetNum(int num) {
    num_ = num;
  }

  RationalNumber operator*(const RationalNumber& other) const {
    return RationalNumber(num_ * other.num_, den_ * other.den_);
  }

  RationalNumber& Incr() {
    num_ += den_;
    return *this;
  }

  RationalNumber Incr() const {
    RationalNumber other(num_, den_);
    return other.Incr();
  }

  /*
  int GetNum() const {
    return num_;
  }

  int GetDen() const {
    return den_;
  }
  */

  /*
  friend RationalNumber operator+(const RationalNumber& lhs,
                                  const RationalNumber& rhs);
  */

  friend std::istream& operator>>(std::istream& is,
                                  RationalNumber& n);
 private:
  void Relax() {
    if (den_ == 0) {
      den_ = 1;
    }
    if (den_ < 0) {
      den_ *= -1;
      num_ *= -1;
    }
    int x = 2;
    while (x <= den_ && x <= num_) {
      while (den_ % x == 0 && num_ % x == 0) {
        den_ /= x;
        num_ /= x;
      }
      ++x;
    }
  }

  int num_ = 0;
  int den_ = 1;
};


RationalNumber operator+(const RationalNumber& lhs,
                         const RationalNumber& rhs) {
  RationalNumber res(lhs);
  return res += rhs;
}

std::ostream& operator<<(std::ostream& os, const RationalNumber& n) {
  os << n.ToString();
  return os;
}

std::istream& operator>>(std::istream& is, RationalNumber& n) {
  char c;
  is >> n.num_ >> c >> n.den_;
  return is;
}

struct S {
 // public: по умолчанию
};

class C {
 // private: по умолчанию
};


class RationalNumberPtr {
 public:
  explicit RationalNumberPtr(RationalNumber* ptr) : ptr_(ptr) {
  }

  RationalNumber& operator*() {
    return *ptr_;
  }

  RationalNumber* operator->() {
    return ptr_;
  }

 private:
  RationalNumber* ptr_;
};

class RationalNumberVector {
 public:
  RationalNumberVector() {
    data_.push_back(RationalNumber(2, 3));
  }

  // x = rnv[5];
  // rnv[4] = x;
  RationalNumber& operator[](size_t idx) {
    return data_[idx];
  }

  const RationalNumber& operator[](size_t idx) const {
    return data_[idx];
  }

 private:
  std::vector<RationalNumber> data_;
};


// x(4, 6)
// std::string operator()(size_t i, int x) {
//     ...
// }

int main() {
  const RationalNumber x(1, 3);
  RationalNumber z(1, 3);
  const RationalNumber y(3, 5);

  RationalNumber* ptr = &z;
  (*ptr).ToString();
  ptr->ToString();

  RationalNumberPtr smart_ptr(ptr);
  (*smart_ptr).ToString();
  smart_ptr->ToString();



  z = RationalNumber(1);
  z = 1;
  std::cout << ((z = y) + x).ToString() << '\n';
  z = +y;
  z = -x;

  std::string str;
  // +str == str.size();

  ++z;
  z++;

  std::cout << x.Incr().ToString() << ' ' << x.ToString() << '\n';
  std::cout << z.Incr().ToString() << ' ' << z.ToString() << '\n';
  std::cout << z << '\n';
  std::cin >> z;
  std::cout << z << '\n';
}

