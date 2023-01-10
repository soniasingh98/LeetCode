//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    long long int findMaxProduct(vector<int>&a, int n){
        //Write your code here  
        long long prod=1;
        int zerocount=0,negcount=0,maxneg=INT_MIN;
        for(int i=0;i<n;i++){
            if(a[i]==0){
                zerocount++;
                continue;
            }
            else if(a[i]<0){
                negcount++;
                maxneg=max(maxneg,a[i]);
            }
            prod=prod*a[i]%1000000007;
        }
        if(zerocount==n)return 0;
        if(negcount==1 && negcount==n)return prod;
        if(negcount==1 && (negcount+zerocount==n))return 0;
        if(negcount&1){
            prod=prod/maxneg;
        }
        return prod;
    }
};



//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    vector<int>arr(n);
	    for(int i = 0 ; i < n; i++){
	        cin >> arr[i];
	    }
	    Solution ob;
	    long long int ans = ob.findMaxProduct(arr, n);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends