class Solution {
    vector<vector<string>> ans;
    vector<string> board;
    vector<int> col,d1,d2;
    void dfs(int r,int n){
        if(r==n){ ans.push_back(board); return; }
        for(int c=0;c<n;c++){
            if(!col[c]&&!d1[r-c+n-1]&&!d2[r+c]){
                col[c]=d1[r-c+n-1]=d2[r+c]=1;
                board[r][c]='Q';
                dfs(r+1,n);
                board[r][c]='.';
                col[c]=d1[r-c+n-1]=d2[r+c]=0;
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        board.assign(n,string(n,'.'));
        col.assign(n,0);
        d1.assign(2*n,0);
        d2.assign(2*n,0);
        dfs(0,n);
        return ans;
    }
};
