class WordFilter {
public:
    unordered_map<string,int>mp;
    WordFilter(vector<string>& words) {
        int n = words.size();
        for(int i=0;i<n;i++){
            string pre = "",suff = "";
            for(int j=0;j<=words[i].size();j++){
                suff = "";
                for(int k=words[i].size()-1;k>=0;k--){
                    suff = words[i][k]+suff;
                    mp[pre + "#" + suff] = i;
                }
                pre = pre+words[i][j];
            }
        }
    }
    int f(string pre, string suff) {
        if(mp.find(pre + "#" + suff)==mp.end()) return -1;
        return mp[pre + "#" + suff];
    }
};