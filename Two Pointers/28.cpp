// 28. Find the Index of the First Occurrence in a String
// Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

 class Solution {
public:
    int strStr(string haystack, string needle) {
        int size=needle.size();
        if(haystack.size()<needle.size())return -1;
        for(int i=0;i<=haystack.size()-size;i++){
            string s=haystack.substr(i,size);
            if(s==needle)return i;
        }
        return -1;
    }
};