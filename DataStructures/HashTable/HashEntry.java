/**
 * HashEntry<int,value> for the HashTable implementation
 * @author MarceStarlet
 */
public class HashEntry<E> implements Comparable<HashEntry<E>>{
	
	private int key;
	private E value;
	
	public HashEntry(int key, E value){
		this.key = key;
		this.value = value;
	}

	/**
	 * @return int key
	 */
	public int getKey() {
		return key;
	}

	/**
	 * @return <code>E</code> value
	 */
	public E getValue() {
		return value;
	}
	
	/**
	 * set <code>E</code> value
	 * @param value
	 */
	public void setValue(E value){
		this.value = value;
	}
	
	@Override
	public int hashCode(){
		return key;
	}

	@Override
	public int compareTo(HashEntry<E> o) {
		// compare for keys 
		return this.key == o.key ? 0 : -1;
	}
	
	@Override
	@SuppressWarnings("unchecked")
	public boolean equals(Object o){
		// define equals from keys
		return ((HashEntry<E>) o).getKey() == this.getKey() ? true : false;
	}

}
