class Solution {
public:
    bool isPalindrome(int x) 
    {
        // Negative numbers are not palindromes
        if (x < 0) 
        {
            return false;
        }
        long rev=0;
        long num=x;
        while(x!=0)
        {
            int ld=x%10;
            rev=rev*10+ld;
            x=x/10;
        }
        if(num==rev)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
};