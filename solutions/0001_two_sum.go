/**
 * Author: Xiangyue Cai
 * Date: 2020-03-20
 */


func twoSum(nums []int, target int) []int {
    tmp := make(map[int]int)
    for k, v := range nums {
     	if j, exists := tmp[target - v]; exists {
	    	return []int{j, k}
	 	}
	tmp[v] = k
    }
    return nil
}
