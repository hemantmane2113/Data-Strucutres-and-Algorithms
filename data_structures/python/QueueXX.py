class node:
    def __init__(self,data):
        self.data = data
        self.next = None
    
class QueueXX:
    def __init__(self):
        self.head = None

    def Enqueue(self,data):#insert last
        new_node = node(data)
        temp = self.head

        if(self.head == None):
            self.head = new_node
            return
        
        while(temp.next != None):
            temp = temp.next
        temp.next = new_node

    def Dequeue(self):

        if(self.head == None):
            print("Unable to Dequeue as queue is empty.\n")
            return

        temp = self.head
        iValue = temp

        self.head = self.head.next
        return iValue.data
    
    def Display(self):
        temp = self.head

        if(self.head == None):
            print("Unable to display as queue is empty.\n")
            return
        while(temp != None):
            print(f"| {temp.data} |",end = " ")
            temp = temp.next
        print("\n")

    def Count(self):
        temp = self.head
        iCount = 0

        if(self.head == None):
            print("Unable to Count as queue is empty.\n")
            return
        while(temp != None):
            iCount =  iCount + 1
            temp = temp.next
        return iCount
def main():
    sobj = QueueXX()

    sobj.Enqueue(10)
    sobj.Enqueue(20)
    sobj.Enqueue(30)
    sobj.Enqueue(40)
    sobj.Enqueue(50)

    sobj.Display()

    iRet = sobj.Count()

    print("The number of elements in the queue are: ",iRet)
    print("\n")

    iRet = sobj.Dequeue()
    print("The dequeuing element: ",iRet)

    sobj.Display()

    iRet = sobj.Dequeue()
    print("The dequeuing element: ",iRet)

    sobj.Display()


    iRet = sobj.Dequeue()
    print("The dequeuing element: ",iRet)

    sobj.Display()

    iRet = sobj.Count()

    print("The number of elements in the queue are: ",iRet)

if __name__ == "__main__":
    main()


        





