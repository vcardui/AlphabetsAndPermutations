/*
 * +----------------------------------------------------------------------------+
 * | CARDUI WORKS v1.0.0
 * +----------------------------------------------------------------------------+
 * | Copyright (c) 2024 - 2025, CARDUI.COM (www.cardui.com)
 * | Vanessa Reteguín <vanessa@reteguin.com>
 * | Released under the MIT license
 * | www.cardui.com/carduiframework/license/license.txt
 * +----------------------------------------------------------------------------+
 * | Author.......: Vanessa Reteguín <vanessa@reteguin.com>
 * | First release: August 19th, 2025
 * | Last update..: August 25th, 2025
 * | WhatIs.......: Alphabets-and-permutations - Main
 * +----------------------------------------------------------------------------+
 */

/*
20 de agosto de 2024
Vanessa Reteguín - 375533

Actividad 2 - Alfabetos: Ejercicio 1 y 2

Universidad Aútonoma de Aguascalientes
Ingeniería en Computación Inteligente (ICI)
Semestre V

Grupo 5 - A
Autómatas I
Ángel Eduardo Villegas Ortíz

Instrucciones:

Ejercicio 1:
1. Busque un libro en formato de texto plano
    -Puede usar uno de su preferencia, procure que el libro tenga más de
    5000 palabras.
    -Utilice el enlace para encontrar archivos de libros clásicos:
    https://venmarktec.jimdofree.com/
2. Obtenga el Alfabeto ∑ del texto plano seleccionado, almacénelo en
    una variable V y despliegue todos los elementos del alfabeto en
    consola.
3. Extraiga los alfabetos para Letras, Números, Símbolos-Operadores.
    Despliéguelos en consola.

Ejercicio 2:
    1. Dado alguno de los siguientes alfabetos genere las potencias
    solicitadas en un rango de 1 a 3.
    𝑉 = {𝟎, 𝟏}
    ∑ = {𝒂, 𝒃}
    ∑ = {𝟏, 𝟐, 𝟑}
    𝑉 = {𝒙𝒙, 𝒙𝒚}
    -La entrada del alfabeto debe ser proporcionada por el usuario.
    -Toda cadena resultado debe ser mostrada en consola para cada
    potencia en la notación de Cadenas y Alfabetos (Puede utilizar V1, V2
    y V3 para indicar la potencia del alfabeto

Opcional:
    -Modifique el algoritmo que dado un alfabeto y una potencia pueda
    determinar todas las cadenas del alfabeto

[*] Ejercico opcional completado con éxito :D
*/

/* ------------ Resources / Documentation involved ------------- */
// Read a text file and Loop through each l: https://cplusplus.com/forum/beginner/24492/
// How to Check if a Vector Contains a Given Element in C++?: https://www.geeksforgeeks.org/cpp/check-if-vector-contains-given-element-in-cpp/
// Print a list: https://cplusplus.com/forum/general/163516/
// Decimal to any base conversion code in C++: https://stackoverflow.com/questions/47407953/decimal-to-any-base-convertion-code-in-c

// How to tell file encoding on MacOS:
// (input)  file -I DaVinciCode.txt
// (output) DaVinciCode.txt: text/plain; charset=utf-8

/* ------------------------- Libraries ------------------------- */
#include <cmath>    /* pow */
#include <fstream>  /* ifstream */
#include <iostream> /* cin/cout */
#include <list>
#include <vector>
#include <string>

using namespace std;

/* ------------------------- Functions ------------------------- */
void displayMenu()
{
    cout << endl
         << "\n.-----------------------------------------."
            "\n||              -{ MENU }-               ||"
            "\n.-----------------------------------------."
            "\n| [1] Ejercicio 1: Alfabeto ∑ de .txt     |"
            "\n| [2] Ejercicio 2: Potencias de alfabetos |"
            "\n|                              [3] Salir  |"
            "\n.-----------------------------------------.\n";
}

void endTitle()
{
    cout << "\n  ^~^  , * ------------- *"
            "\n ('Y') ) |  Hasta luego! | "
            "\n /   \\/  * ------------- *"
            "\n(\\|||/)        FIN      \n";
}

