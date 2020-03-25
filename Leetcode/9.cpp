/**
 * 9. 回文数 先转字符串再判断
 * link：https://leetcode-cn.com/problems/palindrome-number/
 */

class Solution {
public:
    bool isPalindrome(int x) {
        stringstream int2string;
        int2string << x;

        string &&problem = int2string.str();

        int low_index = 0;
        int high_index = problem.length() - 1;
        while(low_index<high_index){
            if(problem[low_index++]!=problem[high_index--])return false;
        }   
        return true;
    }
};