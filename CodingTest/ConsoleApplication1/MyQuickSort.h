#pragma once

void QuickSort(int values[], int start, int end);

int PartitionQuickSort(int values[], int start, int end);

template <typename Type>
void IsQuickSort(Type values[], int start, int end);
template <typename Type>
int IsPartitionQuickSort(Type values[], int start, int end);


