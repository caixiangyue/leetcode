use std::collections::HashMap;

// Author: Xiangyue Cai
// Date: 2020-03-27
// O(n)
impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let mut map = HashMap::new();
        for (k, v) in nums.iter().enumerate() {
            let tmp = target - v;
            if map.contains_key(&tmp) {
                return vec![*map.get(&tmp).unwrap(), k as i32];
            }
            map.insert(v, k as i32);
        }
        return vec![];
    }
}