

// Implementation
/*
1. Simple array based Implementation
2. Dynamic array based Implementation (Internal principle of List)
3. LinkedList based Implementation
*/

public class Main
{
	public static void main(String[] args) {
		StackLinkedList stack = new StackLinkedList();
		stack.push(10);
		stack.push(20);
		stack.push(30);
		stack.push(40);
		
		System.out.println(stack.pop());
		System.out.println(stack.pop());
		System.out.println(stack.pop());
		System.out.println(stack.pop());
		System.out.println(stack.pop());	
		
	}
}