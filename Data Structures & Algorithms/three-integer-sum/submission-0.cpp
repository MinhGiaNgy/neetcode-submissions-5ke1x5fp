class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        set<vector<int>> output; 
        vector<vector<int>> finaloutput;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++){
            int j = i + 1;
            int k = nums.size() - 1;
            while(k > j){
                if(nums[i] > 0){
                    break;
                }

                int sum = nums[i] + nums[j] + nums[k];
                if(sum == 0){
                    output.insert({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                }
                else if(sum < 0){
                    j++;

                } else {
                    k--;
                }

            }

        }
        for(auto out : output){
            finaloutput.push_back(out);
        }
        return finaloutput;


















        // std::map<int, int> m;
        // for (int i = 0; i < nums.size(); i++) {
        //     m[i + 1] = nums[i];
        // }
        
        // std::map<std::vector<int>, bool> m2;  
        // std::vector<int> output;
        // std::vector<std::vector<int>> final_output;
        // bool Exist = false;
        // for (int i = 0; i < nums.size(); i++) {
        //     for (int j = i + 1; j < nums.size(); j++) {
        //         int third = -(nums[i] + nums[j]); 
        //         for (const auto& pair : m) {
        //             if (pair.second == third && pair.first - 1 != i && pair.first - 1 != j) { 
        //                 Exist = true;
        //                 break;
        //             }
        //         }
                
        //         if (Exist == true) {
        //             output = {nums[i], nums[j], third};
        //             std::sort(output.begin(), output.end());  
                    
        //             if (m2.find(output) == m2.end()) {
        //                 m2[output] = true;
        //                 final_output.push_back(output);
        //             }
                    
        //             output.clear();
        //             Exist = false;  
        //         }
        //     }
        // }
        
        // return final_output;
    }
};