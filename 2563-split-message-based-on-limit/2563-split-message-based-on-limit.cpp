class Solution {
public:
    vector<string> splitMessage(string message, int limit) {
        vector<int>dig(10001),cum_sum(10001);// contains number of digits in N and cumulative sum of number of digits.
        // find number of digits in X.
        auto number_of_digits=[](int x){
            int ret = 0;
            while(x){
                ret++;
                x/=10;
            }
            return ret;
        };
        for(int i=1;i<=10000;i++){
            dig[i] = number_of_digits(i); 
            cum_sum[i] = cum_sum[i-1]+dig[i];
        }
        
        int actual_size = message.size();
        vector<string>ret;
        for(int N=1;N<=actual_size;N++){
            int newSize = actual_size+3*N+dig[N]*N+cum_sum[N];
            
            //check if possible to achieve the result.
            if((newSize+limit-1)/limit==N){
                string s;
                int cur = 1;
                //for each part we need to add <a/b> with it
                int extra = dig[N]+3;//as a part changes we do it in runtime
                for(char&c:message){
                    s+=c;
                    if(s.size()+dig[cur]+extra==limit){
                        s+="<"+to_string(cur)+"/"+to_string(N)+">";
                        ret.push_back(s);
                        s.clear();
                        cur++;
                    }
                }
                //if last part contains less than limit characters.
                if(s.size()){
                      s+="<"+to_string(cur)+"/"+to_string(N)+">";
                        ret.push_back(s);
                        s.clear();
                }
                return ret;
            }
        }
        return ret;
    }
};