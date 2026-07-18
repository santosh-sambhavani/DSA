# 257. Binary Tree Paths
# Input: root = [1,2,3,null,5]
# Output: ["1->2->5","1->3"]
class Solution:
    def dfs(self, root: Optional[TreeNode], path: str, response: List[str]) -> None:
        if not path:
            path += str(root.val)
        else:
            path += "->" + str(root.val)

        if not root.left and not root.right:
            response.append(path)
            return
        if root.left:
            self.dfs(root.left, path, response)
        if root.right:
            self.dfs(root.right, path, response)
        

    def binaryTreePaths(self, root: Optional[TreeNode]) -> List[str]:
        response = []
        self.dfs(root, "", response)
        return response


# 230. Kth Smallest Element in a BST
# Input: root = [5,3,6,2,4,null,null,1], k = 3
# Output: 3
class Solution:
    count = 0
    ans = 0
    def inOrder(self, root: Optional[TreeNode], k: int):
        if not root:
            return None
        
        self.inOrder(root.left, k)
        self.count += 1
        if k == self.count:
            self.ans = root.val
            return
        self.inOrder(root.right, k)

    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        self.inOrder(root, k)
        return self.ans

# 124. Binary Tree Maximum Path Sum
# Input: root = [1,2,3]
# Output: 6
# Explanation: The optimal path is 2 -> 1 -> 3 with a path sum of 2 + 1 + 3 = 6.
class Solution:
    response = -1001
    def postOrder(self, root: Optional[TreeNode]):
        if not root:
            return 0
        
        leftSum = max(0, self.postOrder(root.left))
        rightSum = max(0, self.postOrder(root.right))

        self.response = max(self.response, leftSum + rightSum + root.val)

        return max(leftSum, rightSum) + root.val

    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        self.postOrder(root)
        return self.response
