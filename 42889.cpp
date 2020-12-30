#include <vector>
#include <algorithm>

using namespace std;

bool compare(const pair<double, int> &a, const pair<double, int> &b)
{
    if (a.first == b.first) return a.second < b.second;
    return a.first > b.first;
}

vector<int> solution(int N, vector<int> stages) {
    sort(stages.begin(), stages.end());
    vector<int> set(N + 2 , 0);
    
    for (int i = 0 ; i < stages.size() ; i++) {
        set[stages[i]]++;
    }
    
    int challenger = stages.size();
    vector<pair<double, int>> rates;
    
    for (int i = 1 ; i <= N ; i++) {
        double rate = (double)set[i] / challenger;
        if (challenger <= 0) rate = 0;
        challenger -= set[i];
        rates.push_back(make_pair(rate, i));
    }
    
    sort(rates.begin(), rates.end(), compare);

    vector<int> answer;
    for (int i = 0 ; i < rates.size() ; i++) {
        answer.push_back(rates[i].second);
    }
    return answer;
}