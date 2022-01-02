#include <iostream>
#include <list>
#include <utility>
#include <stdio.h>
#include <random>
#include <time.h>
#include <locale.h>
#include <windows.h>
#include <string.h>
using namespace std;


void dekartovo(int** mass,int** mass_p2,int n,int n1) {
    //int M[2] = { 1,2 };
    //int J[3] = { 0,1,2 };
    //vector<pair<int, int>> C;
    cout << "Первая матрица";
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << mass[i][j]<<" ";
        }
        printf("\n");
    }
    cout << endl; 
    cout << "Вторая матрица";
    cout << endl;
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n1; j++)
        {
            cout << mass_p2[i][j] << " ";
        }
        printf("\n");
    }
   
    cout << endl;
    int nomer1, nomer2,z,r;
    nomer1 = 0;
    nomer2 = 0;
    z = 0;
    r = 0;
    int** mass_dek = (int**)malloc(sizeof(int) * n * n1);
    for (int i = 0; i < n * n1; i++) {
        mass_dek[i] = (int*)malloc(sizeof(int) * n * n1);
    }
    
    for (int i = 0; i < n * n1; i++)
    {
        if (z == n1)
        {
            z = 0;
            nomer1++;
        }
        r = 0;
        nomer2 = 0;
        for (int j = 0; j < n * n1; j++)
        {
            if (r == n1)
            {
                r = 0;
                nomer2++;
            }

            if (nomer1 == nomer2)
            {
                mass_dek[i][j] = mass_p2[z][r];
            }
            else
            {
                if (z == r)
                {
                    mass_dek[i][j] = mass[nomer1][nomer2];
                }
                else
                {
                    mass_dek[i][j] = 0;
                }
            }
            //mass_dek[i][j] = mass[nomer1][nomer2] * mass_p2[z][r];
            r++;
        }
        z++;
    }
    

    for (int i = 0; i < n * n1; i++)
    {
        for (int j = 0; j < n * n1; j++)
        {
            cout << mass_dek[i][j] << " ";
        }
        printf("\n");
    }
}


using namespace std;

void cpy(int** mass1, int** mass2, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            mass1[i][j] = mass2[i][j];
        }
    }
}

void generate(int** mass, int n) { // заполнение массивов
    int i, r, c;
    for (i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            r = rand() % 2;
            c = rand() % 2;
            if (r == 1) {
                mass[i][j] = 1;
            }
            else
                mass[i][j] = 0;
            if (i == j) {
                mass[i][j] = 0;
            }

        }
    }
    for (i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (mass[i][j] != mass[j][i]) {
                mass[i][j] = mass[j][i];
            }
        }
    }

}

void otoz_lst(int s, int s1, list<list<int>>* spiski, bool print_fl) { //отождествление

    int i, j;
    list<list<int>>::iterator spiski_iter_loc1 = spiski->begin();
    list<list<int>>::iterator spiski_iter_loc2 = spiski->begin();

    list<int> spisok_loc1, spisok_loc2;
    list<int>::iterator spisok_iter_loc1, spisok_iter_loc2;
    bool insert_versh = false;
    bool del_versh = false;


    for (i = 0; i < s; i++)
    {
        spiski_iter_loc1++;
    }
    spisok_iter_loc1 = (*spiski_iter_loc1).begin();

    for (i = 0; i < s1; i++)
    {
        spiski_iter_loc2++;
    }
    spisok_iter_loc2 = (*spiski_iter_loc2).begin();

    while (spisok_iter_loc2 != (*spiski_iter_loc2).end())
    {
        insert_versh = false;
        spisok_iter_loc1 = (*spiski_iter_loc1).begin();
        while (spisok_iter_loc1 != (*spiski_iter_loc1).end())
        {
            if ((*spisok_iter_loc1) == (*spisok_iter_loc2))
            {
                insert_versh = true;
            }
            spisok_iter_loc1++;
        }
        if (!insert_versh)
            (*spiski_iter_loc1).push_back((*spisok_iter_loc2));
        spisok_iter_loc2++;
    }

    spiski_iter_loc2 = spiski->erase(spiski_iter_loc2);

    spiski_iter_loc1 = spiski->begin();
    i = 0;

    while (spiski_iter_loc1 != spiski->end())
    {
        spisok_iter_loc1 = (*spiski_iter_loc1).begin();
        while (spisok_iter_loc1 != (*spiski_iter_loc1).end())
        {
            if ((*spisok_iter_loc1) == s1)
            {
                if (i == s)
                    spisok_iter_loc1 = (*spiski_iter_loc1).erase(spisok_iter_loc1);
                else
                    (*spisok_iter_loc1) = s;
            }
            else
            {
                if ((*spisok_iter_loc1) > s1)
                {
                    (*spisok_iter_loc1) = (*spisok_iter_loc1) - 1;
                }
            }
            if (spisok_iter_loc1 != (*spiski_iter_loc1).end())
                spisok_iter_loc1++;
        }
        (*spiski_iter_loc1).sort();
        (*spiski_iter_loc1).unique();
        spiski_iter_loc1++;
        i++;
    }



    spiski_iter_loc1 = spiski->begin();
    if (print_fl)
    {
        printf("Результат отождествления вершин 1ых списков смежности:\n");
        while (spiski_iter_loc1 != spiski->end())
        {
            spisok_iter_loc1 = (*spiski_iter_loc1).begin();
            printf("{ ");
            while (spisok_iter_loc1 != (*spiski_iter_loc1).end())
            {
                printf("%d ", *spisok_iter_loc1);
                spisok_iter_loc1++;
            }
            printf("}");
            printf("\n");
            spiski_iter_loc1++;
        }
    }
}

