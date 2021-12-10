#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    int points = 0;
    unordered_map<char, int> pointsTable;
    pointsTable[')'] = 3;
    pointsTable[']'] = 57;
    pointsTable['}'] = 1197;
    pointsTable['>'] = 25137;
    while (cin >> s)
    {
        char curr;
        stack<char> stk;
        for (auto x : s)
        {
            if (x == '(' || x == '[' || x == '{' || x == '<')
                stk.push(x);
            else if (x == ')' && stk.top() == '(')
                stk.pop();
            else if (x == ']' && stk.top() == '[')
                stk.pop();
            else if (x == '}' && stk.top() == '{')
                stk.pop();
            else if (x == '>' && stk.top() == '<')
                stk.pop();
            else
            {
                points += pointsTable[x];
                break;
            }
        }
    }
    cout << points;
}