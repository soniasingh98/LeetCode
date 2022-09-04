class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        heapsort(nums,nums.size());
        return nums;
    }
    void heapsort(vector<int>&nums,int n){
        for(int i=n/2-1;i>=0;i--){
            heapify(nums,n,i);
        }
        while(n>0){
            swap(nums[0],nums[n-1]);
            n--;
            heapify(nums,n,0);
        }
    }
    void heapify(vector<int>&nums,int n,int i){
        int largest=i;
        int left=2*i+1;
        int right=2*i+2;
        if(left<n && nums[largest]<nums[left]){
            largest=left;
        }
        if(right<n && nums[largest]<nums[right]){
            largest=right;
        }
        if(largest!=i){
            swap(nums[largest],nums[i]);
            heapify(nums,n,largest);
        }
        }
    
};