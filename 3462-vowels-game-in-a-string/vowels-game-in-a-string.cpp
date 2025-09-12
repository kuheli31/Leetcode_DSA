class Solution {
public:
    bool doesAliceWin(string s) {
        int ans=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'){
                ans++;
            }
        }


        if(ans!=0){
            return 1;
        }
        return 0;
    }
};