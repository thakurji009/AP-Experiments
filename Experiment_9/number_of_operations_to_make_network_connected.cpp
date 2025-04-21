class Solution {
    public:
        void dfs(vector<vector<int>> &adj, int node, vector<bool> &visited){
            visited[node] = true;
    
            for(auto &neigh:adj[node]){
                if(!visited[neigh]){
                    dfs(adj, neigh, visited);
                }
            }
        }
    
        int makeConnected(int n, vector<vector<int>>& connections) {
            int edges = connections.size();
            if(edges < n-1) return -1;
            vector<vector<int>> adj(n);
    
            for(auto i:connections){
                adj[i[0]].push_back(i[1]);
                adj[i[1]].push_back(i[0]);
            }
    
            int dComp = 0;
            vector<bool> visited(n, false);
    
            for(int i=0; i<n; i++){
                if(!visited[i]){
                    dComp++;
                    dfs(adj, i, visited);
                }
            }
    
            return dComp-1;
        }
    };