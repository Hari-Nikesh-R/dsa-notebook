package trees.dfs_traversal;

public class Main {

    static void inorder(Node root) {
        if (root == null) {
            return;
        }

        inorder(root.left);
        System.out.print(root.data + ", ");
        inorder(root.right);
    }

    static void preOrder(Node root) {
        if (root == null) {
            return;
        }

        System.out.print(root.data + ", ");
        inorder(root.left);
        inorder(root.right);
    }

    static void postOrder(Node root) {
        if (root == null) {
            return;
        }

        inorder(root.left);
        inorder(root.right);
        System.out.print(root.data + ", ");
    }

    public static void main(String[] args) {
        Node root = new Node(2);
        root.left = new Node(0);
        root.right = new Node(1);

        root.left.left = new Node(5);
        root.left.right = new Node(4);

        root.right.right = new Node(3);

        System.out.println("Tree created successfully..");

        inorder(root);
        System.out.println();
        preOrder(root);
        System.out.println();
        postOrder(root);

    }
}