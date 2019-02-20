/**
 *
 * File: kyranis_4.c
 *
 * Created by Yiannis Kiranis <std138327@ac.eap.gr>
 *
 * Date: 2019-01-23
 * Time: 23:46
 *
 * ΥΠΟΕΡΓΑΣΙΑ 4
 *
 * Εύρεση ελάχιστου αριθμού κεραιών κινητής τηλεφωνίας
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define plithos_simeiwn 20 /*Πλήθος σημείων ενδιαφέροντος*/
#define Xmin 719604.0 /*Ελάχιστο γεωγραφικό μήκος*/
#define Xmax 722538.0 /*Μέγιστο γεωγραφικό μήκος*/
#define Ymin 4328469.0 /*Ελάχιστο γεωγραφικό πλάτος*/
#define Ymax 4332907.0 /*Μέγιστο γεωγραφικό πλάτος*/
#define Radius 500 /*Ακτίνα εμβέλειας κεραίας*/
#define Total_Regions 2 /*Πλήθος Περιοχών*/

struct Point_of_Interest /*Η δομή για την καταγραφή του κάθε στοιχείου*/
{
    char id[10];
    double x;
    double y;
};

/*Δήλωση Πίνακα σημείων ενδιαφέροντος*/
struct Point_of_Interest Points[plithos_simeiwn];

/*Ο Συμμετρικός πίνακας με τις αποστάσεις του κάθε σημείου από τα υπόλοιπα */
double Distances [plithos_simeiwn][plithos_simeiwn];

double Average_Distances [plithos_simeiwn];

/*Συνάρτηση για την καταχώρηση των σημείων ενδιαφέροντος με αμυντικό προγραμματισμό*/
void Data_Points()
{
    int i;

    // Ζητάει plithos_simeiwn φορές τα σημεία ενδιαφέροντος, με αμυντικό προγραμμτισμό
//    for (i=0; i<plithos_simeiwn; i++) {
//
//        printf("Δώσε id για το σημείο %d: ", i+1);
//        scanf("%s", Points[i].id);
//
//        do {
//            printf("Δωσε γεωγραφικό μήκος για το σημείο %d: [%.0f-%.0f] ", i+1, Xmin, Xmax);
//            scanf("%lf", &Points[i].x);
//
//
//            if (Points[i].x<Xmin || Points[i].x>Xmax) {
//                printf("Έδωσες γεωγραφικό μήκος εκτός ορίων της πόλης\n");
//            }
//        } while (Points[i].x<Xmin || Points[i].x>Xmax);
//
//        do {
//            printf("Δωσε γεωγραφικό πλάτος για το σημείο %d: [%.0f-%.0f] ", i+1, Ymin, Ymax);
//            scanf("%lf", &Points[i].y);
//
//            if (Points[i].y<Ymin || Points[i].y>Ymax) {
//                printf("Έδωσες γεωγραφικό πλάτος εκτός ορίων της πόλης\n");
//            }
//        } while (Points[i].y<Ymin || Points[i].y>Ymax);
//    }

    strcpy(Points[0].id, "1");
    Points[0].x = 719604;
    Points[0].y = 4328469;

    strcpy(Points[1].id, "2");
    Points[1].x = 719704;
    Points[1].y = 4328569;

    strcpy(Points[2].id, "3");
    Points[2].x = 719804;
    Points[2].y = 4328669;

    strcpy(Points[3].id, "4");
    Points[3].x = 719904;
    Points[3].y = 4328769;

    strcpy(Points[4].id, "5");
    Points[4].x = 720004;
    Points[4].y = 4328869;

    strcpy(Points[5].id, "6");
    Points[5].x = 720104;
    Points[5].y = 4328969;

    strcpy(Points[6].id, "7");
    Points[6].x = 720204;
    Points[6].y = 4329069;

    strcpy(Points[7].id, "8");
    Points[7].x = 720304;
    Points[7].y = 4329169;

    strcpy(Points[8].id, "9");
    Points[8].x = 720404;
    Points[8].y = 4329269;

    strcpy(Points[9].id, "10");
    Points[9].x = 720504;
    Points[9].y = 4329369;

    strcpy(Points[10].id, "11");
    Points[10].x = 720604;
    Points[10].y = 4329469;

    strcpy(Points[11].id, "12");
    Points[11].x = 720704;
    Points[11].y = 4329569;

    strcpy(Points[12].id, "13");
    Points[12].x = 720804;
    Points[12].y = 4329669;

    strcpy(Points[13].id, "14");
    Points[13].x = 720904;
    Points[13].y = 4329769;

    strcpy(Points[14].id, "15");
    Points[14].x = 721004;
    Points[14].y = 4329869;

    strcpy(Points[15].id, "16");
    Points[15].x = 721104;
    Points[15].y = 4329969;

    strcpy(Points[16].id, "17");
    Points[16].x = 721204;
    Points[16].y = 4330069;

    strcpy(Points[17].id, "18");
    Points[17].x = 721304;
    Points[17].y = 4330169;

    strcpy(Points[18].id, "19");
    Points[18].x = 721404;
    Points[18].y = 4330269;

    strcpy(Points[19].id, "20");
    Points[19].x = 721504;
    Points[19].y = 4330369;

}


/*Συνάρτηση υπολογισμού της Ευκλείδειας απόστασης μεταξύ δύο σημείων*/
double Euclidean_Distance (int i, int j)
{
    // Επιστρέφει το αποτέλεσμα του υπολογισμού
    return sqrt( pow((Points[i].x - Points[j].x),2) + pow((Points[i].y - Points[j].y),2) );
}


