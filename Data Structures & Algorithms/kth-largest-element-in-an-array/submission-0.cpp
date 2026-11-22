class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> minheap;
        for(int x : nums){
            minheap.push(x);
            if(minheap.size()>k){
                minheap.pop();
            }
        }
        if(minheap.size()==0){
            return 0;
        }
        else{
            return minheap.top();
        }
    }
};
