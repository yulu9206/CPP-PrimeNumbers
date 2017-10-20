#include <iostream>
#include <iomanip>
#include <array>
using namespace std;

const int MAX_NUMBER = 1000;  // maximum possible prime number
const int ROW_SIZE   = 20;    // row size for printing

/***** Complete this program. *****/

void compute_primes(bool arr[], int size)
{
	for (int p = 2; p*p < size-1; p++)
	{
		if (arr[p])
		{
			for (int i = p*2; i <= size - 1; i += p)
			{
				arr[i] = false;
			}
		}
	}
}

void print_primes(bool arr[], int size)
{
	int count = 0;
	for (int i = 2; i < size; i++)
	{
		if (arr[i])
		{
			count++;
			if (count == ROW_SIZE )
			{
				cout << right << setw(4) << i << endl;
				count = 0;
			}
			else cout << right << setw(4) << i;
		}
	}
	cout << endl << endl;
	cout << "Done!" << endl;
}

/**
 * The main: Compute and print the prime numbers up to MAX_NUMBER.
 */

int main()
{
//	create array with 1001 bool values set to true
	int len = MAX_NUMBER + 1;
	bool prime_arr[len];
	for (int i = 0; i < len; i++) prime_arr[i] = true;
// compute prime array
	compute_primes(prime_arr, len);
//	print prime array
	print_primes(prime_arr, len);
	return 0;
}
