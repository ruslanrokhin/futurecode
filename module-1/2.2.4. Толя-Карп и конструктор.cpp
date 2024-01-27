#include <cassert>
#include <string>
#include <iostream>
#include <set>

struct MyStruct
{
  int number = 0;
  std::string name;
  void read(std::string s, int n)
  {
    name = s;
    number = n;
  }
  std::string info()
  {
    std::string answer = "Name: " + name + ";\n" + "Number: " + std::to_string(number) + ";";
    return answer;
  }
};

int main()
{
  MyStruct example;
  example.read("name", 123);
  std::cout << example.info();
}