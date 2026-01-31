// 744. Find Smallest Letter Greater Than Target

// You are given an array of characters letters that is sorted in non-decreasing order, and a character target. There are at least two different characters in letters.

// Return the smallest character in letters that is lexicographically greater than target. If such a character does not exist, return the first character in letters.

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char ans='0';

        int low=0,high=letters.size()-1;

        while(low<=high){
            int mid=low+(high-low)/2;

            if(letters[mid]>target){
                ans=letters[mid];
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans=='0'?letters[0]:ans;
    }
};