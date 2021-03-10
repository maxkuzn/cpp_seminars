#include <iostream>
#include <memory>


class List {
 public:
  List() {
    // head_ = nullptr;
    // tail_ = nullptr;

    head_.reset(new Node);
    tail_ = head_.get();
    head_->next.reset();
    head_->prev = nullptr;

    // head_.next = head_;
    // head_.prev = head_;
  }

  ~List() {
  }

  void push_back(int x) {
    Node* node = new Node;
    // Node* node = new Node;
    node->value = x;

    // head_ / node->prev->next
    // node->next


    node->prev = tail_->prev;
    tail_->prev = node;

    std::unique_ptr<Node>& prev = node->prev ? node->prev->next : head_;

    node->next.reset(prev.release());
    prev.reset(node);
  }

  /* TODO
  void push_front(int x) {
    std::unique_ptr<Node> node(new Node);
    node->value = x;

    node->prev = nullptr;
    node->next = head_;
    head_->prev = node;
    head_ = node;
  }
  */

  void pop_back() {
    std::unique_ptr<Node>& prev = tail_->prev->prev ? tail_->prev->prev->next : head_;
    std::unique_ptr<Node> node(prev.release());

    prev.reset(node->next.release());
    tail_->prev = node->prev;
  }

  /* TODO
  void pop_front() {
    std::unique_ptr<Node> node = head_;
    head_ = node->next;
    head_->prev = nullptr;

    node->prev = nullptr;
    node->next = nullptr;
  }
  */

  int& front() {
    return head_->value;
  }

  int& back() {
    return tail_->prev->value;
  }


  struct Node {
    std::unique_ptr<Node> next;
    Node* prev;
    int value;

    static size_t count;

    Node() {
      ++count;
    }

    ~Node() {
      --count;
    }
  };

 private:
  std::unique_ptr<Node> head_;
  Node* tail_;
};

size_t List::Node::count = 0;


int main() {
  {
    List l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    // l.push_front(1);
    // l.push_front(2);

    std::cout << l.front() << "(== 2)" << '\n';
    std::cout << l.back() << "(== 3)" << '\n';
    std::cout << "Осталось " << List::Node::count << " нод\n";
    // l.pop_front();
    l.pop_back();
    std::cout << "Осталось " << List::Node::count << " нод\n";
    std::cout << l.front() << "(== 1)" << '\n';
    std::cout << l.back() << "(== 1)" << '\n';
  }
  std::cout << "Осталось " << List::Node::count << " нод\n";
}


