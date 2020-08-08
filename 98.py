"""
98.BST与其验证
https://www.geekxh.com/1.4.%E4%BA%8C%E5%8F%89%E6%A0%91%E7%B3%BB%E5%88%97/403.html
"""


class TreeNode:
    """
    Tree structure
    """
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


def is_valid_bst(root: TreeNode) -> bool:
    """
    Bst valid
    :param root:
    :return:
    """
    if not root:
        return True
    return is_bst(root, float('-inf'), float('inf'))


def is_bst(root: TreeNode, lower, upper) -> bool:

    if not root:
        return True
    if root.val <= lower or root.val >= upper:
        return False

    return is_bst(root.left, lower, root.val) & is_bst(root.right, root.val, upper)
