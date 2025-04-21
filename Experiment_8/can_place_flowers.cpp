class Solution {
    public:
        bool canPlaceFlowers(vector<int>& flowerbed, int p) {
            int n = flowerbed.size();
            if(p==0){
                return true;
            }
            for(int i=0;i<n;i++){
                if(flowerbed[i]==0 && (i==0 || flowerbed[i-1]==0) && (i == n-1 || flowerbed[i+1]==0)){
                    flowerbed[i] = 1;
                    p--;
                    if(p==0){
                        return true;
                    }
                }
            }
            return false;
        }
    };