#include<iostream>
using namespace std;

template<typename k,typename v>
class MaxHeap
{
	struct heapitem
	{
		k key;
		v val;
	};
	int capacity;
	int size;

public:
	int* arr;
	MaxHeap()
	{
		arr = nullptr;
	}

	MaxHeap(int _capacity)
	{
		capacity = _capacity;
		size = 0;
		arr = new int[_capacity];
	}

	bool isempty()
	{
		if(arr == NULL)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void heapify(int *array, k ke)
	{
		while(ke >1)
		{
			if(array[ke/2] < array[ke])
			{
				swap(array[ke/2], array[ke]);
				ke = ke/2;
			}
			else 
			{
				ke = ke/2;
			}
		}
	}

	void insert(k ke, v val)
	{
		if(ke <= capacity)
		{
			arr[ke] = val;
			size++;
		}
		else
		{
			capacity = capacity*2;
			int*temp = arr;
			arr = new int [capacity];
			arr = temp;
			insert(ke, val);
		}
		heapify(arr, ke);
	}

	int getmax()
	{
		if(!isempty())
		{
			return arr[1];
		}
		else
		{
			cout << "The heap is empty" << endl;
			return 0;
		}
	}

	bool checkMaxHeap(int *arr, int curr)
	{
		if(curr > 1)
		{
		   if(arr[curr] < arr[curr/2])
		   {
			  return checkMaxHeap(arr, curr/2);
		   } 
		   else
		   { 
			   return false;
		   }
		   return true;
		}
	}

	bool checkMaxHeap()
	{
		return checkMaxHeap(arr, size);
	}

	void print()
	{
		for(int i=1; i<=size; i++)
		{
			cout << arr [i] << " ";
		}
	}

	int getcur()
	{
		return size;
	}

	void MergeHeaps(MaxHeap &a, MaxHeap &b)
	{
		int *arr1, *arr2;
		arr1 = a.arr;
		arr2=b.arr;
		    for(int i=1,j=1; i<=capacity-1; i++)
			{
			    if(i <= a.getcur())
				{
					insert(i, arr1[i]);
			    }
			    else
				{
					insert(i, arr2[j]);
					j++;
			    }
		    }
	}

	int getKthMax(int num)
	{
		int *sortarr;
		sortarr = arr;
		for(int i=1; i<=size; i++)
		{
			for(int j=1; j<=size-i; j++)
			{
				if(sortarr[j] > sortarr[j+1])
					swap(sortarr[j], sortarr[j+1]);
			}
		}
		num = size - (num-1);
		return sortarr[num];
	}

	int Max_possibleSwaps(int kth)
	{
		if(capacity != kth)
		{
			return Max_possibleSwaps((kth + 1)/2);
		}
		else
		{
			cout << "There is no need for swap" << endl;
		}
	}

	~MaxHeap()
	{
		delete []arr;
	}
};

int main()
{
	int c;
	int c1;
	int v;

	cout << "Enter the capacity of the heap 1 : ";
	cin >> c;
	cout << "Enter the capacity of the heap 2 : ";
	cin >> c1;
	MaxHeap<int, int> h(c);
	MaxHeap<int, int> h1(c1);

	cout << "Enter the values in heap 1 : " << endl; 
	for(int i=1; i<=c-1; i++)
	{
		cin >> v;
		h.insert(i, v);
	}

	cout << "Enter values in heap 2 : " << endl;
	for(int i=1; i<=c1-1; i++)
	{
		cin >> v;
		h1.insert(i, v);
	}

	cout << "Values of heap 1 are : ";
	h.print();
	cout << endl;
	cout << "Values of heap 2 are : ";
	h1.print();
	cout << endl;
	int kth = 4;
	MaxHeap<int, int> h2((h1.getcur()+h.getcur())+1);
	cout << "Max value in heap 1 is : ";
	v = h.getmax();
	cout << v << endl;
	cout << "Max value in heap 2 is : ";
	v = h1.getmax();
	cout << v << endl;
	cout << "Merged heap is : ";
	h2.MergeHeaps(h, h1);
	h2.print();
	cout << endl;

	v = h.checkMaxHeap();
	if(v >= 1)
	{
		cout << "Heap 1 is a Max heap" << endl;
	}
	else
	{
		cout << "Heap 1 is not a Max heap" << endl;
	}
	v = h1.checkMaxHeap();
	if(v >= 1)
	{
		cout << "Heap 2 is a Max heap" << endl;
	}
	else
	{
		cout << "Heap 2 is not a Max heap" << endl;
	}
	v = h2.checkMaxHeap();
	if(v >= 1)
	{
		cout << "Heap 3 is a Max heap" << endl;
	}
	else
	{
		cout << "Heap 3 is not a Max heap" << endl;
	}

	cout << "kth largest value is : ";
	v = h.getKthMax(2);
	cout << v << endl;
	cout << "Max possible swap to heapify  " << kth << " node is : " << v+1;
	cout << endl;

	system("pause");
	return 0;
}