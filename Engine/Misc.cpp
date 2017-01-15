
#include "Misc.h"





void pRain(Graphics& gfx) {
	static int pOff1;
	static int pOff2;
	static int pOff3;

	Color c(255, 0, 255);
	//fg rain
	if (pOff1 < 300) {

		int test = rand();
		int test2 = rand() / 255;


		gfx.DrawLine(10, 10 + pOff1, 10, 40 + pOff1, c);
		gfx.DrawLine(50, 20 + pOff1, 50, 50 + pOff1, c);
		gfx.DrawLine(70, 40 + pOff1, 70, 70 + pOff1, c);
		gfx.DrawLine(200, 10 + pOff1, 200, 40 + pOff1, c);
		pOff1 = pOff1 + 10;
	}
	else {
		pOff1 = 0;
	}
	//mid rain
	Color c2(200, 0, 200);
	if (pOff2 < 300) {
		gfx.DrawLine(20, 10 + pOff2, 20, 20 + pOff2, c2);
		gfx.DrawLine(80, 10 + pOff2, 80, 20 + pOff2, c2);
		gfx.DrawLine(90, 10 + pOff2, 90, 20 + pOff2, c2);
		gfx.DrawLine(150, 10 + pOff2, 150, 20 + pOff2, c2);
		pOff2 = pOff2 + 6;
	}
	else {
		pOff2 = 0;
	}

}

void FpsWindow(Graphics& gfx,Font font) {
	//fps system parts
	static int fps[60];  ///for averaging fps rahter than be flickery
	SYSTEMTIME st;
	char buffer3[10];
	Color color = { 200,100,255 };

	int tempSum = 0;

	GetSystemTime(&st);
	static int oldMs;
	static int deltaMs;
	deltaMs = oldMs - st.wMilliseconds;


	//calculate average of fps///
	for (int i = 0; i < 59; i++) {
		fps[i + 1] = fps[i]; //move old measure down the stack
	}
	fps[0] = 1000 / deltaMs; //add new fps measure
	for (int i = 0; i < 60; i++) {
		tempSum = tempSum + fps[i];
	}
	_itoa_s(tempSum / 60, buffer3, 10);
	//tempSum = 0;
	///end calculate average fps///

	font.PrintS(gfx, "FPS: ", 1200, 20, color);
	font.PrintS(gfx, buffer3, 1230, 20, color);



	oldMs = st.wMilliseconds;


	gfx.DrawLine({ 1190,30 }, { 1279,30 }, { 150,50,150 });
	gfx.DrawLine({ 1190,30 }, { 1190,0 }, { 150,50,150 });
}