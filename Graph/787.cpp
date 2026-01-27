// 787. Cheapest Flights Within K Stops
// There are n cities connected by some number of flights. You are given an array flights where flights[i] = [fromi, toi, pricei] indicates that there is a flight from city fromi to city toi with cost pricei.

// You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. If there is no such route, return -1.

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int,vector<pair<int,int>>>adj;
        for(auto edge:flights){
            adj[edge[0]].push_back({edge[1],edge[2]});
        }
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>minHeap;
        vector<int>dist(n,INT_MAX);
        vector<int>stops(n,INT_MAX);

        minHeap.push({0,src,0});
        stops[src]=0;
        dist[src]=0;
    

    while(!minHeap.empty()){
        auto [cost,node,stop]=minHeap.top();
        minHeap.pop();

        if(node==dst)return cost;
        if(stop>k)continue;

        for(auto neighbor:adj[node]){
            int nextDist=cost+neighbor.second;
            int nextStop=stop+1;

            if(nextDist<dist[neighbor.first] || nextStop < stops[neighbor.first]){
                 dist[neighbor.first]=nextDist;
                 stops[neighbor.first]=nextStop;
                 minHeap.push({nextDist,neighbor.first,nextStop});
            }
            
        }
    }
        return -1;
    }
};