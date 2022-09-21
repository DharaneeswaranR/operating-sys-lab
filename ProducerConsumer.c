#include <stdio.h>
#include <stdlib.h>
int mutex = 1, full = 0, empty = 3, item = 0;

int wait(int i)
{
    i--;
    return i;
}

int signal(int i)
{
    i++;
    return i;
}

void producer()
{
    mutex = wait(mutex);
    full = signal(full);
    empty = wait(empty);
    item++;
    printf("Producer produces item %d\n\n", item);
    mutex = signal(mutex);
}

void consumer()
{
    mutex = wait(mutex);
    empty = signal(empty);
    full = wait(full);
    printf("Consumer consumes item %d\n\n", item);
    item--;
    mutex = signal(mutex);
}

int main()
{
    int choice;
    printf("Producer Consumer\n\n");

    while (1) 
    {
        printf("Options:\n");
        printf("1. Producer\n");
        printf("2. Consumer\n");
        printf("3. Exit\n\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:
                if ((mutex == 1) && (empty != 0))
                    producer();
                else
                    printf("Buffer is full.\n\n");
                break;
            case 2:
                if ((mutex == 1) && (full != 0))
                    consumer();
                else
                    printf("Buffer is empty.\n\n");
                break;
            case 3:
                return 0;
        }
    }
}

/* Output

Producer Consumer

Options:
1. Producer
2. Consumer
3. Exit

Enter choice: 1
Producer produces item 1

Options:
1. Producer
2. Consumer
3. Exit

Enter choice: 1
Producer produces item 2

Options:
1. Producer
2. Consumer
3. Exit

Enter choice: 1
Producer produces item 3

Options:
1. Producer
2. Consumer
3. Exit

Enter choice: 1
Buffer is full.

Options:
1. Producer
2. Consumer
3. Exit

Enter choice: 2
Consumer consumes item 3

Options:
1. Producer
2. Consumer
3. Exit

Enter choice: 2
Consumer consumes item 2

Options:
1. Producer
2. Consumer
3. Exit

Enter choice: 2
Consumer consumes item 1

Options:
1. Producer
2. Consumer
3. Exit

Enter choice: 2
Buffer is empty.

Options:
1. Producer
2. Consumer
3. Exit

Enter choice: 3

*/