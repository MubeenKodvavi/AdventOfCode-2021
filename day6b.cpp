#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    stringstream ss(s);
    vector<long long> fishFreq(10, 0);
    while (ss.good())
    {
        string substr;
        getline(ss, substr, ',');
        fishFreq[stoi(substr)]++;
    }
    int daysCount = 256;
    while (daysCount--)
    {
        rotate(fishFreq.begin(), fishFreq.begin() + 1, fishFreq.end());
        if (fishFreq[9])
        {
            fishFreq[6] += fishFreq[9];
            fishFreq[8] += fishFreq[9];
            fishFreq[9] = 0;
        }
    }
    long long count = 0;
    for (int i = 0; i < 9; i++)
    {
        count += fishFreq[i] * 1LL;
    }
    cout << count;
}