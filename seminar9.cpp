#include <iostream>
#include <queue>
#include <algorithm>

int main() {
  std::vector<int> v{1, 3, 5, 6, 7, 9, 10, 12};
  auto lower_it = std::lower_bound(v.begin(), v.end(), 5);
  auto upper_it = std::upper_bound(v.begin(), v.end(), 5);
  if (lower_it != v.end()) {
    std::cout << *lower_it << '\n';
  }
  if (upper_it != v.end()) {
    std::cout << *upper_it << '\n';
  }
  std::cout << '\n';



  // copy
  std::vector<int> v_copy(v.size());
  std::copy(v.begin(), v.end(), v_copy.begin());
  std::cout << "copy:";
  for (int x : v_copy) {
    std::cout << ' ' << x;
  }
  std::cout << '\n';

  std::reverse(v_copy.begin(), v_copy.end());
  std::cout << "reverse:";
  for (int x : v_copy) {
    std::cout << ' ' << x;
  }
  std::cout << '\n';

  v_copy[0] = 1000;

  // reverse_copy
  std::cout << "reverse_copy:";
  std::reverse_copy(v.begin(), v.end(), v_copy.begin());
  for (int x : v_copy) {
    std::cout << ' ' << x;
  }
  std::cout << '\n';

  v_copy.clear();
  auto bi = std::back_inserter(v_copy);
  *bi = 1;
  ++bi;
  *bi = 10;
  std::cout << "back_inserter:";
  for (int x : v_copy) {
    std::cout << ' ' << x;
  }
  std::cout << '\n';

  v_copy.clear();
  std::copy(v.begin(), v.end(), std::back_inserter(v_copy));
  std::cout << "copy+back_inserter:";
  for (int x : v_copy) {
    std::cout << ' ' << x;
  }
  std::cout << '\n';




  std::vector<int> odd(v.begin(), v.end());
  std::vector<int> even;
  // !remove_copy_if
  std::copy_if(odd.begin(), odd.end(), std::back_inserter(even), [](int x) {
      return x % 2 == 0;
  });

  std::cout << "even:";
  for (int x : even) {
    std::cout << ' ' << x;
  }
  std::cout << '\n';

  auto end_after_remove = std::remove_if(odd.begin(), odd.end(), [](int x) {
      return x % 2 == 0;
  });

  std::cout << "odd:";
  for (int x : odd) {
    std::cout << ' ' << x;
  }
  std::cout << '\n';

  odd.erase(end_after_remove, odd.end());

  std::cout << "odd erase:";
  for (int x : odd) {
    std::cout << ' ' << x;
  }
  std::cout << '\n';
  std::cout << '\n';



  // unique
  v.clear();
  v = {5, 5, 4, 5, 1, 1, 3, 1, 4, 4, 5, 2, 1};
  std::cout << "vector:";
  for (int x : v) {
    std::cout << ' ' << x;
  }
  std::cout << '\n';
  auto end_after_unique = std::unique(v.begin(), v.end());
  std::cout << "unique:";
  for (int x : v) {
    std::cout << ' ' << x;
  }
  std::cout << '\n';

  v.erase(end_after_unique, v.end());
  std::cout << "unique erase:";
  for (int x : v) {
    std::cout << ' ' << x;
  }
  std::cout << '\n';

  std::sort(v.begin(), v.end());
  end_after_unique = std::unique(v.begin(), v.end());
  v.erase(end_after_unique, v.end());
  std::cout << "unique sort erase:";
  for (int x : v) {
    std::cout << ' ' << x;
  }
  std::cout << '\n';
  std::cout << '\n';


  v_copy.clear();
  std::copy(v.begin(), v.end(), std::back_inserter(v_copy));

  // transform
  std::transform(v.begin(), v.end(), v.begin(), [](int x) {
      return x * x;
  });
  std::cout << "transform:";
  for (int x : v) {
    std::cout << ' ' << x;
  }
  std::cout << '\n';

  // merge
  std::vector<int> merged;
  std::merge(v.begin(), v.end(),
             v_copy.begin(), v_copy.end(),
             std::back_inserter(merged));

  std::cout << "merge:";
  for (int x : merged) {
    std::cout << ' ' << x;
  }
  std::cout << '\n';
  std::cout << '\n';


  std::priority_queue<int> max_queue;
  max_queue.push(5);
  max_queue.push(3);
  max_queue.push(7);
  max_queue.push(6);
  std::cout << "max queue: " << max_queue.top() << '\n';

  std::less<int> comp_less;
  comp_less(5, 4);

  std::priority_queue<int, std::vector<int>, std::greater<int>> min_queue;
  min_queue.push(5);
  min_queue.push(3);
  min_queue.push(7);
  min_queue.push(6);
  std::cout << "min queue: " << min_queue.top() << '\n';



  // heap
  std::vector<int> heap{5, 3, 6, 2, 5, 4};

  std::make_heap(heap.begin(), heap.end(), std::greater<int>{});

  // push
  heap.push_back(0);
  std::push_heap(heap.begin(), heap.end(), std::greater<int>{});

  // pop
  std::pop_heap(heap.begin(), heap.end(), std::greater<int>{});
  std::cout << heap.back() << '\n';
  heap.pop_back();






}

