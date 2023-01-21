class Solution {
public:
    vector<string>ans ; 
    string in;
    bool valid (string s){
         int curr = stoi(s);
         if ((s.size()>1 && s[0]=='0' ) || curr > 255 )
             return false;
        return true;
    }
    void solve (int idx , int cnt , string curr ){
        if (idx>=in.size()){
            if (cnt==4){
            curr.pop_back();
            return void (ans.push_back(curr));
            }
        }
        for (int i=1;i<=3;i++){
            if (i+idx <= in.size() && valid(in.substr(idx,i)))
                solve (idx+i , cnt+1 , curr+in.substr(idx,i)+".");
        }
    }
    vector<string> restoreIpAddresses(string s) {
        in = s;
        solve (0 , 0 , "");
        return ans ;
    }
};