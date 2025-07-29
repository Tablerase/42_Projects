class Solution(object):
    def removeElement(self, nums: list[int], val):
        """
        :type nums: List[int]
        :type val: int
        :rtype: int
        """
        to_rm = nums.count(val)
        result = len(nums) - to_rm
        try:
            for i in range(0, to_rm):
                nums.remove(val)
        except Exception as e:
            print(e)
        return result


if __name__ == '__main__':
    nums = [3, 2, 2, 3]
    val = 3
    test = Solution()
    result = test.removeElement(nums, val)
    print(nums)
    print(result)
