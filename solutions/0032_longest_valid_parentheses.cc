/**
 * Author: Xiangyue Cai
 * Date: 2019-11-27
 */

// Example 1:

// Input: "(()"
// Output: 2
// Explanation: The longest valid parentheses substring is "()"
// Example 2:

// Input: ")()())"
// Output: 4
// Explanation: The longest valid parentheses substring is "()()"

// runtime 4ms
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1);
        int max_len = 0;
        for (int i = 0 ; i < s.length() ; i++) {
            if (s[i] == '(') {
                st.push(i);
            } else if (s[i] == ')') {
                st.pop();
                if (st.empty())
                    st.push(i);
                max_len = max(max_len, i - st.top());
            }
        }
        return max_len;
    }
};