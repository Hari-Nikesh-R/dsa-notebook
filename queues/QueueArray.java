package queues;

class QueueArray {
    int[] array;
    int front, rear, capacity;

    public QueueArray(int size) {
        this.capacity = size;
        this.array = new int[size];
        front = 0;
        rear = -1;
    }

    public void enqueue(int value) {
        if (rear == capacity - 1) {
            System.out.println("Queue overflow");
            return;
        }
        rear++;
        array[rear] = value;
    }

    public int dequeue() {
        if (front > rear) {
            System.out.println("Queue is underflow");
            return -1;
        }
        return array[front++];
    }

    public boolean isEmpty() {
        return front > rear;
    }

    public int peek() {
        if (front > rear) {
            System.out.println("Queue is underflow");
            return -1;
        }
        return array[front];
    }
}
