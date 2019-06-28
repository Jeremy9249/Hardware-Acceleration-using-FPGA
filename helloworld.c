/* Jeremy Perez
 ECE 520 Mini Project */

#include <stdio.h>
#include "platform.h"
#include "xil_printf.h"
#include "xil_io.h"
#include "xparameters.h"

int main()
{
    short sin_x[720];
	short cos_x[720];
	short sin_2x[720];
    short a=1;
    short b=1;
    short c=1;
    short d=1;
    short f_x[720];

    Xil_Out16(XPAR_AXI_BRAM_CTRL_0_S_AXI_BASEADDR+0,0x00); // Initialize BRAM 1
    Xil_Out16(XPAR_AXI_BRAM_CTRL_1_S_AXI_BASEADDR+0,0x00); // BRAM 2
    Xil_Out16(XPAR_AXI_BRAM_CTRL_2_S_AXI_BASEADDR+0,0x00); // BRAM 3
   short bram[]={
		   0.00000,
		   0.00873,
		   0.01745,
		   0.02618,
		   0.03490,
		   0.04362,
		   0.05234,
		   0.06105,
		   0.06976,
		   0.07846,
		   0.08716,
		   0.09585,
		   0.10453,
		   0.11320,
		   0.12187,
		   0.13053,
		   0.13917,
		   0.14781,
		   0.15643,
		   0.16505,
		   0.17365,
		   0.18224,
		   0.19081,
		   0.19937,
		   0.20791,
		   0.21644,
		   0.22495,
		   0.23345,
		   0.24192,
		   0.25038,
		   0.25882,
		   0.26724,
		   0.27564,
		   0.28402,
		   0.29237,
		   0.30071,
		   0.30902,
		   0.31730,
		   0.32557,
		   0.33381,
		   0.34202,
		   0.35021,
		   0.35837,
		   0.36650,
		   0.37461,
		   0.38268,
		   0.39073,
		   0.39875,
		   0.40674,
		   0.41469,
		   0.42262,
		   0.43051,
		   0.43837,
		   0.44620,
		   0.45399,
		   0.46175,
		   0.46947,
		   0.47716,
		   0.48481,
		   0.49242,
		   0.50000,
		   0.50754,
		   0.51504,
		   0.52250,
		   0.52992,
		   0.53730,
		   0.54464,
		   0.55194,
		   0.55919,
		   0.56641,
		   0.57358,
		   0.58070,
		   0.58779,
		   0.59482,
		   0.60182,
		   0.60876,
		   0.61566,
		   0.62251,
		   0.62932,
		   0.63608,
		   0.64279,
		   0.64945,
		   0.65606,
		   0.66262,
		   0.66913,
		   0.67559,
		   0.68200,
		   0.68835,
		   0.69466,
		   0.70091,
		   0.70711,
		   0.71325,
		   0.71934,
		   0.72537,
		   0.73135,
		   0.73728,
		   0.74314,
		   0.74896,
		   0.75471,
		   0.76041,
		   0.76604,
		   0.77162,
		   0.77715,
		   0.78261,
		   0.78801,
		   0.79335,
		   0.79864,
		   0.80386,
		   0.80902,
		   0.81412,
		   0.81915,
		   0.82413,
		   0.82904,
		   0.83389,
		   0.83867,
		   0.84339,
		   0.84805,
		   0.85264,
		   0.85717,
		   0.86163,
		   0.86603,
		   0.87036,
		   0.87462,
		   0.87882,
		   0.88295,
		   0.88701,
		   0.89101,
		   0.89493,
		   0.89879,
		   0.90259,
		   0.90631,
		   0.90996,
		   0.91355,
		   0.91706,
		   0.92050,
		   0.92388,
		   0.92718,
		   0.93042,
		   0.93358,
		   0.93667,
		   0.93969,
		   0.94264,
		   0.94552,
		   0.94832,
		   0.95106,
		   0.95372,
		   0.95630,
		   0.95882,
		   0.96126,
		   0.96363,
		   0.96593,
		   0.96815,
		   0.97030,
		   0.97237,
		   0.97437,
		   0.97630,
		   0.97815,
		   0.97992,
		   0.98163,
		   0.98325,
		   0.98481,
		   0.98629,
		   0.98769,
		   0.98902,
		   0.99027,
		   0.99144,
		   0.99255,
		   0.99357,
		   0.99452,
		   0.99540,
		   0.99619,
		   0.99692,
		   0.99756,
		   0.99813,
		   0.99863,
		   0.99905,
		   0.99939,
		   0.99966,
		   0.99985,
		   0.99996,
		   1.00000 };

    for (int i=0; i<180;i++){
    	Xil_Out16(XPAR_AXI_BRAM_CTRL_0_S_AXI_BASEADDR+i,bram[i/2]); // 0:90
    	Xil_Out16(XPAR_AXI_BRAM_CTRL_1_S_AXI_BASEADDR+i,-1*bram[i/2]); // 0:90
    	Xil_Out16(XPAR_AXI_BRAM_CTRL_2_S_AXI_BASEADDR+i,bram[i]); // 0:179
    }

    for (int i=180; i<360;i++){
        Xil_Out16(XPAR_AXI_BRAM_CTRL_0_S_AXI_BASEADDR+i,bram[i]); // Initialize BRAM 1
        Xil_Out16(XPAR_AXI_BRAM_CTRL_1_S_AXI_BASEADDR+i,-1*bram[i]); // BRAM 2
        Xil_Out16(XPAR_AXI_BRAM_CTRL_2_S_AXI_BASEADDR+i,bram[i]); // BRAM 3
    }
    for (int i=360; i<420;i++){
    	Xil_Out16(XPAR_AXI_BRAM_CTRL_0_S_AXI_BASEADDR+i,bram[i/2]); // Initialize BRAM 1
    	Xil_Out16(XPAR_AXI_BRAM_CTRL_1_S_AXI_BASEADDR+i,-1*bram[i/2]); // BRAM 2
        Xil_Out16(XPAR_AXI_BRAM_CTRL_2_S_AXI_BASEADDR+i,bram[i]); // BRAM 3
   }
    for (int i=420; i<720;i++){
    	Xil_Out16(XPAR_AXI_BRAM_CTRL_0_S_AXI_BASEADDR+i,bram[i/2]); // Initialize BRAM 1
    	Xil_Out16(XPAR_AXI_BRAM_CTRL_1_S_AXI_BASEADDR+i,-1*bram[i/2]); // BRAM 2
        Xil_Out16(XPAR_AXI_BRAM_CTRL_2_S_AXI_BASEADDR+i,bram[i]); // BRAM 3
   }

    	bram[1] = Xil_In16(XPAR_AXI_BRAM_CTRL_0_S_AXI_BASEADDR+1); // load
  FILE * fp;
  /* open the file for writing*/
  fp = fopen ("outputwave.txt","w");

 for(int i=0; i<720;i++){
    f_x[i]=a*sin_x[i]+b*cos_x[i]+c*sin_2x[i]+d;
    fprintf (fp, " %d\n",i);
    printf(f_x[i]);
 }
    return 0;
}
