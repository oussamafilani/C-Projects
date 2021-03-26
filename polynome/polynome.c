#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct poly {int coef;
                      int exp;   
                      struct poly*suiv;} maillon_p; 


typedef maillon_p*Liste; 
 Liste tete;

void creer_Liste_poly(Liste*tete)
 {*tete=NULL;}

void all_maillon_p(Liste*p)
{*p=(Liste) malloc(sizeof(maillon_p));}

void aff_coef(Liste p, int x) 
{p->coef=x;}

void aff_exp(Liste p, int y) 
{p->exp=y;}

void aff_adr(Liste p,Liste q) 
{p->suiv=q;}

int expo(Liste p) 
{return p->exp;}

int coef(Liste p) 
{return p->coef;}

Liste adr(Liste p) 
{return p->suiv;}

int entrer_poly(Liste*tete, int x, int y) 
 {Liste p; int sortie = 0;
   all_maillon_p(&p);
    if( p!=NULL )
     {
      sortie=1;
      aff_coef(p,x);
      aff_exp(p,y);
      aff_adr(p,*tete);
      *tete=p;}
  return sortie;
 }

 void affiche_poly(Liste p) // une fct qui nous affiche le polynome
  {printf("P=");
    while(p!=NULL) 
     {
         if(coef(p)<0) 
         printf("%d*x^%d",coef(p),expo(p));
         else
              { if(coef(p)>0)
              printf(" + %d*x^%d",coef(p),expo(p)); } 
       p=adr(p); 
     }

  }



 void affiche_operations__poly(Liste p) 
  {printf("S=");
    while(p!=NULL)
     {
         if(coef(p)<0)
         printf("%d*x^%d",coef(p),expo(p));
         else
              { if(coef(p)>0)
              printf(" + %d*x^%d",coef(p),expo(p)); }
       p=adr(p);
     }
  }

// la fonction qui calcule du polynome en un point x donné
float calcul_poly(Liste p,double x)
{ double result=0;

   while (p!=NULL)
     {result=result+ coef(p)* pow(x,expo(p));
     p=adr(p);}
 return result;
 }


// Multiplication par un scalaire
 void Multi_Par_Scalaire(Liste l,int C)
 { 

   
	if(l==NULL)
	{
		printf("la liste est vide \n");
		return ;
	}

printf("donner votre entier  : ");
scanf("%d",&C);
poly* p=l;

while(p)
{
	p->coef*=C;
	p=p->suiv;
	
}
	
}

int  Evaluer_Un_Polynome(Liste l)
{  	if(l==NULL)
	{
		printf("la liste est vide \n");
		return 0;
	}
	int x;
printf("\ndonner votre entier  :\n ");
scanf("%d",&x);

poly* p=l;
int ev=0;
while(p)
{
	ev+=p->coef* (pow(x,p->exp));
	p=p->suiv;
	
}
return ev;	
}
void Supp(Liste l,int N)
{   if(l==NULL)
	{
		printf("la liste est vide \n");
		return;
	}
	
	
	poly* p=l;
	if(p->exp==N)
	{
		l=p->suiv;
		free(p);
		return;
	}
	while(p->suiv->exp!=N && p->suiv->suiv!=NULL)
	{
		p=p->suiv;
	}
	if(p->suiv->exp==N)
	{
		 poly* p2=p->suiv;
		 p->suiv=p->suiv->suiv;
		 free(p2);
		 return;
	}
	printf("\nce degre n'existe pas ! \n");
		
}

 void decroissant_Poly(Liste l){
   
        {Liste p=l;
		if(p->suiv->exp != p->suiv->suiv->exp){
            if(p->suiv->exp < p->suiv->suiv->exp)
            {
                poly* tmp;
                tmp->coef=p->suiv->coef;
                tmp->exp=p->suiv->exp;
                p->suiv->coef=p->suiv->suiv->coef;
                p->suiv->exp=p->suiv->suiv->exp;
                p->suiv->suiv->coef=tmp->coef;
                p->suiv->suiv->exp=tmp->exp;
                
            }
        }else
        if(p->suiv->coef < p->suiv->suiv->coef){
                 poly* tmp;
                tmp->coef=p->suiv->coef;
                tmp->exp=p->suiv->exp;
                p->suiv->coef=p->suiv->suiv->coef;
                p->suiv->exp=p->suiv->suiv->exp;
                p->suiv->suiv->coef=tmp->coef;
                p->suiv->suiv->exp=tmp->exp;
               
            }
        }
       
    }

 void croissant_Poly(Liste l){
   
        {Liste p=l;
		if(p->suiv->exp != p->suiv->suiv->exp){
            if(p->suiv->exp > p->suiv->suiv->exp)
            {
                poly* tmp;
                tmp->coef=p->suiv->coef;
                tmp->exp=p->suiv->exp;
                p->suiv->coef=p->suiv->suiv->coef;
                p->suiv->exp=p->suiv->suiv->exp;
                p->suiv->suiv->coef=tmp->coef;
                p->suiv->suiv->exp=tmp->exp;
                
            }
        }else
        if(p->suiv->coef > p->suiv->suiv->coef){
                 poly* tmp;
                tmp->coef=p->suiv->coef;
                tmp->exp=p->suiv->exp;
                p->suiv->coef=p->suiv->suiv->coef;
                p->suiv->exp=p->suiv->suiv->exp;
                p->suiv->suiv->coef=tmp->coef;
                p->suiv->suiv->exp=tmp->exp;
               
            }
        }
       
    }



 // la fonction qui fait la somme de 2 polynomes
Liste somme_poly(Liste l, Liste q,Liste *s)
 {Liste p; int t;

  for (;l!=NULL && q!=NULL;)
    {
      if (expo(l)==expo(q))
         {t = coef(q)+(coef(l));
          if(t!=0)
          all_maillon_p(&p);
          aff_coef(p,t);
          aff_exp(p,expo(q));
          aff_adr(p,*s);
          *s=p;
          l=adr(l);q=adr(q);}
       else
           { if (expo(l)>expo(q))
             {all_maillon_p(&p);
              aff_coef(p,coef(l));
              aff_exp(p,expo(l));
              aff_adr(p,*s);
              *s=p;
              l=adr(l);}

             else
               if(expo(l)<expo(q))
                  {all_maillon_p(&p);
                  aff_coef(p,coef(q));
                  aff_exp(p,expo(q));
                  aff_adr(p,*s);
                  *s=p;
                  q=adr(q);}
           }

    }
            for (;l!=NULL;)
                {all_maillon_p(&p);
                aff_coef(p,coef(l));
                aff_exp(p,expo(l));
                aff_adr(p,*s);
                *s=p; l=adr(l);
				}
				
            for(;q!=NULL;)
               { all_maillon_p(&p);
                aff_coef(p,coef(q));
                aff_exp(p,expo(q));
                aff_adr(p,*s);
                *s=p;q=adr(q);
				}


     return (*s); 
 }
 
  // la fonction qui fait soustraction de 2 polynomes
Liste soustraction_poly(Liste l, Liste q,Liste *w)
 {Liste p; int t;

  for (;l!=NULL && q!=NULL;)
    {
      if (expo(l)==expo(q))
         {t = coef(l)-(coef(q));
          if(t!=0)
          all_maillon_p(&p);
          aff_coef(p,t);
          aff_exp(p,expo(q));
          aff_adr(p,*w);
          *w=p;
          l=adr(l);q=adr(q);}
       else
           { if (expo(l)>expo(q))
             {all_maillon_p(&p);
              aff_coef(p,coef(l));
              aff_exp(p,expo(l));
              aff_adr(p,*w);
              *w=p;
              l=adr(l);}

             else
               if(expo(l)<expo(q))
                  {all_maillon_p(&p);
                  aff_coef(p,coef(q));
                  aff_exp(p,expo(q));
                  aff_adr(p,*w);
                  *w=p;
                  q=adr(q);}
           }

    }
            for (;l!=NULL;)
                {all_maillon_p(&p);
                aff_coef(p,coef(l));
                aff_exp(p,expo(l));
                aff_adr(p,*w);
                *w=p; l=adr(l);
				}
				
            for(;q!=NULL;)
               { all_maillon_p(&p);
                aff_coef(p,coef(q));
                aff_exp(p,expo(q));
                aff_adr(p,*w);
                *w=p;q=adr(q);
				}


     return (*w); 
 }

  // la fonction qui fait produit de 2 polynomes
Liste produit_poly(Liste l, Liste q,Liste *k)
 {Liste p; int t; int r;

  for (;l!=NULL && q!=NULL;)
    {
      if (expo(l)==expo(q))
         {r = expo(l)+(expo(q));
         t = coef(l)*(coef(q));
         
          if(t!=0)
          all_maillon_p(&p);
          aff_coef(p,t);
          aff_exp(p,r);
          aff_adr(p,*k);
          *k=p;
          l=adr(l);q=adr(q);}
       else
           { if (expo(l)>expo(q))
             {all_maillon_p(&p);
              aff_coef(p,coef(l));
              aff_exp(p,expo(l));
              aff_adr(p,*k);
              *k=p;
              l=adr(l);}

             else
               if(expo(l)<expo(q))
                  {all_maillon_p(&p);
                  aff_coef(p,coef(q));
                  aff_exp(p,expo(q));
                  aff_adr(p,*k);
                  *k=p;
                  q=adr(q);}
           }

    }
            for (;l!=NULL;)
                {all_maillon_p(&p);
                aff_coef(p,coef(l));
                aff_exp(p,expo(l));
                aff_adr(p,*k);
                *k=p; l=adr(l);
				}
				
            for(;q!=NULL;)
               { all_maillon_p(&p);
                aff_coef(p,coef(q));
                aff_exp(p,expo(q));
                aff_adr(p,*k);
                *k=p;q=adr(q);
				}


     return (*k); 
 }
 
 
