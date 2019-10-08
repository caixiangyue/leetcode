/**
 * Author: Xiangyue Cai
 * Date: 2019-10-8
 */

// Example 1:

// Input: [1,2,3]
// Output: [1,2,4]
// Explanation: The array represents the integer 123.
// Example 2:

// Input: [4,3,2,1]
// Output: [4,3,2,2]
// Explanation: The array represents the integer 4321.

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

// runtime: 0ms
// memory usage: 7.2mb
int*
plusOne(int* digits, int digitsSize, int* returnSize)
{
    *returnSize = digitsSize + 1;
    int *res = malloc(sizeof(int) * (*returnSize));
    int carry = 0;
    res[digitsSize] = (digits[digitsSize - 1] + 1 + carry) % 10;
    carry = (digits[digitsSize - 1] + 1 + carry) / 10;
    for (int i = digitsSize - 2 ; i > -1 ; --i) {
        res[i + 1] = (digits[i]  + carry) % 10;
        carry = (digits[i] + carry) / 10;
    }
    if (carry) {
        res[0] = 1;
        return res;
    }
    --(*returnSize);
    return res + 1;
}
