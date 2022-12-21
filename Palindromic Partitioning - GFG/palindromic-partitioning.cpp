//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int palindromicPartition(string str)
    {
        // code here
        int n=str.size();
        vector<int>dp(n,-1);
        return f(0,n,str,dp)-1;
    }
    int f(int i,int n,string str,vector<int>&dp){
        if(i==n)return 0;
        if(dp[i]!=-1)return dp[i];
        int mincost=INT_MAX;
        for(int j=i;j<n;j++){
            if(ispalin(i,j,str)){
                int cost=1+f(j+1,n,str,dp);
                mincost=min(mincost,cost);
            }
        }
        return dp[i]=mincost;
    }
    bool ispalin(int i,int j,string str){
        while(i<j){
            if(str[i]!=str[j])return false;
            j--;
            i++;
        }
        return true;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends