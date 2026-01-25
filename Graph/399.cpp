// 399. Evaluate Division
// You are given an array of variable pairs equations and an array of real numbers values, where equations[i] = [Ai, Bi] and values[i] represent the equation Ai / Bi = values[i]. Each Ai or Bi is a string that represents a single variable.

// You are also given some queries, where queries[j] = [Cj, Dj] represents the jth query where you must find the answer for Cj / Dj = ?.

// Return the answers to all queries. If a single answer cannot be determined, return -1.0.

// Note: The input is always valid. You may assume that evaluating the queries will not result in division by zero and that there is no contradiction.

// Note: The variables that do not occur in the list of equations are undefined, so the answer cannot be determined for them.

class Solution {
public:
    double dfs(string node, string dest, unordered_map<string,vector<pair<string,double>>>&adj,unordered_map<string,bool>&visited){
        if(adj.find(node)==adj.end())return -1.0;
        if(node==dest)return 1.0;
        visited[node]=true;
        

        for(auto &nbr:adj[node]){
            if(!visited[nbr.first]){
               double val=dfs(nbr.first,dest,adj,visited);
               if(val!=-1.0){
                return nbr.second*val;
               }
               
            }
        }
        return -1.0;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,vector<pair<string,double>>>adj;
        
        for(int i=0;i<equations.size();i++){
            string u=equations[i][0];
            string v=equations[i][1];
            
            double wt=values[i];

            adj[u].push_back({v,wt});
            adj[v].push_back({u,(double)(1/wt)});
        }

        vector<double>ans;
        for(int i=0;i<queries.size();i++){
            unordered_map<string,bool>visited;
            ans.push_back(dfs(queries[i][0],queries[i][1],adj,visited));
        }
        return ans;
    }
};