#include <string>
#include <vector>

using namespace std;

int removeZeroAndCount(const string &s) {
    int cnt = 0;
    for (int i = 0 ; i < s.length() ; i++) {
        if (s[i] != '0') cnt++;
    }
    
    return cnt;
}

string numToString(int num) {
    string s = "";
    while(num) {
        if (num % 2) s = "1" + s;
        else s = "0" + s;
        num /= 2;
    }
    
    return s;
}

vector<int> solution(string s) {
    vector<int> answer;
    int cnt_0 = 0, cnt_t = 0;
    
    while(s != "1") {
        int new_len = removeZeroAndCount(s);
        cnt_0 += s.length() - new_len;
        
        s = numToString(new_len);
        cnt_t++;
    }
    
    answer.push_back(cnt_t);
    answer.push_back(cnt_0);
    
    return answer;
}