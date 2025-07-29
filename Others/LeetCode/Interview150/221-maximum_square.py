class Point:
    def __init__(self, row=0, col=0):
        self.row: int = row
        self.col: int = col

    def __str__(self):
        return f"row: {self.row}, col: {self.col}"


class Solution(object):
    def maximalSquare(self, matrix: list[list[str]]):
        """
        :type matrix: List[List[str]]
        :rtype: int
        """
        rows = len(matrix)
        columns = len(matrix[0])
        max_len = 0

        def squareMaxLen(start: Point):
            row_max_len = 0
            for cell in range(start.col, columns):
                if matrix[start.col][cell] == '1':
                    row_max_len = row_max_len + 1
                else:
                    break
            print("Row max:", row_max_len)
            col_max_len = 1
            for col in range(start.col, start.col + row_max_len):
                current_max_len = 1
                for row in range(start.row, rows):
                    if matrix[row][col] == '1':
                        current_max_len = current_max_len + 1
                    else:
                        break
                if current_max_len < col_max_len:
                    col_max_len = current_max_len
                    row_max_len = col_max_len
            return col_max_len

        '''
        search accross matrix 1
            for each 1 do a square search
                find square len
                skip when square len < max len
        '''
        start = Point(1, 2)
        print(start)
        print(squareMaxLen(start))

        return max_len * max_len


if __name__ == '__main__':
    matrix = [["1", "0", "1", "0", "0"],
              ["1", "0", "1", "1", "1"],
              ["1", "1", "1", "1", "1"],
              ["1", "0", "0", "1", "0"]]
    test = Solution()
    print("Result:", test.maximalSquare(matrix))
