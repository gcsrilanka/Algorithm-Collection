/**
 * LinkedList implementation
 * A single linked list implementation with the four
 * basic operations: add, remove, get and size.
 * This linked list implementation uses an internal Node class
 * to keep the value and the pointer to the next Node in the list
 * @param <T>
 */
public class LinkedList<T> implements List<T>{

    // the head of the list
    private Node<T> head;
    // to handle the size of the list
    private int size = 0;

    public LinkedList(){
        // init the head with an empty Node
        this.head = new Node<>();
    }


    @Override
    public boolean add(T value) {
        try{
            Node<T> aux = this.head; // we always start at head
            while ( aux.getNext() != null ){ // get next Node until getNext() != null
                aux = aux.getNext();
            }

            aux.setNext( new Node<>( value ) ); // create new Node using the value passed
            size = size + 1;
        }catch ( Exception e ){
            return false;
        }
        return true;
    }

    @Override
    public boolean remove(int index) throws IndexOutOfBoundsException {
        // index is not valid?
        if( index < 0 || index > size() ) {
            throw new IndexOutOfBoundsException();
        }

        Node<T> aux = this.head; // we always start at head
        try{
            for (int i = 0; i < index && aux.getNext() != null; i++) { // iterate up to index
                aux = aux.getNext();
            }

            // remove the Node by re-assign the 'Node.next' to the next  Node in the list
            aux.setNext( aux.getNext().getNext() );
            size = size - 1;
        }catch ( Exception e ){
            return false;
        }

        return true;
    }

    /**
     * Removes the first occurrence of the value from the list
     * @param value
     * @return true if succeed
     */
    public boolean remove(T value) {
        Node<T> aux = this.head; // we always start at head
        if (null != value) {
            while (!value.equals(aux.getNext().getValue())) { // iterate until values are equals
                aux = aux.getNext();
            }

            // remove the Node by re-assign the 'Node.next' to the next  Node in the list
            aux.setNext(aux.getNext().getNext());
            size = size - 1;
        }else{
            return false;
        }

        return true;
    }

    @Override
    public T get(int index) throws IndexOutOfBoundsException {
        // index is not valid?
        if( index < 0 || index > size() ) {
            throw new IndexOutOfBoundsException();
        }

        Node<T> aux = this.head; // we always start at head
        for (int i = 0; i <= index && aux.getNext() != null; i++){  // iterate up to index
            aux = aux.getNext();
        }

        return aux.getValue();
    }

    @Override
    public int size() {
        return size;
    }

    @Override
    public String toString(){
        StringBuilder str = new StringBuilder("");
        str.append("LinkedList={");

        Node<T> aux = this.head; // we always start at head
        while ( aux.getNext() != null ) {
            aux = aux.getNext();
            str.append( aux.toString() ).append(",");
        }
        str.replace(str.length()-1, str.length(), "}");

        return str.toString();
    }

    /**
     * Node abstracts the elements in the list, keeps
     * the value and points to the next Node in the list
     * @param <E>
     */
    class Node<E> {

        private E value;
        private Node<E> next;

        public Node( E value ){
            this.value = value;
        }

        public Node() {

        }

        public E getValue() {
            return value;
        }

        public Node<E> getNext() {
            return next;
        }

        public void setNext(Node<E> next) {
            this.next = next;
        }

        @Override
        public String toString(){
            return this.getValue().toString();
        }
    }
}
