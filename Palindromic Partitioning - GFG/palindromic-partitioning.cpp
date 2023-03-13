//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int isPalin(int i,int j,string s){
        while(i<j){
            if(s[i++]!=s[j--])return false;
        }
        return true;
    }
    int f(int i,string str,vector<int>&dp){
        int mini=INT_MAX;
        if(i==str.size())return 0;
        if(dp[i]!=-1)return dp[i];
        for(int ind=i;ind<str.size();ind++){
            if(isPalin(i,ind,str)){
               int steps=1+f(ind+1,str,dp);
            mini=min(mini,steps);
            }
        }
        return dp[i]=mini;
    }
    int palindromicPartition(string str)
    {
        // code here
        vector<int>dp(str.size()+1,-1);
        return f(0,str,dp)-1;
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