#include "header.h"
int makingMiniGameTiles(sPosition s, int x) {
	for (int i = 0; i < x; i++) {
		s->nextStog = newStog(i);
		mgtPosition help = s->nextStog->firstMGT;
		for (int j = 0; j < x - 1; j++) {
			while (help->brother != NULL) {
				help = help->brother;
			}
			help->brother = newMGT();
		}
		s = s->nextStog;
	}
	return 0;
}