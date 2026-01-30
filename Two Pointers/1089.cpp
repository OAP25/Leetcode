// 1089. Duplicate Zeros
// Given a fixed-length integer array arr, duplicate each occurrence of zero, shifting the remaining elements to the right.

// Note that elements beyond the length of the original array are not written. Do the above modifications to the input array in place and do not return anything.

class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int i=0;
        while(i<arr.size()){
            if(arr[i]==0){
               int j=arr.size()-1;
               while(j>i){
                arr[j]=arr[j-1];
                j--;
               }
               if(i<arr.size()-1){
               arr[i+1]=0;
               i++;
               }
            }
            i++;
        }
    }
};