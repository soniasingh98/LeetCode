//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int equalPartition(int N, int arr[])
    {
        // code here
        int ts=0;
        for(int i=0;i<N;i++){
            ts+=arr[i];
        }
        if(ts%2)return 0;
        int k=ts/2;
        vector<vector<int>>dp(N,vector<int>(k+1,-1));
        return f(N-1,arr,k,dp);
    }
    int f(int i,int arr[],int sum,vector<vector<int>>&dp){
        if(i==0){
            return (arr[i]==sum);
        }
        if(dp[i][sum]!=-1)return dp[i][sum];
        int nt=f(i-1,arr,sum,dp);
        int t=0;
        if(arr[i]<=sum){
            t=f(i-1,arr,sum-arr[i],dp);
        }
        return dp[i][sum]=nt|t;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends