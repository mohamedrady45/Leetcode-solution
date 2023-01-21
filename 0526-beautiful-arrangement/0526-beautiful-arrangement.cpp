class Solution {
public:
    int ans=0;
    int visited = 0;
    void solve (int n , int idx){
        if (idx > n){
            ans++;
            return ;
        }
       for (int i=1;i<=n;i++){
        int mask = 1 << i;
        if (!(visited & mask)){
            if (i % idx == 0 || idx % i == 0){
                visited ^=mask;
                solve(n,idx+1);
                visited ^=mask;
            }
        }
       }
    }
    int countArrangement(int n) {
       if (n<4)
       return n;
       solve(n,1);
       return ans;
    }
};