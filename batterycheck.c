#include <stdio.h>
#include <stdlib.h>

void check_battery_status() {
    FILE *fp;
    char buffer[256];
    fp = fopen("/sys/class/power_supply/BAT0/status", "r");
    if (fp == NULL) {
        perror("Failed to open battery status file");
        return;
    }


    fgets(buffer, sizeof(buffer), fp);
    printf("Battery Status: %s", buffer);
    fclose(fp);  



    fp = fopen("/sys/class/power_supply/BAT0/capacity", "r");
    if (fp == NULL) {
        perror("Failed to open battery capacity file");
        return;
    }

    fgets(buffer, sizeof(buffer), fp);
    printf("Battery Capacity: %s%%\n", buffer);
    fclose(fp);
}

int main() {
    check_battery_status();
    return 0;
}
