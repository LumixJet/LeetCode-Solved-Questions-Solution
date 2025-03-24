class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) 
    {
        int n = meetings.size();

        sort(meetings.begin(),meetings.end()); //sort the meetings array wrt to first element 

        int res = 0; //to store total number of days without meetings
        int start = 0; //start from 0 day as this marks start of the day of current interval
        int end = 0; //end day as this marks end of the day of current interval 

        for(auto &meet : meetings) //traverse the meetings array
        {
            if(meet[0] > end) //if current start of interval is greater than end of previous interval
            {
                res += meet[0] -end - 1; //days between this two will be days without meetings so add to res
            }

            end = max(end, meet[1]); //compute end day which is till now max end day for event of meeting
        }
        if(days > end) //if total days given is more than last interval end then we find remaining left
        {                           //remaining days and store in res 
            res += days- end;
        }

        return res; //at last we return total number of days which were without meetings
    }
};