#include <iostream>

using namespace std;
class Person {
private:
    std::string Name;
    int Age;
protected:
    std::string Address;
public:
    void SetName(const std::string& name) {
        this->Name = name;
    }

    void SetAge(int age) {
        this->Age = age;
    }
};

class Student : protected Person {
public:
    void SetAddress(const std::string& address) {
        Address = address;
    }
    void set()
    {
    SetName("John");
    SetAge(20);
    }
};

int main() {
    Student student;
    student.SetAddress("123 Main St.");
}
