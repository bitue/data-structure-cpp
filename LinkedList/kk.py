class Node:
    def __init__(self, value=None, next=None):
        self.value = value
        self.next = next




class Linked:
    def __int__(self):
        self.head = None


    def insert_at_tail(self, val):
        newNode = Node(val)
        if self.head == None:
            self.head = newNode
        else:
            temp = self.head
            while temp is not None:
                print(temp.value)
                temp = temp.next

            temp.next = newNode

    def print_list(self):
        temp = self.head
        while temp is not None:
            print(temp.value)
            temp = temp.next


myList = Linked()

for i in range(5):
    myList.insert_at_tail(i)



myList.print_list()
