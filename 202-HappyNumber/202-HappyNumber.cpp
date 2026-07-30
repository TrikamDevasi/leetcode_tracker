// Last updated: 30/07/2026, 10:23:42
class Solution {
public:
    bool isHappy(int n) {
        int slow = n;
        int fast = n;

        do {
            slow = getNext(slow);           // Moves 1 step
            fast = getNext(getNext(fast)); // Moves 2 steps
        } while (slow != fast);

        // If they meet at 1, it's a happy number
        return slow == 1;
    }

private:
    int getNext(int num) {
        int totalSum = 0;
        while (num > 0) {
            int digit = num % 10;
            totalSum += digit * digit;
            num /= 10;
        }
        return totalSum;
    }
};