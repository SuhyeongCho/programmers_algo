#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int getRealDistance(const vector<char> &friends, const int &first, const int &second) {
    int f_pos = -1, s_pos = -1;
    for (int i = 0 ; i < 8 ; i++) {
        if (friends[i] == first) f_pos = i;
        if (friends[i] == second) s_pos = i;
    }
    return abs(f_pos - s_pos) - 1;
}

int solution(int n, vector<string> data) {
    int answer = 0;
    vector<char> friends = {'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T'};
    
    do {
        bool flag = true;
        for (int i = 0 ; i < data.size() ; i++) {
            string d = data[i];
            char first = d[0];
            char second = d[2];
            char op = d[3];
            int wanted_dist = d[4] - '0';
            
            int real_dist = getRealDistance(friends, first, second);
            
            if (op == '=' && wanted_dist != real_dist) {flag = false; break;}
            if (op == '>' && wanted_dist >= real_dist) {flag = false; break;}
            if (op == '<' && wanted_dist <= real_dist) {flag = false; break;}
        }
        if (flag) answer++;
    } while (next_permutation(friends.begin(), friends.end()));
    
    return answer;
}