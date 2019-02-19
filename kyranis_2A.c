/**
 *
 * File: kyranis_2A.c
 *
 * Created by Yiannis Kiranis <std138327@ac.eap.gr>
 *
 * Date: 23/1/2019
 * Time: 1:48 ��
 * 
 * ���������� 2�
 *
 * �� ������ ��������� ��� ������ ��������������� C, �� ����� �� �������� ��� ��
 * ������������ ��� ������ ������� ������ �������������, ��� ���� �������� �� ���������� ��
 * ������������ �� ���, �����, ������, ����, ����� ��� ������������, �� ����� ��� �� ���������.
 * �� �������������� ��������� ��������������� ���� � ������� �� ����� ������� ��� �� ���� 9
 * ������. �������� ��� ���� ����� ���� 30 ������
 *
 */

#include <stdio.h>

// �� ������������� ��� ������
#define MONTHS 12
#define DAYS 30
#define HOURS 24
#define MINUTES 60
#define SECONDS 60

int main()
{

    int givenSeconds; // �� ������������ ��� ����� � �������
    int remainSeconds; // �� �������� ��� ������������� ��� �������� ��� ��� ������� ���������
    int years, months, days, hours, minutes, seconds; // �� ����������� ����������

    // � ������� ����� ������ ������������� �� �������� �������������� (1-999999999)
    do {
        printf("���� ������ �������������: ");
        scanf("%d", &givenSeconds);

        if (givenSeconds<=0 || givenSeconds>999999999) {
            printf("� ������� ��� ������������� �� ������ �� ����� ������� �������� ����� 9 �����\n");
        }

    } while (givenSeconds<=0 || givenSeconds>999999999);

    // ����������� ��� ���� ����������. � �������� ����� ��� ���������.
    // �� �������� ��� ����������� ��� ��� ������� ���������
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

    // �������� ��� �������������
    printf("�� %d ������������ ������������ ��\n%d ������, %d �����, %d �����, %d ����, %d �����, %d ������������\n",
            givenSeconds, years, months, days, hours, minutes, seconds);

    return 0;
}