/**
 * Author: Xiangyue Cai
 * Date: 2019-09-25
 */

// Example 1:

// Input: a = "11", b = "1"
// Output: "100"
// Example 2:

// Input: a = "1010", b = "1011"
// Output: "10101"

// runtime: 0ms beats 100%
// memory usage: 7mb beats 75%
char*
addBinary(char * a, char * b){
    int a_len = strlen(a) - 1;
    int b_len = strlen(b) - 1;
    
    int r_len = (a_len > b_len? a_len : b_len) + 3;
    char *res = malloc(r_len);
    res[--r_len] = '\0';
    int carry = 0;
    while (a_len > -1 || b_len > -1) {
        char ch_a = a_len > -1 ? a[a_len--] : '0';
        char ch_b = b_len > -1 ? b[b_len--] : '0';
        if (ch_a == '1' && ch_b == '1' && carry == 0) {
            carry = 1;
            res[--r_len] = '0';
        }
        else if (((ch_a == '1' && ch_b == '0') || (ch_a == '0' && ch_b == '1')) && carry == 0 ) {
            carry = 0;
            res[--r_len] = '1';
        }
        else if (ch_a == '0' && ch_b == '0' && carry == 0) {
            carry = 0;
            res[--r_len] = '0';
        }
        else if (ch_a == '1' && ch_b == '1' && carry == 1) {
            carry = 1;
            res[--r_len] = '1';
        }
        else if (((ch_a == '1' && ch_b == '0') || (ch_a == '0' && ch_b == '1')) && carry == 1 ) {
            carry = 1;
            res[--r_len] = '0';
        }
        else if (ch_a == '0' && ch_b == '0' && carry == 1) {
            carry = 0;
            res[--r_len] = '1';
        }
    }
    if (carry) res[--r_len] = '1';
    else return res+1;
    return res;
}