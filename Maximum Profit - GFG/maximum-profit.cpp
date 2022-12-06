//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maxProfit(int K, int N, int A[]) {
        // code here
        vector<vector<vector<int>>>dp(N,vector<vector<int>>(2,vector<int>(K+1,-1)));
        return f(0,N,K,A,1,dp);
    }
    int f(int i,int n,int cap,int a[],int buy,vector<vector<vector<int>>>&dp){
        if(i==n || cap==0)return 0;
        if(dp[i][buy][cap]!=-1)return dp[i][buy][cap];
        if(buy){
            return dp[i][buy][cap]=max(f(i+1,n,cap,a,1,dp),-a[i]+f(i+1,n,cap,a,0,dp));
        }
        return dp[i][buy][cap]=max(f(i+1,n,cap,a,0,dp),a[i]+f(i+1,n,cap-1,a,1,dp));
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
}
// } Driver Code Ends