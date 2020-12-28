#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    int len = s.length();
    
    if (len % 2) {
        return s.substr(len / 2, 1);
    }
    return s.substr(len / 2 - 1, 2);
}