class Node {
    int data;
    Node next;

    public Node(int data) {
        this.data = data;
        this.next = null;
    }
}

class StackLinkedList {
    private Node head;

    public StackLinkedList() {
        this.head = null;
    }

    public void push(int data) {
        Node newNode = new Node(data);
        newNode.next = head;
        head = newNode;
    }

    public int pop() {
        if (head == null) {
            System.out.println("Stack is Empty");
            return -1;
        }
        int value = head.data;
        head = head.next;
        return value;
    }

}