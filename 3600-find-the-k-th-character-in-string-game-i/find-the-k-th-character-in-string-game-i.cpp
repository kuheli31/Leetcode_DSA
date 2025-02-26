class Solution {
public:
    char kthCharacter(int k) {
        if (k == 1) return 'a';
        int len = 1;
        while (len < k) 
        {
            len = len*2;
        }
        int half = len / 2;
        if (k <= half) 
        {
            return kthCharacter(k);
        } 
        else 
        {
            char c = kthCharacter(k - half);
            return (c - 'a' + 1) % 26 + 'a';
        }
    }
};