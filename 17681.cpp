#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    for (int i = 0 ; i < n ; i++) {
        string row = "";
        int d = arr1[i] | arr2[i];
        for (int j = 0 ; j < n ; j++) {
            if (d % 2) row = "#" + row;
            else row = " " + row;
            d /= 2;
        }
        answer.push_back(row);
    }
    return answer;
}