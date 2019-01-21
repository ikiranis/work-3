/**
 *
 * File: kyranis_1D.c
 *
 * Created by Yiannis Kiranis <std138327@ac.eap.gr>
 *
 * Date: 2019-01-21
 * Time: 23:02
 *
 * Για τον τριψήφιο ακέραιο αριθμό 145 ισχύει ότι ισούται με το άθροισμα των παραγοντικών των ψηφίων
 * του δηλ. 145=1! + 4! + 5!. Να γραφεί πρόγραμμα στη γλώσσα προγραμματισμού C, το οποίο με χρήση εξαντλητικής
 * αναζήτησης όλων των πενταψήφιων αριθμών να βρίσκει τον μοναδικό πενταψήφιο ακέραιο αριθμό που ισούται με το
 * άθροισμα των παραγοντικών των ψηφίων του.
 *
 */

#include <stdio.h>

int factorial(int number);

int main()
{
    int number;
    int digit;
    int sum;
    int i;

    for (i=10000; i<100000; i++) {
        number = i;
        sum = 0;

        while (number > 0) {
            digit = number % 10;
            number = number /  10;

            sum += factorial(digit);
        }

        if(sum == i) {
            printf("Το %d ισούται με το άθροισμα των παραγοντικών ψηφίων του\n", i);
        }

    }

    return 0;
}

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