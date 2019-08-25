/**
 * Author: Lanqing Ye
 * Date: 2019-08-25
 */
/* 
Input: 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.

*/ 

int countPrimes(int n){
    if(n<=2) return 0;
    int num = 0;
    int i,j;
    for(i = 2;i<n;i++){
        int tmp=(int)sqrt(i);
        for(j=2;j<=tmp;j++){
            if(i%j==0)
                break;
        }
        if(j>tmp) num++;
    }
    return num;
}

