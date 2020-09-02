/**
 * 剑指 Offer 20. 表示数值的字符串  有限状态自动机/DFA
 * link：https://leetcode-cn.com/problems/biao-shi-shu-zhi-de-zi-fu-chuan-lcof/
 */

class Solution
{
    enum State
    {
        kInital,
        kIntSign,
        kInt,
        kPoint,
        kPointWithoutInt,
        kFraction,
        kExp,
        kExpSign,
        kExpNum,
        kEnd
    };
    enum CharType
    {
        kNumber,
        kSign,
        kExponent,
        kSpace,
        kDecPoint,
        kIllegal
    };

    CharType toCharType(char &c)
    {
        if (c >= '0' && c <= '9')
            return CharType::kNumber;
        else if (c == '+' || c == '-')
            return CharType::kSign;
        else if (c == 'e' || c == 'E')
            return CharType::kExponent;
        else if (c == '.')
            return CharType::kDecPoint;
        else if (c == ' ')
            return CharType::kSpace;
        return CharType::kIllegal;
    }

public:
    bool isNumber(string s)
    {
        State cur = State::kInital;

        for (int i = 0; i < s.length(); i++)
        {
            CharType curChar = toCharType(s[i]);
            switch (cur)
            {
            case State::kInital:
                switch (curChar)
                {
                case CharType::kNumber:
                    cur = State::kInt;
                    break;
                case CharType::kDecPoint:
                    cur = State::kPointWithoutInt;
                    break;
                case CharType::kSign:
                    cur = State::kIntSign;
                    break;
                case CharType::kSpace:
                    cur = State::kInital;
                    break;
                default:
                    return false;
                }
                break;

            case State::kIntSign:
                switch (curChar)
                {
                case CharType::kNumber:
                    cur = State::kInt;
                    break;
                case CharType::kDecPoint:
                    cur = State::kPointWithoutInt;
                    break;
                default:
                    return false;
                }
                break;

            case State::kInt:
                switch (curChar)
                {
                case CharType::kNumber:
                    cur = State::kInt;
                    break;
                case CharType::kExponent:
                    cur = State::kExp;
                    break;
                case CharType::kDecPoint:
                    cur = State::kPoint;
                    break;
                case CharType::kSpace:
                    cur = State::kEnd;
                    break;
                default:
                    return false;
                }
                break;

            case State::kPoint:
            case State::kFraction:
                switch (curChar)
                {
                case CharType::kNumber:
                    cur = State::kFraction;
                    break;
                case CharType::kExponent:
                    cur = State::kExp;
                    break;
                case CharType::kSpace:
                    cur = State::kEnd;
                    break;
                default:
                    return false;
                }
                break;

            case State::kPointWithoutInt:
                switch (curChar)
                {
                case CharType::kNumber:
                    cur = State::kFraction;
                    break;
                default:
                    return false;
                }
                break;

            case State::kExp:
                switch (curChar)
                {
                case CharType::kNumber:
                    cur = State::kExpNum;
                    break;
                case CharType::kSign:
                    cur = State::kExpSign;
                    break;
                default:
                    return false;
                }
                break;

            case State::kExpSign:
                switch (curChar)
                {
                case CharType::kNumber:
                    cur = State::kExpNum;
                    break;
                default:
                    return false;
                }
                break;

            case State::kExpNum:
                switch (curChar)
                {
                case CharType::kNumber:
                    cur = State::kExpNum;
                    break;
                case CharType::kSpace:
                    cur = State::kEnd;
                    break;
                default:
                    return false;
                }
                break;

            case State::kEnd:
                switch (curChar)
                {
                case CharType::kSpace:
                    cur = State::kEnd;
                    break;
                default:
                    return false;
                }
                break;

            default:
                return false;
            }
        }
        return (cur == State::kEnd || cur == State::kExpNum || cur == State::kInt || cur == State::kFraction || cur == State::kPoint);
    }
};