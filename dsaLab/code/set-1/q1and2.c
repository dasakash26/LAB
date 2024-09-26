#include <stdio.h>
#define x 10

int arr[x];
int top = 0;

void addElement(int a[], int val)
{
    if (top >= x) {
        printf("Array is full. Cannot add element.\n");
        return;
    }
    a[top++] = val;
}

void insert(int a[], int j, int val)
{
    if (top >= x) {
        printf("Array is full. Cannot insert element.\n");
        return;
    }
    if (j < 0 || j > top) {
        printf("Invalid position. Please enter a position between 0 and %d.\n", top);
        return;
    }
    for (int i = top; i > j; i--) {
        a[i] = a[i - 1];
    }
    a[j] = val;
    top++;
}

void deleteElement(int a[], int j)
{
    if (top == 0) {
        printf("Array is empty. Cannot delete element.\n");
        return;
    }
    if (j < 0 || j >= top) {
        printf("Invalid position. Please enter a position between 0 and %d.\n", top - 1);
        return;
    }
    for (int i = j; i < top - 1; i++) {
        a[i] = a[i + 1];
    }
    top--;
}

void reverseList(int a[])
{
    for (int i = 0; i < top / 2; i++) {
        int temp = a[i];
        a[i] = a[top - i - 1];
        a[top - i - 1] = temp;
    }
}

void printList(int a[])
{
    if (top == 0) {
        printf("Array is empty.\n");
        return;
    }
    printf("List: [");

    for (int i = 0; i < top; i++) {
        if (i==top-1)
        {
            printf("%d]\n", a[i]);
        }
        else{
            printf("%d, ", a[i]);
        }
    }
    printf("\n\n");
}

int main()
{
    int li, val, pos;
    do
    {
        printf("\n\n");
        printf("1. Add element\n");
        printf("2. Insert element\n");
        printf("3. Delete element\n");
        printf("4. Reverse List\n");
        printf("5. Print List\n");
        printf("6. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &li);
        switch (li)
        {
        case 1:
            printf("Enter the element to be added: ");
            scanf("%d", &val);
            addElement(arr, val);
            break;
        case 2:
            printf("Enter the element to be inserted: ");
            scanf("%d", &val);
            printf("Enter the position to be inserted: ");
            scanf("%d", &pos);
            insert(arr, pos, val);
            break;
        case 3:
            printf("Enter the position to be deleted: ");
            scanf("%d", &pos);
            deleteElement(arr, pos);
            break;
        case 4:
            reverseList(arr);
            break;
        case 5:
            printList(arr);
            break;
        case 6:
            printf("Exited\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
        }
    } while (li != 6);

    return 0;
}
