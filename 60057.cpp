#include <string>
#include <algorithm>

#define INF 1987654321

using namespace std;

int solution(string s) {
    int answer = INF;
 
    for (int i = 1 ; i <= s.length() ; i++) {
        int cnt = 1;
        string convert = "";
        string t = s.substr(0, i);
        for (int j = i ; j < s.length() ; j += i) {
            if (t == s.substr(j, i)) cnt++;
            else {
                if (cnt > 1) convert += to_string(cnt);
                convert += t;
                t = s.substr(j, i);
                cnt = 1;
            }
        }
        if (cnt > 1) convert += to_string(cnt);
        convert += t;
        answer = min((int)convert.length(), answer);
    }
    
    return answer;
}