void otoz(int s, int s1, int** mass, int n) { //отождествление
    int i, j;
    printf("Результат отождествления вершин 1й матрицы:\n");

    for (i = 0; i < n; i++) { //заносим 1ю матрицу
        for (j = 0; j < n; j++) {
            if (mass[s][j] > mass[s1][j])
                mass[s1][j] = 1;
            if (mass[i][s1] > mass[s1][j])
                mass[i][s1] = 1;
        }
    }

    int l = 0, g = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (mass[s][j] == 1)
                g = 1;
            if (mass[i][s] == 1)
                l = 1;
            mass[s][j] = 0;
            if (g == 1)
                mass[s1][j] = g;
            mass[i][s] = 0;
            if (l == 1)
                mass[i][s1] = l;
            g = 0;
            l = 0;
            mass[s1][s1] = 0;
            mass[s][s] = 0;

        }
    }

    //выполняем отождествление и вывод матрицы
    int** printmass = (int**)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i == s || j == s) {
                continue;
            }
            printf("%d ", mass[i][j]);
        }
        if (i != s) {
            printf("\n");
        }

    }

}

void styag_lst(int s, int s1, list<list<int>>* spiski) { //стягивание

    int i, j;
    list<list<int>>::iterator spiski_iter_loc1 = spiski->begin();
    list<list<int>>::iterator spiski_iter_loc2;
    list<int> spisok_loc1, spisok_loc2;
    list<int>::iterator spisok_iter_loc1, spisok_iter_loc2;
    bool del_versh = false;
    bool s_check = false;
    bool s1_check = false;
    bool smezh_versh = false;


    for (i = 0; i < s; i++)
    {
        spiski_iter_loc1++;
    }
    spisok_iter_loc1 = (*spiski_iter_loc1).begin();

    spiski_iter_loc2 = spiski->begin();

    for (i = 0; i < s1; i++)
    {
        spiski_iter_loc2++;
    }
    spisok_iter_loc2 = (*spiski_iter_loc2).begin();

    while (spisok_iter_loc1 != (*spiski_iter_loc1).end())
    {
        if ((*spisok_iter_loc1) == s1)
            s1_check = true;
        spisok_iter_loc1++;

    }

    while (spisok_iter_loc2 != (*spiski_iter_loc2).end())
    {
        if ((*spisok_iter_loc2) == s)
            s_check = true;
        spisok_iter_loc2++;

    }

    smezh_versh = s1_check && s_check;
    if (smezh_versh)
    {
        spisok_iter_loc1 = (*spiski_iter_loc1).begin();
        spisok_iter_loc2 = (*spiski_iter_loc2).begin();

        while (spisok_iter_loc1 != (*spiski_iter_loc1).end())
        {
            if ((*spisok_iter_loc1) == s1)
                spisok_iter_loc1 = (*spiski_iter_loc1).erase(spisok_iter_loc1);
            if (spisok_iter_loc1 != (*spiski_iter_loc1).end())
                spisok_iter_loc1++;
        }

        while (spisok_iter_loc2 != (*spiski_iter_loc2).end())
        {
            if ((*spisok_iter_loc2) == s)
                spisok_iter_loc2 = (*spiski_iter_loc2).erase(spisok_iter_loc2);
            if (spisok_iter_loc2 != (*spiski_iter_loc2).end())
                spisok_iter_loc2++;
        }

        otoz_lst(s, s1, spiski, false);

        printf("\nРезультат стягивания вершин 1ых списков смежности:\n");
        spiski_iter_loc1 = spiski->begin();

        while (spiski_iter_loc1 != spiski->end())
        {
            spisok_iter_loc1 = (*spiski_iter_loc1).begin();
            printf("{ ");
            while (spisok_iter_loc1 != (*spiski_iter_loc1).end())
            {
                printf("%d ", *spisok_iter_loc1);
                spisok_iter_loc1++;
            }
            printf("}");
            printf("\n");
            spiski_iter_loc1++;
        }
    }
}

