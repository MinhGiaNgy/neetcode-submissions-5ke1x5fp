class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int chosen{0};
        for(int x = 0; x < matrix.size(); x++){
            if(matrix[x][0] <= target && matrix[x][matrix[x].size() - 1] >= target){
                chosen = x;
            }
        }
        vector<int> choice = matrix[chosen];
        int start = 0;
        int end = static_cast<int>(matrix[chosen].size()) - 1;
        while(start <= end){
            int mid = start + ((end - start) / 2);
            if(matrix[chosen][mid] < target){
                start = mid + 1;
            }
            else if(matrix[chosen][mid] == target){
                return 1;
            } else {
                end = mid - 1;
            }
            
        }
        return 0;
        
        
    }
};
