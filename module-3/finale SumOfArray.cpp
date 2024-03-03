template <typename T>
T sumOfArray(T *array, size_t n)
{
    T sum = *array;
    while (--n != 0)
    {
        sum += *(++array);
    }
    return sum;
}