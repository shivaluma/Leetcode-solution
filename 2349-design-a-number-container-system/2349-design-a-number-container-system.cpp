class NumberContainers {
public:
    map<int, int> mp;
    NumberContainers() 
    {

    }
    
    void change(int index, int number)
    {
        mp[index] = number;
    }
    
    int find(int number)
    {
       for(auto it: mp){
           if(it.second == number) return it.first;
       }
        
       return -1;
    }
};