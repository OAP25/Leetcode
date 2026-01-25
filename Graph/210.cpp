// 210. Course Schedule II
// There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

// For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
// Return the ordering of courses you should take to finish all courses. If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array.

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        vector<int>indegree(numCourses);
        for(int i=0;i<prerequisites.size();i++){
            int u=prerequisites[i][0];
            int v=prerequisites[i][1];

            adj[v].push_back(u);
            indegree[u]++;
        }

        vector<int>topo;
        queue<int>q;

        for(int i=0;i<numCourses;i++)if(indegree[i]==0)q.push(i);

        while(!q.empty()){
            int curr=q.front();
            q.pop();
            topo.push_back(curr);

            for(int i:adj[curr]){
                indegree[i]--;
                if(indegree[i]==0)q.push(i);
            }
        }
        vector<int>emp{};
        return topo.size()!=numCourses?emp:topo;
    }
};