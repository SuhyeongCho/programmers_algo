#include <vector>

using namespace std;

int count0 = 0;
int count1 = 0;

// 모두 0으로 같으면 0 반환, 모두 1로 같으면 1 반환, 다른 것이 있으면 -1 반환
int isEqualValues(const vector<vector<int>> &arr, int ys, int ye, int xs, int xe) {
    int cnt0 = 0, cnt1 = 0;
    for (int i = ys ; i < ye ; i++) {
        for (int j = xs ; j < xe ; j++) {
            if (arr[i][j] == 1) cnt1++;
            else cnt0++;
        }
    }
    
    if (cnt0 == 0) return 1;
    else if (cnt1 == 0) return 0;
    return -1;
}

void fn(const vector<vector<int>> &arr, int ys, int ye, int xs, int xe) {
    int isAllEqual = isEqualValues(arr, ys, ye, xs, xe);

    if (isAllEqual == 0) { count0++; return; }
    if (isAllEqual == 1) { count1++; return; }
    
    fn(arr, ys, (ys + ye) / 2, xs, (xs + xe) / 2);
    fn(arr, ys, (ys + ye) / 2, (xs + xe) / 2, xe);
    fn(arr, (ys + ye) / 2, ye, xs, (xs + xe) / 2);
    fn(arr, (ys + ye) / 2, ye, (xs + xe) / 2, xe);
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer;
    int n = arr.size();
    fn(arr, 0, n, 0, n);

    answer.push_back(count0);
    answer.push_back(count1);
    return answer;
}