class Solution {
public:
    void reverseString(vector<char>& s) {
        int i, j;
        char t;
        int n = s.size(); // Get the size of the vector
        
        i = 0; 
        j = n - 1; // Set j to last index

        while (i < j)  // Swap characters until the middle is reached
        {
            t = s[i];
            s[i] = s[j];
            s[j] = t;
            i++;
            j--;
        }
    }
};