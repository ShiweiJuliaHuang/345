#include <iostream>
#include <string.h>

using namespace std;

const int MAX = 2000;
const int N   = 10;

void setupstring (char [], int&);

int main ()
{
   char omega [MAX];
   int omegalength;

   setupstring (omega, omegalength);

   for (int i = 0; i < omegalength; i++)
      cout << omega [i];

   cout << endl;
   return 0;
}


void setupstring (char omega[], int& omegalen)
{
   int i, j;

   strcpy (omega, "272722");
   for (i = 0; i < N; i++)
      strcat (omega, "28272272927222");

   strcat (omega, "272722");

   for (i = 0; i < N; i++) {
      strcat (omega, "272733733");
 
      for (j = i; j < N; j++)
         strcat (omega, "373338393373737333");
      strcat (omega, "3637322");
   }

   omegalen = strlen (omega);
}