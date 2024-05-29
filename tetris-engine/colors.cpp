#include "colors.h"
#include <vector>

const Color emptyCellColor = Color{ 19, 153, 130, 255 }; // Light green
const Color redColor = Color{ 245, 126, 118, 255 };
const Color pinkColor = Color{ 245, 118, 241, 255 };
const Color blueColor = Color{ 122, 118, 245, 255 };

std::vector<Color> GetCellColors() {
	return { emptyCellColor, redColor, pinkColor, blueColor };
}