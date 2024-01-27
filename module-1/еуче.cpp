#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
  int arr[] = {1, 2, 3, 4, 5};

  cout << arr[3] << endl;
  cout << *(arr + 3) << endl;
  cout << *(3 + arr) << endl;

  return 0;
}
