class Solution {
public:
    int isWinner(vector<int>& player1, vector<int>& player2) {
        int p1_score = 0;
        int p2_score = 0;

        int n = player1.size();

        if (n == 1) {
            p1_score = player1[0];
            p2_score = player2[0];
        } else if (n >= 2) {
            p1_score = player1[0] + (player1[0] == 10 ? 2 : 1) * player1[1];
            p2_score = player2[0] + (player2[0] == 10 ? 2 : 1) * player2[1];

            for (int i = 2; i < n; i++) {
                p1_score += ((player1[i-1] == 10 || player1[i-2] == 10) ? 2 : 1) * player1[i];
                p2_score += ((player2[i-1] == 10 || player2[i-2] == 10) ? 2 : 1) * player2[i];
            }
        }

        cout << p1_score << " - " << p2_score << endl;

        return p1_score > p2_score ? 1 : p1_score == p2_score ? 0 : 2;
    }
};