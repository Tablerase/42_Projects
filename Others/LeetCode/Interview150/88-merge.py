class Solution(object):
    def merge(nums1, m, nums2, n):
        """
        :type nums1: List[int]
        :type m: int
        :type nums2: List[int]
        :type n: int
        :rtype: None Do not return anything, modify nums1 in-place instead.
        """
        # 2 sorted array with 0 at the end of nums1
        last_value1 = m - 1
        last_value2 = n - 1
        last_array = m + n - 1
        while last_value2 >= 0 and last_value1 >= 0:
            if nums2[last_value2] > nums1[last_value1]:
                nums1[last_array] = nums2[last_value2]
                last_value2 = last_value2 - 1
            else:
                nums1[last_array] = nums1[last_value1]
                last_value1 = last_value1 - 1
            last_array = last_array - 1
            # print(nums1)


if __name__ == '__main__':
    nums1 = [1, 2, 3, 0, 0, 0]
    m = 3
    nums2 = [2, 5, 6]
    # nums1 = [-1, 0, 0, 3, 3, 3, 0, 0, 0]
    # m = 6
    # nums2 = [1, 2, 2]
    n = 3
    Solution.merge(nums1, m, nums2, n)
    print(nums1)
