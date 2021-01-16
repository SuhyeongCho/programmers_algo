#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    set<string> s;
    
    int first = 0, second = 0;
    
    char last = words[0].back();
    s.insert(words[0]);
    
    for (int i = 1 ; i < words.size() ; i++) {
        if (last != words[i].front() || s.find(words[i]) != s.end()) {
            first = i % n + 1;
            second = i / n + 1;
            break;
        }
        last = words[i].back();
        s.insert(words[i]);
    }
    
    answer.push_back(first);
    answer.push_back(second);
    
    return answer;
}