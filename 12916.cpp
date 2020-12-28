#include <string>

using namespace std;

bool solution(string s) {
    int count1 = 0, count2 = 0;
    int len = s.length();
    for (int i = 0 ; i < len ; i++) {
        if (s[i] == 'p' || s[i] == 'P') count1++;
        if (s[i] == 'y' || s[i] == 'Y') count2++;
    }

    return count1 == count2;
}