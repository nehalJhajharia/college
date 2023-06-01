// Program to store temperature of 5 cities for 365 days
// It displays the average temperature of the cities for a year

#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Creating 5 matrices to hold temperature values for 5 years
    int JaipurTemp[5][365];
    int DelhiTemp[5][365];
    int SuratTemp[5][365];
    int NoidaTemp[5][365];
    int SikarTemp[5][365];

    // Putting random temperature values to the arrays using rand() funtion
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 365; j++) {
            JaipurTemp[i][j] = 20 + rand()%21;
        }
    }
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 365; j++) {
            DelhiTemp[i][j] = 20 + rand()%21;
        }
    }
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 365; j++) {
            SuratTemp[i][j] = 20 + rand()%21;
        }
    }
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 365; j++) {
            NoidaTemp[i][j] = 20 + rand()%21;
        }
    }
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 365; j++) {
            SikarTemp[i][j] = 20 + rand()%21;
        }
    }

    // Calculate average temperature for the individual cities of 5 years
    int sum = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 365; j++) {
            sum += JaipurTemp[i][j];
        }
    }
    int avgTempJaipur = (sum / (365*5));
    
    sum = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 365; j++) {
            sum += DelhiTemp[i][j];
        }
    }
    int avgTempDelhi = (sum / (365*5));

    sum = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 365; j++) {
            sum += SuratTemp[i][j];
        }
    }
    int avgTempSurat = (sum / (365*5));

    sum = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 365; j++) {
            sum += NoidaTemp[i][j];
        }
    }
    int avgTempNoida = (sum / (365*5));

    sum = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 365; j++) {
            sum += SikarTemp[i][j];
        }
    }
    int avgTempSikar = (sum / (365*5));

    // Printing the average temperature
    printf("Average temperature for the last 5 years are: \n");
    printf("Jaipur: %d deg Celcius\n", avgTempJaipur);
    printf("Delhi: %d deg Celcius\n", avgTempDelhi);
    printf("Surat: %d deg Celcius\n", avgTempSurat);
    printf("Noida: %d deg Celcius\n", avgTempNoida);
    printf("Sikar: %d deg Celcius\n", avgTempSikar);

    // Calculating average temperature of 5 years of all the cities combined
    float avgTemp = (float)(avgTempJaipur + avgTempDelhi + avgTempSurat + avgTempNoida + avgTempSikar) / 5;

    printf("Average tmperature overall is %.2f deg Celcius.\n", avgTemp);

    return 0;
}