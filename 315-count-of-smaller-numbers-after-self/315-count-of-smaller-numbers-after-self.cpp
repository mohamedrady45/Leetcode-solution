#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>;
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        ordered_set<int>st;
        vector<int> res(nums.size());
        int n=nums.size();
        for (int i=n-1;i>=0;i--){
        res[i]= (st.order_of_key(nums[i]));
            st.insert(nums[i]);
        }
        
        return res;
    }
};