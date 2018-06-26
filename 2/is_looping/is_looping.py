class Node:
    def __init__(self, val):
        self.val = val
        self.next = None

node1 = Node(12)
node2 = Node(99)
node3 = Node(30)
node4 = Node(30)
node5 = Node(30)
node6 = Node(30)
node7 = Node(30)
node8 = Node(30)
node9 = Node(30)

node1.next = node2
node2.next = node3
node3.next = node4
node4.next = node5
node5.next = node6
node6.next = node7
node7.next = node8
node8.next = node9
node9.next = node3

def is_looping(head):
    slow = head
    fast = head
    while (slow and fast and fast.next):
        slow = slow.next
        fast = fast.next.next
        if (slow == fast):
            return 1
    return 0

print(is_looping(node1))
    


    