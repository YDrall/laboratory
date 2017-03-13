public class Vector {

    private static final int DEFAULT_VECTOR_SIZE = 16;
    private static final int CHUNK_SIZE = 4;
    private Chunk[] chunks;
    private int chunksCount=0;
    private int lastIndex;
    
    Vector() {
        chunks = new Chunk[CHUNK_SIZE];
        chunks[0] = new Chunk(DEFAULT_VECTOR_SIZE);
        chunksCount = 1;
        lastIndex = -1;
    }

    public void insert(int value) {
        // get last index and
        //insert at index+1 if space left otherwise add more space
        if((lastIndex+1)>chunksCount*DEFAULT_VECTOR_SIZE-1) {
            addChunk();
        }
        System.out.println("itemIndex: "+getItemIndex()+" chunkIndex: "+(chunksCount-1)+" value: "+value);
        chunks[chunksCount-1].insert(getItemIndex(), value);
        lastIndex +=1;
    }

    private int getChunkIndexFor(int forIndex) {
        return (forIndex)/DEFAULT_VECTOR_SIZE;
    }

    private int getItemIndex() {
        return ((lastIndex+1)%DEFAULT_VECTOR_SIZE);
    }

    public void addChunk() {
        chunks[chunksCount] = new Chunk(DEFAULT_VECTOR_SIZE);
        chunksCount +=1;
    }

    public int at(int index) {
        return chunks[getChunkIndexFor(index)].at(index%(DEFAULT_VECTOR_SIZE));
    }

    private class Chunk {

        private int[] array;
        Chunk(int size) {
            array = new int[size];
        }

        public int at(int index) {
            return array[index];
        }

        public void insert(int index,int value) {
            array[index] = value;
        }
    }

    public static void main(String[] args) {
        Vector vector = new Vector();
        for(int i=0;i<64;i++)
            vector.insert(i);
        
        for(int i=0;i<64;i++)
            System.out.println(vector.at(i));
        
    }
}