
#include <iostream>
#include <conio.h>
using namespace std;

    int Fun(int X, int Y, int Z)
    {
        int result;
        if (X == 1) result = 1;
        else
            if (Y == Z) result = 2;
            else result = 3;
        return result;
    }

class Neuron
{
    float Wx = 0.0, Wy = 0.0, Wz = 0.0;
public:
    Neuron()
    {
        Wx = Wy = Wz = 1/3.0;
        //Wx = 0.7; Wy = 0.2; Wz = 0.1;
    }
    int Resut(int X, int Y, int Z)
    {
        //сумматор
        float S = (X * Wx) + (Y * Wy) + (Z * Wz);
        int result;
        //преобразователь
        if (S >= 0.7) result = 1;
        else
            if ((S < 0.1) || ((S >= 0.3)&&(S <= 0.4))) result = 2;
            else result = 3;
        return result;
    }
    void Print()
    {
        cout << " Wx = " << Wx << " Wy = " << Wy << " Wz = " << Wz;
    }
    bool Training(int Y, int y) // Y - результат программы; y - нужный результат
    {
        if (Y != y)
        {
            Wx = Wx + 0.2;
            Wy = Wy - 0.05;
            Wz = Wz - 0.15;
            cout << "\n Expected result: " << y << "\n Result: " << Y << "\n Updated weights: ";
            cout << " Wx = " << Wx << " Wy = " << Wy << " Wz = " << Wz;
            return false;
        }
        cout << "\n Expected result: " << y << "\n Result: " << Y;
        return true;
    }
};

int main()
{
    srand(time(NULL));
    int X, Y, Z, count = 0;

    Neuron A;
    cout << "\n First weights: ";
    A.Print();

    while (count <= 4)
    {
        count++;
        cout << "\n\n       ITERATION #" << count;
        X = rand() % 2 + 0;
        Y = rand() % 2 + 0;
        Z = rand() % 2 + 0;
        cout << endl << " X = " << X << " Y = " << Y << " Z = " << Z;
        A.Training(A.Resut(X, Y, Z), Fun(X, Y, Z));
    }
    cout << "\n      Training completed\n";

        cout << "\n\n Insert data: ";
        cin >> X, Y, Z;
        count = A.Resut(X, Y, Z);
        cout << "\n RESULT = " << count << endl;
}

