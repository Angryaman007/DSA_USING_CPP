#include <bits/stdc++.h>
using namespace std;
typedef long long alokLong;

int main() {
    int alokNumLines;
    cin >> alokNumLines;
    vector<vector<pair<int, int>>> alokPaths(alokNumLines);
    map<pair<int, int>, vector<int>> alokPointToSegmentsMap;

    // Input paths for each line segment
    for (int alokLineIndex = 0; alokLineIndex < alokNumLines; alokLineIndex++) {
        int alokX1, alokY1, alokX2, alokY2;
        cin >> alokX1 >> alokY1 >> alokX2 >> alokY2;

        int alokDeltaX = alokX2 - alokX1, alokDeltaY = alokY2 - alokY1;
        int alokStepCount = max(abs(alokDeltaX), abs(alokDeltaY));
        int alokStepX = (alokDeltaX == 0) ? 0 : alokDeltaX / abs(alokDeltaX);
        int alokStepY = (alokDeltaY == 0) ? 0 : alokDeltaY / abs(alokDeltaY);

        // Track all points in the segment path
        for (int alokStep = 0; alokStep <= alokStepCount; alokStep++) {
            int alokCurrentX = alokX1 + alokStepX * alokStep;
            int alokCurrentY = alokY1 + alokStepY * alokStep;
            alokPaths[alokLineIndex].emplace_back(make_pair(alokCurrentX, alokCurrentY));
            alokPointToSegmentsMap[{alokCurrentX, alokCurrentY}].emplace_back(alokLineIndex);
        }
    }

    string alokInput;
    getline(cin, alokInput); // Clear the buffer
    getline(cin, alokInput); // Read the next line
    unordered_map<string, int> alokValueMap;

    // Parsing input data into a map
    int alokPos = 0, alokInputLength = alokInput.size();
    while (alokPos < alokInputLength) {
        size_t alokColonPos = alokInput.find(':', alokPos);
        if (alokColonPos == string::npos) break;
        string alokKey = alokInput.substr(alokPos, alokColonPos - alokPos);
        alokPos = alokColonPos + 1;
        size_t alokSpacePos = alokInput.find(' ', alokPos);
        if (alokSpacePos == string::npos) alokSpacePos = alokInputLength;
        int alokValue = stoi(alokInput.substr(alokPos, alokSpacePos - alokPos));
        alokValueMap[alokKey] = alokValue;
        alokPos = alokSpacePos + 1;
    }

    string alokTarget;
    cin >> alokTarget;

    alokLong alokTotalCost = 0;

    // Calculate total overlap cost
    for (auto &alokEntry : alokPointToSegmentsMap) {
        if (alokEntry.second.size() >= 2) {
            int alokOverlapCount = alokEntry.second.size();
            int alokMinimumCost = INT_MAX;

            for (auto alokSegmentID : alokEntry.second) {
                auto &alokSegmentPath = alokPaths[alokSegmentID];
                size_t alokPathLength = alokSegmentPath.size();
                size_t alokIndex = find(alokSegmentPath.begin(), alokSegmentPath.end(), alokEntry.first) - alokSegmentPath.begin();
                int alokLeftMoves = alokIndex;
                int alokRightMoves = alokPathLength - alokIndex - 1;
                int alokMoveCost = (alokLeftMoves > 0 && alokRightMoves > 0) ? min(alokLeftMoves, alokRightMoves) : max(alokLeftMoves, alokRightMoves);
                alokMinimumCost = min(alokMinimumCost, alokMoveCost);
            }
            alokTotalCost += (alokLong)alokOverlapCount * alokMinimumCost;
        }
    }

    // Check if the accumulated cost meets the target condition
    if (alokValueMap.find(alokTarget) != alokValueMap.end()) {
        if (alokTotalCost >= alokValueMap[alokTarget]) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    } else {
        cout << "No\n";
    }

    // Calculate success rate for all keys
    int alokValidKeyCount = 0, alokTotalKeyCount = alokValueMap.size();
    for (auto &alokEntry : alokValueMap) {
        if (alokTotalCost >= alokEntry.second) {
            alokValidKeyCount++;
        }
    }

    // Output the success rate
    double alokSuccessRate = (double)alokValidKeyCount / alokTotalKeyCount;
    cout << fixed << setprecision(2) << alokSuccessRate;

    return 0;
}