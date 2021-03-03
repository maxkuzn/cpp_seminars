#include <iostream>
#include <vector>

class Matrix {
 public:
  Matrix(const std::vector<std::vector<int>>& data) : data_(data) {
  }

  int& operator()(size_t i, size_t j) {
    return data_[i][j];
  }

  int operator()(size_t i, size_t j) const {
    return data_[i][j];
  }

  std::pair<size_t, size_t> size() const {
    return std::make_pair(data_.size(), data_[0].size());
  }

  class Iterator {
   public:
    Iterator(Matrix& matrix, size_t row, size_t col)
      : matrix_(matrix)
      , row_(row)
      , col_(col)
    {}

    bool operator!=(const Iterator& other) const {
      return &matrix_ != &other.matrix_ ||
             row_ != other.row_ || col_ != other.col_;
    }

    Iterator& operator++() {
      ++col_;
      if (col_ == matrix_.size().second) {
        col_ = 0;
        ++row_;
      }
      return *this;
    }

    int& operator*() {
      return matrix_(row_, col_);
    }

   private:
    Matrix& matrix_;
    size_t row_;
    size_t col_;
  };


  Iterator begin() {
    return Iterator(*this, 0, 0);
  }

  Iterator end() {
    return Iterator(*this, data_.size(), 0);
  }

  // const_iterator begin() const;
  // const_iterator end() const;

  // const_iterator cbegin() const;
  // const_iterator cend() const;


 private:
  std::vector<std::vector<int>> data_;
};


std::ostream& operator<<(std::ostream& os, const Matrix& m) {
  /*
  auto size = m.size();
  size_t rows = size.first;
  size_t cols = size.second;
  */
  auto [rows, cols] = m.size();
  for (size_t i = 0; i != rows; ++i) {
    for (size_t j = 0; j != cols; ++j) {
      os << m(i, j) << ' ';
    }
    std::cout << '\n';
  }
  return os;
}


class FlattenMatrix {
 public:
  FlattenMatrix(const std::vector<std::vector<int>>& data) {
    cols_ = data[0].size();
    data_.resize(data.size() * data[0].size());

    for (size_t i = 0; i != data.size(); ++i) {
      for (size_t j = 0; j != data[0].size(); ++j) {
        (*this)(i, j) = data[i][j];
      }
    }
  }

  // 0 1
  // 2 3
  // 0 1 2 3

  int& operator()(size_t i, size_t j) {
    return data_[i * cols_ + j];
  }

  int operator()(size_t i, size_t j) const {
    return data_[i * cols_ + j];
  }

  std::pair<size_t, size_t> size() const {
    return std::make_pair(data_.size() / cols_, cols_);
  }

  auto begin() {
    return data_.begin();
  }

  auto end() {
    return data_.end();
  }

  // const_iterator begin() const;
  // const_iterator end() const;

  auto cbegin() const {
    return data_.cbegin();
  }

  // const_iterator cend() const;


 private:
  size_t cols_;
  std::vector<int> data_;
};


std::ostream& operator<<(std::ostream& os, const FlattenMatrix& m) {
  /*
  auto size = m.size();
  size_t rows = size.first;
  size_t cols = size.second;
  */
  auto [rows, cols] = m.size();
  for (size_t i = 0; i != rows; ++i) {
    for (size_t j = 0; j != cols; ++j) {
      os << m(i, j) << ' ';
    }
    std::cout << '\n';
  }
  return os;
}



int main() {
  Matrix m({{1, 2}, {3, 4}});
  std::cout << m;

  for (auto it = m.begin(); it != m.end(); ++it) {
    *it += 1;
  }
  std::cout << '\n';

  std::cout << m;
  std::cout << '\n';

  FlattenMatrix fm({{1, 2}, {3, 4}});
  std::cout << fm;

  for (auto it = fm.begin(); it != fm.end(); ++it) {
    *it += 1;
  }
  std::cout << '\n';

  std::cout << fm;



  for (int& x : m) {  // begin(), end()
    x *= 10;
  }
  std::cout << m << '\n';
}

