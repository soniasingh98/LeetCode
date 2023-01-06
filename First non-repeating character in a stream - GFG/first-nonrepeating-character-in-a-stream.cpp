//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		    string ans="";
		    vector<char>v;
		    vector<int>vis(26,0);
		    for(int i=0;i<A.size();i++){
		        if(!vis[A[i]-'a']){
		            v.push_back(A[i]);
		        }
		        vis[A[i]-'a']++;
		        int f=0;
		        for(int j=0;j<v.size();j++){
		            if(vis[v[j]-'a']==1){
		                f=1;
		                ans.push_back(v[j]);
		                break;
		            }
		        }
		        if(f==0){
		            ans.push_back('#');
		        }
		    }
		    return ans;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends