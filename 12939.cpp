#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";
    vector<int> v;
    
    int pos = 0;
    bool flag = false;
    for (int i = 0 ; i < s.length() ; i++) {
        if (s[i] == ' ') {
            v.push_back(stoi(s.substr(pos, i - pos)));
            flag = false;
        } else {
            if (flag) continue;
            pos = i;
            flag = true;
        }
    }
    
    v.push_back(stoi(s.substr(pos)));

    sort(v.begin(), v.end());
     
    return to_string(v.front()) + " " + to_string(v.back());
}