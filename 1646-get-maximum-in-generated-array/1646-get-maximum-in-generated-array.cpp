class Solution {
public:
    int getMaximumGenerated(int n) {
        // int mx=INT_MIN;
        // for(int i=0;i<=n;i++){
        //     int c=f(i);
        //    mx=max(mx,c);
        // }
        // return mx;
       vector<int>arr(n+1,0);
        if(n==0 || n==1)return n;
        int mx=0;
        
        arr[0]=0;
        arr[1]=1;
        for(int i=2;i<=n;i++){
            if(i%2==0){
                arr[i]=arr[i/2];
            }
            else{
                arr[i]=arr[i/2+1]+arr[i/2];
            }
            mx=max(mx,arr[i]);
        }
        return mx;
    }
    //int f(int i){
    //     if(i==0 || i==1)return i;
    //     if(i%2==0)return f(i/2);
    //     return f(i/2-1)+f(i/2);
    // }
};