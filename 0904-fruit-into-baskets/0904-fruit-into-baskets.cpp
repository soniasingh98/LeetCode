class Solution {
public:
    int totalFruit(vector<int>& f) {
       int n=f.size();
        unordered_map<int,int>m;
        int i=0,j=0,mx=1;
        while(j<n){
            m[f[j]]++;
            if(m.size()<=2){
                mx=max(mx,j-i+1);
                j++;
            }
            else if(m.size()>2){
                while(m.size()>2){
               
                    m[f[i]]--;
                    if(m[f[i]]==0){m.erase(f[i]);}
                    i++;
                
                }
             j++;
            }
        }
        return mx;
    }
};