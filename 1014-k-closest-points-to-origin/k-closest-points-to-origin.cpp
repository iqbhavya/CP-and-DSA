class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        using p = pair<float, int>;
        priority_queue<p, vector<p>, greater<p>> pq;

        for(int i = 0; i < points.size(); i++){
            float distance = sqrt(points[i][0]*points[i][0] + points[i][1]*points[i][1]);
            pq.push({distance,i});
        }

        vector<vector<int>> ans;

        for(int i = 0; i< k; i++){
            auto curr = pq.top(); 
            ans.push_back(points[curr.second]);
            pq.pop();
        }

        return ans;
    }
};