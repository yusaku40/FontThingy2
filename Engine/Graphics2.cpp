#include "Graphics2.h"




void DrawFatRect(Graphics & gfx, int x1, int y1,int x2,int y2, Color c)
{
	///top line
	gfx.DrawLine(x1,y1,x2,y1, c);
	gfx.DrawLine(x1,y1+1,x2,y1+1,c);
	///left line
	gfx.DrawLine(x1, y1, x1, y2, c);
	gfx.DrawLine(x1+1, y1, x1+1, y2, c);
	///Right Line
	gfx.DrawLine(x2, y1, x2, y2, c);
	gfx.DrawLine(x2-1, y1, x2-1, y2, c);
	///Bottom Line
	gfx.DrawLine(x1, y2, x2, y2, c);
	gfx.DrawLine(x1, y2-1, x2, y2-1, c);
}
