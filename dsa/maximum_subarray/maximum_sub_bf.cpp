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
        int maxSum = INT_MIN; // -2^31
        for(int i = 0; i < nums.size(); i++)
        {
            for(int j = i; j < nums.size(); j++)
            {
                int sum = 0;
                for(int k = i; k <= j; k++)
                {
                    sum += nums[k];
                }
                if(sum > maxSum) maxSum = sum;
            }
        }
        return maxSum;
    }
    // Brute Force with Big(O) notation equals O(N^2)
    int maxSubArray1(std::vector<int>& nums) 
    {
        int maxSum = INT_MIN; // you can also use int maxSum = nums[0]; instead
        for(int i = 0; i < nums.size(); i++)
        {
            int sum = 0;
            for(int j = i; j < nums.size(); j++)
            {
                sum += nums[j];
                if(sum > maxSum) maxSum = sum;
            }
        }
        return maxSum;
    }
    // And if you want to print their result
    void printSubarray(std::vector<int>& nums)
    {
        int maxSum = INT_MIN;
        int startIndex = 0;
        int endIndex = 0;

        for (int i = 0; i < nums.size(); i++) 
        {
            int sum = 0;

            for (int j = i; j < nums.size(); j++) 
            {
                sum += nums[j];

                if (sum > maxSum) {
                    maxSum = sum;
                    /* 
                    Avoid copying the subarray every time maxSum changes like that:
                    result.clear(); 
                    for(int k = i; k <= j; k++) result.push_back(nums[k]);
                    And reduce time complexity, store the start and end indices instead. 
                    */
                    startIndex = i;
                    endIndex = j;
                }
            }
        }

        std::cout << "The subarray [";

        for (int i = startIndex; i <= endIndex; i++) 
        {
            std::cout << nums[i];
            if (i < endIndex) std::cout << ", ";
        }

        std::cout << "] has the largest sum " << maxSum << '\n';
    }
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
    for (int& x : nums) 
    {
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
        end1 - start1;

    std::cout << result << '\n'
              << "Big(O) - O(n^3) runtime: " << std::fixed << std::setprecision(3)
              << runtime.count() << " ms\n"
              << result1 << '\n'
              << "Big(O) - O(n^2) runtime: " << runtime1.count() << " ms\n";
    std::cout << sizeof(int) << '\n';
    std::cout << INT_MIN << '\n';
    std::cout << INT_MAX << '\n';
    return 0;
}