void displayAlphabetsMenu()
{
    cout << endl
         << "Seleccione un alfabeto";
    cout
        << "\n.---------------------."
           "\n||  -{ Alfabetos }-  ||"
           "\n.---------------------."
           "\n| [1] V1 = {0, 1}    |"
           "\n| [2] V2 = {xx, xy}  |"
           "\n| [3] ∑1 = {a, b}    |"
           "\n| [4] ∑2 = {1, 2, 3} |"
           "\n.---------------------.\n";
}

void textAlphabet()
{
    ifstream ifs("DaVinciCode.txt");
    string line;

    vector<char> alphabet;

    char character;
    int occurrences;

    while (std::getline(ifs, line))
    {
        // cout << line.c_str() << endl;

        for (int i = 0; i < line.length(); ++i)
        {
            character = line[i];
            // cout << int(character) << endl;

            occurrences = count(alphabet.begin(), alphabet.end(), character);
            // cout << occurrences << endl;

            if (occurrences == 0 && (int(character) >= 0))
            {
                alphabet.push_back(character);
            }
        }
    }

    cout << "Alfabeto ∑ : ";
    for (char i : alphabet)
    {
        cout << i << " ";
    }
}

string decimalToNBase(int decimalNum, int base, vector<string> digits)
{
    string result = "";
    list<string> reverseResultList;

    int i;

    // vector<string> digits = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"};

    if (decimalNum <= 1)
    {
        reverseResultList.push_front(digits[0]);
    }

    if (decimalNum == 0)
    {
        reverseResultList.push_front(digits[0]);
    }

    while (decimalNum > 0)
    {
        int remainder = decimalNum % base;
        // result += digits[remainder];
        reverseResultList.push_front(digits[remainder]);
        decimalNum /= base;
    }

    list<string>::iterator iter;

    if ((iter = reverseResultList.begin()) != reverseResultList.end())
    {
        for (i = 0; i < reverseResultList.size(); ++i)
        {
            result += *iter;
            ++iter;
        }
    }

    return result;
}

void alphabetPermutations()
{
    /* - Auxiliaries- */
    int i, j;
    string currentPermutation;

    /* - User settings - */
    int userChoice;
    bool run = true;
    int power;
    int alphabetSize = 0;

    /* - Alphabets- */
    vector<string> chosenAlphabet = {};
    vector<string> v1 = {"0", "1"};
    vector<string> v2 = {"xx", "xy"};
    vector<string> s1 = {"a", "b"};
    vector<string> s2 = {"1", "2", "3"};

    while (run == true)
    {
        displayAlphabetsMenu();
        while (!((cin >> userChoice) && (userChoice >= 1 && userChoice <= 4)))
        {
            cin.clear();
            cin.ignore();
        }
        run = false;
    }

    cout << endl
         << "Ingrese potencia a emplear (1 - 3): ";
    while (!((cin >> power) && (power >= 1 && power <= 3)))
    {
        cin.clear();
        cin.ignore();
    }

    switch (userChoice)
    {
    case 1:
        chosenAlphabet = v1;
        cout << endl
             << "v1" << endl;
        break;

    case 2:
        chosenAlphabet = v2;
        cout << endl
             << "v2" << endl;
        break;

    case 3:
        chosenAlphabet = s1;
        cout << endl
             << "s1" << endl;
        break;

    case 4:
        chosenAlphabet = s2;
        cout << endl
             << "s2" << endl;
        break;
    }

    cout << "∑ ^ " << power << " = {";

    alphabetSize = chosenAlphabet.size();

    for (i = 0; i <= (pow(alphabetSize, power) - 1); i++)
    {
        currentPermutation = "";
        currentPermutation = decimalToNBase(i, power, chosenAlphabet);

        // cout << i;

        if (i != 0)
        {
            cout << ", ";
        }

        cout << currentPermutation;
    }

    cout << "}";
}

int main()
{
    /* ------------------------- Variables ------------------------- */
    /* - Menu - */
    int userChoice;
    bool run = true;

    /* --------------------------- Code ---------------------------- */
    while (run == true)
    {
        displayMenu();
        while (!((cin >> userChoice) && (userChoice >= 1 && userChoice <= 3)))
        {
            cin.clear();
            cin.ignore();
        }

        switch (userChoice)
        {
        case 1:
            textAlphabet();
            break;

        case 2:
            alphabetPermutations();
            break;

        case 3:
            endTitle();
            run = false;
            break;
        }
    }

    return 0;
}
