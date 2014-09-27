#include <stdio.h>
#include <memory.h>
#define N 2000001
#define FIN "primes.in"
#define FOUT "primes.out"

FILE *fin, 
     *fout;

char sita[ N / 8 + 1];

int checkOne(int n, int p) 
{

    return (sita[ n ] >> p) & 1;
}

void one(int n, int p) 
{

     int mask = 1;

     mask <<= p;

     sita[ n ] |= mask;
}

void Erathostene() 
{

     int i,
         j;

     for( i = 2; i * i <= N; i++ )
     {
           
          if( !checkOne( i / 8, i % 8 ) )
          {
               j = 2;

               while( i * j  <= N ) 
               {
                      one( (i*j) / 8, (i*j) % 8);

                      j++;                       
               }
          }           
     } 
     
};

int isPrime( int n ) 
{
    return !checkOne( n / 8, n % 8 );
}

int main() {

    int num;
 
    fin = fopen(FIN, "r");

    fout = fopen(FOUT, "w");

    memset(sita, 0, sizeof( sita ));

    Erathostene();

    while(fscanf(fin, "%d", &num) == 1) {

          if( isPrime( num ) ) {

              fprintf(fout, "%7d is Prime\n", num); 

          }  else {

              fprintf(fout, "%7d Is Not Prime\n", num); 

          }             
    }

    fclose( fin ); 
    fclose( fout ); 

    return(0);
};