import copy

# Definition for a Node.


class Node(object):
    def __init__(self, val=0, neighbors=None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []

    def __str__(self):
        return f"Value: {self.val}, Neighbors: {[(n.val, id(n)) for n in self.neighbors]}, Addr: {id(self)}"


class Solution(object):
    def _nodeCpy(self, node: Node, store: dict[int, Node]):
        if store.get(node.val):
            return
        # Create new node
        newNode = Node(node.val, None)
        store[newNode.val] = newNode
        # Fill neighbors
        for neighbor in node.neighbors:
            self._nodeCpy(neighbor, store)
            # Updates neighbor address with new nodes (done after all new node creation)
            newNode.neighbors.append(store.get(neighbor.val))
            # print(f'newNode: {newNode.val}, \nADD: {neighbor}')

    def cloneGraph(self, node: Node):
        """
        :type node: Node
        :rtype: Node
        """
        dictOfNodes: dict[int, Node] = {}
        self._nodeCpy(node, dictOfNodes)
        for elem in dictOfNodes.values():
            print(elem)
        return dictOfNodes[node.val]


if __name__ == "__main__":
    """
    Input: adjList = [[2,4],[1,3],[2,4],[1,3]]
    Output: [[2,4],[1,3],[2,4],[1,3]]
    Explanation: There are 4 nodes in the graph.
    1st node (val = 1)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).
    2nd node (val = 2)'s neighbors are 1st node (val = 1) and 3rd node (val = 3).
    3rd node (val = 3)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).
    4th node (val = 4)'s neighbors are 1st node (val = 1) and 3rd node (val = 3). 
    """
    node1 = Node(1)
    node2 = Node(2)
    node3 = Node(3)
    node4 = Node(4)

    node1.neighbors = [node2, node4]
    node2.neighbors = [node1, node3]
    node3.neighbors = [node2, node4]
    node4.neighbors = [node1, node3]

    solution = Solution()

    # Test deepcopy
    cloned_deepcopy = copy.deepcopy(node1)
    print(f"Original: {id(node1)}, Deepcopy: {id(cloned_deepcopy)}")
    print(f"Different objects: {node1 is not cloned_deepcopy}")

    # Test manual clone
    cloned_manual = solution.cloneGraph(node1)
    print(f"Manual clone: {id(cloned_manual)}")
