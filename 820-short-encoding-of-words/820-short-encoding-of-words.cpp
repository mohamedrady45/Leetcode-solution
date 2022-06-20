class Solution {
public:  
    #define all(v) ((v).begin()), ((v).end())
    int minimumLengthEncoding(vector<string>& words) {
    set<string>st(all(words)),s(all(words));
        for(auto it:words)
        {
            for (int i=1;i<it.size();i++)
            {
                string ss=it.substr(i);
                s.erase(ss);
            }
        }
        int sum=0;
        for (auto i:s)
            sum+=i.size()+1;
        return sum;
    }
};