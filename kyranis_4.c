/**
 *
 * File: kyranis_4.c
 *
 * Created by Yiannis Kiranis <std138327@ac.eap.gr>
 *
 * Date: 2019-01-23
 * Time: 23:46
 *
 * ���������� 4
 *
 * ������ ��������� ������� ������� ������� ����������
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define plithos_simeiwn 20 /*������ ������� �������������*/
#define Xmin 719604.0 /*�������� ���������� �����*/
#define Xmax 722538.0 /*������� ���������� �����*/
#define Ymin 4328469.0 /*�������� ���������� ������*/
#define Ymax 4332907.0 /*������� ���������� ������*/
#define Radius 500 /*������ ��������� �������*/
#define Total_Regions 2 /*������ ��������*/

struct Point_of_Interest /*� ���� ��� ��� ��������� ��� ���� ���������*/
{
    char id[10];
    double x;
    double y;
};

/*������ ������ ������� �������������*/
struct Point_of_Interest Points[plithos_simeiwn];

/*� ����������� ������� �� ��� ���������� ��� ���� ������� ��� �� �������� */
double Distances [plithos_simeiwn][plithos_simeiwn];

double Average_Distances [plithos_simeiwn];

/*��������� ��� ��� ���������� ��� ������� ������������� �� �������� ��������������*/
void Data_Points()
{
    int i;

    // ������ plithos_simeiwn ����� �� ������ �������������, �� �������� �������������
//    for (i=0; i<plithos_simeiwn; i++) {
//
//        printf("���� id ��� �� ������ %d: ", i+1);
//        scanf("%s", Points[i].id);
//
//        do {
//            printf("���� ���������� ����� ��� �� ������ %d: [%.0f-%.0f] ", i+1, Xmin, Xmax);
//            scanf("%lf", &Points[i].x);
//
//
//            if (Points[i].x<Xmin || Points[i].x>Xmax) {
//                printf("������ ���������� ����� ����� ����� ��� �����\n");
//            }
//        } while (Points[i].x<Xmin || Points[i].x>Xmax);
//
//        do {
//            printf("���� ���������� ������ ��� �� ������ %d: [%.0f-%.0f] ", i+1, Ymin, Ymax);
//            scanf("%lf", &Points[i].y);
//
//            if (Points[i].y<Ymin || Points[i].y>Ymax) {
//                printf("������ ���������� ������ ����� ����� ��� �����\n");
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


/*��������� ����������� ��� ����������� ��������� ������ ��� �������*/
double Euclidean_Distance (int i, int j)
{
    // ���������� �� ���������� ��� �����������
    return sqrt( pow((Points[i].x - Points[j].x),2) + pow((Points[i].y - Points[j].y),2) );
}


/*��������� ����������� ���� ������� �� ��� �� ��������*/
void Populate_Distance_Matrix()
{
    int i, j; // ��������

    // ������� ��� �� ������ ������ ���� ��� ���������� ��� ��������
    for (i=0; i<plithos_simeiwn; i++) {
        for (j=0; j<plithos_simeiwn; j++) {
            Distances[i][j] = Euclidean_Distance(i, j);
        }
    }
}


/*��������� ����������� ��� ����� ��������� ��� ���� ������� �� ���� �� ��������*/
void Average_Distance_Matrix()
{
    int i, j; // ��������
    double sum; // �� �������� �������� ��� ���������� ���� ������� �� �� ��������

    // ������� ���� ��� ���������� ��� ������ Distances ������ ����
    // ��� ���������� ��� ���� ���
    for (i=0; i<plithos_simeiwn; i++) {
        sum = 0; // ������������ ��� �����������

        for (j=0; j<plithos_simeiwn; j++) {
            sum += Distances[i][j];
        }

        // ���������� ��� ���� ��� ��� ��� ��������� ���� ������ Average_Distances
        Average_Distances[i] = (double) sum / (plithos_simeiwn-1);
    }
}

int main()
{
    int i,j;
    double totalSum; // �� �������� ��� ����� ����
    double totalAverage; // � ��������� ����� ����
    int Regions[plithos_simeiwn]; // �� �������� ��� ������ �� ���� ������
    double maxAverageInRegions[Total_Regions]; // � �������� ���� ���� ��������

    Data_Points();
    /*�������� ��� ������� ��� ����� � �������*/
    printf("\n \n Data Entered \n \n");
    for (i=0; i<plithos_simeiwn;i++)
        printf("id=%s  x=%lf y=%lf \n", Points[i].id, Points[i].x, Points[i].y);
    printf("\n \n Distance Matrix \n \n");
    /*����� ���������� ��� ��� ���������� ��� ����������*/
    Populate_Distance_Matrix();
    /*�������� ��� ���������� ��� �������������*/
    for (i=0; i<plithos_simeiwn; i++)
    {
        printf("\n");
        for (j=0; j<plithos_simeiwn; j++)
            printf("%6.2lf\t", Distances[i][j]);
    }
    printf("\n \n Average Distance Matrix \n \n");
    /*����� ���������� ����������� ��� ����� ���������� ��� ������*/
    Average_Distance_Matrix();
    /*�������� ��� ����� ���������� ��� �������������*/
    for (i=0; i<plithos_simeiwn;i++)
        printf("id=%s  Average=%lf \n", Points[i].id, Average_Distances[i]);


    // ����������� ��� �������� ��� ��������� ����� ����
    totalSum = 0;

    for (i=0; i<plithos_simeiwn; i++) {
        totalSum += Average_Distances[i];
    }

    totalAverage = (double) totalSum / plithos_simeiwn;

    printf("\nTotal Average: %f\n", totalAverage);

    // ������� ��� ������ Regions �� ��� ������� ��� ������ �� ���� ������
    // ��� �������� ���

    printf("\nCategorisation in Regions:\n");

    for (i=0; i<plithos_simeiwn; i++) {
        // ���� � ���� ���� ����� ���������� � ���� ��� ��������� ����� ����
        // ������ ���� ������� 100. ������ ���� 200
        Regions[i] = (Average_Distances[i]<=totalAverage) ? 100 : 200;

        printf("id=%s Region=%d\n", Points[i].id, Regions[i]);
    }

    /*����������� ��� �������� ����� ����� ��� �������*/

    printf("\nCalculation of Max Distance per Region\n\n");

    for (i=0; i<Total_Regions; i++) {
        // ������������ ��� �������� ��� ��� �������
        maxAverageInRegions[i] = 0;

        // ������ ��� ����� ���� ��� ���� �������
        for (j = 1; j < plithos_simeiwn; j++) {

            // �� � ������� ��� ������� ����� � 100 � � 200
            if (Regions[j]==((i+1)*100)) {
                // ������� �� � ���� ����� ���������� ��� ��� �������� �������
                // ��� ��� ����� ��� ��� ��� �������
                if (Average_Distances[j]>maxAverageInRegions[i]) {
                    maxAverageInRegions[i] = Average_Distances[j];
                }
            }
        }

        printf("Region=%d max in region: %f\n", (i+1)*100, maxAverageInRegions[i]);

    }

    /*����������� ��� ������� ��� �� ���������� ��� �������, �� ���������������*/

    printf("\nCalculation of Amount of Antennas per Region\n");

    for (i=0; i<Total_Regions; i++) {
        printf("\n�� ������ ��� ������� ��� ��� ������� %d �����: %d\n",
                (i+1)*100, (int) ((maxAverageInRegions[i] / Radius) + 0.5));
    }


    return 0;
}


