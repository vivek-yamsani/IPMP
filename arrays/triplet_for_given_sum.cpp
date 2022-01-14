#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

vector<tuple<int, int, int>> triplet(vector<int> v, int n, int target)
{
    vector<tuple<int, int, int>> ans;
    for (int a = 0; a < n - 2; a++)
    {
        int sum = target - v[a];
        unordered_map<int, int> m;
        for (int i = a + 1; i < n; i++)
        {
            if (m.find(sum - v[i]) != m.end())
            {
                ans.push_back({a, m[sum - v[i]], i});
            }
            m[v[i]] = i;
        }
    }

    return ans;
}

int main()
{
    vector<tuple<int, int, int>> ans = triplet(vector<int>{1, 2, 3, 4, 5}, 5, 9);
    for (auto i : ans)
    {
        cout << get<0>(i) << " " << get<1>(i) << " " << get<2>(i) << "\n";
    }
    return 0;
}