void styag(int s, int s1, int** mass1, int n) { //стягивание
    int g = 0, l = 0;
    printf("Результат стягивания ребра 1й матрицы:\n");
    if (mass1[s][s1]==1)
    { 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (mass1[s][j] == 1)
                g = 1;
            if (mass1[i][s] == 1)
                l = 1;
            mass1[s][j] = 0;
            if (g == 1)
                mass1[s1][j] = g;
            mass1[i][s] = 0;
            if (l == 1)
                mass1[i][s1] = l;
            g = 0;
            l = 0;
            mass1[s1][s1] = 0;
        }
    }
    
    for (int i = 0; i < n; i++) { //выполняем стягивание и вывод матрицы
        for (int j = 0; j < n; j++) {
            if (i == s || j == s) {
                continue;
            }
            printf("%d ", mass1[i][j]);
        }
        if (i != s) {
            printf("\n");
        }
    }
    }
}

void ras_lst(int s, list<list<int>>* spiski) { //расщепление

    int i, j, size_lst;
    list<list<int>>::iterator spiski_iter_loc1 = spiski->begin();
    list<list<int>>::iterator spiski_iter_loc2 = spiski->begin();
    list<int> spisok_insert;
    list<int>::iterator spisok_iter_loc1, spisok_iter_loc2;

    size_lst = spiski->size();
    printf("Результат расщепления вершин 1ых списков смежности:\n");

    for (i = 0; i < s; i++)
    {
        spiski_iter_loc1++;
    }
    spisok_iter_loc1 = (*spiski_iter_loc1).begin();
    (*spiski_iter_loc1).push_back(size_lst);


    while (spisok_iter_loc1 != (*spiski_iter_loc1).end())
    {
        if ((*spisok_iter_loc1) < (size_lst / 2))
        {
            spisok_insert.push_back((*spisok_iter_loc1));
            spisok_iter_loc1 = (*spiski_iter_loc1).erase(spisok_iter_loc1);
        }
        if (spisok_iter_loc1 != (*spiski_iter_loc1).end())
            spisok_iter_loc1++;
    }
    spisok_insert.push_back(s);
    spiski->push_back(spisok_insert);

    spiski_iter_loc1 = spiski->begin();

    while (spiski_iter_loc1 != spiski->end())
    {
        spisok_iter_loc1 = (*spiski_iter_loc1).begin();
        printf("{ ");
        while (spisok_iter_loc1 != (*spiski_iter_loc1).end())
        {
            printf("%d ", *spisok_iter_loc1);
            spisok_iter_loc1++;
        }
        printf("}");
        printf("\n");
        spiski_iter_loc1++;
    }
}

void ras(int s, int s1, int** mass2, int n, int** mass3) { //расщепление
    printf("\nРезультат расщепления вершины 1й матрицы:\n");

    for (int i = 0; i < n + 1; i++) {
        for (int j = 0; j < n + 1; j++) {
            mass2[i][j] = 0;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            mass2[i][j] = mass3[i][j];
        }
    }

    for (int i = 0; i < n + 1; i++) { //расщепление вершины 1й матрицы
        for (int j = 0; j < n + 1; j++) {
            mass2[n][s] = 1;
            mass2[s][n] = 1;
            if (j < n / 2 && mass2[s][j] == 1) {
                mass2[n][j] = 1;
                mass2[s][j] = 0;
            }
            if (i < n / 2 && mass2[i][s] == 1) {
                mass2[i][n] = 1;
                mass2[i][s] = 0;
            }
            printf("%d ", mass2[i][j]); //вывод результата
        }
        printf("\n");
    }
}

