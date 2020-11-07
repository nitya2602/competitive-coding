class Solution {
public:
    long calSum(vector<int> nums, int n)
    {
        long sum = 0;
        for(int i = 0; i<nums.size(); i++)
        {
            sum += ceil(float(nums[i])/n);
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        long sum = 0;
        int left = 1;
        int right = nums[nums.size()-1];
        while(calSum(nums, right) > threshold)
        {
            left = right;
            right <<= 1;
        }
        while(left <= right)
        {
            int mid = (left + right)/2;
            sum = calSum(nums, mid);
            if(sum <= threshold)
            {
                right = mid - 1;
            }
            else 
                left = mid + 1;
        }
        return left;
    }
};