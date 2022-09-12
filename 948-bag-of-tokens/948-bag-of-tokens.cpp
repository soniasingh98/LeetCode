class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        if(tokens.size()==0)return 0;
        int mx=INT_MIN;
        int score=0;
        int n=tokens.size();
        int l=tokens.size()-1;
        sort(tokens.begin(),tokens.end());
        for(int i=0;i<n;i++){
            if(tokens[i]!=-1){
                if(power>=tokens[i]){
                    power-=tokens[i];
                    score+=1;
                }
                else if(score>0){
                    power+=tokens[l];
                    score-=1;
                    tokens[l]=-1;
                    l--;
                    if(power>=tokens[i]){
                        score+=1;
                        power-=tokens[i];
                    }
                }
            }
            mx=max(mx,score);
        }
        return mx;
    }
};