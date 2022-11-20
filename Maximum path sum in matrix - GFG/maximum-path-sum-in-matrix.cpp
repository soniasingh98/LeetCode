//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        // code here
        int maxi=INT_MIN;
        vector<vector<int>>dp(N,vector<int>(N,-1));
        for(int j=0;j<N;j++){
            maxi=max(maxi,f(N-1,j,N,Matrix,dp));
        }
        return maxi;
    }
    int f(int i,int j,int N,vector<vector<int>>&Matrix,vector<vector<int>>&dp){
        if(j<0 || j>=N)return -1e9;
        if(i==0)return Matrix[0][j];
        if(dp[i][j]!=-1)return dp[i][j];
        int s=Matrix[i][j]+f(i-1,j,N,Matrix,dp);
        int ld=Matrix[i][j]+f(i-1,j-1,N,Matrix,dp);
        int rd=Matrix[i][j]+f(i-1,j+1,N,Matrix,dp);
        return dp[i][j]=max(s,max(ld,rd));
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}
// } Driver Code Ends