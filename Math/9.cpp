// 9. Palindrome Number
// Given an integer x, return true if x is a palindrome, and false otherwise.

class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0){
            return false;
        }
        int check=x;
        long ans=0;
        
        while(x!=0){
            int digit=x%10;
            ans=ans*10+digit;
            
            x=x/10;
        }
        return check==ans;

    }
};