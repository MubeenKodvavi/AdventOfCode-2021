#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<vector<string>> input;
    vector<vector<string>> output;
    string s;
    int j = 0;
    int totalSum = 0;
    while (cin >> s)
    {
        unordered_map<int, set<char>> currMp;
        input.push_back(vector<string>(0));
        output.push_back(vector<string>(0));
        input[j].push_back(s);
        switch (s.length())
        {
        case 2:
            for (auto x : s)
            {
                currMp[1].insert(x);
            }
            break;
        case 4:
            for (auto x : s)
            {
                currMp[4].insert(x);
            }
            break;
        case 3:
            for (auto x : s)
            {
                currMp[7].insert(x);
            }
            break;
        case 7:
            for (auto x : s)
            {
                currMp[8].insert(x);
            }
            break;
        default:
            break;
        }
        for (int i = 0; i < 9; i++)
        {
            cin >> s;
            input[j].push_back(s);
            switch (s.length())
            {
            case 2:
                for (auto x : s)
                {
                    currMp[1].insert(x);
                }
                break;
            case 4:
                for (auto x : s)
                {
                    currMp[4].insert(x);
                }
                break;
            case 3:
                for (auto x : s)
                {
                    currMp[7].insert(x);
                }
                break;
            case 7:
                for (auto x : s)
                {
                    currMp[8].insert(x);
                }
                break;
            default:
                break;
            }
        }
        for (int i = 0; i < input[j].size(); i++)
        {
            set<char> currSet;
            for (auto x : input[j][i])
            {
                currSet.insert(x);
            }
            switch (input[j][i].length())
            {
            case 5:
                if (includes(currSet.begin(), currSet.end(), currMp[1].begin(), currMp[1].end()))
                {
                    currMp[3] = currSet;
                }
                break;
            case 6:
                if (includes(currSet.begin(), currSet.end(), currMp[4].begin(), currMp[4].end()))
                {
                    currMp[9] = currSet;
                }
                break;
            default:
                break;
            }
        }
        for (int i = 0; i < input[j].size(); i++)
        {
            set<char> currSet;
            for (auto x : input[j][i])
            {
                currSet.insert(x);
            }
            switch (input[j][i].length())
            {
            case 5:
                if (includes(currMp[9].begin(), currMp[9].end(), currSet.begin(), currSet.end()) && currSet != currMp[3])
                {
                    currMp[5] = currSet;
                }
                break;
            case 6:
                if (includes(currSet.begin(), currSet.end(), currMp[7].begin(), currMp[7].end()) && currSet != currMp[9])
                {
                    currMp[0] = currSet;
                }
                break;
            default:
                break;
            }
        }
        for (int i = 0; i < input[j].size(); i++)
        {
            set<char> currSet;
            for (auto x : input[j][i])
            {
                currSet.insert(x);
            }
            switch (input[j][i].length())
            {
            case 5:
                if (currSet != currMp[5] && currSet != currMp[3])
                {
                    currMp[2] = currSet;
                }
                break;
            case 6:
                if (currMp[0] != currSet && currSet != currMp[9])
                {
                    currMp[6] = currSet;
                }
                break;
            default:
                break;
            }
        }
        cin >> s;
        int currNum = 0;
        for (int i = 3; i >= 0; i--)
        {
            cin >> s;
            output[j].push_back(s);
            set<char> currSet;
            for (auto y : s)
            {
                currSet.insert(y);
            }
            for (auto y : currMp)
            {
                if (currSet == y.second)
                {
                    currNum += y.first * pow(10, i);
                }
            }
        }
        totalSum += currNum;
        j++;
    }
    cout << totalSum;
}