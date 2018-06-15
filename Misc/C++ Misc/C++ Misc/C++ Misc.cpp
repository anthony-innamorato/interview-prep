// C++ Misc.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
using namespace std;

int removeDuplicates(vector<int>& nums)
{
	if (nums.size() == 0) { return 0; }
	size_t i = 1;
	int currNum = nums[0];
	while (i < nums.size())
	{
		if (nums[i] == currNum) { i--;  nums.erase(nums.begin() + i); }
		else { currNum = nums[i];}
		i++;
	}
	return nums.size();
}


int main()
{
	vector<int> nums = { 0, 0, 1, 1, 1, 2, 2, 3, 3, 4 };
	cout << "length after: " << removeDuplicates(nums) << endl;
	for (const int num : nums) { cout << num << ' '; }
	cout << endl;

	vector<int> nums2 = { 1, 1, 2};
	cout << "length after: " << removeDuplicates(nums2) << endl;
	for (const int num : nums2) { cout << num << ' '; }
	cout << endl;
    return 0;
}

