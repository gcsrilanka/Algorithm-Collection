

public class Queue {

	 private QueueNode front;
	 private QueueNode back;
	 
	 Queue(){
		 this.front = null;
		 this.back = null;
	 }
	 
	 
	 boolean isEmpty() {
		 if(this.front == null) {
			 return true;
		 }else {
			 return false;
		 }
	 }
	 
	 void enqueue(int data) {
		 QueueNode newNode = new QueueNode(data);
		 
		 if(isEmpty()) {
			 this.front = newNode;
			 this.back = newNode;
		 }else {
			 this.back.setNext(newNode);
			 this.back = newNode;
		 }
	 }
	 
	 int dequeue() {
		 
		 if(isEmpty()) {
			 return 0;
		 }else {
			 QueueNode temp = this.front;
			 this.front = this.front.getNext();
			 
			 if(this.front == null) {
				 this.back = null;
			 }
			 
			 return temp.getData();
		 }
	 }
	 
	 void peek() {
		 if(isEmpty()) {
			 System.out.println("Empty Queue");
		 }else {
			 System.out.println(this.front.getData());
		 }
	 }
	 
	 void print() {
		 QueueNode temp = this.front;
		 
		 while(!isEmpty()) {
			 System.out.print(dequeue() +"  ");
			 temp = temp.getNext();
		 }
	 }
}
