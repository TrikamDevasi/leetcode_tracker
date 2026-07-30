// Last updated: 30/07/2026, 10:22:57
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st;
        
        for (int ast : asteroids) {
            bool destroyed = false;
            
            // Collision happens ONLY when the top of the stack moves RIGHT (+) 
            // and the current asteroid moves LEFT (-)
            while (!st.empty() && st.back() > 0 && ast < 0) {
                // If the top asteroid is smaller, it gets destroyed. 
                // The current asteroid continues to collide with previous ones.
                if (st.back() < abs(ast)) {
                    st.pop_back();
                    continue;
                } 
                // If they are equal in size, both explode.
                else if (st.back() == abs(ast)) {
                    st.pop_back();
                }
                
                // If the top asteroid is larger or equal, the current asteroid explodes.
                destroyed = true;
                break;
            }
            
            // If the current asteroid wasn't destroyed, push it to the stack
            if (!destroyed) {
                st.push_back(ast);
            }
        }
        
        return st;
    }
};