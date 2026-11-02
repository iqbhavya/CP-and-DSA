class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int,int>> p;
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
                if(matrix[i][j] == 0){
                    p.push_back({i,j});
                }
            }
        }

        for(int i = 0; i < p.size(); i++){
            int row = p[i].first;
            for(int j = 0; j < matrix[0].size(); j++){
                matrix[row][j] = 0;
            }
        }

        for(int i = 0; i < p.size(); i++){
            int col = p[i].second;
            for(int j = 0; j < matrix.size(); j++){
                matrix[j][col] = 0;
            }
        }

        
    }
};