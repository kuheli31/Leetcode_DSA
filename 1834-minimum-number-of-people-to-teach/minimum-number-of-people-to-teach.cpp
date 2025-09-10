class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int m=languages.size();

        vector<unordered_set<int>>langSet(m+1);
        for(int i=0;i<m;i++){
            for(int l:languages[i]){
                langSet[i+1].insert(l);
            }

        }
        unordered_set<int>needTeach;
        for(auto &f:friendships){
            int u=f[0],v=f[1];
            bool canCommunicate=false;
            for(int l:langSet[u]){
                if(langSet[v].count(l)){
                    canCommunicate=true;
                    break;
                }
            }
            if(!canCommunicate){
                needTeach.insert(u);
                needTeach.insert(v);
            }
        }
        if(needTeach.empty())return 0;

        vector<int>langCount(n+1,0);
        for(int person:needTeach){
            for(int l:langSet[person]){
                langCount[l]++;
            }
        }
        int maxKnown=0;
        for(int l=1;l<=n;l++){
            maxKnown=max(maxKnown,langCount[l]);
        }
        return(int)needTeach.size()-maxKnown;
    }
};