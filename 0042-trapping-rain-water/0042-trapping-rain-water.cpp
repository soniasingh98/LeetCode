class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int>mini(n),maxi(n);
        mini[0]=height[0];
        maxi[n-1]=height[n-1];
        for(int i=1;i<n;i++){
            mini[i]=max(mini[i-1],height[i]);
        }
        for(int i=n-2;i>=0;i--){
            maxi[i]=max(maxi[i+1],height[i]);
        }
        int sum=0;
        for(int i=0;i<n;i++){
            sum=sum+min(maxi[i],mini[i])-height[i];
        }
        return sum;
    }
};