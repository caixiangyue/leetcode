/**
 * Author: Xiangyue Cai
 * Date: 2019-10-20
 */

// runtime: 12ms
// memory usage: 10.2mb
class Solution {
public:
    // y = ax + b
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        if (coordinates.size() == 2) return true;
        float y = coordinates[1][1] - coordinates[0][1];
        float ax = coordinates[1][0] - coordinates[0][0];
        float a = y / ax;
        float b = coordinates[0][1] - a * coordinates[0][0];
        
        for (int i = 2 ; i < coordinates.size() ; i++) {
            if (coordinates[i][1] != int(a * coordinates[i][0] + b))
                return false;
        }
        return true;
    }
};