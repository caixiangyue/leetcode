/**
 * Author: Lanqing Ye
 * Date: 2019-10-15
 */
 
/* 
Example:

Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
Explanation: The sum of 2 and 7 is 9. Therefore index1 = 1, index2 = 2.


*/ 

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0 , j = numbers.size() - 1;
        int sum;
        while(i < j){
            sum = numbers[i] + numbers[j];
            if(sum == target){
                return {i+1,j+1};
            }else if(sum < target){
                i++;
            }else{
                j--;
            }
        } 
        return {-1,-1};
    }
};

