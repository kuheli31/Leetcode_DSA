class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n==0 || n==-1) return false;

        if(n%3==0 && isPowerOfThree(n/3)==1 || n==1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};