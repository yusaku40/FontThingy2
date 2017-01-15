#include "Portals.h"




SimplePortal::SimplePortal(Graphics gfx, int x1, int y1, int x2, int y2, Color bColor)
{
	X1 = x1; Y1 = y1; X2 = x2; Y2 = y2; //copy in location
	this->BorderColor = bColor; //remove if uneccessary
	
	///calculate internal size
	WidthIn = X2 - X1 - 4; ///subtract border width
	HeightIn = Y2 - Y1 - 4;


}
