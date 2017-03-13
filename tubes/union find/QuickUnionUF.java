public class QuickUnionUF {
    private int[] id;

    public QuickUnionUF(int size) {
        id = new int[size];
        for(int i=0;i<size;i++) {
            id[i] = i;
        }
    }

    public boolean connected(int node1,int node2) {
        return root(node1) == root(node2);
    }

    public int root(int node) {
        while(id[node] != node) {
            
            node = id[node];
        }
        return node;
    }

    public void union(int node1,int node2) {
        int r1 = root(node1);
        int r2 = root(node1);
        id[r2] = r1;
    }

}