#include <stdio.h>

struct Semployee
{
    char m_name[20];
    int m_id;
};

int main(int argc, char const *argv[])
{
    struct Semployee emp1 = {"Alex", 1002}, emp2 = {"Ali", 1003}, emp3 = {"Maged", 1004};
    struct Semployee *arr[3];
    struct Semployee *(*ptr)[3] = &arr;
    arr[0] = &emp1;
    arr[1] = &emp2;
    arr[2] = &emp3;

    printf("\nEmployee name = %s\nEmployee id = %d", (*(*ptr))->m_name, (*(*ptr))->m_id);
    return 0;
}
