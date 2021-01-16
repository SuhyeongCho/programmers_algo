#include <string>
#include <vector>

using namespace std;

bool isUpper(char c) {
    if (c >= 'A' && c <= 'Z') return true;
    return false;
}

bool isLower(char c) {
    if (c >= 'a' && c <= 'z') return true;
    return false;
}

bool isAlpha(char c) {
    if (isUpper(c) || isLower(c)) return true;
    return false;
}

string getHash(string s) {
    string temp;
    char c1 = s[0];
    char c2 = s[1];
    
    if (isAlpha(c1) && isAlpha(c2)) {
        if (isLower(c1)) c1 = c1 - 'a' + 'A';
        if (isLower(c2)) c2 = c2 - 'a' + 'A';
        temp.push_back(c1);
        temp.push_back(c2);
        return temp;
    }
    return "";
}

int solution(string str1, string str2) {
    vector<pair<string, bool>> st1, st2;
    for (int i = 0 ; i < str1.length() - 1 ; i++) {
        string s = getHash(str1.substr(i, 2));
        if (s.length()) st1.push_back(make_pair(s, true));
    }
    for (int i = 0 ; i < str2.length() - 1 ; i++) {
        string s = getHash(str2.substr(i, 2));
        if (s.length()) st2.push_back(make_pair(s, true));
    }
    
    int intersec = 0;
    int uni = 0;
    
    for (int i = 0 ; i < st1.size() ; i++) {
        for (int j = 0 ; j < st2.size() ; j++) {
            if (!st1[i].second || !st2[j].second) continue;
            if (st1[i].first == st2[j].first) {
                st1[i].second = false;
                st2[j].second = false;
                intersec++;
            }
        }
    }
    uni = st1.size() + st2.size() - intersec;
    
    if (!uni) return 65536;
    return 65536 * intersec / uni;
}