#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <vector>


std::map<std::string, size_t> CountFreqMap(const std::vector<std::string>& words) {
  std::map<std::string, size_t> freqs;
  for (const std::string& word : words) {
    freqs[word] += 1;
  }
  return freqs;
}

std::unordered_map<std::string, size_t> CountFreqUMap(
                                          const std::vector<std::string>& words) {
  std::unordered_map<std::string, size_t> freqs;
  for (const std::string& word : words) {
    freqs[word] += 1;
  }
  return freqs;
}

std::unordered_map<std::string, size_t> CountFreqUMapReserve(
                                          const std::vector<std::string>& words) {
  std::unordered_map<std::string, size_t> freqs;
  freqs.reserve(words.size());
  for (const std::string& word : words) {
    freqs[word] += 1;
  }
  return freqs;
}


std::set<size_t> NumsToSet(size_t n) {
  std::set<size_t> s;
  size_t x = 42;
  size_t step = n;
  for (size_t i = 0; i != n; ++i) {
    s.insert(x);
    x += step;
  }
  return s;
}

std::unordered_set<size_t> NumsToUSet(size_t n) {
  std::unordered_set<size_t> us;
  us.reserve(n / 1000);
  us.max_load_factor(1);
  size_t x = 42;
  size_t step = us.bucket_count();
  for (size_t i = 0; i != n; ++i) {
    us.insert(x);
    x += step;
  }
  return us;
}


int main() {
  /*
  size_t n;
  std::cin >> n;
  std::vector<std::string> words(n);
  for (std::string& word : words) {
    std::cin >> word;
  }

  auto map_start = std::chrono::steady_clock::now();
  CountFreqMap(words);
  auto map_end = std::chrono::steady_clock::now();
  std::chrono::duration<double> map_elapsed = map_end - map_start;

  auto umap_start = std::chrono::steady_clock::now();
  CountFreqUMap(words);
  auto umap_end = std::chrono::steady_clock::now();
  std::chrono::duration<double> umap_elapsed = umap_end - umap_start;

  auto umap_reserve_start = std::chrono::steady_clock::now();
  CountFreqUMapReserve(words);
  auto umap_reserve_end = std::chrono::steady_clock::now();
  std::chrono::duration<double> umap_reserve_elapsed = umap_reserve_end - umap_reserve_start;


  std::cout << " map        : " << map_elapsed.count() << '\n';
  std::cout << "umap        : " << umap_elapsed.count() << '\n';
  std::cout << "umap+reserve: " << umap_reserve_elapsed.count() << '\n';
  */

  size_t n = 10000;

  auto set_start = std::chrono::steady_clock::now();
  NumsToSet(n);
  auto set_end = std::chrono::steady_clock::now();
  std::chrono::duration<double> set_elapsed = set_end - set_start;

  auto uset_start = std::chrono::steady_clock::now();
  NumsToUSet(n);
  auto uset_end = std::chrono::steady_clock::now();
  std::chrono::duration<double> uset_elapsed = uset_end - uset_start;

  std::cout << " set        : " << set_elapsed.count() << '\n';
  std::cout << "uset        : " << uset_elapsed.count() << '\n';
}

