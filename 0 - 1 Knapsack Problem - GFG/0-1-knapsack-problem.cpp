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
       // Your code here;
       vector<vector<int>>dp(n,vector<int>(W+1,0));
       for(int w=wt[0];w<=W;w++){
           dp[0][w]=val[0];
       }
       for(int i=1;i<n;i++){
           for(int w=0;w<=W;w++){
               int notpick=0+dp[i-1][w];
               int pick=INT_MIN;
               if(wt[i]<=w)pick=val[i]+dp[i-1][w-wt[i]];
               dp[i][w]=max(pick,notpick);
           }
       }
       return dp[n-1][W];
    }
    int f(int i,int wt[],int val[],int W,vector<vector<int>>&dp){
        if(i==0){
            if(wt[i]<=W)return val[i];
            else return 0;
        }
        if(dp[i][W]!=-1)return dp[i][W];
        int notpick=0+f(i-1,wt,val,W,dp);
        int pick=INT_MIN;
        if(wt[i]<=W)pick=val[i]+f(i-1,wt,val,W-wt[i],dp);
        return dp[i][W]=max(pick,notpick);
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