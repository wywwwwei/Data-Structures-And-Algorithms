# 7. 整数反转 处理溢出
# link：https://leetcode-cn.com/problems/reverse-integer/

# @param {Integer} x
# @return {Integer}
def reverse(x)
  result = 0
  negative = (x < 0)
  x = x.abs
  while x > 0
    result *= 10
    if result > ((1 << 31) - (negative ? 0 : 1)) - x % 10
      return 0
    end
    result += x % 10
    x /= 10
  end
  negative ? -result : result
end
