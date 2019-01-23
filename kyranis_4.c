/**
 *
 * File: kyranis_4.c
 *
 * Created by Yiannis Kiranis <std138327@ac.eap.gr>
 *
 * Date: 2019-01-23
 * Time: 23:46
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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
    /* Συμπληρώστε τον κώδικα */
}


/*Συνάρτηση υπολογισμού της Ευκλείδειας απόστασης μεταξύ δύο σημείων*/
double Euclidean_Distance (int i, int j)
{
/* Συμπληρώστε τον κώδικα */
}


/*Συνάρτηση υπολογισμού κάθε σημείου με όλα τα υπόλοιπα*/
void Populate_Distance_Matrix()
{
/* Συμπληρώστε τον κώδικα */
}


/*Συνάρτηση υπολογισμού της μέσης απόστασης του κάθε σημείου ως προς τα υπόλοιπα*/
void Average_Distance_Matrix()
{
/* Συμπληρώστε τον κώδικα */
}

int main()
{
    int i,j;
    /* Συμπληρώστε τον κώδικα */

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
    /*Υπολογισμός των μέγιστων μέσων τιμών ανά περιοχή*/
    /*Υπολογισμός των κεραιών που θα χρειαστούν ανά περιοχή*/
    /* Συμπληρώστε τον κώδικα */

    return 0;
}


