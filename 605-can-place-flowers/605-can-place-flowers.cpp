class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {

        int nk = flowerbed.size();


        for (int i = 0; i < nk; i++) {
            
            if (n == 0) return true;

            if (i == 0 && i == nk - 1 && flowerbed[i] == 0) {
                flowerbed[i] = 1;
                n--;

                return n == 0;
            }
            
            if (i == 0 && flowerbed[i] == 0 && flowerbed[i+1] == 0) {
                flowerbed[i] = 1;
                n--;
            }

            else if (i == nk - 1 && flowerbed[i] == 0 && flowerbed[i-1] == 0) {
                flowerbed[i] = 1;
                n--;
            }

            else if (i > 0 && i < nk - 1 && flowerbed[i] == 0 && flowerbed[i-1] == 0 && flowerbed[i+1] == 0) {
                flowerbed[i] = 1;
                n--;
            }
        }

        return n == 0;
    }
};