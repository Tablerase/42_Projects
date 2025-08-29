class Solution(object):
    def removeDuplicates(self, nums: list[int]):
        """
        :type nums: List[int]
        :rtype: int
        """
        processed_nums : dict[int, int] = {}
        for i in nums:
            if processed_nums.get(i) == None:
                processed_nums[i] = 1;
            else:
                continue
        nums[:] = list(processed_nums.keys())
        # print('Nums:',nums)
        return nums.__len__()


if __name__ == '__main__':
    test = Solution()
    nums = [-1,0,0,0,0,3,3]
    result = test.removeDuplicates(nums)
    print("Result: ", result, nums)

