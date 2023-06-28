//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        vector<int>v,temp;
        ss(0,arr,N,v,temp);
        return v;
    }
    void ss(int i,vector<int>&arr,int n,vector<int>&v,vector<int>temp){
        if(i==n){
            int sum=0;
            for(auto it:temp)sum+=it;
            v.push_back(sum);
            return;
        }
        temp.push_back(arr[i]);
        ss(i+1,arr,n,v,temp);
        temp.pop_back();
        ss(i+1,arr,n,v,temp);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends