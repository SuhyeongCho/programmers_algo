#include <vector>
#include <algorithm>

using namespace std;


int solution(vector<vector<int>> board) {   
    int answer = 0;
    int height = board.size();
    int width = board[0].size();
    
    vector<vector<int>> map(height + 1, vector<int>(width + 1, 0));
    for (int i = 0 ; i < height ; i++) {
        for (int j = 0 ; j < width ; j++) {
            map[i + 1][j + 1] = board[i][j];
        }
    }
   
    for (int i = 1 ; i <= height ; i++) {
        for (int j = 1 ; j <= width ; j++) {
            if (map[i][j] == 0) continue;
            
            map[i][j] = min(map[i - 1][j - 1], min(map[i - 1][j], map[i][j - 1])) + 1;
            answer = max(answer, map[i][j]);
        }
    }
    
    return answer * answer;
}