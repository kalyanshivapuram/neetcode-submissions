class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> freq1(26);
        vector<int> freq2(26);

        int n = s1.size();
        int m = s2.size();
        if(n>m) return false;
        for(int i=0;i<n;i++){
            freq1[s1[i] - 'a']++;
            freq2[s2[i] - 'a']++;
        }

        if(freq1==freq2) return true;
        for(int j=n;j<m;j++){
            freq2[s2[j]-'a']++;
            freq2[s2[j-n]-'a']--;
            if(freq1==freq2) return true; 
        }
        return false;
    }
};
