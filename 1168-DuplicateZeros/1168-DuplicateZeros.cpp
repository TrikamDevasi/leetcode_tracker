// Last updated: 30/07/2026, 10:22:35
class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n = arr.size();
        int possible_dups = 0;
        int length_to_keep = n - 1;

        for (int i = 0; i <= length_to_keep - possible_dups; i++) {
            if (arr[i] == 0) {
                if (i == length_to_keep - possible_dups) {
                    arr[n - 1] = 0;
                    n -= 1;
                    break;
                }
                possible_dups++;
            }
        }

        int last = n - 1 - possible_dups;

        for (int i = last; i >= 0; i--) {
            if (arr[i] == 0) {
                arr[i + possible_dups] = 0;
                possible_dups--;
                arr[i + possible_dups] = 0;
            } else {
                arr[i + possible_dups] = arr[i];
            }
        }
    }
};