#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h> 

typedef struct point {
	double x;
	double y;
} point;

int cx(const void *_a, const void *_b) {
	point *a = (point*)_a;
	point *b = (point*)_b;
	return a->x - b->x;
} 

int cy(const void *_a, const void *_b) {
	point *a = (point*)_a;
	point *b = (point*)_b;
	return a->y - b->y;
}


double distant(point i, point j) {
	return sqrt(pow(i.x - j.x, 2) + pow(j.y - i.y, 2));
}

double piar(point *points, int start, int end) {
	double d = INT_MAX;
	if (start == end) {
		return d;	
	}
	if (start + 1 == end) {
		return distant(points[start], points[end]);
	}
	int mid = (start + end) / 2;
	double d1 = piar(points, start, mid);
	double d2 = piar(points, mid + 1, end);
	d = fmin(d1, d2);
	point temp[end - start + 1];
	int top = 0;
	for (int i = start; i <= end; ++i) {
		if (abs(points[i].x - points[mid].x) < d) {
			temp[top++] = points[i];
		} 
	}
	qsort(temp, top, sizeof(point), cy);
	for (int i = 0; i < top - 1; ++i) {
		for (int j = i + 1; j < top; ++j) {
			if (abs(points[i].y - points[j].y) < d) {
				double d3 = distant(points[i], points[j]);
				if (d3 < d) {
					d = d3;
				}
			}
		}
	}
	return d;
}

int main() {
	int n;
	printf("请输入点的数量：");
	scanf("%d", &n);
	point points[n];
	for (int i = 0; i < n; ++i) {
		printf("请输入x和y坐标: ");
		scanf("%lf%lf", &points[i].x,&points[i].y); 
	}
	qsort(points, n, sizeof(point), cx);
	printf("最小的距离为: %.2f", piar(points, 0, n - 1));
	return 0; 
}

