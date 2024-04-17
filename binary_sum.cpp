#include<bits/stdc++.h>

using namespace std;

const int SIZE = pow(2,20);
const int cIn=0; // Initial carry in 

bool A[SIZE];
bool B[SIZE];
bool S[SIZE]; // Sum array
//int cIndx = SIZE; // The current index of the bit to write the sum in

int add_binary(bool a, bool b, bool cin, bool* s);
void init();
void display_array(bool* arr, int N);	
int add_A_and_B(bool* A, bool* B, bool cin, int level, int start, int end);

int main() {
	int resCarry;
	init();
	//display_array(A, SIZE);
	//display_array(B, SIZE);
	cout << "Cin=" << cIn << endl;
	resCarry = add_A_and_B(A, B, cIn, SIZE-1, 0, SIZE-1);
	cout << "--------- Finished. Sum: \n";
	//display_array(S, SIZE);
	cout << "Carray = " << resCarry << endl;


}

/**
 * Add 2 bits and return the carry*/
int add_binary(bool a, bool b, bool cin, bool* s) {
	//cout << "Adding binary A=" << a << ", B=" << b;
	*s = (a ^ b) ^ cin;
	//cout << ", Sum=" << *s << endl;
	bool G = a && b;
	bool P = a != b; // a XOR b
	return G || (P && cin); // The resultant carry cout
}

/**
 * Add A and B into s and return the carry
 * Each time we'll be dividing the array into sub blocks
 * and making the sum recursively.
 * level: initially = SIZE-1*/
int add_A_and_B(bool* A, bool* B, bool cin, int level, int start, int end) {
	if (start == end) {
	//	cout << "Adding into sum[" << start << "],";
		// atomic addition between two bits
		return add_binary(A[start], B[start], cin, &S[start]);
	
	}
		return add_A_and_B(A, 
				B, 
				add_A_and_B(A, B, cin, level-1, (start+end)/2+1, end),
		        	level-1, 
				start,
				(start+end)/2	
				);
}

/**
 * Initialize A & B with random bits*/
void init() {
	auto gen = std::bind(std::uniform_int_distribution<>(0,1),std::default_random_engine());
	for (int i=0; i<SIZE; i++) {
		A[i] = gen();
		B[i] = gen();
	}
}

void display_array(bool* arr, int N) {	
	for (int i=0; i<N; i++) {
		cout << arr[i];
	}
	cout << endl;
}
