class Solution {
public:
    // Check if a character is a vowel
    bool checkVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }

    int maxFreqSum(string s) {
        int n = s.size();
        unordered_map<char, int> mpp;

        // Count frequency of each character
        for (int i = 0; i < n; i++) {
            mpp[s[i]]++;
        }

        int vowel = 0, conso = 0;

        for (auto it : mpp) {
            if (checkVowel(it.first)) {
                vowel = max(vowel, it.second);
            } else {
                conso = max(conso, it.second);
            }
        }

        return vowel + conso;
    }
};
