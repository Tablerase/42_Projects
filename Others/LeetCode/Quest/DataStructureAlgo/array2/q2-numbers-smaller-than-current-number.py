"""
watchexec -r -e py python script.py
"""

"""
Given the array nums, for each nums[i] find out how many numbers in the array are smaller than it. 
That is, for each nums[i] you have to count the number of valid j's such that j != i and nums[j] < nums[i].

Return the answer in an array.
"""

import sys
import unittest


class Solution:
    def _sumOfInferiorNumbers(
        self, num_comparator: int, nums_to_compare: list[int]
    ) -> int:
        sum: int = 0
        for num in nums_to_compare:
            if num < num_comparator:
                sum += 1
        return sum

    def smallerNumbersThanCurrent(self, nums: list[int]) -> list[int]:
        res: list[int] = []
        for num in nums:
            res.append(self._sumOfInferiorNumbers(num, nums))
        # print("\n", res, file=sys.stdout)
        return res


class TestSolution(unittest.TestCase):
    def test_cases(self):
        cases = [
            ("ex1", [8, 1, 2, 2, 3], [4, 0, 1, 1, 3]),
            ("ex2", [7, 7, 7, 7], [0, 0, 0, 0]),
        ]
        for name, param1, expeceted in cases:
            with self.subTest(case_name=name):
                s = Solution()
                self.assertEqual(s.smallerNumbersThanCurrent(param1), expeceted)


def main():
    unittest.main(verbosity=2)


if __name__ == "__main__":
    main()
