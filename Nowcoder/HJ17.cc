/**
 * HJ17 坐标移动
 * link：https://www.nowcoder.com/practice/119bcca3befb405fbe58abe9c532eb29
 */

#include <bits/stdc++.h>
#include <regex>
#include <sstream>

using namespace std;

int main()
{
    string input;
    cin >> input;

    int resultX = 0, resultY = 0;
    stringstream ss(input);
    string part;
    while (getline(ss, part, ';'))
    {
        if (regex_match(part, regex("[AWSD][0-9]+")))
        {
            int move = stoi(part.substr(1));
            switch (part[0])
            {
            case 'A':
                resultX -= move;
                break;
            case 'D':
                resultX += move;
                break;
            case 'W':
                resultY += move;
                break;
            case 'S':
                resultY -= move;
                break;
            default:
                break;
            }
        }
    }
    cout << resultX << ',' << resultY;
}