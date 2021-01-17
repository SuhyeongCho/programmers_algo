#include <string>
#include <vector>
#include <map>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<string, string> m;
    vector<vector<string>> v;
    
    for (int i = 0 ; i < record.size() ; i++) {
        bool flag = false;
        int pos = 0;
        
        vector<string> tmp;
        for (int j = 0 ; j < record[i].length() ; j++) {
            if (record[i][j] == ' ' && flag) {
                tmp.push_back(record[i].substr(pos, j - pos));
                flag = false;
            } else {
                if (!flag) {
                    pos = j;
                    flag = true;
                }
            }
        }
        
        tmp.push_back(record[i].substr(pos));
        if (tmp[0] != "Leave") m[tmp[1]] = tmp[2];
        
        if (tmp[0] != "Change") v.push_back(tmp);
    }
    
    for (int i = 0 ; i < v.size() ; i++) {
        if (v[i][0] == "Enter") answer.push_back(m[v[i][1]] + "님이 들어왔습니다.");
        else if (v[i][0] == "Leave") answer.push_back(m[v[i][1]] + "님이 나갔습니다.");
    }
    
    return answer;
}