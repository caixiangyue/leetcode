/**
 * Author: Lanqing Ye
 * Date: 2019-10-16
**/

//Fun One 
class Solution {
public:
    int maxProductAfterCutting(int length) {
        if(length == 2) return 1;
        if(length == 3) return 2;
        if(length == 4) return 4;
        return dfs(length);
    }
    
    int dfs(int length){
        if(length == 2) return 2;
        if(length == 3) return 3;
        if(length == 4) return 4;
        while(length > 4){
            return 3 * dfs(length - 3);
        }
    }
    
};

