class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
      int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>>pre(n+1,vector<int>(m+1,0));
       for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            pre[i+1][j]=pre[i][j]+matrix[i][j];
        }
    }
        int cnt=0;
         for (int i=0;i<n;i++){
             for (int j=i+1;j<=n;j++){
                 for (int k=0;k<m;k++){
                     int rem=0;
                     for (int h=k;h<m;h++){
                         rem+=pre[j][h]-pre[i][h];
                         if (rem==target)
                             cnt++;
                     }
                 }
             }
         }
        return cnt;
    }
};