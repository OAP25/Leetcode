// 905. Sort Array By Parity
// Given an integer array nums, move all the even integers at the beginning of the array followed by all the odd integers.

// Return any array that satisfies this condition.

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<bool>check(nums.size(),false);
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0)check[i]=true;
        }
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            if(check[i])ans.push_back(nums[i]);
        }
        for(int i=0;i<nums.size();i++){
            if(!check[i])ans.push_back(nums[i]);
        }
        return ans;
    }
};