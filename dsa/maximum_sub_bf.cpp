#include <chrono>
#include <iostream>
#include <vector>
#include <climits>
#include <iomanip>

class Solution 
{
    public:
    // Brute Force with Big(O) notation equals O(N^3)
    int maxSubArray(std::vector<int>& nums)
    {
        int maxSum = INT_MIN;
        for(int i = 0; i < nums.size(); i++){
            for(int j = i; j < nums.size(); j++){
                int sum = 0;
                for(int k = i; k <= j; k++){
                    sum += nums[k];
                }
                if(sum > maxSum) maxSum = sum;
            }
        }
        return maxSum;
    }
    // Brute Force with Big(O) notation equals O(N^2)
    void printSubarray(std::vector<int>& nums)
    {
        std::vector<int> result;
        int sum = INT_MIN;
        for(int i = 0; i < nums.size(); i++){
            int curSum = 0;
            for(int j = i; j < nums.size(); j++){
                curSum += nums[j];
                if(curSum > sum) {
                    sum = curSum;
                    result.clear();
                    for(int k = i; k <= j; k++) result.push_back(nums[k]);
                }
            }
        }
        // std::cout << "The subarray [";
        // for (int i = 0; i < result.size(); i++) {
        //     std::cout << result[i];
        //     if(i < result.size() - 1) std::cout << ", ";
        // }

        // std::cout << "] has the largest sum " << sum << std::endl;
        std::cout << sum;
    }
    // Or
    int maxSubArray1(std::vector<int>& nums) {
        int maxSum = INT_MIN;
        for(int i = 0; i < nums.size(); i++){
            int currentSum = 0;
            for(int j = i; j < nums.size(); j++){
                currentSum += nums[j];
                if(currentSum > maxSum) {
                    maxSum = currentSum;
                }
            }
        }
        return maxSum;
    }
};
int main()
{
    int n;
    if (!(std::cin >> n) || n <= 0) {
        std::cerr << "N must be a positive integer.\n";
        return 1;
    }

    std::vector<int> nums(n);
    for (int& x : nums) {
        std::cin >> x;
    }

    Solution solution;

    const auto start = std::chrono::steady_clock::now();
    const int result = solution.maxSubArray(nums);
    const auto end = std::chrono::steady_clock::now();

    const auto start1 = std::chrono::steady_clock::now();
    const int result1 = solution.maxSubArray1(nums);
    const auto end1 = std::chrono::steady_clock::now();

    const std::chrono::duration<double, std::milli> runtime =
        end - start;
    const std::chrono::duration<double, std::milli> runtime1 =
        end - start;

    std::cout << result << '\n'
              << "Big(O) - O(N^3) runtime: " << std::fixed << std::setprecision(3)
              << runtime.count() << " ms\n"
              << result1 << '\n'
              << "Big(O) - O(N^2) runtime: " << runtime1.count() << " ms\n";

    return 0;
}
