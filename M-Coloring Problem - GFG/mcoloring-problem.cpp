//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool graphColoring(bool graph[101][101], int m, int n) {
        // your code here
        vector<int>colors(n,0);
        return solve(0,graph,m,n,colors);
    }
    bool solve(int node,bool graph[101][101],int m,int n,vector<int>&colors){
        if(node==n)return true;
        for(int col=1;col<=m;col++){
            if(safe(node,col,graph,colors,n)){
                colors[node]=col;
                if(solve(node+1,graph,m,n,colors))return true;
                else colors[node]=0;
            }
        }
        return false;
    }
    bool safe(int node,int col,bool graph[101][101],vector<int>&colors,int n){
        for(int k=0;k<n;k++){
            if(k!=node && graph[k][node]==1 && colors[k]==col)return false;
        }
        return true;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends