/* Subroutine Flash(a,n,m,ctr)

- Sorts array a with n elements by use of the index vector l of

dimension m (with m about 0.1 n).

- The routine runs fastest with a uniform distribution of elements.

- The vector l is declare dynamically using the calloc function.

- The variable ctr counts the number of times that flashsort is called.

- THRESHOLD is a very important constant.  It is the minimum number

of elements required in a subclass before recursion is used.     */



#include < stdio.h > 

#include < math.h > 

#include < malloc.h > 
#include <iostream>



const int THRESHOLD = 75;

const int CLASS_SIZE = 75;     /* minimum value for m */



void flashsort(float a[], int n, int m)

{

	/* declare variables */

	int *l, nmin, nmax, i, j, k, nmove, nx, mx;

	float c1, c2, flash, hold;



	/* allocate space for the l vector */

	l = (int*)calloc(m, sizeof(int));



	/***** CLASS FORMATION ****/



	nmin = nmax = 0;

	for (i = 0; i < n; i++){

		if (a[i] < a[nmin]) nmin = i;

		else if (a[i] > a[nmax]) nmax = i;
	}


		if (a[nmax] == a[nmin])

		{

			printf("All the numbers are identical, the list is sorted\n");

			return;

		}



		c1 = (m - 1.0) / (a[nmax] - a[nmin]);

		c2 = a[nmin];



		l[0] = -1; /* since the base of the "a" (data) array is 0 */

		for (k = 1; k < m; k++) l[k] = 0;



		for (i = 0; i < n; i++)

		{

			k = floor(c1*(a[i] - c2));

			l[k] += 1;

		}



		for (k = 1; k < m; k++) l[k] += l[k - 1];



		hold = a[nmax];

		a[nmax] = a[0];

		a[0] = hold;





		/**** PERMUTATION *****/



		nmove = 0;

		j = 0;

		k = m - 1;



		while (nmove <  n)

		{

			while (j  >  l[k])

			{

				j++;

				k = floor(c1*(a[j] - c2));

			}



			flash = a[j];



			while (j <= l[k])

			{

				k = floor(c1*(flash - c2));

				hold = a[l[k]];

				a[l[k]] = flash;

				l[k]--;

				flash = hold;

				nmove++;

			}

		}



		/**** Choice of RECURSION or STRAIGHT INSERTION *****/



		for (k = 0; k<(m - 1); k++)

			if ((nx = l[k + 1] - l[k]) > THRESHOLD)  /* then use recursion */

			{

				flashsort(&a[l[k] + 1], nx, (int)(0.43*CLASS_SIZE));


			}



			else  /* use insertion sort */{
				for (i = l[k + 1] -1; i > l[k]; i--)

					if (a[i] > a[i + 1])

					{
						hold = a[i];

						j = i;

						while (hold > a[j + 1])  a[j++] = a[j + 1];

						a[j] = hold;

					}
			}

		free(l);   /* need to free the memory we grabbed for the l vector */

}
void flashsort2(float arr[], int size, int CS){
	int AMIN = arr[0];
	int imax = 0;
	int i, j, k, hold, flash, nmove;

	for (int i = 0; i < size; ++i){
		if (arr[i] < AMIN){
			AMIN = arr[i];
		}
		else if (arr[i]>arr[imax]){
			imax = i;
		}
	}
	if (AMIN == arr[imax])return;

	double C = (CS - 1.0) / (arr[imax] - AMIN);

	int *L = new int[CS]();
	L[0] = -1;

	for (i = 0; i < size; ++i){
		k = (int)(C*(arr[i] - AMIN));
		L[k]++;
	}

	for (i = 1; i < CS; ++i){
		L[i] += L[i - 1];
	}

	hold = arr[imax];
	arr[imax] = arr[0];
	arr[0] = hold;

	nmove = 0;
	j = 0;
	k = CS - 1;

	while (nmove < size){
		while (j >= L[k]){
			j++;
			k = (int)(C*(arr[j] - AMIN));
		}

		flash = arr[j];

		while (j <= L[k]){
			k = (int)(C*(flash - AMIN));

			hold = arr[L[k]];
			arr[L[k]] = flash;
			flash = hold;

			L[k]--;
			nmove++;
		}
	}

	for (k = 0; k < CS - 1; ++k){
		if (L[k + 1] - L[k]>CLASS_SIZE){
			flashsort2(&arr[L[k] + 1], L[k + 1] - L[k], (int)(0.43*CLASS_SIZE));
		}
		else{
			for (i = L[k] + 2; i <= L[k + 1]; ++i){
				hold = arr[i];
				j = i;
				for (; j > 0 && arr[j-1] > hold; --j){
					arr[j] = arr[j - 1];
				}
				arr[j] = hold;
			}
			/*for (i = L[k + 1] - 1; i > L[k]; i--)

				if (arr[i] > arr[i + 1])

				{
					hold = arr[i];

					j = i;

					while (hold > arr[j + 1])  arr[j++] = arr[j + 1];

					arr[j] = hold;

				}*/
		}
	}
	delete[]L;
}
int main(void){

	int size = 15;
	float p[15] = { 1,1,1,1,0,0,0,10,10,1,2,3,1,2,3};
	flashsort2(p, size, (int)(0.43*size));

	for (int i = 0; i < size; i++){
		std::cout << p[i] << "\t";
	}

	return 0;
}