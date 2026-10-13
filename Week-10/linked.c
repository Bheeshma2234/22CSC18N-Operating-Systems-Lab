#include <stdio.h>

#define MAX 50

int main()
{
    int disk[MAX] = {0};
    int blocks[MAX];
    int n, i, j;

    printf("LINKED FILE ALLOCATION\n");

    printf("Enter number of blocks required: ");
    scanf("%d", &n);

    /* Validate the number of blocks */
    if (n <= 0 || n > MAX)
    {
        printf("Invalid number of blocks!\n");
        return 0;
    }

    printf("Enter the block numbers (0-49):\n");

    for (i = 0; i < n; i++)
    {
        printf("Block %d: ", i + 1);
        scanf("%d", &blocks[i]);

        /* Check block number range */
        if (blocks[i] < 0 || blocks[i] >= MAX)
        {
            printf("Invalid block number!\n");
            return 0;
        }

        /* Check for duplicate blocks */
        for (j = 0; j < i; j++)
        {
            if (blocks[i] == blocks[j])
            {
                printf("Duplicate block number!\n");
                return 0;
            }
        }

        /* Check whether the block is already allocated */
        if (disk[blocks[i]] == 1)
        {
            printf("Block already allocated!\n");
            return 0;
        }

        /* Allocate the block */
        disk[blocks[i]] = 1;
    }

    printf("\nFile allocated successfully.\n");
    printf("Linked block chain:\n");

    /* Display the linked block chain */
    for (i = 0; i < n; i++)
    {
        if (i < n - 1)
        {
            printf("%d -> ", blocks[i]);
        }
        else
        {
            printf("%d -> NULL\n", blocks[i]);
        }
    }

    return 0;
}
