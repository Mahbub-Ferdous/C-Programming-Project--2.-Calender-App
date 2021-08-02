#include<stdio.h>

int getFirstdayOftheYear(int year){
    int day = (year*365 + ((year - 1)/ 4) - ((year - 1)/ 100) + ((year - 1)/ 400)) % 7;    // this is the calculation of first day of the year in which day getting via online
    return day;
}
int main(){
    char *months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    int daysInmonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31,};
    int i, j, totalDays, weekDay = 0, sCounter = 0, year;
    printf("Enter Your favourite year:\n");
    scanf("%d", &year);
    printf("\n\n************************ Welcome to %d ************************\n\n", year);

    // check if it is leap year or not!

    if(( year % 4 == 0 && year % 100 != 0) || ( year % 400 == 0)){
        daysInmonth[1] = 29;
    }

    // get the first date of the month in

    weekDay = getFirstdayOftheYear(year);

    for( i = 0; i < 12; i++){
        printf("\n\n\n---------------------------- %s ----------------------------\n\n", months[i]);
        printf("\n      Sun     Mon     Tue     Wed     Thu     Fri     Sat     \n\n");
        for(sCounter = 1; sCounter <= weekDay; sCounter++){
            printf("        ");
        }
        totalDays = daysInmonth[i];
        for( j = 1; j <= totalDays; j++){
            printf("%8d", j);                       /// /// (%8d) means 8 step aggresive
            weekDay++;
            if(weekDay > 6){
                weekDay = 0;
                printf("\n");
            }
        }

    }





return 0;
}
