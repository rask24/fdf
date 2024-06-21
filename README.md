## FDF File Format

- Each line consists of multiple elements separated by spaces or tabs (trailing spaces or tabs are also accepted).
- Each element represents the **height** and must be an integer within the range of `INT_MIN` to `INT_MAX`.
- An element can optionally include a **color** in hexadecimal format starting with `0x`, within the range of `0x000000` to `0xFFFFFF`.
- The number of elements in each line remains consistent, forming a well-defined rectangular shape.
- A newline character, space, or tab at the end of the file is optional.

### Sample Format

```plaintext
0  0  0  0  0  0  0  0  0  0
0 10 10 10 10 10 10 10 10  0
0 10 20,0xFF0000 15,0xFF0000 12 15,0xFF0000 17,0xFF0000 20,0xFF0000 10  0
0 10 15,0xFF0000 10 12 15,0xFF0000 15,0xFF0000 15,0xFF0000 10  0
0  5 15,0xFF0000 10 12 15,0xFF0000 15,0xFF0000 13 10  0
0  5 10  5  7 12 12 12 10  0
0  5  7  1  2  7  5  5  7  0
0  3  0  0  1  2  2  2  5  0
0  1  0  0  0  0  0  0  3  0
0  0  0  0  0  0  0  0  0  0
```
