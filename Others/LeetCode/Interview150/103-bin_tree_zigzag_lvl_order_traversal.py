# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left: TreeNode = left
        self.right: TreeNode = right


class Solution(object):
    def _traversal(self, lvl: int, root: TreeNode | None, res: list[list[int]]):
        if root == None:
            return
        if len(res) <= lvl:
            res.append([])
        if lvl % 2:
            res[lvl].insert(0, root.val)
        else:
            res[lvl].append(root.val)

        # print(f'Root: {root.val}, Lvl: {lvl}, Res len: {res.__len__()}')

        lvl = lvl + 1
        self._traversal(lvl, root.left, res)
        self._traversal(lvl, root.right, res)

    def zigzagLevelOrder(self, root: TreeNode):
        """
        1st lvl: Left Right -> 2nd lvl: Right Left -> ...
        :type root: Optional[TreeNode]
        :rtype: List[List[int]]
        """
        res: list[list[int]] = []
        lvl = 0
        self._traversal(lvl, root, res)
        return res


if __name__ == "__main__":
    # root = TreeNode(3)
    # root.left = TreeNode(9)
    # root.right = TreeNode(20, TreeNode(15), TreeNode(7))
    # test = Solution()
    # print(f'Value: {test.zigzagLevelOrder(root)}')
    # print(f'Expected: ', [[3], [20, 9], [15, 7]])
    root = TreeNode(1)
    root.left = TreeNode(2)
    root.right = TreeNode(3)
    root.left.left = TreeNode(4)
    root.right.right = TreeNode(5)
    test = Solution()
    print(f'Value: {test.zigzagLevelOrder(root)}')
    print(f'Expected: ', [[1], [3, 2], [4, 5]])