void obe_lst(list<list<int>>* spiski1, list<list<int>>* spiski2) { //объединение

    list<list<int>>::iterator spiski_iter_loc1 = spiski1->begin();
    list<list<int>>::iterator spiski_iter_loc2 = spiski2->begin();
    list<int>::iterator spisok_iter_loc1, spisok_iter_loc2;
    bool versh_searched = false;

    printf("Результат объединения 2ух экземпляров списков смежности:\n");

    if (spiski1->size() >= spiski2->size())
    {
        while (spiski_iter_loc2 != spiski2->end())
        {
            spisok_iter_loc2 = spiski_iter_loc2->begin();
            while (spisok_iter_loc2 != (*spiski_iter_loc2).end())
            {
                versh_searched = false;
                spisok_iter_loc1 = (*spiski_iter_loc1).begin();
                while (spisok_iter_loc1 != (*spiski_iter_loc1).end())
                {
                    if ((*spisok_iter_loc2) == (*spisok_iter_loc1))
                        versh_searched = true;
                    spisok_iter_loc1++;
                }
                if (!versh_searched)
                    (*spiski_iter_loc1).push_back((*spisok_iter_loc2));
                spisok_iter_loc2++;
            }
            spiski_iter_loc2++;
            spiski_iter_loc1++;
        }

        spiski_iter_loc1 = spiski1->begin();

        while (spiski_iter_loc1 != spiski1->end())
        {
            spisok_iter_loc1 = (*spiski_iter_loc1).begin();
            printf("{ ");
            while (spisok_iter_loc1 != (*spiski_iter_loc1).end())
            {
                printf("%d ", *spisok_iter_loc1);
                spisok_iter_loc1++;
            }
            printf("}");
            printf("\n");
            spiski_iter_loc1++;
        }
    }

    if (spiski2->size() > spiski1->size())
    {
        while (spiski_iter_loc1 != spiski1->end())
        {
            spisok_iter_loc1 = spiski_iter_loc1->begin();
            while (spisok_iter_loc1 != (*spiski_iter_loc1).end())
            {
                versh_searched = false;
                spisok_iter_loc2 = (*spiski_iter_loc2).begin();
                while (spisok_iter_loc2 != (*spiski_iter_loc2).end())
                {
                    if ((*spisok_iter_loc1) == (*spisok_iter_loc2))
                        versh_searched = true;
                    spisok_iter_loc2++;
                }
                if (!versh_searched)
                    (*spiski_iter_loc2).push_back((*spisok_iter_loc1));
                spisok_iter_loc1++;
            }
            spiski_iter_loc1++;
            spiski_iter_loc2++;
        }

        spiski_iter_loc2 = spiski1->begin();

        while (spiski_iter_loc2 != spiski1->end())
        {
            spisok_iter_loc2 = (*spiski_iter_loc2).begin();
            printf("{ ");
            while (spisok_iter_loc2 != (*spiski_iter_loc2).end())
            {
                printf("%d ", *spisok_iter_loc2);
                spisok_iter_loc2++;
            }
            printf("}");
            printf("\n");
            spiski_iter_loc2++;
        }
    }
}


void obe(int** mass_p1, int** mass_p2, int n, int n1) { //объединение
    int i, j;

    printf("Матрица 1\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {

            printf("%d ", mass_p1[i][j]); //вывод матрицы
        }
        printf("\n");
    }

    printf("\nМатрица 2\n");
    for (i = 0; i < n1; i++) {
        for (j = 0; j < n1; j++) {

            printf("%d ", mass_p2[i][j]); //вывод матрицы
        }
        printf("\n");
    }

    //выполнение операции
    if (n >= n1) {
        for (i = 0; i < n1; i++) {
            for (j = 0; j < n1; j++) {
                if (mass_p1[i][j] != 1 && mass_p2[i][j] == 1) {
                    mass_p1[i][j] = 1;
                }
            }
        }
        printf("\nРезультат объединения матриц:\n");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                printf("%d ", mass_p1[i][j]);
            }
            printf("\n");
        }
    }

    if (n1 > n) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (mass_p1[i][j] == 1 && mass_p2[i][j] != 1) {
                    mass_p2[i][j] = 1;
                }
            }
        }

        printf("\nРезультат объединения матриц:\n");
        for (int i = 0; i < n1; i++) {
            for (int j = 0; j < n1; j++) {
                printf("%d ", mass_p2[i][j]);
            }
            printf("\n");
        }
    }
}

