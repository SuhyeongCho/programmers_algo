#include <string>
#include <vector>

using namespace std;

string solution(int n, int t, int m, int p) {
    string answer = "";
    
    string s = "0";
    int i = 0;
    while(s.length() < m * t) {
        int cur = i;
        string tmp;
        while(cur) {
            switch(cur % n) {
                case 10: tmp = "A" + tmp; break;
                case 11: tmp = "B" + tmp; break;
                case 12: tmp = "C" + tmp; break;
                case 13: tmp = "D" + tmp; break;
                case 14: tmp = "E" + tmp; break;
                case 15: tmp = "F" + tmp; break;
                default: tmp = to_string(cur % n) + tmp;
            }
            cur /= n;
        }
        s += tmp;
        i++;
    }
    
    s = s.substr(0, m * t);
    
    for (int i = 0 ; i < s.length() ; i++) {
        if (i % m + 1 == p) answer.push_back(s[i]);
    }
    return answer;
}