#include <iostream>
using namespace std;
bool  checkstatus(int frames[], int numberofframes, int pages[], int n)
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
void fifo(int Frame[], int pages[], int n, int numberofframes, int ptr)
{
	//fifo(f1, p1, n1, numberofframes, numberofpages);
	
	
	if (ptr > numberofframes-1)
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
void Optimal(int frames[], int pages[], int n, int numberofframes, int numberofpages)
{
	int* count_fun = new int[numberofframes];
	for (int e = 0; e < numberofframes; e++)
	{
		count_fun[e] = numberofpages + e;
	}
	///////////////////////////////////////////////////////////////
	if (n < numberofframes)
	{
		frames[n] = pages[n];
	}
	else
	{
		for (int i = 0; i < numberofframes; i++)
		{
			for (int x = n; x < numberofpages; x++)
			{
				if (frames[i] == pages[x])
				{
					count_fun[i] = x;
					break;
				}
			}

		}
	
		int biggest = 0;
		int temp = count_fun[0];
		for (int i = 1; i < numberofframes; i++)
		{
			if (temp < count_fun[i]) {
				biggest = i;
			}
		}
		frames[biggest] = pages[n];
	}
	/////////////////////////////////////////////////////
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
	

int main()
{
	cout << "Welcome to your future " << endl;
	int i=-2;
	while (i !=-1)
	{
		cout << "****1 Step**** " << endl;
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
		entry:

		cout << "Choose your Algorithm " << endl;
		cout << "1) FIFO Algorithm " << endl;
		cout << "2) Optimal Algorithm " << endl;
		cout << "3) LRU Algorithm " << endl;
	 
		cout << "To exit press -1" << endl;
		//////////////////////////////////////////////////////

		int x;
		cin >> x;
		if (x == 1)
		{
			int* p1 = new int[numberofpages];
			int* f1 = new int[numberofframes];
			int n1 = 0;
			int hit1 = 0;
			int fault1 = 0;
			int ptr = 0;
			for (int w = 0; w < numberofpages; w++)
			{
			
				p1[w] = pages[w]; 
			}
			for (int e = 0; e < numberofframes; e++)
			{
				f1[e] = -1;
			}

			cout << "************************" << endl;
			cout << "Step 2" << endl;
			cout << "************************" << endl;
			cout << "*********FIFo************" << endl;
			cout << endl;
			while (n1 < numberofpages)
			{

				if (checkstatus(f1, numberofframes, p1, n1) == true)
				{
					cout << "page [" << pages[n1] << "] : is hit" << endl;
					hit1++;
				}
				else
				{

					fifo(f1, p1, n1, numberofframes, ptr);

					fault1++;
					ptr++;
				}
				n1++;
			}

			cout << endl;
			cout << "Total page fault= " << fault1 << endl;
			cout << "Total page hit= " << hit1 << endl;
			goto entry;
		
		}
		else if (x == 2)
		{
			cout << "************************" << endl;
			cout << "Step 2" << endl;
			cout << "************************" << endl;
			cout << "*********Optimal*********" << endl;
			cout << endl;
			int* p2 = new int[numberofpages];
			int* f2 = new int[numberofframes];
			int n2 = 0;
			int hit2 = 0;
			int fault2 = 0;
			

			for (int r = 0; r < numberofpages; r++)
			{

				p2[r] = pages[r];
			}
			for (int t = 0; t < numberofframes; t++)
			{
				f2[t] = -1;
			}

			while (n2 < numberofpages)
			{

				if (checkstatus(f2, numberofframes, p2, n2) == true)
				{
					cout << "page [" << pages[n2] << "] : is hit" << endl;
					hit2++;
				}
				else
				{

					Optimal(f2, p2, n2, numberofframes, numberofpages);

					fault2++;

				}
				n2++;
			}

			cout << endl;
			cout << "Total page fault= " << fault2 << endl;
			cout << "Total page hit= " << hit2 << endl;
			cout << endl;
			goto entry;
		
		}
		else if (x == 3)
		{
			cout << "************************" << endl;
			cout << "Step 2" << endl;
			cout << "************************" << endl;
			cout << "******* **LRU**********" << endl;
			cout << endl;
			int* p3 = new int[numberofpages];
			int* f3 = new int[numberofframes];
			int n3 = 0;
			int hit3 = 0;
			int fault3 = 0;


			for (int p = 0; p < numberofpages; p++)
			{

				p3[p] = pages[p];
			}
			for (int o = 0; o < numberofframes; o++)
			{
				f3[o] = -1;
			}
			
			while (n3 < numberofpages)
			{

				if (checkstatus(f3, numberofframes, p3, n3) == true)
				{
					cout << "page [" << pages[n3] << "] : is hit" << endl;
					hit3++;
				}
				else
				{

					LRU(f3, p3, n3, numberofframes, numberofpages);

					fault3++;

				}
				n3++;
			}

			cout << endl;
			cout << "Total page fault= " << fault3 << endl;
			cout << "Total page hit= " << hit3 << endl;
			goto entry;
		}
		else if (x==-1)
		{
		i = -1;

        }	
		else
		{
			cout << "Wrong entry try again " << endl;
			cin >> i;
		}

		

	}
	

	return 0;
}


