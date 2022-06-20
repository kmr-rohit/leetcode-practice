		class Solution {
		public:
			vector<int> searchRange(vector<int>& nums, int target) 
			{
				auto first=lower_bound(nums.begin(),nums.end(),target);
				auto last=upper_bound(nums.begin(),nums.end(),target);
				if(first<last)
					return {int(first-nums.begin()),int(--last-nums.begin())};
				return {-1,-1};
			}

		};