#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    cin >> str;
    stringstream ss(str);
    vector<int> numbers;
    while (ss.good())
    {
        string substr;
        getline(ss, substr, ',');
        numbers.push_back(stoi(substr));
    }

    vector<vector<vector<int>>> matrices;

    int a;
    while (cin >> a)
    {
        vector<vector<int>> matrix(5, vector<int>(5, 0));
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                if (i == 0 && j == 0)
                {
                    matrix[i][j] = a;
                }
                else
                {
                    cin >> matrix[i][j];
                }
            }
        }
        matrices.push_back(matrix);
    }
    vector<vector<vector<int>>> done(matrices.size(), vector<vector<int>>(5, vector<int>(5, 0)));
    bool found = false;
    pair<int, int> values;
    for (int i = 0; i < numbers.size() && found == false; i++)
    {
        for (int j = 0; j < matrices.size() && found == false; j++)
        {
            for (int k = 0; k < 5; k++)
            {
                for (int l = 0; l < 5; l++)
                {
                    if (matrices[j][k][l] == numbers[i])
                    {
                        done[j][k][l] = 1;
                    }
                }
            }
            for (int k = 0; k < 5 && found == false; k++)
            {
                found = true;
                for (int l = 0; l < 5; l++)
                {
                    if (!done[j][k][l])
                    {
                        found = false;
                    }
                }
                if (found == true)
                {
                    values = {j, numbers[i]};
                }
            }
            for (int k = 0; k < 5 && found == false; k++)
            {
                found = true;
                for (int l = 0; l < 5; l++)
                {
                    if (!done[j][l][k])
                    {
                        found = false;
                    }
                }
                if (found == true)
                {
                    values = {j, numbers[i]};
                }
            }
        }
    }
    // cout << get<0>(values) <<  get<1>(values) << get<2>(values);
    int unmarked, last = values.second;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (done[values.first][i][j] == 0)
            {
                unmarked += matrices[values.first][i][j];
            }
        }
        cout << endl;
    }
    cout << unmarked * last;
    // cout << matrices.size() << endl;
    // for (int i = 0; i < numbers.size(); i++)
    // {
    //     for (int j = 0; j < matrices.size(); j++)
    //     {
    //         for (int k = 0; k < 5; k++)
    //         {
    //             for (int l = 0; l < 5; l++)
    //             {
    //                 cout << done[j][k][l] << " ";
    //             }
    //             cout << endl;
    //         }
    //     }
    // }
}