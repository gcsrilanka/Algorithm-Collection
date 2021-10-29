class Stack {
    static final int MAX = 100; // Maximum size of Stack
    int top;
    int a[] = new int[MAX];
    Stack() { top = -1; }

    boolean push(int x) {
        if (top >= (MAX - 1)) {
            System.out.println("Stack Overflow");
            return false;
        }
        else {
            a[++top] = x;
            return true;
        }
    }

    int pop() {
        if (top < 0) {
            System.out.println("Stack Underflow");
            return 0;
        }
        else {
            int x = a[top--];
            return x;
        }
    }

    int peek() {
        if (top < 0) {
            System.out.println("Stack Underflow");
            return 0;
        }
        else {
            int x = a[top];
            return x;
        }
    }

    boolean isEmpty() {
        return (top < 0);
    }
}

// Driver code
class Main {
    public static void main(String args[])
    {
        Stack stk = new Stack();
        stk.push(1);
        stk.push(2);
        stk.push(3);
        System.out.println("1, 2, 3 added to stack");

        // Pop up Stack
        System.out.println(stk.pop() + " Popped from stack");

        // Get the top values
        System.out.println(stk.peek() + " is the peek value");

        // isEmpty
        if (stk.isEmpty()){
            System.out.println("Empty");
        }
        else {
            System.out.println("Not empty");
        }
    }
}