// 7. Reverse Integer
// Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

// Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

class Solution {
public:
    int reverse(int x) {
        long ans=0;
        long count=0;
        long copy=x;
        while(copy!=0){
            copy=copy/10;
            count++;
        }
        while(x!=0 && count>=0){
          int digit=x%10;
          ans=ans+digit*pow(10,count-1);
          count--;
          x=x/10;
        }
        if(ans>pow(2,31)-1 || ans<pow(-2,31)){
            return 0;
        }
        return ans;
    }
};