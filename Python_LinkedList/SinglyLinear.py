class Node:
    def __init__(self,No):
        self.data = No
        self.next = None

class SinglyLinearLL:
    def __init__(self):
        self.first = None
        self.iCount = 0

    #8
########################################################################################## 
    
    def InsertFirst(self,No):
        newn = Node(No)

        if(self.first == None):  # LL is Empty
            self.first = newn

        else:              # LL contains  at least 1 node
            newn.next = self.first
            self.first = newn

        self.iCount = self.iCount +1   

########################################################################################### 

    def InsertLast(self,No):
        newn = Node(No)

        if(self.first == None):  # LL is Empty
            self.first = newn

        else:              # LL contains  at least 1 node
            temp = self.first
            
            while(temp.next != None):
                temp = temp.next

            temp.next = newn 
            
        self.iCount = self.iCount + 1    


########################################################################################## 
    
    def DeleteFirst(self):
        
        if(self.first == None):
            print("LL is empty ")
            return
        else:
            temp = self.first
            self.first = self.first.next
            del temp


            self.iCount = self.iCount - 1    
       

########################################################################################### 

    def DeleteLast(self):
            
            if(self.first == None):         # LL is empty
                print("LL is empty ")
                return
            elif(self.first.next == None):               # LL contains 1 node
                del self.first
                self.first = None

            else:                           # LL contains more than 1 node
                
                temp = self.first 
                while(temp.next.next != None):
                    temp = temp.next

                del temp.next
                temp.next = None
                
            self.iCount = self.iCount - 1        
       

########################################################################################### 

    def InsertAtPos(self,No,pos):

        if(pos < 1 or pos > self.iCount+1):
            print("Invalid Position")
            return
        
        if(pos == 1):
            self.InsertFirst(No)

        elif(pos == self.iCount+1):
            self.InsertLast(No)

        else:
            newn = Node(No)    
            temp = self.first

            for i in range(1,pos-1,1):
                temp = temp.next

            newn.next = temp.next
            temp.next = newn

            self.iCount = self.iCount + 1

###########################################################################################
 
    def DeleteAtPos(self,pos):

        if(pos < 1 or pos > self.iCount):
            print("Invalid Position")
            return
        
        if(pos == 1):
            self.DeleteFirst()

        elif(pos == self.iCount):
            self.DeleteLast()

        else:  
            temp = self.first

            for i in range(1,pos-1,1):
                temp = temp.next

            target = temp.next
            temp.next = target.next
            
            del target


            
            self.iCount = self.iCount - 1


################################################################################## 

    def CountEven(self):
        
        EvenCount = 0

        temp = self.first

        while(temp != None):
            if(temp.data % 2 == 0):
                EvenCount += 1
            temp = temp.next

        return EvenCount        

        
################################################################################## 
    
    def CountOdd(self):
        
        EvenOdd = 0

        temp = self.first

        while(temp != None):
            if(temp.data % 2 != 0):
                EvenOdd += 1
            temp = temp.next

        return EvenOdd     
    
################################################################################## 

    def Maximum(self):
        
        Max = self.first.data

        temp = self.first.next

        while(temp != None):
            if(Max < temp.data):
               Max = temp.data
            temp = temp.next

        return Max    
    
################################################################################## 

    def Minimum(self):
        
        Min = self.first.data

        temp = self.first.next

        while(temp != None):
            if(Min > temp.data):
               Min = temp.data
            temp = temp.next

        return Min    
    
################################################################################## 

    def Summation(self):
        
        Sum = 0

        temp = self.first
        while(temp != None):
            Sum = Sum + temp.data
            temp = temp.next

        return Sum    
    
################################################################################## 

    def Search(self,No):
        
        temp = self.first

        while(temp is not None):
            if(temp.data == No):
                return True
            temp = temp.next

        return False    
    
################################################################################## 

    def Frequency(self,No):
        
        Frequncy = 0

        temp = self.first

        while(temp is not None):
            if(temp.data == No):
                Frequncy = Frequncy +  1
            temp = temp.next

        return Frequncy    
    
################################################################################## 

    def Display(self):
        
        temp = self.first

        print("None <=> ",end="")
        while(temp != None):
            print(f"| {temp.data} | <=> ",end = "")
            temp = temp.next

        print("None",end="\n")

##################################################################################          

    def Count(self):
        
        return self.iCount

################################################################################## 

    def Display(self):
        temp = self.first

        while(temp != None):
            print(f"| {temp.data} | -> ", end = "")
            temp = temp.next

        print("None")
        
########################################################################################## 
    
    def Count(self):
        return self.iCount


########################################################################################## 



def main():

    SinglyLinear = SinglyLinearLL()
    
    while True:
        print("----------------------------------------------------------------------------------")
        print("---------------------------- Singly Linear Linked List ---------------------------")
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
            SinglyLinear.InsertFirst(value)

        elif(choice == 2): 
            value = int(input("Enter the Value : "))
            SinglyLinear.InsertLast(value)

        elif(choice == 3): 
            value = int(input("Enter the Value : "))
            position = int(input("Enter the position : "))
            SinglyLinear.InsertAtPos(value,position)

        elif(choice == 4): 
            print("First node has been deleted.")
            SinglyLinear.DeleteFirst()

        elif(choice == 5):
            print("Last node has been deleted.")
            SinglyLinear.DeleteLast()

        elif(choice == 6): 
            position = int(input("Enter the position : "))
            SinglyLinear.DeleteAtPos(position)

        elif(choice == 7):  
            print("Display All Linked List : ")
            SinglyLinear.Display()

        elif(choice == 8): 
            iRet = SinglyLinear.Count()
            print("Total Nodes in Linked List are : ",iRet)

        elif(choice == 9):  
            iRet = SinglyLinear.CountEven()
            print("Total Even Nodes in Linked List are : ",iRet)

        elif(choice == 10): 
            iRet = SinglyLinear.CountOdd()
            print("Total Odd Nodes in Linked List are : ",iRet)

        elif(choice == 11):  
            iRet = SinglyLinear.Maximum()
            print("Maximum Nodes in Linked List is : ",iRet)

        elif(choice == 12):
            iRet = SinglyLinear.Minimum()
            print("Minimum Nodes in Linked List is : ",iRet)

        elif(choice == 13): 
            iRet = SinglyLinear.Summation()
            print("Summation of All Nodes is : ",iRet)

        elif(choice == 14):
            value = int(input("Enter the Value that you want to search : "))
            bRet = SinglyLinear.Search(value)

            if bRet:
                print("Element is Present")
            else:
                print("Elements is not Present")    

        elif(choice == 15): 
            value = int(input("Enter the Value that you want to Count Freqency : "))
            iRet = print(SinglyLinear.Frequency(value))

             
        elif(choice == 0):
            print("Thank You For using Singly Linear Linked List Application.....!")   
            break

        else:    
            print("Invalid Choice...!")

    

if __name__ == "__main__":
    main()    