//Given an array S of n integers, find three integers in S such that
//the sum is closest to a given number, target.Return the sum of the
//three integers.You may assume that each input would have exactly one solution.

//For example, given array S = { -1 2 1 - 4 }, and target = 1.
//The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

#include<stdio.h>
#include<stdlib.h>

int cmp(const void* a, const void* b)
{
	return *(int*)a - *(int*)b;
}

int threeSumClosest(int* nums, int numsSize, int target) {
	int sum = 0, tmpSum = 0;

	qsort(nums, numsSize, sizeof(nums[0]), cmp);
	sum = nums[0] + nums[1] + nums[2];
	if (numsSize == 3)
	{
		return sum;
	}
	for (int i = 0; i < numsSize - 2; i++)
	{
		int j = i + 1;
		int k = numsSize - 1;
		while (j < k)
		{
			tmpSum = nums[i] + nums[j] + nums[k];
			if (abs(target - sum) > abs(target - tmpSum))
			{
				sum = tmpSum;
				if (sum == target) return sum;
			}
			tmpSum > target ? k-- : j++;
		}
	}
	return sum;
}

int main()
{
	int a[] = { 1, 2, 4, 8, 16, 32, 64, 128 };
	int b = threeSumClosest(a, sizeof(a) / sizeof(a[0]), 82);
	printf("%d\n", b);
	return 0;
}