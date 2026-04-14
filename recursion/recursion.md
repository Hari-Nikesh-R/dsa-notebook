# Recursion

Recursion is most use
ful for tasks that can be defined in terms of similar subtask.

For example

1. Sort
2. Search
3. Traversal
   <br> etc..

## Syntax

```java
 static int sum(int n) {

    // Breaking point
    if (n == 0) {
        return 1;
    }

    sum(n-1);
 }

 public static void main(String args[]) {
    System.out.print(sum(5));
 }
```

### Use cases
