class Solution {
public:
    bool isAnagram(string s, string t) {
        int hmap[26]={0};
        int pos =0;
        if(s.size()!=t.size()){
            return false;
        }
        else{
            for(int i =0 ;i<s.size();i++){
                pos = s[i]-'a';
                hmap[pos]++;
                pos = t[i]-'a';
                hmap[pos]--;
            }
            for(int j =0;j<26;j++){
                if(hmap[j]!=0){
                    return false;
                }
        }
        }
        return true;
    }
};
