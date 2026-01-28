// 125. Valid Palindrome
// A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

// Given a string s, return true if it is a palindrome, or false otherwise.

class Solution {
public:
    bool isPalindrome(string s) {
        string st="";
        for(char c:s){
            if(c>='A' && c<='Z'){
                st+=c-'A'+'a';
            }else if((c>='a' && c<='z') || (c>='0' && c<='9') ){
                st+=c;
            }
        }
        int i=0,j=st.length()-1;
        while(i<j){
            if(st[i]!=st[j])return false;
            i++;
            j--;
        }
        return true;
    }
};