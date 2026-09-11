#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
#include <chrono>
#include <iomanip>

class Solution {
public:
    int maxSubArray(std::vector<int>& nums)
    {
        return maxSubarray(nums, 0, static_cast<int>(nums.size()) - 1);
    }
private:
    int maxSubarray(const std::vector<int>& nums, int low, int high)
    {
        if (low == high) return nums[low];
        const int mid = low + (high - low) / 2;
        const int wL = maxSubarray(nums, low, mid);
        const int wR = maxSubarray(nums, mid + 1, high);
        const int wM = maxCrossMidPoint(nums, low, mid, high);

        return std::max({wL, wR, wM});
    }

    int maxCrossMidPoint(const std::vector<int>& nums, int low, int mid,
                         int high)
    {
        int sum = 0;
        int bestLeft = INT_MIN;
        for (int i = mid; i >= low; --i)
        {
            sum += nums[i];
            bestLeft = std::max(bestLeft, sum);
        }
        sum = 0;
        int bestRight = INT_MIN;
        for (int i = mid + 1; i <= high; ++i)
        {
            sum += nums[i];
            bestRight = std::max(bestRight, sum);
        }
        return bestLeft + bestRight;
    }
    // // Or you can also split maxCrossMidPoint to 2 functions
    // int maxLeft(const std::vector<int>& nums, int low, int high){
    //     int sum = 0;
    //     int maxLeft = INT_MIN;
    //     for (int i = high; i >= low; --i)
    //     {
    //         sum += nums[i];
    //         maxLeft = std::max(maxLeft, sum);
    //     }
    //     return maxLeft;
    // }
    // int maxRight(const std::vector<int>& nums, int low, int high){
    //     int sum = 0;
    //     int maxRight = INT_MIN;
    //     for (int i = low; i <= high; i++)
    //     {
    //         sum += nums[i];
    //         maxRight = std::max(maxRight, sum);
    //     }
    //     return maxRight;
    // }
    // int maxSubarray(const std::vector<int>& nums, int low, int high)
    // {
    //     if (low == high) return nums[low];
    //     const int mid = low + (high - low) / 2;
    //     const int wL = maxSubarray(nums, low, mid);
    //     const int wR = maxSubarray(nums, mid + 1, high);
    //     const int wM = maxLeft(nums, low, mid) + maxRight(nums, mid+1, high);
    //     return std::max({wL, wR, wM});
    // }
};

int main()
{
    int n;
    if (!(std::cin >> n) || n <= 0)
    {
        std::cerr << "N must be a positive integer.\n";
        return 1;
    }

    std::vector<int> nums(n);
    for (int& value : nums)
    {
        if (!(std::cin >> value))
        {
            std::cerr << "Expected " << n << " array elements.\n";
            return 1;
        }
    }

    Solution solution;
    const auto start = std::chrono::steady_clock::now();
    const int result = solution.maxSubArray(nums);
    const auto end = std::chrono::steady_clock::now();
    const std::chrono::duration<double, std::milli> runtime =
        end - start;
    std::cout << result << '\n'
              << "Big(O) - O(nlogn) runtime:" << std::fixed << std::setprecision(3)
              << runtime.count() << " ms\n";
    return 0;
}
