class Solution {
public:
    int compress(vector<char>& chars) {
        

        char prev = chars[0];
        int count = 0;
        int c_idx = 0;
        for (int i = 0; i < chars.size(); i++) {
            if ((chars[i] != prev && i != 0)) {

                chars[c_idx++] = (char)(prev);

                if (count > 1) {
                    string countinstring = to_string(count);
                    for (int k = 0; k < countinstring.length(); k++) {
                        chars[c_idx++] = countinstring[k]; 
                    }
                }

                count = 0;

            }

            count++;
            prev = chars[i];
        }

        if (count > 0) {
            chars[c_idx++] = (char)(prev);
            
            if (count > 1) {
                string countinstring = to_string(count);
                for (int k = 0; k < countinstring.length(); k++) {
                    chars[c_idx++] = countinstring[k]; 
                }
            }
        }

        return c_idx;
            
    }

};