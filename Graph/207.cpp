// 207. Course Schedule
// There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

// For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
// Return true if you can finish all courses. Otherwise, return false.

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>topo;
        vector<vector<int>>adj(numCourses);
        vector<int>indegree(numCourses);
        for(int i=0;i<prerequisites.size();i++){
            int u=prerequisites[i][0];
            int v=prerequisites[i][1];

            adj[v].push_back(u);
            indegree[u]++;
        }

        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0)q.push(i);
        }

        while(!q.empty()){
            int curr=q.front();
            q.pop();
            topo.push_back(curr);

            for(int &i:adj[curr]){
                indegree[i]--;
                if(indegree[i]==0)q.push(i);
            }
        }
        return topo.size()==numCourses;

    }
};