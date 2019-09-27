# Author: Xiangyue Cai
# Date: 2019-09-27

# For example, given n = 3, a solution set is:

# [
#   "((()))",
#   "(()())",
#   "(())()",
#   "()(())",
#   "()()()"
# ]

# runtime: 32ms beats 99%
# memory usage: 14mb beats 6.67%
class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        if n == 0: return []
        res = []
        dfs(0, 0, '', res, n)
        return res

def dfs(left, right, buffer, res, n):
        if (left == n and right == n):
            res.append(buffer)
            return
        if (left < n):
            dfs(left + 1, right, buffer + '(', res, n)
        if (left > right):
            dfs(left, right + 1, buffer + ')', res, n)
