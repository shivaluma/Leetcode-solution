class Solution {
    int cal(int n, int x) {
        n /= x;
        return n * (n + 1) / 2 * x;
    }
public:
    int sumOfMultiples(int n) {
        return cal(n, 3) + cal(n, 5) + cal(n, 7) - cal(n, 15) - cal(n, 21) - cal(n, 35) + cal(n, 105);
    }
};