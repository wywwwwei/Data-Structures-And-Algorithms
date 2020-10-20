/**
 * [编程题]压缩算法
 * https://www.nowcoder.com/questionTerminal/c27561e5b7e0441493adb9a54071888d
 */

#include <bits/stdc++.h>

using namespace std;

// overload operator *
string operator*(string s, size_t count)
{
    string ret;
    for (size_t i = 0; i < count; ++i)
    {
        ret = ret + s;
    }
    return ret;
}

class Decompress
{
    string &input;
    int index;
    int size;

    enum State
    {
        kString,
        kInt,
        kComString
    };

public:
    explicit Decompress(string &str) : input(str), index(0)
    {
        size = input.length();
    }

    string parse()
    {
        string result;
        State cur = State::kString;

        int count = 0;
        string cur_str;
        while (index < size)
        {
            switch (cur)
            {
            case State::kString:
                if (input[index] == '[')
                {
                    cur = State::kInt;
                }
                else if (input[index] == ']')
                {
                    index--;
                    return result;
                }
                else
                {
                    result += input[index];
                }
                break;

            case State::kInt:
                if (input[index] == '|')
                {
                    cur = State::kComString;
                }
                else
                {
                    count = count * 10 + (input[index] - '0');
                }
                break;

            case State::kComString:
                if (input[index] == '[')
                {
                    cur_str.append(parse());
                }
                else if (input[index] == ']')
                {
                    result += cur_str * count;
                    cur_str.clear();
                    count = 0;
                    cur = State::kString;
                }
                else
                {
                    cur_str += input[index];
                }
                break;
            default:
                break;
            }
            index++;
        }
        return result;
    }
};

int main()
{
    string input;
    cin >> input;
    cout << Decompress(input).parse() << endl;
}