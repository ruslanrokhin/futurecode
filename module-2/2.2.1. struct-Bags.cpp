#include <iostream>

struct BagStruct
{
    unsigned int capacity_, balance_ = 0;
    BagStruct(unsigned int capacity) : capacity_(capacity) {}
    void Mint(unsigned int number)
    {
        if (number + balance_ < capacity_)
        {
            balance_ += number;
        }
        else
            balance_ = capacity_;
    }
    unsigned int Balance()
    {
        return balance_;
    }
    void Transfer1(BagStruct &destination)
    {
        unsigned int transfer = destination.capacity_ - destination.balance_;
        if (transfer < balance_)
        {
            destination.balance_ = destination.capacity_;
            balance_ -= transfer;
        }
        else
        {
            destination.balance_ += balance_;
            balance_ = 0;
        }
    }
    void Transfer(BagStruct &destination)
    {
        unsigned int transfer = destination.capacity_ - destination.balance_;
        transfer = transfer > balance_ ? balance_ : transfer;
        balance_ -= transfer;
        destination.balance_ += transfer;
    }
};