//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       vector<vector<int>>dp(n,vector<int>(W+1,0));
       for(int w=0;w<=W;w++){
           if(w>=wt[0])dp[0][w]=val[0];
       }
       for(int i=1;i<n;i++){
           for(int j=0;j<=W;j++){
               int t=-1e9;
               if(wt[i]<=j)t=val[i]+dp[i-1][j-wt[i]];
               int nt=dp[i-1][j];
               dp[i][j]=max(t,nt);
           }
       }
       return dp[n-1][W];
    }
    int f(int i,int wt[],int val[],int W,vector<vector<int>>&dp){
        if(i==0){
            if (W>=wt[i])return val[i];
            return 0;
        }
        if(dp[i][W]!=-1)return dp[i][W];
        int t=-1e9;
        if(wt[i]<=W)t=val[i]+f(i-1,wt,val,W-wt[i],dp);
        int nt=f(i-1,wt,val,W,dp);
        return dp[i][W]=max(nt,t);
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends