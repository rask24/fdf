## FDF File Format

The .fdf file is structured in the following format:
- Each line consists of multiple elements separated by spaces or tabs. (trailing spaces or tabs is also accepted)
- The first element represents the **height** and must be an integer; it's a mandatory element.
- The second element represents the **color** and is optional. It should be a positive hexadecimal number starting with `0x`.
- The number of elements in each line remains consistent, forming a well-defined rectangular shape.
- A newline character(or spaces or tabs) at the end of the file is mandatory.

### Sample Format:

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

Above format describes the .fdf file structure, where each line represents a set of elements:

- The first element denotes the height of the segment and is mandatory.
- The second element represents the color of the segment and is optional. It should be a positive hexadecimal number starting with 0x.
- The file ends with a newline character, which is mandatory.
