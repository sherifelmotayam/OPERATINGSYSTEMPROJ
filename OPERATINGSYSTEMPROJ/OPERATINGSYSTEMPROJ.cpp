#include <iostream>
using namespace std;
void fifo(int Frame[], int pages[], int n, int numberofframes, int ptr)
{
	if (ptr > numberofframes - 1)
	{
		ptr = ptr % numberofframes;
	}
	Frame[ptr] = pages[n];

	cout << "page [" << pages[n] << "] :";
	for (int i = 0; i < numberofframes; i++)
	{
		if (Frame[i] == -1)
		{
			cout << " -";
		}
		else
		{
			cout << Frame[i] << " ";
		}
	}
	cout << endl;
}
void LRU(int frames[], int pages[], int n, int numberofframes, int numberofpages)
{
	if (n < numberofframes)
	{
		frames[n] = pages[n];
	
	}
	else
	{

		int* check2 = new int[numberofframes - 1];
		int y = 0;
		bool* chech1 = new bool[numberofframes];

		for (int q = 0; q < numberofframes; q++)
		{
			chech1[q] = false;
	
		}
		int k = n - 1;
		for (int i = 0; i < numberofframes-1; i++)
		{
			fu:
			check2[i] = pages[k];
			k--;
	
			for (int m = 0; m < i; m++)
			{
				if (check2[i] == check2[m])
				{
					k--;
					goto fu;
				}
			}

		
		}


		for (int x = 0; x < numberofframes - 1; x++)
		{
			for (int z = 0; z < numberofframes; z++)
			{
				if (check2[x] == frames[z])
				{
					chech1[z] = true;
					break;
				}
			}
		}
		for (int w = 0; w < numberofframes; w++)
		{
			if (chech1[w] == false)
			{
				frames[w] = pages[n];
			}

		}
	}
		cout << "page [" << pages[n] << "] :";
		for (int v = 0; v < numberofframes; v++)
		{
			if (frames[v] == -1)
			{
				cout << " -";
			}
			else
			{
				cout << frames[v] << " ";
			}
		}
		cout << endl;
}
bool  checkstatus(int frames[],int numberofframes,int pages[],int n)
{
	bool checkstatus = false;
	//search if process is here
	for (int x = 0; x < numberofframes; x++)
	{
		if (frames[x] == pages[n])
		{

			checkstatus = true;
			break;
		}
	}
	return checkstatus;
}

int main()
{
	cout << "enter number of pages " << endl;
	int numberofpages;
	cin >> numberofpages;
	cout << "enter number of frames" << endl;
	int numberofframes;
	cin >> numberofframes;
	///////////////////////////////////////////////////////
	int* pages = new int[numberofpages];
	int* frames = new int[numberofframes];
	///////////////////////////////////////////////////////
	int n = 0;
	int hit = 0;
	int fault = 0;
	///////////////////////////////////////////////////////
	for (int y = 0; y < numberofframes; y++)
	{
		frames[y] = -1;
	}

	cout << "enter pages " << endl;
	for (int i = 0; i < numberofpages; i++)
	{
		cin >> pages[i];
	}
	///////////////////////////////////////////////////////
	while (n < numberofpages)
	{
	
		if (checkstatus(frames,numberofframes,pages, n) == true)
		{
			cout << "page [" << pages[n] << "] : is hit" << endl;
			hit++;
		}
		else
		{


			LRU(frames, pages, n, numberofframes, numberofpages);

			fault++;

		}
		n++;
	}


	cout << "Total page fault= " << fault << endl;
	cout << "Total page hit= " << hit << endl;

	return 0;
}


