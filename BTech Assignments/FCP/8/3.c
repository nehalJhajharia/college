#include <stdio.h>
#include <stdlib.h>

struct Time {  // Defining a structure for time
    int hours;
    int minutes;
    int seconds;
};

int tDiff(struct Time time1, struct Time time2); // Declaration of function for time difference

int main()
{
    struct Time time1, time2;

    // Taking input for one time
    printf("For a time, enter: \n");
    printf("Hour/s: ");
    scanf("%d", &time1.hours);
    printf("Minute/s: ");
    scanf("%d", &time1.minutes);
    printf("Second/s: ");
    scanf("%d", &time1.seconds);

    // Taking input for another time
    printf("\nFor another time, enter: \n");
    printf("Hour/s: ");
    scanf("%d", &time2.hours);
    printf("Minute/s: ");
    scanf("%d", &time2.minutes);
    printf("Second/s: ");
    scanf("%d", &time2.seconds);

    // Printing the difference in time
    printf("\nDifference between %d:%d:%d and %d:%d:%d = %d seconds \n\n",
        time1.hours,
        time1.minutes,
        time1.seconds,
        time2.hours,
        time2.minutes,
        time2.seconds,
        tDiff(time1, time2));

    return 0;
}

// Function to calculate the difference in times
int tDiff(struct Time time1, struct Time time2) {
    struct Time time3;
    int diff;

    time3.hours = time1.hours - time2.hours;
    time3.minutes = time1.minutes - time2.minutes;
    time3.seconds = time1.seconds - time2.seconds;

    diff = abs(time3.hours * 3600 + time3.minutes * 60 + time3.seconds);

    return diff;
}