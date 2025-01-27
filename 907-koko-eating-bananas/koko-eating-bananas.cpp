class Solution {
public:
    int findMax(vector<int>& piles)
    {
        int maxi=0;
        for(int i=0 ; i<piles.size()  ; i++)
        {
            maxi=max(maxi , piles[i]);
        }
        return maxi;
    }

    long long calcTotalHours(vector<int>& piles , int mid)
    {
        long long totalHours = 0;
        for(int i=0 ; i<piles.size() ; i++)
        {
            totalHours += ceil((double)piles[i] / (double)mid);
        }
        return totalHours;
    }

    int minEatingSpeed(vector<int>& piles, int h) 
    {
        int low=1 , high=findMax(piles);

        while(low <= high)
        {
            long long mid=low + (high - low)/2;
            long long totalHours = calcTotalHours(piles , mid);
            if(totalHours <= h)
            {
                high = mid -1;
            }
            else
            {
                low = mid +1;
            }
        }
        return low; 
    }
};