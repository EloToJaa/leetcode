# Category: algorithms
# Level: Medium
# Percent: 44.407974%



# Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.
# 
# Note: You must not use any built-in BigInteger library or convert the inputs to integer directly.
# 
#  
# Example 1:
# Input: num1 = "2", num2 = "3"
# Output: "6"
# Example 2:
# Input: num1 = "123", num2 = "456"
# Output: "56088"
# 
#  
# Constraints:
# 
# 
# 	1 <= num1.length, num2.length <= 200
# 	num1 and num2 consist of digits only.
# 	Both num1 and num2 do not contain any leading zero, except the number 0 itself.
# 
 

class Solution:
    def sum(self, num1, num2):
        carry = 0
        res = []
        num1 = num1[::-1]
        num2 = num2[::-1]
        for i in range(max(len(num1), len(num2))):
            a = int(num1[i]) if i < len(num1) else 0
            b = int(num2[i]) if i < len(num2) else 0
            sum = a + b + carry
            carry = sum // 10
            res.append(str(sum % 10))
            
        if carry > 0:
            res.append(str(carry))
        ans = res[::-1]
        for i in range(len(ans)):
            if i != '0':
                ans = ans[i:]
                break
        if ans.count('0') == len(ans):
            return '0'
        return ''.join(ans)

    
    def multiply(self, num1: str, num2: str) -> str:
        carry = 0
        res = []
        ans = "0"
        num1 = num1[::-1]
        num2 = num2[::-1]
        for i in range(len(num2)):
            b = int(num2[i])
            carry = 0
            res = ['0'] * i
            for j in range(len(num1)):
                a = int(num1[j])
                sum = a * b + carry
                carry = sum // 10
                res.append(str(sum % 10))
            if carry > 0:
                res.append(str(carry))
            c = "".join(res[::-1])
            ans = self.sum(ans, c)
            
        return ans
