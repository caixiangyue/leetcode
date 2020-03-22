// Author: Xiangyue Cai
// Date: 2020-03-22
 
// Given an array of integers A, a move consists of choosing any A[i], and incrementing it by 1.

// Return the least number of moves to make every value in A unique.

//  

// Example 1:

// Input: [1,2,2]
// Output: 1
// Explanation:  After 1 move, the array could be [1, 2, 3].
// Example 2:

// Input: [3,2,1,2,1,7]
// Output: 6
// Explanation:  After 6 moves, the array could be [3, 4, 1, 2, 5, 7].
// It can be shown with 5 or less moves that it is impossible for the array to have all unique values.


func minIncrementForUnique(A []int) int {
    if len(A) <= 1 {
        return 0
    }
    sort.Ints(A)
    move := 0

    n1 := A[0]
    for i := 1 ; i < len(A) ; i++ {
        if (A[i] > n1) {
            n1 = A[i]
        } else {
            move += (n1 - A[i] + 1)
            n1++
        }
    }
    return move
}