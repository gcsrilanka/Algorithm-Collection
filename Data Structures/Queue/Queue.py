class Queue:
  def __init__(self):
         self.queue=[]
  def enque(self,item):
         self.queue.append(item) 
  def deque(self):
         if(len(self.queue)<1):
             return None
         return self.queue.pop(0)
  def display(self):
         print(self.queue)
obj=Queue()
while True:
   print("\nYour options")
   print("1.for Enqueue")
   print("2.for Deque")
   print("3.for Display")
   print("4. EXIT")
   choice=int(input("\n Enter any one of the above"))
   if(choice==1):
       k=int(input("Please Enter Your Value"))
       obj.enque(k)
   elif (choice==2):
       obj.deque()
   elif (choice==3):
       obj.display()
   elif (choice==4):
       break
   else:
      print("Enter an Valid option")

   
