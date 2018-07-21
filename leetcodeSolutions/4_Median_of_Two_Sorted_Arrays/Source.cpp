/*
There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

Example 1:
nums1 = [1, 3]
nums2 = [2]

The median is 2.0
Example 2:
nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int m = nums1.size();
		int n = nums2.size();
		int mid = (m + n + 1) >> 1;
		int maxidx = m;
		int minidx = 0;
		int i, j, num1, num2;

		if (m > n)
			return findMedianSortedArrays(nums1, nums2);

		while (minidx <= maxidx) {
			i = (minidx + maxidx) >> 1;
			j = mid - i;
			if (i < m && j > 0 && nums2[j - 1] > nums1[i])
				minidx = i + 1;
			else if (i > 0 && j < n && nums2[j] < nums1[i - 1])
				maxidx = i - 1;
			else {
				if (i == 0)
					num1 = nums2[j - 1];
				else if (j == 0)
					num1 = nums1[i - 1];
				else
					num1 = max(nums1[i - 1], nums2[j - 1]);
				break;
			}
		}

		if (((m + n) & 1))
			return num1;

		if (i == m)
			num2 = nums2[j];
		else if (j == n)
			num2 = nums1[i];
		else
			num2 = min(nums1[i], nums2[j]);

		return (num1 + num2) / 2.;
	}
};

int main(void)
{
	Solution mysol;
	vector<int> nums1 = { 1, 2 };
	vector<int> nums2 = { 3, 4 };
	double answer = 0;

	answer = mysol.findMedianSortedArrays(nums1, nums2);

	cout << "answer: " << answer << endl;
	return 0;
}