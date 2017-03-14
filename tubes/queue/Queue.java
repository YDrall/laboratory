import java.lang.StringBuffer;

public class Queue<T> {

    private Node<T> head;
    private Node<T> tail;

    public Queue() {
    }

    public void enqueue(T value) {
        Node<T> node= new Node<T>(value,null);
        if(tail == null) {
            tail = head = node;
        }
        else {
            tail.setNext(node);
            tail = node;
        }
        
    }

    public T dequeue() {
        if(head == null)
            throw new IndexOutOfBoundsException("No element in list");
        Node<T> node = head;
        if(head==tail) {
            tail = head.getNext();
        }
        head = head.getNext();
        return node.getData();
    }

    public boolean isempty() {
        return head==null;
    }

    @Override
    public String toString() {
        StringBuffer string = new StringBuffer();
        Node<T> node = head;
        string.append("{ ");
        while(node!=null) {
            string.append(node.getData());
            node = node.getNext();
            string.append(", ");
        }
        string.append("}");
        return string.toString();
    }

    private class Node<T> {
        private T data;
        private Node<T> next;

        public Node(T data, Node<T> next) {
            this.data = data;
            this.next = next;
        }

        public T getData() {
            return this.data;
        }

        public Node<T> getNext() {
            return this.next;
        }

        public void setNext(Node<T> next) {
            this.next = next;
        }

        public void setData(T data) {
            this.data =data;
        }
    }

    public static void main(String[] args) {
        Queue<Integer> q = new Queue<>();
        q.enqueue(-10);
        System.out.println(q);
        q.dequeue();
        System.out.println(q);
        for(int i=0;i<10;i++) {
            q.enqueue(i);
        }
        System.out.println(q);
        q.dequeue();
        q.enqueue(-1);
        System.out.println(q);
        q.dequeue();
        System.out.println(q);
        // for(int i=0;i<10;i++) {
        //     System.out.println(q.dequeue());
        // }

    }

}