class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
       vector<int>v=nums1;
        
        int i=0,j=0,k=0;
        while(i<m && j<n){
            if(v[i]>=nums2[j]){
                nums1[k]=nums2[j];
                j++;
                k++;
            }
            else{
                nums1[k]=v[i];
                i++;
                k++;
            }
        }
        if(i==m){
            while(j<n){
                nums1[k]=nums2[j];
                j++;
                k++;
            }
        }
        else{
            while(i<m){
                nums1[k]=v[i];
                i++;
                k++;
            }
        }
    }
};