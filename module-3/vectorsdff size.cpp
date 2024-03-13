#include  <iostream>

template <typename T>
void IncreaseSize(T *&buffer, unsigned int oldSize, unsigned int newSize)
{
    if (oldSize == newSize)
    {
        return;
    }
    T *tmp = buffer;
    buffer = new T[newSize];
    for (size_t i = 0; i < oldSize; i++)
    {
        buffer[i] = tmp[i];
    }
    delete[] tmp;
}

int main(int argc, char const *argv[])
{
    int *buffer = new int[3];
    buffer[0] = 1;
    buffer[1] = 2;
    buffer[2] = 3;
    IncreaseSize(buffer, 3, 6);
    buffer[3] = 4;
    buffer[4] = 5;
    buffer[5] = 6;
    for (int i = 0; i < 6; ++i)
    {
        std::cout << buffer[i] << " ";
    }
    delete[] buffer;
    // Должен вывести:
    // 1 2 3 4 5 6
    return 0;
}
