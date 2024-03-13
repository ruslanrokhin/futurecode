#include <iostream>

using namespace std;

class Animal
{
    public:
    virtual void MakeSound()
    {
        std::cout << "I am an unknown animal(\n";
    }
    void MakeSound_N()
    {
        std::cout << "NNNN I am an unknown animal(\n";
    }
    virtual void Eat() = 0;
};

class Dog : public Animal
{
    public:
    void MakeSound() override
    {
        std::cout << "Dog(\n";
    }
    void MakeSound_N()
    {
        std::cout << "NNN Dog(\n";
    }
};

class Cat : public Animal
{
    public:
    Cat() {
        MakeSound();
        MakeSound_N();
    }
    // void MakeSound() override
    // {
    //     std::cout << "Cat(\n";
    // }
    void MakeSound_N()
    {
        std::cout << "NNN Cat(\n";
    }
};



int main(int argc, char const *argv[])
{
    int n = 2;
    //std::cin >> n;

    Animal *ptr = 0;
    if (n >= 0)
    {
        ptr = new Cat();
    }
    else
    {
        ptr = new Dog();
    }
    ptr->MakeSound();
    ptr->MakeSound_N();
    static_cast<Dog *>(ptr)->MakeSound_N();
    return 0;
}
