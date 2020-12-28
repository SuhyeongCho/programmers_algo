#include <string>
#include <vector>

using namespace std;

bool check(vector<int> stack) {
    int siz = stack.size();
    if (siz <= 1) return false;
    if (stack[siz - 1] == stack[siz - 2]) return true;
    return false;
}

void handleRemove(vector<int> &stack) {
    int siz = stack.size();
    if (siz <= 1) return;
    stack.pop_back();
    stack.pop_back();
    return;
}

int solution(vector<vector<int>> board, vector<int> moves) {
    int N = board.size();
    int M = board[0].size();

    vector<vector<int>> map(M);
    vector<int> stack;
    int answer = 0;

    for (int i = 0 ; i < M ; i++) {
        for (int j = N - 1 ; j >=0 ; j--) {
            int d = board[j][i];
            if (d == 0) break;
            map[i].push_back(d);
        }
    }
    
    for (int i = 0 ; i < moves.size() ; i++) {
        int d = moves[i] - 1;
        int n = map[d].back();
        if (n ==0) continue;
        answer++;
        
        map[d].pop_back();
        
        stack.push_back(n);
        if (check(stack)) handleRemove(stack);
    }
    
    return answer - stack.size();
}