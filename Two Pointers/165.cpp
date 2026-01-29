// 165. Compare Version Numbers
// Given two version strings, version1 and version2, compare them. A version string consists of revisions separated by dots '.'. The value of the revision is its integer conversion ignoring leading zeros.

// To compare version strings, compare their revision values in left-to-right order. If one of the version strings has fewer revisions, treat the missing revision values as 0.

// Return the following:

// If version1 < version2, return -1.
// If version1 > version2, return 1.
// Otherwise, return 0.
 
class Solution {
public:
    int compareVersion(string version1, string version2) {
        version1+='.';
        version2+='.';

        int i=0,j=0;

        while(i<version1.length() || j<version2.length()){
            string s1;
            string s2;

            while(i<version1.length() && version1[i]!='.'){
                s1+=version1[i];
                i++;
            }
            i++;

            while(j<version2.length() && version2[j]!='.'){
                s2+=version2[j];
                j++;
            }
            j++;

            int a=s1.empty()?0:stoi(s1);
            int b=s2.empty()?0:stoi(s2);

            if(a>b)return 1;
            if(a<b)return -1;
        }
        return 0;
    }
};