public class Stack {

    stackNode head;

    public boolean isEmpty(){
        if(head == null){
            return true;
        }else{
            return false;
        }
    }

    public void push(char data){
        stackNode newNode = new stackNode(data);

        if(head == null){
            head = newNode;
        }else{
            newNode.next = head;
            head = newNode;
        }

    }

    public void pop(){

        head = head.next;

    }

    public char peek(){

       return head.data;

    }

    public void display(){

        stackNode currentNode = head;

        while(currentNode != null){
            System.out.println(currentNode.data);

            currentNode = currentNode.next;
        }

    }

}
