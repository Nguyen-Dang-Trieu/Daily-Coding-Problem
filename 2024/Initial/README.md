## Using intptr_t and uintptr_t
The types `intptr_t` and `uintptr_t` are used for *storing pointer addresses*. They provide a portable and safe way of declaring pointers, and will be the same size as the underlying pointer used on the system. 
***They are useful for converting pointers to their integer representation.***

To explain "*They are useful for converting pointers to their integer representation*". We will look at the following `example_code.c`.
~~~cpp
~~~

The following illustrates how to use `intptr_t` and `uintptr_t`:
~~~cpp
#include <stdio.h>
#include <stdint.h>  // Để sử dụng uintptr_t và intptr_t

int main(){
    int num;
    intptr_t *pi = (intptr_t*)&num;
    uintptr_t *pu = (uintptr_t*)&num;

    return 0;
}
~~~
If we try to assign the address of an integer to a pointer of type `uintptr_t` and `intptr_t` as follows, we will get a syntax error:
~~~cpp
intptr_t *pi = &num;
uintptr_t *pu = &num;
~~~
The error follows:
~~~cpp
warning: initialization of ‘intptr_t *’ {aka ‘long int *’} from incompatible pointer type ‘int *’ [-Wincompatible-pointer-types]
    8 |     intptr_t *pi = &num;
      |                    ^
main.c:9:21: warning: initialization of ‘uintptr_t *’ {aka ‘long unsigned int *’} from incompatible pointer type ‘int *’ [-Wincompatible-pointer-types]
    9 |     uintptr_t *pu = &num;
      |                     ^
~~~
