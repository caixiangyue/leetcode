/**
 * Author: Xiangyue Cai
 * Date: 2019-09-02
 */

char*
longestCommonPrefix(char ** strs, int strsSize){
    if (strsSize < 1) return "";
    int len = strlen(strs[0]);
    int i = 0;
    for (; i < len ; ++i) {
        char ch = strs[0][i];
        for (int j = 1; j < strsSize; ++j) {
            if (strlen(strs[j]) <= i || strs[j][i] != ch) {
                goto OUT;
            }
        }
    }
    
OUT:    
    if (i > 0) {
        strs[0][i] = '\0';
        return strs[0];
    }  
    
    return "";
}