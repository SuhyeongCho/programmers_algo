#include <vector>

using namespace std;

void push(vector<int> & v, int data) {
    int top = v.back();
    if (top == data) return;
    v.push_back(data);
    return;
}

vector<int> solution(vector<int> arr) {
    vector<int> answer;

    answer.push_back(arr[0]);
    for (int i = 1 ; i < arr.size() ; i++) {
        push(answer, arr[i]);
    }

    return answer;
}