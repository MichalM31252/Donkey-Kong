extern "C" {
#include "./Platform.h"
#include "./PlatformHolder.h"
}

void initPlatformHolder(PlatformHolder* platformHolder) {	
	platformHolder->platforms = new Platform[MAXIMUM_AMOUNT_OF_PLATFORMS]; // this is the reason why platforms are not pointers
	platformHolder->numberOfElements = 0; // number of elements currently inside
	platformHolder->sizeOfArray = MAXIMUM_AMOUNT_OF_PLATFORMS;
}

void addPlatform(PlatformHolder* platformHolder, Platform* platform) { // this doesn't work
	if (platformHolder->numberOfElements == platformHolder->sizeOfArray) {
		Platform* temp = new Platform[platformHolder->sizeOfArray];
		
		for (int i = 0; i < platformHolder->numberOfElements; i++) {
			temp[i] = platformHolder->platforms[i];
		}

		delete[] platformHolder->platforms;

		platformHolder->platforms = temp;
		platformHolder->sizeOfArray *= 2;
	}
	platformHolder->platforms[platformHolder->numberOfElements] = *platform;
	platformHolder->numberOfElements++;
}

void emptyPlatformHolder(PlatformHolder* platformHolder) {
	delete[] platformHolder->platforms;
}