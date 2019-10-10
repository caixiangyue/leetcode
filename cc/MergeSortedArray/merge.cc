/**
 * Author: Xiangyue Cai
 * Date: 2019-10-10
 */

// Input:
// nums1 = [1,2,3,0,0,0], m = 3
// nums2 = [2,5,6],       n = 3

// Output: [1,2,2,3,5,6]

// runtime: 4ms beats 84.17%
// memory usage: 8.6mb beats 97.83%
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int index = m + n - 1;
        while(m > 0 && n > 0) {
            if (nums2[n - 1] > nums1[m - 1]){
                nums1[index--] = nums2[n - 1];
                --n;
            }
            else {
                nums1[index--] = nums1[m - 1];
                --m;
            }
        }
        while (n > 0)
            nums1[index--] = nums2[--n];
    }
};
