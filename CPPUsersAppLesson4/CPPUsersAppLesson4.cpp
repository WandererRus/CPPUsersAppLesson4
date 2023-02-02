// CPPUsersAppLesson4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

char** AddStringInTheEnd(char** massive, const char* string, int col, int rows)
{
    char** newmassive = new char* [rows + 1];
    for (int i = 0; i <= rows; i++)
    {
        newmassive[i] = new char[col];
    }
    for (int i = 0; i <= rows; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (i != rows)
            { 
                newmassive[i][j] = massive[i][j];            
            }
            else
            {
                newmassive[i][j] = string[j];
            }
        }
    }
    return newmassive;
}
char** AddStringInTheStart(char** massive, const char* string, int col, int rows)
{
    char** newmassive = new char* [rows + 1];
    for (int i = 0; i <= rows; i++)
    {
        newmassive[i] = new char[col];
    }
    for (int i = 0; i <= rows; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (i != 0)
            {
                newmassive[i][j] = massive[i-1][j];
            }
            else
            {
                newmassive[i][j] = string[j];
            }
        }
    }
    return newmassive;
}
char** InsertStringAt(char** massive, const char* string, int col, int rows, int index)
{
    char** newmassive = new char* [rows + 1];
    for (int i = 0; i <= rows; i++)
    {
        newmassive[i] = new char[col];
    }
    for (int i = 0; i <= rows; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (i < index)
            {
                newmassive[i][j] = massive[i][j];
            }
            else if (i == index)
            {
                newmassive[i][j] = string[j];
            }
            else
            {
                newmassive[i][j] = massive[i-1][j];
            }
        }
    }
    return newmassive;
}
char** RemoveStringAt(char** massive, int col, int rows, int index)
{
    char** newmassive = new char* [rows - 1];
    for (int i = 0; i < rows-1; i++)
    {
        newmassive[i] = new char[col];
    }
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (i < index)
            {
                newmassive[i][j] = massive[i][j];
            }
            if (i > index)
            {
                newmassive[i-1][j] = massive[i][j];
            }
        }
    }
    return newmassive;
}
void PrintMassive(char** massive, int rows)
{
    int col = 0;
    for (int i = 0; i < rows; i++)
    {
        col = strlen(massive[i]);
        for (int j = 0; j < col; j++)
        {
            std::cout << massive[i][j];
        }
    }
    std::cout << "\n";
}

int main()
{
    char* TwoDMassive[15];
    for (int i = 0; i < 15; i++) {
        TwoDMassive[i] = new char[15] {"string string\n"};
    }

    char** pointerMassive = TwoDMassive;
    PrintMassive(pointerMassive, 15);
    pointerMassive = AddStringInTheEnd(pointerMassive, "newstring\n",15,15);
    PrintMassive(pointerMassive,16);
    pointerMassive = TwoDMassive;
    pointerMassive = AddStringInTheStart(pointerMassive, "newstring\n", 15, 15);
    PrintMassive(pointerMassive, 16);
    pointerMassive = TwoDMassive;
    pointerMassive = InsertStringAt(pointerMassive, "newstring\n", 15, 15,8);
    PrintMassive(pointerMassive, 16);
    pointerMassive = TwoDMassive;
    pointerMassive = RemoveStringAt(pointerMassive, 15, 15, 8);
    PrintMassive(pointerMassive, 14);

    

    std::cout << " " << "\n";
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
