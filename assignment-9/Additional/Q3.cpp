class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int,list<pair<int,int>>>graph;
        for(auto &t: times){
            int u=t[0],v=t[1],w=t[2];
            graph[u].push_back({v,w});
        }

        //distance array
        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;

        //set will store pair distance,nodes
        set<pair<int,int>>st;
        st.insert({0,k});

        while(!st.empty()){
            auto it=*st.begin();
            st.erase(st.begin());

            int time=it.first;
            int node=it.second;
            if(!graph.count(node))continue;
            for(auto &nbr:graph[node]){
                int v=nbr.first;
                int w=nbr.second;
                if(time+w<dist[v]){
                    if (dist[v] != INT_MAX) {
                        st.erase({dist[v], v});
                    }
                    // update distance
                    dist[v] = time + w;
                    st.insert({dist[v], v});
                }
            }
        }
        int maxTime = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == INT_MAX) return -1;   // unreachable
            maxTime = max(maxTime, dist[i]);
        }
        return maxTime;
    }
};
