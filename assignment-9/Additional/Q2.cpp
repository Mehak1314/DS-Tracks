class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        if(heights.empty()){
            return 0;
        }
        typedef pair<int,pair<int,int>>p;
        vector<vector<int>>dirs={{-1,0},{1,0},{0,-1},{0,1}};
        int m = heights.size();
        int n = heights[0].size();

        auto isSafe =[&](int x,int y){
            return x>=0 && x<m && y>=0 && y<n;
        };

        vector<vector<int>>result(m,vector<int>(n,INT_MAX));
        priority_queue<p,vector<p>,greater<p>>pq;
        result[0][0]=0;
        pq.push({0,{0,0}});

        while(!pq.empty()){
            int diff=pq.top().first;
            auto coord=pq.top().second;
            pq.pop();
            int x=coord.first;
            int y=coord.second;
            for(auto &dir:dirs){
                int x_ =x+dir[0];
                int y_=y+dir[1];

                if(isSafe(x_,y_)){
                    int absdiff=abs(heights[x][y]-heights[x_][y_]);
                    int maxdiff= max(diff,absdiff);
                    if(result[x_][y_]>maxdiff){
                        result[x_][y_]=maxdiff;
                        pq.push({maxdiff,{x_,y_}});
                    }
                }
            }
        }
        return result[m-1][n-1];
    }
};
