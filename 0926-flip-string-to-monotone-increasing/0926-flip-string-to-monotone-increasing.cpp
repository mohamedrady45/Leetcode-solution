class Solution {
public:
    int minFlipsMonoIncr(string s) {
       int  ones=0 , flip = 0;
       int ans = 0;
        for (auto &i : s){
            if (i=='0'){
                flip++;
                flip = min(ones,flip);
            }
            else ones++;
        }
        return flip;
    }
};