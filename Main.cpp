#include <iostream>
#include <conio.h>
using namespace std;

struct node{
	int jarak;
	node *jalur;	
};

int main(){	
	node *surabaya = new node;
	node *sidoarjo = new node;
	node *ngawi    = new node;
	surabaya -> jarak = 5;
	sidoarjo -> jarak = 5;
	ngawi    -> jarak = 9;
	
	surabaya -> jalur = sidoarjo;
	sidoarjo -> jalur = surabaya;
	
	surabaya -> jalur = ngawi;
	
	node *sekarang = new node;
	sekarang = surabaya;
	sekarang = surabaya->jalur;
	cout<<sekarang->jarak;	
	
	
	return 0;
}
