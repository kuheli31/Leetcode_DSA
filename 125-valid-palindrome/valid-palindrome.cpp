class Solution {
public:
    bool isPalindrome(string s) {
        int i;
        std::string ch; // Create a new string to hold valid characters
        std::transform(s.begin(), s.end(), s.begin(),
                       ::tolower); // Convert to lowercase

        // Filter out non-alphanumeric characters
        for (i = 0; i < s.size(); i++) {
            if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')) {
                ch.push_back(s[i]);
            }
        }

        // Reverse the filtered string
        std::string rev = ch;
        std::reverse(rev.begin(), rev.end());

        // Check if the filtered string is equal to its reverse
        if (rev == ch) {
            return true;
        } else {
            return false;
        }
    }
};