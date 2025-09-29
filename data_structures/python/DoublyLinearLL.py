class Node:
    def __init__(self,data):
        self.data = data
        self.prev = None
        self.next = None

class DoublyLinearLL:
    def __init__(self):
        self.head = None

    def InsertFirst(self,data):
        new_node = Node(data)
        if(self.head == None):#LL is empty
            self.head = new_node

        else:
            new_node.next = self.head
            self.head.prev = new_node
            self.head = new_node
            

    def InsertLast(self,data):
        new_node = Node(data)
        if(self.head == None):#LL is empty
            self.head = new_node

        else:#LL contains atleast one node
            temp = self.head
            while(temp.next != None):
                temp = temp.next
            temp.next = new_node
            new_node.prev = temp

    def DeleteFirst(self):
        if(self.head == None):#LL is empty
            print("Linked List is empty")
            return
        
        if(self.head.next == None):#LL contains only one node
            self.head = None

        else:
            self.head = self.head.next
            self.head.prev = None

        
    def DeleteLast(self):
        if(self.head == None):#LL is empty
            print("Linked List is empty")
            return
        
        if(self.head.next == None):#LL contains only one node
            self.head = None

        else:
            temp = self.head
            while(temp.next != None):
                temp = temp.next
            temp.prev.next = None

    def Display(self):
        temp = self.head
        print("None",end = "")
        while(temp != None):
            
            print(f"<=>|{temp.data}|",end = "")
            temp = temp.next
        print("<=> None")

    def Count(self):
        iCount = 0
        temp = self.head

        while(temp != None):
            iCount = iCount + 1
        
            temp = temp.next
        return iCount

    def InsertAtPos(self,data,pos):
        iCount = self.Count()

        if(pos < 1 or pos > iCount + 1):
            print("Invalid Position")
            return
        
        if(pos == 1):
            self.InsertFirst(data)

        elif(pos == iCount + 1):
            self.InsertLast(data)

        else:
            new_node = Node(data)
            temp = self.head
            for i in range(1,pos-1):
                temp = temp.next

            new_node.next = temp.next
            temp.next.prev = new_node
            temp.next = new_node
            new_node.prev = temp
            

    def DeleteAtPos(self,pos):

        iCount = self.Count()

        if(pos < 1 or pos > iCount):
            print("Invalid Position")
            return
        
        if(pos == 1):
            self.DeleteFirst()

        elif(pos == iCount):
            self.DeleteLast()

        else:
            temp = self.head
            for i in range(1,pos-1):
                temp = temp.next
            target = temp.next
            temp.next = target.next
            target.next.prev = temp
            
def main():
    sobj = DoublyLinearLL()

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
