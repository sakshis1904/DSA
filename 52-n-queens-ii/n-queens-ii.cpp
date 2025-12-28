class Solution {
    int cnt=0;
    vector<int> col,d1,d2;
    void dfs(int r,int n){
        if(r==n){ cnt++; return; }
        for(int c=0;c<n;c++){
            if(!col[c]&&!d1[r-c+n-1]&&!d2[r+c]){
                col[c]=d1[r-c+n-1]=d2[r+c]=1;
                dfs(r+1,n);
                col[c]=d1[r-c+n-1]=d2[r+c]=0;
            }
        }
    }
public:
    int totalNQueens(int n) {
        col.assign(n,0);
        d1.assign(2*n,0);
        d2.assign(2*n,0);
        dfs(0,n);
        return cnt;
    }
};
