using namespace std;

int solution(int n) {
    int answer = 0;
    
    while (n) {
        if (n % 2) answer++;
        n /= 2;
    }

    return answer;
}