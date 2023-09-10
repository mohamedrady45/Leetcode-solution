class Solution {
public:
    int countOrders(int n) {
        long long ans = 1;
        int MOD = 1e9+7;
        for (int i=2;i<=n;i++){
            ans = ((ans%MOD * (2*i-1)%MOD * i%MOD)%MOD);
            ans%=MOD;
        }
        return (int)ans%MOD ;
    }
};