class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int m = n;
        vector<vector<int>> ans(n,vector<int> (n));
        int j=1;
        int left = 0,top = 0,right = m-1,bottom = n-1;
        
        while(top<=bottom && left <= right){
            
            // left to right
            for(int i=left;i<=right;i++){
                ans[top][i] = j++;
            }
            top++;

            // top to bottom
            for(int i=top;i<=bottom;i++){
                ans[i][right] = j++;
            }
            right--;

            //right to left
            if(top<=bottom){
                for(int i=right;i>=left;i--){
                    ans[bottom][i] = j++;
                } 
                bottom--;
            }
            
            if(left<=right){
                for(int i=bottom;i>=top;i--){
                    ans[i][left] = j++;
                } 
                left++;
            }
            
        }
        return ans;
    }
};