#include <stdio.h>
#include <stdlib.h>
#include <time.h>



double stopandwait(int number, double percentage, int T_P, int TIMEOUT)
{
  srand(time(NULL));
  int szansa;
  float time = 0;
  for(int i = 0; i<number; i++)
    {
      szansa = rand() % 100;
      time += T_P;
      if(szansa<(100-percentage))
	{
	  time+=TIMEOUT;
	  i--;
	  //	  printf("Pakiet %d miss\n", i);
	}
      else
	{
	  time+=T_P;
	  //	  printf("Pakiet %d\n", i);
	}
    }
  return time;
}

double gobackn(int number, double percentage, int T_P, int TIMEOUT, int windowsize)
{
  srand(time(NULL));
  int n = 0;
  int szansa;
  double time = 0;
  for(int i = 0; i<number; i++)
    {
      szansa = rand() % 100;
      time += T_P/(double)(windowsize -1 );
      if(n>0)
	szansa = 100;
      if(szansa<(100-percentage))
	{
	  n += windowsize+1;
	  //	  printf("Pakiet %d miss\n", i);
	}
      else
	{
	  time+=T_P/(double)(windowsize-1);
	  //	  printf("Pakiet %d\n", i);
	  if(n>1)
	    n--;
	  if(n==1)
	    {
	      i-=windowsize+1;
	      n--;
	      //printf("backtracking\n");
	    }
	}
    }
  return time;
}


int main(int argc, char *argv[])
{
  if(argc<4)
    {
      printf("zla liczba argumentów\nuzycie %s <ilosc> <procent> <ping> <rozmiar okna>\n", argv[0]);
      return 0;
    }
  
  int number = atoi(argv[1]);
  double reliability = atoi(argv[2]);
  int ping = atoi(argv[3]);
  int miss = ping*3;
  int n = atoi(argv[4]);
  
  printf("%lf,",stopandwait(number, reliability, ping, miss));
  printf("%lf",gobackn(number, reliability, ping, miss, n)); 
}
