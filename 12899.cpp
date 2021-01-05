#include <string>

using namespace std;

string solution(int n) {
    string answer = "";
    
    while (n) {
        int r = n % 3;
        n /= 3;
        
        if (r == 0) {
            n--;
            answer = "4" + answer;
        } else if (r == 1) answer = "1" + answer;
        else if (r == 2) answer = "2" + answer;
    }
    
    return answer;
}