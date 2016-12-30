/****************************************************************************************** 
Font Lib test

 ******************************************************************************************/
#include "Font.h"
#include "Utilies.h"
#include "Graphics.h"

Font::Font()	
{
	
}

Line::Line()
{
}

Line::Line(Vec2 a, Vec2 b)
{
	this->vtx1 = a;
	this->vtx2 = b;
}

Glyph2::Glyph2(int lcount)
{
	this->linecount = lcount;
	
}

GlyphVector::GlyphVector(int lcount)
{
	this->linecount = lcount;
}


bool Font::PrintGlyph(Graphics& gRef,int glyph,int startX,int startY,Color color )
{
	GlyphVector g(4);
	Glyph2 g2(5);

	int S = 2;
	
	if (glyph < 123 && glyph >96) {		// convert lower case to Upper case for now
		glyph = glyph - 32;
	}

	switch (glyph){
		case 48 :	// 0
			g.linecount = 5;
			g.points[0] = { startX, startY };
			g.points[1] = { startX, startY - 10 };
			g.points[2] = { startX + 6, startY - 10 };
			g.points[3] = { startX + 6, startY };
			g.points[4] = { startX + 1, startY };
			g.points[5] = { startX + 6, startY - 10 };

			for (int i = 0; i < g.linecount; i++) {
				gRef.DrawLine(g.points[i].x, g.points[i].y, g.points[i + 1].x, g.points[i + 1].y, color);
			}
			return true;
			break;
		case 49:	// 1
			g.linecount = 1;
			g.points[0] = { startX +3, startY };
			g.points[1] = { startX + 3, startY - 10 };

			for (int i = 0; i < g.linecount; i++) {
				gRef.DrawLine(g.points[i].x, g.points[i].y, g.points[i + 1].x, g.points[i + 1].y, color);
			}
			return true;
			break;

		case 50:	//  2
			g.linecount = 4;
			g.points[0] = { startX , startY - 9 };
			g.points[1] = { startX +3 , startY - 10 };
			g.points[2] = { startX +6 , startY - 8 };
			g.points[3] = { startX , startY  };
			g.points[4] = { startX + 6 , startY  };
			for (int i = 0; i < g.linecount; i++) {
				gRef.DrawLine(g.points[i].x, g.points[i].y, g.points[i + 1].x, g.points[i + 1].y, color);
			}
			return true;
			break;
		case 51:	//  3
			g.linecount = 6;
			g.points[0] = { startX , startY};
			g.points[1] = { startX + 6 , startY };
			g.points[2] = { startX + 6 , startY -4 };
			g.points[3] = { startX , startY -5};
			g.points[4] = { startX + 6 , startY-6 };
			g.points[5] = { startX + 6 , startY -9 };
			g.points[6] = { startX  , startY -10 };
			for (int i = 0; i < g.linecount; i++) {
				gRef.DrawLine(g.points[i].x, g.points[i].y, g.points[i + 1].x, g.points[i + 1].y, color);
			}
			return true;
			break;

		case 52:	// 4
			g.linecount = 3;
			g.points[0] = { startX +4 , startY };
			g.points[1] = { startX +4 , startY -10 };
			g.points[2] = { startX  , startY - 3 };
			g.points[3] = { startX +6  , startY - 3 };
			for (int i = 0; i < g.linecount; i++) {
				gRef.DrawLine(g.points[i].x, g.points[i].y, g.points[i + 1].x, g.points[i + 1].y, color);
			}
			return true;
			break;

		case 53:	// 5
			g.linecount = 4;
			g.points[0] = { startX  , startY };
			g.points[1] = { startX + 6 , startY - 3 };
			g.points[2] = { startX  , startY - 5 };
			g.points[3] = { startX   , startY -10 };
			g.points[4] = { startX +6  , startY -10 };
			for (int i = 0; i < g.linecount; i++) {
				gRef.DrawLine(g.points[i].x, g.points[i].y, g.points[i + 1].x, g.points[i + 1].y, color);
			}
			return true;
			break;

		case 54:	// 6
			g.linecount = 7;
			g.points[0] = { startX +6  , startY -8   };
			g.points[1] = { startX + 3 , startY - 9 };
			g.points[2] = { startX     , startY - 7  };
			g.points[3] = { startX     , startY - 4  };
			g.points[4] = { startX + 1 , startY      };
			g.points[5] = { startX + 4 , startY      };
			g.points[6] = { startX +6  , startY - 4  };
			g.points[7] = { startX     , startY - 4  };
			for (int i = 0; i < g.linecount; i++) {
				gRef.DrawLine(g.points[i].x, g.points[i].y, g.points[i + 1].x, g.points[i + 1].y, color);
			}
			return true;
			break;


		case 55:	// 7
			g.linecount = 2;
			g.points[0] = { startX  , startY -9 };
			g.points[1] = { startX + 6 , startY - 9 };
			g.points[2] = { startX +3 , startY  };
			for (int i = 0; i < g.linecount; i++) {
				gRef.DrawLine(g.points[i].x, g.points[i].y, g.points[i + 1].x, g.points[i + 1].y, color);
			}
			return true;
			break;

		case 56:	// 8
			g.linecount = 6;
			g.points[0] = { startX + 0 , startY  };
			g.points[1] = { startX + 0 , startY - 9 };
			g.points[2] = { startX + 6 , startY -9 };
			g.points[3] = { startX + 6 , startY };
			g.points[4] = { startX + 0 , startY };
			g.points[5] = { startX + 0 , startY - 5 };
			g.points[6] = { startX + 6 , startY - 5 };
			for (int i = 0; i < g.linecount; i++) {
				gRef.DrawLine(g.points[i].x, g.points[i].y, g.points[i + 1].x, g.points[i + 1].y, color);
			}
			return true;
			break;

		case 57:	// 9
			g.linecount = 6;
			g.points[0] = { startX + 0, startY - 0 };
			g.points[1] = { startX + 3, startY - 0 };
			g.points[2] = { startX + 6, startY - 4 };
			g.points[3] = { startX + 6, startY - 9 };
			g.points[4] = { startX + 0, startY - 9 };
			g.points[5] = { startX + 0, startY - 4 };
			g.points[6] = { startX + 6, startY - 4 };
			for (int i = 0; i < g.linecount; i++) {
				gRef.DrawLine(g.points[i].x, g.points[i].y, g.points[i + 1].x, g.points[i + 1].y, color);
			}
			return true;
			break;

		case 58 :	// :
			g.linecount = 1;
			g.points[0] = { startX + 3 , startY -2 };
			g.points[1] = { startX + 3 , startY - 4 };
			for (int i = 0; i < g.linecount; i++) {
				gRef.DrawLine(g.points[i].x, g.points[i].y, g.points[i + 1].x, g.points[i + 1].y, color);
			}
			g.points[0] = { startX + 3 , startY - 6 };
			g.points[1] = { startX + 3 , startY - 8 };
			for (int i = 0; i < g.linecount; i++) {
				gRef.DrawLine(g.points[i].x, g.points[i].y, g.points[i + 1].x, g.points[i + 1].y, color);
			}
			return true;
			break;

		case 65 :// cap A
			gRef.DrawLine(startX, startY, startX + 3, startY - 10, color);
			gRef.DrawLine(startX + 1, startY, startX + 4, startY - 10, color);
			gRef.DrawLine(startX + 3, startY - 10, startX + 6, startY , color);
			gRef.DrawLine(startX + 4, startY - 10, startX + 7, startY, color);
			gRef.DrawLine(startX + 2, startY - 2, startX + 5,startY - 2, color);
			return true;
			break;
		case 66 :  // B
			gRef.DrawLine(startX, startY, startX , startY - 10, color);
			gRef.DrawLine(startX + 1, startY, startX+1, startY - 10, color);
			gRef.DrawLine(startX , startY - 10, startX + 5, startY - 10, color);
			gRef.DrawLine(startX + 5, startY -10, startX + 5, startY - 5, color);
			gRef.DrawLine(startX + 5, startY -5, startX, startY - 5, color);
			gRef.DrawLine(startX + 5, startY - 5, startX + 5, startY, color);
			gRef.DrawLine(startX + 5, startY, startX, startY , color);
			
			return true;
			break;
		case 67 : //  C
			gRef.DrawLine(startX , startY, startX + 5, startY, color);
			gRef.DrawLine(startX , startY, startX, startY - 10, color);
			gRef.DrawLine(startX, startY -10, startX + 5, startY - 10, color);
			return true;
			break;
		case 68 : //  D
			g.linecount = 5;
			g.points[0] = {startX, startY };
			g.points[1] = {startX, startY - 10 };
			g.points[2] = { startX + 6, startY- 10 };
			g.points[3] = { startX + 6, startY };
			g.points[4] = { startX + 1, startY };
			g.points[5] = { startX + 1, startY - 10};
			for (int i = 0; i < g.linecount;i++) {
				gRef.DrawLine(g.points[i].x, g.points[i].y, g.points[i + 1].x, g.points[i + 1].y, color);
			}
			return true;
			break;

		case 69 :	//  E
			g2.linecount = 4;
			g2.lines[0].vtx1 = Vec2(startX, startY);
			g2.lines[0].vtx2 = { startX + 0,startY - 9 };
			g2.lines[1].vtx1 = { startX + 0,startY - 9 };
			g2.lines[1].vtx2 = { startX + 6,startY - 9 };
			g2.lines[2].vtx1 = { startX + 6,startY - 5 };
			g2.lines[2].vtx2 = { startX + 0,startY - 5 };
			g2.lines[3].vtx1 = { startX + 6,startY - 0 };
			g2.lines[3].vtx2 = { startX + 0,startY - 0 };
			for (int i = 0; i < g2.linecount;i++){
				gRef.DrawLine(g2.lines[i].vtx1, g2.lines[i].vtx2, color);
			}
			return true;
			break;

		case 70:	//  F
			g2.linecount = 3;
			g2.lines[0].vtx1 = {startX + 0, startY + 0 };
			g2.lines[0].vtx2 = {startX + 0, startY - 9 };
			g2.lines[1].vtx1 = {startX + 0, startY - 9 };
			g2.lines[1].vtx2 = {startX + 6, startY - 9 };
			g2.lines[2].vtx1 = {startX + 6, startY - 5 };
			g2.lines[2].vtx2 = {startX + 0, startY - 5 };
			for (int i = 0; i < g2.linecount; i++) {
				gRef.DrawLine(g2.lines[i].vtx1, g2.lines[i].vtx2, color);
			}
			return true;
			break;

		case 71:	//  G
			g2.linecount = 5;
			g2.lines[0].vtx1 = { startX + 0 , startY + 0};
			g2.lines[0].vtx2 = { startX + 0 , startY - 9};
			g2.lines[1].vtx1 = { startX + 0 , startY - 9};
			g2.lines[1].vtx2 = { startX + 6 , startY - 9};
			g2.lines[2].vtx1 = { startX + 6 , startY - 4};
			g2.lines[2].vtx2 = { startX + 2 , startY - 4};
			g2.lines[3].vtx1 = { startX + 6 , startY - 4};
			g2.lines[3].vtx2 = { startX + 6 , startY - 0};
			g2.lines[4].vtx1 = { startX + 6 , startY - 0};
			g2.lines[4].vtx2 = { startX + 0 , startY - 0};

			for (int i = 0; i < g2.linecount; i++) {
				gRef.DrawLine(g2.lines[i].vtx1, g2.lines[i].vtx2, color);
			}
			return true;
			break;

		case 72:	//  H
			g2.linecount = 3;
			g2.lines[0].vtx1 = { startX + 0  , startY + 0 };
			g2.lines[0].vtx2 = { startX + 0  , startY - 9 };
			g2.lines[1].vtx1 = { startX + 0  , startY - 5 };
			g2.lines[1].vtx2 = { startX + 6  , startY - 5 };
			g2.lines[2].vtx1 = { startX + 6  , startY - 0 };
			g2.lines[2].vtx2 = { startX + 6  , startY - 9 };
			for (int i = 0; i < g2.linecount; i++) {
				gRef.DrawLine(g2.lines[i].vtx1, g2.lines[i].vtx2, color);
			}
			return true;
			break;

		case 73:	//  I
			g2.linecount = 3;
			g2.lines[0].vtx1 = { startX + 0  , startY + 0 };
			g2.lines[0].vtx2 = { startX + 6  , startY - 0 };
			g2.lines[1].vtx1 = { startX + 3  , startY - 0 };
			g2.lines[1].vtx2 = { startX + 3  , startY - 9 };
			g2.lines[2].vtx1 = { startX + 0  , startY - 9 };
			g2.lines[2].vtx2 = { startX + 6  , startY - 9 };
			for (int i = 0; i < g2.linecount; i++) {
				gRef.DrawLine(g2.lines[i].vtx1, g2.lines[i].vtx2, color);
			}
			return true;
			break;

		case 74:	//  J
			g2.linecount = 4;
			g2.lines[0].vtx1 = { startX + 0  , startY - 9 };
			g2.lines[0].vtx2 = { startX + 6  , startY - 9 };
			g2.lines[1].vtx1 = { startX + 4  , startY - 9 };
			g2.lines[1].vtx2 = { startX + 4  , startY - 2 };
			g2.lines[2].vtx1 = { startX + 4  , startY - 2 };
			g2.lines[2].vtx2 = { startX + 2  , startY - 0 };
			g2.lines[3].vtx1 = { startX + 2  , startY - 0 };
			g2.lines[3].vtx2 = { startX + 0  , startY - 2 };
			for (int i = 0; i < g2.linecount; i++) {
				gRef.DrawLine(g2.lines[i].vtx1, g2.lines[i].vtx2, color);
			}
			return true;
			break;

		case 75:	//  K
			g2.linecount = 3;
			g2.lines[0].vtx1 = { startX + 0  , startY - 0 };
			g2.lines[0].vtx2 = { startX + 0  , startY - 9 };
			g2.lines[1].vtx1 = { startX + 0  , startY - 5 };
			g2.lines[1].vtx2 = { startX + 6  , startY - 9 };
			g2.lines[2].vtx1 = { startX + 0  , startY - 5 };
			g2.lines[2].vtx2 = { startX + 6  , startY - 0 };
			for (int i = 0; i < g2.linecount; i++) {
				gRef.DrawLine(g2.lines[i].vtx1, g2.lines[i].vtx2, color);
			}
			return true;
			break;

		case 76:	//  L
			g2.linecount = 2;
			g2.lines[0].vtx1 = { startX + 0  , startY - 0 };
			g2.lines[0].vtx2 = { startX + 0  , startY - 9 };
			g2.lines[1].vtx1 = { startX + 0  , startY - 0 };
			g2.lines[1].vtx2 = { startX + 6  , startY - 0 };
			for (int i = 0; i < g2.linecount; i++) {
				gRef.DrawLine(g2.lines[i].vtx1, g2.lines[i].vtx2, color);
			}
			return true;
			break;

		case 77:	//  M
			g2.linecount = 4;
			g2.lines[0].vtx1 = { startX + 0  , startY - 0 };
			g2.lines[0].vtx2 = { startX + 0  , startY - 9 };
			g2.lines[1].vtx1 = { startX + 0  , startY - 9 };
			g2.lines[1].vtx2 = { startX + 3  , startY - 5 };
			g2.lines[2].vtx1 = { startX + 3  , startY - 5 };
			g2.lines[2].vtx2 = { startX + 6  , startY - 9 };
			g2.lines[3].vtx1 = { startX + 6  , startY - 9 };
			g2.lines[3].vtx2 = { startX + 6  , startY - 0 };
			for (int i = 0; i < g2.linecount; i++) {
				gRef.DrawLine(g2.lines[i].vtx1, g2.lines[i].vtx2, color);
			}
			return true;
			break;

		case 78:	//  N
			g2.linecount = 3;
			g2.lines[0].vtx1 = { startX + 0  , startY - 0 };
			g2.lines[0].vtx2 = { startX + 0  , startY - 9 };
			g2.lines[1].vtx1 = { startX + 0  , startY - 9 };
			g2.lines[1].vtx2 = { startX + 6  , startY - 0 };
			g2.lines[2].vtx1 = { startX + 6  , startY - 0 };
			g2.lines[2].vtx2 = { startX + 6  , startY - 9 };
			for (int i = 0; i < g2.linecount; i++) {
				gRef.DrawLine(g2.lines[i].vtx1, g2.lines[i].vtx2, color);
			}
			return true;
			break;

		case 79:	//  O
			g2.linecount = 4;
			g2.lines[0].vtx1 = { startX + 0  , startY - 0 };
			g2.lines[0].vtx2 = { startX + 0  , startY - 9 };
			g2.lines[1].vtx1 = { startX + 0  , startY - 9 };
			g2.lines[1].vtx2 = { startX + 6  , startY - 9 };
			g2.lines[2].vtx1 = { startX + 6  , startY - 9 };
			g2.lines[2].vtx2 = { startX + 6  , startY - 0 };
			g2.lines[3].vtx1 = { startX + 6  , startY - 0 };
			g2.lines[3].vtx2 = { startX + 0  , startY - 0 };
			for (int i = 0; i < g2.linecount; i++) {
				gRef.DrawLine(g2.lines[i].vtx1, g2.lines[i].vtx2, color);
			}
			return true;
			break;

		case 80:	//  P
			g2.linecount = 4;
			g2.lines[0].vtx1 = { startX + 0  , startY + 0 };
			g2.lines[0].vtx2 = { startX + 0  , startY - 9 };
			g2.lines[1].vtx1 = { startX + 0  , startY - 9 };
			g2.lines[1].vtx2 = { startX + 6  , startY - 9 };
			g2.lines[2].vtx1 = { startX + 6  , startY - 9 };
			g2.lines[2].vtx2 = { startX + 6  , startY - 5 };
			g2.lines[3].vtx1 = { startX + 6  , startY - 5 };
			g2.lines[3].vtx2 = { startX + 0  , startY - 5 };
			for (int i = 0; i < g2.linecount; i++) {
				gRef.DrawLine(g2.lines[i].vtx1, g2.lines[i].vtx2, color);
			}
			return true;
			break;

		case 81:	//  Q
			g2.linecount = 5;
			g2.lines[0].vtx1 = { startX + 0  , startY - 0 };
			g2.lines[0].vtx2 = { startX + 0  , startY - 9 };
			g2.lines[1].vtx1 = { startX + 0  , startY - 9 };
			g2.lines[1].vtx2 = { startX + 5  , startY - 9 };
			g2.lines[2].vtx1 = { startX + 5  , startY - 9 };
			g2.lines[2].vtx2 = { startX + 5  , startY - 0 };
			g2.lines[3].vtx1 = { startX + 5  , startY - 0 };
			g2.lines[3].vtx2 = { startX + 0  , startY - 0 };
			g2.lines[4].vtx1 = { startX + 3  , startY - 5 };
			g2.lines[4].vtx2 = { startX + 7  , startY - 1 };
			for (int i = 0; i < g2.linecount; i++) {
				gRef.DrawLine(g2.lines[i].vtx1, g2.lines[i].vtx2, color);
			}
			return true;
			break;

		case 82:	//  R
			g2.linecount = 5;
			g2.lines[0].vtx1 = { startX + 0  , startY - 0 };
			g2.lines[0].vtx2 = { startX + 0  , startY - 9 };
			g2.lines[1].vtx1 = { startX + 0  , startY - 9 };
			g2.lines[1].vtx2 = { startX + 6  , startY - 9 };
			g2.lines[2].vtx1 = { startX + 6  , startY - 9 };
			g2.lines[2].vtx2 = { startX + 6  , startY - 5 };
			g2.lines[3].vtx1 = { startX + 6  , startY - 5 };
			g2.lines[3].vtx2 = { startX + 0  , startY - 5 };
			g2.lines[4].vtx1 = { startX + 0  , startY - 5 };
			g2.lines[4].vtx2 = { startX + 6  , startY - 0 };
			for (int i = 0; i < g2.linecount; i++) {
				gRef.DrawLine(g2.lines[i].vtx1, g2.lines[i].vtx2, color);
			}
			return true;
			break;

		case 83:	//  S
			g2.linecount = 3;
			g2.lines[0].vtx1 = { startX + 0  , startY + 0 };
			g2.lines[0].vtx2 = { startX + 6  , startY - 0 };
			g2.lines[1].vtx1 = { startX + 6  , startY - 0 };
			g2.lines[1].vtx2 = { startX + 0  , startY - 9 };
			g2.lines[2].vtx1 = { startX + 0  , startY - 9 };
			g2.lines[2].vtx2 = { startX + 6  , startY - 9 };
			for (int i = 0; i < g2.linecount; i++) {
				gRef.DrawLine(g2.lines[i].vtx1, g2.lines[i].vtx2, color);
			}
			return true;
			break;

		case 84:	//  T
			g2.linecount = 2;
			g2.lines[0].vtx1 = { startX + 3  , startY + 0 };
			g2.lines[0].vtx2 = { startX + 3  , startY - 9 };
			g2.lines[1].vtx1 = { startX + 0  , startY - 9 };
			g2.lines[1].vtx2 = { startX + 6  , startY - 9 };
			for (int i = 0; i < g2.linecount; i++) {
				gRef.DrawLine(g2.lines[i].vtx1, g2.lines[i].vtx2, color);
			}
			return true;
			break;

		case 85:	//  U
			g2.linecount = 3;
			g2.lines[0].vtx1 = { startX + 0  , startY + 0 };
			g2.lines[0].vtx2 = { startX + 0  , startY - 9 };
			g2.lines[1].vtx1 = { startX + 0  , startY - 0 };
			g2.lines[1].vtx2 = { startX + 6  , startY - 0 };
			g2.lines[2].vtx1 = { startX + 6  , startY - 0 };
			g2.lines[2].vtx2 = { startX + 6  , startY - 9 };
			for (int i = 0; i < g2.linecount; i++) {
				gRef.DrawLine(g2.lines[i].vtx1, g2.lines[i].vtx2, color);
			}
			return true;
			break;

		case 86:	//  V
			g2.linecount = 2;
			g2.lines[0].vtx1 = { startX + 3  , startY + 0 };
			g2.lines[0].vtx2 = { startX + 0  , startY - 9 };
			g2.lines[1].vtx1 = { startX + 3  , startY - 0 };
			g2.lines[1].vtx2 = { startX + 6  , startY - 9 };
			for (int i = 0; i < g2.linecount; i++) {
				gRef.DrawLine(g2.lines[i].vtx1, g2.lines[i].vtx2, color);
			}
			return true;
			break;

		case 87:	//  W
			g2.linecount = 4;
			g2.lines[0].vtx1 = { startX + 0  , startY - 9 };
			g2.lines[0].vtx2 = { startX + 0  , startY - 0 };
			g2.lines[1].vtx1 = { startX + 0  , startY - 0 };
			g2.lines[1].vtx2 = { startX + 3  , startY - 4 };
			g2.lines[2].vtx1 = { startX + 3  , startY - 4 };
			g2.lines[2].vtx2 = { startX + 6  , startY - 0 };
			g2.lines[3].vtx1 = { startX + 6  , startY - 0 };
			g2.lines[3].vtx2 = { startX + 6  , startY - 9 };
			for (int i = 0; i < g2.linecount; i++) {
				gRef.DrawLine(g2.lines[i].vtx1, g2.lines[i].vtx2, color);
			}
			return true;
			break;

		case 88 :	//  X
			g.linecount = 4;
			g.points[0] = { startX, startY };
			g.points[1] = { startX + 6, startY - 10 };
			g.points[2] = { startX + 3, startY -5 };
			g.points[3] = { startX , startY -10 };
			g.points[4] = { startX + 6 , startY  };
			for (int i = 0; i < g.linecount; i++) {
				gRef.DrawLine(g.points[i].x, g.points[i].y, g.points[i + 1].x, g.points[i + 1].y, color);
			}
			return true;
			break;

		case 89:	//  Y
			g.linecount = 4;
			g.points[0] = { startX + 3, startY };
			g.points[1] = { startX + 3, startY - 5 };
			g.points[2] = { startX , startY - 10 };
			g.points[3] = { startX + 3, startY - 5 };
			g.points[4] = { startX + 6 , startY - 10 };
			for (int i = 0; i < g.linecount; i++) {
				gRef.DrawLine(g.points[i].x, g.points[i].y, g.points[i + 1].x, g.points[i + 1].y, color);
			}
			return true;
			break;

		case 90:	//  Z
			g2.linecount = 3;
			g2.lines[0].vtx1 = { startX + 0  , startY - 9 };
			g2.lines[0].vtx2 = { startX + 6  , startY - 9 };
			g2.lines[1].vtx1 = { startX + 6  , startY - 9 };
			g2.lines[1].vtx2 = { startX + 0  , startY - 0 };
			g2.lines[2].vtx1 = { startX + 0  , startY - 0 };
			g2.lines[2].vtx2 = { startX + 6  , startY - 0 };
			for (int i = 0; i < g2.linecount; i++) {
				gRef.DrawLine(g2.lines[i].vtx1, g2.lines[i].vtx2, color);
			}
			return true;
			break;

		default:
			return false;
			
	}
		
	
	
	
}

void Font::PrintS(Graphics & gfx, const char * text, int X, int Y, Color color)
{
	for (int i = 0; i <= strlen(text); i++) {
		if ((X + i * 10) < gfx.ScreenWidth - 10) {
			PrintGlyph(gfx, text[i], X + (i * 10), Y, color);
		}
		
	}
}

void Font::PrintRect(Graphics& gfx, tRect& tr) {
	
	int xPos = tr.llCorner.x;
	int yPos = tr.llCorner.y;

	Color tempC;
	tempC.SetA(255);
	tempC.SetR(255);
	tempC.SetG(255);
	tempC.SetB(255);

	for (int i = 0; i <= strlen(tr.data); i++) {
		if (tr.data[i] = 13) {
			yPos = yPos + 10;
		}
		PrintGlyph(gfx, tr.data[i], xPos, yPos, tempC);
	}
}
