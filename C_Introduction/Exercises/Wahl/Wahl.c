// =====================================================================================
// Wahl.c
// =====================================================================================

#include <stdio.h>

void exercise_wahl()
{
    int stimmzettel = -1;

    int stimmenCDU = 0;
    int stimmenFDP = 0;
    int stimmenGruene = 0;
    int stimmenLinke = 0;
    int stimmenSPD = 0;

    float prozentCDU = 0.0;
    float prozentFDP = 0.0;
    float prozentGruene = 0.0;
    float prozentLinke = 0.0;
    float prozentSPD = 0.0;

    printf("Simulation Wahl\n");
    printf("===============\n");

    printf("1 = CDU/CSU\n");
    printf("2 = FDP\n");
    printf("3 = Gruene\n");
    printf("4 = Linke\n");
    printf("5 = SPD\n");

    while (stimmzettel != 0) {

        printf("Bitte Stimme abgeben: ");   // 1, 2, 3, 4, 5
        scanf_s("%d", &stimmzettel);

        if (stimmzettel == 1) {
            stimmenCDU++;
        }
        else if (stimmzettel == 2) {
            stimmenFDP++;
        }
        else if (stimmzettel == 3) {
            stimmenGruene++;
        }
        else if (stimmzettel == 4) {
            stimmenLinke++;
        }
        else if (stimmzettel == 5) {
            stimmenSPD++;
        }
        else if (stimmzettel != 0) {
            printf("Ungültiger stimmzettel abgegeben: ");
            continue;
        }

        // Berechne aktuelles Ergebnis:
        int stimmzettelTotal = stimmenCDU + stimmenFDP + stimmenGruene + stimmenLinke + stimmenSPD;

        prozentCDU = stimmenCDU / (float)stimmzettelTotal * 100;
        prozentFDP = (float)stimmenFDP / stimmzettelTotal * 100.0f;
        prozentGruene = (float)stimmenGruene / stimmzettelTotal * 100.0f;
        prozentLinke = (float)stimmenLinke / stimmzettelTotal * 100.0f;
        prozentSPD = (float)stimmenSPD / stimmzettelTotal * 100.0f;

        printf("Aktuelle Hochrechnung:\n");
        printf("CDU/CSU:  %6.2f%%\n", prozentCDU);
        printf("FDP:      %6.2f%%\n", prozentFDP);
        printf("Gruene:   %6.2f%%\n", prozentGruene);
        printf("Linke:    %6.2f%%\n", prozentLinke);
        printf("SPD:      %6.2f%%\n", prozentSPD);
        printf("\n");
    }
}

// =====================================================================================
// End-of-File
// =====================================================================================
