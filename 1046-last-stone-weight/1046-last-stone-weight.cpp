class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        if(stones.size()==1)return stones[0];
        int size=stones.size();
        priority_queue<int>p;
        for(auto i:stones){
            p.push(i);
        }
        while(p.size()>1){
            int first=p.top();
            p.pop();
            int second=p.top();
            p.pop();
            if(first!=second){
                p.push(first-second);
            }
        }
        if(p.empty()){
            return 0;
        }
        else{
            return p.top();
        }
    }
};