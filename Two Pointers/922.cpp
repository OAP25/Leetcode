// 922. Sort Array By Parity II
// Given an array of integers nums, half of the integers in nums are odd, and the other half are even.

// Sort the array so that whenever nums[i] is odd, i is odd, and whenever nums[i] is even, i is even.

// Return any answer array that satisfies this condition.


class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        priority_queue<int,vector<int>,greater<int>>pqe;
        priority_queue<int,vector<int>,greater<int>>pqo;
        for(int i:nums){
            if(i%2==0){pqe.push(i);}
            else{pqo.push(i);}
        }
        
        vector<int>ans;
        while(!pqe.empty() && !pqo.empty()){
            ans.push_back(pqe.top());
            pqe.pop();
            ans.push_back(pqo.top());
            pqo.pop();
        }
        return ans;
    }
};