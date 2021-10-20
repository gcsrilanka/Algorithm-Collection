class SubsetSum {


	public static void main(String args[])
    {
        int set[] = { 5, 3, 4, 1, 8, 2 };
        int sum = 8;
        int n = set.length;
        if (sumOf(set, n, sum) == true)
            System.out.println("Found a subset");
                               
        else
            System.out.println("Not Found");
                               
    }


    static boolean sumOf(int set[],int n, int sum)
    {
        
        if (sum == 0)
            return true;
        if (n == 0)
            return false;
 
        
        if (set[n - 1] > sum)
            return sumOf(set, n - 1, sum);
 
        
        return sumOf(set, n - 1, sum) || sumOf(set, n - 1, sum - set[n - 1]);
    }
 
    
    
}