#include <string>
#include <cmath>

using namespace std;

struct Result {
    int score;
    int bonus;
    int option;
};

bool isDigit(char c) {
    return c >= '0' && c <= '9';
}

int solution(string dartResult) {
    int answer = 0;
    struct Result results[4] = {{0,},};
    int scores[4] = {0,};
    
    string score = "";
    int pos = 1;
    
    dartResult += " ";
    
    for (int i = 1 ; i < 4 ; i++) {
        results[i].score = 0;
        results[i].bonus = 0;
        results[i].option = 1;
    }
    
    for (int i = 0 ; i < dartResult.length() - 1 ; i++) {
        char c = dartResult[i];
        
        char n = dartResult[i + 1];
        
        if (isDigit(c)) {
            score.push_back(c);
        } else {
            results[pos].score = stoi(score);
            if (!score.empty()) score.clear();
            if (c == 'S') results[pos].bonus = 1;
            else if (c == 'D') results[pos].bonus = 2;
            else if (c == 'T') results[pos].bonus = 3;

            if (!isDigit(n) && n != ' ') {
                // option이 있는 경우
                if (n == '*') {
                    results[pos].option *= 2;
                    results[pos - 1].option *= 2;
                }
                else if (n == '#') results[pos].option *= -1;
                i++;
            }
            pos++;
        }
    }
    
    for (int i = 1 ; i < 4 ; i++) {
        answer += pow(results[i].score, results[i].bonus) * results[i].option;
    }
    return answer;
}