#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    int width = 0, height = 0;
    
    for (int i = 1 ; i * i <= yellow ; i++) {
        if (yellow % i == 0) {
            height = i + 2;
            width = (yellow / i) + 2;
            if (width * height == yellow + brown) break;
        }
    }
    answer.push_back(width);
    answer.push_back(height);
    return answer;
}