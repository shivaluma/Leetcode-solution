class uf{
    public:
    unordered_map<int,int>parent,rank;
    uf(vector<int>&nums){
        for(auto & i:nums){
            parent[i]=i;
            rank[i]=1;
        }
    }
    int find(int ele){
        if(parent[ele]==ele)
            return ele;
        return parent[ele]=find(parent[ele]);
    }
    void un(int a,int b){
        int p1=find(a),p2=find(b);
        if(p1==p2)
            return;
        if(rank[p2]>=rank[p1])
            swap(p2,p1);
        parent[p2]=p1;
        rank[p1]=rank[p1]+rank[p2];
    }
    int ans(){
        int res=0;
        for(auto & [u,v]:rank)
          res=max(res,v);  
        return res;
    }
};

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        uf ob(nums);
        unordered_set<int>seen;
        for(auto & i:nums){
            if(seen.count(i-1))
                ob.un(i,i-1);
            if(seen.count(i+1))
                ob.un(i,i+1);
            seen.insert(i);
        }
        return ob.ans();
    }
};