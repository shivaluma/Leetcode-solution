class FrequencyTracker {
public:
    unordered_map<int,int> freq;
    unordered_map<int,int> freq_count;
    FrequencyTracker() {
        
    }
    
    void add(int number) {  

        if (freq_count[freq[number]] > 0) {
            freq_count[freq[number]]--;
        }
        
        freq[number]++;
        freq_count[freq[number]]++;
    }
    
    void deleteOne(int number) {
        if (freq_count[freq[number]] > 0) {
            freq_count[freq[number]]--;
        }
        
        if (freq[number] > 0) {
            freq[number]--;
        }

        freq_count[freq[number]]++;
    }
    
    bool hasFrequency(int frequency) {
        return freq_count[frequency] > 0;
    }
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */