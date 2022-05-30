class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>v(nums1);
        v.insert(v.end(),nums2.begin(),nums2.end());
        sort(v.begin(),v.end());
        int a=v.size()/2;
        double ans;
        if(v.size()%2==0){
            ans=((double)v[a]+(double)v[a-1])/2;
        }
        else{
            ans=(double)v[a];
        }
        return ans;
    }
};