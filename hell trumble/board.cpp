/*****************************
	 Implementation of Board Class
******************************/
#include "board.hpp"
#include "textureconst.hpp"

/*Board::Board() {
	//DrawTriangles();
}

void Board::Draw() {

	SDL_Rect Board_Dest = { 0,0,Display::Width,Display::Height };
	//SDL_Rect Red_Triangle_Down = {BOARD_BOARDER_OFFSET,BOARD_BOARDER_OFFSET,TRIANGLE_WIDTH,TRIANGLE_HEIGHT};
	SDL_Rect Triangle_Up = { BOARD_BOARD_OFFSET,BOARD_BOARD_OFFSET,TRIANGLE_WIDTH,TRIANGLE_HEIGHT };
	SDL_Rect Triangle_Down = { BOARD_BOARD_OFFSET,BOARD_BOARD_OFFSET,TRIANGLE_WIDTH,TRIANGLE_HEIGHT };

	SDL_Texture* Red_Up = TextureManager::Images[R_TRIANGLE_UP];
	SDL_Texture* Red_Down = TextureManager::Images[R_TRIANGLE_DOWN];
	SDL_Texture* White_Up = TextureManager::Images[W_TRIANGLE_UP];
	SDL_Texture* White_Down = TextureManager::Images[W_TRIANGLE_DOWN];

	int toptriangleposx[12] = { NULL };

	for (int top = 0; top < 12; top++) {

		int xpos = 34 + TRIANGLE_WIDTH * top;
		int chipx = 34 + TRIANGLE_WIDTH * top - 32;
		int chipy = Display::Height - BOARD_BOARD_OFFSET - TRIANGLE_HEIGHT;
		SDL_Rect chip = { BOARD_BOARD_OFFSET + 16,32,64,64 };



		if (top > 5) {
			xpos += 34;
		}
		Triangle_Down.x = xpos;

		if (top % 2 == 0) {
			Display::DrawTexture(TextureManager::Images[R_TRIANGLE_DOWN], Triangle_Down);
			toptriangleposx[top] = xpos;
		}
		else {
			Display::DrawTexture(TextureManager::Images[W_TRIANGLE_DOWN], Triangle_Down);
			toptriangleposx[top] = xpos;
		}

	}


	int ypos = Display::Height - BOARD_BOARD_OFFSET - TRIANGLE_HEIGHT;
	Triangle_Down.y = ypos;

	for (int bottom = 0; bottom < 12; bottom++) {
		int xpos = 34 + TRIANGLE_WIDTH * bottom;

		if (bottom > 5) {
			xpos += 34;
		}
		Triangle_Down.x = xpos;

		if (bottom % 2 == 0) {
			Display::DrawTexture(TextureManager::Images[R_TRIANGLE_UP], Triangle_Down);
		}

		else {
			Display::DrawTexture(TextureManager::Images[W_TRIANGLE_UP], Triangle_Down);
		}
	}

}
*/