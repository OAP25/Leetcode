// 1346. Check If N and Its Double Exist
// Given an array arr of integers, check if there exist two indices i and j such that :

// i != j
// 0 <= i, j < arr.length
// arr[i] == 2 * arr[j]

class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> s;
        for(int i:arr){
            if(s.find(2*i)!=s.end() || (i%2==0 && s.find(i/2)!=s.end())){
                return true;
            }
            s.insert(i);
        }
        return false;
    }
};