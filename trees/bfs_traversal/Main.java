package trees.bfs_traversal;
// Level order traversal

import java.util.*;

class Node {
    int data;
    Node left, right;

    public Node(int value) {
        this.data = value;
        left = right = null;
    }
}

public class Main {
    public static void levelOrder(Node root) {

        if (root == null) {
            return;
        }

        Queue<Node> queue = new LinkedList<>();
        queue.add(root);

        while (!queue.isEmpty()) {
            Node current = queue.poll();
            System.out.print(current.data + ", ");

            if (current.left != null) {
                queue.add(current.left);
            }
            if (current.right != null) {
                queue.add(current.right);
            }

        }

    }

    public static void main(String[] args) {
        Node root = new Node(0);
        root.left = new Node(5);
        root.left.left = new Node(3);
        root.right = new Node(2);
        root.right.right = new Node(4);
        root.right.right.left = new Node(1);
        root.right.right.right = new Node(10);

        levelOrder(root);

    }
}
