#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for (int i = 0 ; i < commands.size(); i++) {
        vector<int> command = commands[i];
        
        int start = command[0];
        int end = command[1];
        int target = command[2];
        
        vector<int> subvector(array.begin() + start - 1, array.begin() + end);
        sort(subvector.begin(), subvector.end());
        
        answer.push_back(subvector[target - 1]);
    }
    return answer;
}