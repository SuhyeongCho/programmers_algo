#include <vector>
#include <algorithm>

using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

bool isVisited[101][101] = {0,};

int dfs(int y, int x, int cnt, const int &m, const int &n, const vector<vector<int>> &picture) {
    isVisited[y][x] = true;
    for (int i = 0 ; i < 4 ; i++) {
        int y1 = y + dy[i];
        int x1 = x + dx[i];
        
        if (y1 < 0 || y1 >= m || x1 < 0 || x1 >= n) continue;
        if (picture[y1][x1] != picture[y][x]) continue;
        if (isVisited[y1][x1]) continue;
        cnt = dfs(y1, x1, cnt + 1, m, n, picture);
    }
    
    return cnt;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    
    for (int i = 0 ; i < 101 ; i++) {
        for (int j = 0 ; j < 101 ; j++) {
            isVisited[i][j] = false;
        }
    } 
    
    for (int i = 0 ; i< m ; i++) {
        for (int j = 0 ; j < n ; j++) {
            if (picture[i][j] == 0 || isVisited[i][j]) continue;
            number_of_area++;
            max_size_of_one_area = max(max_size_of_one_area, dfs(i, j, 1, m, n, picture));
        }
    }
    
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}