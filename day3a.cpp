#include <bits/stdc++.h>
using namespace std;

int binaryToInt(vector<char> s)
{
    int integer;
    int j = 0;
    for (int i = s.size() - 1; i >= 0; i--)
    {
        if (s[i] == '1')
        {
            integer += pow(2, j);
        }
        j++;
    }
    return integer;
}

int main()
{
    string s;
    cin >> s;
    vector<vector<int>> arr(2, vector<int>(s.length(), 0));
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '0')
            arr[0][i]++;
        else
            arr[1][i]++;
    }
    while (cin >> s)
    {
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '0')
                arr[0][i]++;
            else
                arr[1][i]++;
        }
    }
    vector<char> gamma;
    vector<char> epsilon;
    for (int i = 0; i < s.length(); i++)
    {
        if (arr[0][i] > arr[1][i])
        {
            gamma.push_back('0');
            epsilon.push_back('1');
        }
        else
        {
            gamma.push_back('1');
            epsilon.push_back('0');
        }
    }
    cout << binaryToInt(gamma) * binaryToInt(epsilon) << endl;
}