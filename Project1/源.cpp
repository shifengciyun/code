#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void Busort(int arr[], int n) {//√∞≈›≈≈–Ú
	int flag = 0;
	for (int i = 0;i < n - 1;i++) {
		for (int j = 0;j < n - i - 1;j++) {
			if (arr[j] > arr[j + 1]) {
				flag = 1;
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
		if (!flag)break;
	}

}


void Insertsort(int arr[], int n) {//øÏÀŸ≤Â»Î≈≈–Ú
	int temp, j, i;
	for (i = 1;i <= n;i++) {
		if (arr[i] < arr[i - 1]) {
			temp = arr[i];
			arr[i] = arr[i - 1];
			for (j = i - 2;temp < arr[j];j--)
				arr[j + 1] = arr[j];//÷∏ˆ∫Û“∆
			arr[j + 1] = temp;
		}
	}
}                       

void BInsertsort(int arr[], int n) {//’€∞Î≤Â»Î≈≈–Ú
	int i, j, temp, low, high, middle;
	for (i = 1;i <= n;i++) {
		temp = arr[i];
		low = 0;
		high = i - 1;
		while (low <= high) {
			middle = (low + high) / 2;
			if (temp < arr[middle]) {
				high = middle - 1;
			}
			else {
				low = middle + 1;
			}
		}
		for (j = i - 1;j >= high + 1;j--) {
			arr[j + 1] = arr[j];
		}
		arr[high + 1] = temp;
	}
}

void Shellsort(int arr[], int n,int dk) {//œ£∂˚≈≈–Ú
	int i,j;
	for (i = dk;i < n;i++) {
		if (arr[i] < arr[i - dk]) {
			int temp = arr[i];
			for ( j = i - dk;j > 0 && temp < arr[j];j -= dk) {
				arr[j + dk] = arr[j];
			}
			arr[j + dk] = temp;
		}
	}
}

int Partition(int arr[], int low,int high) {

	int temp = arr[low];
	int key = temp;
	while (low < high) {
		while (low<high && arr[high]>=key)--high;
		arr[low] = arr[high];
		while (low < high && arr[low] <= key)++low;
		arr[high] = arr[low];
	}
	arr[low] = key;
	return low;
}

void Qsort(int arr[],int low,int high,int n) {
	int low = 0, high = n,key;
	if (low < high) {
		key = Partition(arr, low, high);
		Qsort(arr, low, key - 1,n);
		Qsort(arr, key + 1, high,n);
	}
}

void SelectSort(int arr[],int n) {
	int i, j, k;
	for (i = 0;i < n;++i) {
		k = i;
		for (j = i + 1;j < n;++j) {
			if (arr[j] < arr[k])k = j;
		}
		if (k != i) {
			int t = arr[i];
			arr[i] = arr[k];
			arr[k] = t;

		}
	}
}