#include <string>

using namespace std;

string solution(string s) {
    for (int i = 0, wordIndex = 0 ; i < s.length() ; i++, wordIndex++) {
        if (s[i] == ' ') {
            wordIndex = -1;
            continue;
        }
        if (wordIndex % 2) {
            if (s[i] >= 'A' && s[i] <= 'Z') s[i] += 'a' - 'A';
        }
        else {
            if (s[i] >= 'a' && s[i] <= 'z') s[i] += 'A' - 'a';
        }
    }
    return s;
}