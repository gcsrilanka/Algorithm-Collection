public class DisjointSet {
        private int[] parent;

        public DisjointSet(int n) {
            parent = new int[n];
            for (var i = 0; i < n; i++) {
                parent[i] = i;
            }
        }

        public int find(int x) {
            if (x == parent[x]) {
                return x;
            }
            // compress the paths
            return parent[x] = find(parent[x]);
        }

        public void union(int x, int y)  {
            var px = find(x);
            var py = find(y);
            if (px != py) {
                parent[px] = py;
            }
        }
        // number of groups
        public int size() {
            int ans = 0;
            for (int i = 0; i < parent.length; ++ i) {
                if (i == parent[i]) ans ++;
            }
            return ans;
        }

        public static void main(String[] args) {
            var ds = new DisjointSet(5);
            System.out.println(ds.find(3));

            ds.union(3, 4);
            System.out.println(ds.find(3)); // after join, 3's parent is 4.
        }
    }