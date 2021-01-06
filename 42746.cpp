#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<int> numbers) {
    string answer = "";
    
    int me = *max_element(numbers.begin(), numbers.end());
    if (me == 0) return "0";
    
    vector<pair<string, string>> v;
    for (int i = 0 ; i < numbers.size() ; i++) {
        string d = to_string(numbers[i]);
        string ext_d = d + d + d + d;
        v.push_back(make_pair(ext_d, d));
    }
    sort(v.begin(), v.end(), greater<>());
    
    for (int i = 0 ; i < v.size() ; i++) {
        answer += v[i].second;
    }
    
    return answer;
}