#include <string>
#include <vector>

using namespace std;

bool isLeft(int n) {
    if (n % 3 == 1) return true;
    return false;
}

bool isRight(int n) {
    if (n == 0) return false;
    if (n % 3 == 0) return true;
    return false;
}

int calcDistance(int src, int dst) {
    int rows[12] = {3, 0, 0, 0, 1, 1, 1, 2, 2, 2, 3, 3};
    int cols[12] = {1, 0, 1, 2, 0, 1, 2, 0, 1, 2, 0, 2};
    
    return abs(rows[dst] - rows[src])\
        + abs(cols[dst] - cols[src]);
}

void handleLeft(string &answer, int &pos, const int &n) {
    answer += "L";
    pos = n;
}

void handleRight(string &answer, int &pos, const int &n) {
    answer += "R";
    pos = n;
}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int leftPos = 10;
    int rightPos = 11;
    
    for (int i = 0 ; i < numbers.size() ; i++) {
        int number = numbers[i];
        if (isLeft(number)) handleLeft(answer, leftPos, number);
        else if (isRight(number)) handleRight(answer, rightPos, number);
        else {
            int fromLeft = calcDistance(leftPos, number);
            int fromRight = calcDistance(rightPos, number);
            
            if (fromLeft < fromRight) handleLeft(answer, leftPos, number);
            else if (fromLeft > fromRight) handleRight(answer, rightPos, number);
            else if (hand == "left") handleLeft(answer, leftPos, number);
            else handleRight(answer, rightPos, number);
        }
    }
    return answer;
}