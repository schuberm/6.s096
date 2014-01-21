/*
PROG: floating
LANG: C
*/

#include <stdio.h>
#include <stdlib.h>

union float_bits {
	float f;
	unsigned int bits;
	unsigned u;
};

void print_hex( float f) {
	union float_bits t;
	t.f = f;
	printf("The float looks like 0x%x in hex.\n", t.bits );
}

void print_bin( float f) {
	union float_bits t;
	t.f = f;
	printf("The float looks like %u in unsigned.\n", t.u );
}

void showbits(float f)
    {
        union float_bits t;
        t.f=f;
        int i; 
        for(i=(sizeof(int)*8)-1; i>=0; i--)
            (t.bits&(1<<i))?putchar('1'):putchar('0');
 
    	printf("\n");
    }

void bits(float f, int *bin, char *repfloat, int *ee)
    {
        union float_bits t;
        t.f=f;
        int i;
        int e=0;
        int count=0;
        for(i=(sizeof(int)*8)-1; i>=0; i--){
            if ((t.bits&(1<<i)))
            	bin[count]=1;
            else
            	bin[count]=0;
        	count++;
 		}
 		for (i=1;i<=8;i++){
            e = (e<<1) | bin[i];
            //printf("%i",bin[i]);
 		}
 		for (i=0;i<=23;i++){
 			if (bin[i+9]==1)
 				repfloat[i]='1';
 			else
 				repfloat[i]='0';
 		}
 		e=e-127;
 		*ee=e;
    }

int main(void){
	char line[80];
	int *bin=malloc(sizeof(int));
	char *repfloat=malloc(sizeof(char));
	float num;
	int ee;
	FILE *input = fopen ("floating.in","r");
	FILE *output = fopen("floating.out","w");
		while(fgets(line, 80, input) != NULL)
   		{
	 		sscanf (line, "%f", &num);
	 		/* convert the string to a long int */
	 		//printf ("%f\n", num);
	 		//print_hex(num);
	 		//print_bin(num);
	 		//showbits(num);
	 		bits(num,bin,repfloat,&ee);
	 		//printf("%s\n",str);
	 		//for (i=1;i<=8;i++){
            //e=e+2^((9-i)*bin[i]);
            //	e = (e<<1) | bin[i];
            //	printf("%i",bin[i]);
 			//}
 			//e=e-127;
 			//printf("%s\n",repfloat);
	 		if (bin[0]==0)
 				fprintf(output,"1.%s * 2^%i\n",repfloat,ee);
 			else
 				fprintf(output,"-1.%s * 2^%i\n",repfloat,ee);
   		}
	fclose( input );
	fclose( output );
	free (repfloat);
	return 0;
}