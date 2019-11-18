/**
 * Author: Xiangyue Cai
 * Date: 2019-08-30
 */

double
findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int sum = nums1Size + nums2Size;
    int nums[sum];
    
    int n1 = 0;
    int n2 = 0;
    int i = 0;
    while (n1 < nums1Size || n2 < nums2Size) {
        if (n1 < nums1Size && n2 < nums2Size) {
            if (nums1[n1] < nums2[n2])
                nums[i++] = nums1[n1++];
            else
                nums[i++] = nums2[n2++];
        }
        else if (n1 < nums1Size && !(n2 < nums2Size))
            nums[i++] = nums1[n1++];
        else if (!(n1 < nums1Size) && n2 < nums2Size)
            nums[i++] = nums2[n2++];
    }
    
    if (sum % 2 == 0)
        return (nums[sum / 2 - 1] + nums[sum / 2]) / 2.0;
    return nums[sum / 2];
}