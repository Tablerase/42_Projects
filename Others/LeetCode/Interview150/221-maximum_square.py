# Version 2 - with Dynamic Programming
class Solution(object):
    def maximalSquare(self, matrix: list[list[str]]):
        if not matrix or not matrix[0]:
            return 0
        max_side = 0
        rows, cols = len(matrix), len(matrix[0])

        dp = [[0] * (cols + 1) for _ in range(rows + 1)]
        for i in range(1, rows + 1):
            for j in range(1, cols + 1):
                if matrix[i - 1][j - 1]  == "1":
                    # check min max side for each cell adjacent behind i,j cell
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]) + 1
                    if dp[i][j] > max_side:
                        max_side = dp[i][j]
                        print(i, j, max_side)
        return max_side * max_side

if __name__ == '__main__':
    matrix = [["1", "0", "1", "0", "0"],
              ["1", "0", "1", "1", "1"],
              ["1", "1", "1", "1", "1"],
              ["1", "0", "0", "1", "0"]]
    test = Solution()
    # print("Test: ", test.checkValidity(Point(0,2), Point(1,3), matrix))
    print("Result:", test.maximalSquare(matrix))
# Version 1 - without Dynamic Programming

# class Point:
#     def __init__(self, row=0, col=0):
#         self.row = row
#         self.col = col
#
#     def __str__(self):
#         return f"row: {self.row}, col: {self.col}"
#
# class Solution(object):
#     def __init__(self) -> None:
#         self.max_len = 0
#         self.max_col = 0
#         self.max_row = 0
#         pass
#
#     def checkValidity(self, start: Point, end: Point, matrix: list[list[str]]):
#         # Check only row and column of end (assume previous one are already checked)
#         for cel in range(start.col, end.col + 1):
#             if matrix[end.row][cel] != "1":
#                 # print(f"Row not valid: row{end.row} col{cel}")
#                 return False
#         for cel in range(start.row, end.row + 1):
#             if matrix[cel][end.col] != "1":
#                 # print(f"Col not valid: row{cel} col{end.col}")
#                 return False
#         return True
#
#     def maxLenFromPoint(self, start: Point, matrix: list[list[str]]):
#         # traverse diagonaly till checkValidity is false
#         current_len = 1
#         while (start.row + current_len < self.max_row and
#                start.col + current_len < self.max_col and
#                self.checkValidity(start, Point(start.row + current_len, start.col + current_len), matrix)):
#             current_len += 1
#
#         if current_len > self.max_len:
#             self.max_len = current_len
#
#     def maximalSquare(self, matrix: list[list[str]]):
#         """
#         # traverse from top to bottom -> left to right
#             # check if cell is 1 then
#             # for each 1 point then traverse diagonaly and check for validity until not
#               ["X", "🔍", "?", "?", "?"],
#               ["🔍", "X", "?", "?", "?"],
#               ["?", "?", "?", "?", "?"],
#               ["?", "?", "?", "?", "?"] 
#         """
#         self.max_row = len(matrix)
#         self.max_col = len(matrix[0])
#         for row in range(0, self.max_row - 1):
#             for col in range(0, self.max_col - 1):
#                 to_check = Point(row,col)
#                 if matrix[to_check.row][to_check.col] == "1":
#                     self.maxLenFromPoint(to_check, matrix)
#
#         return self.max_len * self.max_len
#

