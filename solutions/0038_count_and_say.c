/**
 * Author: Xiangyue Cai
 * Date: 2019-09-11
 */

// runtime: 0ms
// memory usage: 7.1mb
char*
countAndSay(int n){
    if (n == 1) return "1";
    char res[10000] = {"1"};
    int i = 1;
    for(; i < n ; ++i) {
        char tmp[10000] = {""};
        int repeat_count = 1;
        int j = 0;
        int index = 0;
        for (; j < strlen(res) ; ++j) {
            if (j + 1 < strlen(res) && res[j] == res[j + 1])
                ++repeat_count;
            else {
                tmp[index++] = repeat_count + '0';
                tmp[index++] = res[j];
                repeat_count = 1;
            }     
        }
        strcpy(res, tmp);
    }
    return strdup(res);
}