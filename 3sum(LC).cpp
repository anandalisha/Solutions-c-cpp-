void findTripletWithSumZero(vector<int>& nums, int searchIndex, vector<vector<int>>& triplets) {
	const int targetSum = 0;

	int left = searchIndex + 1;
	int right = (int)nums.size() - 1;

	while (left < right) {
		int sum = nums[searchIndex] + nums[left] + nums[right];
		if (sum == targetSum) {
			triplets.insert(ans.end(), { nums[searchIndex], nums[left], nums[right] });

			const int leftNum = nums[left];
			while (left < right && nums[left] == leftNum) ++left;

			const int rightNum = nums[right];
			while (left < right && nums[right] == rightNum) --right;
		} else if (sum < targetSum) {
			++left;
		} else --right;
	}
}

vector<vector<int>> threeSum(vector<int>& nums) {
	vector<vector<int>> triplets;

	sort(nums.begin(), nums.end());
	/*
		[-1, 0, 1, 2, -1, -4]

			  i      l  r
		[-4, -1, -1, 0, 1, 2, 2] => (-1, -1, 2), (-1, 0, 1)
	*/
	for (int i = 0; i < (int)nums.size(); i++) {
		int num = nums[i];

		findTripletWithSumZero(nums, i, triplets);
		while (i < (int)nums.size() - 1 && nums[i + 1] == num) ++i;
	}
	return triplets;
}
