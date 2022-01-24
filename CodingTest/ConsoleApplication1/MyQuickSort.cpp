#include "MyQuickSort.h"
#include <iostream>

void QuickSort(int values[], int start, int end)
{
    int pivot = 0;
    if (start < end)
    {
        pivot = PartitionQuickSort(values, start, end);
        QuickSort(values, start, pivot - 1);
        QuickSort(values, pivot + 1, end);
    }
}

int PartitionQuickSort(int values[], int start, int end)
{
    int pivot = end;
    int left = start;
    int right = end - 1;
    int temp = 0;

    while (left < right)
    {
        while (values[left] < values[pivot] && left < right)
        {
            left++;
        }
        while (values[right] > values[pivot] && left < right)
        {
            right--;
        }

        if (left < right)
        {
            //std::cout << "values: " << values[left] << " " << values[right];
            temp = values[left];
            values[left] = values[right];
            values[right] = temp;
        }
    }

    temp = values[pivot];
    values[pivot] = values[right];
    values[right] = temp;

    return right;
}

template<typename Type>
void IsQuickSort(Type values[], int start, int end)
{
    int pivot = 0;
    if (start < end)
    {
        pivot = IsPartitionQuickSort(values, start, end);
        IsQuickSort(values, start, pivot - 1);
        IsQuickSort(values, pivot + 1, end);
    }
}

template<typename Type>
int IsPartitionQuickSort(Type values[], int start, int end)
{
    int pivot = end;
    int left = start;
    int right = end - 1;

    while (left < right)
    {
        while(values[left] < values[pivot] && left < right) left++;
        while(values[right] > values[pivot] && left < right) right--;

        if (left < right)
        {
            Type temp = values[left];
            values[left] = values[right];
            values[right] = temp;
        }
    }
    Type temp = values[pivot];
    values[pivot] = values[right];
    values[right] = temp;


    return right;
}

/*int main()
{
    int values[8] = { 80, 75, 10, 60, 15, 49, 12, 25 };
    IsQuickSort(values, 0, 7);

    std::cout << "values: ";
    for (int i = 0; i < 8; i++)
    {
        std::cout << values[i] << " ";
    }

    return 0;
}*/