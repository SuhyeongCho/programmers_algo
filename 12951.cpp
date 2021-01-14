#include <string>

using namespace std;

string solution(string s) {
    bool flag = true;
    for (int i = 0 ; i < s.length() ; i++) {
        char c = s[i];
        if (c == ' ') {
            flag = true;
        } else {
            if (flag) {
                if(c >= 'a' && c <= 'z') {
                    s[i] = s[i] - 'a' + 'A';
                }
                flag = false;
            } else {
                if (c >= 'A' && c <= 'Z') {
                    s[i] = s[i] - 'A' + 'a';
                }
            }
        }
    }
    
    return s;
}