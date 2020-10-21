class Fibonacci{
    static long memo[];
    
    static long fib(int n){
        long result = 0;
        if(memo[n] != 0)  return memo[n];

        if(n == 1 || n == 2) result = 1; 

        else result = fib(n-1) + fib(n-2);

        memo[n] = result;
        
        return result;
    }
    public static void main(String[] args) {
        int n = 50;
        memo = new long[n+1];
        System.out.println(fib(n));
    }
}