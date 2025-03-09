class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& basket) 
    {
        int i = 0;
        int j = 0;
        int n = basket.size();

        while(i<n) //traverse the fruits array
        {
            for(int j=0;j<n;j++) //tarverse the baskets array 
            {
                if(fruits[i] <= basket[j]) //if fruits are less than baskets 
                {
                    fruits[i] = -1; //we place the fruits at that respective baskets and mark 
                    basket[j] = -1; //both the cells -1 to represent that at corresponding basket fruit is placed
                    break;
                }
            }
            i++;
        }
        int cnt = 0;
        for(int i=0;i<n;i++) //traverse the fruits array
        {
                if(fruits[i] != -1) //if fruits array encounter number at any cell not equal to -1 
                {
                    cnt ++; //that means that fruit was not able to get placed in basket so we increase cnt
                }
        }
        return cnt; //finally we return cnt which is number of fruits that get unplaced
    }
};