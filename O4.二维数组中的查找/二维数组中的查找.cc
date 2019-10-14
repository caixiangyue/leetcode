/**
 * Author: Lanqing Ye
 * Date: 2019-10-09
 */
 
class Solution {
public:
    bool searchArray(vector<vector<int>> array, int target) {
        if(array.empty() || array[0].empty())
            return false;
        int m = array.size();
        int n = array[0].size();
        int i = 0 , j = n - 1;
        while( i < m && j >= 0){
            if(array[i][j] == target)
                return true;
            else if(array[i][j] > target){
                j--;
            }else{
                i++;
            }
        }
        return false;
    }
};
