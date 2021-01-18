#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const vector<string> &a, const vector<string> &b) {
    if (a[0] == b[0]) {
        int num_a = stoi(a[1]);
        int num_b = stoi(b[1]);
        return num_a < num_b;
    }
    return a[0] < b[0];
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    
    vector<vector<string>> v;

    for (int i = 0 ; i < files.size() ; i++) {
        string file = files[i];
        file += " ";
        string head, number;
        
        int pos = 0;
        
        for (int j = pos ; j < file.length() ; j++) {
            if (file[j] >= '0' && file[j] <= '9') {
                head = file.substr(pos, j - pos);
                pos = j;
                break;
            }
        }
        
        for (int j = pos ; j < file.length() ; j++) {
            if (!(file[j] >= '0' && file[j] <= '9')) {
                number = file.substr(pos, min(j - pos, 5));
                pos = j;
                break;
            }
        }
            
        for (int j = 0 ; j < head.length() ; j++) {
            if (head[j] >= 'A' && head[j] <= 'Z') head[j] = head[j] - 'A' + 'a';
        }
        
        v.push_back({head, number, files[i]});
    }
    
    stable_sort(v.begin(), v.end(), compare);
    
    for (int i = 0 ; i < v.size() ; i++) {
        answer.push_back(v[i][2]);
    }
    
    return answer;
}