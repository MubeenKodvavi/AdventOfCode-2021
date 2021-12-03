#include <bits/stdc++.h>
using namespace std;

int main()
{
    int prev, pprev, now, next;
    cin >> prev >> pprev >> now;
    int prevSum = prev + pprev + now;
    int currSum = 0;
    int increase = 0;
    while (cin >> next)
    {
        currSum = pprev + now + next;
        if (currSum > prevSum)
        {
            increase++;
        }
        pprev = now;
        now = next;
        prevSum = currSum;
    }
    cout << increase;
}