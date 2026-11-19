#include <stdio.h>

int main()
{
    int numCuenta[2000];
    float calif[2000];
    int numCalif;
    int i;
    int j;

    scanf_s("%d", &numCalif);

    for (i = 0; i < numCalif; i++)
    {
        scanf_s("%d %f", &numCuenta[i], &calif[i]);
    }

    i = 0;
    while (i < numCalif - 1)
    {
        j = 0;
        while (j < numCalif - 1 - i)
        {
            if (numCuenta[j] > numCuenta[j + 1])
            {
                int temp_cuenta = numCuenta[j];
                numCuenta[j] = numCuenta[j + 1];
                numCuenta[j + 1] = temp_cuenta;

                float temp_note = calif[j];
                calif[j] = calif[j + 1];
                calif[j + 1] = temp_note;
            }

            j++;
        }

        i++;
    }

    int totalAlumnos = 0;

    for (i = 0; i < numCalif; i++)
    {
        if (i == 0 || numCuenta[i] != numCuenta[i - 1])
        {
            totalAlumnos++;
        }
    }

    printf("%d\n", totalAlumnos);

    i = 0;
    while (i < numCalif)
    {
        int cuentaF = numCuenta[i];
        float maxCalif = calif[i];
        j = i + 1;

        while (j < numCalif && numCuenta[j] == cuentaF)
        {
            if (calif[j] > maxCalif)
            {
                maxCalif = calif[j];
            }

            j++;
        }

        printf("%d %f\n", cuentaF, maxCalif);
        i = j;
    }

    return 0;
}