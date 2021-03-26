#include<stdio.h>
#include<stdlib.h>


int* Allocation(int n)
{int* t;
	t=(int*)malloc(n*sizeof(int));
	return t;
}
int* saisi(int n)
{
	int i;
	int* t=Allocation(n);
	for(i=0;i<n;i++){
		printf("donner T[%d] : ",i+1);
	scanf("%d",&t[i]);
	}
	return t;
}

void afficher(int* t,int n)
{
	int i;
	printf("\n");
	for(i=0;i<n;i++)
	{
		printf("%d  ",t[i]);
	}
}

void afficher_inverse(int* t,int n)
{
	int i;
	for(i=n-1;i>=0;i--)
	{
		printf("%d  ",t[i]);
	}
}
void echanger(int *v1,int* v2)
{
	int temp;
	temp=*v1;
	*v1=*v2;
	*v2=temp;
}

int* Trie_insertion(int* t,int n)
{
	int i,j;
	
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(t[i]>t[j])
		 {
			echanger(&t[i],&t[j]);
		}
	}
}
	return t;
}


int indiceMin(int *t,int i,int n)
{
	int j, min=i;
	
	for(j=i+1;j<n;j++)
	{
		if(t[j]<t[min])
		{
			min=j;
		}
	}
	
	return min;
}


int* Trie_selection(int* t,int n)
{
	int i,temp1;
	
	for(i=0;i<n;i++)
	{
			
	temp1=indiceMin(t,i,n);
	echanger(&t[i],&t[temp1]);

	}
return t;
}

int* Tri_Bulle(int* t,int n)
{
	int i=0,j,temp;  int v=1;
	while(i<n && v )
	{
		v=0;
		for(j=0;j<n-i;j++)
		{
			if(t[j]>t[j+1])
			{ echanger(&t[j],&t[j+1]);
			
				v=1;
			}
		}
		i++;
	}

return t;
}
int menu()
{
	int x;
	do{
		system("cls");
	printf("*************************************************************\n");
	printf("    1)  Trie par Insertion                                 |\n");
	printf("    2)  Trie par Selection                                 | \n");
	printf("    3)  Trie a Bulle                                       | \n");
	printf("*************************************************************\n");
	printf("donner votre choix\n");
	scanf("%d",&x);
	
	}while(x<1 || x>3);
	return x;
}




main(){

int* t;
int n,x;
printf("donner la taille du tableau\n");
scanf("%d",&n);
t=saisi(n);
x=menu();
printf("avant le Trie\n");afficher(t,n);
switch(x)
{   
	case 1: {  t=Trie_insertion(t,n);
		break;
	}
	case 2: {  t=Trie_selection(t,n);
		break;
	}
	case 3: {  t=Tri_Bulle(t,n);
		break;
	}
	
}
printf("\napres le Trie\n");
afficher(t,n);

getchar();
}

