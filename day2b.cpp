#include <bits/stdc++.h>
using namespace std;

int main()
{
    string direction;
    int units;
    long horizontal = 0, vertical = 0, aim = 0;
    while (cin >> direction >> units)
    {
        if (direction == "forward")
        {
            horizontal += units;
            vertical += aim * units;
        }
        else if (direction == "up")
        {
            aim -= units;
        }
        else if (direction == "down")
        {
            aim += units;
        }
    }
    cout << horizontal * vertical << endl;
}