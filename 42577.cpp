#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    sort(phone_book.begin(), phone_book.end());
    
    int len = phone_book.size();
    for (int i = 0 ; i < len ; i++) {
        string pivot = phone_book[i];
        int p_len = pivot.length();
        for (int j = i + 1 ; j < len ; j++) {
            if (pivot == phone_book[j].substr(0, p_len)) return false;
        }
    }
    return answer;
}