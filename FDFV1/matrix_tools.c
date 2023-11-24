#include "fdf.h"

void compilation_matrix(double comp[3][3], double R[3][3], double R3[3][3])
{
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			comp[i][j] = 0;
		}
	}

	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			for (int k = 0; k < 3; ++k) {
				comp[i][j] += R[i][k] * R3[k][j];
			}
		}
	}
}