class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n=score.size();
        priority_queue<int>q;
        for(int i=0;i<n;i++){
            q.push(score[i]);
        }
        int k=4;
        vector<string>ans(n);
        for(int i=0;i<n;i++){
            int a=q.top();
            q.pop();
            for(int j=0;j<n;j++){
                if(score[j]==a){
                    if(i==0){
                        ans[j]="Gold Medal";
                    }
                    else if(i==1){
                        ans[j]="Silver Medal";
                    }
                    else if(i==2){
                        ans[j]="Bronze Medal";
                    }
                    else{
                        ans[j]=to_string(k);
                        k++;
                    }
                }
            }
        }
        return ans;
    }
};