#include <iostream>
#include <string>

class Animal {
public:
  Animal();
};

Animal::Animal() {
  std::string name;
  name = "terlik";
}

int main() {
  if (true) {
    int i = 1;
  }
  Animal a = Animal();
  return 0;
}
