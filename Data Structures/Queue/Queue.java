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

class QueueNode {
	
//you can define any type of data in here
	private int data;
	private QueueNode next;
	
	QueueNode(int data){
		this.data = data;
		this.next = null;
	}

	public int getData() {
		return data;
	}

	public void setData(int data) {
		this.data = data;
	}

	public QueueNode getNext() {
		return next;
	}

	public void setNext(QueueNode next) {
		this.next = next;
	}
	
	

}