class Node:
    def __init__(self,No):
        self.data = No
        self.next = None
        self.prev = None

class DoublyCircularLL:
    def __init__(self):
        self.first = None
        self.last = None
        self.iCount = 0

    
##########################################################################################
 
    def Display(self):
        
        if(self.first is None):
            print("Linked List is Empty")
            return


        temp = self.first

        while True:
            print(f"<=> | {temp.data} | ",end="")
            temp = temp.next

            if temp == self.first:
                break

        print()  

########################################################################################## 

    def Count(self):
        
        return self.iCount

########################################################################################## 
    
    def InsertFirst(self,No):
        
        newn = Node(No)

        if(self.first == None and self.last == None):
            self.first = newn
            self.last = newn
            self.last.next = self.first
            self.first.prev = self.last

        else:
            newn.next = self.first
            self.first.prev = newn
            self.first = newn
            self.last.next = self.first
            self.first.prev = self.last


        self.iCount = self.iCount + 1        

###########################################################################################  
  
    def InsertLast(self,No):
        
        newn = Node(No)

        if(self.first == None and self.last == None):
            self.first = newn
            self.last = newn
            self.last.next = self.first
            self.first.prev = self.last

        else:
           self.last.next = newn
           newn.prev = self.last
           self.last = newn
           self.last.next = self.first
           self.first.prev = self.last

        self.iCount = self.iCount + 1        

###########################################################################################

    def DeleteFirst(self):

        if(self.first is None and self.last is None):
            print("Linked List is Empty")
            return
        
        elif(self.first == self.last):
            self.first = None
            self.last = None

        else:
           
           self.first = self.first.next
           del self.first.prev
           self.last.next = self.first
           self.first.prev = self.last

        self.iCount = self.iCount - 1    
 

###########################################################################################

    def DeleteLast(self):

        if(self.first is None and self.last is None):
            print("Linked List is Empty")
            return
        
        elif(self.first == self.last):
            self.first = None
            self.last = None

        else:
           self.last = self.last.prev
           del self.last.next
           self.last.next = self.first
           self.first.prev =  self.last
   
        self.iCount = self.iCount - 1    

###########################################################################################

    def InsertAtPos(self,no,pos):

        if pos < 1 or pos > self.iCount+1:
            print("Invalid Position")
            return
        
        if (pos == 1):
            self.InsertFirst(no)

        elif (pos == self.iCount + 1):
            self.InserLast(no)

        else:

            newn = Node(no)

            temp = self.first

            for i in range(1, pos - 1):
                temp = temp.next

            newn.next = temp.next
            temp.next = newn

        self.iCount = self.iCount + 1                
        

###########################################################################################

    def DeleteAtPos(self,pos):

        if pos < 1 or pos > self.iCount:
            print("Invalid Position")
            return
        
        if (pos == 1):
            self.DeleteFirst()

        elif (pos == self.iCount):
            self.DeleteLast()

        else:
        
            temp = self.first

            for i in range(1, pos - 1):
                temp = temp.next

            target = temp.next
            temp.next = target.next
            temp.next.prev = temp

            del target 

           
        self.iCount = self.iCount - 1                
    
###########################################################################################

    def CountEven(self):

        EvenCount = 0

        temp = self.first

        while True:
            if temp.data % 2 == 0:
                EvenCount = EvenCount + 1

            temp = temp.next
            if temp == self.first:
                break

        return EvenCount      

###########################################################################################

    def CountOdd(self):

        OddCount = 0

        temp = self.first

        while True:
            if temp.data % 2 != 0:
                OddCount = OddCount + 1

            temp = temp.next
            if temp == self.first:
                break

        return OddCount   
    
############################################################################################

    def Maximum(self):

        if self.first is None:
            return None
        
        maximum = self.first.data

        temp = self.first.next

        while temp != self.first:
            if temp.data > maximum:
                maximum = temp.data

            temp = temp.next 

        return maximum     
    
