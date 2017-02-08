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

//low:�������߽�ֵ����ʼΪ0
//high:������ұ߽�ֵ����ʼΪlength-1
void QuikSort(int arr[], int low, int high,int len) {
	if (low >= high) {    //�ݹ��˳�������ֻ��һ��Ԫ��ʱ
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
							   //���зֻ�(partition),�ݹ�
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