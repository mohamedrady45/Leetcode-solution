class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix[0].size();
       int st=matrix[0][0],en=matrix[n-1][n-1];
        int res=st;
        while (st<=en){
            int mid=(st + en )/2;
            int cur=0;
            for (int i=0;i<n;i++){
                cur+=upper_bound (matrix[i].begin(),matrix[i].end(),mid)-matrix[i].begin();
            }
            if (cur<k)
                res=mid+1,st=mid+1;
            else en=mid-1;
        }
        return res;
    }
};