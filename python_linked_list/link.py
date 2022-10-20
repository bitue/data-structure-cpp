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
    def detect_cycle(self):
        slow = self.head
        fast = self.head

        while(slow is not None and fast.next is not None):
            slow = slow.next
            fast = fast.next.next
            if(slow == fast):
                return True

        return False



    def make_cycle(self, pos):
        # go to this pos
        temp = self.head
        tail = self.head
        while tail.next is not None :
            tail = tail.next
        for i in range (pos):
            temp = temp.next

        tail.next = temp




    def remove_cycle(self):
        slow = self.head
        fast = self.head

        while(slow is not None and fast.next is not None):
            slow = slow.next
            fast = fast.next.next
            if(slow == fast):
                fast = self.head
                print(slow.value, "slow er value ")

                while(slow.next is not fast.next):
                    slow = slow.next
                    fast = fast.next
                print(slow.value, fast.value , "meet point to give null")
                slow.next = None
                return

    def reverse_linkList(self):
        prevNode = None
        currNode = self.head
        nextNode = currNode.next

        while True:
            currNode.next = prevNode
            # update them
            prevNode = currNode
            currNode = nextNode
            if currNode is None:
                break
            nextNode = nextNode.next


        return prevNode

    def reverse_recurr(self):
        if self.head.next is None :
            return self.head
        # save the save value
        save = self.head
        # iteration done one self.head
        self.head = self.head.next
        #newHead capture
        newHead = self.reverse_recurr()
        # print(newHead.value, "newNode")
        # print(save.value, "save")
        save.next.next = save
        save.next = None
        return newHead









myList = LinkedList()

# make list
for i in range(7):
    myList.insert_at_tail(i)


# myList.insert_at_after_pos(5, 5)
# res = myList.remove_from_pos(6)
# print( f"removed value is {res}")
# myList.print_list()
# myList.make_cycle(3)
# res = myList.detect_cycle()
# if(res):
#     print("Cycle detect")
# else :
#     print("No cycle")
#
# myList.remove_cycle()
# res1 = myList.detect_cycle()
# if(res1):
#     print("Cycle detect")
# else :
#     print("No cycle")
# myList.print_list()

print(myList.head)

myList.head = myList.reverse_recurr()
myList.print_list()
print(myList.head)
# print(myList.find_mid())
# print("size is ",myList.size)





