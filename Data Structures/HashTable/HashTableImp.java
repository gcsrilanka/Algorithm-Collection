import java.util.LinkedList;
import java.util.Optional;

/**
 * HashTable Implementation
 * Separate chaining with linked list to prevent collisions
 * HashTable for an HashEntry<int,T>
 * @author MarceStarlet
 */
public class HashTableImp<T> implements HashTable<T>{
	
	// the HashTable maximum size
	private static int HASTABLE_SIZE = 128;
	// the linked list of HashEntry<T> type
	private LinkedList<HashEntry<T>>[] hashTable;
	
	@SuppressWarnings("unchecked")
	public HashTableImp(){
		hashTable = new LinkedList[HASTABLE_SIZE];
		for(int i = 0; i < HASTABLE_SIZE; i++){
			hashTable[i] = null;
		}
	}

	@Override
	public T get(int key) {
		// hash the key
		int hash = hashInt(key);
		// get the linked list in the hash position
		LinkedList<HashEntry<T>> entryList = hashTable[hash];
		
		// return if null
		if(entryList == null)
			return null;
		
		// filter for the key and return the value
		Optional<HashEntry<T>> found = entryList.stream().filter(e -> e.getKey() == key).findFirst();
		
		return found.isPresent() ? found.get().getValue() : null;
	}

	@Override
	public void put(int key, T value) {
		// hash the key
		int hash = hashInt(key);
		// create new HashEntry
		HashEntry<T> entry = new HashEntry<T>(key, value);
		// get the linked list in the hash position
		LinkedList<HashEntry<T>> entryList = hashTable[hash];
		
		// if the position is null then create new LinkedList
		// and add the new HashEntry to the list
		if(null == entryList){
			entryList = new LinkedList<HashEntry<T>>();
			entryList.add(entry);
		}else{
			// else, ask if the new entry exists
			// if exists, replace the value
			// if does not exists, add to the current list
			int exists = entryList.indexOf(entry);
			if(exists >= 0){
				entryList.get(exists).setValue(value);
			}else{
				entryList.add(entry);
			}
		}
		// assign the new list in the hash position
		hashTable[hash] = entryList;
	}
	
	/**
	 * @param key
	 * @return hash code for the key given
	 */
	private int hashInt(int key){
		// simple hash, module of the key
		return key % HASTABLE_SIZE;
	}
	
	@Override
	public String toString(){
		StringBuilder str = new StringBuilder();
		LinkedList<HashEntry<T>> entryList;
		str.append("HashTable=[");
		for(int i = 0; i < HASTABLE_SIZE; i++){
			entryList = hashTable[i];
			if(null != entryList){
				entryList.stream().forEach(e -> str.append("{").append(e.getKey())
					.append(",").append(e.getValue()).append("}").append(","));
			}
		}
		str.replace(str.length()-1, str.length(), "");
		str.append("]");
		
		return str.toString();
	}

}
