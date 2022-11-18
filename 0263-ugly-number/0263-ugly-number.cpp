class Solution {
public:
    bool isUgly(int num) {
        while (num != 1) {
            int copy = num;
            if (copy % 2 == 0) copy /= 2;
            if (copy % 3 == 0) copy /= 3;
            if (copy % 5 == 0) copy /= 5;
            
            if (copy == num) return false; 
            num = copy;
        }
        
        return true;
    }
};