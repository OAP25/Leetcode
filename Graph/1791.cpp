// 1791. Find Center of Star Graph
// There is an undirected star graph consisting of n nodes labeled from 1 to n. A star graph is a graph where there is one center node and exactly n - 1 edges that connect the center node with every other node.

// You are given a 2D integer array edges where each edges[i] = [ui, vi] indicates that there is an edge between the nodes ui and vi. Return the center of the given star graph.


class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n=-1;
        for(int i=0;i<edges.size();i++){
            n=max({n,edges[i][0],edges[i][1]});
        }
        vector<vector<int>>adj(n);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]-1].push_back(edges[i][1]-1);
            adj[edges[i][1]-1].push_back(edges[i][0]-1);
        }
        for(int i=0;i<n;i++){
            if(adj[i].size()==n-1)return i+1;
        }
        return -1;
    }
};