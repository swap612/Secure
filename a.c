#include <stdio.h>
#include <stdlib.h>
struct temp
{
char z[256];
}temp;
int main()
{
        int size = 100000;
        size /= 4;
        int index[size];
        for(int i=0;i<size;i++)
                index[i]=i;   //Streaming Index
        struct temp a[size], b[size/100];


        for(int i=0;i<size;i++)// Initialize array a
                for(int j =0;j<255;j++){
                        a[i].z[j] = 1;
				 b[i].z[j] = 1;
                }
        while(1){
                for(int j=0;j<size;j++){
                        //if((j%8 == 1) ||(j%8 == 2)||(j%8 == 3)||(j%8 == 0))
			a[j].z[0] = index[j] * a[index[j]].z[index[0]];
                        a[j].z[64] = index[j] * a[index[j]].z[index[64]];
                        a[j].z[128] = index[j] * a[index[j]].z[index[128]];
                        a[j].z[192] = index[j] * a[index[j]].z[index[192]];
                        //if((j%8 == 4) ||(j%8 == 5)||(j%8 == 6)||(j%8 == 7))
			a[j].z[0] = index[j] * a[index[j]].z[index[0]];
                        a[j].z[64] = index[j] * a[index[j]].z[index[64]];
                        a[j].z[128] = index[j] * a[index[j]].z[index[128]];
                        a[j].z[192] = index[j] * a[index[j]].z[index[192]];



			//b[j].z[0] = index[j] * b[index[j]].z[index[0]];
                        //b[j].z[64] = index[j] * b[index[j]].z[index[64]];
                        //b[j].z[128] = index[j] * b[index[j]].z[index[128]];
                        //b[j].z[192] = index[j] * b[index[j]].z[index[192]];
			


                        }
        }
        return 0;
}
