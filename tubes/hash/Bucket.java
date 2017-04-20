import Node;

public class Bucket<T> {
    private INode head;

    public Bucket() {
        head = new TermainalNode();
    }
    public void put(T data) {
        head = head.link(T);
    }

    public void remove(T data) {

    }

    public T[] getAll() {

    }

}