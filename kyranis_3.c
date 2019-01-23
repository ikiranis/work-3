/**
 *
 * File: kyranis_3.c
 *
 * Created by Yiannis Kiranis <std138327@ac.eap.gr>
 *
 * Date: 2019-01-23
 * Time: 21:43
 *
 * Σχεδίαση γραφικής παράστασης
 *
 */

#define P 45      /* σημεία για υπολογισμό */
#define M 50      /* Screen: 90 rows x 160 columns */
#define N 20

#include <math.h> /* απαιτείται για την χρήση της fabs(), η οποία επιστρέφει tηn απόλυτη τιμή της παραμέτρου που δέχεται ως είσοδο*/
#include <stdio.h>

struct point {
    double x, y;
};

struct point vals[P];
char         screen[N][M];


double function(double x)       /* Η συνάρτησή μας */
{
    return (fabs(x)+x-2);
}

int nearest(double x) /* Συνάρτηση στρογγυλοποίησης στον πλησιέστερο ακέραιο */
{
    return ((int) (x+0.5));
}

/* Γέμισμα με κενούς χαρακτήρες */
void clear_screen()
{
    int i, j; // Μετρητές

    // Προσπέλαση όλων των στοιχείων του διδιάστατου πίνακα screen και γέμισμα με κενά.
    for (i=0; i<N; i++) {
        for (j=0; j<M; j++) {
            screen[i][j] = ' ';
        }
    }
}

// Εκτύπωση των στοιχείων του πίνακα screen, με τις γραμμές ανάποδα
void plot_screen()
{
    int i, j; // Μετρητές

    // Προσπέλαση όλων των στοιχείων του διδιάστατου πίνακα screen και εκτύπωση
    for (i=N-1; i>=0; i--) {
        for (j=0; j<M; j++) {
            printf("%c", screen[i][j]);
        }
        printf("\n");
    }

}

// Υπολογισμός των σημείων P της συνάρτησης
void calculate_values(double l, double r)
{
    int i; // Μετρητής

    for (i=0; i<P; i++) {
        vals[i].x = l + (i*(r-l))/(P-1); // Υπολογισμός του x
        vals[i].y = function(vals[i].x); // Υπολογισμός του y=f(x)
    }

}

// Γέμισμα της γραμμής row του πίνακα screen με "-"
void horizontal(int row)
{
    int i; // Μετρητής

    // Γέμισμα των στηλών της γραμμής row με τον χαρακτήρα "-"
    for (i=0; i<M; i++) {
        screen[row][i] = '-';
    }
}

// Γέμισμα της γραμμής row του πίνακα screen με "-"
void vertical(int col)
{
    int i; // Μετρητής

    // Γέμισμα των γραμμών της στήλης col με τον χαρακτήρα "|"
    for (i=0; i<N; i++) {
        screen[i][col] = '|';
    }
}

// Σχεδίαση της γραφικής παράστασης
void map_to_screen(double l, double r, double d, double u)
{
    int z; // Μετρητής
    int i, j;  // Οι υπολογιζόμενες συντενταγμένες του πίνακα screen, όπου υπάρχει τιμή
    int col, row; // Το σημείο 0,0 των αξόνων

    // Υπολογισμός του σημείου 0,0 των αξόνων και σχεδιασμός τους
    // στον πίνακα screen, αν είναι μέσα στα όρια της οθόνης
    col = nearest( ( (0-l) * (M-1) ) / (r-l) );
    row = nearest( ( (0-d) * (N-1) ) / (u-d) );

    if ( (row>=0 && row<N-1) && (col>=0 && col<=M-1) ) {
        vertical(col);
        horizontal(row);
    }

    // Προσπέλαση του πίνακα vals
    for (z=0; z<P; z++) {
        // Υπολογισμός των i, j συντεταγμένων για τον πίνακα screen,
        // όπου θα μπει ο χαρακτήρας "."
        i = nearest( ( (vals[z].y-d) * (N-1) ) / (u-d) );
        j = nearest( ( (vals[z].x-l) * (M-1) ) / (r-l) );

        // Ελέγχουμε αν είναι μέσα στα όρια της οθόνης
        if ( (i>=0 && i<N-1) && (j>=0 && j<=M-1) ) {
            screen[i][j] = '.';
        }
    }

}

int main()
{
    clear_screen();
    calculate_values(-5, 5.0);
    map_to_screen(-5.0, 5.0, -5.0, 10.0);
    plot_screen();
    getchar();/*system("PAUSE"); */
    return 0;
}