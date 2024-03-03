#include <vector>
#include <cassert>
using namespace std;
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
    vector<int> fromList;
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

int main(int argc, char const *argv[])
{
    Node *first = constructNode(1);
    pushBack(first, 2);
    pushBack(first, 3);
    assert(
        sumOfList(first) == 6);
    assert(
        sizeOfList(first) == 3);
    deleteList(first);

    return 0;
}
