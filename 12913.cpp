#include <vector>
#include <algorithm>
using namespace std;

int dp[100001][4] = {0,};

int t_max(int &a, int &b, int &c) {
    return max(max(a, b), c);
}

int solution(vector<vector<int>> land) {
    int answer = 0;
    
    dp[0][0] = land[0][0];
    dp[0][1] = land[0][1];
    dp[0][2] = land[0][2];
    dp[0][3] = land[0][3];
    
    for (int i = 1 ; i < land.size() ; i++) {
        dp[i][0] = t_max(dp[i - 1][1], dp[i - 1][2], dp[i - 1][3]) + land[i][0];
        dp[i][1] = t_max(dp[i - 1][0], dp[i - 1][2], dp[i - 1][3]) + land[i][1];
        dp[i][2] = t_max(dp[i - 1][0], dp[i - 1][1], dp[i - 1][3]) + land[i][2];
        dp[i][3] = t_max(dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]) + land[i][3];
    }
    
    for (int i = 0 ; i < 4 ; i++) {
        answer = max(answer, dp[land.size() - 1][i]);
    }

    return answer;
}