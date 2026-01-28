// 345. Reverse Vowels of a String
// Given a string s, reverse only all the vowels in the string and return it.

// The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower and upper cases, more than once.

class Solution {
public:
    string reverseVowels(string s) {
        vector<bool>check(s.length(),false);
        string vowels="";
        for(int i=0;i<s.length();i++){
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' || s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' ||
            s[i]=='U' ){
                vowels+=s[i];
                check[i]=true;
            }
        }
        reverse(vowels.begin(),vowels.end());
        int j=0;
        for(int i=0;i<s.length();i++){
            if(check[i]){
                s[i]=vowels[j];
                j++;
            }
        }
        return s;
    }
};