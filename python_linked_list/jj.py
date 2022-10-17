class Node:
    def __init__(self, value=None, next=None):
        self.value = value
        self.next = next


class Linked:


    def __init__(self):
        self.head = None

    def insert_at_tail(self, val):
        newNode = Node(val)
        if self.head == None:
            self.head = newNode
            # print(self.head.value)
        else:
            temp = self.head
            # traverse till last node
            while temp.next != None:  # temp is not None
                temp = temp.next
            print("Last Node Value: ", temp.value)
            # insert newNode to the next of last node
            temp.next = newNode

    def print_list(self):
        # print(self.head.value)
        temp = self.head
        while temp is not None:
            print(temp.value)
            temp = temp.next


myList = Linked()
# myList.insert_at_tail(10)

for i in range(5):
    myList.insert_at_tail(i)

myList.print_list()