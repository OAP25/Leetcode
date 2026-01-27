// 743. Network Delay Time
// You are given a network of n nodes, labeled from 1 to n. You are also given times, a list of travel times as directed edges times[i] = (ui, vi, wi), where ui is the source node, vi is the target node, and wi is the time it takes for a signal to travel from source to target.

// We will send a signal from a given node k. Return the minimum time it takes for all the n nodes to receive the signal. If it is impossible for all the n nodes to receive the signal, return -1.

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(int i=0;i<times.size();i++){
            int u=times[i][0]-1;
            int v=times[i][1]-1;
            int wt=times[i][2];

            adj[u].push_back({v,wt});
        }

        vector<int>dist(n,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        dist[k-1]=0;
        pq.push({0,k-1});

        while(!pq.empty()){
            auto [wt,node]=pq.top();
            pq.pop();

            for(auto &p:adj[node]){
                int currwt=p.second;
                int nbr=p.first;
                if(wt+currwt<dist[nbr]){
                    dist[nbr]=wt+currwt;
                    pq.push({dist[nbr],nbr});
                }
            }
        }
        
        int ans=*max_element(dist.begin(),dist.end());
        return ans==INT_MAX?-1:ans;
    }
};