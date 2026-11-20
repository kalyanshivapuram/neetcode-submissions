#include <string>
class Solution {
public:

    string encode(vector<string>& strs) {
        string encode_str;
        for(const string& str : strs){
            encode_str += to_string(str.size())+"#" + str;
        }
        return encode_str;
    }

    vector<string> decode(string s) {
        vector<string> decode_str;
        int i=0;
        while(i < s.size()){
            int j = i;
            while(s[j]!='#') j++;
            int len = stoi(s.substr(i,j-i));
            decode_str.push_back(s.substr(j+1,len));
            i = j+1+len;
        }
        return decode_str;
        

    }
};
