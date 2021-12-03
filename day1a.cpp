#include <bits/stdc++.h>
using namespace std;

int main()
{
    int increase = 0;
    int prev, next;
    cin >> prev;
    while (cin >> next)
    {
        if (prev < next)
        {
            increase++;
        }
        prev = next;
    }
    cout << increase;
}