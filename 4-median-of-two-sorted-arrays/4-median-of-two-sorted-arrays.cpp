class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        vector<int>v;
        for (int i:nums1)
        v.push_back(i);
        for (int i:nums2)
        v.push_back(i);
        v.resize(n+m);
        sort(v.begin(),v.end());
        double mid=0;
        if (v.size()&1)
            mid=v[v.size()/2]*1.00000;
        else 
            mid=(v[v.size()/2]+v[v.size()/2-1])/2.00000;
        return mid;
    }
};