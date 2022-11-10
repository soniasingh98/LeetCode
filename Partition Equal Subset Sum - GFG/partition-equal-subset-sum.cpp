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
        int totalsum=0;
        for(int i=0;i<N;i++){
            totalsum+=arr[i];
        }
        if(totalsum%2!=0)return false;
        int k=totalsum/2;
        vector<vector<int>>dp(N,vector<int>(k+1,-1));
        return f(N-1,arr,k,dp);
    }
    int f(int i,int arr[],int k,vector<vector<int>>&dp){
        if(i==0){
            return arr[i]==k;
        }
        if(dp[i][k]!=-1)return dp[i][k];
        int nt=f(i-1,arr,k,dp);
        int t=0;
        if(arr[i]<=k)t=f(i-1,arr,k-arr[i],dp);
        return dp[i][k]=nt|t;
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