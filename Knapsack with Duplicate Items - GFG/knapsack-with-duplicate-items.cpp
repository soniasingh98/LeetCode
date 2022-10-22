//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        vector<vector<int>>dp(N,vector<int>(W+1,0));
        for(int i=0;i<=W;i++){
            dp[0][i]=(i/wt[0])*val[0];
        }
        for(int i=1;i<N;i++){
            for(int w=0;w<=W;w++){
                int nt=0+dp[i-1][w];
                int t=INT_MIN;
                if(wt[i]<=w)t=val[i]+dp[i][w-wt[i]];
                dp[i][w]=max(nt,t);
            }
        }   
        // return f(N-1,W,val,wt,dp);
        return dp[N-1][W];
    }
    int f(int i,int W,int val[],int wt[],vector<vector<int>>&dp){
        if(i==0){
            return W/wt[0]*val[0];
        }
        if(dp[i][W]!=-1)return dp[i][W];
        int nt=0+f(i-1,W,val,wt,dp);
        int t=INT_MIN;
        if(wt[i]<=W)t=val[i]+f(i,W-wt[i],val,wt,dp);
        return dp[i][W]=max(nt,t);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends