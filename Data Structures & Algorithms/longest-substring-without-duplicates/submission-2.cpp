class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> sett;
        int left =0;
        int max_length = 0;
        for(int right = 0;right<s.length();right++){
            while(sett.count(s[right])){
                sett.erase(s[left]);
                left++;
            }
            sett.insert(s[right]);
            max_length = max(max_length,right-left+1);

        }
        return max_length;
    }
};
