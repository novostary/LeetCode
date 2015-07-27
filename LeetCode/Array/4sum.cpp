#include <iostream>
#include <vector>
#include <algorithm>
using std::vector;
// Runtime: 68 ms
// best: 12 ms???
class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		vector<vector<int>> res;
		if (nums.size() < 4) {
			return res;
		}
		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size() - 3; i++) {
			if (i > 0 && nums[i] == nums[i - 1]) {
				continue;
			}
			for (int j = i + 1; j < nums.size() - 2; j++) {
				if (j > i + 1 && nums[j] == nums[j - 1]) {
					continue;
				}
				int k = j + 1;
				int l = nums.size() - 1;
				int target2sum = target - nums[i] - nums[j];
				while (k < l) {
					int tmp = nums[k] + nums[l];
					if (tmp < target2sum) {
						k++;
					}
					else if (tmp > target2sum) {
						l--;
					}
					else {
						vector<int> vt(4, 0);
						vt[0] = nums[i];
						vt[1] = nums[j];
						vt[2] = nums[k];
						vt[3] = nums[l];
						res.push_back(vt);
						k++;
						l--;
						while (k < l && nums[k] == nums[k - 1]) {
							k++;
						}
						while (k < l && nums[l] == nums[l + 1]) {
							l--;
						}
					}
				}
			}
		}
		return res;
	}
	// 16 ms
	vector<vector<int>> fourSumWithPruning(vector<int>& nums, int target) {
		vector<vector<int>> res;
		if (nums.size() < 4) {
			return res;
		}
		sort(nums.begin(), nums.end());
		int maxLWhenAIncrease = nums.size() - 1;
		for (int i = 0; i < maxLWhenAIncrease - 2; i++) {
			if (i > 0 && nums[i] == nums[i - 1] || nums[i] + nums[maxLWhenAIncrease - 2] 
					+ nums[maxLWhenAIncrease - 1] + nums[maxLWhenAIncrease] < target) {
				continue;
			}
			int firstThree = nums[i] + nums[i + 1] + nums[i + 2];
			if (firstThree + nums[i + 3] > target) {
				// only this statement, 44 ms
				break;
			}
			if (firstThree + nums[maxLWhenAIncrease] > target) {
				maxLWhenAIncrease--;
			}

			for (int j = i + 1; j < maxLWhenAIncrease - 1; j++) {
				if (j > i + 1 && nums[j] == nums[j - 1]) {
					continue;
				}
				int k = j + 1;
				int l = nums.size() - 1;
				int target2sum = target - nums[i] - nums[j];
				while (k < l) {
					int tmp = nums[k] + nums[l];
					if (tmp < target2sum) {
						k++;
					}
					else if (tmp > target2sum) {
						l--;
					}
					else {
						vector<int> vt(4, 0);
						vt[0] = nums[i];
						vt[1] = nums[j];
						vt[2] = nums[k];
						vt[3] = nums[l];
						res.push_back(vt);
						k++;
						l--;
						while (k < l && nums[k] == nums[k - 1]) {
							k++;
						}
						while (k < l && nums[l] == nums[l + 1]) {
							l--;
						}
					}
				}
			}
		}
		return res;
	}
	// 12 ms
	vector<vector<int>> fourSumWithPruning2(vector<int>& nums, int target) {
		vector<vector<int>> res;
		if (nums.size() < 4) {
			return res;
		}
		sort(nums.begin(), nums.end());
		int maxLWhenIIncrease = nums.size() - 1;
		for (int i = 0; i < maxLWhenIIncrease - 2; i++) {
			if ((i > 0 && nums[i] == nums[i - 1]) || nums[i] + nums[maxLWhenIIncrease - 2]
				+ nums[maxLWhenIIncrease - 1] + nums[maxLWhenIIncrease] < target) {
				continue;
			}
			int firstThree = nums[i] + nums[i + 1] + nums[i + 2];
			if (firstThree + nums[i + 3] > target) {
				// only this statement, 44 ms
				break;
			}
			while (firstThree + nums[maxLWhenIIncrease] > target) {
				maxLWhenIIncrease--;
			}
			int maxLWhenJIncrease = maxLWhenIIncrease;
			for (int j = i + 1; j < maxLWhenJIncrease - 1; j++) {
				if ((j > i + 1 && nums[j] == nums[j - 1]) || nums[i] + nums[j] 
						+ nums[maxLWhenJIncrease - 1] + nums[maxLWhenJIncrease] < target) {
					continue;
				}
				firstThree = nums[i] + nums[j] + nums[j + 1];
				if (firstThree + nums[j + 2] > target) {
					break;
				}
				while (firstThree + nums[maxLWhenJIncrease] > target) {
					maxLWhenJIncrease--;
				}

				int k = j + 1;
				int l = maxLWhenJIncrease;
				int target2sum = target - nums[i] - nums[j];
				while (k < l) {
					int tmp = nums[k] + nums[l];
					if (tmp < target2sum) {
						k++;
					}
					else if (tmp > target2sum) {
						l--;
					}
					else {
						vector<int> vt(4, 0);
						vt[0] = nums[i];
						vt[1] = nums[j];
						vt[2] = nums[k];
						vt[3] = nums[l];
						res.push_back(vt);
						k++;
						l--;
						while (k < l && nums[k] == nums[k - 1]) {
							k++;
						}
						while (k < l && nums[l] == nums[l + 1]) {
							l--;
						}
					}
				}
			}
		}
		return res;
	}
	// https://leetcode.com/discuss/45243/16ms-c-solution-with-pruning
	vector<vector<int>> fourSum16mssometimes12ms(vector<int>& nums, int target) {
		vector<vector<int>>  result;
		if (nums.size() < 4) return result;

		vector<int> solution(4, 0);
		std::sort(nums.begin(), nums.end());
		int sum, a, b, c, d, Max_d_when_a_increase = nums.size() - 1, Max_d_when_b_increase;

		//a,b,c,d are the four index
		//Max_d_when_a_increase is the max possible d when a increase. To have the same sum, when a increase, d can only decrease
		//Max_d_when_b_increase is the max possible d when b increase

		for (a = 0; a < Max_d_when_a_increase - 2; a++)
		{
			//remove dupilcate & do pruning if a too small or too big
			if ((a>0 && nums[a] == nums[a - 1])
				|| nums[a] + nums[Max_d_when_a_increase] + nums[Max_d_when_a_increase - 1] 
					+ nums[Max_d_when_a_increase - 2] < target) 
				continue;
			if (nums[a] + nums[a + 1] + nums[a + 2] + nums[a + 3] > target) 
				break;

			//update Max_d_when_a_increase
			sum = nums[a] + nums[a + 1] + nums[a + 2];
			while (sum + nums[Max_d_when_a_increase] > target)
				Max_d_when_a_increase--;
			Max_d_when_b_increase = Max_d_when_a_increase;

			solution[0] = nums[a];
			for (b = a + 1; b < Max_d_when_b_increase - 1; b++)
			{
				//remove dupilcate & do pruning if b too small or too big
				if ((b>a + 1 && nums[b] == nums[b - 1])
					|| nums[a] + nums[b] + nums[Max_d_when_b_increase - 1] + nums[Max_d_when_b_increase] < target) 
					continue;
				sum = nums[a] + nums[b] + nums[b + 1];
				if (sum + nums[b + 2] > target) 
					break;

				//update Max_d_when_b_increase
				while (sum + nums[Max_d_when_b_increase]>target) 
					Max_d_when_b_increase--;

				solution[1] = nums[b];
				c = b + 1;
				d = Max_d_when_b_increase;
				sum = nums[a] + nums[b];
				while (c < d)//this are the same as two sum
				if (sum + nums[c] + nums[d] == target)
				{
					solution[2] = nums[c];
					solution[3] = nums[d];
					result.push_back(solution);

					do{ c++; } while (c < d && nums[c] == nums[c - 1]);
					do{ d--; } while (c < d && nums[d] == nums[d + 1]);
				}
				else if (sum + nums[c] + nums[d] < target)
					do{ 
						c++; 
					} while (c < d && nums[c] == nums[c - 1]);
				else 
					do{ 
						d--; 
					} while (c < d && nums[d] == nums[d + 1]);
			}
		}
		return result;
	}
};