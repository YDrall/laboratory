import java.lang.StringBuilder;

public class DList<T> {

    private Node<T> head;
    private Node<T> tail;
    private int size=0;

    public void append(T data) {
        Node<T> node = new Node<T>(data,null,null);
        if(head==null) {
            tail = head = node;
            size+=1;
            return;
        }
        tail.setNext(node);
        node.setPrev(tail);
        tail = node;
        size+=1;
    }

    public void prepend(T data) {
        Node<T> node = new Node<T>(data,null, null);
        if(head==null) {
            tail = head = node;
            size+=1;
            return;
        }
        head.setPrev(node);
        node.setNext(head);
        head =node;
        size+=1;
    }

    public T at(int index) {
        if(index>this.size-1)
            throw new IndexOutOfBoundsException();
        if(index<0)
            index = size - index%size;
        Node<T> node = head;
        int count = 0;
        while(count !=index)
            node = node.getNext();
        return node.getData();
    }


    public void deleteAt(int index) {
        if(index>this.size-1)
            throw new IndexOutOfBoundsException();
        if(index<0)
            index = size - index%size;
        Node<T> node = head;
        int count = 0;
        while(count !=index) {
            node = node.getNext();
            count+=1;
        }
        if(head==tail) {
            head = tail = null;
            return;
        }
        if(node==head)
            head=node.getNext();
        else if(node==tail)
            tail=node.getPrev();
        else {
            node.getPrev().setNext(node.getNext());
            node.getNext().setPrev(node.getPrev());
        }
        size-=1;
    }

    public void insertAfter(int index, T value) {
        if(index>this.size-1)
            throw new IndexOutOfBoundsException();
        if(index<0)
            index = size - index%size;
        Node<T> node = head;
        int count = 0;
        while(count !=index) {
            node = node.getNext();
            count+=1;
        }
        if(node==head)
            this.prepend(value);
        else if(node==tail)
            this.append(value);
        else {
            Node<T> newNode = new Node<T>(value,node.getNext(),node);
            node.getNext().setPrev(newNode);
            node.setNext(newNode);
            size+=1;
        }
    }

    public T pop() {
        if(tail==null)
            throw new IndexOutOfBoundsException();
        Node<T> node = tail;
        if(head==tail) {
            head=tail=null;
            size-=1;
            return node.getData();
        }
        tail = tail.getPrev();
        tail.setNext(null);
        node.setPrev(null);
        size-=1;
        return node.getData();
    }

    public int size() {
        return size;
    }

    @Override
    public String toString() {
        Node<T> node = head;
        StringBuilder builder = new StringBuilder();
        builder.append("{ ");
        while(node!=null) {
            builder.append(node.getData() + ", ");
            node = node.getNext();
        }
        builder.append("}");
        return builder.toString();
    }

    private class Node<T> {
        private T data;
        private Node<T> next;
        private Node<T> prev;

        public Node(T data, Node<T> next, Node<T> prev) {
            this.data=data;
            this.next = next;
            this.prev = prev;
        }

        public Node<T> getNext() {
            return this.next;
        }

        public Node<T> getPrev() {
            return this.prev;
        }

        public T getData() {
            return this.data;
        }

        public void setData(T data) {
            this.data = data;
        }

        public void setNext(Node<T> node) {
            this.next =node;
        }

        public void setPrev(Node<T> node) {
            this.prev = node;
        }
    }

    public static void main(String[] args) {
        DList<Integer> list = new DList<>();
        list.append(1);
        System.out.println(list.pop());
        for(int i=0;i<5;i++)
            list.append(i);
        System.out.println(list.size());
        System.out.println(list);
        list.pop();
        list.prepend(23);
        System.out.println(list);
        System.out.println(list.size());
        list.insertAfter(3,44);
        System.out.println(list);
        list.deleteAt(3);
        System.out.println(list);
        list.deleteAt(0);
        System.out.println(list);
        list.deleteAt(2);
        System.out.println(list);

    }
}