void pere_lst(list<list<int>>* spiski1, list<list<int>>* spiski2) { //пересечение

    list<list<int>>::iterator spiski_iter_loc1 = spiski1->begin();
    list<list<int>>::iterator spiski_iter_loc2 = spiski2->begin();
    list<int>::iterator spisok_iter_loc1, spisok_iter_loc2;
    bool versh_searched = false;

    printf("Результат пересечения 2ух экземпляров списков смежности:\n");

    if (spiski1->size() >= spiski2->size())
    {
        while (spiski_iter_loc2 != spiski2->end())
        {
            spisok_iter_loc1 = spiski_iter_loc1->begin();
            while (spisok_iter_loc1 != spiski_iter_loc1->end())
            {
                versh_searched = false;

                if (!spiski_iter_loc2->empty())
                {
                    spisok_iter_loc2 = spiski_iter_loc2->begin();
                    while (spisok_iter_loc2 != spiski_iter_loc2->end())
                    {
                        if ((*spisok_iter_loc2) == (*spisok_iter_loc1))
                        {
                            versh_searched = true;
                            break;
                        }
                        spisok_iter_loc2++;
                    }
                    if (!versh_searched)
                        spisok_iter_loc1 = spiski_iter_loc1->erase(spisok_iter_loc1);
                    else
                    {
                        if (spisok_iter_loc1 != (*spiski_iter_loc1).end())
                            spisok_iter_loc1++;
                    }
                }
            }
            spiski_iter_loc2++;
            spiski_iter_loc1++;
        }

        spiski_iter_loc1 = spiski1->begin();

        while (spiski_iter_loc1 != spiski1->end())
        {
            spisok_iter_loc1 = spiski_iter_loc1->begin();
            printf("{ ");
            while (spisok_iter_loc1 != spiski_iter_loc1->end())
            {
                printf("%d ", *spisok_iter_loc1);
                spisok_iter_loc1++;
            }
            printf("}");
            printf("\n");
            spiski_iter_loc1++;
        }
    }

    if (spiski2->size() > spiski1->size())
    {
        while (spiski_iter_loc1 != spiski1->end())
        {
            spisok_iter_loc2 = spiski_iter_loc2->begin();
            while (spisok_iter_loc2 != spiski_iter_loc2->end())
            {
                versh_searched = false;
                if (!spiski_iter_loc1->empty())
                {
                    spisok_iter_loc1 = spiski_iter_loc1->begin();
                    while (spisok_iter_loc1 == spiski_iter_loc1->end())
                    {
                        if ((*spisok_iter_loc1) == (*spisok_iter_loc2))
                        {
                            versh_searched = true;
                            break;
                        }
                        spisok_iter_loc1++;
                    }
                    if (!versh_searched)
                        spisok_iter_loc2 = spiski_iter_loc2->erase(spisok_iter_loc2);
                    else
                    {
                        if (spisok_iter_loc2 != (*spiski_iter_loc2).end())
                            spisok_iter_loc2++;
                    }
                }
            }
            spiski_iter_loc1++;
            spiski_iter_loc2++;
        }

        spiski_iter_loc2 = spiski2->begin();

        while (spiski_iter_loc2 != spiski2->end())
        {
            spisok_iter_loc2 = spiski_iter_loc2->begin();
            printf("{ ");
            while (spisok_iter_loc2 != spiski_iter_loc2->end())
            {
                printf("%d ", *spisok_iter_loc2);
                spisok_iter_loc2++;
            }
            printf("}");
            printf("\n");
            spiski_iter_loc2++;
        }
    }
}


