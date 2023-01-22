class Solution {
public:
    vector<vector<string>> ans ;
    string in ;
    bool pal (string s){
        string curr = s;
        reverse(curr.begin(),curr.end());
        return s==curr;
    }
    void solve (int idx, vector<string>curr){
        if (idx==in.size()){
            return void (ans.push_back(curr));
        }
        for (int i=idx;i<in.size();i++){
            if (pal(in.substr(idx,i-idx+1)))
            {
                curr.push_back(in.substr(idx,i-idx+1));
                solve (i+1 , curr);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        in = s;
        vector<string>curr;
        solve (0,curr);
        return ans;
    }
};