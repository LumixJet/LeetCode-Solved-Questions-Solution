class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids)
    {
        vector<int> st;

        for(int a : asteroids){
            int destroyed = false;

            while(!st.empty() && a < 0 && st.back() > 0){
                if(st.back() < -a){
                    st.pop_back();
                    continue;
                }
                else if(st.back() == -a){
                    st.pop_back();
                }

                destroyed = true;
                break;
            }

            if(!destroyed){
                st.push_back(a);
            }
        }    

        return st;
    }
};