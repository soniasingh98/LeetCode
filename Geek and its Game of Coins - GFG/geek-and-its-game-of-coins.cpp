//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int findWinner(int N, int X, int Y)
	{
		// Your code goes here
		vector<int>dp(N+1,0);
		dp[1]=1;
		for(int i=2;i<=N;i++){
		    if(i-1>=0 && dp[i-1]==0){
		        dp[i]=1;
		    }
		    else if(i-X>=0 && dp[i-X]==0){
		        dp[i]=1;
		    }
		    else if(i-Y>=0 && dp[i-Y]==0){
		        dp[i]=1;
		    }
		    else{
		        dp[i]=0;
		    }
		}
		return dp[N];
	}

};
	

//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
       	int n, x, y;
       	cin >> n >> x >> y;

       

        Solution ob;
        cout << ob.findWinner(n, x, y);
	    cout << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends