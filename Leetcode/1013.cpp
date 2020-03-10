/**
 * 1013. 将数组分成和相等的三个部分
 * link：https://leetcode-cn.com/problems/partition-array-into-three-parts-with-equal-sum/
 */

/**
 * We just need to find the fastest cut point 
 * where the sum of the previous values is sum / 3
 * and so is the second cut point
 * 
 * explanation Why just find the fastest place 
 * where sum / 3 appears as the first cut point: 
 * if sum/3 = x, c1 = sum/3 first appearance, c1' = sum/3 second appearance
 * |<--- x --->|<--- ? --->|<--- x --->|<--- x --->|
 * 0           c1          c1'         c2         size
 * if  sum(0->c1) = x and sum(0->c1') = x; 
 * So sum(c1->c1') = 0;
 * So sum(c1->c2) = x;
 * And this does not affect our results
 */
class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int sum = 0;
        for(auto a : A){
            sum += a;
        }
        if(sum % 3)return false;
        sum /= 3;
        
        int left_sum = 0;
        int index = 0;
        int A_size = A.size();
        while(index < A_size - 2){
            left_sum += A[index++];
            if(left_sum == sum)break;
        }
        if(left_sum != sum)return false;

        left_sum = 0;
        while(index < A_size - 1){
            left_sum += A[index++];
            if(left_sum == sum)break;
        }

        return (left_sum == sum);
    }
};