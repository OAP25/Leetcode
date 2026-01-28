// 977. Squares of a Sorted Array

// Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n);
        int k=n-1;
        int i=0,j=nums.size()-1;
        while(k>=0){
            int sqi=nums[i]*nums[i];
            int sqj=nums[j]*nums[j];
           ans[k]=max(sqi,sqj);
           if(sqi>sqj)i++;
           else{j--;}
           k--;
        }
        return ans;
    }
};