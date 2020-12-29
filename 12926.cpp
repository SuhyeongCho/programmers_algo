#include <string>

using namespace std;

string solution(string s, int n) {
    for (int i = 0 ; i < s.length() ; i++) {
        char c = s[i];
        if (c >= 'A' && c <= 'Z') {
            s[i] = ((c - 'A' + n) % 26) + 'A';
        } else if (c >= 'a' && c <= 'z') {
            s[i] = ((c - 'a' + n) % 26) + 'a';
        }
    }
    return s;
}