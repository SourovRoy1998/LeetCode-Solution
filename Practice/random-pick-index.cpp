//https://leetcode.com/problems/random-pick-index/


class Solution {
public:
    vector<int> numbers;
    Solution(vector<int>& nums) {
        this->numbers=nums;
    }
    
    int pick(int target) {
        int count=0,ret;
        for(int i=0;i<numbers.size();i++){
            if(numbers[i]==target){
                count++;
                if(rand()%count==0)
                    ret=i;
            }
        }
        return ret;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
