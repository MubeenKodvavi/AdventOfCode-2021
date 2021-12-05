#include <bits/stdc++.h>
using namespace std;

int main()
{
    string start, sep, end;
    vector<vector<int>> mat(1000, vector<int>(1000, 0));
    while (cin >> start >> sep >> end)
    {
        // cout << start << end;
        stringstream ss1(start), ss2(end);
        vector<int> startPoints, endPoints;
        while (ss1.good() && ss2.good())
        {
            string substr1, substr2;
            getline(ss1, substr1, ',');
            getline(ss2, substr2, ',');
            startPoints.push_back(stoi(substr1));
            endPoints.push_back(stoi(substr2));
        }
        if (startPoints[0] == endPoints[0])
        {
            int lesser, greater;
            if (startPoints[1] > endPoints[1])
            {
                lesser = endPoints[1];
                greater = startPoints[1];
            }
            else
            {
                lesser = startPoints[1];
                greater = endPoints[1];
            }
            for (int i = lesser; i <= greater; i++)
            {
                mat[startPoints[0]][i]++;
            }
        }
        else if (startPoints[1] == endPoints[1])
        {
            int lesser, greater;
            if (startPoints[0] > endPoints[0])
            {
                lesser = endPoints[0];
                greater = startPoints[0];
            }
            else
            {
                lesser = startPoints[0];
                greater = endPoints[0];
            }
            for (int i = lesser; i <= greater; i++)
            {
                mat[i][startPoints[1]]++;
            }
        }
        else
        {
            if (startPoints[0] < endPoints[0] && startPoints[1] < endPoints[1])
            {
                for (int i = startPoints[0], j = startPoints[1]; i <= endPoints[0] && j <= endPoints[1]; i++, j++)
                {
                    mat[i][j]++;
                }
            }
            else if (startPoints[0] < endPoints[0] && startPoints[1] > endPoints[1])
            {
                for (int i = startPoints[0], j = startPoints[1]; i <= endPoints[0] && j >= endPoints[1]; i++, j--)
                {
                    mat[i][j]++;
                }
            }
            else if (startPoints[0] > endPoints[0] && startPoints[1] < endPoints[1])
            {
                for (int i = startPoints[0], j = startPoints[1]; i >= endPoints[0] && j <= endPoints[1]; i--, j++)
                {
                    mat[i][j]++;
                }
            }
            else if (startPoints[0] > endPoints[0] && startPoints[1] > endPoints[1])
            {
                for (int i = startPoints[0], j = startPoints[1]; i >= endPoints[0] && j >= endPoints[1]; i--, j--)
                {
                    mat[i][j]++;
                }
            }
        }
    }
    int count = 0;
    for (int i = 0; i < mat.size(); i++)
    {
        for (int j = 0; j < mat.size(); j++)
        {
            if (mat[i][j] >= 2)
                count++;
        }
    }
    cout << count;
}