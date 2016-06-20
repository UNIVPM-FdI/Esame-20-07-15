#include <iostream>
#include <fstream>
using namespace std;
struct elem {
	int info;
	int occorrenza;
	elem *succ;
};
typedef elem* lista;
fstream sondaggio;

bool estrai_elem_dato(lista& inizio,elem& a)
{
	lista p,q;
	for (q=inizio;q!=0 && q->info!=a.info;q=q->succ) p=q;
	if (q==0) return false;
	if (q==inizio) inizio=q->succ;
	else p->succ=q->succ;
	a=*q;
	delete q;
	return true;
}
void inserimento_ordinato(lista& inizio,elem a)
{
	lista p=0,q,d;
	for (q=inizio;q!=0 && q->occorrenza>a.occorrenza;q=q->succ) p=q;
	d=new elem;
	*d=a;
	d->succ=q;
	if (q==inizio)inizio=d;
	else p->succ=d;
	}
	void carica (lista& p0)
	{
		elem e;
		while (sondaggio >>e.info)
		{				
			if (estrai_elem_dato(p0,e))e.occorrenza = e.occorrenza+1;
            else e.occorrenza = 1;
			inserimento_ordinato(p0,e);
		}
	}
	float media(lista p0)
	{
		float media_num,totale=0,somma=0;
		while(p0!=0)
		{
			media_num=p0->info*p0->occorrenza;
			totale+=p0->occorrenza;
			somma+=media_num;
			p0=p0->succ;
		}
		return somma/totale;
	}
	void stampa(lista p0)
	{
		while (p0!=0)
		{
			cout << p0->info << " che si ripete " << p0->occorrenza << endl;
			p0=p0->succ;
		}
	}
	int main (int argc, char *argv[])
	{
		lista numeri=0;
		sondaggio.open(argv[1],ios::in);
		carica(numeri);
	    cout << "la moda e' " << numeri->info << " che si ripete " << numeri->occorrenza << " volte" << endl;
	    cout << "la media aritmetica e' " << media(numeri) << endl;
	    stampa(numeri);
		sondaggio.close(); 
	}
