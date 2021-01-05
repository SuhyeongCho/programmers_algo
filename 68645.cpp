#include <vector>

using namespace std;


vector<int> solution(int n) {
    // 아래, 오른쪽, 대각선위 순서
    int dir[3][2] = {{0,1},{1,0},{-1,-1}};
    int map[1001][1001] = {0, };
    
    int limit = n * (n + 1) / 2;
    
    int x = 0; int y = -1;

    int pos = 0;
    int cn = n;
    int num = 0;
    while(cn > 0) {
        for (int i = 0 ; i < cn ; i++) {
            int dx = dir[pos % 3][0];
            int dy = dir[pos % 3][1];
            
            x += dx;
            y += dy;
            map[y][x] = ++num;
        }
        cn--;
        pos++;
    }
    
    vector<int> answer;
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j <= i ; j++) {
            answer.push_back(map[i][j]);
        }
    }
    return answer;
}