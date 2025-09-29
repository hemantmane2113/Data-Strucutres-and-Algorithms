class node:
    def __init__(self,data):
        self.data = data 
        self.next = None

class StackXX:
    def __init__(self):
        self.head = None

    def Push(self,data):#insert first
        new_node = node(data)

        new_node.next = self.head
        self.head = new_node
    
    def Pop(self):
        temp = self.head
        if(self.head == None):
            print("Unable to pop as stack is empty.\n")
            return
        
        iValue = temp
        self.head = self.head.next
        return iValue.data

    def Display(self):
        temp = self.head
        while(temp != None):
            print(f"|  {temp.data} |")
            temp = temp.next
    
    def Count(self):
        iCount = 0
        temp = self.head
        while(temp != None):
            iCount = iCount + 1
            temp = temp.next
        return iCount
    
def main():
    sobj = StackXX()

    sobj.Push(10)
    sobj.Push(20)
    sobj.Push(30)
    sobj.Push(40)
    sobj.Push(50)

    sobj.Display()

    iRet = sobj.Count()

    print("The total number of elements in the stack are: ",iRet)

    iRet = sobj.Pop()
    print("Popping element: ",iRet)

    sobj.Display()

    iRet = sobj.Pop()
    print("Popping element: ",iRet)

    sobj.Display()

    iRet = sobj.Pop()
    print("Popping element: ",iRet)

    sobj.Display()

    iRet = sobj.Count()

    print("The total number of elements in the stack are: ",iRet)



    




if __name__ == "__main__":
    main()

