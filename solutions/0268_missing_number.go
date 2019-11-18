// Author: Xiangyue Cai
// Date: 2019-11-18
 
// Example 1:

// Input: [3,0,1]
// Output: 2
// Example 2:

// Input: [9,6,4,2,3,5,7,0,1]
// Output: 8

// runtime 16 ms beats 91.38%
// memory 5.9MB beats 100%
func missingNumber(nums []int) int {
    n := len(nums)
	var res int = n
	var sum int

	for i := 0; i < n; i++ {
		sum += nums[i]
		res += i
	}
	return res - sum
}