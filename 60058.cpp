#include <string>
#include <vector>

using namespace std;

string fn(string s) {
    if (s == "") return "";
    
    string u = "", v = "";
    int l_cnt = 0, r_cnt = 0;
    
    vector<char> st;
    for (int i = 0 ; i < s.length() ; i++) {
        char d = s[i];
        if (d == '(') {
            l_cnt++;
            st.push_back(d);
        }
        else {
            r_cnt++;
            if (st.size() && st.back() != d) st.pop_back();
            else st.push_back(d);
        }
        
        if (l_cnt == r_cnt) {
            u = s.substr(0, i + 1);
            v = s.substr(i + 1);
            break;
        }
    }
    if (st.empty()) return u + fn(v);
    else {
        string new_u = "";
        for (int i = 1 ; i < u.length() - 1 ; i++) {
            if (u[i] == '(') new_u.push_back(')');
            else new_u.push_back('(');
        }
        return "(" + fn(v) +")" + new_u;
    }
}

string solution(string p) {
    return fn(p);
}