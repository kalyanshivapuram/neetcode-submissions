class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std::unordered_set<int> s(nums.begin(),nums.end());
        int best =0;
        for(int x : s){
            if(s.count(x-1)){
                continue;
            }
            
            int length =1;
            int curr =x;
            while(s.count(curr+1)){
                length++;
                curr++;
            }
            best =max(best,length);
            
        }
        return best;
    }
};
