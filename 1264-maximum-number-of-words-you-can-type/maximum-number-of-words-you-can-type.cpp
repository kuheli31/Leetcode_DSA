class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        vector<bool> broken(26, false);
        for (char c : brokenLetters) {
            broken[c - 'a'] = true;
        }
        stringstream ss(text);
        string curr;
        int res = 0;
        while (getline(ss, curr, ' ')) {
            bool possible = true;
            for (char c : curr) {
                if (broken[c - 'a']) {
                    possible = false;
                    break;
                }
            }
            res += possible;
        }
        return res;
    }
};