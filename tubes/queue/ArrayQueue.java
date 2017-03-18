public class ArrayQueue<T> {
    
    private final T[] queue;
    private int head;
    private int tail;
    private int length;

    @SuppressWarnings("unchecked")
    public ArrayQueue(int size) {
        queue = (T[]) new Object[size];
        length = size;
        head = tail = -1;
    }

    public void enqueue(T value) throws Exception{
        if(!isFull()) {
            if(tail==-1 || tail==length-1) {
                tail=0;
                queue[tail]=value;
                if(head==-1)
                    head=0;
            }
            else {
                tail+=1;
                queue[tail] = value;
            }
        }
        else {
            throw new Exception("Overflow");
        }
    }

    public T dequeue() throws Exception{
        if(!isEmpty()) {
            T value = queue[head];
            if(head==tail)
                head=tail=-1;
            else if(head==length-1)
                head = 0;
            else
                head=head+1;
            return value;
        }
        else {
            throw new Exception("Underflow");
        }
    }

    public boolean isEmpty() {
        return head==-1;
    }

    public boolean isFull() {
        return head==tail+1 || (head==0 && tail==length-1);
    }

    public static void main(String[] args) {
        ArrayQueue<String> queue = new ArrayQueue<>(10);
        try {
            queue.enqueue("a");
            System.out.println(queue.dequeue());
        } catch(Exception e) {
            e.printStackTrace();
        }
    }
}