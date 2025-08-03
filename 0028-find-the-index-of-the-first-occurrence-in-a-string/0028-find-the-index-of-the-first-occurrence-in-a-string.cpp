#define d 256
const int q = 101;

class Solution {
public:
    int strStr(string txt, string pat) 
    {
        int n = txt.size();
        int m = pat.size(); 

        int h = 1;
        for(int i=0;i<m-1;i++) 
        {                     
            h = (h * d) % q;
        }
        
        int p = 0;
        int t = 0;

        for(int i=0;i<m;i++) 
        {           
            p = (p * d + pat[i]) % q; 
            t = (t * d + txt[i]) % q;
        }

        for(int i=0;i<=n-m;i++)
        {
            if(p == t)
            {
                bool flag = true; 
                
                for(int j=0;j<m;j++) 
                {
                    if(pat[j] != txt[i+j]) 
                    {
                        flag = false; 
                        break;
                    }
                }
                
                if(flag) 
                {
                   return i;
                }
            }
            if(i < n-m)
            {
                t = ((d * (t - txt[i] * h)) + txt[i + m]) % q; 
                
                if(t < 0)
                {
                    t = t + q;
                }
            }
        }
        return -1;
    }
};