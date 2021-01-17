#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    map<string, int> m;
    
    for (int i = 1 ; i <= 26 ; i++) {
        string s;
        s.push_back('A' + i - 1);
        m[s] = i;
    }
    
    msg += "1";
    
    int next = 27;
    int out;
    for (int i = 0 ; i < msg.length() - 1 ; i++) {
        for (int j = 1 ; j <= msg.length() - i ; j++) {
            string w = msg.substr(i, j);
            if(m[w]) {
                out = m[w];
            } else {
                m[w] = next++;
                answer.push_back(out);
                i += j - 2;
                break;
            }
        }
    }

    return answer;
}