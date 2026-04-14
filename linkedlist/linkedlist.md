# Linked List

Linked
list is a data structure for storing collection of data like array.

It has some properties that is different from arrays

1. Elements or a node is connected by pointers.
2. Last Node's address will be pointing to NULL.
3. We can also shrink or increase the size of the linkedList dynamically during the code execution.
4. Traversal is done via `head` reference.
5. Does not waste the memory space.

## Create a LinkedList

## Algorithm

### Step 1

We create the structure of the node

```java
public static class Node {
        int data;
        Node next;

        public Node(int data) {
            this.data = data;
            this.next = null;
        }
    }
```

### Step 2

Declare the head variable to keep the track of the head all the time.

### Step 3

Create a function to insert the element into the linkedlist, it can be insertAtBeginning or insertAtEnd or insertAt`somewhere`middle.
In below example we did insertionAtend

```java
  public void insertAtEnd(int data) {
        // This is how we create a new node.
        Node newNode = new Node(data);

         if (head == null) {
             head = newNode;
             return;
         }

         // We don't want to lose the head, so we will create a temp
         Node temp = head;
         while (temp.next != null) {
             temp = temp.next;
         }

         temp.next = newNode;
    }
```

### Step 4

We write a display function to print all the element in the linkedList

```java
  public void display() {
        // We don't want to lose the head, so we will create a temp
        Node temp = head;

        while (temp != null) {
            System.out.print(temp.data + " -> ");
            temp = temp.next;
        }
        System.out.print("NULL");
    }
```

## Step 5

We can also write function to delete, search and Identifying the size of the linkedList.<br>
<strong>Can take this as exercise.</strong>

## Programs to practice

https://leetcode.com/problem-list/linked-list
