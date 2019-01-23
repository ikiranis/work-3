/**
 *
 * File: kyranis_2A.c
 *
 * Created by Yiannis Kiranis <std138327@ac.eap.gr>
 *
 * Date: 23/1/2019
 * Time: 1:48 πμ
 *
 * Να γραφεί πρόγραμμα στη γλώσσα προγραμματισμού C, το οποίο να διαβάζει από το
 * πληκτρολόγιο ένα θετικό ακέραιο αριθμό δευτερολέπτων, και στην συνέχεια να μετατρέπει τα
 * δευτερόλεπτα σε έτη, μήνες, ημέρες, ώρες, λεπτά και δευτερόλεπτα, τα οποία και να εμφανίζει.
 * Να χρησιμοποιηθεί αμυντικός προγραμματισμός ώστε ο αριθμός να είναι θετικός και το πολύ 9
 * ψηφίων. Υποθέστε ότι κάθε μήνας έχει 30 ημέρες
 *
 */

#include <stdio.h>

// Οι υποδιαιρέσεις του χρόνου
#define MONTHS 12
#define DAYS 30
#define HOURS 24
#define MINUTES 60
#define SECONDS 60

int main()
{

    int givenSeconds; // Τα δευτερόλεπτα που δίνει ο χρήστης
    int remainSeconds; // Το υπόλοιπο των δευτερολέπτων που απομένει για την επόμενη μετατροπή
    int years, months, days, hours, minutes, seconds; // Οι αντίστοιχες μετατροπές

    // Ο χρήστης δίνει αριθμό δευτερολέπτων με αμυντικό προγραμματισμό (1-999999999)
    do {
        printf("Δώσε αριθμό δευτερολέπτων: ");
        scanf("%d", &givenSeconds);

        if (givenSeconds<=0 || givenSeconds>999999999) {
            printf("Ο αριθμός των δευτερολέπτων θα πρέπει να είναι θετικός ακέραιος μέχρι 9 ψηφία\n");
        }

    } while (givenSeconds<=0 || givenSeconds>999999999);

    // Υπολογισμός της κάθε μετατροπής. Η διαίρεση κάνει την μετατροπή.
    // Το υπόλοιπο της μεταφέρεται για την επόμενη μετατροπή
    years = givenSeconds / (SECONDS * MINUTES * HOURS * DAYS * MONTHS);
    remainSeconds = givenSeconds % (SECONDS * MINUTES * HOURS * DAYS * MONTHS);
    months = remainSeconds / (SECONDS * MINUTES * HOURS * DAYS);
    remainSeconds = remainSeconds % (SECONDS * MINUTES * HOURS * DAYS);
    days = remainSeconds / (SECONDS * MINUTES * HOURS);
    remainSeconds = remainSeconds % (SECONDS * MINUTES * HOURS);
    hours = remainSeconds / (SECONDS * MINUTES);
    remainSeconds = remainSeconds % (SECONDS * MINUTES);
    minutes = remainSeconds / SECONDS;
    remainSeconds = remainSeconds % SECONDS;
    seconds = remainSeconds;

    // Εκτύπωση του αποτελέσματος
    printf("Τα %d δευτερόλεπτα αντιστοιχούν σε\n%d χρόνια, %d μήνες, %d μέρες, %d ώρες, %d λεπτά, %d δευτερόλεπτα\n",
            givenSeconds, years, months, days, hours, minutes, seconds);

    return 0;
}