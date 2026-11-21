class Solution {
public:
    vector<int> countBits(int n) {
        
        vector<int> result;
        for(int i=0;i<=n;i++){
            int m =i;
            int count=0;
            while(m){
                m=m&(m-1);
                count+=1;
            }
            result.push_back(count);
        }
        return result;
    }
};
