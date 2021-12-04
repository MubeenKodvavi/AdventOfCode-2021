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
    vector<int> bingo(matrices.size(), 0);
    bool found = false, lastBingo = false;
    pair<int, int> values;
    for (int i = 0; i < numbers.size() && lastBingo == false; i++)
    {
        for (int j = 0; j < matrices.size() && lastBingo == false; j++)
        {
            for (int k = 0; k < 5 && lastBingo == false; k++)
            {
                for (int l = 0; l < 5 && lastBingo == false; l++)
                {
                    if (matrices[j][k][l] == numbers[i])
                    {
                        done[j][k][l] = 1;
                        found = true;
                        for (int m = 0; m < 5; m++)
                        {
                            if (!done[j][k][m])
                            {
                                found = false;
                            }
                        }
                        if (found == true)
                        {
                            values = {j, numbers[i]};
                            bingo[j] = 1;
                            lastBingo = true;
                            for (int n = 0; n < bingo.size(); n++)
                            {
                                if (!bingo[n])
                                {
                                    lastBingo = false;
                                }
                            }
                            if (numbers[i] == 12)
                                cout << "Hello";
                        }
                        else
                        {
                            found = true;
                            for (int o = 0; o < 5; o++)
                            {
                                if (!done[j][o][l])
                                {
                                    found = false;
                                }
                            }
                            if (found == true)
                            {
                                values = {j, numbers[i]};
                                bingo[j] = 1;
                                lastBingo = true;
                                for (int n = 0; n < bingo.size(); n++)
                                {
                                    if (!bingo[n])
                                    {
                                        lastBingo = false;
                                    }
                                }
                            }
                        }
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
    cout << values.first << " " << values.second;
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
}