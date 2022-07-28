void dfs(vector<int> &temp, vector<int> &vis, int V, int target, vector<vector<int>> &adj)
{
    for(int i=0; i<V; i++)
    {
        if(!vis[i] && adj[target][i])
        {
            temp.push_back(i);
            vis[i] = 1;
            dfs(temp, vis, V, i, adj);
        }
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    vector<vector<int>> adj(V, vector<int> (V, 0));
    for(int i=0; i<edges.size(); i++){
        adj[edges[i][0]][edges[i][1]] = 1;
        adj[edges[i][1]][edges[i][0]] = 1;
    }
    
    vector<vector<int>> res;
    vector<int> vis(V, 0);
    for(int i=0; i<V; i++){
        vector<int> temp;
        if(!vis[i])
        {
            temp.push_back(i);
            vis[i]=1;
            dfs(temp, vis, V, i, adj);
            res.push_back(temp);
        }
    }
    
    return res;
}