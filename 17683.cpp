#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const pair<string, string> &a, const pair<string, string> &b) {
    return a.second.length() > b.second.length();
}

string changeMusic(string s) {
    string n_music = "";
    for (int i = 0 ; i < s.length() ; i++) {
        char cur = s[i];
        char next = (i == s.length() - 1) ? 0 : s[i + 1];

        if (next == '#') {
            if (cur == 'C') n_music.push_back('H');
            else if (cur == 'D') n_music.push_back('I');
            else if (cur == 'F') n_music.push_back('J');
            else if (cur == 'G') n_music.push_back('K');
            else if (cur == 'A') n_music.push_back('L');
            i++;
        } else n_music.push_back(s[i]);
    }
    return n_music;
}

string solution(string m, vector<string> musicinfos) {
    string answer = "";
    
    vector<pair<string, string>> v;
    for (int i = 0 ; i < musicinfos.size() ; i++) {
        string musicinfo = musicinfos[i];
        
        vector<string> tmp;
        int pos = 0;
        bool flag = false;
        for (int j = 0 ; j < musicinfo.length() ; j++) {
            char c = musicinfo[j];
            if (c == ',' && flag) {
                tmp.push_back(musicinfo.substr(pos, j - pos));
                flag = false;
            } else {
                if (!flag) {
                    pos = j;
                    flag = true;
                }
            }
        }
        if (flag) tmp.push_back(musicinfo.substr(pos));
        
        int hour0 = 10 * tmp[0][0] + tmp[0][1];
        int hour1 = 10 * tmp[1][0] + tmp[1][1];
        
        int min0 = 10 * tmp[0][3] + tmp[0][4];
        int min1 = 10 * tmp[1][3] + tmp[1][4];
        
        int during0 = 60 * hour0 + min0;
        int during1 = 60 * hour1 + min1;
        
        int during = during1 - during0;
        
        string music, n_music;
        
        music = changeMusic(tmp[3]);
        
        for (int j = 0 ; j < during ; j++) {
            n_music += music[j % music.size()];
        }
        
        v.push_back(make_pair(tmp[2], n_music));
        
    }
    
    sort(v.begin(), v.end(), compare);
    
    m = changeMusic(m);
    
    for (int i = 0 ; i < v.size() ; i++) {
        for (int j = 0 ; j < v[i].second.length() ; j++) {
            if (m == v[i].second.substr(j, m.length())) return v[i].first;
        }
    }
    
    return "(None)";
}