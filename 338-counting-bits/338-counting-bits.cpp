class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>v(n+1);
        v[0]=0;
        for(int i=1;i<=n;i++){
            int ans=0;
            int n=i;
            while(n!=0){
                n=n&n-1;
                ans++;
            }
            v[i]=ans;
        }
        return v;
    }
};