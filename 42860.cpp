#include <string>
#include <algorithm>

#define INF 1987654321

using namespace std;

int get_min_path(int a, int b, int len) {
    if (a > b) swap(a, b);
    return min(b - a, a - b + len);
}

int get_alpha[26] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,12,11,10,9,8,7,6,5,4,3,2,1};

bool isVisited[20] = {0,};
int map[20][20] = {0,};

int dfs(const int &cur, int cnt ,const string &name) {
    int len = name.length();
    isVisited[cur] = true;
    
    int ans = INF;
    for (int i = 0 ; i < len ; i++) {
        if (i != cur && !isVisited[i]) {
            ans = min(ans, dfs(i, cnt + map[i][cur], name));
        }
    }
    
    isVisited[cur] = false;
    return ans == INF ? cnt : ans;
}

int solution(string name) {
    int answer = 0;
    int len = name.length();
    
    for (int i = 0 ; i < len ; i++) {
        for (int j = 0 ; j < len ; j++) {
            map[i][j] = get_min_path(i, j, len);
        }
    }
    
    
    for (int i = 1 ; i < len ; i++) {
        if (name[i] == 'A') isVisited[i] = true;
        else isVisited[i] = false;
    }
    
    for (int i = 0 ; i < len ; i++) {
        int n = name[i] - 'A';
        answer += get_alpha[n];
    }
    
    answer += dfs(0, 0, name);
    
    return answer;
}