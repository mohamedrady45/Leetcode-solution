class Solution {
public:
    string s ;
    int dp[100001][2];
    int solve (int i , int lst){
        if (i>=s.size())
            return 1;
        int &ret = dp[i][lst];
        if (~ret)
            return ret;
        if (lst==1){
            if (s[i]=='1')
             ret = solve(i+1,lst);
            else ret = solve(i+1,lst)+1;
        }
        else {
            int op1,op2;
            op1=op2=INT_MAX;
            if (s[i]=='1'){
                op1= solve (i+1,1);
                op2= solve (i+1,0)+1;
            }
            else {
                op1= solve (i+1,1)+1;
                op2= solve (i+1,0);
            }
            ret = min(op1,op2);
        }
        return ret;
    }
    int minFlipsMonoIncr(string ss) {
      s = ss;
      memset(dp,-1,sizeof dp);
      int ans = solve (0,0);
      return --ans;
    }
};