#include <stdio.h>
#include <stdlib.h>

#define N 10

int main() {

	srand(time(NULL));
	int matrix[N][N];
	float res[N];
	int num, count = 0;
	FILE* fp = fopen("F1.txt", "w");

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {

			matrix[i][j] = (rand() % N) - N/2;

			fprintf(fp, "%d\t ", matrix[i][j]);
			printf("%d\t ", matrix[i][j]);

		}
		fprintf(fp, "\n");
		printf("\n");
	}
	fclose(fp);
	printf("\n");

	fp = fopen("F1.txt", "r");
	FILE* fs = fopen("F2.txt", "w");

	for (int i = 0; i < N; i++) {
		res[i] = 0;
		count = 0;
		for (int j = 0; j < N; j++) {
			fscanf(fp, "%d", &matrix[i][j]);


			printf("%d\t ", matrix[i][j]);

			if (matrix[j][i] >= 0) {
				count++;
				res[i] += matrix[j][i];
			}
		}

		res[i] = res[i] / count;

		printf("\n");

		


	}

	printf("\nResults are: ");
	fprintf(fs, "Results are: ");

	for (int i = 0; i < N; i++) {

		fprintf(fs, "%.2f\t ", res[i]);
		printf("%.2f ", res[i]);
	}
	printf("\n");
	fclose(fs);

	return 0;
}