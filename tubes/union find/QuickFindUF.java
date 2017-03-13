public class QuickFindUF {

    private int[] id;

    public QuickFindUF(int size) {
        id = new int[size];
        for(int i=0;i<size;i++)
            id[i] = i;
    }

    public boolean connected(int p, int q) {
        return id[p]==id[q];
    }

    public void union(int p, int q) {
        int pid = id[p];
        int qid = id[q];
        for(int i=0;i<id.length;i++) {
            if(id[i]==pid)
                id[i]=qid;
        }
    }

    public static void main(String[] args) {
        String testFilename = "test.txt";
        String resultsFilename = "results.txt";
        try(BufferedReader reader= new BufferedReader(new FileReader(filename))) {
            int testCases = Integer.parseInt(reader.readLine());
            for(int i=0;i<testCases;i++) {
                String metaData = reader.readLine().split();
                int size = Integer.parseInt(reader.readLine());
                QuickFindUF uf = new QuickFindUF(size);
                String[] command = reader.readLine().split();

                // incomplete
            }
        }
        catch(IoException e) {
            e.printStackTrace();
        }
        catch(NumberFormatException e) {
            e.printStackTrace();
        }
    }
}