int main()
{ float res,C; int y,x; double z; int i=1 ; int test=1;
   Liste l,s,S,v,w,D,H,k;
   int n,m,max; 
   creer_Liste_poly(&l);


        printf("donner le nombre de termes de votre polynome :\n");
        scanf("%d",&n);
        printf("entrer le premier coefficient de votre 1er polynome\n");
        scanf("%d",&x);
        printf("entrer le premier puissance de  votre 1er polynome \n");
        scanf("%d",&y);
        if(y<0) {
		printf("votre exposant doit etre positive\n"); 
		printf("rettaper votre exposant.\n"); 
		scanf("%d",&y);}
        test= entrer_poly(&l,x,y);
        if (test==0)
         printf("espace insuffisant\n");


   while(i<=n-1 && test==1) 

     {
        printf("donner le coefficient  \n");
        scanf("%d",&x);
        printf("donner le puissance \n");
        scanf("%d",&y);
           if(y<0) {printf("votre exposant doit etre positive\n"); 
		   printf("rettaper votre exposant.\n");
		    scanf("%d",&y);}
        test= entrer_poly(&l,x,y);
        if (test==0)
         printf("espace insuffisant\n");
		 i++;
     }
  printf("voici votre polynome:\n");
  affiche_poly(l);
  printf("\n\n");
//decroissant_Poly(l);
printf("\npolynome dans l'ordre decroissant :\n");
//affiche_poly(l);
//croissant_Poly(l);
printf("\npolynome dans l'ordre croissant :\n");
//affiche_poly(l);
  printf("entrer la valeur pour polynome sera calcule:\n");
  scanf("%lf",&z);
  res=calcul_poly(l,z);
  printf("voici le resultat du calcule:%f\n",res);
Multi_Par_Scalaire(l,C);
affiche_poly(l);
printf("\ndonner le degre de polynome pour supprimer : ");
int N;
scanf("%d",&N);
Supp( l, N);
affiche_poly(l);
printf("\n\n %d",Evaluer_Un_Polynome(l));
// la sommes de 2 polynomes
creer_Liste_poly(&v);// la liste du 2eme polynome

        printf("\ndonner le nombre de termes de votre 2eme polynome :\n");
        scanf("%d",&m);
        printf("entrer le premier coefficient de votre 2eme polynome \n");
        scanf("%d",&x);
        printf("entrer le premier puissance de  votre 2eme polynome \n");
        scanf("%d",&y);
        if(y<0) {printf("votre exposant doit etre positive\n"); 
		printf("rettaper votre exposant.\n");
		 scanf("%d",&y);}
        test= entrer_poly(&v,x,y);
        if (test==0)
        printf(" espace insuffisant\n");i=1;


         while(i<=m-1 && test==1) 

     {
        printf("donner le coefficient \n");
        scanf("%d",&x);
        printf("donner le puissance \n");
        scanf("%d",&y);
        if(y<0) {printf("votre exposant doit etre positive\n");
		 printf("rettaper votre exposant.\n");
		  scanf("%d",&y);}
        test= entrer_poly(&v,x,y);
        if (test==0)
        printf("espace insuffisant\n");
		i++;
     }
  printf("voici votre 2eme polynome\n");
  affiche_poly(v);printf("\n");

creer_Liste_poly(&s);
 if(n>m)
 max=n;
 else if(m >n||m==n)
      max=m;
      
creer_Liste_poly(&w);
 if(n>m)
 max=n;
 else if(m >n||m==n)
      max=m;

creer_Liste_poly(&k);
 if(n>m)
 max=n;
 else if(m >n||m==n)
      max=m;


S= somme_poly(l,v,&s);
printf("\n\nLa somme deux polynomes est :\n");
affiche_operations__poly(S);
D=soustraction_poly( l,  v, &w);
printf("\n\nLa soustraction deux polynomes est:\n");
affiche_operations__poly(D);
H =produit_poly( l,  v, &k);
printf("\n\nLe produit deux polynomes est :\n");
affiche_operations__poly(H);
printf("\n\n************************************** \n");
getchar();
system("PAUSE");
return 0;
}
