/**
 * Author: Lanqing Ye
 * Date: 2019-09-25
 */
 
/* 
Example 1:
nums1 = [1, 3]
nums2 = [2]

The median is 2.0


Example 2:
nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5

*/ 

// Fun One: Merge Sort O(max(m,n)) O(m+n)
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int sum = n + m;
        int coNum[sum];
        int n1=0,n2=0,n3=0;
        while(n1<n || n2<m){
            if(n1<n && n2<m){
                if(nums1[n1]<nums2[n2]){
                    coNum[n3++] = nums1[n1++];
                }else{
                    coNum[n3++] = nums2[n2++];
                }
            }else if(n1<n && n2>=m){
                coNum[n3++] = nums1[n1++];
            }else{
                coNum[n3++] = nums2[n2++];
            }
        }
        if(sum%2==0){
            return (coNum[sum/2-1]+coNum[sum/2])/2.0;
        }else{
            return coNum[sum/2];
        }
    }
};

// Fun Two: find k  O(log(m+n) O(1)
class Solution {
public:
    
    double getKth(vector<int>& nums1,int start1,int end1,vector<int>& nums2,int start2,int end2,int k){
        int len1 = end1 - start1 +1;
        int len2 = end2 - start2 +1;
        if(len1>len2) return getKth(nums2,start2,end2,nums1,start1,end1,k);
        if(len1==0) return nums2[start2+k-1];
        
        if(k==1) return min(nums1[start1],nums2[start2]);
        
        int i = start1+min(len1,k/2)-1;
        int j = start2+min(len2,k/2)-1;
        
        if(nums1[i]<nums2[j]) return getKth(nums1,i+1,end1,nums2,start2,end2,k-(i-start1+1));
        else return getKth(nums1,start1,end1,nums2,j+1,end2,k-(j-start2+1));
        
    }
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int left = (n+m+1)/2;
        int right = (n+m+2)/2;
        return (getKth(nums1,0,n-1,nums2,0,m-1,left)+getKth(nums1,0,n-1,nums2,0,m-1,right))*0.5 ;
    }
};