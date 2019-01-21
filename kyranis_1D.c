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
    int someNumber = 10;

    printf("Factorial: %d\n", factorial(someNumber));


    return 0;
}

/**
 * Υπολογισμός του παραγοντικού
 */
int factorial(int number)
{
    if(number==1) {
        return 1;
    } else {
        return number * factorial(number-1);
    }
}