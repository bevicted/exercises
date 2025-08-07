# Data Structures

## Arrays

Linear and ordered, constant-time access by index. Stored in contiguous memory

- O(1): Access, append and assign
- O(n): Insert and delete

```
[A, B, C, D, E]
          ^
arr[3] = D
O(1)
```

```
[A, B, C, D, E]
              ^
append(arr[5], F)
O(1) usually
```

```
[A, B, C, D, E]
    ^
delete(arr[1])
O(n)

shift C, D, E left
delete last space
```

```
[A, B, C, D, E]
     ^
insert(arr[2], F)
O(n)

add space to end
shift C, D, E right
insert item
```
