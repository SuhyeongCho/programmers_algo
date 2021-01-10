#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    int len_limit = number.length() - k;
    
    vector<char> v;
    v.push_back(number[0]);
    
    int i = 1;
    for (; i < number.length(); i++) {
        if (v.back() >= number[i]) v.push_back(number[i]);
        else {
            while(!v.empty() && v.back() < number[i] && k){
                v.pop_back();
                k--;
            }
            v.push_back(number[i]);
        }
    }
    
    if (k == 0) {
        for (int j = i ; j < number.length() ; j++) {
            v.push_back(number[j]);
        }
    }
    
    for (int i = 0 ; i < len_limit ; i++) {
        answer.push_back(v[i]);
    }
    return answer;
}