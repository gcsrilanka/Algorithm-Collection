class DoublyLinkedList {

    Node head;
    Node tail;

    //rear insertion
    public void insert(String pageName, int id, String data, String siteUrl, boolean bookmark){

        Node newNode = new Node(pageName, id, data, siteUrl, bookmark);

        if(head == null){
            head = newNode;
        }else {
            tail.next = newNode;
            newNode.prev = tail;
        }
        tail = newNode;
    }

//deletion 
    public void delete(int id){

        Node toDelete = search(id);

        if(toDelete != null){

            if(toDelete == head) {
                head.next.prev = null;
                head = head.next;
                System.out.println("Deleted : " + id);

            }else if(toDelete == tail){
                tail.prev.next = null;
                tail = tail.prev;
                System.out.println("Deleted  : " + id);

            }else {
                toDelete.prev.next  = toDelete.next;
                toDelete.next.prev = toDelete.prev;
                System.out.println("Deleted : " + id);
            }

        }
    }
//display list
    public void display(){
        Node current = head;

        while(current != null){
            System.out.println("id = " + current.id);

            current = current.next;
        }
    }

//serch list by id    
    private Node search(int id){

        Node current = head;

        while(current != null){
            if(current.id == id){
                return current;
            }
            current = current.next;
        }
        return null;
    }



}


class Node {

//I used sample data here

    String pageName;
    int id;
    String data;
    String siteUrl;
    boolean bookmark;

    Node next;
    Node prev;

    public Node(String pageName, int id, String data, String siteUrl, boolean bookmark) {
        this.pageName = pageName;
        this.id = id;
        this.data = data;
        this.siteUrl = siteUrl;
        this.bookmark = bookmark;

        Node next = null;
        Node prev = null;
    }
}



class Driver {

    public static void main(String[] args){
        DoublyLinkedList DoublyLinkedList = new DoublyLinkedList();


        DoublyLinkedList.insert("youtube" , 1001 , "10.01.2020 ", "www.youtube.com" , false);
        DoublyLinkedList.insert("whatsapp" , 1011 , "10.01.2020" , "www.whatsapp.com" , true);
        DoublyLinkedList.insert("facebook" , 1012 , "10.01.2020" , "www.facebook.com" , true);
        DoublyLinkedList.insert("github" , 1003 , "10.01.2020" , "www.github.com" , false);

        //DoublyLinkedList.delete(1001);
        //DoublyLinkedList.delete(1011);
        DoublyLinkedList.delete(1003);


        DoublyLinkedList.display();
        DoublyLinkedList.printBookmark();
    }


}
