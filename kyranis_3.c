/**
 *
 * File: kyranis_3.c
 *
 * Created by Yiannis Kiranis <std138327@ac.eap.gr>
 *
 * Date: 2019-01-23
 * Time: 21:43
 *
 * ���������� 3
 *
 * �������� �������� ����������
 *
 */

#define P 45      /* ������ ��� ���������� */
#define M 160      /* Screen: 90 rows x 160 columns */
#define N 90

#include <math.h> /* ���������� ��� ��� ����� ��� fabs(), � ����� ���������� t�n ������� ���� ��� ���������� ��� ������� �� ������*/
#include <stdio.h>

struct point {
    double x, y;
};

struct point vals[P];
char         screen[N][M];


double function(double x)       /* � ��������� ��� */
{
    return (fabs(x)+x-2);
}

int nearest(double x) /* ��������� ���������������� ���� ����������� ������� */
{
    return ((int) (x+0.5));
}

/* ������� �� ������ ���������� */
void clear_screen()
{
    int i, j; // ��������

    // ���������� ���� ��� ��������� ��� ����������� ������ screen ��� ������� �� ����.
    for (i=0; i<N; i++) {
        for (j=0; j<M; j++) {
            screen[i][j] = ' ';
        }
    }
}

// �������� ��� ��������� ��� ������ screen, �� ��� ������� �������
void plot_screen()
{
    int i, j; // ��������

    // ���������� ���� ��� ��������� ��� ����������� ������ screen ��� ��������
    for (i=N-1; i>=0; i--) {
        for (j=0; j<M; j++) {
            printf("%c", screen[i][j]);
        }
        printf("\n");
    }

}

// ����������� ��� ������� P ��� ����������
void calculate_values(double l, double r)
{
    int i; // ��������

    // ������������ ��� ����� ��� ��� ����������� ���� ������ vals
    for (i=0; i<P; i++) {
        vals[i].x = l + (i*(r-l)) / (P-1); // ����������� ��� x
        vals[i].y = function(vals[i].x); // ����������� ��� y=f(x)
    }

}

// ������� ��� ������� row ��� ������ screen �� "-"
void horizontal(int row)
{
    int i; // ��������

    // ������� ��� ������ ��� ������� row �� ��� ��������� "-"
    for (i=0; i<M; i++) {
        screen[row][i] = '-';
    }
}

// ������� ��� ������� row ��� ������ screen �� "-"
void vertical(int col)
{
    int i; // ��������

    // ������� ��� ������� ��� ������ col �� ��� ��������� "|"
    for (i=0; i<N; i++) {
        screen[i][col] = '|';
    }
}

// �������� ��� �������� ����������
void map_to_screen(double l, double r, double d, double u)
{
    int z; // ��������
    int i, j;  // �� �������������� �������������� ��� ������ screen, ���� ������� ����
    int col, row; // �� ������ 0,0 ��� ������

    // ����������� ��� ������� 0,0 ��� ������ ��� ���������� ����
    // ���� ������ screen, �� ����� ���� ��� ���� ��� ������
    col = nearest( ( (0-l) * (M-1) ) / (r-l) );
    row = nearest( ( (0-d) * (N-1) ) / (u-d) );

    if ( (row>=0 && row<N-1) && (col>=0 && col<=M-1) ) {
        vertical(col);
        horizontal(row);
    }

    // ���������� ��� ������ vals
    for (z=0; z<P; z++) {
        // ����������� ��� i, j ������������� ��� ��� ������ screen,
        // ���� �� ���� � ���������� "."
        i = nearest( ( (vals[z].y-d) * (N-1) ) / (u-d) );
        j = nearest( ( (vals[z].x-l) * (M-1) ) / (r-l) );

        // ��������� �� ����� ���� ��� ���� ��� ������
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