void pere(int** mass_o1, int** mass_o2, int n, int n1) { //пересечение
    int i, j;
    printf("Матрица 1\n");
    for (i = 0; i < n; i++) { //вывод матрицы1
        for (j = 0; j < n; j++) {

            printf("%d ", mass_o1[i][j]);
        }
        printf("\n");
    }

    printf("\nМатрица 2\n");
    for (i = 0; i < n1; i++) { //вывод матрицы2
        for (j = 0; j < n1; j++) {

            printf("%d ", mass_o2[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    if (n >= n1) { //выполнение операции
        for (i = 0; i < n1; i++) {
            for (j = 0; j < n1; j++) {
                if (mass_o2[i][j] == 1 && mass_o1[i][j] == 1)
                    mass_o1[i][j] = 1;
                else mass_o1[i][j] = 0;
            }
        }
        printf("Результат пересечения матриц:\n");
        for (i = 0; i < n1; i++) {
            for (j = 0; j < n1; j++) {
                printf("%d ", mass_o1[i][j]);
            }
            printf("\n");
        }
    }
    if (n1 > n) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (mass_o2[i][j] == 1 && mass_o1[i][j] == 1)
                    mass_o2[i][j] = 1;
                else mass_o2[i][j] = 0;
                if (n > n1) {
                    mass_o2[i][j] = 0;
                }
            }
        }

        printf("Результат пересечения матриц:\n");
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                printf("%d ", mass_o2[i][j]);
            }
            printf("\n");
        }
    }
    printf("\n");
}

void kolz_lst(list<list<int>>* spiski1, list<list<int>>* spiski2) { //кольцевая сумма

    list<list<int>>::iterator spiski_iter_loc1 = spiski1->begin();
    list<list<int>>::iterator spiski_iter_loc2 = spiski2->begin();
    list<int>::iterator spisok_iter_loc1, spisok_iter_loc2;
    bool versh_searched = false;

    printf("Результат кольцевой суммы 2ух экземпляров списков смежности:\n");

    if (spiski1->size() >= spiski2->size())
    {
        while (spiski_iter_loc2 != spiski2->end())
        {
            spisok_iter_loc2 = spiski_iter_loc2->begin();
            while (spisok_iter_loc2 != spiski_iter_loc2->end())
            {
                versh_searched = false;

                if (!spiski_iter_loc1->empty())
                {
                    spisok_iter_loc1 = spiski_iter_loc1->begin();
                    while (spisok_iter_loc1 != spiski_iter_loc1->end())
                    {
                        if ((*spisok_iter_loc1) == (*spisok_iter_loc2))
                        {
                            versh_searched = true;
                            break;
                        }
                        spisok_iter_loc1++;
                    }
                    if (versh_searched)
                    {
                        spisok_iter_loc1 = spiski_iter_loc1->erase(spisok_iter_loc1);
                    }
                    else
                    {
                        spiski_iter_loc1->push_back((*spisok_iter_loc2));
                    }
                    spisok_iter_loc2++;
                }
            }
            spiski_iter_loc2++;
            spiski_iter_loc1++;
        }

        spiski_iter_loc1 = spiski1->begin();

        while (spiski_iter_loc1 != spiski1->end())
        {
            spisok_iter_loc1 = spiski_iter_loc1->begin();
            printf("{ ");
            while (spisok_iter_loc1 != spiski_iter_loc1->end())
            {
                printf("%d ", *spisok_iter_loc1);
                spisok_iter_loc1++;
            }
            printf("}");
            printf("\n");
            spiski_iter_loc1++;
        }
    }

    if (spiski2->size() > spiski1->size())
    {
        while (spiski_iter_loc1 != spiski1->end())
        {
            spisok_iter_loc1 = spiski_iter_loc1->begin();
            while (spisok_iter_loc1 != spiski_iter_loc1->end())
            {
                versh_searched = false;
                if (!spiski_iter_loc2->empty())
                {
                    spisok_iter_loc2 = spiski_iter_loc2->begin();
                    while (spisok_iter_loc2 == spiski_iter_loc2->end())
                    {
                        if ((*spisok_iter_loc2) == (*spisok_iter_loc1))
                        {
                            versh_searched = true;
                            break;
                        }
                        spisok_iter_loc2++;
                    }
                    if (versh_searched)
                    {
                        spisok_iter_loc2 = spiski_iter_loc2->erase(spisok_iter_loc2);
                    }
                    else
                    {
                        spiski_iter_loc2->push_back((*spisok_iter_loc1));
                    }
                    spisok_iter_loc1++;
                }
            }
            spiski_iter_loc1++;
            spiski_iter_loc2++;
        }

        spiski_iter_loc2 = spiski2->begin();

        while (spiski_iter_loc2 != spiski2->end())
        {
            spisok_iter_loc2 = spiski_iter_loc2->begin();
            printf("{ ");
            while (spisok_iter_loc2 != spiski_iter_loc2->end())
            {
                printf("%d ", *spisok_iter_loc2);
                spisok_iter_loc2++;
            }
            printf("}");
            printf("\n");
            spiski_iter_loc2++;
        }
    }
}

