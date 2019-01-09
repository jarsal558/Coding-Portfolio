//
// Function randInt
//

int randInt(int loBound, int hiBound) {

	int intervalSize;
	int randomOffset;
	int value;

	intervalSize = (hiBound - loBound) + 1;

	randomOffset = rand() % intervalSize;
	value = loBound + randomOffset;

	return value;

} // end randInt