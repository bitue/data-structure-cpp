class Node:
    def __init__(self, value=None, next = None ):
        self.value = value
        self.next = next



class LinkedList:

    def __init__(self):
        self.head = None
        self.size =0

    def insert_at_tail(self, value):
        newNode = Node(value)
        self.size +=1
        if self.head is None:
            self.head = newNode
        else:
            temp = self.head
            while temp.next is not None :
                temp = temp.next
            temp.next = newNode

    def print_list(self):
        temp = self.head
        while temp is not None :
            print(temp.value)
            temp = temp.next


    def insert_at_head(self, value):
        self.size+=1
        newNode = Node(value)
        preHead = self.head
        newNode.next = preHead
        self.head = newNode

    def insert_at_after_pos(self, pos, value):

        if 0 <= pos < self.size :
            newNode = Node(value)
            self.size += 1
            temp = self.head
            for i in range(pos):
                temp = temp.next
            temp_node = temp.next
            temp.next = newNode
            newNode.next = temp_node
        elif pos ==-1 :
            self.insert_at_head(value)

        elif pos ==self.size :
            self.insert_at_tail(value)
        else :
            print(f"Enter the valid position where total size is {self.size}")
            return

    def remove_from_pos(self, pos):
        temp = self.head
        self.size -=1
        if pos ==-1 :
            new_head = temp.next
            self.head = new_head
            del temp
            return temp.value

        for i in range(pos-1):
            temp = temp.next

        del_node = temp.next
        next_node = del_node.next
        temp.next = next_node
        value = del_node.value
        del del_node
        return value

    def find_mid(self):
        mid = self.size //2
        temp = self.head
        for i in range (mid):
            temp = temp.next

        return temp.value










myList = LinkedList()

for i in range(7):
    myList.insert_at_tail(i)

# myList.print_list()

# myList.insert_at_after_pos(5, 5)
res = myList.remove_from_pos(2)
print( f"removed value is {res}")
myList.print_list()

print(myList.find_mid())
print(myList.size)





