#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <unistd.h>

int main() {
    time_t rawtime = 0;
    struct tm *pTime = NULL;
    bool isRunning = true;

    int alarmHour = -1;
    int alarmMin = -1;

    printf("-------------Current Alarm Sets\n");

    printf("Do you want to set an alarm? (1 = yes / 0 = no): ");
    int setAlarm = 0;
    scanf("%d", &setAlarm);

    if (setAlarm == 1) {
        printf("Enter alarm time (hour minute): ");
        scanf("%d %d", &alarmHour, &alarmMin);
        printf("Alarm set for %02d:%02d\n", alarmHour, alarmMin);
    }

    printf("Current Time\n");

    while(isRunning){
        time(&rawtime);
        pTime = localtime(&rawtime);

        int h = pTime->tm_hour;
        int m = pTime->tm_min;
        int s = pTime->tm_sec;

        printf("%02d:%02d:%02d\n", h, m, s);

        if (setAlarm == 1 && h == alarmHour && m == alarmMin && s == 0) {
            printf("ALARM!!! It's %02d:%02d\n", h, m);
        }

        sleep(1); // only works on Linux and macOS
    }

    return 0;
}
