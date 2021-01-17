#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int N = 0;
int M = 0;
vector<vector<int>> uniqs;

void fn(const vector<vector<string>> &relation, vector<int> v, int pos) {
    if (pos == M) {
        set<vector<string>> s;
        for (int i = 0 ; i < N ; i++) {
            vector<string> tmp;
            for (int j = 0 ; j < v.size() ; j++) {
                tmp.push_back(relation[i][v[j]]);
            }
            s.insert(tmp);
        }
        
        if (s.size() == N && !v.empty()) uniqs.push_back(v);
      
        return;
    }
    
    v.push_back(pos);
    fn(relation, v, pos + 1);
    
    v.pop_back();
    fn(relation, v, pos + 1);
}

bool compare(const vector<int> &a, const vector<int> &b) {
    return a.size() < b.size();
}

int solution(vector<vector<string>> relation) {
    int answer = 0;
    N = relation.size();
    M = relation[0].size();
    
    vector<int> v;
    
    fn(relation, v, 0);
    
    sort(uniqs.begin(), uniqs.end(), compare);
        
    vector<bool> isMinimal(uniqs.size(), true);
    
    for (int i = 0 ; i < uniqs.size() ; i++) {
        for (int j = i + 1; j < uniqs.size() ; j++) {
            if (!isMinimal[j]) continue;
            
            vector<int> v1 = uniqs[i];
            vector<int> v2 = uniqs[j];
            
            int cnt = 0;
            for(int ii = 0 ; ii < v1.size() ; ii++) {
                for (int jj = 0 ; jj < v2.size() ; jj++) {
                    if (v1[ii] == v2[jj]) {
                        cnt++;
                        continue;
                    }
                }
            }
            
            if (cnt == v1.size()) isMinimal[j] = false;
        }
    }
    
     for (int i = 0 ; i < uniqs.size() ; i++) {
        if (isMinimal[i]) answer++;
    }
    
    return answer;
}