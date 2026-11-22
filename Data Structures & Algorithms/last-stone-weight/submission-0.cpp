class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int,vector<int>> maxHeap;
        int num_stones = stones.size();
        for(int x : stones){
            maxHeap.push(x);
        }
        while(maxHeap.size()>1){
            int x=maxHeap.top();
            maxHeap.pop();
            int y =maxHeap.top();
            maxHeap.pop();
            if(x!=y){
                maxHeap.push(abs(x-y));
            }
        }
        if(maxHeap.size()==0){
            return 0;
        }
        else{
            return maxHeap.top();
        }
        

    }
};
