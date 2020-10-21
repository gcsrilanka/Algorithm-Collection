/**
 * List
 * A simple list definition with the four
 * basic operations: add, remove, get and size.
 * @author MarceStarlet
 * @param <T>
 */
public interface List<T> {

    /**
     * Adds a value to the end of the list
     * @param value
     * @return true if succeed
     */
    boolean add( T value );

    /**
     * Removes the value in the position <code>index</code>
     * @param index
     * @return true if succeed
     * @throws IndexOutOfBoundsException whether (index < 0 or index > size())
     */
    boolean remove( int index ) throws IndexOutOfBoundsException;

    /**
     * Gets the value in the position <code>index</code>
     * @param index
     * @return value type T
     * @throws IndexOutOfBoundsException whether (index < 0 or index > size())
     */
    T get( int index ) throws IndexOutOfBoundsException;

    /**
     * @return the number of elements in the list
     */
    int size();
}
