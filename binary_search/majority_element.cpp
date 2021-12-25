#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool ismajority(vector<int> v, int n, int key)
{
    int lower = lower_bound(v.begin(), v.end(), key) - v.begin();

    if (v[lower] == key && ((lower + n / 2) < n && v[lower + n / 2] == key))
        return true;

    return false;
}

int main()
{
    vector<int> v = {1, 1, 1, 2, 2};
    cout << ismajority(v, 5, 1);
    return 0;
}