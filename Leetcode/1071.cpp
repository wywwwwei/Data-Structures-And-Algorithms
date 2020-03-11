/**
 * 1071. 字符串的最大公因子 辗转相除法
 * link：https://leetcode-cn.com/problems/greatest-common-divisor-of-strings/
 */

/**
 * Greatest common divisor -> __gcd(str1.length(),str2.length) is the length of the string to be calculated
 * 
 * But this is based on the fact that both strings are divisible by the same substring
 * Judge method:
 * 1.Find the smallest divisor separately and compare
 *   e.g. str1 = "ABCABC"  str2 = "ABC"   ----> "ABC"(*2) = "ABC"(*1)
 *        str1 = "LEET"    str2 = "CODE"  ----> "LEET"(*1) != "CODE"(*1)
 * 2. str1 + str2 == str2 + str1 
 */

class Solution
{
public:
    string gcdOfStrings(string str1, string str2)
    {
        if (str1 + str2 != str2 + str1)
            return "";
        return str1.substr(0, __gcd(str1.length(), str2.length()));
    }
};