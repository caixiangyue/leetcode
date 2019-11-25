/**
 * Author: Xiangyue Cai
 * Date: 2019-11-25
 */


// Example 1:

// Input: "Hello"
// Output: "hello"
// Example 2:

// Input: "here"
// Output: "here"
// Example 3:

// Input: "LOVELY"
// Output: "lovely"

// runtime 0ms
char*
toLowerCase(char * str){
    for (int i = 0 ; i < strlen(str) ; ++i) {
        if (str[i] > 64 && str[i] < 91) {
            str[i] += 32;
        }
    }
    return str;
}
