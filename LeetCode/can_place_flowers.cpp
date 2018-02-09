class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count = 0;
        if(flowerbed.size() > 1){
            if(flowerbed[0] ==0 && flowerbed[1] == 0){
                count++;
                flowerbed[0]= 1;
            }
            if(flowerbed[flowerbed.size()-1] == 0 && flowerbed[flowerbed.size()-2] ==0){
                count++;
                flowerbed[flowerbed.size()-1] = 1;
            }
        }
        for(int index = 1;index<flowerbed.size()-1;index++){
            if(flowerbed[index] == 0){
                if(flowerbed[index-1] == 0 && flowerbed[index+1] == 0){
                    count++;
                    flowerbed[index] = 1;
                }
            }
        }
        if(flowerbed.size() == 1 && flowerbed[0] == 0)
            count++;
        if(count >= n)
            return true;
        return false;
    }
};
