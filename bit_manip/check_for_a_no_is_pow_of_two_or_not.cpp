#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    if ((n & (n - 1)) == 0)
    {
        cout << "yes";
    }
    else
        cout << "no";
    return 0;
}