#include <iostream>
#include <cassert>
#include "FlexArray.h"

using namespace std;
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

ostream & operator<< (ostream &out, const test &tmp)
{
   out << tmp.id_;
   return out;
}

unsigned test::con_counter_ = 0;
unsigned test::dst_counter_ = 0;

int main()
{
    {
        FlexArray<test> flex(3);
        std::cout << flex.Size() << '\n'; // 3
        cout << flex << endl;
    }

    assert(test::con_counter_ == test::dst_counter_);
}