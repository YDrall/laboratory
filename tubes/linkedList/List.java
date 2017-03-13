import java.lang.StringBuilder;

public class List<T> {

    private Node<T> head;
    private Node<T> tail;
    private int size;


    public List() {
        this(null);
    }

    public List(Node<T> head) {
        this(head,null);
    }

    public List(Node<T> head, Node<T> tail) {
        this.head = head;
        this.tail = tail;
    }

    public boolean isempty() {
        return head==null;
    }

    public T valueAt(int index) {
        Node<T> n = head;
        int count=0;
        while(n !=null && count!=index) {
            n=n.next();
            count+=1;
        }

        if(n==null) {
            throw new IndexOutOfBoundsException();
        }
        return n.data();
    }

    public void reverse() {
        Node<T> node = head;
        Node<T> prev = null;
        Node<T> tmp = null;
        while(node !=null) {
            tmp = node.next();
            node.setNext(prev);
            prev = node;
            node = tmp;
        }

        head = prev;
    }

    public void prepend(T data) {
        Node<T> n = new Node<T>(data,null);
        n.setNext(this.head);
        this.head = n;
        size++;
    }

    public void append(T data) {
        if(head==null) {
            head = new Node<T>(data,null);
            return;
        }
        Node<T> node = head;
        while(node.next()!=null) {
            node = node.next();
        }
        node.setNext(new Node<T>(data, null));
        size++;
    }

    public Node<T> first() {
        return head;
    }
    public Node<T> middle(Node<T> node) {
        if(node==null)
            throw new NullPointerException("Parameter is null");
        Node<T> slow = node;
        Node<T> fast = node;
        while(fast.next()!=null) {
            fast = fast.next().next();
            slow = slow.next();
        }
        return slow;
    }

    public Node<T> last(Node<T> node) {
        if(n==null)
            throw new NullPointerException("Parameter is null");
        Node<T> n = node;
        while(n.next()!=null) {
            n=n.next();
        }
        return n;
    }

    // public void sort() {
    //     Node<T> n = head;
        
    // }

    
    
    @Override
    public String toString() {
        StringBuilder string = new StringBuilder();
        string.append("{ ");
        Node<T> node = head;

        while(node!=null) {
            string.append(node.data());
            string.append(", ");
            node = node.next();
        }
        string.append("}");
        return string.toString();
    }
    
    public class Node<P> {
        private P data;
        private Node<P> next;
    
        public Node(P data, Node<P> next){
            this.data = data;
            this.next= next;
        }

        public Node<P> next() {
            return this.next;
        }

        public void setNext(Node<P> node) {
            this.next = node;
        }

        public P data() {
            return this.data;
        }

        public void setData(P data) {
            this.data = data;
        }

    }

    public static void main(String[] agrs) {
        List<Integer> list = new List<>();
        for(int i=0;i<8;i++)
            list.append(i);
        System.out.println(list);
         list.reverse();
        System.out.println(list);
        System.out.println(list.valueAt(4));
        list.prepend(-1);
        System.out.println(list);
        
    }
}