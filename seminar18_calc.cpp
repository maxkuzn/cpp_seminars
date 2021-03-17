#include <iostream>
#include <memory>

class Expression {
 public:
  virtual ~Expression() = default;

  virtual double eval() = 0;
};


class Number : public Expression {
 public:
  Number(double value) : value_(value) {
  }

  double eval() override {
    return value_;
  }

 private:
  double value_;
};


class Add : public Expression {
 public:
  Add(const std::shared_ptr<Expression>& left,
      const std::shared_ptr<Expression>& right)
    : left_(left)
    , right_(right)
  {}

  double eval() override {
    return left_->eval() + right_->eval();
  }

 private:
  std::shared_ptr<Expression> left_;
  std::shared_ptr<Expression> right_;
};


class Sub : public Expression {
  // TODO
};

class Square : public Expression {
  // TODO
};


int main() {
  // 1 + (2 + 3)
  std::shared_ptr<Expression> exp = std::make_shared<Add>(
    std::make_shared<Number>(1),
    std::make_shared<Add>(
      std::make_shared<Number>(2),
      std::make_shared<Number>(3)
    )
  );

  std::shared_ptr<Expression> five = std::make_shared<Number>(5);

  exp = std::make_shared<Add>(
    std::make_shared<Sub>(
      std::make_shared<Square>(five),
      five
    ),
    std::make_shared<Add>(
      std::make_shared<Number>(2),
      std::make_shared<Number>(3)
    )
  );

  std::cout << exp->eval() << '\n';
}

