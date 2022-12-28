class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int>pq;
        for(auto it:piles){
            pq.push(it);
        }
        int sum=0;
        for (int i=0;i<k;i++){
            int a=pq.top();
            pq.pop();
            pq.push(a-(a/2));
        }
        while(!pq.empty()){
            sum+=pq.top();
            pq.pop();
        }
        return sum;
    }
};