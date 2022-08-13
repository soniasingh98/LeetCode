class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        vector<vector<int>>v(matrix.size());
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix.size();j++){
               v[i].push_back(matrix[matrix.size()-j-1][i]);
            }
        }
        matrix=v;
    }
};