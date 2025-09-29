class Node:                                      #class
    def __init__(self, data):                    #constructor
        self.data = data                         #instance variable or attributes
        self.next = None                         #instance variable

class SinglyLinearLL:                           #class
    def __init__(self):                           #constructor
        self.head = None                          #instance variable

    def InsertFirst(self, data):                  #instance method
        new_node = Node(data)
        if self.head == None:#LL is empty
            self.head = new_node
            return
        
        else:#LL has atleast one Node
            new_node.next = self.head
            self.head = new_node

    def InsertLast(self, data):
        new_node = Node(data)
        if self.head == None:#LL is empty
            self.head = new_node
            return

        temp = self.head
        while temp.next:
            temp = temp.next
        temp.next = new_node

    def DeleteFirst(self):
        if self.head == None:#LL is empty
            print("Linked-List is empty.")
            return
        
        if self.head.next == None:#LL has only one node
            self.head = None

        else:#LL has atleast one node
            self.head = self.head.next

    def DeleteLast(self):
        if self.head == None:
            print("Linked-List is empty.")
            return
        
        if self.head.next == None:
            self.head = None
            return

        temp = self.head
        while temp.next.next:
            temp = temp.next
        temp.next = None

    def Display(self):
        if self.head == None:
            print("List is empty.")
            return

        temp = self.head
        while temp != None:
            print(f"| {temp.data} | -> ", end="")
            temp = temp.next
        print("None")

    def Count(self):
        iCount = 0
        temp = self.head

        while temp != None:
            iCount += 1
            temp = temp.next
        return iCount


    def InsertAtPos(self,data,pos):
        new_node = Node(data)

        temp = self.head

        iCount = self.Count()

        if(pos < 1 or pos > iCount + 1):
            print("Invalid position")

        elif(pos == 1):
            self.InsertFirst(data)

        elif(pos == iCount + 1):
            self.InsertLast(data)

        else:
            for i in range(1,pos - 1):
                temp = temp.next

            new_node.next = temp.next
            temp.next = new_node


    def DeleteAtPos(self,pos):
        temp = self.head

        iCount = self.Count()

        if(pos < 1 or pos > iCount):
            print("Invalid position")

        elif(pos == 1):
            self.DeleteFirst()

        elif(pos == iCount):
            self.DeleteLast()

        else:
            for i in range(1,pos - 1):
                temp = temp.next
            target = temp.next
            temp.next = target.next

def main():

    sobj = SinglyLinearLL()

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