class Solution {
public:
    vector<string> validStrings(int n) 
    {
        vector<string> result;

        result.push_back("0");
        result.push_back("1");

        if(n == 1) return result;

        for(int i=2;i<=n;i++)
        {
            vector<string> temp;
            for(string str : result)
            {
                if(str.back() == '1')
                {
                    temp.push_back(str + '0');
                    temp.push_back(str + '1');
                }
                else
                {
                    temp.push_back(str + '1');
                }
            }
            result=temp;
        }
        return result;
    }
};