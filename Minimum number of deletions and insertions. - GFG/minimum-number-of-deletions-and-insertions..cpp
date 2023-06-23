//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int minOperations(string str1, string str2) 
	{ 
	  int n=str1.size(),m=str2.size();
	  vector<int>prev(m+1,0),curr(m+1,0);
	  for(int i=1;i<=n;i++){
	      for(int j=1;j<=m;j++){
	          if(str1[i-1]==str2[j-1])curr[j]=1+prev[j-1];
	          else curr[j]=max(curr[j-1],prev[j]);
	      }
	      prev=curr;
	  }
	  return (n+m)-2*prev[m];
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