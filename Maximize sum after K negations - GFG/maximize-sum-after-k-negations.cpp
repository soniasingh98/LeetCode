//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long int maximizeSum(long long int a[], int n, int k)
    {
      
        sort(a,a+n);
        int i=0;
        while(a[i]<0 && k>0 && i<n){
            a[i]=0-a[i];
            i++;
            k--;
        }
        sort(a,a+n);
        if(k%2)a[0]=0-a[0];
        long long int sum=0;
        for(int j=0;j<n;j++){
            sum+=a[j];
        }
        return sum;
    }
};

//{ Driver Code Starts.
int main()
 {
     int t;
     cin>>t;
     while(t--)
     {
         int n, k;
         cin>>n>>k;
         long long int a[n+5];
         for(int i=0;i<n;i++)
         cin>>a[i];
         Solution ob;
         cout<<ob.maximizeSum(a, n, k)<<endl;
     }
	
	return 0;
}
// } Driver Code Ends