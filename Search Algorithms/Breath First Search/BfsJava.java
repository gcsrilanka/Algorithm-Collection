import java.util.Iterator;
import java.util.LinkedList;

public class BfsJava {
    // number of nodes
    private final int numberOfVerities;
    // represent the graph
    private final LinkedList<Integer>[] graph;

    BfsJava(int nodes) {
        numberOfVerities = nodes;
        graph = new LinkedList[nodes];
        // implement the graph
        for (int i = 0; i < nodes; ++i)
            graph[i] = new LinkedList();
    }


    // add edge to the graph
    void addEdge(int statNode, int endNode) {
        graph[statNode].add(endNode);
    }

    // implement the bfs
    void BFS(int startingNode) {
        // keeping visited nodes
        boolean[] visited = new boolean[numberOfVerities];
        // implement the queue for the bfs
        LinkedList<Integer> queue = new LinkedList<Integer>();

        visited[startingNode] = true;
        queue.add(startingNode);

        while (queue.size() != 0) {
            // get first item from queue
            startingNode = queue.poll();
            System.out.print(startingNode + " ");

            Iterator<Integer> i = graph[startingNode].listIterator();
            while (i.hasNext()) {
                int n = i.next();
                if (!visited[n]) {
                    visited[n] = true;
                    queue.add(n);
                }
            }
        }
    }

    //
    public static void main(String[] args) {
        BfsJava bfsImp = new BfsJava(6);

        bfsImp.addEdge(0, 1);
        bfsImp.addEdge(0, 4);
        bfsImp.addEdge(4, 1);
        bfsImp.addEdge(1, 2);
        bfsImp.addEdge(2, 3);
        bfsImp.addEdge(4, 3);
        bfsImp.addEdge(3, 5);

        System.out.println("bfs :");

        bfsImp.BFS(0);
    }
}

