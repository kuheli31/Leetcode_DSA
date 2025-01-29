class Solution {
public:
    int dayFinder(vector<int>& weights, int capacity)
    {
        int day=1;
        int load=0;
        int n=weights.size();
        for(int i=0 ; i<n ;i++)
        {
            if(load + weights[i] > capacity)
            {
                day+=1;
                load=weights[i];
            }
            else
            {
                load+=weights[i];
            }
        }
        return day;
    }
    int shipWithinDays(vector<int>& weights, int days) 
    {
        int n=weights.size();
        int maximum = *max_element(weights.begin() , weights.end());
        int sum=accumulate(weights.begin() , weights.end() ,0);
        int i ;
        long long low=maximum;
        long long high=sum;

        while(low<=high)
        {
            int mid= low +(high - low)/2;
            if(dayFinder(weights,mid) <= days)
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