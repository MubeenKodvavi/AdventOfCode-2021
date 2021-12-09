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
    vector<int> countArr;
    for (auto x : lowPoints)
    {
        // perform bfs on every low point.
        queue<pair<int, int>> q;
        int currCount = 1;
        vector<vector<int>> visited(puzzle.size(), vector<int>(puzzle[0].size(), 0));
        q.push(x);
        visited[x.first][x.second] = 1;
        while (!q.empty())
        {
            int curr_x = q.front().first;
            int curr_y = q.front().second;
            q.pop();
            for (int i = 0; i < directions.size(); i++)
            {
                if (isValid(rows, cols, curr_x + directions[i].first, curr_y + directions[i].second) &&
                    puzzle[curr_x][curr_y] < puzzle[curr_x + directions[i].first][curr_y + directions[i].second] &&
                    puzzle[curr_x + directions[i].first][curr_y + directions[i].second] != 9 &&
                    !visited[curr_x + directions[i].first][curr_y + directions[i].second])
                {
                    q.push({curr_x + directions[i].first, curr_y + directions[i].second});
                    visited[curr_x + directions[i].first][curr_y + directions[i].second] = 1;
                    currCount++;
                }
            }
        }
        countArr.push_back(currCount);
    }
    sort(countArr.begin(), countArr.end(), greater<int>());
    int mul = 1;
    for (int i = 0; i < 3; i++)
    {
        mul *= countArr[i];
    }
    cout << mul;
}