#ifndef VMlib_STACK_H_
#define VMlib_STACK_H_

typedef struct stack_t stack_t;

extern stack_t *stack_new(int size, int valsize);
extern void stack_free(stack_t *st);
extern int stack_size(stack_t *st);

extern int stack_push(stack_t *st, void *elem);
extern void *stack_pop(stack_t *st);
extern int stack_set(stack_t *st, int index, void *elem);
extern void *stack_get(stack_t *st, int index);

#endif /* VMlib_STACK_H_ */
