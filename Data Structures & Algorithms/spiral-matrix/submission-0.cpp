class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int left = 0;
        int right = m-1;
        int top = 0;
        int bottom = n-1;
        vector<int> result;
        while(left<=right && top<=bottom){
            for(int i =left;i<=right;i++){
                result.push_back(matrix[top][i]);
            }
            for(int j=top+1;j<=bottom;j++){
                result.push_back(matrix[j][right]);
            }
            if (top < bottom){
                for(int k=right-1;k>=left;k--){
                    result.push_back(matrix[bottom][k]);
                }
            }
            if (left < right){
                for(int l = bottom-1;l>top;l--){
                    result.push_back(matrix[l][left]);
                }
            }
            left++;
            right--;
            bottom--;
            top++;
        }
        return result;
    }
};
