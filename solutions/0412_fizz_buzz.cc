/** 
 * Author: Lanqing Ye
 * Date: 2019-09-01 
 */
/*
 
Example:

n = 15,

Return:
[
    "1",
    "2",
    "Fizz",
    "4",
    "Buzz",
    "Fizz",
    "7",
    "8",
    "Fizz",
    "Buzz",
    "11",
    "Fizz",
    "13",
    "14",
    "FizzBuzz"
]

*/

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        
        vector<string> vec;
        for(int i=1;i<=n;i++){
            if(i%15==0 )    vec.push_back("FizzBuzz");
            else if(i%3==0) vec.push_back("Fizz");
            else if(i%5==0) vec.push_back("Buzz");
            else    vec.push_back(to_string(i));
        }
        return vec;
    }
}; 
