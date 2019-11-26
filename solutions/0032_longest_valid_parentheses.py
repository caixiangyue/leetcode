# Author: Xiangyue Cai
# Date: 2019-11-26

"""
Example 1:

Input: "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()"
Example 2:

Input: ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()"
"""

# runtime: 40ms beats 96.22%
# memory usage: 13.4mb beats 61.11%
class Solution:
    def longestValidParentheses(self, s: str) -> int:
        res = 0
        last = -1
        stack = []
        if s is None or len(s) < 2:
            return res
        
        for i in range(len(s)):
            if s[i] == '(':
                stack.append(i)
            else:
                if stack == []:
                    last = i
                else:
                    stack.pop()
                    if stack == []:
                        res = max(res, i - last)
                    else:
                        res = max(res, i - stack[-1])
        return res
