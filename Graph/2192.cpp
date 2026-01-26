// 2192. All Ancestors of a Node in a Directed Acyclic Graph
// You are given a positive integer n representing the number of nodes of a Directed Acyclic Graph (DAG). The nodes are numbered from 0 to n - 1 (inclusive).

// You are also given a 2D integer array edges, where edges[i] = [fromi, toi] denotes that there is a unidirectional edge from fromi to toi in the graph.

// Return a list answer, where answer[i] is the list of ancestors of the ith node, sorted in ascending order.

// A node u is an ancestor of another node v if u can reach v via a set of edges.

class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
      vector<vector<int>>adj(n);
      vector<int>indegree(n,0);
      for(int i=0;i<edges.size();i++){
        int u=edges[i][0];
        int v=edges[i][1];
        adj[u].push_back(v);
        indegree[v]++;
      }  
      queue<int>q;
      for(int i=0;i<n;i++){
        if(indegree[i]==0)q.push(i);
      }
      vector<int>topo;
      while(!q.empty()){
        int curr=q.front();
        q.pop();

        topo.push_back(curr);

        for(int i:adj[curr]){
            indegree[i]--;
            if(indegree[i]==0)q.push(i);
        }
      }
      vector<vector<int>>ans(n);
      vector<set<int>>temp(n);

      for(int i:topo){
        for(int nbr:adj[i]){
           temp[nbr].insert(i);
           for(int x:temp[i]){
            temp[nbr].insert(x);
           }
        }
      }
      for(int i=0;i<n;i++){
        vector<int>v(temp[i].begin(),temp[i].end());
        ans[i]=v;
      }
      return ans;

    }
};