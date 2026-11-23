class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        int num_edges = edges.size();
        if(num_edges!= n-1){
            return false;
        }
        vector<vector<int>> adj(n);
        for(auto& e: edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<int> vis(n,false);
        int count=0;
        dfs(0,adj,vis,count);
        return count==n;
    }
    void dfs(int node,vector<vector<int>>& adj, vector<int>& vis, int& count){
        vis[node] =true;
        count++;
        for(int next : adj[node]){
            if(!vis[next]) dfs(next,adj,vis,count);
        }
    }
};
