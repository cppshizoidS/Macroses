#define DEFER2(head, tail, i) for (int i = (head, 0); !i; tail, i++)
#define DEFER(head, tail) DEFER2(head, tail, __deferVar__##__LINE__)
