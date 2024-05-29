#include "colors.h"
#include <vector>

const Color emptyCellColor = Color{ 19, 153, 130, 255 }; // Light green
const Color redColor = Color{ 245, 126, 118, 255 };
const Color pinkColor = Color{ 245, 118, 241, 255 };
const Color blueColor = Color{ 122, 118, 245, 255 };
const Color greenColor = Color{ 107, 245, 126, 255 };
const Color yellowColor = Color{ 245, 228, 102, 255 };
const Color orangeColor = Color{ 245, 177, 86, 255 };
const Color tealColor = Color{ 99, 244, 244, 255 };

std::vector<Color> GetCellColors() {
	return { emptyCellColor, redColor, pinkColor, blueColor, greenColor, yellowColor, orangeColor, tealColor };
}