#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    vector<long long> pointsList;
    while (cin >> s)
    {
        long long points = 0;
        char curr;
        stack<char> stk;
        bool complete = true;
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
                complete = false;
                break;
            }
        }
        if (complete)
        {
            while (!stk.empty())
            {
                if (stk.top() == '(')
                {
                    points *= 5;
                    points += 1;
                }
                else if (stk.top() == '[')
                {
                    points *= 5;
                    points += 2;
                }
                else if (stk.top() == '{')
                {
                    points *= 5;
                    points += 3;
                }
                else if (stk.top() == '<')
                {
                    points *= 5;
                    points += 4;
                }
                stk.pop();
            }
            pointsList.push_back(points);
        }
    }
    sort(pointsList.begin(), pointsList.end());
    cout << pointsList[pointsList.size() / 2];
}