############################################################################################

    def Minimum(self):

        if self.first is None:
            return None
        
        minimum = self.first.data

        temp = self.first.next

        while temp != self.first:
            if temp.data < minimum:
                minimum = temp.data

            temp = temp.next 

        return minimum       

############################################################################################

    def Summation(self):

        if self.first is None:
            return 0
        
        sum  = 0

        temp = self.first

        while True:
            sum = sum + temp.data
            temp = temp.next

            if temp == self.first:
                break

        return sum    

############################################################################################     

    def Search(self,no):
       
       temp = self.first

       while True:
           if temp.data == no:
               return True
           temp = temp.next

           if temp == self.first:
               break
              
       return False

###########################################################################################
    
    def Frequency(self,no):

        Freq = 0

        temp = self.first
        Freq = 0

        while True:
            if temp.data == no:
                Freq = Freq + 1
            temp = temp.next

            if temp == self.first:
                break

        return Freq
            
###########################################################################################                  
        

def main():
    
    DoublyCircular = DoublyCircularLL()
    
    while True:
        print("----------------------------------------------------------------------------------")
        print("---------------------------- Doubly Circular Linked List ---------------------------")
        print("----------------------------------------------------------------------------------")

        print("1 : Insert at First")
        print("2 : Insert at Last")
        print("3 : Insert At Position")
        print("4 : Delete First")
        print("5 : Delete Last")
        print("6 : Delete At Position")
        print("7 : Display")
        print("8 : Count Total Nodes")
        print("9 : Count Even Elements")
        print("10 : Count Odd Elements")
        print("11 : Maximum Element")
        print("12 : Minimum Element")
        print("13 : Summation Of All Elements")
        print("14 : Search Element")
        print("15 : Frequency of Element")
        print("0 : Exit")

        choice = int(input("Enter your Choice : "))

        if(choice == 1):
            value = int(input("Enter the Value : "))
            DoublyCircular.InsertFirst(value)

        elif(choice == 2): 
            value = int(input("Enter the Value : "))
            DoublyCircular.InsertLast(value)

        elif(choice == 3): 
            value = int(input("Enter the Value : "))
            position = int(input("Enter the position : "))
            DoublyCircular.InsertAtPos(value,position)

        elif(choice == 4): 
            print("First node has been deleted.")
            DoublyCircular.DeleteFirst()

        elif(choice == 5):
            print("Last node has been deleted.")
            DoublyCircular.DeleteLast()

        elif(choice == 6): 
            position = int(input("Enter the position : "))
            DoublyCircular.DeleteAtPos(position)

        elif(choice == 7):  
            print("Display All Linked List : ")
            DoublyCircular.Display()

        elif(choice == 8): 
            iRet = DoublyCircular.Count()
            print("Total Nodes in Linked List are : ",iRet)

        elif(choice == 9):  
            iRet = DoublyCircular.CountEven()
            print("Total Even Nodes in Linked List are : ",iRet)

        elif(choice == 10): 
            iRet = DoublyCircular.CountOdd()
            print("Total Odd Nodes in Linked List are : ",iRet)

        elif(choice == 11):  
            iRet = DoublyCircular.Maximum()
            print("Maximum Nodes in Linked List is : ",iRet)

        elif(choice == 12):
            iRet = DoublyCircular.Minimum()
            print("Minimum Nodes in Linked List is : ",iRet)

        elif(choice == 13): 
            iRet = DoublyCircular.Summation()
            print("Summation of All Nodes is : ",iRet)

        elif(choice == 14):
            value = int(input("Enter the Value that you want to search : "))
            bRet = DoublyCircular.Search(value)

            if bRet:
                print("Element is Present")
            else:
                print("Elements is not Present")    

        elif(choice == 15): 
            value = int(input("Enter the Value that you want to Count Freqency : "))
            iRet = print(DoublyCircular.Frequency(value))

             
        elif(choice == 0):
            print("Thank You For using Doubly Circular Linked List Application.....!")   
            break

        else:    
            print("Invalid Choice...!")
    

    

if __name__ == "__main__":
    main()    