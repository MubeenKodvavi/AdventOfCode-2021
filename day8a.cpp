#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    int one = 0, four = 0, seven = 0, eight = 0;
    while (cin >> s)
    {
        for (int i = 0; i < 9; i++)
        {
            cin >> s;
        }
        cin >> s;
        for (int i = 0; i < 4; i++)
        {
            cin >> s;
            if (s.length() == 2)
                one++;
            else if (s.length() == 4)
                four++;
            else if (s.length() == 3)
                seven++;
            else if (s.length() == 7)
                eight++;
        }
    }
    cout << one + four + seven + eight;
}