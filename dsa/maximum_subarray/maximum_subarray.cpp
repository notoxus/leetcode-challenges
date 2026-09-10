#include <algorithm>
#include <iostream>
#include <vector>
#include <chrono>
#include <iomanip>

class Solution 
{
public:
    // Kanade algorithm - DP
    int maxSubArray(std::vector<int>& nums) 
    {
        int currentSum = nums[0];
        int maxSum = nums[0];

        for (std::size_t i = 1; i < nums.size(); ++i) 
        {
            // Either extend the previous subarray or start a new one here.
            currentSum = std::max(nums[i], currentSum + nums[i]);
            maxSum = std::max(maxSum, currentSum);
        }

        return maxSum;
    }
};
int main() 
{
    int n;
    std::cin >> n;
    std::vector<int> nums(n);
    for (int& x : nums) std::cin >> x;
    Solution solution;
    const auto start = std::chrono::steady_clock::now();
    int result = solution.maxSubArray(nums);
    const auto end = std::chrono::steady_clock::now();
    const std::chrono::duration<double, std::milli> runtime =
        end - start;
    std::cout << result << '\n' << "Big O - O(n) runtime: "
              << std::fixed << std::setprecision(3) << runtime.count() << " ms\n";
    return 0;
}
