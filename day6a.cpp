#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    stringstream ss(s);
    vector<int> fishTimer;
    while (ss.good())
    {
        string substr;
        getline(ss, substr, ',');
        fishTimer.push_back(stoi(substr));
    }
    int daysCount = 80;
    while (daysCount--)
    {
        int fishCount = fishTimer.size();
        for (int i = 0; i < fishCount; i++)
        {
            fishTimer[i]--;
            if (fishTimer[i] < 0)
            {
                fishTimer[i] = 6;
                fishTimer.push_back(8);
            }
        }
    }
    cout << fishTimer.size();
}