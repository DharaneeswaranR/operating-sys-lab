#include <stdio.h>
#define LEFT (i + 4) % 5
#define RIGHT (i + 1) % 5
#define THINKING 0
#define HUNGRY 1
#define EATING 2

int state[5];
void put_forks(int);
void test(int);
void take_forks(int);

void philosopher(int i)
{
    if (state[i] == 0)
    {
        take_forks(i);
        if (state[i] == EATING)
            printf("\nEating in process....");
        put_forks(i);
    }
}

void put_forks(int i)
{
    state[i] = THINKING;
    printf("\nPhilosopher %d completed its works\n", i);
    test(LEFT);
    test(RIGHT);
}

void take_forks(int i)
{
    state[i] = HUNGRY;
    test(i);
}

void test(int i)
{
    if (state[i] == HUNGRY && state[LEFT] != EATING && state[RIGHT] != EATING)
    {
        printf("Philosopher %d can eat", i);
        state[i] = EATING;
    }
}

int main()
{
    int i;
    for (i = 1; i <= 5; i++)
    {
        state[i] = 0;
    }

    printf("Dining Philosopher Problem\n");

    for (i = 1; i <= 5; i++)
    {
        printf("\nThe philosopher %d falls hungry\n", i);
        philosopher(i);
    }
}

/* Output

Dining Philosopher Problem

The philosopher 1 falls hungry
Philosopher 1 can eat
Eating in process....
Philosopher 1 completed its works

The philosopher 2 falls hungry
Philosopher 2 can eat
Eating in process....
Philosopher 2 completed its works

Philosopher 3 can eat
Eating in process....
Philosopher 3 completed its works

The philosopher 4 falls hungry
Philosopher 4 can eat
Eating in process....
Philosopher 4 completed its works

The philosopher 5 falls hungry
Philosopher 5 can eat
Eating in process....
Philosopher 5 completed its works

*/


