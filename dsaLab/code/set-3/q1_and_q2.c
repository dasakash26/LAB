#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node *create()
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    int x;
    printf("Enter a number (-1 for no node): ");
    scanf("%d", &x);
    newNode->data = x;
    if (x == -1)
        return NULL;
    printf("Enter a number to the left of %d\n", x);
    newNode->left = create();
    printf("Enter a number to the right of %d\n", x);
    newNode->right = create();
    return newNode;
}

void inOrder(Node *root)
{
    if (root == NULL)
        return;
    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}

void preOrder(Node *root)
{
    if (root == NULL)
        return;
    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(Node *root)
{
    if (root == NULL)
        return;
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->data);
}

int search(int arr[], int start, int end, int value)
{
    for (int i = start; i <= end; i++)
    {
        if (arr[i] == value)
        {
            return i;
        }
    }
    return -1;
}

Node *buildTree(int inOrder[], int preOrder[], int inStart, int inEnd, int *preIndex)
{
    if (inStart > inEnd)
    {
        return NULL;
    }

    Node *tNode = (Node *)malloc(sizeof(Node));
    tNode->data = preOrder[*preIndex];
    (*preIndex)++;

    if (inStart == inEnd)
    {
        tNode->left = tNode->right = NULL;
        return tNode;
    }

    int inIndex = search(inOrder, inStart, inEnd, tNode->data);

    tNode->left = buildTree(inOrder, preOrder, inStart, inIndex - 1, preIndex);
    tNode->right = buildTree(inOrder, preOrder, inIndex + 1, inEnd, preIndex);

    return tNode;
}

Node *createTreeFromTraversals(int inOrder[], int preOrder[], int length)
{
    int preIndex = 0;
    return buildTree(inOrder, preOrder, 0, length - 1, &preIndex);
}

int main()
{
    Node *root = NULL;
    int choice;

    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Create a binary tree\n");
        printf("2. In-order traversal\n");
        printf("3. Pre-order traversal\n");
        printf("4. Post-order traversal\n");
        printf("5. Create tree from pre-order and in-order traversal\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            root = create();
            break;
        case 2:
            printf("In-order traversal: ");
            inOrder(root);
            printf("\n");
            break;
        case 3:
            printf("Pre-order traversal: ");
            preOrder(root);
            printf("\n");
            break;
        case 4:
            printf("Post-order traversal: ");
            postOrder(root);
            printf("\n");
            break;
        case 5:
        {
            int n;
            printf("Enter the number of nodes: ");
            scanf("%d", &n);
            int inOrderArr[n], preOrderArr[n];
            printf("Enter in-order traversal: ");
            for (int i = 0; i < n; i++)
            {
                scanf("%d", &inOrderArr[i]);
            }
            printf("Enter pre-order traversal: ");
            for (int i = 0; i < n; i++)
            {
                scanf("%d", &preOrderArr[i]);
            }
            root = createTreeFromTraversals(inOrderArr, preOrderArr, n);
            break;
            // Inorder: 4 2 5 1 6 3 7
            // Preorder: 1 2 4 5 3 6 7
        }
        case 6:
            exit(0);
        default:
            printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}