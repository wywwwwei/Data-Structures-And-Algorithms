# 1. 两数之和
# link：https://leetcode-cn.com/problems/two-sum/

# @param {Integer[]} nums
# @param {Integer} target
# @return {Integer[]}
def two_sum(nums, target)
  count = Hash.new
  nums.each_with_index do |num, i|
    if count.has_key?(target - num)
      return [count[target - num], i]
    end
    count.store(num, i)
  end
end