void kolz(int** mass_k1, int** mass_k2, int n, int n1) { //кольцевая сумма
    int i, j;
    printf("\nМатрица 1\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {

            printf("%d ", mass_k1[i][j]);
        }
        printf("\n");
    }

    printf("\nМатрица 2\n");
    for (i = 0; i < n1; i++) {
        for (j = 0; j < n1; j++) {

            printf("%d ", mass_k2[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    if (n >= n1) { //выполнение операции
        for (i = 0; i < n1; i++) {
            for (j = 0; j < n1; j++) {
                if (mass_k1[i][j] != 1 && mass_k2[i][j] == 1 || mass_k2[i][j] != 1 && mass_k1[i][j] == 1) {
                    mass_k1[i][j] = 1;
                }
                else mass_k1[i][j] = 0;
            }
        }

        printf("Результат кольцевой суммы матриц:\n");
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                printf("%d ", mass_k1[i][j]);
            }
            printf("\n");
        }
    }
    if (n1 > n) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (mass_k1[i][j] != 1 && mass_k2[i][j] == 1 || mass_k2[i][j] != 1 && mass_k1[i][j] == 1) {
                    mass_k2[i][j] = 1;
                }
                else mass_k2[i][j] = 0;
            }
        }

        printf("Результат кольцевой суммы матриц:\n");
        for (i = 0; i < n1; i++) {
            for (j = 0; j < n1; j++) {
                printf("%d ", mass_k2[i][j]);
            }
            printf("\n");
        }
    }
}

