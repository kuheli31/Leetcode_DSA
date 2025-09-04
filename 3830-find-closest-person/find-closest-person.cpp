class Solution {
public:
    int findClosest(int x, int y, int z) 
    {
        int diffx , diffy;
        //x can come first
        diffx= abs(z - x);
        //y can come first
        diffy= abs(z - y);

        if(diffx < diffy)
        {
            return 1;
        }
        else if(diffy == diffx)
        {
            return 0;
        }
        else
        {
            return 2;
        }
    }
};