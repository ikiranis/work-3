/**
 *
 * File: kyranis_1D.c
 *
 * Created by Yiannis Kiranis <std138327@ac.eap.gr>
 *
 * Date: 2019-01-21
 * Time: 23:02
 * 
 * ΥΠΟΕΡΓΑΣΙΑ 1Δ
 *
 * Για τον τριψηφιο ακεραιο αριθμο 145 ισχυει οτι ισουται με το αθροισμα των παραγοντικων των ψηφιων
 * του δηλ. 145=1! + 4! + 5!. Να γραφει προγραμμα στη γλωσσα προγραμματισμου C, το οποιο με χρηση εξαντλητικης
 * αναζητησης ολων των πενταψηφιων αριθμων να βρισκει τον μοναδικο πενταψηφιο ακεραιο αριθμο που ισουται με το
 * αθροισμα των παραγοντικων των ψηφιων του.
 *
 */

#include <stdio.h>

/**
 * Υπολογισμός του παραγοντικού, με αναδρομική συνάρτηση
 */
int factorial(int number)
{
    if(number==0) {
        return 1; // Επιστρέφει 1 και τερματίζεται την αναδρομή
    } else {
        return number * factorial(number-1); // n!=n*(n-1)!
    }
}

int main()
{
    int number; // Ο αριθμός που ελέγχεται κάθε φορά
    int digit; // Το ψηφίο που ελέγχεται κάθε φορά
    int sum; // Το άθροισμα των παραγοντικών ψηφίων
    int i; // Μετρητής

    // Σάρωση των πενταψήφιων αριθμών
    for (i=10000; i<100000; i++) {
        number = i; // Περνάμε το i στην τιμή του number για να ελεγχθεί
        sum = 0;

        // Όσο ο αριθμός που ελέγχουμε είναι μεγαλύτερος του μηδενός (δεν έχει άλλα ψηφία δηλαδή)
        while (number > 0) {
            digit = number % 10; // Παίρνει το τελευταίο ψηφίο
            number = number / 10; // Ο αριθμός που απομένει μόλις αφαιρεθεί το τελευταίο ψηφίο

            sum += factorial(digit); // Προσθήκη στο άθροισμα, του παραγοντικού του τρέχοντος ψηφίου
        }

        // Αν ο αριθμός ισούται με το άθροισμα των παραγοντικών ψηφίων, εμφανίζει το μήνυμα
        if(sum == i) {
            printf("Το %d ισούται με το άθροισμα των παραγοντικών ψηφίων του\n", i);
        }

    }

    return 0;
}

