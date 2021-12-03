#include <bits/stdc++.h>
using namespace std;

int main()
{
    string direction;
    int units;
    int horizontal = 0, vertical = 0;
    while (cin >> direction >> units)
    {
        if (direction == "forward")
        {
            horizontal += units;
        }
        else if (direction == "up")
        {
            vertical -= units;
        }
        else if (direction == "down")
        {
            vertical += units;
        }
    }
    cout << horizontal * vertical << endl;
}