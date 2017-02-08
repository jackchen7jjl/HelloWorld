#include <iostream>

using namespace std;

void showArray(int arr[], int low, int high, int len)
{
	cout << "low: " << low << ", high: " << high << "-------";
	for (int i = 0; i < len; i++)
	{
		cout << arr[i];
	}
	cout << endl;
}


void Swap(int &a, int &b) 
{
	int temp = a;
	a = b;
	b = temp;
}

//low:数组的左边界值，开始为0
//high:数组的右边界值，开始为length-1
void QuikSort(int arr[], int low, int high,int len) {
	if (low >= high) {    //递归退出条件：只有一个元素时
		return;
	}

	int pivot = arr[low];
	int i = low;
	for (int j = low + 1; j <= high; j++) {
		if (arr[j] <= pivot) {        //a[j] is smaller than pivot
			i++;    //a[i] is bigger than pivot
			if (i != j) {
				Swap(arr[i], arr[j]);
				showArray(arr, low, high, len);
			}
		}
	}
	Swap(arr[low], arr[i]);    //Swap pivot to middle position

	showArray(arr, low, high,len);
							   //进行分化(partition),递归
	QuikSort(arr, low, i - 1, len);        //a[i] is the pivot now
	QuikSort(arr, i + 1, high, len);

}

void QuikSort(int arr[], int length) {

	QuikSort(arr, 0, length - 1, length);

}

int main()
{
	int arr[] = {8,4,6,7,2,1,5};
	QuikSort(arr,7);
	cin.get();
	cin.get();
	return 0;
}