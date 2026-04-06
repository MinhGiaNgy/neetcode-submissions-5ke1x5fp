class Solution {
public:
    int climbStairs(int n) {
        std::vector<int> total(n+1);
        if(n <= 2){
            return n;
        }
        total[0] = 0;
        total[1] = 1;
        total[2] = 2;
        for( int i = 3; i <= n; i++){
            total[i] = total[i-1] + total[i-2];
        }
        return total[n];
        
        
    }
};