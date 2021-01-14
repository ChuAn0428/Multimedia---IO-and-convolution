/////////////////////////////////////
// CSCI 558 Multimedia - I/O and convolution
// Author: Chu-An Tsai
// 02/10/2020
/////////////////////////////////////

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <windows.h>
#include <math.h>
#define DATASIZE 375000
#define sleep(x) Sleep(1000 * (x))

FILE *file_id1, *file_id2;
unsigned char data[DATASIZE], outdata[DATASIZE];

int main( )
{
    file_id1 = fopen("unesco750-1.raw","rb");
    fread(data, 1, DATASIZE, file_id1);
    fclose(file_id1);

	int filter[] = {1, 2, 3, 4, 5, 4, 3, 2, 1};
	int n = 9;
    int i, j, m;
    int tempData[DATASIZE+8] = {0};
	int calculationUse;

    for(i = 0; i < DATASIZE+8; i++)
    {
        if (i > 3 && i < DATASIZE+3)
        {
			tempData[i] = data[i-4];
		}		
        //printf("%d\n",tempData[i]);	// check
        //sleep(0.1);
    }
    
	for(i = 0; i < DATASIZE; i++)
	{
	    //printf("%d\n",tempData[i]);  // check
        //sleep(0.1);
        
        calculationUse = 0;
		for(j = i, m = 0; m < n; j++, m++)
        {
            calculationUse += tempData[j]*filter[m];
            //printf("%d----%d===%d\n",tempData[j], filter[m], calculationUse);	// check
			//sleep(0.1);
        }
        //printf("%d-", calculationUse/25);	// check
		
		outdata[i] = calculationUse/(1+2+3+4+5+4+3+2+1);
		
		//printf("%d\n",outdata[i]);    // check
        //sleep(0.1);
	}
	/* // check
	for (i = 0; i < 20; i++)
	{
		printf("%d\n", outdata[i]);
	}

	for (i = DATASIZE-20; i < DATASIZE; i++)
	{
		printf("%d\n", outdata[i]);
	}
	*/
	
    file_id2 = fopen("output.raw","wb");
    fwrite(outdata, 1, DATASIZE, file_id2);
    fclose(file_id2);

    return 0;
}
