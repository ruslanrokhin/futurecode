 #include <iostream>
 #include <cassert>
 int rangeCheck(long long a[], int x, long long *b)
 {
    return (a <= b && b <= (a + (x - 1)));
 }

 inline const int COUNT = 10;
 int main(int argc, char const *argv[])
 {
    long long a[COUNT];
   assert(rangeCheck(a, COUNT, a - 2 ) == 0);
    assert(rangeCheck(a, COUNT, a  ) == 1);
    assert(rangeCheck(a, COUNT, a + COUNT ) == 0);
    assert(rangeCheck(a, COUNT, a + (COUNT -1) ) == 1);
    assert(rangeCheck(a, COUNT, a + 1 ) == 1);
    return 0;
 }
 