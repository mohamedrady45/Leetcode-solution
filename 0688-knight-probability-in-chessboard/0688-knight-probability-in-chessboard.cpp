class Solution {
public:
    int dx [8] = {-2 , -1 , 1 , 2 , 2, 1,-1,-2};
    int dy [8] = {-1 , -2 , -2 , -1 , 1, 2, 2 , 1}; 
    double dp [26][26][101]; 
    static bool valid (int i , int  j , int n ){
        return i>=0 && i<n && j>=0 && j <n;
    }
    double solve (int i , int j , int cnt , int n ){
        if (!valid(i,j,n))
         return 0 ;
         if (cnt == 0)
          return 1;
        double & ret = dp[i][j][cnt];
        if (ret!=0)
        return ret;
        double ans  = 0 ;
        for (int k=0;k<8;k++){
           int new_i , new_j ;
           new_i = dx[k]+i;
           new_j = dy[k]+j;
           ans+=solve (new_i , new_j , cnt-1 , n)/8.0;
        }
        return ret = ans ;
    }
    double knightProbability(int n, int k, int row, int column) {
        memset (dp , 0 , sizeof dp);
        return  solve (row , column , k , n);
    }
};