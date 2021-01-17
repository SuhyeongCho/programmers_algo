#include <string>
#include <vector>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    
    if (cacheSize == 0) return 5 * cities.size();
    
    for (int i = 0 ; i < cities.size() ; i++) {
        for (int j = 0 ; j < cities[i].length() ; j++) {
            if (cities[i][j] >= 'A' && cities[i][j] <= 'Z'){
                cities[i][j] = cities[i][j] - 'A' + 'a';
            }
        }
    }
    
    vector<pair<string, int>> cache(cacheSize, make_pair("", -1));
    
    bool flag = false;
    for (int i = 0 ; i < cities.size() ; i++) {
        string city = cities[i];
        for (int j = 0 ; j < cacheSize ; j++) {
            if (city == cache[j].first) {
                answer += 1;
                cache[j].second = i;
                flag = true;
                continue;
            }
        }
        
        if (flag) {
            flag = false;
            continue;
        }
        
        int least = 0;
        for (int j = 1 ; j < cacheSize ; j++) {
            if (cache[least].second > cache[j].second) {
                least = j;
            }
        }
        
        cache[least].first = city;
        cache[least].second = i;
        answer += 5;
    }
    
    return answer;
}