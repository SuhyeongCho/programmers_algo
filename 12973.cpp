#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    
    vector<char> st;
    
    for (int i = 0 ; i < s.length() ; i++) {
        if (st.empty()) st.push_back(s[i]);
        else {
            char d = st.back();
            if (d == s[i]) {
                st.pop_back();
            } else st.push_back(s[i]);
        }
    }
    
    return st.empty();
}