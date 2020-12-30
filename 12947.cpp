using namespace std;

bool solution(int x) {
    int d = x;
    int sum = 0;
    while (d) {
        sum += d % 10;
        d /= 10;
    }
    return !(x % sum);
}