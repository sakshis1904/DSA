class Solution {
    bool ok(vector<vector<char>>& b,int r,int c,char ch){
        for(int i=0;i<9;i++){
            if(b[r][i]==ch||b[i][c]==ch) return false;
            if(b[3*(r/3)+i/3][3*(c/3)+i%3]==ch) return false;
        }
        return true;
    }
    bool dfs(vector<vector<char>>& b){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(b[i][j]=='.'){
                    for(char ch='1';ch<='9';ch++){
                        if(ok(b,i,j,ch)){
                            b[i][j]=ch;
                            if(dfs(b)) return true;
                            b[i][j]='.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        dfs(board);
    }
};
