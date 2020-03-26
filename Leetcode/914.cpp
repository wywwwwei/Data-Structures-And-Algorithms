/**
 * 914. 卡牌分组 gcd
 * link：https://leetcode-cn.com/problems/x-of-a-kind-in-a-deck-of-cards/
 */

class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int,int> group;
        for(const int &num : deck)group[num]++;

        int result = 0;
        for(const auto &num : group){
            result = __gcd(result,num.second);
            if(result < 2)return false;
        }

        return true;
    }
};