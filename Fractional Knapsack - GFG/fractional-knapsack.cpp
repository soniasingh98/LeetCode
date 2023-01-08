//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        vector<pair<double,int>>v;
        for(int i=0;i<n;i++){
            double x=(arr[i].value*0.1)/(arr[i].weight*0.1);
            v.push_back({x,i});
        }
        sort(v.begin(),v.end(),greater<pair<double,int>>());
        int w=0;
        double ans;
        for(int i=0;i<n;i++){
            if((w+arr[v[i].second].weight)<W){
                ans+=arr[v[i].second].value;
                w+=arr[v[i].second].weight;
                }
                else{
                    double x=(W-w)*1.0;
                    ans+=(x*v[i].first);
                    break;
                }
        }
        return ans;
    }
        
};


//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends