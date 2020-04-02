/**
 * 67. 二进制求和
 * link：https://leetcode-cn.com/problems/add-binary/
 */

class Solution
{
public:
    string addBinary(string a, string b)
    {
        stringstream ss;
        int index1 = a.length() - 1;
        int index2 = b.length() - 1;

        bool carry = false;
        while (index1 >= 0 && index2 >= 0)
        {
            char sum = a[index1] - '0' + b[index2] - '0' + (carry ? 1 : 0);
            carry = judge(sum, ss);
            index1--;
            index2--;
        }
        while (index1 >= 0)
        {
            char sum = a[index1] - '0' + (carry ? 1 : 0);
            carry = judge(sum, ss);
            index1--;
        }
        while (index2 >= 0)
        {
            char sum = b[index2] - '0' + (carry ? 1 : 0);
            carry = judge(sum, ss);
            index2--;
        }
        if (carry)
            ss << '1';
        string result = ss.str();
        reverse(result.begin(), result.end());
        return result;
    }

    bool judge(char &a, stringstream &ss)
    {
        switch (a)
        {
        case 3:
            ss << '1';
            return true;
        case 2:
            ss << '0';
            return true;
        case 1:
            ss << '1';
            return false;
        case 0:
            ss << '0';
            return false;
        }
        return false;
    }
};