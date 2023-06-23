//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	int minOperations(string str1, string str2) 
	{ 
	  int n=str1.size(),m=str2.size();
	  vector<vector<int>>dp(n,vector<int>(m,-1));
	  int lcs=f(str1,str2,n-1,m-1,dp);
	  return (n+m)-2*lcs;
	} 
	int f(string &s,string &t,int i,int j,vector<vector<int>>&dp){
	    if(i<0 || j<0)return 0;
	    if(dp[i][j]!=-1)return dp[i][j];
	    if(s[i]==t[j])return dp[i][j]=1+f(s,t,i-1,j-1,dp);
	    return dp[i][j]= max(f(s,t,i-1,j,dp),f(s,t,i,j-1,dp));
	}
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends