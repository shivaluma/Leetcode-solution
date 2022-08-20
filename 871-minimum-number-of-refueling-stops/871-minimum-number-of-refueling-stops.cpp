class Solution {
public:
    // TIME COMPLEXITY:- O(NLOG(N))
    // SPACE COMPLEXITY:- O(N)
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations)
    {
        priority_queue<int> Fuels; // to keep track of gases being untaken in non increasing order
        stations.push_back({target,0});
        int max_reachable=startFuel,ans=0;
        for(int i=0;i<stations.size();i++){
            // refuel your vehicle till max_reachable becomes atleast current station coordinate
            while(!Fuels.empty() and max_reachable<stations[i][0]){
                ans++;
                max_reachable+=Fuels.top();
                Fuels.pop();
            }
            // if still max_reachable is not atleast current station coordinate, output -1
            if(max_reachable<stations[i][0])
                return -1;
            Fuels.push(stations[i][1]);
        }
        return ans;
    }
};