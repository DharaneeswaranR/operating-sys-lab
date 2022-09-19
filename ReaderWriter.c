#include <stdio.h>
#include <stdlib.h>

void main()
{
    typedef int semaphore;
    semaphore sread = 0, swrite = 0;
    int ch, r = 0;
    printf("Reader Writer\n");

    do
    {
        printf("\nMenu\n");
        printf("\n1. Read from file");
        printf("\n2. Write to file");
        printf("\n3. Exit the reader");
        printf("\n4. Exit the writer");
        printf("\n5. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
            case 1:
                if (swrite == 0)
                {
                    sread = 1;
                    r += 1;
                    printf("\nReader %d reads the file...\n", r);
                }
                else
                {
                    printf("\nWriter already in progress..Can't read...\n");
                }
                break;

            case 2:
                if (sread == 0 && swrite == 0)
                {
                    swrite = 1;
                    printf("\nWriter in progress...\n");
                }
                else if (swrite == 1)
                {
                    printf("\nWriter already in progress..Can't write...\n");
                }
                else if (sread == 1)
                {
                    printf("\nReader already in progress..Can't write...\n");
                }
                else
                    printf("\nCannot write file\n");
                break;

            case 3:
                if (r == 1)
                {
                    printf("\nThe reader %d closes the file\n", r);
                    r -= 1;
                    sread = 0;
                }
                else if (r != 0)
                {
                    printf("\nThe reader %d closes the file\n", r);
                    r -= 1;
                }
                else 
                {
                    printf("\nCurrently no readers access the file\n");
                    sread = 0;
                }
                break;

            case 4:
                if (swrite == 1)
                {
                    printf("\nWriter closes the file\n");
                    swrite = 0;
                }
                else
                    printf("\nThere is no writer in the file\n");
                break;

            case 5:
                exit(0);
        }
    } while (ch < 6);
}

/* Output:

Reader Writer

Menu

1. Read from file
2. Write to file
3. Exit the reader
4. Exit the writer
5. Exit

Enter your choice: 1

Reader 1 reads the file...

Menu

1. Read from file
2. Write to file
3. Exit the reader
4. Exit the writer
5. Exit

Enter your choice: 2

Reader already in progress..Can't write...

Menu

1. Read from file
2. Write to file
3. Exit the reader
4. Exit the writer
5. Exit

Enter your choice: 3

The reader 1 closes the file

Menu

1. Read from file
2. Write to file
3. Exit the reader
4. Exit the writer
5. Exit

Enter your choice: 2

Writer in progress...

Menu

1. Read from file
2. Write to file
3. Exit the reader
4. Exit the writer
5. Exit

Enter your choice: 1

Writer already in progress..Can't read...

Menu

1. Read from file
2. Write to file
3. Exit the reader
4. Exit the writer
5. Exit

Enter your choice: 4

Writer closes the file

Menu

1. Read from file
2. Write to file
3. Exit the reader
4. Exit the writer
5. Exit

Enter your choice: 1 

Reader 1 reads the file...

Menu

1. Read from file
2. Write to file
3. Exit the reader
4. Exit the writer
5. Exit

Enter your choice: 5

*/