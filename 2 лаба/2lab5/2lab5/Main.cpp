//Main.cpp
#include <iostream>
#include "Combi1.h"
#include <tchar.h>
#include "Knapsack.h"
#include "Auxil.h"

#define ITEM_MAX_AMOUNT 18                // ���������� ��������� (��)
#define KNAP_MAX_WEIGHT 300               // ����������� ������� (��)

/*(������� 2, 6, 10, 14) ���������� � ������� (���� ��������� � �� ��������� ������������� ��������� �������:
����������� ������� 300 ��, ���� ��������� 10 � 300 ��, ��������� ��������� 5 � 55 �.�.; ���������� ��������� � 18 ��.);*/

int main()
{
    setlocale(LC_ALL, "rus");
    int item_weight[ITEM_MAX_AMOUNT],      // ��� �������� ������� ����  
        item_price[ITEM_MAX_AMOUNT];       // ��������� �������� ������� ���� 
    short item_instance[ITEM_MAX_AMOUNT];                       // ���������� ��������� ������� ����  {0,1}  

    auxil::start();
    for (int i = 0; i < ITEM_MAX_AMOUNT; i++) {
        item_weight[i] = (double)auxil::iget(10, 300);
        item_price[i] = (double)auxil::iget(5, 55);
    }

    int optimal_weight = knapsack_s(KNAP_MAX_WEIGHT, ITEM_MAX_AMOUNT, item_weight, item_price, item_instance);

    std::cout << "\t\t���������� ������ � �������";
    std::cout << std::endl << "- ���������� ��������� (��):\t\t" << ITEM_MAX_AMOUNT;
    std::cout << std::endl << "- ����������� ������� (��):\t\t" << KNAP_MAX_WEIGHT;

    std::cout << std::endl << "- ������� ��������� (��):\t\t";
    for (int i = 0; i < ITEM_MAX_AMOUNT; i++) std::cout << item_weight[i] << " ";
    std::cout << std::endl << "- ��������� �������� ($):\t\t";
    for (int i = 0; i < ITEM_MAX_AMOUNT; i++) std::cout << item_price[i] << " ";
    std::cout << std::endl << "- ����������� ��������� ������� ($):\t" << optimal_weight;
    std::cout << std::endl << "- ��� ������� (��):\t\t\t";
    int s = 0; for (int i = 0; i < ITEM_MAX_AMOUNT; i++) s += item_instance[i] * item_weight[i];
    std::cout << s;
    std::cout << std::endl << "- ������� ��������:\t\t\t";
    for (int i = 0; i < ITEM_MAX_AMOUNT; i++) std::cout << item_instance[i] << " ";
    std::cout << std::endl << std::endl;
    system("pause");
    return 0;
}