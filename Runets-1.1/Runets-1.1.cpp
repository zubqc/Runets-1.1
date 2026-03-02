#include <iostream>
#include <stdio.h>
#include "Header1.h"
using namespace std;


int operator-(masiv_class ths, masiv_class other) {
    node* current = ths.gethead();
    int max1 = -100, max2 = -100;
    for (int i{}; i < ths.getsize(); i++) {
        if (current->data > max1) {
            max1 = current->data;
        }
        current = current->next;
    }
    current = other.gethead();
    for (int i{}; i < other.getsize(); i++) {
        if (current->data > max2) {
            max2 = current->data;
        }
        current = current->next;
    }
    return(abs(max1 - max2));
}

void write2file(masiv_class* dMas) {
    FILE* textFile;
    fopen_s(&textFile, "tetFile.txt", "w+");
    if (textFile) {
        int size = dMas->getSize();
        for (int i = 0; i < size; i++)
            fprintf(textFile, "%d\n", dMas->getElement(i));
        fclose(textFile);
    }
}


int main()
{
    setlocale(LC_ALL, "Russian");
    masiv_class mas1;
    mas1.author();
    masiv_class mas2(3);
    mas2.setElement(0, 67);
    mas2.display();
    masiv_class mas3 = mas2;
    mas3.display();
    masiv_class mas4(3);
    mas4.display();
    printf("\nобъединение - %d\n", mas2 | mas4);
    printf("\nумножние - %d\n", *mas2);
    printf("\nразность - %d\n", mas2 - mas4);
    masiv_class mas5(4);
    mas5.display();
    mas5.addElementEnd(99);
    mas5.addElementFront(-99);
    mas5.insertElement(2, 0); 
    mas5.display();
    printf("\n3-uй элемент - %d", mas5.getElement(3));
    mas5.delElement(0);
    mas5.display();
}

