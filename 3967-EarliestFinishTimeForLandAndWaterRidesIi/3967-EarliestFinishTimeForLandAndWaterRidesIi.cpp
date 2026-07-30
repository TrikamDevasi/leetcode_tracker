// Last updated: 30/07/2026, 10:21:31
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
private:
    struct Ride {
        int start;
        int duration;
        int finish; // start + duration
    };

    long long checkOrder(const vector<int>& start1, const vector<int>& dur1, const vector<int>& start2, const vector<int>& dur2) {
        int n = start1.size();
        int m = start2.size();

        // 1. Package and sort the second ride category by start times
        vector<Ride> rides2(m);
        for (int i = 0; i < m; ++i) {
            rides2[i] = {start2[i], dur2[i], start2[i] + dur2[i]};
        }
        sort(rides2.begin(), rides2.end(), [](const Ride& a, const Ride& b) {
            return a.start < b.start;
        });

        // 2. Precompute Prefix Minimum of Durations for early arrivals
        vector<int> prefMinDur(m);
        prefMinDur[0] = rides2[0].duration;
        for (int i = 1; i < m; ++i) {
            prefMinDur[i] = min(prefMinDur[i - 1], rides2[i].duration);
        }

        // 3. Precompute Suffix Minimum of Finish Times for late arrivals
        vector<int> suffMinFinish(m);
        suffMinFinish[m - 1] = rides2[m - 1].finish;
        for (int i = m - 2; i >= 0; --i) {
            suffMinFinish[i] = min(suffMinFinish[i + 1], rides2[i].finish);
        }

        long long minTotalFinish = LLONG_MAX;

        // 4. Evaluate each ride from the first category
        for (int i = 0; i < n; ++i) {
            long long f1 = (long long)start1[i] + dur1[i];

            // Binary search to find the first ride in group 2 that opens AFTER f1
            // We search based on the ride's starting time
            int low = 0, high = m - 1;
            int idx = m; // Default if all elements have start <= f1

            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (rides2[mid].start > f1) {
                    idx = mid;
                    high = mid - 1; // Try to find an even earlier late-opener
                } else {
                    low = mid + 1;
                }
            }

            // Case A: There are rides that open before or exactly at f1 (Indices 0 to idx - 1)
            if (idx > 0) {
                minTotalFinish = min(minTotalFinish, f1 + prefMinDur[idx - 1]);
            }

            // Case B: There are rides that open strictly after f1 (Indices idx to m - 1)
            if (idx < m) {
                minTotalFinish = min(minTotalFinish, (long long)suffMinFinish[idx]);
            }
        }

        return minTotalFinish;
    }

public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        // Evaluate both paths: Land -> Water and Water -> Land
        long long option1 = checkOrder(landStartTime, landDuration, waterStartTime, waterDuration);
        long long option2 = checkOrder(waterStartTime, waterDuration, landStartTime, landDuration);
        
        return min(option1, option2);
    }
};