int main() {
    setlocale(LC_ALL, "Rus");
    srand(time(NULL));
    int s, s1, n, n1;

    printf("ЗАДАНИЕ 1\n");
    
    list<list<int>>* spiski, * spiski1;
    list<list<int>>* spiski_p2, * spiski2;
    list<list<int>>::iterator spiski_iter;
    list<int> spisok;
    list<int>::iterator spisok_iter;

    spiski = new list<list<int>>;
    spiski1 = new list<list<int>>;
    spiski_p2 = new list<list<int>>;
    spiski2 = new list<list<int>>;


    printf("Введите размеры массивов через пробел:");
    scanf_s("%d %d", &n, &n1);
    int** mass = (int**)malloc(sizeof(int) * n);
    int** mass1 = (int**)malloc(sizeof(int) * n);
    int** mass_p1 = (int**)malloc(sizeof(int) * n);
    int** mass_o1 = (int**)malloc(sizeof(int) * n);
    int** mass_k1 = (int**)malloc(sizeof(int) * n);
    int** mass_k5 = (int**)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        mass[i] = (int*)malloc(sizeof(int) * n);
        mass1[i] = (int*)malloc(sizeof(int) * n);
        mass_p1[i] = (int*)malloc(sizeof(int) * n);
        mass_o1[i] = (int*)malloc(sizeof(int) * n);
        mass_k1[i] = (int*)malloc(sizeof(int) * n);
        mass_k5[i] = (int*)malloc(sizeof(int) * n);
    }
    int** massre = (int**)malloc(sizeof(int) * n1);
    int** mass_p2 = (int**)malloc(sizeof(int) * n1);
    int** mass_o2 = (int**)malloc(sizeof(int) * n1);
    int** mass_k2 = (int**)malloc(sizeof(int) * n1);
    int** mass_o5 = (int**)malloc(sizeof(int) * n1);
    for (int i = 0; i < n1; i++) {
        massre[i] = (int*)malloc(sizeof(int) * n1);
        mass_p2[i] = (int*)malloc(sizeof(int) * n1);
        mass_o2[i] = (int*)malloc(sizeof(int) * n1);
        mass_k2[i] = (int*)malloc(sizeof(int) * n);
        mass_o5[i] = (int*)malloc(sizeof(int) * n1);
    }
    int** mass2 = (int**)malloc(sizeof(int) * n + 1);
    for (int i = 0; i < n + 1; i++) {
        mass2[i] = (int*)malloc(sizeof(int) * n + 1);
    }
    int** mass3 = (int**)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        mass3[i] = (int*)malloc(sizeof(int) * n);
    }

    int i = 0;
    int j = 0, k = 0, m = 0;
    int a;

    printf("Действия с матрицами\n\n");

    printf("\nМатрица 1:\n");
    generate(mass, n);
    generate(mass_p2,
        n1);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            mass1[i][j] = mass[i][j];
            mass_o1[i][j] = mass1[i][j];
            mass_p1[i][j] = mass1[i][j];
            mass_k1[i][j] = mass1[i][j];
            mass_k5[i][j] = mass1[i][j];
        }
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", mass[i][j]);
        }
        printf("\n");
    }

    printf("\nМатрица 2:\n");
    for (i = 0; i < n1; i++) {
        for (j = 0; j < n1; j++) {
            printf("%d ", mass_p2[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    printf("\nЗАДАНИЕ 2\n");


    for (int i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (mass[i][j] == 1)
            {
                spisok.push_back(j);
            }
        }
        spiski->push_back(spisok);
        spisok.clear();
    }

    for (int i = 0; i < n1; i++)
    {
        for (j = 0; j < n1; j++)
        {
            if (mass_p2[i][j] == 1)
            {
                spisok.push_back(j);
            }
        }
        spiski_p2->push_back(spisok);
        spisok.clear();
    }


    printf("1.Отождествление вершин\n");
    printf("Введите номера вершин:");
    scanf_s("%d %d", &s, &s1);
    printf("\n");
    cpy(mass3, mass, n);
    otoz(s, s1, mass3, n);
    printf("\n");
    printf("\n2.Стягивание ребер\n");
    printf("\n");
    cpy(mass3, mass, n);
    styag(s, s1, mass3, n);
    printf("\n");
    printf("\n3.Расщепление вершин\n");
    cpy(mass3, mass, n);
    ras(s, s1, mass2, n, mass3);
    printf("\n");

    printf("\nЗАДАНИЕ 3\n");

    printf("1.Объединение матриц\n");
    cpy(mass_k2, mass_p2, n1);
    cpy(mass_o5, mass_p2, n1);
    printf("\n");
    obe(mass_p1, mass_p2, n, n1);
    printf("\n");
    printf("\n2.Пересечение матриц\n");
    cpy(mass_o2, mass_p2, n1);
    printf("\n");
    pere(mass_o1, mass_o2, n, n1);
    printf("\n3.Кольцевая сумма матриц\n");
    kolz(mass_k1, mass_k2, n, n1);
    printf("\nДекартово произведение графов\n");
    dekartovo(mass, mass_o5,n,n1);

    printf("\nДействия со списками смежности\n\n");

    printf("1ые списки смежности:\n");

    spiski_iter = spiski->begin();

    while (spiski_iter != spiski->end())
    {
        spisok_iter = (*spiski_iter).begin();
        printf("{ ");
        while (spisok_iter != (*spiski_iter).end())
        {
            printf("%d ", *spisok_iter);
            spisok_iter++;
        }
        printf("}");
        printf("\n");
        spiski_iter++;
    }

    printf("2ые списки смежности:\n");

    spiski_iter = spiski_p2->begin();

    while (spiski_iter != spiski_p2->end())
    {
        spisok_iter = (*spiski_iter).begin();
        printf("{ ");
        while (spisok_iter != (*spiski_iter).end())
        {
            printf("%d ", *spisok_iter);
            spisok_iter++;
        }
        printf("}");
        printf("\n");
        spiski_iter++;
    }
    printf("\n1.Отождествление вершин\n");
    printf("\n");
    (*spiski1) = (*spiski);
    otoz_lst(s, s1, spiski1, true);
    printf("\n");
    printf("\n2.Стягивание ребер\n");
    (*spiski1) = (*spiski);
    styag_lst(s, s1, spiski1);
    printf("\n");
    printf("\n3.Расщепление вершин\n");
    (*spiski1) = (*spiski);
    ras_lst(s, spiski1);
    printf("\n");
    printf("\n4.Объединение вершин\n");
    printf("\n");
    (*spiski1) = (*spiski);
    (*spiski2) = (*spiski_p2);
    obe_lst(spiski1, spiski2);
    printf("\n");
    printf("\n5.Пересечение вершин\n");
    (*spiski1) = (*spiski);
    (*spiski2) = (*spiski_p2);
    pere_lst(spiski1, spiski2);
    printf("\n");
    printf("\n6.Кольцевая сумма вершин\n");
    (*spiski1) = (*spiski);
    (*spiski2) = (*spiski_p2);
    kolz_lst(spiski1, spiski2);
    printf("\n");
}