#include <iostream>
#include <cassert>
#include "FlexArray.h"

using namespace std;

void test1()
{
    FlexArray<int> flex(3);
    flex.at(0) = 1;
    flex.at(1) = 2;
    flex.at(2) = 3;
    std::cout << flex.Size(); // 3

    auto prod = flex * 2;

    for (int i = 0; i < prod.Size(); ++i)
    {
        std::cout << prod.at(i) << " ";
    }
    std::cout << "\n";
    // Должен вывести 1 2 3 1 2 3

    {
        FlexArray<int> last(2);
        last.at(0) = 4;
        last.at(1) = 5;
        flex += last;
        for (int i = 0; i < flex.Size(); ++i)
        {
            std::cout << flex.at(i) << " ";
        }
    }
    std::cout << "\n";
    // Должен вывести 1 2 3 4 5
}

struct test
{
    static unsigned con_counter_, dst_counter_;
    unsigned id_;
    test()
    {
        con_counter_++;
        id_ = con_counter_;
    };
    ~test()
    {
        dst_counter_++;
    };
    // ostream &operator<<(ostream &out) const
    // {
    //     out << id_;
    //     return out;
    // }
};

ostream &operator<<(ostream &out, const test &tmp)
{
    out << tmp.id_;
    return out;
}

unsigned test::con_counter_ = 0;
unsigned test::dst_counter_ = 0;

int main()
{
    test1();
    {
        FlexArray<test> flex(3);
        std::cout << flex.Size() << '\n'; // 3
        cout << flex << endl;
    }

    assert(test::con_counter_ == test::dst_counter_);
}