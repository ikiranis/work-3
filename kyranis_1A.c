/**
 *
 * File: kyranis_1A.c
 *
 * Created by Yiannis Kiranis <std138327@ac.eap.gr>
 *
 * Date: 2019-01-21
 * Time: 21:47
 *
 * Να γραφεί συνάρτηση στη γλώσσα προγραμματισμού C, η οποία θα δέχεται ως είσοδο 2 ακέραιους αριθμούς και
 * θα επιστρέφει 1 αν οι αριθμοί αυτοί έχουν ίδια τα δύο τελευταία ψηφία τους, διαφορετικά θα επιστρέφει 0.
 *
 */

#include <stdio.h>

int compareDigitOfIntegers(int a, int b);

int main()
{
    int a=12, b=34;

    printf("Το αποτέλεσμα του ελέγχου των δύο ακεραίων είναι: %d", compareDigitOfIntegers(a,b));

    return 0;
}

/**
 * Έλεγχος 2 ακεραίων, αν έχουνε ίδια τα 2 τελευταία ψηφία τους
 *
 * @param a
 * @param b
 * @return
 */
int compareDigitOfIntegers(int a, int b)
{



    return 1;
}