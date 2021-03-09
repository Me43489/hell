#pragma once

/*****************************
	Instance of board class
******************************/
#include <cstdint>
#include <stack>
#include <vector>
#include "space.hpp"
#include "game.hpp"


class Board {
private:
	static const uint32_t SIZE = 144;

public:
	//Space data[SIZE] { 0 };
	std::vector<Space> data;
	std::stack<Space> waitQueue;
	Board();
	void clear();
	void update();
	static void Draw();
};

