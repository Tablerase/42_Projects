class Solution(object):
    def majorityElement(self, nums: list[int]):
        """
        :type nums: List[int]
        :rtype: int
        """
        dictOfNums: dict[int, int] = {}
        for elem in nums:
            if dictOfNums.get(elem) == None:
                dictOfNums[elem] = nums.count(elem)
        return max(dictOfNums, key=dictOfNums.get)


if __name__ == '__main__':
    # Input = [2, 2, 1, 1, 1, 2, 2]
    Input = [3, 3, 4]
    test = Solution()
    print(test.majorityElement(Input))
