class Solution {
public:
   
   bool func(vector<int>& bloomDay, int Day , int m, int k){
        int cnt = 0;
        int Ans = 0;

        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<=Day){
                cnt++;
            }else{
                Ans += (cnt/k);
                cnt = 0;
            }
        }
        Ans += (cnt/k);
        return Ans>=m;
   }
    
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if((long long)m*k>n){
            return -1;
        }

        int left = *min_element(bloomDay.begin(),bloomDay.end());
        int right = *max_element(bloomDay.begin(),bloomDay.end());

        while(left<=right){
            int mid = (left+right)/2;

            if(func(bloomDay,mid,m,k) ){
                right = mid-1;
            }else{
                left = mid+1;
            }
        }
        return left;
    }
};