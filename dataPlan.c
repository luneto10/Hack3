    /**
 * Name: Luciano Carvalho (lguedesdecarvalhon2@huskers.unl.edu)
 * 
 * Date: 2023 - 08 - 06
 * 
 * Uses the argument line to say the remain gigabites by the user, the average
 * use and how much can he uses.
*/

#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

int main(int argc, char **argv)
{

    if (argc != 4)
    {
        printf("ERROR: incorrect number of command line arguments\n\n");
        exit(-1);
    }

    double numberGBTotal = atof(argv[1]);
    int dayPeriod = atoi(argv[2]);
    double totalUsedGB = atof(argv[3]);

    double expectedDailyAverage = numberGBTotal / 30.0;
    double realDailyAverage = (double)(totalUsedGB) / (dayPeriod);
    bool valid = true;

    // error conditions

    if (dayPeriod < 1 || dayPeriod > 30)
    {
        printf("ERROR: incorrect number of command line arguments!! Input a valid day between 1 - 30!\n\n");
        valid = false;
    }
    if (numberGBTotal < 0 || totalUsedGB < 0)
    {
        printf("ERROR: incorrect number of command line arguments!! Impossible negative GB values!!\n\n");
        valid = false;
    }

    if (valid)
    {
        printf("%d days used, %d days remainig\n", dayPeriod, 30 - dayPeriod);
        printf("Average daily use: %.3lf GB/day\n\n", realDailyAverage);

        if (realDailyAverage > expectedDailyAverage && (numberGBTotal - totalUsedGB) / (30 - dayPeriod) > 0)
        {
            printf("You are EXCEEDING your average daily use (%.3lf GB/day).\n", expectedDailyAverage);
            printf("Continuing this high usage, you'll exceed your data plan by %.2lf GB.\n\n", (realDailyAverage * (30 - dayPeriod) + totalUsedGB) - (numberGBTotal));

            printf("To stay below your data plan, use no more than %.3lf GB/day.\n", (numberGBTotal - totalUsedGB) / (30 - dayPeriod));
        }
        else if (realDailyAverage < expectedDailyAverage && (numberGBTotal - totalUsedGB) / (30 - dayPeriod) > 0)
        {
            printf("You are at or below your average daily use (%.3lf GB/day)\n", expectedDailyAverage);
            printf("You can use up to %.3lf GB/day and stay bellow your data plan limit.\n", (numberGBTotal - totalUsedGB) / (30 - dayPeriod));
        }
        else
        {
            printf("You have already met your limit for this month.  Looks like you're getting some overage charges...");
        }
    }

    return 0;
}
