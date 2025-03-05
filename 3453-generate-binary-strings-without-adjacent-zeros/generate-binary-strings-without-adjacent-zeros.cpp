class Solution {
public:
    void generateStrings(int n , string curr , vector<string>&result)
    {
        if(curr.size() == n) 
        {
            result.push_back(curr);
            return;
        }
        generateStrings(n,curr + '1',result);
        //Add 0 only if the last char is not 0
        if(curr.empty() || curr.back()!='0')
        {
            generateStrings(n,curr + '0',result);
        }
    }
    vector<string> validStrings(int n) 
    {
        vector<string> result;
        generateStrings(n, "", result);
        return result;
    }
};