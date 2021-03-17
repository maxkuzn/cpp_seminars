#include <iostream>


class Animal {
 public:
  explicit Animal(int health) : health_(health) {
  }

  void Eat() {
    std::cout << "Eat\n";
    health_ += 10;
  }

  void TakeDamage(int damage) {
    health_ -= damage;
  }

  void Sleep() {
    std::cout << "Sleep: Zzzzz...\n";
  }

 protected:
  int health_ = 100;
};


/*

   public:
   public -> public
   protected -> protected
   private -> unavaliable

   protected:
   public -> protected
   protected -> protected
   private -> unavaliable

   private:
   public -> private
   protected -> private
   private -> unavaliable

*/


// Dog::Animal()
// Dog()

class Dog : public Animal {
 public:
  Dog(int health) : Animal(health) {
  }

  void Eat() {
    std::cout << "Dog: ";
    Animal::Eat();
  }

  void Bark() {
    health_ += 1;
    std::cout << "Bark, Bark!!!\n";
  }
};



// basic_ios
class Base {
 public:
  void bar() {
    std::cout << "Base\n";
  }
};

// istream
class Derived1 : virtual public Base {
 public:
  void foo() {
    std::cout << "Derived1\n";
  }
};

// ostream
class Derived2 : virtual public Base {
 public:
  void foo() {
    std::cout << "Derived2\n";
  }
};

// iostream
class DerivedFinal : public Derived1, public Derived2 {
  // Derived1 d1;
  // Derived2 d2;
};


/*
        Base
       /    \
  Derived1 Derived2
      |     /
    DerivedFinal

    /\
    \/
*/


int main() {
  Animal a(100);
  Dog d(200);

  a.Eat();
  a.Sleep();

  // d.Eat();
  // d.Sleep();
  d.Eat();
  d.Bark();

  DerivedFinal df;
  df.bar();
}

