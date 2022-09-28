class Solution {
public:
    bool isPowerOfFour(long long  n) {
        if (!(n&(n-1)) && n!=0){
            int cnt = __builtin_ctz(n);
            if (!(cnt&1))
                return true;
        }
        return false;
    }
};