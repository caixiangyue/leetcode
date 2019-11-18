/**
 * Author: Lanqing Ye
 * Date: 2019-08-28
 */
/* 
Example:
	
Input: 38
Output: 2 
Explanation: The process is like: 3 + 8 = 11, 1 + 1 = 2. 
             Since 2 has only one digit, return it.
*/ 

class Solution {
public:
    int addDigits(int num) {
        if(num<10)	return num;
        vector<int> v;
        while(num){
        	v.push_back(num%10);
        	num = num /10;
        }
        int sum=0;
        for(int i:v){
        	sum+=i;
        }
        if(sum<10) return sum;
        else{
        	return addDigits(sum);
        }
    }
};

