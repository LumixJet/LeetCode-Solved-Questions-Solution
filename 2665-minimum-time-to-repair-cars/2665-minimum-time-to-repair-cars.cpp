class Solution {
public:
    bool isPossible(vector<int> &ranks, long long mid, int cars)
    {
        int n = ranks.size();
        long long count = 0;

        for(int i=0;i<n;i++)
        {
            count += sqrt(mid / ranks[i]); //check each mechanic repair how many cars with this time frame
        }
        return count >= cars; //if in this time total cars got repaired is more or equal to given no. of cars 
    }                        //then this is possible time we need to minimize it 
                                             
    long long repairCars(vector<int>& ranks, int cars) 
    {
        int n = ranks.size();
        long long ans = -1;

        int maxi = *max_element(ranks.begin(), ranks.end()); //maxRank mechanic will take max time to repair

        long long low = 1; //minimum time taken by a mechanic to repair the car is 1 
        long long high = 1LL * maxi * cars * cars; //max time for mechanic can be taken to repair all cars

        while(low <= high)
        {
            long long mid = (low + high) / 2; //time to repair all the cars by the mechanic 

            if(isPossible(ranks,mid,cars)) //check with this time mid all cars can be repaired or not
            {
                ans = mid; //if mid time is possible ans then to minimize it we make high as mid - 1
                high = mid - 1;
            }
            else //if mid time is not ans then we need to increase the time so we make low as mid + 1
            {
                low = mid + 1;
            }
        }
        return ans; //finally we return min time which is required to repair all no.s of given cars 
    }
};