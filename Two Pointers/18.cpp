// 18. 4Sum
// Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

// 0 <= a, b, c, d < n
// a, b, c, and d are distinct.
// nums[a] + nums[b] + nums[c] + nums[d] == target
// You may return the answer in any order.

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if(nums.size()<4){
            return  {};
        }
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        for(int i=0;i<nums.size()-3;i++){
              
            if(i>0 && nums[i]==nums[i-1]){continue;}

             for(int j=i+1;j<nums.size()-2;j++){
                if(j>i+1 && nums[j]==nums[j-1]){continue;}
                int k=j+1,m=nums.size()-1;
                while(k<m){
                    long long sum=static_cast<long long>(nums[i])+nums[j]+nums[k]+nums[m];
                    if(sum==target){
                        vector<int>v;
                        v.push_back(nums[i]);
                        v.push_back(nums[j]);
                        v.push_back(nums[k]);
                        v.push_back(nums[m]);
                        ans.push_back(v);

                        while(k<m && nums[k]==nums[k+1]){k++;}
                        while(k<m && nums[m]==nums[m-1]){m--;}
                        k++;
                        m--;
                    }
                    else if(sum>target){
                        m--;
                    }
                    else if(sum<target){
                        k++;
                    }
                }
        }
        }
        return ans;
    }
};