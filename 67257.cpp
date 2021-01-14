#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

long long solution(string expression) {
    long long answer = 0;
    
    char op[6][3] = {\
            {'+', '-', '*'}, {'+', '*', '-'},\
            {'-', '+', '*'}, {'-', '*', '+'},\
            {'*', '+', '-'}, {'*', '-', '+'}\
        };
    
    vector<long long> nums;
    vector<char> ops;
    
    bool flag = false;
    int pos = 0;
    
    for (int i = 0 ; i < expression.length() ; i++) {
        char c = expression[i];
        if (c == '+' || c == '-' || c == '*') {
            if (flag) {
                ops.push_back(c);
                nums.push_back(stoi(expression.substr(pos, i - pos)));
                flag = false;
            }
        } else {
            if (!flag) {
                pos = i;
                flag = true;
            }
        }
    }
    
    nums.push_back(stoi(expression.substr(pos)));
    
    for (int i = 0 ; i < 6 ; i++) {
        vector<long long> tmp = nums;
        vector<long long> st;
        vector<char> t_ops = ops;
        
        for (int j = 0 ; j < 3 ; j++) {
            char p = op[i][j];
            vector<char> n_ops;
            st.push_back(tmp[0]);
            for (int i = 0 ; i < tmp.size() - 1 ; i++) {
                if (t_ops[i] == p) {
                    long long cc = st.back();
                    st.pop_back();
                    
                    long long new_cc = cc;
                    if (p == '+') new_cc += tmp[i + 1];
                    else if (p == '-') new_cc -= tmp[i + 1];
                    else if (p == '*') new_cc *= tmp[i + 1];
                    st.push_back(new_cc);
                } else {
                    st.push_back(tmp[i + 1]);
                    n_ops.push_back(t_ops[i]);
                }
            }
            
            tmp = st;
            st.clear();
            t_ops = n_ops;
        }
        
        answer = max(answer, abs(tmp[0]));
    }
    
    return answer;
}