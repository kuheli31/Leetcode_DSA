class Solution {
public:
    bool isAnagram(string s, string t) {
        int n1 = s.size();
        int n2 = t.size();
        vector<int> mark(26, 0);
        if (n1 != n2)
            return false;
        for (int i = 0; i < n1; i++) {
            mark[s[i] - 'a']++;
        }
        for (int j = 0; j < n2; j++) {
            mark[t[j] - 'a']--;
        }
        for (int i = 0; i < 26; i++) {
            if (mark[i] != 0)
                return false;
        }
        return true;
    }
};