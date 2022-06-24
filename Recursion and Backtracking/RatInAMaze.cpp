void solve(vector<vector<int>> &maze, int i, int j, int n, vector<vector<int>> &path, vector<vector<int>> &ans)
{    
    if(i == n-1 and j == n-1){
        path[i][j]=1;
        vector<int> temp;
        for(int i= 0; i< n; i++){
            for(int j= 0; j< n; j++){
                temp.push_back(path[i][j]);
            }
        }
        ans.push_back(temp);
        return;
    }
    
    if(i< 0 || j< 0 || i>= n || j>= n || path[i][j] == 1 || maze[i][j] == 0)
        return;
    
    path[i][ j]=1 ;
     solve(maze, i+1, j, n, path, ans);
    solve(maze, i-1, j, n, path, ans);
    solve(maze, i, j+1, n, path, ans);
    solve(maze, i, j-1, n, path, ans);
    path[i][j]=0;
}

vector<vector<int> > ratInAMaze(vector<vector<int> > &maze, int n){
    vector<vector<int>> ans;
    vector<vector<int>> path(n, vector<int>(n, 0));
    solve(maze, 0, 0, n, path, ans);
    return ans;
}