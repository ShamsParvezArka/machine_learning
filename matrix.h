#ifndef MATRIX_H_
#define MATRIX_H_

#pragma once

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

typedef struct Mat {
	size_t rows;
	size_t cols;
	float *es;
} Mat;

#define MAT_AT(m, i, j) (m).es[(i)*(m).cols + (j)]

Mat mat_alloc(size_t rows, size_t cols);
void mat_rand(Mat m, float low, float high);
void mat_print(Mat m);
void mat_dot(Mat dst, Mat a, Mat b);
void mat_fill(Mat m, float n);
float randf(float low, float high);

#endif // MATRIX_H_

#ifndef MATRIX_IMPLEMENTATION

Mat mat_alloc(size_t rows, size_t cols) 
{
	Mat m;
	m.rows = rows;
	m.cols = cols;
	m.es = malloc(sizeof(*m.es)*rows*cols);
	assert(m.es != NULL);

	return m;
}

float randf(float low, float high)
{
	return (float) rand() / (float) RAND_MAX;
}

void mat_rand(Mat m, float low, float high)
{
	for (int i = 0; i < m.rows; i++) {
		for (int j = 0; j < m.cols; j++) {
			MAT_AT(m, i, j) = randf(1, 10)*(high - low) + low;
		}
	}
}

void mat_print(Mat m)
{
	for (int i = 0; i < m.rows; i++) {
		for (int j = 0; j < m.cols; j++) {
			printf("%f ", MAT_AT(m, i, j));
		}
		printf("\n");
	}

	(void) m;
}

void mat_dot(Mat dst, Mat a, Mat b)
{
	assert(a.cols == b.rows);
	size_t inner_size = a.cols;
	assert(dst.rows == a.rows);
	assert(dst.cols == b.cols);

	for (int i = 0; i < dst.rows; i++) {
		for (int j = 0; j < dst.cols; j++) {
			for (int k = 0; k < inner_size; k++) {
				MAT_AT(dst, i, j) += MAT_AT(a, i, k)*MAT_AT(b, k, j);
			}
		}
	}

	(void) dst;
}

void mat_fill(Mat m, float n)
{
	for (int i = 0; i < m.rows; i++) {
		for (int j = 0; j < m.cols; j++) {
			MAT_AT(m, i, j) = n;
		}
	}
}

#endif // MATRIX_IMPLEMENTATION