/*Συνάρτηση υπολογισμού κάθε σημείου με όλα τα υπόλοιπα*/
void Populate_Distance_Matrix()
{
    int i, j; // Μετρητές

    // Σαρώνει όλα τα σημεία μεταξύ τους και υπολογίζει την απόσταση
    for (i=0; i<plithos_simeiwn; i++) {
        for (j=0; j<plithos_simeiwn; j++) {
            Distances[i][j] = Euclidean_Distance(i, j);
        }
    }
}


/*Συνάρτηση υπολογισμού της μέσης απόστασης του κάθε σημείου ως προς τα υπόλοιπα*/
void Average_Distance_Matrix()
{
    int i, j; // Μετρητές
    double sum; // Το συνολικό άθροισμα των αποστάσεων ενός σημείου με τα υπόλοιπα

    // Σαρώνει όλες τις αποστάσεις του πίνακα Distances μεταξύ τους
    // και υπολογίζει τον μέσο όρο
    for (i=0; i<plithos_simeiwn; i++) {
        sum = 0; // Αρχικοποίηση του αθροίσματος

        for (j=0; j<plithos_simeiwn; j++) {
            sum += Distances[i][j];
        }

        // Υπολογίζει τον μέσο όρο και των καταχωρεί στον πίνακα Average_Distances
        Average_Distances[i] = (double) sum / (plithos_simeiwn-1);
    }
}

int main()
{
    int i,j;
    double totalSum; // Το άθροισμα των μέσων όρων
    double totalAverage; // Ο συνολικός μέσος όρος
    int Regions[plithos_simeiwn]; // Οι περιοχές που ανήκει το κάθε σημείο
    double maxAverageInRegions[Total_Regions]; // Ο μέγιστος όρος κάθε περιοχής

    Data_Points();
    /*Εμφάνιση των σημείων που έδωσε ο χρήστης*/
    printf("\n \n Data Entered \n \n");
    for (i=0; i<plithos_simeiwn;i++)
        printf("id=%s  x=%lf y=%lf \n", Points[i].id, Points[i].x, Points[i].y);
    printf("\n \n Distance Matrix \n \n");
    /*Κλήση συνάρτησης για τον υπολογισμό των αποστάσεων*/
    Populate_Distance_Matrix();
    /*Εμφάνιση των αποστάσεων που υπολογίστηκαν*/
    for (i=0; i<plithos_simeiwn; i++)
    {
        printf("\n");
        for (j=0; j<plithos_simeiwn; j++)
            printf("%6.2lf\t", Distances[i][j]);
    }
    printf("\n \n Average Distance Matrix \n \n");
    /*Κλήση συνάρτησης υπολογισμού των μέσων αποστάσεων ανά σημείο*/
    Average_Distance_Matrix();
    /*Εμφάνιση των μέσων αποστάσεων που υπολογίστηκαν*/
    for (i=0; i<plithos_simeiwn;i++)
        printf("id=%s  Average=%lf \n", Points[i].id, Average_Distances[i]);


    // Υπολογισμός και εμφάνιση του συνολικού μέσου όρου
    totalSum = 0;

    for (i=0; i<plithos_simeiwn; i++) {
        totalSum += Average_Distances[i];
    }

    totalAverage = (double) totalSum / plithos_simeiwn;

    printf("\nTotal Average: %f\n", totalAverage);

    // Γέμισμα του πίνακα Regions με την περιοχή που ανήκει το κάθε σημείο
    // και εμφάνιση του

    printf("\nCategorisation in Regions:\n");

    for (i=0; i<plithos_simeiwn; i++) {
        // Όταν ο μέσο όρος είναι μικρότερος ή ίσος του συνολικού μέσου όρου
        // ανήκει στην περιοχή 100. Αλλιώς στην 200
        Regions[i] = (Average_Distances[i]<=totalAverage) ? 100 : 200;

        printf("id=%s Region=%d\n", Points[i].id, Regions[i]);
    }

    /*Υπολογισμός των μέγιστων μέσων τιμών ανά περιοχή*/

    printf("\nCalculation of Max Distance per Region\n\n");

    for (i=0; i<Total_Regions; i++) {
        // Αρχικοποίηση του μεγίστου για την περιοχή
        maxAverageInRegions[i] = 0;

        // Σάρωση των μέσων όρων του κάθε σημείου
        for (j = 1; j < plithos_simeiwn; j++) {

            // Αν η περιοχή του σημείου είναι η 100 ή η 200
            if (Regions[j]==((i+1)*100)) {
                // Ελέγχει αν η τιμή είναι μεγαλύτερη από την τρέχουσα μέγιστη
                // και την θέτει σαν την νέα μέγιστη
                if (Average_Distances[j]>maxAverageInRegions[i]) {
                    maxAverageInRegions[i] = Average_Distances[j];
                }
            }
        }

        printf("Region=%d max in region: %f\n", (i+1)*100, maxAverageInRegions[i]);

    }

    /*Υπολογισμός των κεραιών που θα χρειαστούν ανά περιοχή, με στρογγυλοποίηση*/

    printf("\nCalculation of Amount of Antennas per Region\n");

    for (i=0; i<Total_Regions; i++) {
        printf("\nΤο πλήθος των κεραιών για την περιοχή %d είναι: %d\n",
                (i+1)*100, (int) ((maxAverageInRegions[i] / Radius) + 0.5));
    }


    return 0;
}


