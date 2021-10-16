

public class QueueNode {
	
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
