#include<stdio.h>
#include <string.h>

struct Skater
{
    char name[50];
    char surname[50];
    double keeping_ree[6];
    double keeping_av;
};


double calculateScore(struct Skater person) {
    double result = 0;

    for (int i = 0; i < 6; i++) {

        result = result + person.keeping_ree[i];
    }
    return result / 6;
}

int loadSkaters(struct Skater skaters[4], char* filename) {

    FILE* fp;
    fp = fopen(filename, "r");

    for (int i = 0; i < 4; i++) {
        fscanf(fp, "%s %s %lf %lf %lf %lf %lf %lf",
            skaters[i].name,
            skaters[i].surname,
            &skaters[i].keeping_ree[0],
            &skaters[i].keeping_ree[1],
            &skaters[i].keeping_ree[2],
            &skaters[i].keeping_ree[3],
            &skaters[i].keeping_ree[4],
            &skaters[i].keeping_ree[5]);

        skaters[i].keeping_av = calculateScore(skaters[i]);
    }


    double maxAverage = 0;
    int champion = 0;
    for (int i = 0; i < 4; i++) {
        if (maxAverage < skaters[i].keeping_av) {

            maxAverage = skaters[i].keeping_av;
            champion = i + 1;
        }
    }

    return champion;

}

int main() {

    char* file = "C:\\Users\\MONSTER\\Desktop\\skaters.txt";
    struct Skater skaters[4];

    printf("Champion is %d. skater. Congratulations!", loadSkaters(skaters, file));


}



