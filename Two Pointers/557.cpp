// 557. Reverse Words in a String III
// Given a string s, reverse the order of characters in each word within a sentence while
//  still preserving whitespace and initial word order.

 class Solution {
private:
    void reverse(string &s){
        int i=0,j=s.size()-1;
        while(i<=j){
            swap(s[i],s[j]);
            i++;
            j--;
        }
    }
public:
    string reverseWords(string s) {
        string ans;
        istringstream ns(s);
        string word;
        while(ns>>word){
            reverse(word);
            ans=ans+word+" ";
        }
        ans.erase(ans.end()-1,ans.end());
        return ans;
    }
};