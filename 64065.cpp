#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    vector<pair<int, vector<int>>> v;
    vector<int> tmp;
    
    int pos = 0;
    bool flag = false;

    for (int i = 1 ; i < s.size() - 1 ; i++) {
        if (s[i] == '{') continue;
        
        if (s[i] == ',' || s[i] == '}') {
            if (flag) {
                int num = stoi(s.substr(pos, i - pos));
                tmp.push_back(num);

                if (s[i] == '}') {
                    v.push_back(make_pair(tmp.size(), tmp));
                    tmp.clear();
                }
                flag = false;
            }
        } else {
            if (!flag) {
                flag = true;
                pos = i;
            }
        }
    }
    
    sort(v.begin(), v.end());
    
    set<int> check;
    for (int i = 0 ; i < v.size() ; i++) {
        vector<int> d = v[i].second;
        for (int j = 0 ; j < d.size() ; j++) {
            int num = d[j];
            if (check.find(num) != check.end()) continue;
            check.insert(num);
            answer.push_back(num);
        }
    }
    return answer;
}