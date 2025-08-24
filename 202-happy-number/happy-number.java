import java.util.HashSet;

class Solution {
    // Helper function: calculate sum of squares of digits
    private int getNext(int n) {
        int total = 0;
        while (n > 0) {
            int digit = n % 10;
            total += digit * digit;
            n /= 10;
        }
        return total;
    }

    public boolean isHappy(int n) {
        HashSet<Integer> seen = new HashSet<>();
        
        while (n != 1 && !seen.contains(n)) {
            seen.add(n);          // store current number
            n = getNext(n);       // move to next number
        }
        
        return n == 1;
    }
}
