#include <iostream>
#include <cassert>

using namespace std;

int Period(int a)
{
    int mod, period = 0;
    mod = a;
    do  {
        mod = mod * a;
        ++period;
    } while(mod % 10 != a%10);
    return period;
}
int Mod (int a, int b)
{
 int rem = a, i = b % Period(a);
 if(i == 0) {
 i = Period(a);
 }
 while(i != 1){
    rem = rem* a;
    --i;
 }
 rem = rem% 10;
 return(rem);
}
int main()
{
    assert(Mod(2, 100) == 6);
    assert(Mod(1, 5) == 1);
    assert(Mod(3, 10) == 9);
    cout << Mod(8,2022);

    cout << endl << "end\n";
    return 0;
}