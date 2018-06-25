class Node:
    def __init__(self, val, arrayNodes):
        self.val = val
        self.nodes = {}

node1 = Node(12, {node2, node3})
node2 = Node(99, [node4])
node3 = Node(30, [node5])
node4 = Node(30, [node7, node8])
node5 = Node(30, [node9])
node6 = Node(30)
node7 = Node(30)
node8 = Node(30)
node9 = Node(30)

def height_tree(root):
    if root is None:
        return -1
    else:
        i = 0
        nodeCount = len(root.nodes)
        max = 0
        while i < nodeCount:
            if height_tree(root.nodes[i]) > max:
                max = height_tree(root.nodes[i])
            i += 1
        return max + 1

print(height_tree(node1))


