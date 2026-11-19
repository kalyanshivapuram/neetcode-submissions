class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
    //  std::unordered_set<int> repeat;
    //  for(int i=0;i<nums.size();i++){
    //    if(repeat.count(nums[i]) >0){
    //     return true;
    //    }
    //    else{
    //     repeat.insert(nums[i]);
    //    }
    //    // repeat[nums[i]]++;
    //  }
    //  return false;  
    std::unordered_set<int> repeat; 
    for(int i=0;i<nums.size();i++){
       if(repeat.find(nums[i])!=repeat.end()){
        return true;
       }
       else{
        repeat.insert(nums[i]);
       }
       // repeat[nums[i]]++;
     }
     return false;   
    }
};