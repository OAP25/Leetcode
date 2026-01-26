// 2115. Find All Possible Recipes from Given Supplies
// You have information about n different recipes. You are given a string array recipes and a 2D string array ingredients. The ith recipe has the name recipes[i], and you can create it if you have all the needed ingredients from ingredients[i]. A recipe can also be an ingredient for other recipes, i.e., ingredients[i] may contain a string that is in recipes.

// You are also given a string array supplies containing all the ingredients that you initially have, and you have an infinite supply of all of them.

// Return a list of all the recipes that you can create. You may return the answer in any order.

// Note that two recipes may contain each other in their ingredients.

class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string,vector<string>>adj;
        unordered_map<string,int>indegree;
        for(string s:supplies)indegree[s]=0;
        for(int i=0;i<recipes.size();i++){
            for(string s:ingredients[i]){
                adj[s].push_back(recipes[i]);
                indegree[recipes[i]]++;
            }
        }
        queue<string>q;
        for(string s:supplies){
           q.push(s);
        }
        set<string>rec(recipes.begin(),recipes.end());
       
        vector<string>ans;
        while(!q.empty()){
            string s=q.front();
            q.pop();
            
           
            for(string st:adj[s]){
                indegree[st]--;
                if(indegree[st]==0){
                    q.push(st);
                    if(rec.find(st)!=rec.end())ans.push_back(st);
                }
            }
        
        }
       
       
        
        return ans;
    }

};