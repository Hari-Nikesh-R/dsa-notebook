package queues;

public class Main {
    public static void main(String[] args) {
        QueueArray queue = new QueueArray(5);
        queue.enqueue(1);
        queue.enqueue(5);
        queue.enqueue(10);
        queue.enqueue(2);

        System.out.println(queue.dequeue());
        System.out.println(queue.dequeue());
        System.out.println(queue.peek());
        System.out.println(queue.dequeue());

    }
}
