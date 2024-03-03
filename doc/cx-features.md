# Special features implemented

## Struct methods/functions

This allows to associate a function to a structure and call
it as a method, similar to C3's style.

```
struct person {
    char *name;
    int age;
};

char* foo.get_name(f) {
    return f.name;
}

int foo.set_age(*f, int new_age) {
    return f->age = new_age;
}

int main()
{
    struct foo f = {"Charles", 30};
    f.get_name();
    // pointers are added automatically
    f.set_age(31);
    struct foo *ptr = &f;
    // and also removed
    ptr->get_name();
    return 0;
}
```

## For/else, while/else

This adds an `else` clause to the for and while -loops, with functionality similar to Python.

The `else` clause gets executed if the loop exits normally (no `break`).

```
int i;
for (i=0; i<100; i++) {
    if (i == 50)
        break;
} else {
    // doesn't get executed
    printf("i=%d\n");
}
```

or

```
struct person {
    char *name;
    int age;
};

struct person *
find_by_name(char *name, struct person *list, int list_count) {
    for (int i=0; i<list_count; i++) {
        if (!strcmp(list[i].name, name))
            return name;
    } else {
        // throw some error or mine bitcoin, whatever you do
        // in this situation
        return NULL;
    }
    // meh
    //return NULL;
}
```

## Default parameters for functions

This allows to set default parameters on functions. The parameters
need to be constant.

```
int foo(int a, int b=6);
// ...
foo(7); // foo(7, 6);
foo(1, 18);
```

```
struct bar_data {
    int x, y;
};
int bar(struct bar_data data = {1,2});
// ...
bar();  // bar((struct bar_data){1,2})
bar(my_data);
```

```
// not allowed:
int bad(int a = random() + puts("stalin did nothing wrong"));
int bad2(int a = 6, int b = a << 5);
```

## Function call with argument designators

This allows to pass arguments with key words, similar to some high-level
languages (Python).

_They should be specially useful with functions with default arguments_

```
int mega_foo(int a, int b = 6, int c = 23, int d = -1);
// ...
mega_foo(5, .b = 12, .c = -4, .d = 0);  // mega_foo(5, 12, -4, 0)
mega_foo(.d = 99, .a = 13, .c = -2);    // mega_foo(13, 6, -2, 99)
```

There can't be positional arguments after named arguments.

```
// bad
mega_foo(.d = 4, 67, 12);
```

