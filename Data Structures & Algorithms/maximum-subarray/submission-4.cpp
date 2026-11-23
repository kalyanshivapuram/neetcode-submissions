class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // int best = nums[0];
        // int cur = nums[0];
        // for(int i=1;i<nums.size();i++){
        //     cur = max(nums[i],cur +nums[i]);
        //     best = max(best,cur);
        // }
        // return best;

        int sum =0;
        int best = nums[0];
        for(int x :nums){
            if(sum<0) sum=0;
            sum+=x;
            best = max(sum,best);
        }
        return best;

    }
};
