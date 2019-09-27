/**
 * Author: Lanqing Ye
 * Date: 2019-09-27
**/
 
class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> vec;
        
        
        if( m == 0 || n == 0 ) return vec;
        
        int left = 0 , right = n - 1 , top = 0 , bottom = m - 1;
        while( left <= right && top <= bottom){
            
            for(int i = left ; i <= right ; i++)    vec.emplace_back(matrix[top][i]);
            for(int i = top+1 ; i <= bottom ; i++)    vec.emplace_back(matrix[i][right]);
            if(top < bottom)
                for(int i = right - 1 ; i >= left ; i--)    vec.emplace_back(matrix[bottom][i]);
            if(left < right)
                for(int i = bottom - 1 ; i > top ; i--)    vec.emplace_back(matrix[i][left]);
            left++ ;
            right-- ;
            top++;
            bottom--;
        }
        return vec;
    }
};