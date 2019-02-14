/**
 *
 * File: kyranis_1A.c
 *
 * Created by Yiannis Kiranis <std138327@ac.eap.gr>
 *
 * Date: 2019-01-21
 * Time: 21:47
 *
 * ΥΠΟΕΡΓΑΣΙΑ 1Α
 *
 * Να γραφεί συνάρτηση στη γλώσσα προγραμματισμού C, η οποία θα δέχεται ως είσοδο 2 ακέραιους αριθμούς και
 * θα επιστρέφει 1 αν οι αριθμοί αυτοί έχουν ίδια τα δύο τελευταία ψηφία τους, διαφορετικά θα επιστρέφει 0.
 *
 */

#include <stdio.h>

int compareDigitsOfIntegers(int a, int b);

int main()
{
    int a=1223, b=3425;

    printf("Το αποτέλεσμα του ελέγχου των δύο ακεραίων είναι: %d", compareDigitsOfIntegers(a,b));

    return 0;
}

/**
 * Έλεγχος 2 ακεραίων, αν έχουνε ίδια τα 2 τελευταία ψηφία τους
 */
int compareDigitsOfIntegers(int a, int b)
{
    // Τα 2 τελευταία ψηφία ενός αριθμού είναι το υπόλοιπο της διαίρεσης του αριθμού, με το 100
    // Ελέγχουμε αν είναι ίσα μεταξύ τους τα δύο τελευταία ψηφία των 2 αριθμών
    // Επιστρέφει 1 αν ισχύει η ισότητα, 0 αν όχι
    return ( (a % 100) == (b % 100) );
}