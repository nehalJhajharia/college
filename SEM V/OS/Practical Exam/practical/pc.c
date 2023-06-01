#include <stdio.h>
#include <stdlib.h>

int m = 1; // Initialize a mutex to 1
int full_slots = 0; // Number of full slots
int empty_slots = 10; // Number of empty slots 
int buffer_size = 0; // Size of buffer

void producer() {
    --m;
    ++full_slots;
    --empty_slots;
    buffer_size++;
    printf("\nProducer produces item %d", buffer_size);
    ++m;
}

void consumer() {
    --m;
    --full_slots;
    ++empty_slots;
    printf("\nConsumer consumes item %d", buffer_size);
    buffer_size--;
    ++m;
}

int main() {
    char ch = 0;
    printf("\nPress P to Producer"
           "\nPress C to Consumer"
           "\nPress 0 to Exit");

    #pragma omp critical
    while (1) {
        printf("\nEnter a choice: ");
        scanf("%c", &ch);

        switch (ch) {
        case 'P':
            if ((m == 1) && (empty_slots != 0)) {
                producer();
            } else {
                printf("Buffer is full!");
            }
            break;

        case 'C':
            if ((m == 1) && (full_slots != 0)) {
                consumer();
            } else {
                printf("Buffer is empty!");
            }
            break;

        // Exit Condition
        case '0':
            exit(0);
            break;
            
        default:
            break;
        }
    }
}
