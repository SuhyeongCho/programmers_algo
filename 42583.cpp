#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int current_time = 0;
    queue<int> wait_trucks;
    queue<pair<int,int>> running_trucks;
    
    for (int i = 0 ; i < truck_weights.size() ; i++) {
        wait_trucks.push(truck_weights[i]);
    }
    
    int total_weight = 0;
    while(true) {
        if (wait_trucks.empty() && running_trucks.empty()) break;
        // 활동트럭 명단에서 제거
        if (!running_trucks.empty()) {
            int running_truck_weight = running_trucks.front().first;
            int start_time = running_trucks.front().second;
            if (current_time - start_time >= bridge_length) {
                running_trucks.pop();
                total_weight -= running_truck_weight;
            }
        }
        // 대기트럭 명단에서 활동트럭 명단으로 이동
        if (!wait_trucks.empty()) {
            int wait_truck_weight = wait_trucks.front();
            if (total_weight + wait_truck_weight <= weight) {  
                running_trucks.push(make_pair(wait_truck_weight, current_time));
                total_weight += wait_truck_weight;
                wait_trucks.pop();
            }
        }
        current_time++;
    }
    return current_time;
}