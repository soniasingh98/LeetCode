class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int ct=0;
        if(ruleKey=="type"){
            for(int i=0;i<items.size();i++){
                if(items[i][0]==ruleValue){
                    ct++;
                }
            }
        }
        if(ruleKey=="color"){
            for(int i=0;i<items.size();i++){
                if(items[i][1]==ruleValue){
                    ct++;
                }
            }
        }
        if(ruleKey=="name"){
            for(int i=0;i<items.size();i++){
                if(items[i][2]==ruleValue){
                    ct++;
                }
            }
        }
        return ct;
    }
};