class Solution {
public:
            vector<vector<string>>res;
         bool isvalid(vector<string>&v ,int row,int col){
         for (int i=0;i<v.size();i++){
             if (v[row][i]=='Q')
             return false;
         }
         for (int i=row,j=col;i>=0&&j>=0;i--,j--){
             if (v[i][j]=='Q')
                 return false;
         }
         for (int i=row,j=col;j>=0&&i<v.size();i++,j--){
             if (v[i][j]=='Q')
                 return false;
         }
         return true;
     }
   void solve (vector<string>&v,int col){
        if (col==v.size()){
            res.push_back(v);
        }
        for (int row=0;row<v.size();row++){
            if (isvalid(v,row,col)){
                v[row][col]='Q';
                solve(v,col+1);
                v[row][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string>v(n,string(n,'.'));
        solve (v,0);
        return res;
    }
};