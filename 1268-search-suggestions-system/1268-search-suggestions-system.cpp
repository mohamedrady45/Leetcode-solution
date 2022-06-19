class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
    vector<vector<string>>ans;
     unordered_map<string,vector<string>>mp;
        sort(products.begin(),products.end());
        for (auto s:products){
            string ss="";
            for (int i=0;i<s.size();i++)
            {
                ss.push_back(s[i]);
                if (mp[ss].size()<3)
                    mp[ss].push_back(s);
            }
        }
        string sub;
     for (auto i :searchWord)
     {
         sub.push_back(i);
         ans.push_back(mp[sub]);
     }
        return ans;
    }
};