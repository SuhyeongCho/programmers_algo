#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

set<int> s;

bool isPrime(int n) {
    if (n == 0) return false;
    if (n == 1) return false;
    
    for (int i = 2 ; i * i <= n ; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

void fn(string numbers, int pos, const int &n) {
    if (pos == n) {
        for (int i = 1 ; i <= n ; i++) {
            int d = stoi(numbers.substr(0, i));
            s.insert(d);
        }
    }
    
    for (int i = pos ; i < n ; i++) {
        swap(numbers[pos], numbers[i]);
        fn(numbers, pos + 1 ,n);
        swap(numbers[pos], numbers[i]);
    }
}

int solution(string numbers) {
    int answer = 0;
    int len = numbers.length();
    
    fn(numbers, 0, len);
    
    vector<int> v(s.begin(), s.end());
    
    for (int i = 0 ; i < v.size() ; i++) {
        if (isPrime(v[i])) answer++;
    }
    
    return answer;
}