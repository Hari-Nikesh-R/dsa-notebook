// Implement using Dynamic array based Stack 
public class DynamicStack {
    private int[] array;
    private int top;
    private int capacity;

    public DynamicStack(int capacity) {
        this.capacity = capacity;
        this.array = new int[capacity];
        this.top = -1;
    }

    private void resize(int newCapacity) {
        int[] newArray = new int[newCapacity];
        for (int i = 0; i <= top; i++) {
            newArray[i] = array[i];
        }
        array = newArray;
        capacity = newCapacity;
    }

    public void push(int data) {
        if (top == capacity - 1) {
            resize(capacity * 2);
        }
        array[++top] = data;
        System.out.println("Added element " + data + " to the stack");
    }

    public int pop() {
        if (top == -1) {
            System.out.println("Stack underflow");
            return -1;
        }
        return array[top--];
    }

    public int topElement() {
        if (top == -1) {
            System.out.println("Stack is empty");
            return -1;
        }
        return array[top];
    }

    public boolean isEmpty() {
        return top == -1;
    }

    public void display() {
        for (int i = 0; i <= top; i++) {
            System.out.print(array[i] + " ");
        }
        System.out.println();
    }
}