#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(vector<int> numbers) {
    
    set<int> s;
    int N = numbers.size();
    for (int i = 0; i< N ; i++) {
      for (int j = 0 ; j < N; j++) {
        if (i == j) continue;
        s.insert(numbers[i] + numbers[j]);
      } 
    }
    
    vector<int> answer(s.begin(), s.end());
    return answer;
}