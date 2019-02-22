/**
 *
 * File: kyranis_1B.c
 *
 * Created by Yiannis Kiranis <std138327@ac.eap.gr>
 *
 * Date: 2019-01-21
 * Time: 22:34
 *
 * ΥΠΟΕΡΓΑΣΙΑ 1Β
 *
 * Να γραφεί πρόγραμμα στη γλώσσα προγραμματισμού C, το οποίο να υπολογίζει το άθροισμα όλων των ακέραιων
 * αριθμών μεταξύ 1000 και 1200 που διαιρουνται ακριβως με το 9. Υπενθυμιζεται οτι ενας αριθμος διαιρειται
 * ακριβως με το 9, αν το υπολοιπο της διαιρεσης του αριθμου με το 9 ειναι 0.
 *
 */

#include <stdio.h>

int main()
{

    int sum = 0; // Αρχικοποίηση του αθροίσματος
    int i; // Μετρητής

    // Σάρωση των αριθμών από 1000-1200
    for (i=1000; i<=1200; i++) {
        // Έλεγχος αν το υπόλοιπο της διαίρεσης με το 9 είναι 0
        // Αν είναι 0 παίρνουμε το ΝΟΤ του (1), για να βγει η παράσταση αληθής
        if (!(i%9)) {
            // Αν διαιρείται το προσθέτουμε στο συνολικό άθροισμα
            sum += i;
        }
    }

    // Εκτύπωση του αποτελέσματος
    printf("Το άθροισμα είναι: %d\n", sum);

    return 0;
}