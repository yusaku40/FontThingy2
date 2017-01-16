
#include "Misc.h"






void pRain(Graphics& gfx,SimplePortal& rPortal) {
	static int pOff1;
	
	static bool init;
	static Vec2 FGR[100]; //create 20 Foreground rain droplets

	static Color c(200, 0, 255);
	///new FG Rain
	//init//
	if (!init) {
		for (int i = 0; i < 100; i++) {
			FGR[i].x = rand() % rPortal.WidthIn;
			FGR[i].y = rand() % rPortal.HeightIn;
			pOff1 = 0;
			init = true;
		}
	}
	else {
		for (int i = 0; i < 100; i++) {
			rPortal.DrawLine(gfx, { FGR[i].x,FGR[i].y + pOff1 }, { FGR[i].x, FGR[i].y + pOff1 + 10 }, c);
			if (pOff1 < rPortal.HeightIn) pOff1 = pOff1 +2; //move rain down
			if (pOff1 + 0 >= rPortal.HeightIn) {
				pOff1 = 0;
				FGR[i].x = rand() % rPortal.WidthIn;
				FGR[i].y = 0;
			}
		}
		
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