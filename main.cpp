#include <iostream>
#include <cmath>
using namespace std;
unsigned long long int MAX = 1000000000000;
unsigned long long int MIN = 1;

bool isPrime(unsigned long long int num); 

int Euclide(unsigned long long int a,unsigned long long int b); 

bool isMultiple (unsigned long long int a, unsigned long long int b);

int main()
{
	srand(time(NULL));
	register unsigned int p , q , e , d , a;
	static unsigned int mod, prod;
	while (!isPrime(p))
			p = rand() % MAX;
	while (!isPrime(q))
			q = rand() % MAX;
	mod = p * q;
	prod = (p-1) * (q-1);
	e = rand() % prod - 1;
	direct:
	while (Euclide(e,prod)!=1)
		e = rand() % prod - 1;
	if (e >= prod) goto direct;
	do{
		d = rand() % prod;
		a = (d * e) - 1;
	}while (!isMultiple(a,prod));
	cout << " chiave pubblica " << "(" << mod << "," << e << ")" << endl;
	cout << " chiave privata " << "(" << mod << "," << d << ")" << endl;
	return 0;
}
bool isPrime(unsigned long long int num) {

	for (int i = 3; i <= sqrt(num) + 1; i = i + 2) {
		if (num % i == 0)
			return true;
	}

	return false;
}

int Euclide(unsigned long long int a,unsigned long long int b) 
{
    int r;
    while(b != 0) 
    {
         r = a % b;
         a = b; 
         b = r; 
    }
    return a; 
}
bool isMultiple (unsigned long long int a, unsigned long long int b)
{
	if (b%a==0) return true;
	else return false;
}