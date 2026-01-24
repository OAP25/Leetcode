// 997. Find the Town Judge
// In a town, there are n people labeled from 1 to n. There is a rumor that one of these people is secretly the town judge.

// If the town judge exists, then:

// The town judge trusts nobody.
// Everybody (except for the town judge) trusts the town judge.
// There is exactly one person that satisfies properties 1 and 2.
// You are given an array trust where trust[i] = [ai, bi] representing that the person labeled ai trusts the person labeled bi. If a trust relationship does not exist in trust array, then such a trust relationship does not exist.

// Return the label of the town judge if the town judge exists and can be identified, or return -1 otherwise.

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<vector<int>>inc(n);
        vector<vector<int>>out(n);
        for(int i=0;i<trust.size();i++){
            inc[trust[i][1]-1].push_back(trust[i][0]-1);
            out[trust[i][0]-1].push_back(trust[i][1]-1);
        }

        for(int i=0;i<n;i++){
            if(inc[i].size()==n-1 && out[i].size()==0){
                return i+1;
            }
        }
        return -1;
    }
};