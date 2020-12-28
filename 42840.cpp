#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int N = answers.size();
    
    int count1 = 0;
    int count2 = 0;
    int count3 = 0;
    
    int arr1[5] = {1,2,3,4,5};
    int arr2[8] = {2,1,2,3,2,4,2,5};
    int arr3[10] = {3,3,1,1,2,2,4,4,5,5};
    
    for (int i = 0 ; i < N ; i++) {
        int d = answers[i];
        int pos1 = i % 5;
        int pos2 = i % 8;
        int pos3 = i % 10;
        
        if (d == arr1[pos1]) count1++;
        if (d == arr2[pos2]) count2++;
        if (d == arr3[pos3]) count3++;
    }
    
    int max = 0;
    answer.push_back(1);
    max = count1;
    
    if (max == count2) answer.push_back(2);
    else if (max < count2) {
        answer.clear();
        answer.push_back(2);
        max = count2;
    }
    
    if (max == count3) answer.push_back(3);
    else if (max < count3) {
        answer.clear();
        answer.push_back(3);
    }
    
    return answer;
}