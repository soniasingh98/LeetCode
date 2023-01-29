class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int n=nums.size();
        return mergesort(nums,0,n-1);
    }
    int mergesort(vector<int>&nums,int low,int high){
        int inv=0;
        if(low<high){
            int mid=(low+high)/2;
            inv+=mergesort(nums,low,mid);
            inv+=mergesort(nums,mid+1,high);
            inv+=merge(nums,low,mid,high);
        }
        return inv;
    }
    int merge(vector<int>&nums,int low,int mid,int high){
        int inv=0;
        int j=mid+1;
        for(int i=low;i<=mid;i++){
            while(j<=high && nums[i]>(2LL*nums[j]))j++;
            inv+=(j-(mid+1));
        }
        vector<int>temp;
        int a=low,b=mid+1;
        while(a<=mid && b<=high){
            if(nums[a]<=nums[b]){
                temp.push_back(nums[a++]);
            }
            else{
                temp.push_back(nums[b++]);
            }
        }
        while(a<=mid){
            temp.push_back(nums[a++]);
        }
        while(b<=high){
            temp.push_back(nums[b++]);
        }
        for(int i=low;i<=high;i++){
            nums[i]=temp[i-low];
        }
        return inv;
    }
};