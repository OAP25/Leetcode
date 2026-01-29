// 2976. Minimum Cost to Convert String I
// You are given two 0-indexed strings source and target, both of length n and consisting of lowercase English letters. You are also given two 0-indexed character arrays original and changed, and an integer array cost, where cost[i] represents the cost of changing the character original[i] to the character changed[i].

// You start with the string source. In one operation, you can pick a character x from the string and change it to the character y at a cost of z if there exists any index j such that cost[j] == z, original[j] == x, and changed[j] == y.

// Return the minimum cost to convert the string source to the string target using any number of operations. If it is impossible to convert source to target, return -1.

// Note that there may exist indices i, j such that original[j] == original[i] and changed[j] == changed[i].

 class Solution {
public:
    vector<long long> dijikstra(unordered_map<char,vector<pair<char,int>>>&adj,char src){
       
        vector<long long>dist(26,LLONG_MAX);
        dist[src-'a']=0;
        priority_queue<pair<long long, char>,vector<pair<long long, char>>,greater<pair<long long, char>>>pq;
        pq.push({0,src});

        while(!pq.empty()){
            auto [wt,node]=pq.top();
            pq.pop();

            if(wt>dist[node-'a'])continue;

            for(auto &p:adj[node]){
                char nbr=p.first;
                int currwt=p.second;

                if(currwt+wt<dist[nbr-'a']){
                    dist[nbr-'a']=currwt+wt;
                    pq.push({dist[nbr-'a'],nbr});
                }
            }
        }
        
        return dist;

    }
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        unordered_map<char,vector<pair<char,int>>>adj;
        for(int i=0;i<original.size();i++){
            char u=original[i];
            char v=changed[i];

            int wt=cost[i];

            adj[u].push_back({v,wt});
        }
       vector<vector<long long>>shortest(26,vector<long long>(26,LLONG_MAX));
       for(int i=0;i<26;i++){
        char ch='a'+i;
            shortest[i]=dijikstra(adj,ch);
       }
       long long ans=0;
       for(int i=0;i<source.size();i++){
        long long val=shortest[source[i]-'a'][target[i]-'a'];
        if(val==LLONG_MAX)return -1;
        ans+=val;
       }
        return ans;
    }
};