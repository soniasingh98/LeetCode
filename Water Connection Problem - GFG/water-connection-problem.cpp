//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    int dfs(int i,int &ans,vector<int>&dia,vector<int>&ends){
        if(ends[i]==0)return i;
        if(dia[i]<ans)ans=dia[i];
        return dfs(ends[i],ans,dia,ends);
    }
    vector<vector<int>> solve(int n,int p,vector<int> a,vector<int> b,vector<int> d)
    {
        // code here
        vector<int>ends(n+1);
        vector<int>receives(n+1);
        vector<int>dia(n+1);
        for(int i=0;i<p;i++){
            int p=a[i];
            int q=b[i];
            int r=d[i];
            ends[p]=q;
            receives[q]=p;
            dia[p]=r;
        }
        vector<vector<int>>v;
        for(int i=1;i<=n;i++){
           if(ends[i] && receives[i]==0){
               int ans=INT_MAX;
               int w=dfs(i,ans,dia,ends);
               vector<int>vec;
               vec.push_back(i);
               vec.push_back(w);
               vec.push_back(ans);
               v.push_back(vec);
           } 
        }
        return v;
    }
};


//{ Driver Code Starts.
int main()
{
	int t,n,p;
	cin>>t;
	while(t--)
    {
        cin>>n>>p;
        vector<int> a(p),b(p),d(p);
        for(int i=0;i<p;i++){
            cin>>a[i]>>b[i]>>d[i];
        }
        Solution obj;
        vector<vector<int>> answer = obj.solve(n,p,a,b,d);
        cout<<answer.size()<<endl;
        for(auto i:answer)
        {
            cout<<i[0]<<" "<<i[1]<<" "<<i[2]<<endl;
        }
        
    }
	return 0;
}
// } Driver Code Ends