#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    cin >> str;
    stringstream ss(str);
    vector<int> positions;
    while (ss.good())
    {
        string substr;
        getline(ss, substr, ',');
        positions.push_back(stoi(substr));
    }
    int minCost = INT_MAX;
    for (int i = 0; i < 2000; i++)
    {
        int cost = 0;
        for (int j = 0; j < positions.size(); j++)
        {
            cost += abs(i - positions[j]);
        }
        minCost = min(cost, minCost);
    }
    cout << minCost;
}