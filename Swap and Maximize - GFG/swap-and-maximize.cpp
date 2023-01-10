//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
long long int maxSum(int arr[], int n);

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int arr[n];
		for(int i=0;i<n;++i)
			cin>>arr[i];
		cout<<maxSum(arr,n)<<endl;
	}
	return 0;
}
// } Driver Code Ends


long long int maxSum(int arr[], int n)
{
    sort(arr,arr+n);
    int count=0,i=0,j=n-1;
    vector<int>v;
    while(i<=j){
        if(count%2==0){
            v.push_back(arr[i]);
            i++;
        }
        else{
            v.push_back(arr[j]);
            j--;
        }
        count++;
    }
    long long sum=0;
    for(int i=0;i<n-1;i++){
        sum+=abs(v[i+1]-v[i]);
    }
    sum+=v[n-1]-v[0];
    return sum;
}