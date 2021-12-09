#include <bits/stdc++.h>
using namespace std;

bool isValid(int rows, int cols, int i, int j)
{
    if (i < 0 || i >= rows)
    {
        return false;
    }
    if (j < 0 || j >= cols)
    {
        return false;
    }
    return true;
}

int main()
{
    string s;
    vector<vector<int>> puzzle;
    while (cin >> s)
    {
        vector<int> curr;
        for (auto x : s)
        {
            curr.push_back(x - '0');
        }
        puzzle.push_back(curr);
    }
    int rows = puzzle.size();
    int cols = puzzle[0].size();
    vector<pair<int, int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    vector<pair<int, int>> lowPoints;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            bool low = true;
            for (int k = 0; k < directions.size(); k++)
            {
                if (isValid(rows, cols, i + directions[k].first, j + directions[k].second) &&
                    puzzle[i][j] >= puzzle[i + directions[k].first][j + directions[k].second])
                {
                    low = false;
                }
            }
            if (low)
            {
                lowPoints.push_back({i, j});
            }
        }
    }
    int sum = 0;
    for (auto x : lowPoints)
    {
        sum += puzzle[x.first][x.second] + 1;
    }
    cout << sum;
}