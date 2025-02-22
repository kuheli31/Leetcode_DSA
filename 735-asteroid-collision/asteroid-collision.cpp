class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) 
    {
        int n = asteroids.size(); // Get the size of the asteroids array
        list<int> st; // Use a list to simulate a stack for asteroid collisions

        for(int i = 0; i < n; i++) // Iterate through each asteroid in the array
        {
            if(asteroids[i] > 0) // If the asteroid is moving to the right, push it to the list
            {
                st.push_back(asteroids[i]);
            }
            else // If the asteroid is moving to the left, check for collisions
            {
                while(!st.empty() && st.back() > 0 && st.back() < abs(asteroids[i])) 
                {
                    // Keep removing smaller right-moving asteroids until:
                    // - The stack is empty
                    // - A larger or equal-sized asteroid is encountered
                    st.pop_back();
                }

                if(!st.empty() && st.back() == abs(asteroids[i])) 
                {
                    // If the top asteroid has the same magnitude but opposite direction,
                    // both are destroyed, so remove the top asteroid
                    st.pop_back();
                    continue; // Skip pushing the negative asteroid since it's also destroyed
                }

                if(st.empty() || st.back() < 0) 
                {
                    // If there are no right-moving asteroids left in the stack,
                    // or the last asteroid is also moving left, push the new asteroid
                    st.push_back(asteroids[i]);
                }
            }
        }

        return vector<int>(st.begin(), st.end()); // Convert list to vector and return the result
    }
};
