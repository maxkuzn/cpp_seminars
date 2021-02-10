#include <iostream>


class Empty {
 public:
  Empty(int) {
  }
};


class RationalNumber {
 public:
  // __init__(self, num, den)
  RationalNumber() : num_(1), den_(0) {
    Relax();
  }

  RationalNumber(int num, int den = 1)
    : num_(num)
    , den_(den)
  {
    Relax();
  }

  std::string ToString() const {
    return std::to_string(num_) + "/" + std::to_string(den_);
  }

  double ToDouble() const {
    return static_cast<double>(num_) / den_;
  }

  void SetNum(int num) {
    num_ = num;
  }


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

  int num_;
  int den_;
};


struct S {
 // public:
};

class C {
 // private:
};

int main() {
  RationalNumber n(8, 2);
  std::cout << n.ToString() << '\n';
}

