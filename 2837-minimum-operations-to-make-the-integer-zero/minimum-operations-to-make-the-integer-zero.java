class Solution {
    public int makeTheIntegerZero(int a, int b) {
        for(int i=1;i<=60;i++){
            long target=(long)a-(long)i*b;
            if(target<i) continue;
            if(Long.bitCount(target)<=i) return i;
        }
        return -1;
    }
}