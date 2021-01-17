#include <string>
#include <vector>

using namespace std;

int answer = 0;
char map[30][30] = {0, };

bool fn(int m, int n) {
    int cnt = 0;
    bool isRemoved[30][30] = {0, };

    // 4칸씩 확인하여 제거할 대상 찾기
    for (int i = 0 ; i < m - 1 ; i++) {
        for (int j = 0 ; j < n - 1 ; j++) {
            if (map[i][j] != 0 && map[i][j] == map[i][j + 1] && map[i][j] == map[i + 1][j] && map[i][j] == map[i + 1][j + 1]) {
                isRemoved[i][j] = true;
                isRemoved[i][j + 1] = true;
                isRemoved[i + 1][j] = true;
                isRemoved[i + 1][j + 1] = true;
            }
        }
    }
    
    // 제거할 블록 개수 세고 제거
    for (int i = 0 ; i < m ; i++) {
        for (int j = 0 ; j < n ; j++) {
            if (isRemoved[i][j]) {
                cnt++;
                answer++;
                map[i][j] = 0;
            }
        }
    }
    
    if (cnt == 0) return false;
    
    // 아래로 이동
    for (int i = m - 1 ; i > 0 ; i--) {
        for (int j = 0 ; j < n ; j++) {
            if (!map[i][j]) {
                for (int k = i ; k >= 0 ; k--) {
                    if (map[k][j]) {
                        map[i][j] = map[k][j];
                        map[k][j] = 0;
                        break;
                    }
                }
            }
        }
    }
    
    return true;
}

int solution(int m, int n, vector<string> board) {
    
    for (int i = 0 ; i < m ; i++) {
        for (int j = 0 ; j < n ; j++) {
            map[i][j] = board[i][j];
        }
    }
    
    while(fn(m, n));
    return answer;
}