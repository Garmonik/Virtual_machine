### Virtual Machine
> Stack-based virtual machine. Version 1.0.

### Stack
```C
typedef struct Stack Stack;

extern Stack *new_stack(size_t size, vtype_t value);
extern void free_stack(Stack *stack);

extern size_t size_stack(Stack *stack);

extern size_t size_stack(Stack *stack);

extern void set_stack(Stack *stack, size_t index, void *value);
extern value_t get_stack(Stack *stack, size_t index);

extern void push_stack(Stack *stack, void *value);
extern value_t pop_stack(Stack *stack);
label begin
```

### Tree
```C
typedef enum {
    DECIMAL_ELEM,
    REAL_ELEM,
    STRING_ELEM,
} vtype_tree_t;

typedef union {
    int64_t decimal;
    double real;
    uint8_t *string;
} value_tree_t;

typedef struct tree_node {
    struct {
        value_tree_t key;
        value_tree_t value;
    } data;
    struct tree_node *left;
    struct tree_node *right;
    struct tree_node *parent;
} tree_node;

typedef struct Tree {
    struct {
        vtype_tree_t key;
        vtype_tree_t value;
    } type;
    struct tree_node *node;
} Tree;

extern Tree *new_tree(vtype_tree_t key, vtype_tree_t value);
extern void free_tree(Tree *tree);

extern value_tree_t get_tree(Tree *tree, void *key);
extern void set_tree(Tree *tree, void *key, void *value);
extern void del_tree(Tree *tree, void *key);
extern _Bool in_tree(Tree *tree, void *key);

extern void *decimal(int64_t x);
extern void *string(uint8_t *x);
extern void *real(double x);

extern void print_tree(Tree *tree);
extern void print_tree_as_list(Tree *tree);
```

### Hash Table
```C
typedef struct HashTab HashTab;

extern HashTab *new_hashtab(size_t size, vtype_t key, vtype_t value);
extern void free_hashtab(HashTab *hashtab);

extern value_t get_hashtab(HashTab *hashtab, void *key);
extern int8_t set_hashtab(HashTab *hashtab, void *key, void *value);
extern void del_hashtab(HashTab *hashtab, void *key);
extern _Bool in_hashtab(HashTab *hashtab, void *key);

extern _Bool eq_hashtab(HashTab *x, HashTab *y);
extern size_t size_hashtab(HashTab *hashtab);
extern size_t sizeof_hashtab(void);

extern void print_hashtab(HashTab *hashtab);
extern void println_hashtab(HashTab *hashtab);

extern void print_hashtab_format(HashTab *hashtab);
extern void println_hashtab_format(HashTab *hashtab);
```

### Additional instructions (num = 14)  
1.  [PUSH_CODE] = [0x01] = "push",
2.  [POP_CODE] = [0x02] = "pop",
3.  [ADD_CODE] = [0x03] = "add",
4.  [SUB_CODE] = [0x04] = "sub",
5.  [MUL_CODE] = [0x05] = "mul",
6.  [DIV_CODE] = [0x06] = "div",
7.  [JMP_CODE] = [0x07] = "jmp",
8.  [JL_CODE] = [0x08] = "jl",
9.  [JG_CODE] = [0x09] = "jg",
10. [JE_CODE] = [0x0A] = "je",
11. [JNE_CODE] = [0x0B] = "jne",
12. [STORE_CODE] = [0x0C] = "stor",
13. [LOAD_CODE] = [0x0D] = "load",
14. [CALL_CODE] = [0x0E] = "call",
15. [RET_CODE] = [0x0F] = "ret",
16. [HLT_CODE] = [0x10] = "hit",
17. [LABEL_CODE] = [0x11] = "label",
18. [COMMENT_CODE] = [0x12] = ";",

### Example: caesar encryption (assembly code)
```asm
label begin
    ;A
    push 10
    call fact
    jmp end
    
label end
    pop
    hlt

label fact
    ; B <- A
    load $-2
    ; if B < 2
    push 2
    load $-2
    jl _clfact
label _fact
    ; B <- B - 1
    push 1
    load $-2
    sub
    store $-2 $-1
    pop
    ; A <- A * B
    load $-3
    load $-2
    mul
    store $-4 $-1
    pop
    ; if B > 1
    push 1
    load $-2
    jg _fact
label _clfact
    pop
    ret
```

### Example: caesar encryption (binary code)
```
0000 0000 0a0d 0000 0011 0600 0000 0f01
0f0c ffff fffe 0000 0000 020c ffff fffe
0700 0000 5e00 0000 0001 0cff ffff fe03
0bff ffff feff ffff ff01 0cff ffff fd0c
ffff fffe 040b ffff fffc ffff ffff 0100
0000 0001 0cff ffff fe08 0000 0025 010e
```
