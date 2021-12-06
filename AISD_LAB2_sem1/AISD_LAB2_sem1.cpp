#include <iostream>
#include <windows.h>
#include <ctime>

using namespace std;
#define RANGE 255

bool isSortChar(char* array, int size)
{
    for (int i = 0; i < size - 1; i++)
        if (array[i + 1] < array[i]) return false;
    return true;
}

bool isSort(int* array, int size)
{
    for (int i = 0; i < size - 1; i++)
        if (array[i + 1] < array[i]) return false;
    return true;
}

int Search_Binary(int array[], int left, int right, int variable)
{
	int midd = 0;
	while (1)
	{
		midd = (left + right) / 2;

		if (variable < array[midd])      
			right = midd - 1;      
		else if (variable > array[midd]) 
			left = midd + 1;    
		else                     
			return midd;        

		if (left > right)         
			return -1;
	}
}

void quickSort(int array[], int length) {  
    int i = 0;
    int j = length - 1;
    int mid = array[length / 2];

    do {
        while (array[i] < mid) 
        {
            i++;
        }
       
        while (array[j] > mid) 
        {
            j--;
        }

        if (i <= j) 
        {
            int tmp = array[i];
            array[i] = array[j];
            array[j] = tmp;

            i++;
            j--;
        }
    } while (i <= j);
  
    if (j > 0) {
        quickSort(array, j + 1);
    }
    if (i < length) {
        quickSort(&array[i], length - i);
    }
}

void bubbleSort(int array[], int length)
{
    int temp=0;
  
    for (int i = 0; i < length - 1; i++)
    {
        for (int j = 0; j < length - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

int correct(int* array, int length) {
    while (length-- > 0)
        if (array[length - 1] > array[length])
            return 0;
    return 1;
}

void shuffle(int* array, int length) {
    for (int i = 0; i < length; ++i)
        std::swap(array[i], array[(rand() % length)]);
}

void bogosort(int* array, int length) {
    while (!correct(array, length))
        shuffle(array, length);
}

int str_len(char* str)
{
    int i(0);

    while (str[i] == '\0')
        i++;

    return(i);
}

void countSort(char array[], int length)
{
    char max = 0;
    for (int i = 0; i < length; i++)
        if (array[i] > max) max = array[i];
    char* arr2 = new char[max + 1];
    for (int i = 0; i < max + 1; i++)
        arr2[i] = 0;
    for (int i = 0; i < length; ++i) {
        ++arr2[array[i]];
    }
    int b = 0;
    for (int i = 0; i < max + 1; ++i) {
        for (int j = 0; j < arr2[i]; ++j) {
            array[b++] = i;
        }
    }

}

int main()
{
	const int length = 10;
	int array[length];
    int variablelength;
	int variable = 0;
	int index = 0;
    int enter;
    boolean flag = 1;

    while (flag == 1) 
    {
        cout << "1)Search_Binary.\n";
        cout << "2)quickSort.\n";
        cout << "3)bubbleSort.\n";
        cout << "4)bogosort.\n";
        cout << "5)countSort.\n";
        cout << "6)Exit.\n";
        cin >> enter;
        if (enter == 1)
        {   
            cout << "Enter int array: \n";
            for (int i = 0; i < length; i++)
            {
                cin >> array[i];
            }

            cout << "\n";
            cout << "Enter number:";
            cin >> variable;
            cout << "\n";
            quickSort(array,length);
            for (int i = 0; i < length; i++)
            {
                cout << array[i] << " ";
            }
            cout << "\n";
            index = Search_Binary(array, 0, length, variable);

            if (index >= 0)
                cout << "The specified number is in the cell with the index: " << index << "\n";
            else
                cout << "There is no such number in the array!\n";
        }
        if(enter==2)
        {
            variablelength = 100;
            cout << "int array: \n";
            for (int i = 0; i < variablelength; i++)
            {
                cout << array[i] << " ";
               array[i]= rand() % 10;;
            }
            cout << "\n";
            cout << "\n";
            time_t end;
            quickSort(array, length);
            end = clock();
            cout << "Time: " << end / 1000.0 <<"\n";

            for (int i = 0; i < variablelength; i++)
            {
                cout << array[i] <<" ";
            }
            cout << "\n";
        }
        if(enter==3)
        {
            variablelength = 100;
            cout << "int array: \n";
            for (int i = 0; i < variablelength; i++)
            {
                array[i] = rand() % 10;;
                cout << array[i] << " ";
            }
            cout << "\n";
            cout << "\n";
            time_t end;
            bubbleSort(array, length);
            end = clock();
            cout << "Time: " << end / 1000.0 << "\n";

            for (int i = 0; i < variablelength; i++)
            {
                cout << array[i] << " ";
            }
            cout << "\n";
        }
        if(enter==4)
        {
            cout << "Enter int array: \n";
            for (int i = 0; i < length; i++)
            {
                cin >> array[i];
            }
            bogosort(array, length);
            for (int i = 0; i < length; i++)
            {
                cout << array[i] << " ";
            }
            cout << "\n";
        }
        if (enter == 5) 
        {
           cout << "char array: \n";
           char array[length];

           for (int i = 0; i < length; i++) {
               array[i] = "0123456789ABCD"[rand() % 256];
               cout << array[i] << " ";
           }
           cout << "\n";
           cout << "\n";

           countSort(array, length);
           for (int i = 0; i < length; i++) {
           cout << array[i] <<" ";
           }
           cout << "\n";
        }
        if (enter == 6) {
            break;
        }
    }
	return 0;
}