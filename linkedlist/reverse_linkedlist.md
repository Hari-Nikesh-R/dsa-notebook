# Reverse LinkedList

## Goal

Given<br>
head <br>
1 -> 2 -> 3 -> NULL
<br> to <br>
3 -> 2 -> 1 -> NULL

## Algorithm

Given information is only the head node.

### Possible options

1. We can create a temp variable and do the swapping

   ```
   s1: (head) 1 -> 2 -> 3 -> NULL
   s2: (head)(temp) 1 -> 2 -> 3 -> NULL
   s3: (head)1 -> (temp)2 -> 3 -> NULL
   s4: (head)2 -> (temp)1 -> 3 -> NULL
   s5: (head)2 -> 1 -> (temp)3 -> NULL
   s6: (head)3 -> 1 -> (temp)2 -> NULL
   s7: (head)3 -> 1 -> 2 -> (temp)NULL

   End result
   s8: (head)3 -> 1 -> 2 -> NULL
   ```

2. Creating 3 variables including head

   ```
   s1: (head) 1 -> 2 -> 3 -> NULL
   s2: (head)(temp1)(temp2) 1 -> 2 -> 3 -> NULL
   s3: (head)(temp1)1 -> (temp2)2  3 -> NULL
   s4: (head)1 -> (temp2)2 -> (temp1)3 -> NULL
   s5: (head)3 -> (temp2)2 -> (temp1)1 -> NULL
   s6: (head)3 -> 2 -> (temp2)1 -> (temp1)NULL
   s7: (head)3 -> 2 -> 1 -> NULL
   ```

3. Creating 4 variables including head
   - Create variable named - previous = null, current and next = null;
   - Traverse the list till the current becomes `null`
   - Current is going to start from the head node.
     `current = head;`
   - next = current.next;
   - current.next = previous;
   - previous = current;
   - current = next

   ```
   s1: (head) 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> NULL
   s2: (head)(current)1 -> 2 -> 3 -> 4 -> 5 -> 6 -> NULL
   s3: (head)(current)1 -> (next)2 -> 3 -> 4 -> 5 -> 6 -> NULL
   s4: (head)(previous)(current)1 -> (next)2 -> 3 -> 4 -> 5 -> 6 -> NULL
   // Did not success
   ```

4. Creating 4 variables to reverse the linkedList
   - Initial state
     s

   ```
    s1: (head) 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> NULL

    s2: (head)(current)1 -> (next)2 -> 3 -> 4 -> 5 -> 6 -> NULL

    s3: (head)(current)1 -> NULL; (next)2 -> 3 -> 4 -> 5 -> 6 -> NULL

    s4: (head)(previous)(current)1 -> NULL; (next)2 -> 3 -> 4 -> 5 -> 6 -> NULL

    s5: (head)(previous)1 -> NULL; (current)(next)2 -> 3 -> 4 -> 5 -> 6 -> NULL

    s6: (head)(previous)1 -> NULL; (current)2 -> (next)3 -> 4 -> 5 -> 6 -> NULL

    s7:(current)2 -> (previous)1 -> NULL; (next)3 -> 4 -> 5 -> 6 -> NULL;

    s8: (current)(previous)2 -> 1 -> NULL; (next)3 -> 4 -> 5 -> 6 -> NULL;

    s9:(previous)2 -> 1 -> NULL; (next)(current)3 -> 4 -> 5 -> 6 -> NULL;

    s10: (previous)2 -> 1 -> NULL; (current)3 -> (next)4 -> 5 -> 6 -> NULL;

    s11: (current)3 -> (previous)2 -> 1 -> NULL; (next)4 -> 5 -> 6 -> NULL;

    s12: (current)(previous)3 -> 2 -> 1 -> NULL; (next)4 -> 5 -> 6 -> NULL;

    s13: (previous)3 -> 2 -> 1 -> NULL; (next)(current)4 -> 5 -> 6 -> NULL;

    s14: (previous)3 -> 2 -> 1 -> NULL; (current)4 -> (next) 5 -> 6 -> NULL;

    s15: (current)4 -> (previous)3 -> 2 -> 1 -> NULL; (next)5 -> 6 -> NULL;

    s16: (current)(previous) 4 -> 3 -> 2 -> 1 -> NULL; (next)5 -> 6 -> NULL;

    s17:(previous) 4 -> 3 -> 2 -> 1 -> NULL; (current)(next)5 -> 6 -> NULL;

    s.. : (previous)6 -> 5 -> 4 -> 3 -> 2 -> 1 -> NULL;
    current and next = NULL;

    // Success
   ```
