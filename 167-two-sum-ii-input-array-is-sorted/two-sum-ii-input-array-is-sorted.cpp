class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size() - 1;
        
        while (left < right) {
            int sum = numbers[left] + numbers[right];
            if (sum == target) {
                return {left + 1, right + 1}; // Convert to 1-based index
            } else if (sum < target) {
                left++; // Move left pointer right to increase sum
            } else {
                right--; // Move right pointer left to decrease sum
            }
        }
        
        return {}; // This line should never be reached as per problem constraints
    }
};
