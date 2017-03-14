public class ArrayQueue<T> {
    
    private final T[] queue;
    private int head;
    private int tail;

    @SuppressWarnings("unchecked")
    public ArrayQueue(int size) {
        // @SuppressWarnings("unchecked")
        queue = (T[]) new Object[size];
        head = tail = 0;
    }

    public void enqueue(T value) {

    }

    public T dequeue() {

    }

    public boolean isEmpty() {
        return head==tail;
    }

    public static void main(String[] args) {
        ArrayQueue queue = new ArrayQueue(20);
    }

}