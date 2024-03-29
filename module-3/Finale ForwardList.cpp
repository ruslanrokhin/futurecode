#include <vector>
#include <iostream>
#include <cassert>
struct Node
{
    Node(Node *next, int value) : next(next), value(value)
    {
    }
    Node *next;
    int value;
};

size_t sizeOfList(Node *first)
{
    size_t size = 0;
    while (first != nullptr)
    {
        size++;
        first = first->next;
    }
    return size;
}

Node *constructNode(int value)
{
    return new Node(nullptr, value);
}

void pushBack(Node *first, int value)
{
    while (true)
    {
        if (first->next == nullptr)
        {
            first->next = new Node(nullptr, value);
            return;
        }
        first = first->next;
    }
}
Node *pushFront(Node *first, int value)
{
    return new Node(first, value);
}
int sumOfList(Node *first)
{
    size_t sum = 0;
    while (first != nullptr)
    {
        sum += first->value;
        first = first->next;
    }
    return sum;
}
void deleteList(Node *first)
{
    while (first != nullptr)
    {
        auto cleaner = first->next;
        delete first;
        first = cleaner;
    }
}

int maxOfList(Node *first)
{
    size_t max = first->value;
    while (first->next != nullptr)
    {
        first = first->next;
        if (max < first->value)
        {
            max = first->value;
        }
    }
    return max;
}
std::vector<int> getVectorFromList(Node *first)
{
   std::vector<int> fromList;
    while (first != nullptr)
    {
        fromList.push_back(first->value);
        first = first->next;
    }
    return fromList;
}
bool compareLists(Node *first1, Node *first2)
{
    while (first1 != nullptr && first2 != nullptr)
    {
        if (first1->value != first2->value)
        {
            return false;
        }
        first1 = first1->next;
        first2 = first2->next;
    }
    return first1 == nullptr && first2 == nullptr;
}

class Iterator
{
public:
    Node *ptr_ = nullptr;
    Node operator()()
    {
        return *ptr_;
    }
    Iterator()
    {
    }
    Iterator(Node *node_ptr) : ptr_(node_ptr)
    {
    }
    Iterator &operator++()
    {
        ptr_ = ptr_->next;
        return *this;
    }
    bool operator!=(Iterator &another)
    {
        return (ptr_ != another.ptr_);
    }
    int &operator*()
    {
        return ptr_->value;
    }
};
class ForwardList
{
public:
    ForwardList(Node *start)
    {
        next_ = start;
    }
    Node *next_;
    Iterator begin()
    {
        return Iterator(next_);
    }
    Iterator end()
    {
        return Iterator();
    }
};

int main(int argc, char const *argv[])
{
    Node *start = nullptr;
    start = pushFront(start, 1);
    pushBack(start, 2);
    pushBack(start, 3);
    ForwardList f(start);
    for (int &v : f)
    {
        v *= 100;
    }
    auto elements = getVectorFromList(start);
    for (int v : elements)
    {
        std::cout << v << "\n";
    }
    // Вывод / 100 / 200 / 300
    pushBack(start, 4);
    for (int v : f)
    {
        std::cout << v << "\n";
    }
    // Вывод / 100 / 200 / 300 / 4
    deleteList(start);
}
