static void
swap(int *nums, int i, int j) {
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}

static int
sort(int *nums, int l, int r) {
    int pivot = nums[r];
    int n = l;
    for (int i = l; i < r; ++i) {
        if (nums[i] < pivot) {
            swap(nums, i, n);
            ++n;
        }
    }
    swap(nums, r, n);
    return n;
}

static void
quickSort(int *nums, int l, int r) {
    if (l < r) {
        int mid = sort(nums,l,r);
        quickSort(nums, l, mid - 1);
        quickSort(nums, mid + 1, r);
    }
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArray(int* nums, int numsSize, int* returnSize){
    *returnSize = numsSize;
    int *res = malloc(sizeof(int) * (*returnSize));
    if (numsSize > 0)
        quickSort(nums, 0, numsSize-1);
    return nums;
}