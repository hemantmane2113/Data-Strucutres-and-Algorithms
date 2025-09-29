class Node:
    def __init__(self,data):
        self.data = data
        self.next = None

class SinglyCircularLL:
    def __init__(self):
        self.head = None
        self.tail = None

    def InsertFirst(self,data):
        new_node = Node(data)
        if self.head == None and self.tail == None:#LL is empty
            self.head = new_node
            self.tail = new_node
            new_node.next = self.head

        else:#LL contains atleast one node
            new_node.next = self.head
            self.head = new_node
            self.tail.next = self.head

    def InsertLast(self,data):
        new_node = Node(data)
        temp = self.head
        if self.head == None and self.tail == None:#LL is empty
            self.head = new_node
            self.tail = new_node
            new_node.next = self.head

        else:#LL contains atleast one node
            self.tail.next = new_node
            new_node.next = self.head
            self.tail = new_node

    def DeleteFirst(self):
        if self.head == None and self.tail == None:#LL is empty
            print("Linked list is empty")
            return
        
        if self.head == self.tail:#LL contains only one node
            self.head = None
            self.tail = None

        else:#LL contains atleast one node
            self.head = self.head.next
            self.tail.next = self.head

    def DeleteLast(self):
        if self.head == None and self.tail == None:#LL is empty
            print("Linked list is empty")
            return
        
        if self.head == self.tail:#LL contains only one node
            self.head = None
            self.tail = None

        else:#LL contains atleast one node
            temp = self.head
            while(temp.next != self.tail):
                temp = temp.next
            temp.next = self.head
            self.tail = temp
            
    def Display(self):
        if(self.head == None):
            print("Linked List is empty")
            return
        
        temp = self.head
        print("<-", end="")
        while True:
                print(f"| {temp.data} |->", end="")

                if temp == self.tail: 
                    break 
                temp = temp.next                
        print()

    def Count(self):
        iCount = 0
        if(self.head == None):
            return 0
        
        temp = self.head

        while True:
            iCount = iCount + 1

            if(temp == self.tail):
                break
            temp = temp.next
        return iCount
    
    def InsertAtPos(self,data,pos):
                
        new_node = Node(data)

        temp = self.head

        iCount = self.Count()

        if(pos < 1 or pos > iCount + 1):
            print("Invalid position")
            return
        
        if(pos == 1):
            self.InsertFirst(data)

        elif(pos == iCount + 1):
            self.InsertLast(data)

        else:
            for i in range(1,pos-1):
                temp = temp.next

            new_node.next = temp.next
            temp.next = new_node

    def DeleteAtPos(self,pos):

        temp = self.head

        iCount = self.Count()

        if(pos < 1 or pos > iCount):
            print("Invalid position")
            return
        
        if(pos == 1):
            self.DeleteFirst()

        elif(pos == iCount ):
            self.DeleteLast()

        else:
            temp = self.head
            for i in range(1,pos-1):
                temp = temp.next

            target = temp.next
            temp.next = target.next

def main():
    sobj = SinglyCircularLL()

    sobj.InsertFirst(51)
    sobj.InsertFirst(21)
    sobj.InsertFirst(11)

    sobj.InsertLast(101)
    sobj.InsertLast(111)
    sobj.InsertLast(121)

    sobj.Display()  
    iRet = sobj.Count()
    print("The total number of nodes in linked list are: ", iRet) 

    sobj.InsertAtPos(105,5)
    sobj.Display()  
    iRet = sobj.Count()
    print("The total number of nodes in linked list are: ", iRet) 

    sobj.DeleteAtPos(5)
    sobj.Display()  
    iRet = sobj.Count()
    print("The total number of nodes in linked list are: ", iRet) 

if __name__ == "__main__":
    main()        
        

