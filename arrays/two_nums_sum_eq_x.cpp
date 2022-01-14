#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

vector<int> twoSum(vector<int> &a, int target)
{
    unordered_map<int, int> m;
    int n = a.size();
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        if (m.find(target - a[i]) != m.end())
        {
            ans.push_back(m[target - a[i]]);
            ans.push_back(i);
            return ans;
        }

        m[a[i]] = i;
    }

    return ans;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int &i : a)
        cin >> i;
    int i = 0, j = n - 1;
    sort(a.begin(), a.end());
    vector<pair<int, int>> ans;
    while (i < j)
    {
        if (a[i] + a[j] == k)
        {
            ans.push_back({a[i], a[j]});
            i++;
            j--;
        }
        else if (a[i] + a[j] < k)
        {
            i++;
        }
        else
            j--;
    }
    for (auto i : ans)
    {
        cout << i.first << " " << i.second << "\n";
    }
    cout << endl;

    return 0;
}