#include <iostream>
#include <random>
#include <chrono>
#include <thread>

int main() {
  // std::random_device rd;
  // std::mt19937 gen(rd());
  std::mt19937 gen(1255);
  std::uniform_int_distribution<int32_t> distrib(-5, 12);
  for (size_t i = 0; i != 10; ++i) {
    std::cout << distrib(gen) << ' ';
  }
  std::cout << '\n';
  std::cout << '\n';

  auto start = std::chrono::steady_clock::now();
  std::this_thread::sleep_for(std::chrono::seconds(1));
  auto middle = std::chrono::steady_clock::now();
  auto end = std::chrono::steady_clock::now();
  auto duration = end - start;
  std::cout << duration.count() << '\n';

  auto duration_sm = std::chrono::duration_cast<std::chrono::nanoseconds>(middle - start);
  auto duration_se = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
  std::cout << duration_sm.count() << '\n';
  std::cout << duration_se.count() << '\n';
}

