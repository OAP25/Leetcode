// 1976. Number of Ways to Arrive at Destination
// You are in a city that consists of n intersections numbered from 0 to n - 1 with bi-directional roads between some intersections. The inputs are generated such that you can reach any intersection from any other intersection and that there is at most one road between any two intersections.

// You are given an integer n and a 2D integer array roads where roads[i] = [ui, vi, timei] means that there is a road between intersections ui and vi that takes timei minutes to travel. You want to know in how many ways you can travel from intersection 0 to intersection n - 1 in the shortest amount of time.

// Return the number of ways you can arrive at your destination in the shortest amount of time. Since the answer may be large, return it modulo 109 + 7.

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int mod=1000000007;
        vector<vector<pair<int,int>>>adj(n);
        for(int i=0;i<roads.size();i++){
            int u=roads[i][0];
            int v=roads[i][1];
            int wt=roads[i][2];

            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }

        vector<long long>dist(n,LLONG_MAX);
        vector<int>paths(n,0);

        dist[0]=0;
        paths[0]=1;
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq;
        pq.push({0,0});

        while(!pq.empty()){
            auto [wt,node]=pq.top();
            pq.pop();

            for(auto &p:adj[node]){
                long long currwt=p.second;
                int nbr=p.first;
                if (wt > dist[node]) continue; 
                if(wt+currwt<dist[nbr]){
                    dist[nbr]=(currwt+wt);
                    paths[nbr]=(paths[node]);
                    pq.push({dist[nbr],nbr});
                }else if(wt+currwt==dist[nbr]){
                    paths[nbr]=(paths[nbr]+paths[node])%mod;
                }
            }
            }
        return paths[n-1];
 
    }
};