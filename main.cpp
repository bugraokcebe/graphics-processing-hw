#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <math.h>

// Buðra Han Okcebe
// 201213093


void noktaKoy(int x, int y){
	putpixel(x,y,RED);	
}
void daireCiz(int xMerkez, int yMerkez, int r){
	int x, y;
	for(y = -r; y<=r; y++) {
		for(x = -r; x<=r; x++) {
		if( x * x + y * y < r * r){
			noktaKoy(x+xMerkez,y+yMerkez);
		}
		}	
	}
}
void cemberCiz(int x0, int y0, int radius){
    int x = radius;
    int y = 0;
    int err = 0;
 
    while (x >= y)
    {
    	noktaKoy(x0 + x, y0 + y);
    	noktaKoy(x0 + y, y0 + x);
    	noktaKoy(x0 - y, y0 + x);
    	noktaKoy(x0 - x, y0 + y);
    	noktaKoy(x0 - x, y0 - y);
    	noktaKoy(x0 - y, y0 - x);
    	noktaKoy(x0 + y, y0 - x);
    	noktaKoy(x0 + x, y0 - y);

		if (err <= 0)
		{
		    y += 1;
		    err += 2*y + 1;
		}
 
		if (err > 0)
		{
		    x -= 1;
		    err -= 2*x + 1;
		}
    }
}
void cizgiCiz(int X0, int Y0, int X1, int Y1){
	
    int dx = X1 - X0;
    int dy = Y1 - Y0;
 
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
 

    float Xinc = dx / (float)steps;
    float Yinc = dy / (float)steps;
 
    float X = X0;
    float Y = Y0;
    for (int i = 0; i <= steps; i++) {
        noktaKoy(round(X), round(Y)); 
        X += Xinc; 
        Y += Yinc;
    }
}	
void dortgenCiz(int solUst, int sagUst, int solAlt, int sagAlt){
	
	cizgiCiz(solUst,sagUst,solAlt,sagUst); 
	cizgiCiz(solUst,sagAlt,solAlt,sagAlt);
	cizgiCiz(solUst,sagUst,solUst,sagAlt);
	cizgiCiz(solAlt,sagUst,solAlt,sagAlt);
	
}
void ucgenCiz(int xUst, int yUst, int xSol, int ySol, int xSag, int ySag){
	cizgiCiz(xUst,yUst,xSol,ySol);
	cizgiCiz(xSol,ySol,xSag,ySag);
	cizgiCiz(xSag,ySag,xUst,yUst);
	
}
void elipsCiz(int xMerkez, int yMerkez, int a , int b){
	
	int x=0;
    int y=b;
    int aKare=a*a;
    int bKare=b*b;
    int fx = 2*bKare*x;
    int fy = 2*aKare*y;
  	int d=bKare-(aKare*b)+(aKare*0.25);
  	
	do{
		  noktaKoy(xMerkez+x,yMerkez+y);
		  noktaKoy(xMerkez-x,yMerkez-y);
		  noktaKoy(xMerkez+x,yMerkez-y);
		  noktaKoy(xMerkez-x,yMerkez+y);

   	if(d<0){
  		d=d+fx+bKare;
	}
	else{
	  y=y-1;
	  d=d+fx+-fy+bKare;
	  fy=fy-(2*aKare);
  	}
	  x=x+1;
	  fx=fx+(2*bKare);
	}
	while(fx<fy);
	   
	int deger1=(x+0.5)*(x+0.5);
	int deger2=(y-1)*(y-1);
	d=bKare*deger1+aKare*deger2-(aKare*bKare);
   	
	do{
	  noktaKoy(xMerkez+x,yMerkez+y);
	  noktaKoy(xMerkez-x,yMerkez-y);
	  noktaKoy(xMerkez+x,yMerkez-y);
	  noktaKoy(xMerkez-x,yMerkez+y);

   	if(d>=0) d=d-fy+aKare;
   	else{
	  x=x+1;
	  d=d+fx-fy+aKare;
	  fx=fx+(2*bKare);
	}
	y=y-1;
	fy=fy-(2*aKare);
	}
	
   while(y>0);
}
void egriCiz(int x0, int y0, int radius){
    int x = radius;
    int y = 0;
    int radi = 2*radius;
    int x1 = x0-1;
    int y1 = y0+radi-1;
    int err = 0;
 
    while (x >= y)
    {
    	noktaKoy(x0 + x, y0 + y);
    	noktaKoy(x0 + y, y0 + x);
    	noktaKoy(x0 + y, y0 - x);
    	noktaKoy(x0 + x, y0 - y);

		if (err <= 0)
		{
		    y += 1;
		    err += 2*y + 1;
		}
 
		if (err > 0)
		{
		    x -= 1;
		    err -= 2*x + 1;
		}
    }
    x = radius;
    y = 0;
    err = 0;
    while (x >= y)
    {
   		noktaKoy(x1 - y, y1 + x);
    	noktaKoy(x1 - x, y1 + y);
    	noktaKoy(x1 - x, y1 - y);
    	noktaKoy(x1 - y, y1 - x);

		if (err <= 0)
		{
		    y += 1;
		    err += 2*y + 1;
		}
 
		if (err > 0)
		{
		    x -= 1;
		    err -= 2*x + 1;
		}
    }
}
void yayCiz(int x0, int y0, int radius){
	int x = radius;
    int y = 0;
    int err = 0;
 
    while (x >= y)
    {
    	noktaKoy(x0 + x, y0 + y);
    	noktaKoy(x0 + y, y0 + x);
    	noktaKoy(x0 + y, y0 - x);
    	noktaKoy(x0 + x, y0 - y);

		if (err <= 0)
		{
		    y += 1;
		    err += 2*y + 1;
		}
 
		if (err > 0)
		{
		    x -= 1;
		    err -= 2*x + 1;
		}
    }
}
//disk yarým
void diskCiz(int xMerkez, int yMerkez, int r, int icBoy){
	int x, y;
	int yeniR = r-icBoy;
	for(y = -r; y<=r; ++y) {
		for(x = -r; x<=r; ++x) {
			if( x * x + y * y < r * r){
				//if(x * x + y * y < yeniR * yeniR) break;
				noktaKoy(x+xMerkez,y+yMerkez);
			}
		}	
	}
	for(y = -yeniR; y<=yeniR; ++y) {
		for(x = -yeniR; x<=yeniR; ++x) {
			if( x * x + y * y < yeniR * yeniR){
				putpixel(x+xMerkez,y+yMerkez,0);
			}
		}	
	}
}
void polyCiz(int x, int *arr){

	int i;

	int diziBoyut = x*2;

	for(i=0;i<diziBoyut;i+=2){
		if(diziBoyut-2 == i){
			cizgiCiz(arr[i], arr[i+1], arr[i], arr[i+1]);	
		}
		else{
			cizgiCiz(arr[i], arr[i+1], arr[i+2], arr[i+3]);	
		}
	}


}

int main(int argc, char *argv[]) {
	initwindow(500,500);

		
	//daireCiz(250,250,150);
	//cemberCiz(250,250,150);
	//cizgiCiz(50,50,100,250);
	//dortgenCiz(50,50,100,250);
	//ucgenCiz(50,50,400,400,90,150);
	//yayCiz(400,150,50);
	//egriCiz(150,100,25);
	//elipsCiz(200,200,50,150);
	//diskCiz(250,250,150,110);
	/*
	int poly[10];
	poly[0] = 20; // 1st vertex 
	poly[1] = 100;
	poly[2] = 120;
	poly[3] = 140;  // 2nd vertex 
	poly[4] = 240;
	poly[5] = 260;  // 3rd vertex 
	poly[6] = 120;
	poly[7] = 320; // 4th vertex 
	poly[8] = poly[0];
	poly[9] = poly[1]; 
	polyCiz(5,poly);
	*/
	//Yýldýz 
	int poly[22] = {395,250,418,257,418,280,431,261,
	454,269,440,250,453,231,431,238,417,220,417,243,395,250};
	polyCiz(11,poly);
	
	getch();
    closegraph();
	return 0;
}
