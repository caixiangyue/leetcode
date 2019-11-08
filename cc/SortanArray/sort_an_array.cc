/**
 * Author: Lanqing Ye
 * Date: 2019-11-06
 */
 
/* 

Example 1:

Input: nums = [5,2,3,1]
Output: [1,2,3,5]


Example 2:

Input: nums = [5,1,1,2,0,0]
Output: [0,0,1,1,2,5]

*/ 


//Bubble Sort O(n^2) O(1) TML
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        bool hasChange = true;
        for(int i = 0; i < nums.size() - 1 && hasChange; i ++){
            hasChange = false;
            for(int j = 0; j < nums.size() - 1 - i; j ++){
                if(nums[j] > nums[j + 1]){
                    swap(nums[j], nums[j + 1]);
                    hasChange = true;
                }
            }
        }
        return nums;
    }
};

//Insert sort O(n^2) O(1) TML
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        for(int i = 1, current, j; i < nums.size(); i ++){
            current = nums[i];
            for(j = i - 1; j >= 0 && nums[j] > current; j --){
                nums[j + 1] = nums[j];
            }
            nums[j + 1] = current;
        }
        return nums;
    }
};

// MergeSort O(nlogn) O(n) 
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        sort(nums, 0, nums.size() - 1);
        return nums;
    }
    
    void sort(vector<int>& nums, int l, int r){
        if(l >= r)  return;
        int mid = (l + r) / 2;
        sort(nums, l , mid);
        sort(nums, mid + 1, r);
        merge(nums, l, mid, r);
    }
    
    void merge(vector<int>& nums, int l, int mid, int r){
        int copy[r - l + 1];
        int k = 0, i = l, j = mid + 1;
        while(i <= mid && j <= r)
            if(nums[i] <= nums[j])  copy[k++] = nums[i++];
            else    copy[k++] = nums[j++];
        while(i <= mid) copy[k++] = nums[i++];
        while(j <= mid) copy[k++] = nums[j++];
        for(int n = 0; n < k; n ++) nums[l + n] = copy[n];
        return ;
    }
    
};

// Quick Sort  O(n^2)~O(nlogn) O(logn)
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        sort(nums, 0, nums.size() - 1);
        return nums;
    }
    
    void sort(vector<int>& nums, int l, int r){
        if(l >= r)  return;
        int p = partition(nums, l, r);
        sort(nums, l, p - 1);
        sort(nums, p + 1, r);
    }
    
    int partition(vector<int>& nums, int l, int r){
        int randNum = l + rand() % (r - l + 1);
        swap(nums[randNum], nums[r]);
        int i,j;
        for(i = l, j = l; j < r; j ++)
            if(nums[j] < nums[r])
                swap(nums[i++], nums[j]);
        swap(nums[i], nums[r]);
        return i;
    }
    
};

// Heap Sort 
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        heapSort(nums, nums.size());
        return nums;
    }
    
    void heapify(vector<int>& nums, int n, int i){
        if(i >= n)  return;
        int c1 = 2 * i + 1;
        int c2 = 2 * i + 2;
        int max = i;
        if(c1 < n && nums[c1] > nums[max])  max = c1;
        if(c2 < n && nums[c2] > nums[max])  max = c2;
        if(max != i){
            swap(nums[i], nums[max]);
            heapify(nums, n, max);
        }
    }
    
    void buildHeap(vector<int>& nums, int n){
        int lastNode = n - 1;
        int parent = (lastNode - 1) / 2;
        for(int i = parent; i >= 0; i --){
            heapify(nums, n, i);
        }
    }
    
    void heapSort(vector<int>& nums, int n){
        buildHeap(nums, n);
        for(int i = n - 1; i >= 0; i --){
            swap(nums[i], nums[0]);
            heapify(nums, i, 0);
        }
    }
    
};

// Bucket Sort
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        return bucketSort(nums);
    }
    
    vector<int> bucketSort(vector<int>& nums) {
        if (nums.empty()) return {};
        int low = *min_element(nums.begin(), nums.end());
        int high = *max_element(nums.begin(), nums.end());
        int n = high - low + 1;
        vector<int> buckets(n);
        for (auto x : nums) ++buckets[x - low];
        vector<int> res;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < buckets[i]; ++j) {
                res.push_back(i + low);
            }
        }
        return res;
    }
    
};
