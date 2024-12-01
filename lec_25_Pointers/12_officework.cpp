#include <iostream>
#include <cstring>

#define MAX_PEOPLE 30

using namespace std;

int main() {
    int total_people, total_friendships, target_value;
    int connection[MAX_PEOPLE][MAX_PEOPLE] = {0}; 
    int current_state[MAX_PEOPLE]; 
    int next_state[MAX_PEOPLE];    

    cin >> total_people >> total_friendships;

    for (int i = 0; i < total_friendships; i++) {
        int person_a, person_b;
        cin >> person_a >> person_b;

        if (person_a < total_people && person_b < total_people) {
            connection[person_a][person_b] = 1;
            connection[person_b][person_a] = 1;
        }
    }

    cin >> target_value;

    for (int i = 0; i < total_people; i++) {
        current_state[i] = 1; 
    }

    int total_active = total_people; 
    int day_count = 1;

    while (total_active < target_value) {
        int daily_active = 0; 

        for (int i = 0; i < total_people; i++) {
            int active_friends = 0;

            for (int j = 0; j < total_people; j++) {
                if (connection[i][j] == 1 && current_state[j] == 1) {
                    active_friends++;
                }
            }

            if (current_state[i] == 1 && active_friends == 3) {
                next_state[i] = 1; 
            } else if (current_state[i] == 0 && active_friends < 3) {
                next_state[i] = 1; 
            } else {
                next_state[i] = 0;
            }

            if (next_state[i] == 1) {
                daily_active++;
            }
        }

        total_active += daily_active;
        memcpy(current_state, next_state, total_people * sizeof(int)); 
        day_count++;

        if (total_active >= target_value) {
            break;
        }
    }

    cout << day_count;

return 0;

}