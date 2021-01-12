#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
    vector<char> st;
    for (int i = 0 ; i < s.length() ; i++) {
        if (s[i] == '(') st.push_back('(');
        else {
            if (st.empty()) return false;
            char d = st.back();
            if (d != '(') return false;
            st.pop_back();
        }
    }

    return st.empty();
}