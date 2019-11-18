/**
 * Author: Xiangyue Cai
 * Date: 2019-09-24
 */

// runtime: 0ms
// memory usage: 7.2mb
int
strStr(char * haystack, char * needle){
    if (!needle || needle[0] == '\0') return 0;
    if (!haystack || haystack[0] == '\0') return -1;

    int n_len = strlen(needle);
    int h_len = strlen(haystack);
    for (int i = 0 ; haystack[i] != '\0' && i <= (h_len - n_len) ; ++i) {
        for (int j = 0; needle[j] != '\0' ; ++j) {
            if (haystack[i + j] != needle[j])
                break;
            if (needle[j + 1] == '\0') return i;
        }
    }
    return -1;
}