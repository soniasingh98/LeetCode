class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int a=edges[0][0];
        int b=edges[0][1];
        if(edges[1][0]==a || edges[1][1]==a){
            return a;
        }
        return b;
    }
};