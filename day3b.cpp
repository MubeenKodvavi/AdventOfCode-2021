#include <bits/stdc++.h>
using namespace std;

int binaryToInt(string s)
{
    int integer;
    int j = 0;
    for (int i = s.length() - 1; i >= 0; i--)
    {
        if (s[i] == '1')
        {
            integer += pow(2, j);
        }
        j++;
    }
    return integer;
}

int main()
{
    string s;
    int currentZeroes = 0;
    int currentOnes = 0;
    vector<string> records;
    while (cin >> s)
    {
        records.push_back(s);
    }
    int currentPos = 0;
    vector<string> prevArr = records;
    vector<string> currArr;
    while (currArr.size() != 1 || currentPos < s.length())
    {
        currArr = {};
        currentOnes = 0;
        currentZeroes = 0;
        for (int i = 0; i < prevArr.size(); i++)
        {
            if (prevArr[i][currentPos] == '1')
            {
                currentOnes++;
            }
            else
            {
                currentZeroes++;
            }
        }
        if (currentOnes < currentZeroes)
        {
            for (int j = 0; j < prevArr.size(); j++)
            {
                if (prevArr[j][currentPos] == '0')
                {
                    currArr.push_back(prevArr[j]);
                }
            }
        }
        else
        {
            for (int j = 0; j < prevArr.size(); j++)
            {
                if (prevArr[j][currentPos] == '1')
                {
                    currArr.push_back(prevArr[j]);
                }
            }
        }
        prevArr = currArr;
        currentPos++;
    }
    string oxygenGenerator = currArr[0];
    prevArr = records;
    currArr = {};
    currentPos = 0;
    currentOnes = 0;
    currentZeroes = 0;
    while (currArr.size() != 1 && currentPos < s.length())
    {
        currArr = {};
        currentOnes = 0;
        currentZeroes = 0;
        for (int i = 0; i < prevArr.size(); i++)
        {
            if (prevArr[i][currentPos] == '1')
            {
                currentOnes++;
            }
            else
            {
                currentZeroes++;
            }
        }
        if (currentOnes < currentZeroes)
        {
            for (int j = 0; j < prevArr.size(); j++)
            {
                if (prevArr[j][currentPos] == '1')
                {
                    currArr.push_back(prevArr[j]);
                }
            }
        }
        else
        {
            for (int j = 0; j < prevArr.size(); j++)
            {
                if (prevArr[j][currentPos] == '0')
                {
                    currArr.push_back(prevArr[j]);
                }
            }
        }
        prevArr = currArr;
        currentPos++;
    }
    string CO2Scrubber = currArr[0];
    cout << binaryToInt(CO2Scrubber) * binaryToInt(oxygenGenerator);
}