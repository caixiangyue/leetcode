/**
 * Author: Xiangyue Cai
 * Date: 2019-09-04
 */

// runtime: 1280ms
// memory usage: 9.7mb
class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_area = 0;
        int size = height.size();
        for(int i = 0 ; i < size; ++i){
            for(int j = i + 1; j < size; ++j) {
                int h = min(height[i], height[j]);
                int area = h * (j - i);
                max_area = area > max_area? area : max_area;
            }
        }
        return max_area;
    }
};

// runtime: 12ms
// memory usage: 9.8mb
class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_area = 0;
        int l = 0;
        int r = height.size() - 1;
        
        while (l < r) {
            max_area = max(max_area, min(height[l], height[r]) * (r - l));
            
            if (height[l] < height[r])
                ++l;
            else
                --r;
        }
        return max_area;
    }
};