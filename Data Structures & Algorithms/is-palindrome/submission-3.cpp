class Solution {
public:
    bool isPalindrome(string s) {
        int start=0;
        int end= s.size()-1;
        while(start < end ){
            //if(s[i]==' ') continue;
            //if(s[j]==' ') continue;
            while(!isalnum(s[start])) start++;
            while(!isalnum(s[end])) end--;
            if(start<end && tolower(s[start])!=tolower(s[end])){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
};
