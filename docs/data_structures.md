# Data Structures

## Array

Linear and ordered, constant-time access by index. Stored in contiguous memory.

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

## String

Array of characters.

```
[H, e, l, l, o]
```

Immutable in most languages, if the language allows you do "add" to a string
it actually copies the underlying data and does not modify the original.

```go
s := "Hello" // original
s += "!"     // copy
```

Which means that doing this:

```go
var result string
for char := range "Hello!" {
    result += char
}
```

Is an O(n^2) operation and lands you on an international watchlist.

## Set

Collection of unordered, unique values.

```
{a, b, c, d, e}
```

Checking membership is O(1) complexity.

## Hash Map

Key-value pair system where the values are stored in an array and the key is
used to calculate the index of the value. Uses a hash function on the key to
generate a pseudo random number, which modulod by the length of the internal
array, will yield the index at which the value is stored.

```
map["my key"] = "my val"

hash("my key") % 5 = 2
["asd", "", "", "dsa", ""]
            ^
["asd", "", "my val", "dsa", ""]

map["my key"]
hash("my key") % 5 = 2
["asd", "", "my val", "dsa", ""]
            ^
```

Index calculation: `idx := hash(key) % len(arr)`

- O(1): Lookup & insert

### Collision

Multiple keys can hash into the same index, which is called a collision.

#### Solutions

**Separate Chaining**

Keys are mapped to a chain. (array or linked list)

**Open Addressing**

If there's a collision, use the next free memory address.

The most common algorithms for this are:

- linear probing
- quadratic probing
- double hashing
