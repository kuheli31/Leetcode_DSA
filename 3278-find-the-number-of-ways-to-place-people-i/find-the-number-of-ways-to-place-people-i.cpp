class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int count=0;
        sort(points.begin(),points.end(),[&](vector<int>& pointA,vector<int>& pointB){
            int x1=pointA[0];
            int x2=pointB[0];
            int y1=pointA[1];
            int y2=pointB[1];

            if(x1==x2)
                return y1>y2;
            return x1<x2;
        });
        for(int pointA=0;pointA<points.size();pointA++){
            int maxY=INT_MIN;
            int x1=points[pointA][0];
            int y1=points[pointA][1];

            for(int pointB=pointA+1;pointB<points.size();pointB++){
                int x2=points[pointB][0];
                int y2=points[pointB][1];
                if(y2>y1)
                    continue;
                if(y2>maxY){
                    count++;
                    maxY=y2;
                }
            }
        }
        return count;
    }
};