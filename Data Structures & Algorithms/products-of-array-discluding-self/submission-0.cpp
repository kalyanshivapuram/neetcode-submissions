class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> results(n,1);
        //left pass
        int prefix =1;
        int suffix =1;
        for(int i=0;i<n;i++){
            results[i] *= prefix;
            prefix *= nums[i];
        }

        //right pass
        for(int c=n-1;c>=0;c--){
            results[c]*=suffix;
            suffix *= nums[c];
        }
        return results;

    }
};
