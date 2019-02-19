/**
 *
 * File: kyranis_2B.c
 *
 * Created by Yiannis Kiranis <std138327@ac.eap.gr>
 *
 * Date: 23/1/2019
 * Time: 2:50 ��
 *
 * ���������� 2�
 *
 * �� ������ ��������� ��� ������ ��������������� C, �� ����� �� �������� ��������� 3
 * ��������� �������� ��� �� ���� ������� �� ��� ���� ����������� �����. �� ��������������
 * ��������� ��������������� ���� � ������ ������� �� ����� ��� �������� [-10,10], ��� ����
 * �������� �� �������� �10 ��� ��� ����������� ��� (�.�. �� � ������ ������� ����� 7, ���� �
 * �������� ������ �� ����� ��� �������� [-3,17]. �� ���������� � �������� ����� -2, ���� � ������
 * ������ �� ����� ��� �������� [-12,8]). ��� ����� �� ��������� �� ����� ��� �� ��������� ���
 * ���� ���� ������, ����� ��� �� ������ ��� ������ �� ������ ����.
 *
 */

#include <stdio.h>
#include <stdlib.h>

#define NUMBERS 3 // �� ������ ��� ������� ��� ������ �� ���������
#define RANGE 10  // �� �������� ��� ��� ����������� ������

struct node /* ������� ������ ������ */
{
    int data;
    struct node *next; /* ������� �� ���� ����� node */
} *head;

// �������� ��������� ��� ����� ��� ������
void insertInList(int value)
{
    struct node *item, *temp; // ������ ������ ���� �������� ��� ����������
    temp = head; // � ������ ������� ���� ���� ��� ������

    item = (struct node *) malloc(sizeof (struct node)); // �������� ������
    item->data = value; // �� ����� data ������� ��� ���� ��� �������� �������

    if(head==NULL) { // �� � ����� ����� ����� ��������� ��� ���� ���
        head = item;
        head->next = NULL;
    } else { // ������ ������� � �������� ���� �����
        while(temp->next!=NULL) { // ���������� ���� ��������� ����� ��� ������ ���������
            temp = temp->next;
        }

        item->next = NULL; // �� ����� next ������� ��� ���� null ��� �� ������� ��� ��� ����� �� �����
        temp->next = item; // � ���������� ������ ������� ���� ���
    }
}


// �������� ����� ���� ������������ ������ ��� ������� ������� �������
void displayList()
{
    struct node *temp; // ������ ���������� ������ ����� node
    int countPositives = 0; // �������� ������� �����

    temp = head; // � ������ ������� ���� ���� ��� ������

    if (temp==NULL) { // �� � ����� ����� �����
        printf("\n� ����� ����� �����");
    } else { // �� ��� ����� �����

        printf("\n����� ������: ");

        while (temp!=NULL) { // ��� ��� ������ ������ ��� ����� ��� ������
            printf("%d ", temp->data); // �������� ��� ������ data

            if (temp->data>0) { // �� � ������� ����� ������� ��������� ��� �������
                countPositives++;
            }

            temp = temp->next; // ��������� ���� ������� �����
        }

        printf("\n�������� %d ������� ����� ���� �����\n", countPositives);
    }
}

int main()
{
    int i; // ��������
    int number; // ������� ��� ������� � �������
    int startRange, endRange; // ���� ��� ������ ����������� ��� ������ �� ������ � �������

    number = 0; // ���������� ��� ������� ��� �� ���������� �� ������ �������� ���������� �������

    // �������� ��������� ��� NUMBERS ��������, �� �������� ��������������
    for(i=0; i<NUMBERS; i++) {

        // ����������� ��� ����� ��� ������ ��� ����������� ��� ������ � �������� �������
        startRange = number - RANGE;
        endRange = number + RANGE;

        do {
            printf("\n�������� ��� ���� ��� %d�� ������: [%d,%d] ", i+1, startRange, endRange);
            scanf("%d", &number);

            if (number<startRange || number>endRange) {
                printf("\n����� ����! � ���� ������ �� ����� ��� ��������: [%d,%d]", startRange, endRange);
            }
        } while (number<startRange || number>endRange);

        insertInList(number);
    }

    displayList();

    return 0;
}
