#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*month*/
#define Jan 1
#define Feb 2
#define Mar 3
#define Apr 4
#define May 5
#define Jun 6
#define Jul 7
#define Aug 8
#define Sep 9
#define Oct 10
#define Nov 11
#define Dec 12

/*constellation
 * ~end month/day
 * month * 100 + day
*/
#define Cap 120
#define Aqu 219
#define Pis 320
#define Ari 420
#define Tau 521
#define Gem 621
#define Can 722
#define Leo 821
#define Vir 923
#define Lib 1023
#define Sco 1122
#define Sag 1222

int check_star(int month, int day) {
    int md = month * 100 + day;
    if      (md <= Cap) return 0;
    else if (md <= Aqu) return 1;
    else if (md <= Pis) return 2;
    else if (md <= Ari) return 3;
    else if (md <= Tau) return 4;
    else if (md <= Gem) return 5;
    else if (md <= Can) return 6;
    else if (md <= Leo) return 7;
    else if (md <= Vir) return 8;
    else if (md <= Lib) return 9;
    else if (md <= Sco) return 10;
    else if (md <= Sag) return 11;
    else return 0;
}

void print_day(int month, int day, int year) {
    int check_star();
    char constellation[12][20] = {"capricorn", "aquarius", "pisces", "aries", "taurus", "gemini",
                                  "cancer", "leo", "virgo", "libra", "scorpio",
                                  "sagittarius"};
    if (month < 10) printf("0%d/", month);
    else            printf("%d/", month);

    if (day < 10) printf("0%d/", day);
    else          printf("%d/", day);
        
    if (year < 10) printf("000%d ", year);
    else if (year < 100) printf("00%d ", year);
    else if (year < 1000) printf("0%d ", year);
    else printf("%d ", year);

    printf("%s\n", constellation[check_star(month, day)]);
}

int main() {
    int count;
    char *tmp;
    if((tmp = malloc(100)) == NULL) {
        printf("malloc\n");
        exit(1);
    }

    fgets(tmp, 100, stdin);
    sscanf(tmp, "%d", &count);
    int i;
    int cal, day, month, year;
       
    for (i = 0; i < count; i++) {
        fgets(tmp, 100, stdin);
        sscanf(tmp, "%d", &cal);
        year  = cal % 10000;
        month = cal / 1000000;
        day   = cal / 10000 - month * 100; 
        day += 280; /* 40weeks = 280days*/
        
        while (1) {
            switch (month) {
                case Feb:
                    if (year % 4 == 0) {
                        if (year % 100 == 0 && year % 400 != 0) goto No_uruu;/*-> line102*/
                        if (day <= 29) goto OUT; /*-> line 127*/
                        day -= 29;
                        month++;
                    } else {
                        No_uruu:
                        if (day <= 28) goto OUT; /*-> line 127*/ 
                        day -= 28;
                        month++;
                    }
                    break;
                case Apr:
                case Jun:
                case Sep:
                case Nov:
                    if (day <= 30) goto OUT; /*-> line 127*/ 
                    day -= 30;
                    month++;
                    break;
                default: 
                    if (day <= 31) goto OUT; /*-> line 127*/ 
                    day -= 31;
                    if (month == Dec) {
                        month = Jan;
                        year += 1;
                    } else
                        month++;
                    break;
            }
        }
        OUT:
        printf("%d ", i+1);
        print_day(month, day, year);
    }
    free(tmp);
    return 0;
}

