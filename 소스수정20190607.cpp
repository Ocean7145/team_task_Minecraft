#define _CRT_SECURE_NO_WARNINGS

#include <CoalaMOD.h>
#pragma comment(lib, "CoalaMOD.lib")

void swap(int* array_x1, int* array_x2);
void makefloor(int array_x1, int array_z1, int array_x2, int array_z2);

void process310(int x, int y, int z, int(*array)[100], double size_darray_x, double size_darray_z, int array_x1, int array_z1);
void process208(int x, int y, int z, int(*array)[100], double size_darray_x, double size_darray_z, int array_x1, int array_z1);
void processground(int x, int y, int z, int(*array)[100], double size_darray_x, double size_darray_z, int array_x1, int array_z1);
void processparkingplace(int x, int y, int z, int(*array)[100], double size_darray_x, double size_darray_z, int array_x1, int array_z1);
void processflower(int x, int y, int z, int(*array)[100], double size_darray_x, double size_darray_z, int array_x1, int array_z1);
void process_kim_lamp(int x, int y, int z, int(*array)[100], double size_darray_x, double size_darray_z, int array_x1, int array_z1);
void process_kim_road_mid(int x, int y, int z, int(*array)[100], double size_darray_x, double size_darray_z, int array_x1, int array_z1);
void process_kim_road_garo(int x, int y, int z, int(*array)[100], double size_darray_x, double size_darray_z, int array_x1, int array_z1);
void process_kim_road_sero(int x, int y, int z, int(*array)[100], double size_darray_x, double size_darray_z, int array_x1, int array_z1);
void process_hong_cauburger(int x, int y, int z, int(*array)[100], double size_darray_x, double size_darray_z, int array_x1, int array_z1);
void process_hong_seven(int x, int y, int z, int(*array)[100], double size_darray_x, double size_darray_z, int array_x1, int array_z1);
void process101(int x, int y, int z, int(*array)[100], double size_darray_x, double size_darray_z, int array_x1, int array_z1);
void processpond(int x, int y, int z, int(*array)[100], double size_darray_x, double size_darray_z, int array_x1, int array_z1);
void process_kim_riceandpotato(int x, int y, int z, int(*array)[100], double size_darray_x, double size_darray_z, int array_x1, int array_z1);

void arrayprintf(int(*array)[100]);
void arraymark(int(*array)[100], int a, int b, int c, int d);

void make310(int x, int y, int z);
void make310_body(int x, int y, int z);
void make310_decorating(int x, int y, int z);
void make310_window(int x, int y, int z);
void make310_eliminating(int x, int y, int z);


void make208(int x, int y, int z);
void make208_body(int x, int y, int z);
void make208_decorating(int x, int y, int z);

void makeground(int x, int y, int z);

void makeparkingplace(int x, int y, int z);

void makeflower(int x, int y, int z);

void make_kim_lamp(int x, int y, int z);

void make_kim_road_mid(int x, int y, int z);
void make_kim_road_garo(int x, int y, int z);
void make_kim_road_sero(int x, int y, int z);

void make_hong_cauburger(int x, int y, int z);
void make_hong_seven(int x, int y, int z);

void make101(int x, int y, int z);

void makepond(int x, int y, int z);
void crtrect(BlockID block, int ex, int ey, int ez, int sx, int sz); //높이 1 직사각형 생성 함수, 매개변수는 좌표 2개
#define SWAP(x, y) { int t = x; x = y; y=t; } // 중간고사 문제에 나왔던 코드
void crtstree(int ex, int ey, int ez); //나무 만드는 함수. 나무 밑동이 기준점임
void crtslight(int ex, int ey, int ez); //등불. 울타리 + 발광석
void stackblock(BlockID block, int ex, int ey, int ez, int height); //수직으로 블록 쌓는 함수, 매개변수는 좌표1개랑 높이(int)

void make_kim_riceandpotato(int x, int y, int z);

int main() {
	int array_x1, array_z1; //마을 크기중 x,z 좌표를 입력받을 변수
	int array_x2, array_z2; //마을 크기중 x,z 좌표를 입력받을 변수

	int array[50][100] = { 0 }; //cmd에서 건물이 설치된 공간을 나타내기위해 배열을 선언하고 0으로 초기화한다.
	int i = 0, j = 0;

	printf("지금 화면은 건물이 놓아진 곳을 xz좌표로 보여주고 있습니다. 위쪽이 북쪽(-z), 오른쪽이 동쪽(+x)입니다.\n");
	printf("빈공간은 l로 표시되고 건물이 생성된 공간은 @로 표시 됩니다.\n");
	//array[100][50]의 요소를 'l'로 초기화한다.
	for (i = 0;i < 50;i++) {
		for (j = 0;j < 100;j++) {
			array[i][j] = 'l';
		}
	}
	arrayprintf(array); //cmd에서 array[50][100]을 출력한다.
	printf("\n");


	//마을의 크기 좌표를 입력받는다.
	printf("마을의 크기는 얼마나 큰가요?\n");
	printf("(x,z),(x,z)좌표를 입력해서 알려주세요.");
	scanf("%d %d %d %d", &array_x1, &array_z1, &array_x2, &array_z2);

	//바닥을 생성한다.
	makefloor(array_x1, array_z1, array_x2, array_z2);

	//값이 작은 것은 array_x1과 array_z1, 값이 작은 것은 array_x2와 array_z2에 들어가게한다.
	if (array_x1 > array_x2)
		swap(&array_x1, &array_x2);
	if (array_z1 > array_z2)
		swap(&array_z1, &array_z2);

	//크기(변화량)를 구한다.
	double darray_x, darray_z;
	darray_x = (double)(array_x2 - array_x1);
	darray_z = (double)(array_z2 - array_z1);

	//배열의에서 한 칸의 크기를 구하기 위해 z는 50(=배열의 행길이)으로 x는 100(=배열의 열길이)으로 나눈다.
	//그리고 그 크기를 저장한다.
	double size_darray_x = darray_x / 100, size_darray_z = darray_z / 50;

	for (;1;) {
		printf("어떤 건물을 짓고 싶나요?\n");
		printf("1. 310관 x %d칸, z %d칸\n", (int)(134 / size_darray_x), (int)(60 / size_darray_z)); //310관 x좌표 크기는 134, z좌표 크기는 60이다
		printf("2. 208관 x %d칸, z %d칸\n", (int)(118 / size_darray_x), (int)(15 / size_darray_z)); //208관 x좌표 크기는 118, z좌표 크기는 15이다
		printf("3. 운동장 x %d칸, z %d칸\n", (int)(75 / size_darray_x), (int)(50 / size_darray_z)); //운동장 x좌표 크기는 75, z좌표 크기는 50이다
		printf("4. 기숙사 앞 주차장 x %d칸, z %d칸 \n", (int)(20 / size_darray_x), (int)(50 / size_darray_z)); // x좌표 크기는 20, z좌표 크기는 50이다
		printf("5. 운동장 앞 화단 x %d칸, z %d칸 \n", (int)(5 / size_darray_x), (int)(30 / size_darray_z)); // x좌표 크기는 5, z좌표 크기는 30이다
		printf("6. 가로등 x %d칸, z %d칸 \n",(int)(3 / size_darray_x), (int)(3 / size_darray_z)); //x좌표 크기는 3, z좌표 크기는 3이다
		printf("7. 도로_교차로 x %d칸, z %d칸 \n", (int)(10 / size_darray_x), (int)(10 / size_darray_z)); //x좌표 크기는 10, z좌표 크기는 10이다
		printf("8. 도로_가로 x %d칸, z %d칸 \n", (int)(60 / size_darray_x), (int)(10 / size_darray_z)); //x좌표 크기는 60, z좌표 크기는 10이다
		printf("9. 도로_세로 x %d칸, z %d칸 \n", (int)(10 / size_darray_x), (int)(60 / size_darray_z)); //x좌표 크기는 10, z좌표 크기는 60이다
		printf("10. 카우버거 x %d칸, z %d칸 \n", (int)(30 / size_darray_x), (int)(30 / size_darray_z)); //x좌표 크기는 10, z좌표 크기는 10이다
		printf("11. 세븐일레븐 x %d칸, z %d칸 \n", (int)(35 / size_darray_x), (int)(35 / size_darray_z)); //x좌표 크기는 35, z좌표 크기는 35이다
		printf("12. 영신관 x %d칸, z %d칸 \n", (int)(54 / size_darray_x), (int)(12 / size_darray_z)); //x좌표 크기는 54, z좌표 크기는 12이다
		printf("13. 청룡연못 x %d칸, z %d칸 \n", (int)(64 / size_darray_x), (int)(55 / size_darray_z)); //x좌표 크기는 64, z좌표 크기는 55이다
		printf("14. 라포 x %d칸, z %d칸 \n ",(int)(35 / size_darray_x), (int)(35 / size_darray_z)); //x좌표 크기는 35, z좌표 크기는 35이다

		printf(" 0. 프로그램 종료 \n");

		int num;
		scanf("%d", &num);


		if (num == 1) {
			printf("좌표를 입력해주세요(x,y,z)");
			int x, y, z;
			scanf("%d %d %d", &x, &y, &z);


			process310(x, y, z, array, size_darray_x, size_darray_z, array_x1, array_z1);

			/*
			make310(x, y, z);
			arraymark(array, (int)(134 / size_darray_x), (int)(60 / size_darray_z), -(int)(array_z1 / size_darray_z) + (int)(z / size_darray_z), -(int)(array_x1 / size_darray_x) + (int)(x / size_darray_x));
			*/
			/*
			for (i = 0;i < (int)(134 / size_darray_x);i++) {
				for (j = 0;j < (int)(60 / size_darray_z);j++) {
					array[-(int)(array_z1 / size_darray_z) + (int)(z / size_darray_z) + j][-(int)(array_x1 / size_darray_x) + (int)(x / size_darray_x) + i] = '@';
				}
			}
			*/
		}

		if (num == 2) {
			printf("좌표를 입력해주세요(x,y,z)");
			int x, y, z;
			scanf("%d %d %d", &x, &y, &z);

			process208(x, y, z, array, size_darray_x, size_darray_z, array_x1, array_z1);

			/*
			make208(x, y, z);
			arraymark(array, (int)(118 / size_darray_x), (int)(15 / size_darray_z), -(int)(array_z1 / size_darray_z) + (int)(z / size_darray_z), -(int)(array_x1 / size_darray_x) + (int)(x / size_darray_x));
			*/
			/*
			for (i = 0;i < (int)(118 / size_darray_x);i++) {
				for (j = 0;j < (int)(15 / size_darray_z);j++) {
					array[-(int)(array_z1 / size_darray_z) + (int)(z / size_darray_z) + j][-(int)(array_x1 / size_darray_x) + (int)(x / size_darray_x) + i] = '@';
				}
			}
			*/
		}

		if (num == 3) {
			printf("좌표를 입력해주세요(x,y,z)");
			int x, y, z;
			scanf("%d %d %d", &x, &y, &z);

			processground(x, y, z, array, size_darray_x, size_darray_z, array_x1, array_z1);
			/*
			makeground(x, y, z);
			arraymark(array, (int)(75 / size_darray_x), (int)(50 / size_darray_z), -(int)(array_z1 / size_darray_z) + (int)(z / size_darray_z), -(int)(array_x1 / size_darray_x) + (int)(x / size_darray_x));
			*/
			/*
			for (i = 0;i < (int)(75 / size_darray_x);i++) {
				for (j = 0;j < (int)(50 / size_darray_z);j++) {
					array[-(int)(array_z1 / size_darray_z) + (int)(z / size_darray_z) + j][-(int)(array_x1 / size_darray_x) + (int)(x / size_darray_x) + i] = '@';
				}
			}
			*/
		}

		if (num == 4) {
			printf("좌표를 입력해주세요(x,y,z)");
			int x, y, z;
			scanf("%d %d %d", &x, &y, &z);
			processparkingplace(x, y, z, array, size_darray_x, size_darray_z, array_x1, array_z1);
			/*
			makeparkingplace(x, y, z);
			arraymark(array, (int)(20 / size_darray_x), (int)(50 / size_darray_z), -(int)(array_z1 / size_darray_z) + (int)(z / size_darray_z), -(int)(array_x1 / size_darray_x) + (int)(x / size_darray_x));
			*/
			/*
			for (i = 0;i < (int)(20 / size_darray_x);i++) {
				for (j = 0;j < (int)(50 / size_darray_z);j++) {
					array[-(int)(array_z1 / size_darray_z) + (int)(z / size_darray_z) + j][-(int)(array_x1 / size_darray_x) + (int)(x / size_darray_x) + i] = '@';
				}
			}
			*/

		}

		if (num == 5) {
			printf("좌표를 입력해주세요(x,y,z)");
			int x, y, z;
			scanf("%d %d %d", &x, &y, &z);
			processflower(x, y, z, array, size_darray_x, size_darray_z, array_x1, array_z1);
			/*
			makeparkingplace(x, y, z);
			arraymark(array, (int)(5 / size_darray_x), (int)(30 / size_darray_z), -(int)(array_z1 / size_darray_z) + (int)(z / size_darray_z), -(int)(array_x1 / size_darray_x) + (int)(x / size_darray_x));
			*/
			/*
			for (i = 0;i < (int)(5 / size_darray_x);i++) {
				for (j = 0;j < (int)(30 / size_darray_z);j++) {
					array[-(int)(array_z1 / size_darray_z) + (int)(z / size_darray_z) + j][-(int)(array_x1 / size_darray_x) + (int)(x / size_darray_x) + i] = '@';
				}
			}
			*/
		}
		if (num == 6) {
			printf("좌표를 입력해주세요(x,y,z)");
			int x, y, z;
			scanf("%d %d %d", &x, &y, &z);
			process_kim_lamp(x, y, z, array, size_darray_x, size_darray_z, array_x1, array_z1);
		}
		if (num == 7) {
			printf("좌표를 입력해주세요(x,y,z)");
			int x, y, z;
			scanf("%d %d %d", &x, &y, &z);
			process_kim_road_mid(x, y, z, array, size_darray_x, size_darray_z, array_x1, array_z1);
		}
		if (num == 8) {
			printf("좌표를 입력해주세요(x,y,z)");
			int x, y, z;
			scanf("%d %d %d", &x, &y, &z);
			process_kim_road_garo(x, y, z, array, size_darray_x, size_darray_z, array_x1, array_z1);
		}
		if (num == 9) {
			printf("좌표를 입력해주세요(x,y,z)");
			int x, y, z;
			scanf("%d %d %d", &x, &y, &z);
			process_kim_road_sero(x, y, z, array, size_darray_x, size_darray_z, array_x1, array_z1);
		}
		if (num == 10) {
			printf("좌표를 입력해주세요(x,y,z)");
			int x, y, z;
			scanf("%d %d %d", &x, &y, &z);
			process_hong_cauburger(x, y, z, array, size_darray_x, size_darray_z, array_x1, array_z1);

		}
		if (num == 11) {
			printf("좌표를 입력해주세요(x,y,z)");
			int x, y, z;
			scanf("%d %d %d", &x, &y, &z);
			process_hong_seven(x, y, z, array, size_darray_x, size_darray_z, array_x1, array_z1);

		}
		if (num == 12) {
			printf("좌표를 입력해주세요(x,y,z)");
			int x, y, z;
			scanf("%d %d %d", &x, &y, &z);
			process101(x, y, z, array, size_darray_x, size_darray_z, array_x1, array_z1);
		}
		if (num == 13) {
			printf("좌표를 입력해주세요(x,y,z)");
			int x, y, z;
			scanf("%d %d %d", &x, &y, &z);
			processpond(x, y, z, array, size_darray_x, size_darray_z, array_x1, array_z1);

		}
		if (num == 14) {
			printf("좌표를 입력해주세요(x,y,z)");
			int x, y, z;
			scanf("%d %d %d", &x, &y, &z);
			process_kim_riceandpotato(x, y, z, array, size_darray_x, size_darray_z, array_x1, array_z1);
		}

		if (num == 0) {
			break;
		}


		//배열을 출력한다.
		arrayprintf(array);


	}

	printf("이용해주셔서 감사합니다");
	return 0;
}




////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void swap(int* array_x1, int* array_x2) {
	int p = 0;
	p = *array_x1;
	*array_x1 = *array_x2;
	*array_x2 = p;
}



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void makefloor(int array_x1, int array_z1, int array_x2, int array_z2) {
	BlockID stone = createBlock(BLOCK_STONE);
	int xx1, yy1, zz1, xx2, yy2, zz2;

	if (array_x1 > array_x2)
		swap(&array_x1, &array_x2);
	if (array_z1 > array_z2)
		swap(&array_z1, &array_z2);
	////
	//밑바닥 설정
	////

	xx1 = array_x1, yy1 = 4, zz1 = array_z1;
	xx2 = array_x2, yy2 = 4, zz2 = array_z2;

	for (; yy1 <= yy2; yy1++) {
		for (; xx1 <= xx2; xx1++) {
			for (; zz1 <= zz2; zz1++) {
				locateBlock(stone, xx1, yy1, zz1);
			}
			zz1 = array_z1;
		}
		xx1 = array_x1;
	}
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void process310(int x, int y, int z, int(*array)[100], double size_darray_x, double size_darray_z, int array_x1, int array_z1) {
	make310(x, y, z);
	arraymark(array, (int)(134 / size_darray_x), (int)(60 / size_darray_z), -(int)(array_z1 / size_darray_z) + (int)(z / size_darray_z), -(int)(array_x1 / size_darray_x) + (int)(x / size_darray_x));
}
void process208(int x, int y, int z, int(*array)[100], double size_darray_x, double size_darray_z, int array_x1, int array_z1) {
	make208(x, y, z);
	arraymark(array, (int)(118 / size_darray_x), (int)(15 / size_darray_z), -(int)(array_z1 / size_darray_z) + (int)(z / size_darray_z), -(int)(array_x1 / size_darray_x) + (int)(x / size_darray_x));
}
void processground(int x, int y, int z, int(*array)[100], double size_darray_x, double size_darray_z, int array_x1, int array_z1) {
	makeground(x, y, z);
	arraymark(array, (int)(75 / size_darray_x), (int)(50 / size_darray_z), -(int)(array_z1 / size_darray_z) + (int)(z / size_darray_z), -(int)(array_x1 / size_darray_x) + (int)(x / size_darray_x));
}
void processparkingplace(int x, int y, int z, int(*array)[100], double size_darray_x, double size_darray_z, int array_x1, int array_z1) {
	makeparkingplace(x, y, z);
	arraymark(array, (int)(20 / size_darray_x), (int)(50 / size_darray_z), -(int)(array_z1 / size_darray_z) + (int)(z / size_darray_z), -(int)(array_x1 / size_darray_x) + (int)(x / size_darray_x));
}
void processflower(int x, int y, int z, int(*array)[100], double size_darray_x, double size_darray_z, int array_x1, int array_z1) {
	makeflower(x, y, z);
	arraymark(array, (int)(5 / size_darray_x), (int)(30 / size_darray_z), -(int)(array_z1 / size_darray_z) + (int)(z / size_darray_z), -(int)(array_x1 / size_darray_x) + (int)(x / size_darray_x));
}
void process_kim_lamp(int x, int y, int z, int(*array)[100], double size_darray_x, double size_darray_z, int array_x1, int array_z1) {
	make_kim_lamp(x, y, z);
	arraymark(array, (int)(3 / size_darray_x), (int)(3 / size_darray_z), -(int)(array_z1 / size_darray_z) + (int)(z / size_darray_z), -(int)(array_x1 / size_darray_x) + (int)(x / size_darray_x));

}
void process_kim_road_mid(int x, int y, int z, int(*array)[100], double size_darray_x, double size_darray_z, int array_x1, int array_z1) {
	make_kim_road_mid(x, y, z);
	arraymark(array, (int)(10 / size_darray_x), (int)(10 / size_darray_z), -(int)(array_z1 / size_darray_z) + (int)(z / size_darray_z), -(int)(array_x1 / size_darray_x) + (int)(x / size_darray_x));
}
void process_kim_road_garo(int x, int y, int z, int(*array)[100], double size_darray_x, double size_darray_z, int array_x1, int array_z1) {
	make_kim_road_garo(x, y, z);
	arraymark(array, (int)(60 / size_darray_x), (int)(10 / size_darray_z), -(int)(array_z1 / size_darray_z) + (int)(z / size_darray_z), -(int)(array_x1 / size_darray_x) + (int)(x / size_darray_x));

}
void process_kim_road_sero(int x, int y, int z, int(*array)[100], double size_darray_x, double size_darray_z, int array_x1, int array_z1) {
	make_kim_road_sero(x, y, z);
	arraymark(array, (int)(10 / size_darray_x), (int)(60 / size_darray_z), -(int)(array_z1 / size_darray_z) + (int)(z / size_darray_z), -(int)(array_x1 / size_darray_x) + (int)(x / size_darray_x));

}
void process_hong_cauburger(int x, int y, int z, int(*array)[100], double size_darray_x, double size_darray_z, int array_x1, int array_z1) {
	make_hong_cauburger(x, y, z);
	arraymark(array, (int)(30 / size_darray_x), (int)(30 / size_darray_z), -(int)(array_z1 / size_darray_z) + (int)(z / size_darray_z), -(int)(array_x1 / size_darray_x) + (int)(x / size_darray_x));
	//고쳐야함_고쳤음
}
void process_hong_seven(int x, int y, int z, int(*array)[100], double size_darray_x, double size_darray_z, int array_x1, int array_z1) {
	make_hong_seven(x, y, z);
	arraymark(array, (int)(35 / size_darray_x), (int)(35 / size_darray_z), -(int)(array_z1 / size_darray_z) + (int)(z / size_darray_z), -(int)(array_x1 / size_darray_x) + (int)(x / size_darray_x));
	//고쳐야함_고쳤음
}
void process101(int x, int y, int z, int(*array)[100], double size_darray_x, double size_darray_z, int array_x1, int array_z1) {
	make101(x, y, z);
	arraymark(array, (int)(54 / size_darray_x), (int)(12 / size_darray_z), -(int)(array_z1 / size_darray_z) + (int)(z / size_darray_z), -(int)(array_x1 / size_darray_x) + (int)(x / size_darray_x));
	//고쳐야함_고쳤음
}
void processpond(int x, int y, int z, int(*array)[100], double size_darray_x, double size_darray_z, int array_x1, int array_z1) {
	makepond(x, y, z);
	arraymark(array, (int)(64 / size_darray_x), (int)(55 / size_darray_z), -(int)(array_z1 / size_darray_z) + (int)(z / size_darray_z), -(int)(array_x1 / size_darray_x) + (int)(x / size_darray_x));
	//고쳐야함_고쳤음
}
void process_kim_riceandpotato(int x, int y, int z, int(*array)[100], double size_darray_x, double size_darray_z, int array_x1, int array_z1) {
	make_kim_riceandpotato(x, y, z);
	arraymark(array, (int)(35 / size_darray_x), (int)(35 / size_darray_z), -(int)(array_z1 / size_darray_z) + (int)(z / size_darray_z), -(int)(array_x1 / size_darray_x) + (int)(x / size_darray_x));
//고쳐야함
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void arrayprintf(int(*array)[100]) {

	int i = 0, j = 0;

	for (i = 0;i < 100;i++) {
		printf("-");
	}
	printf("\n");
	for (i = 0;i < 50;i++) {
		for (j = 0;j < 100;j++) {
			printf("%c", array[i][j]);
		}
		printf("\n");
	}
	for (i = 0;i < 100;i++) {
		printf("-");
	}
	printf("\n");
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void arraymark(int(*array)[100], int a, int b, int c, int d) {
	int i = 0, j = 0;

	for (i = 0;i < a;i++) {
		for (j = 0;j < b;j++) {
			array[c + j][d + i] = '@';
		}
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void make310(int x, int y, int z) {

	BlockID glass = createBlock(BLOCK_GLASS);
	WoolID red = createWool(COLOR_RED);
	BlockID blue = createBlock(BLOCK_STAINED_GLASS);
	BlockID iron = createBlock(BLOCK_IRON);
	FlowerID TULIP = createFlower(FLOWER_RED_TULIP);
	BlockID air = createBlock(BLOCK_AIR);
	WoodID oak = createWood(WOOD_OAK, STRIP_EAST_WEST);
	BlockID stone = createBlock(BLOCK_STONE);
	BlockID grass = createBlock(BLOCK_GRASS);
	WoolID white = createWool(COLOR_WHITE);


	int a = 1, b = 1, c = 1;
	int xx1, yy1, zz1, xx2, yy2, zz2;
	xx1 = x, yy1 = y + 1, zz1 = z;
	xx2 = x + 134, yy2 = y + 50, zz2 = z + 60;


	make310_body(x, y, z);

	yy1 = y + 1;

	make310_decorating(x, y, z); //건물 꾸며주는 함수


	make310_window(x, y, z); //유리 장식 함수



	make310_eliminating(x, y, z); //불필요한부분 제거 함수


	if (a != 0) { //a가 0일경우 이 식은 무한루프에 빠진다.
		for (; zz1 < z + 4 * c; zz1++) { //z2 - 60 * c;는 zz1의 값과 같다
			for (; xx1 <= xx2; xx1 = xx1 + 6 * a) {
				for (; yy1 <= (y + y + 50) / 4; yy1++) {
					locateBlock(air, xx1, yy1 + (y + y + 50) / 4, zz1);
					locateBlock(air, xx1 + 1, yy1 + (y + y + 50) / 4, zz1);
					locateBlock(air, xx1 + 2, yy1 + (y + y + 50) / 4, zz1);

				}
				yy1 = y + 1;
			}
			xx1 = x;
		}
		zz1 = z;
	}

}
void make310_body(int x, int y, int z) {
	BlockID glass = createBlock(BLOCK_GLASS);
	WoolID red = createWool(COLOR_RED);
	BlockID blue = createBlock(BLOCK_STAINED_GLASS);
	BlockID iron = createBlock(BLOCK_IRON);
	FlowerID TULIP = createFlower(FLOWER_RED_TULIP);
	BlockID air = createBlock(BLOCK_AIR);
	WoodID oak = createWood(WOOD_OAK, STRIP_EAST_WEST);
	BlockID stone = createBlock(BLOCK_STONE);
	BlockID grass = createBlock(BLOCK_GRASS);
	WoolID white = createWool(COLOR_WHITE);

	////
	//310관 부분
	////
	int a = 1, b = 1, c = 1;
	int xx1, yy1, zz1, xx2, yy2, zz2;
	xx1 = x, yy1 = y + 1, zz1 = z;
	xx2 = x + 134, yy2 = y + 50, zz2 = z + 60;

	for (; yy1 <= yy2; yy1++) {
		for (; xx1 <= xx2; xx1++) {
			for (; zz1 <= zz2; zz1++) {
				locateBlock(iron, xx1, yy1, zz1);
			}
			zz1 = z;
		}
		xx1 = x;
	}

}

void make310_decorating(int x, int y, int z) {

	BlockID glass = createBlock(BLOCK_GLASS);
	WoolID red = createWool(COLOR_RED);
	BlockID blue = createBlock(BLOCK_STAINED_GLASS);
	BlockID iron = createBlock(BLOCK_IRON);
	FlowerID TULIP = createFlower(FLOWER_RED_TULIP);
	BlockID air = createBlock(BLOCK_AIR);
	WoodID oak = createWood(WOOD_OAK, STRIP_EAST_WEST);
	BlockID stone = createBlock(BLOCK_STONE);
	BlockID grass = createBlock(BLOCK_GRASS);
	WoolID white = createWool(COLOR_WHITE);


	int a = 1, b = 1, c = 1;
	int xx1, yy1, zz1, xx2, yy2, zz2;
	xx1 = x, yy1 = y + 1, zz1 = z;
	xx2 = x + 134, yy2 = y + 50, zz2 = z + 60;

	//310관 장식_1_1
	for (; xx1 < xx2; xx1 = xx1 + 5) {//장식의 크기 변화를 원하지 않아서 c를 곱하지 않는다.(비율을 신경쓰지 않는다)
		for (yy1 = y + 1; yy1 < (yy1 + yy2) / 4 - 2; yy1++) {//(yy1 + yy2) / 4가 절벽의 높이와 같다. 여기서 장식은 절벽 높이까지 할 것이기 때문에 이것을 사용한다.
			locateBlock(stone, xx1, yy1, zz1);
			locateBlock(glass, xx1 + 1, yy1, zz1);
			locateBlock(red, xx1 + 2, yy1, zz1);
			locateBlock(glass, xx1 + 3, yy1, zz1);
			locateBlock(stone, xx1 + 4, yy1, zz1);
		}
	}
	yy1 = y + 1;
	zz1 = z;

	//310관 장식_1_2
	for (; xx1 < xx2; xx1++) {
		locateBlock(stone, xx1, (yy1 + yy2) / 8 + 2 * b, zz1);//값이 소숫점이 되며 값이 줄어들어 정확히 절벽의 중앙에 오지 않았다. 경험적으로 2*b를 더해주면 중앙 값에 가까워짐을 알아서 2*b를 더했다.
	}
	xx1 = x;

}

void make310_window(int x, int y, int z) {
	BlockID glass = createBlock(BLOCK_GLASS);
	WoolID red = createWool(COLOR_RED);
	BlockID blue = createBlock(BLOCK_STAINED_GLASS);
	BlockID iron = createBlock(BLOCK_IRON);
	FlowerID TULIP = createFlower(FLOWER_RED_TULIP);
	BlockID air = createBlock(BLOCK_AIR);
	WoodID oak = createWood(WOOD_OAK, STRIP_EAST_WEST);
	BlockID stone = createBlock(BLOCK_STONE);
	BlockID grass = createBlock(BLOCK_GRASS);
	WoolID white = createWool(COLOR_WHITE);

	int a = 1, b = 1, c = 1;
	int xx1, yy1, zz1, xx2, yy2, zz2;
	xx1 = x, yy1 = y + 1, zz1 = z;
	xx2 = x + 134, yy2 = y + 50, zz2 = z + 60;


	//310관 장식_2_1(유리장식)
	for (; xx1 < xx2; xx1 = xx1 + 2) {//장식의 크기 변화를 원하지 않아서 c를 곱하지 않는다.(비율을 신경쓰지 않는다)
		for (yy1 = (y + 1 + y + 50) / 2; yy1 < yy2; yy1++) {//(y1 + 1 + y2) / 2는 전체 높이의 반이다. 여기서 장식은 절벽 높이까지 할 것이기 때문에 이것을 사용한다.
			locateBlock(iron, xx1, yy1, zz1);
			locateBlock(glass, xx1 + 1, yy1, zz1);
		}
		yy1 = (yy1 + yy2) / 2;
	}
	yy1 = y + 1;
	xx1 = x;

	//310관 장식_2_2(유리장식)
	for (yy1 = (yy1 + yy2) / 4; yy1 < yy2; yy1 = yy1 + 5) {
		for (xx1 = x; xx1 < xx2; xx1++) {
			locateBlock(iron, xx1, yy1, zz1);
		}
	}
	xx1 = x;
	yy1 = y + 1;
}

void make310_eliminating(int x, int y, int z) {

	BlockID glass = createBlock(BLOCK_GLASS);
	WoolID red = createWool(COLOR_RED);
	BlockID blue = createBlock(BLOCK_STAINED_GLASS);
	BlockID iron = createBlock(BLOCK_IRON);
	FlowerID TULIP = createFlower(FLOWER_RED_TULIP);
	BlockID air = createBlock(BLOCK_AIR);
	WoodID oak = createWood(WOOD_OAK, STRIP_EAST_WEST);
	BlockID stone = createBlock(BLOCK_STONE);
	BlockID grass = createBlock(BLOCK_GRASS);
	WoolID white = createWool(COLOR_WHITE);


	int a = 1, b = 1, c = 1;
	int xx1, yy1, zz1, xx2, yy2, zz2;
	xx1 = x, yy1 = y + 1, zz1 = z;
	xx2 = x + 134, yy2 = y + 50, zz2 = z + 60;

	//310관 외형을 위해서 왼쪽 각진 부분을 부분을 제거한다.(마름모꼴 모양으로 만든다)

	for (; yy1 <= yy2; yy1++) {
		for (int i = 0; i < 60 * c; i++) {
			for (int j = 0; j <= i; j++) {
				locateBlock(air, xx1 + j, yy1, zz2 - i - 1);

			}
		}
	}

	yy1 = y + 1;

	//310관 외형을 위해서 왼쪽 각진 부분을 부분을 제거한다.(마름모꼴 모양으로 만든다)

	for (; yy1 <= yy2; yy1++) {
		for (int i = 0; i < 60 * c; i++) {
			for (int j = 0; j <= i; j++) {
				locateBlock(air, xx2 - j, yy1, zz1 + i + 1);
			}
		}
	}
	yy1 = y + 1;

	//310관의 모습을 위해 기둥을 제외한 공간을 뚫는다
	for (; xx1 <= xx2; xx1++) {
		for (; yy1 <= (y + y + 50) / 4; yy1++) {
			locateBlock(air, xx1, yy1 + (y + y + 50) / 4, zz1);
			locateBlock(air, xx1, yy1 + (y + y + 50) / 4, zz1 + 4 * c);
		}
		yy1 = y + 1;
	}
	xx1 = x;

}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void make208(int x, int y, int z) {
	make208_body(x, y, z);
	make208_decorating(x, y, z);

}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void make208_body(int x, int y, int z) {
	BlockID glass = createBlock(BLOCK_GLASS);
	WoolID red = createWool(COLOR_RED);
	BlockID blue = createBlock(BLOCK_STAINED_GLASS);
	BlockID iron = createBlock(BLOCK_IRON);
	FlowerID TULIP = createFlower(FLOWER_RED_TULIP);
	BlockID air = createBlock(BLOCK_AIR);
	WoodID oak = createWood(WOOD_OAK, STRIP_EAST_WEST);
	BlockID stone = createBlock(BLOCK_STONE);
	BlockID grass = createBlock(BLOCK_GRASS);
	WoolID white = createWool(COLOR_WHITE);

	int xx1, yy1, zz1, xx2, yy2, zz2;
	int a = 1, b = 1, c = 1;
	////
	/*208관 부분*/
	////
	xx1 = x, yy1 = y + 1, zz1 = z;
	xx2 = x + 108, yy2 = y + 50, zz2 = z + 15;

	for (; yy1 <= (y + y + 50) / 2; yy1++) {
		for (; xx1 <= xx2; xx1++) {
			for (; zz1 <= zz2; zz1++) {
				locateBlock(white, xx1, yy1, zz1);
			}
			zz1 = z;
		}
		xx1 = x;
	}
	yy1 = y + 1;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void make208_decorating(int x, int y, int z) {
	BlockID glass = createBlock(BLOCK_GLASS);
	WoolID red = createWool(COLOR_RED);
	BlockID blue = createBlock(BLOCK_STAINED_GLASS);
	BlockID iron = createBlock(BLOCK_IRON);
	FlowerID TULIP = createFlower(FLOWER_RED_TULIP);
	BlockID air = createBlock(BLOCK_AIR);
	WoodID oak = createWood(WOOD_OAK, STRIP_EAST_WEST);
	BlockID stone = createBlock(BLOCK_STONE);
	BlockID grass = createBlock(BLOCK_GRASS);
	WoolID white = createWool(COLOR_WHITE);

	int xx1, yy1, zz1, xx2, yy2, zz2;
	int a = 1, b = 1, c = 1;
	////
	xx1 = x, yy1 = y + 1, zz1 = z;
	xx2 = x + 108, yy2 = y + 50, zz2 = z + 15;

	//208관 창문 장식 달기
	int i = 0;
	int j = 0;
	for (xx1 = xx1 + 4 * a; xx1 < xx2; xx1 = xx1 + 6 * a)
	{
		for (i = 0; i < 4 * a; i++)
		{
			for (j = 0; j < 3 * b; j++)
			{
				locateBlock(blue, xx1 + i, yy1 + j + b, zz1);
				locateBlock(blue, xx1 + i, yy1 + j + b, zz2);

				locateBlock(blue, xx1 + i, yy1 + j + 6 * b, zz1);
				locateBlock(blue, xx1 + i, yy1 + j + 6 * b, zz2);

				locateBlock(blue, xx1 + i, yy1 + j + 11 * b, zz1);
				locateBlock(blue, xx1 + i, yy1 + j + 11 * b, zz2);

				locateBlock(blue, xx1 + i, yy1 + j + 16 * b, zz1);
				locateBlock(blue, xx1 + i, yy1 + j + 16 * b, zz2);

				locateBlock(blue, xx1 + i, yy1 + j + 21 * b, zz1);
				locateBlock(blue, xx1 + i, yy1 + j + 21 * b, zz2);

			}
		}
	}
	//208관 통로 뚫기
	for (; yy1 <= (y + y + 50) / 4; yy1++) {
		for (; xx1 <= x + 16; xx1++) {//x1 + 22 * a는 xx1과 같다
			for (; zz1 <= zz2; zz1++) {
				locateBlock(air, xx1 + 16 * a, yy1, zz1);
			}
			zz1 = z;
		}
		xx1 = x;
	}
	yy1 = y + 1;


	//208관 통로 안에 문 뚫기
	for (i = 0; i < 4 * b; i++) {
		for (j = 0; j < 3 * c; j++) {
			locateBlock(air, x + 33, yy1 + i, (zz1 + zz2) / 2 + j);
			locateBlock(air, x + 15, yy1 + i, (zz1 + zz2) / 2 + j);
		}
	}



	//208관 오른쪽
	xx1 = x + 108, yy1 = y + 1, zz1 = z;
	xx2 = x + 118, yy2 = y + 50, zz2 = z + 15;

	for (; yy1 <= (y + 1 + y + 50) / 2; yy1++) {
		for (; xx1 <= xx2; xx1++) {
			for (; zz1 <= zz2; zz1++) {
				locateBlock(white, xx1, yy1, zz1);
			}
			zz1 = z;
		}
		xx1 = x + 108;
	}
	yy1 = y + 1;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void makeground(int x, int y, int z) {
	int xx1, yy1, zz1, xx2, yy2, zz2;

	int a = 1, b = 1, c = 1;

	BlockID glass = createBlock(BLOCK_GLASS);
	WoolID red = createWool(COLOR_RED);
	BlockID blue = createBlock(BLOCK_STAINED_GLASS);
	BlockID iron = createBlock(BLOCK_IRON);
	FlowerID TULIP = createFlower(FLOWER_RED_TULIP);
	BlockID air = createBlock(BLOCK_AIR);
	WoodID oak = createWood(WOOD_OAK, STRIP_EAST_WEST);
	BlockID stone = createBlock(BLOCK_STONE);
	BlockID grass = createBlock(BLOCK_GRASS);
	WoolID white = createWool(COLOR_WHITE);

	////
	/*운동장 부분*/
	////

	xx1 = x, yy1 = y, zz1 = z;
	xx2 = x + 75, yy2 = y, zz2 = z + 50;



	//운동장

	for (; yy1 <= yy2; yy1++) {
		for (; xx1 <= xx2; xx1++) {
			for (; zz1 <= zz2; zz1++) {
				locateBlock(grass, xx1, yy1, zz1);

			}
			zz1 = z;
		}
		xx1 = x;
	}

	yy1 = y;



	//선 긋기



	//선 긋기_세로줄

	for (; zz1 <= zz2 - 10 * c; zz1++) { locateBlock(white, xx1 + (75 * a) / 2, yy1, zz1 + 5 * c); }

	zz1 = z;



	for (; zz1 <= zz2 - 10 * c; zz1++) { locateBlock(white, xx1 + (75 * a) / 10, yy1, zz1 + 5 * c); }
	zz1 = z;


	for (; zz1 <= zz2 - 10 * c; zz1++) { locateBlock(white, xx1 + (9 * 75 * a) / 10, yy1, zz1 + 5 * c); }
	zz1 = z;


	//선 긋기_가로줄

	for (; xx1 < xx2 - 2 * (75 * a) / 10; xx1++) { locateBlock(white, xx1 + (75 * a) / 10, yy1, zz1 + 5 * c); }
	xx1 = x;

	for (; xx1 < xx2 - 2 * (75 * a) / 10; xx1++) { locateBlock(white, xx1 + (75 * a) / 10, yy1, zz2 - 5 * c); }
	xx1 = x;


	//선 긋기_골방어선_왼쪽

	for (; zz1 <= zz2 - 30 * c; zz1++) { locateBlock(white, xx1 + 3 * (75 * a) / 10, yy1, zz1 + 15 * c); }
	zz1 = z;
	for (; xx1 < xx2 - 8 * (75 * a) / 10; xx1++) { locateBlock(white, xx1 + (75 * a) / 10, yy1, zz1 + 15 * c); }
	xx1 = x;
	for (; xx1 < xx2 - 8 * (75 * a) / 10; xx1++) { locateBlock(white, xx1 + (75 * a) / 10, yy1, zz2 - 15 * c); }
	xx1 = x;

	//선 긋기_골방어선_오른쪽

	for (; zz1 <= zz2 - 30 * c; zz1++) { locateBlock(white, xx1 + 7 * (75 * a) / 10, yy1, zz1 + 15 * c); }
	zz1 = z;
	for (; xx1 < xx2 - 8 * (75 * a) / 10; xx1++) { locateBlock(white, xx1 + 7 * (75 * a) / 10, yy1, zz1 + 15 * c); }
	xx1 = x;
	for (; xx1 < xx2 - 8 * (75 * a) / 10; xx1++) { locateBlock(white, xx1 + 7 * (75 * a) / 10, yy1, zz2 - 15 * c); }
	xx1 = x;




}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void makeparkingplace(int x, int y, int z) {
	BlockID glass = createBlock(BLOCK_GLASS);
	WoolID red = createWool(COLOR_RED);
	BlockID blue = createBlock(BLOCK_STAINED_GLASS);
	BlockID iron = createBlock(BLOCK_IRON);
	FlowerID TULIP = createFlower(FLOWER_RED_TULIP);
	BlockID air = createBlock(BLOCK_AIR);
	WoodID oak = createWood(WOOD_OAK, STRIP_EAST_WEST);
	BlockID stone = createBlock(BLOCK_STONE);
	BlockID grass = createBlock(BLOCK_GRASS);
	WoolID white = createWool(COLOR_WHITE);


	int a = 1, b = 1, c = 1;
	int xx1, yy1, zz1, xx2, yy2, zz2;

	////
	/*운동장에 붙어있는 절벽과 주차장 부분*/
	////
	//xx1 = x2 - 20 * a, yy1 = y1 + 1, zz1 = z2 - 110 * c;
	xx1 = x, yy1 = y + 1, zz1 = z;
	//xx2 = x2, yy2 = y2, zz2 = z2 - 60 * c;
	xx2 = x + 20, yy2 = y + 50, zz2 = z + 50;

	//절벽부분

	for (; yy1 <= (yy2 + y + 1) / 4; yy1++) { //y1+1이라 쓴 것은 yy1이다.
		for (; xx1 <= xx2; xx1++) {
			for (; zz1 <= zz2; zz1++) {
				locateBlock(stone, xx1, yy1, zz1);
			}
			zz1 = z;
		}
		xx1 = x;
	}
	yy1 = y + 1;

	//절벽 장식_1
	for (; zz1 < zz2; zz1 = zz1 + 5) {//장식의 크기 변화를 원하지 않아서 c를 곱하지 않는다.(비율을 신경쓰지 않는다)

		for (yy1 = y + 1; yy1 < (yy1 + yy2) / 4 - 2; yy1++) {//(yy1 + yy2) / 4는 절벽의 높이다.
			locateBlock(stone, xx1, yy1, zz1);
			locateBlock(glass, xx1, yy1, zz1 + 1);
			locateBlock(red, xx1, yy1, zz1 + 2);
			locateBlock(glass, xx1, yy1, zz1 + 3);
			locateBlock(stone, xx1, yy1, zz1 + 4);
		}
	}
	yy1 = y + 1;
	zz1 = z;

	//절벽 장식_2
	for (; zz1 < zz2; zz1++) {
		locateBlock(stone, xx1, (yy1 + yy2) / 8 + 2 * b, zz1);//값이 소숫점이 되며 값이 줄어들어 정확히 절벽의 중앙에 오지 않았다. 경험적으로 2*b를 더해주면 중앙 값에 가까워짐을 알아서 2*b를 더했다.

	}
	zz1 = z;



	//주차장 부분

	for (; xx1 <= xx2; xx1++) {
		for (; zz1 <= zz2; zz1++) {
			locateBlock(grass, xx1, (yy2 + yy1) / 4, zz1);
		}
		zz1 = z;
	}
	xx1 = x;


	//주차장_주차선
	for (; zz1 < zz2 - 6; zz1 = zz1 + 4) {
		locateBlock(white, xx1 + 1, (yy2 + yy1) / 4, zz1 + 1);
		locateBlock(white, xx1 + 2, (yy2 + yy1) / 4, zz1 + 1);
		locateBlock(white, xx1 + 3, (yy2 + yy1) / 4, zz1 + 1);

		locateBlock(white, xx2 - 1, (yy2 + yy1) / 4, zz1 + 1);
		locateBlock(white, xx2 - 2, (yy2 + yy1) / 4, zz1 + 1);
		locateBlock(white, xx2 - 3, (yy2 + yy1) / 4, zz1 + 1);
	}
	zz1 = z;


	for (; zz1 < zz2 - 6; zz1++) {
		locateBlock(white, xx1, (yy2 + yy1) / 4, zz1 + 1);
		locateBlock(white, xx2, (yy2 + yy1) / 4, zz1 + 1);
	}


}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void makeflower(int x, int y, int z) {
	BlockID glass = createBlock(BLOCK_GLASS);
	WoolID red = createWool(COLOR_RED);
	BlockID blue = createBlock(BLOCK_STAINED_GLASS);
	BlockID iron = createBlock(BLOCK_IRON);
	FlowerID TULIP = createFlower(FLOWER_RED_TULIP);
	BlockID air = createBlock(BLOCK_AIR);
	WoodID oak = createWood(WOOD_OAK, STRIP_EAST_WEST);
	BlockID stone = createBlock(BLOCK_STONE);
	BlockID grass = createBlock(BLOCK_GRASS);
	WoolID white = createWool(COLOR_WHITE);

	int xx1, yy1, zz1, xx2, yy2, zz2;

	//운동장 화단 부분
	//xx1 = x2 - 100 * a, yy1 = y1, zz1 = z2 - 100 * c;
	xx1 = x, yy1 = y, zz1 = z;
	//xx2 = x2 - 95 * a, yy2 = y1, zz2 = z2 - 70 * c;
	xx2 = x + 5, yy2 = y, zz2 = z + 30;
	for (; yy1 <= yy2; yy1++) {
		for (; xx1 <= xx2; xx1++) {
			for (; zz1 <= zz2; zz1++) {
				locateBlock(grass, xx1, yy1, zz1);

				locateBlock(TULIP, xx1, yy1 + 1, zz1);

			}
			zz1 = z;
		}
		xx1 = x;
	}
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void make_kim_lamp(int sx, int sy, int sz) {
	FenceID fence = createFence(FENCE_SPRUCE);
	BlockID glow = createBlock(BLOCK_GLOWSTONE);
	PaneID pane = createPane(PANE_GLASS);
	SlabID low = createSlab(SLAB_STONE, SLAB_LOWER);
	SlabID up = createSlab(SLAB_STONE, SLAB_UPPER);
	SlabID dou = createSlab(SLAB_STONE, SLAB_DOUBLE);

	locateBlock(fence, sx, sy, sz);
	locateBlock(fence, sx, sy + 1, sz);
	locateBlock(fence, sx, sy + 2, sz);
	locateBlock(fence, sx, sy + 3, sz);
	locateBlock(fence, sx, sy + 4, sz);
	locateBlock(fence, sx, sy + 5, sz);
	locateBlock(fence, sx, sy + 6, sz);
	locateBlock(fence, sx, sy + 7, sz);

	locateBlock(low, sx, sy + 8, sz);

	locateBlock(dou, sx + 1, sy + 7, sz);
	locateBlock(dou, sx - 1, sy + 7, sz);
	locateBlock(dou, sx, sy + 7, sz + 1);
	locateBlock(dou, sx, sy + 7, sz - 1);

	locateBlock(low, sx + 1, sy + 7, sz + 1);
	locateBlock(low, sx + 1, sy + 7, sz - 1);
	locateBlock(low, sx - 1, sy + 7, sz + 1);
	locateBlock(low, sx - 1, sy + 7, sz - 1);

	locatePane(pane, sx + 1, sy + 6, sz);
	locatePane(pane, sx + 1, sy + 6, sz + 1);
	locatePane(pane, sx + 1, sy + 6, sz - 1);
	locatePane(pane, sx, sy + 6, sz + 1);
	locatePane(pane, sx, sy + 6, sz - 1);
	locatePane(pane, sx - 1, sy + 6, sz);
	locatePane(pane, sx - 1, sy + 6, sz + 1);
	locatePane(pane, sx - 1, sy + 6, sz - 1);

	locateBlock(glow, sx, sy + 6, sz);
	locateBlock(glow, sx, sy + 7, sz);

}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void make_kim_road_mid(int sx, int sy, int sz) {
	BlockID stone = createBlock(BLOCK_STONE);
	WoolID black = createWool(COLOR_BLACK);
	WoolID yellow = createWool(COLOR_YELLOW);
	WoolID white = createWool(COLOR_WHITE);
	SlabID slab = createSlab(SLAB_STONE, SLAB_LOWER);

	locateSlab(slab, sx, sy + 1, sz);
	locateSlab(slab, sx, sy + 1, sz + 9);
	locateSlab(slab, sx + 9, sy + 1, sz);
	locateSlab(slab, sx + 9, sy + 1, sz + 9);

	locateBlock(black, sx, sy, sz);
	locateBlock(black, sx + 1, sy, sz);
	locateBlock(black, sx + 2, sy, sz);
	locateBlock(black, sx + 3, sy, sz);
	locateBlock(yellow, sx + 4, sy, sz);
	locateBlock(yellow, sx + 5, sy, sz);
	locateBlock(black, sx + 6, sy, sz);
	locateBlock(black, sx + 7, sy, sz);
	locateBlock(black, sx + 8, sy, sz);
	locateBlock(black, sx + 9, sy, sz);

	locateBlock(black, sx, sy, sz + 1);
	locateBlock(black, sx + 1, sy, sz + 1);
	locateBlock(black, sx + 2, sy, sz + 1);
	locateBlock(black, sx + 3, sy, sz + 1);
	locateBlock(yellow, sx + 4, sy, sz + 1);
	locateBlock(yellow, sx + 5, sy, sz + 1);
	locateBlock(black, sx + 6, sy, sz + 1);
	locateBlock(black, sx + 7, sy, sz + 1);
	locateBlock(black, sx + 8, sy, sz + 1);
	locateBlock(black, sx + 9, sy, sz + 1);

	locateBlock(black, sx, sy, sz + 2);
	locateBlock(black, sx + 1, sy, sz + 2);
	locateBlock(black, sx + 2, sy, sz + 2);
	locateBlock(black, sx + 3, sy, sz + 2);
	locateBlock(black, sx + 4, sy, sz + 2);
	locateBlock(black, sx + 5, sy, sz + 2);
	locateBlock(black, sx + 6, sy, sz + 2);
	locateBlock(black, sx + 7, sy, sz + 2);
	locateBlock(black, sx + 8, sy, sz + 2);
	locateBlock(black, sx + 9, sy, sz + 2);

	locateBlock(black, sx, sy, sz + 3);
	locateBlock(black, sx + 1, sy, sz + 3);
	locateBlock(black, sx + 2, sy, sz + 3);
	locateBlock(black, sx + 3, sy, sz + 3);
	locateBlock(black, sx + 4, sy, sz + 3);
	locateBlock(black, sx + 5, sy, sz + 3);
	locateBlock(black, sx + 6, sy, sz + 3);
	locateBlock(black, sx + 7, sy, sz + 3);
	locateBlock(black, sx + 8, sy, sz + 3);
	locateBlock(black, sx + 9, sy, sz + 3);

	locateBlock(yellow, sx, sy, sz + 4);
	locateBlock(yellow, sx + 1, sy, sz + 4);
	locateBlock(black, sx + 2, sy, sz + 4);
	locateBlock(black, sx + 3, sy, sz + 4);
	locateBlock(yellow, sx + 4, sy, sz + 4);
	locateBlock(yellow, sx + 5, sy, sz + 4);
	locateBlock(black, sx + 6, sy, sz + 4);
	locateBlock(black, sx + 7, sy, sz + 4);
	locateBlock(yellow, sx + 8, sy, sz + 4);
	locateBlock(yellow, sx + 9, sy, sz + 4);

	locateBlock(yellow, sx, sy, sz + 5);
	locateBlock(yellow, sx + 1, sy, sz + 5);
	locateBlock(black, sx + 2, sy, sz + 5);
	locateBlock(black, sx + 3, sy, sz + 5);
	locateBlock(yellow, sx + 4, sy, sz + 5);
	locateBlock(yellow, sx + 5, sy, sz + 5);
	locateBlock(black, sx + 6, sy, sz + 5);
	locateBlock(black, sx + 7, sy, sz + 5);
	locateBlock(yellow, sx + 8, sy, sz + 5);
	locateBlock(yellow, sx + 9, sy, sz + 5);

	locateBlock(black, sx, sy, sz + 6);
	locateBlock(black, sx + 1, sy, sz + 6);
	locateBlock(black, sx + 2, sy, sz + 6);
	locateBlock(black, sx + 3, sy, sz + 6);
	locateBlock(black, sx + 4, sy, sz + 6);
	locateBlock(black, sx + 5, sy, sz + 6);
	locateBlock(black, sx + 6, sy, sz + 6);
	locateBlock(black, sx + 7, sy, sz + 6);
	locateBlock(black, sx + 8, sy, sz + 6);
	locateBlock(black, sx + 9, sy, sz + 6);

	locateBlock(black, sx, sy, sz + 7);
	locateBlock(black, sx + 1, sy, sz + 7);
	locateBlock(black, sx + 2, sy, sz + 7);
	locateBlock(black, sx + 3, sy, sz + 7);
	locateBlock(black, sx + 4, sy, sz + 7);
	locateBlock(black, sx + 5, sy, sz + 7);
	locateBlock(black, sx + 6, sy, sz + 7);
	locateBlock(black, sx + 7, sy, sz + 7);
	locateBlock(black, sx + 8, sy, sz + 7);
	locateBlock(black, sx + 9, sy, sz + 7);

	locateBlock(black, sx, sy, sz + 8);
	locateBlock(black, sx + 1, sy, sz + 8);
	locateBlock(black, sx + 2, sy, sz + 8);
	locateBlock(black, sx + 3, sy, sz + 8);
	locateBlock(yellow, sx + 4, sy, sz + 8);
	locateBlock(yellow, sx + 5, sy, sz + 8);
	locateBlock(black, sx + 6, sy, sz + 8);
	locateBlock(black, sx + 7, sy, sz + 8);
	locateBlock(black, sx + 8, sy, sz + 8);
	locateBlock(black, sx + 9, sy, sz + 8);

	locateBlock(black, sx, sy, sz + 9);
	locateBlock(black, sx + 1, sy, sz + 9);
	locateBlock(black, sx + 2, sy, sz + 9);
	locateBlock(black, sx + 3, sy, sz + 9);
	locateBlock(yellow, sx + 4, sy, sz + 9);
	locateBlock(yellow, sx + 5, sy, sz + 9);
	locateBlock(black, sx + 6, sy, sz + 9);
	locateBlock(black, sx + 7, sy, sz + 9);
	locateBlock(black, sx + 8, sy, sz + 9);
	locateBlock(black, sx + 9, sy, sz + 9);

}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void make_kim_road_garo(int sx, int sy, int sz) {
	BlockID stone = createBlock(BLOCK_STONE);
	WoolID black = createWool(COLOR_BLACK);
	WoolID yellow = createWool(COLOR_YELLOW);
	WoolID white = createWool(COLOR_WHITE);
	SlabID slab = createSlab(SLAB_STONE, SLAB_LOWER);

	for(int i=0;i<6;i++,sx=sx+10){
	locateSlab(slab, sx, sy + 1, sz);
	locateSlab(slab, sx + 1, sy + 1, sz);
	locateSlab(slab, sx + 2, sy + 1, sz);
	locateSlab(slab, sx + 3, sy + 1, sz);
	locateSlab(slab, sx + 4, sy + 1, sz);
	locateSlab(slab, sx + 5, sy + 1, sz);
	locateSlab(slab, sx + 6, sy + 1, sz);
	locateSlab(slab, sx + 7, sy + 1, sz);
	locateSlab(slab, sx + 8, sy + 1, sz);
	locateSlab(slab, sx + 9, sy + 1, sz);

	locateSlab(slab, sx, sy + 1, sz + 9);
	locateSlab(slab, sx + 1, sy + 1, sz + 9);
	locateSlab(slab, sx + 2, sy + 1, sz + 9);
	locateSlab(slab, sx + 3, sy + 1, sz + 9);
	locateSlab(slab, sx + 4, sy + 1, sz + 9);
	locateSlab(slab, sx + 5, sy + 1, sz + 9);
	locateSlab(slab, sx + 6, sy + 1, sz + 9);
	locateSlab(slab, sx + 7, sy + 1, sz + 9);
	locateSlab(slab, sx + 8, sy + 1, sz + 9);
	locateSlab(slab, sx + 9, sy + 1, sz + 9);

	locateBlock(black, sx, sy, sz);
	locateBlock(black, sx + 1, sy, sz);
	locateBlock(black, sx + 2, sy, sz);
	locateBlock(black, sx + 3, sy, sz);
	locateBlock(black, sx + 4, sy, sz);
	locateBlock(black, sx + 5, sy, sz);
	locateBlock(black, sx + 6, sy, sz);
	locateBlock(black, sx + 7, sy, sz);
	locateBlock(black, sx + 8, sy, sz);
	locateBlock(black, sx + 9, sy, sz);

	locateBlock(black, sx, sy, sz + 1);
	locateBlock(black, sx + 1, sy, sz + 1);
	locateBlock(black, sx + 2, sy, sz + 1);
	locateBlock(black, sx + 3, sy, sz + 1);
	locateBlock(black, sx + 4, sy, sz + 1);
	locateBlock(black, sx + 5, sy, sz + 1);
	locateBlock(black, sx + 6, sy, sz + 1);
	locateBlock(black, sx + 7, sy, sz + 1);
	locateBlock(black, sx + 8, sy, sz + 1);
	locateBlock(black, sx + 9, sy, sz + 1);

	locateBlock(black, sx, sy, sz + 2);
	locateBlock(black, sx + 1, sy, sz + 2);
	locateBlock(black, sx + 2, sy, sz + 2);
	locateBlock(black, sx + 3, sy, sz + 2);
	locateBlock(black, sx + 4, sy, sz + 2);
	locateBlock(black, sx + 5, sy, sz + 2);
	locateBlock(black, sx + 6, sy, sz + 2);
	locateBlock(black, sx + 7, sy, sz + 2);
	locateBlock(black, sx + 8, sy, sz + 2);
	locateBlock(black, sx + 9, sy, sz + 2);

	locateBlock(black, sx, sy, sz + 3);
	locateBlock(black, sx + 1, sy, sz + 3);
	locateBlock(black, sx + 2, sy, sz + 3);
	locateBlock(black, sx + 3, sy, sz + 3);
	locateBlock(black, sx + 4, sy, sz + 3);
	locateBlock(black, sx + 5, sy, sz + 3);
	locateBlock(black, sx + 6, sy, sz + 3);
	locateBlock(black, sx + 7, sy, sz + 3);
	locateBlock(black, sx + 8, sy, sz + 3);
	locateBlock(black, sx + 9, sy, sz + 3);

	locateBlock(yellow, sx, sy, sz + 4);
	locateBlock(yellow, sx + 1, sy, sz + 4);
	locateBlock(black, sx + 2, sy, sz + 4);
	locateBlock(black, sx + 3, sy, sz + 4);
	locateBlock(yellow, sx + 4, sy, sz + 4);
	locateBlock(yellow, sx + 5, sy, sz + 4);
	locateBlock(black, sx + 6, sy, sz + 4);
	locateBlock(black, sx + 7, sy, sz + 4);
	locateBlock(yellow, sx + 8, sy, sz + 4);
	locateBlock(yellow, sx + 9, sy, sz + 4);

	locateBlock(yellow, sx, sy, sz + 5);
	locateBlock(yellow, sx + 1, sy, sz + 5);
	locateBlock(black, sx + 2, sy, sz + 5);
	locateBlock(black, sx + 3, sy, sz + 5);
	locateBlock(yellow, sx + 4, sy, sz + 5);
	locateBlock(yellow, sx + 5, sy, sz + 5);
	locateBlock(black, sx + 6, sy, sz + 5);
	locateBlock(black, sx + 7, sy, sz + 5);
	locateBlock(yellow, sx + 8, sy, sz + 5);
	locateBlock(yellow, sx + 9, sy, sz + 5);

	locateBlock(black, sx, sy, sz + 6);
	locateBlock(black, sx + 1, sy, sz + 6);
	locateBlock(black, sx + 2, sy, sz + 6);
	locateBlock(black, sx + 3, sy, sz + 6);
	locateBlock(black, sx + 4, sy, sz + 6);
	locateBlock(black, sx + 5, sy, sz + 6);
	locateBlock(black, sx + 6, sy, sz + 6);
	locateBlock(black, sx + 7, sy, sz + 6);
	locateBlock(black, sx + 8, sy, sz + 6);
	locateBlock(black, sx + 9, sy, sz + 6);

	locateBlock(black, sx, sy, sz + 7);
	locateBlock(black, sx + 1, sy, sz + 7);
	locateBlock(black, sx + 2, sy, sz + 7);
	locateBlock(black, sx + 3, sy, sz + 7);
	locateBlock(black, sx + 4, sy, sz + 7);
	locateBlock(black, sx + 5, sy, sz + 7);
	locateBlock(black, sx + 6, sy, sz + 7);
	locateBlock(black, sx + 7, sy, sz + 7);
	locateBlock(black, sx + 8, sy, sz + 7);
	locateBlock(black, sx + 9, sy, sz + 7);

	locateBlock(black, sx, sy, sz + 8);
	locateBlock(black, sx + 1, sy, sz + 8);
	locateBlock(black, sx + 2, sy, sz + 8);
	locateBlock(black, sx + 3, sy, sz + 8);
	locateBlock(black, sx + 4, sy, sz + 8);
	locateBlock(black, sx + 5, sy, sz + 8);
	locateBlock(black, sx + 6, sy, sz + 8);
	locateBlock(black, sx + 7, sy, sz + 8);
	locateBlock(black, sx + 8, sy, sz + 8);
	locateBlock(black, sx + 9, sy, sz + 8);

	locateBlock(black, sx, sy, sz + 9);
	locateBlock(black, sx + 1, sy, sz + 9);
	locateBlock(black, sx + 2, sy, sz + 9);
	locateBlock(black, sx + 3, sy, sz + 9);
	locateBlock(black, sx + 4, sy, sz + 9);
	locateBlock(black, sx + 5, sy, sz + 9);
	locateBlock(black, sx + 6, sy, sz + 9);
	locateBlock(black, sx + 7, sy, sz + 9);
	locateBlock(black, sx + 8, sy, sz + 9);
	locateBlock(black, sx + 9, sy, sz + 9);
}
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void make_kim_road_sero(int sx, int sy, int sz) {
	BlockID stone = createBlock(BLOCK_STONE);
	WoolID black = createWool(COLOR_BLACK);
	WoolID yellow = createWool(COLOR_YELLOW);
	WoolID white = createWool(COLOR_WHITE);
	SlabID slab = createSlab(SLAB_STONE, SLAB_LOWER);

	for(int i=0;i<6;i++,sz=sz+10){

	locateSlab(slab, sx, sy + 1, sz);
	locateSlab(slab, sx, sy + 1, sz + 1);
	locateSlab(slab, sx, sy + 1, sz + 2);
	locateSlab(slab, sx, sy + 1, sz + 3);
	locateSlab(slab, sx, sy + 1, sz + 4);
	locateSlab(slab, sx, sy + 1, sz + 5);
	locateSlab(slab, sx, sy + 1, sz + 6);
	locateSlab(slab, sx, sy + 1, sz + 7);
	locateSlab(slab, sx, sy + 1, sz + 8);
	locateSlab(slab, sx, sy + 1, sz + 9);

	locateSlab(slab, sx + 9, sy + 1, sz);
	locateSlab(slab, sx + 9, sy + 1, sz + 1);
	locateSlab(slab, sx + 9, sy + 1, sz + 2);
	locateSlab(slab, sx + 9, sy + 1, sz + 3);
	locateSlab(slab, sx + 9, sy + 1, sz + 4);
	locateSlab(slab, sx + 9, sy + 1, sz + 5);
	locateSlab(slab, sx + 9, sy + 1, sz + 6);
	locateSlab(slab, sx + 9, sy + 1, sz + 7);
	locateSlab(slab, sx + 9, sy + 1, sz + 8);
	locateSlab(slab, sx + 9, sy + 1, sz + 9);

	locateBlock(black, sx, sy, sz);
	locateBlock(black, sx + 1, sy, sz);
	locateBlock(black, sx + 2, sy, sz);
	locateBlock(black, sx + 3, sy, sz);
	locateBlock(yellow, sx + 4, sy, sz);
	locateBlock(yellow, sx + 5, sy, sz);
	locateBlock(black, sx + 6, sy, sz);
	locateBlock(black, sx + 7, sy, sz);
	locateBlock(black, sx + 8, sy, sz);
	locateBlock(black, sx + 9, sy, sz);

	locateBlock(black, sx, sy, sz + 1);
	locateBlock(black, sx + 1, sy, sz + 1);
	locateBlock(black, sx + 2, sy, sz + 1);
	locateBlock(black, sx + 3, sy, sz + 1);
	locateBlock(yellow, sx + 4, sy, sz + 1);
	locateBlock(yellow, sx + 5, sy, sz + 1);
	locateBlock(black, sx + 6, sy, sz + 1);
	locateBlock(black, sx + 7, sy, sz + 1);
	locateBlock(black, sx + 8, sy, sz + 1);
	locateBlock(black, sx + 9, sy, sz + 1);

	locateBlock(black, sx, sy, sz + 2);
	locateBlock(black, sx + 1, sy, sz + 2);
	locateBlock(black, sx + 2, sy, sz + 2);
	locateBlock(black, sx + 3, sy, sz + 2);
	locateBlock(black, sx + 4, sy, sz + 2);
	locateBlock(black, sx + 5, sy, sz + 2);
	locateBlock(black, sx + 6, sy, sz + 2);
	locateBlock(black, sx + 7, sy, sz + 2);
	locateBlock(black, sx + 8, sy, sz + 2);
	locateBlock(black, sx + 9, sy, sz + 2);

	locateBlock(black, sx, sy, sz + 3);
	locateBlock(black, sx + 1, sy, sz + 3);
	locateBlock(black, sx + 2, sy, sz + 3);
	locateBlock(black, sx + 3, sy, sz + 3);
	locateBlock(black, sx + 4, sy, sz + 3);
	locateBlock(black, sx + 5, sy, sz + 3);
	locateBlock(black, sx + 6, sy, sz + 3);
	locateBlock(black, sx + 7, sy, sz + 3);
	locateBlock(black, sx + 8, sy, sz + 3);
	locateBlock(black, sx + 9, sy, sz + 3);

	locateBlock(black, sx, sy, sz + 4);
	locateBlock(black, sx + 1, sy, sz + 4);
	locateBlock(black, sx + 2, sy, sz + 4);
	locateBlock(black, sx + 3, sy, sz + 4);
	locateBlock(yellow, sx + 4, sy, sz + 4);
	locateBlock(yellow, sx + 5, sy, sz + 4);
	locateBlock(black, sx + 6, sy, sz + 4);
	locateBlock(black, sx + 7, sy, sz + 4);
	locateBlock(black, sx + 8, sy, sz + 4);
	locateBlock(black, sx + 9, sy, sz + 4);

	locateBlock(black, sx, sy, sz + 5);
	locateBlock(black, sx + 1, sy, sz + 5);
	locateBlock(black, sx + 2, sy, sz + 5);
	locateBlock(black, sx + 3, sy, sz + 5);
	locateBlock(yellow, sx + 4, sy, sz + 5);
	locateBlock(yellow, sx + 5, sy, sz + 5);
	locateBlock(black, sx + 6, sy, sz + 5);
	locateBlock(black, sx + 7, sy, sz + 5);
	locateBlock(black, sx + 8, sy, sz + 5);
	locateBlock(black, sx + 9, sy, sz + 5);

	locateBlock(black, sx, sy, sz + 6);
	locateBlock(black, sx + 1, sy, sz + 6);
	locateBlock(black, sx + 2, sy, sz + 6);
	locateBlock(black, sx + 3, sy, sz + 6);
	locateBlock(black, sx + 4, sy, sz + 6);
	locateBlock(black, sx + 5, sy, sz + 6);
	locateBlock(black, sx + 6, sy, sz + 6);
	locateBlock(black, sx + 7, sy, sz + 6);
	locateBlock(black, sx + 8, sy, sz + 6);
	locateBlock(black, sx + 9, sy, sz + 6);

	locateBlock(black, sx, sy, sz + 7);
	locateBlock(black, sx + 1, sy, sz + 7);
	locateBlock(black, sx + 2, sy, sz + 7);
	locateBlock(black, sx + 3, sy, sz + 7);
	locateBlock(black, sx + 4, sy, sz + 7);
	locateBlock(black, sx + 5, sy, sz + 7);
	locateBlock(black, sx + 6, sy, sz + 7);
	locateBlock(black, sx + 7, sy, sz + 7);
	locateBlock(black, sx + 8, sy, sz + 7);
	locateBlock(black, sx + 9, sy, sz + 7);

	locateBlock(black, sx, sy, sz + 8);
	locateBlock(black, sx + 1, sy, sz + 8);
	locateBlock(black, sx + 2, sy, sz + 8);
	locateBlock(black, sx + 3, sy, sz + 8);
	locateBlock(yellow, sx + 4, sy, sz + 8);
	locateBlock(yellow, sx + 5, sy, sz + 8);
	locateBlock(black, sx + 6, sy, sz + 8);
	locateBlock(black, sx + 7, sy, sz + 8);
	locateBlock(black, sx + 8, sy, sz + 8);
	locateBlock(black, sx + 9, sy, sz + 8);

	locateBlock(black, sx, sy, sz + 9);
	locateBlock(black, sx + 1, sy, sz + 9);
	locateBlock(black, sx + 2, sy, sz + 9);
	locateBlock(black, sx + 3, sy, sz + 9);
	locateBlock(yellow, sx + 4, sy, sz + 9);
	locateBlock(yellow, sx + 5, sy, sz + 9);
	locateBlock(black, sx + 6, sy, sz + 9);
	locateBlock(black, sx + 7, sy, sz + 9);
	locateBlock(black, sx + 8, sy, sz + 9);
	locateBlock(black, sx + 9, sy, sz + 9);
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void make_hong_cauburger(int sx, int sy, int sz) {
	BlockID air = createBlock(BLOCK_AIR);
	TerracottaID bread = createTerracotta(TERRACOTTA, COLOR_YELLOW);
	TerracottaID patty = createTerracotta(TERRACOTTA, COLOR_BROWN);
	WoolID lettuce = createWool(COLOR_LIME);

	//1층과 2층은 bread, 3층과 4층은 patty, 5층과 6층은 lettuce, 7층과 8층은 patty, 9층과 10층은 bread, 11층은 글자도트
	for (int i = sx; i <= sx + 19; i++) {
		for (int j = sz; j <= sz + 19; j++) {
			locateBlock(bread, i + 1, sy, j + 1);
			locateBlock(bread, i + 1, sy + 1, j + 1);
			locateBlock(patty, i + 1, sy + 2, j + 1);
			locateBlock(patty, i + 1, sy + 3, j + 1);
			locateBlock(patty, i + 1, sy + 6, j + 1);
			locateBlock(patty, i + 1, sy + 7, j + 1);
			locateBlock(bread, i + 1, sy + 8, j + 1);
			locateBlock(bread, i + 1, sy + 9, j + 1);
		}
	}

	for (int i = sy; i <= sy + 9; i++) {
		locateBlock(air, sx + 1, i, sz + 1);
		locateBlock(air, sx + 1, i, sz + 20);
		locateBlock(air, sx + 20, i, sz + 1);
		locateBlock(air, sx + 20, i, sz + 20);
	}
	for (int i = sx; i <= sx + 21; i++) {
		for (int j = sz; j <= sz + 21; j++) {
			locateBlock(lettuce, i, sy + 4, j);
			locateBlock(lettuce, i, sy + 5, j);
		}
	}

	for (int i = sy + 4; i <= sy + 5; i++) {
		locateBlock(air, sx, i, sz);
		locateBlock(air, sx, i, sz + 1);
		locateBlock(air, sx, i, sz + 20);
		locateBlock(air, sx, i, sz + 21);
		locateBlock(air, sx + 1, i, sz);
		locateBlock(air, sx + 1, i, sz + 21);
		locateBlock(air, sx + 20, i, sz);
		locateBlock(air, sx + 20, i, sz + 21);
		locateBlock(air, sx + 21, i, sz);
		locateBlock(air, sx + 21, i, sz + 1);
		locateBlock(air, sx + 21, i, sz + 20);
		locateBlock(air, sx + 21, i, sz + 21);
	}
	locateBlock(patty, sx + 19, sy + 10, sz + 4);
	locateBlock(patty, sx + 19, sy + 10, sz + 5);
	locateBlock(patty, sx + 19, sy + 10, sz + 6);
	locateBlock(patty, sx + 19, sy + 10, sz + 9);
	locateBlock(patty, sx + 19, sy + 10, sz + 10);
	locateBlock(patty, sx + 19, sy + 10, sz + 11);
	locateBlock(patty, sx + 19, sy + 10, sz + 12);
	locateBlock(patty, sx + 19, sy + 10, sz + 13);
	locateBlock(patty, sx + 19, sy + 10, sz + 16);
	locateBlock(patty, sx + 19, sy + 10, sz + 17);
	locateBlock(patty, sx + 19, sy + 10, sz + 18);
	locateBlock(patty, sx + 18, sy + 10, sz + 3);
	locateBlock(patty, sx + 18, sy + 10, sz + 7);
	locateBlock(patty, sx + 18, sy + 10, sz + 9);
	locateBlock(patty, sx + 18, sy + 10, sz + 11);
	locateBlock(patty, sx + 18, sy + 10, sz + 13);
	locateBlock(patty, sx + 18, sy + 10, sz + 15);
	locateBlock(patty, sx + 18, sy + 10, sz + 19);
	locateBlock(patty, sx + 17, sy + 10, sz + 3);
	locateBlock(patty, sx + 17, sy + 10, sz + 5);
	locateBlock(patty, sx + 17, sy + 10, sz + 7);
	locateBlock(patty, sx + 17, sy + 10, sz + 9);
	locateBlock(patty, sx + 17, sy + 10, sz + 11);
	locateBlock(patty, sx + 17, sy + 10, sz + 13);
	locateBlock(patty, sx + 17, sy + 10, sz + 15);
	locateBlock(patty, sx + 17, sy + 10, sz + 19);
	locateBlock(patty, sx + 16, sy + 10, sz + 3);
	locateBlock(patty, sx + 16, sy + 10, sz + 4);
	locateBlock(patty, sx + 16, sy + 10, sz + 5);
	locateBlock(patty, sx + 16, sy + 10, sz + 7);
	locateBlock(patty, sx + 16, sy + 10, sz + 9);
	locateBlock(patty, sx + 16, sy + 10, sz + 10);
	locateBlock(patty, sx + 16, sy + 10, sz + 12);
	locateBlock(patty, sx + 16, sy + 10, sz + 13);
	locateBlock(patty, sx + 16, sy + 10, sz + 15);
	locateBlock(patty, sx + 16, sy + 10, sz + 19);
	locateBlock(patty, sx + 13, sy + 10, sz + 3);
	locateBlock(patty, sx + 13, sy + 10, sz + 4);
	locateBlock(patty, sx + 13, sy + 10, sz + 5);
	locateBlock(patty, sx + 13, sy + 10, sz + 6);
	locateBlock(patty, sx + 13, sy + 10, sz + 7);
	locateBlock(patty, sx + 13, sy + 10, sz + 9);
	locateBlock(patty, sx + 13, sy + 10, sz + 10);
	locateBlock(patty, sx + 13, sy + 10, sz + 11);
	locateBlock(patty, sx + 13, sy + 10, sz + 12);
	locateBlock(patty, sx + 13, sy + 10, sz + 13);
	locateBlock(patty, sx + 13, sy + 10, sz + 15);
	locateBlock(patty, sx + 13, sy + 10, sz + 16);
	locateBlock(patty, sx + 13, sy + 10, sz + 17);
	locateBlock(patty, sx + 13, sy + 10, sz + 18);
	locateBlock(patty, sx + 12, sy + 10, sz + 3);
	locateBlock(patty, sx + 12, sy + 10, sz + 5);
	locateBlock(patty, sx + 12, sy + 10, sz + 7);
	locateBlock(patty, sx + 12, sy + 10, sz + 9);
	locateBlock(patty, sx + 12, sy + 10, sz + 11);
	locateBlock(patty, sx + 12, sy + 10, sz + 13);
	locateBlock(patty, sx + 12, sy + 10, sz + 16);
	locateBlock(patty, sx + 12, sy + 10, sz + 19);
	locateBlock(patty, sx + 11, sy + 10, sz + 3);
	locateBlock(patty, sx + 11, sy + 10, sz + 5);
	locateBlock(patty, sx + 11, sy + 10, sz + 7);
	locateBlock(patty, sx + 11, sy + 10, sz + 9);
	locateBlock(patty, sx + 11, sy + 10, sz + 11);
	locateBlock(patty, sx + 11, sy + 10, sz + 13);
	locateBlock(patty, sx + 11, sy + 10, sz + 16);
	locateBlock(patty, sx + 11, sy + 10, sz + 19);
	locateBlock(patty, sx + 10, sy + 10, sz + 3);
	locateBlock(patty, sx + 10, sy + 10, sz + 5);
	locateBlock(patty, sx + 10, sy + 10, sz + 7);
	locateBlock(patty, sx + 10, sy + 10, sz + 9);
	locateBlock(patty, sx + 10, sy + 10, sz + 11);
	locateBlock(patty, sx + 10, sy + 10, sz + 13);
	locateBlock(patty, sx + 10, sy + 10, sz + 16);
	locateBlock(patty, sx + 10, sy + 10, sz + 19);
	locateBlock(patty, sx + 9, sy + 10, sz + 3);
	locateBlock(patty, sx + 9, sy + 10, sz + 5);
	locateBlock(patty, sx + 9, sy + 10, sz + 7);
	locateBlock(patty, sx + 9, sy + 10, sz + 9);
	locateBlock(patty, sx + 9, sy + 10, sz + 11);
	locateBlock(patty, sx + 9, sy + 10, sz + 13);
	locateBlock(patty, sx + 9, sy + 10, sz + 15);
	locateBlock(patty, sx + 9, sy + 10, sz + 16);
	locateBlock(patty, sx + 9, sy + 10, sz + 17);
	locateBlock(patty, sx + 9, sy + 10, sz + 18);
	locateBlock(patty, sx + 6, sy + 10, sz + 3);
	locateBlock(patty, sx + 6, sy + 10, sz + 4);
	locateBlock(patty, sx + 6, sy + 10, sz + 5);
	locateBlock(patty, sx + 6, sy + 10, sz + 6);
	locateBlock(patty, sx + 6, sy + 10, sz + 7);
	locateBlock(patty, sx + 6, sy + 10, sz + 9);
	locateBlock(patty, sx + 6, sy + 10, sz + 10);
	locateBlock(patty, sx + 6, sy + 10, sz + 11);
	locateBlock(patty, sx + 6, sy + 10, sz + 12);
	locateBlock(patty, sx + 6, sy + 10, sz + 13);
	locateBlock(patty, sx + 6, sy + 10, sz + 16);
	locateBlock(patty, sx + 6, sy + 10, sz + 17);
	locateBlock(patty, sx + 6, sy + 10, sz + 18);
	locateBlock(patty, sx + 6, sy + 10, sz + 19);
	locateBlock(patty, sx + 5, sy + 10, sz + 5);
	locateBlock(patty, sx + 5, sy + 10, sz + 7);
	locateBlock(patty, sx + 5, sy + 10, sz + 11);
	locateBlock(patty, sx + 5, sy + 10, sz + 13);
	locateBlock(patty, sx + 5, sy + 10, sz + 15);
	locateBlock(patty, sx + 4, sy + 10, sz + 5);
	locateBlock(patty, sx + 4, sy + 10, sz + 7);
	locateBlock(patty, sx + 4, sy + 10, sz + 11);
	locateBlock(patty, sx + 4, sy + 10, sz + 13);
	locateBlock(patty, sx + 4, sy + 10, sz + 15);
	locateBlock(patty, sx + 3, sy + 10, sz + 4);
	locateBlock(patty, sx + 3, sy + 10, sz + 5);
	locateBlock(patty, sx + 3, sy + 10, sz + 7);
	locateBlock(patty, sx + 3, sy + 10, sz + 10);
	locateBlock(patty, sx + 3, sy + 10, sz + 11);
	locateBlock(patty, sx + 3, sy + 10, sz + 13);
	locateBlock(patty, sx + 3, sy + 10, sz + 15);
	locateBlock(patty, sx + 2, sy + 10, sz + 3);
	locateBlock(patty, sx + 2, sy + 10, sz + 5);
	locateBlock(patty, sx + 2, sy + 10, sz + 6);
	locateBlock(patty, sx + 2, sy + 10, sz + 7);
	locateBlock(patty, sx + 2, sy + 10, sz + 9);
	locateBlock(patty, sx + 2, sy + 10, sz + 11);
	locateBlock(patty, sx + 2, sy + 10, sz + 12);
	locateBlock(patty, sx + 2, sy + 10, sz + 13);
	locateBlock(patty, sx + 2, sy + 10, sz + 16);
	locateBlock(patty, sx + 2, sy + 10, sz + 17);
	locateBlock(patty, sx + 2, sy + 10, sz + 18);
	locateBlock(patty, sx + 2, sy + 10, sz + 19);


}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void make_hong_seven(int sx, int sy, int sz) {
	BlockID stone = createBlock(BLOCK_STONE);
	WoolID orange = createWool(COLOR_ORANGE);
	WoolID lime = createWool(COLOR_LIME);
	WoolID yellow = createWool(COLOR_YELLOW);
	WoolID white = createWool(COLOR_WHITE);
	PaneID glass = createPane(PANE_GLASS);

	for (int i = sx; i <= sx + 34; i++) {
		for (int j = sz; j <= sz + 34; j++) {
			for (int k = sy; k <= sy + 9; k++) {
				locateBlock(stone, i, k, j);
			}
		}
	}
	for (int i = sx; i <= sx + 34; i++) {
		for (int j = sz; j <= sz + 34; j++) {
			locateBlock(white, i, sy + 10, j);
			locateBlock(orange, i, sy + 11, j);
			locateBlock(lime, i, sy + 12, j);
			locateBlock(lime, i, sy + 13, j);
			locateBlock(lime, i, sy + 14, j);
			locateBlock(yellow, i, sy + 15, j);
			locateBlock(white, i, sy + 16, j);
			locateBlock(stone, i, sy + 17, j);
			locateBlock(stone, i, sy, j);
		}
	}
	for (int i = sx; i <= sx + 34; i++) {
		for (int j = sy + 1; j <= sy + 8;j++) {
			locateBlock(glass, i, j, sz);
		}
	}
	for (int i = sx; i <= sx + 34; i++) {
		for (int j = sy + 1; j <= sy + 8; j++) {
			locateBlock(glass, i, j, sz + 34);
		}
	}
	for (int i = sz; i <= sz + 34; i++) {
		for (int j = sy + 1; j <= sy + 8; j++) {
			locateBlock(glass, sx, j, i);
		}
	}
	for (int i = sz; i <= sz + 34; i++) {
		for (int j = sy + 1; j <= sy + 8; j++) {
			locateBlock(glass, sx + 34, j, i);
		}
	}
	for (int i = sy + 1; i <= sy + 8; i++) {
		locateBlock(stone, sx + 34, i, sz + 34);
	}

	for (int i = sy + 1; i <= sy + 8; i++) {
		for (int j = sx; j <= sx + 34; j = j + 11) {
			locateBlock(stone, j, i, sz);
		}
	}
	for (int i = sy + 1; i <= sy + 8; i++) {
		for (int j = sz; j <= sz + 34; j = j + 11) {
			locateBlock(stone, sx, i, j);
		}
	}
	for (int i = sy + 1; i <= sy + 8; i++) {
		for (int j = sz; j <= sz + 34; j = j + 11) {
			locateBlock(stone, sx + 34, i, j);
		}
	}
	for (int i = sy + 1; i <= sy + 8; i++) {
		for (int j = sx; j <= sx + 34; j = j + 11) {
			locateBlock(stone, j, i, sz + 34);
		}
	}
	locateBlock(white, sx + 14, sy + 11, sz);
	locateBlock(white, sx + 14, sy + 12, sz);
	locateBlock(white, sx + 14, sy + 13, sz);
	locateBlock(white, sx + 14, sy + 14, sz);
	locateBlock(white, sx + 14, sy + 15, sz);
	locateBlock(white, sx + 15, sy + 11, sz);
	locateBlock(white, sx + 15, sy + 13, sz);
	locateBlock(white, sx + 15, sy + 14, sz);
	locateBlock(orange, sx + 15, sy + 15, sz);
	locateBlock(white, sx + 16, sy + 11, sz);
	locateBlock(white, sx + 16, sy + 13, sz);
	locateBlock(orange, sx + 16, sy + 14, sz);
	locateBlock(orange, sx + 17, sy + 11, sz);
	locateBlock(orange, sx + 17, sy + 13, sz);
	locateBlock(white, sx + 17, sy + 14, sz);
	locateBlock(white, sx + 18, sy + 11, sz);
	locateBlock(white, sx + 18, sy + 13, sz);
	locateBlock(white, sx + 18, sy + 14, sz);
	locateBlock(white, sx + 19, sy + 11, sz);
	locateBlock(white, sx + 19, sy + 13, sz);
	locateBlock(white, sx + 19, sy + 14, sz);
	locateBlock(white, sx + 20, sy + 11, sz);
	locateBlock(white, sx + 20, sy + 12, sz);
	locateBlock(white, sx + 20, sy + 13, sz);
	locateBlock(white, sx + 20, sy + 14, sz);
	locateBlock(white, sx + 20, sy + 15, sz);

	locateBlock(white, sx + 14, sy + 11, sz + 34);
	locateBlock(white, sx + 14, sy + 12, sz + 34);
	locateBlock(white, sx + 14, sy + 13, sz + 34);
	locateBlock(white, sx + 14, sy + 14, sz + 34);
	locateBlock(white, sx + 14, sy + 15, sz + 34);
	locateBlock(white, sx + 15, sy + 11, sz + 34);
	locateBlock(white, sx + 15, sy + 13, sz + 34);
	locateBlock(white, sx + 15, sy + 14, sz + 34);
	locateBlock(orange, sx + 19, sy + 15, sz + 34);
	locateBlock(white, sx + 16, sy + 11, sz + 34);
	locateBlock(white, sx + 16, sy + 13, sz + 34);
	locateBlock(orange, sx + 18, sy + 14, sz + 34);
	locateBlock(orange, sx + 17, sy + 11, sz + 34);
	locateBlock(orange, sx + 17, sy + 13, sz + 34);
	locateBlock(white, sx + 17, sy + 14, sz + 34);
	locateBlock(white, sx + 18, sy + 11, sz + 34);
	locateBlock(white, sx + 18, sy + 13, sz + 34);
	locateBlock(white, sx + 16, sy + 14, sz + 34);
	locateBlock(white, sx + 19, sy + 11, sz + 34);
	locateBlock(white, sx + 19, sy + 13, sz + 34);
	locateBlock(white, sx + 19, sy + 14, sz + 34);
	locateBlock(white, sx + 20, sy + 11, sz + 34);
	locateBlock(white, sx + 20, sy + 12, sz + 34);
	locateBlock(white, sx + 20, sy + 13, sz + 34);
	locateBlock(white, sx + 20, sy + 14, sz + 34);
	locateBlock(white, sx + 20, sy + 15, sz + 34);

	locateBlock(white, sx, sy + 11, sz + 14);
	locateBlock(white, sx, sy + 12, sz + 14);
	locateBlock(white, sx, sy + 13, sz + 14);
	locateBlock(white, sx, sy + 14, sz + 14);
	locateBlock(white, sx, sy + 15, sz + 14);
	locateBlock(white, sx, sy + 11, sz + 15);
	locateBlock(white, sx, sy + 13, sz + 15);
	locateBlock(white, sx, sy + 14, sz + 15);
	locateBlock(orange, sx, sy + 15, sz + 19);
	locateBlock(white, sx, sy + 11, sz + 16);
	locateBlock(white, sx, sy + 13, sz + 16);
	locateBlock(orange, sx, sy + 14, sz + 18);
	locateBlock(orange, sx, sy + 11, sz + 17);
	locateBlock(orange, sx, sy + 13, sz + 17);
	locateBlock(white, sx, sy + 14, sz + 17);
	locateBlock(white, sx, sy + 11, sz + 18);
	locateBlock(white, sx, sy + 13, sz + 18);
	locateBlock(white, sx, sy + 14, sz + 16);
	locateBlock(white, sx, sy + 11, sz + 19);
	locateBlock(white, sx, sy + 13, sz + 19);
	locateBlock(white, sx, sy + 14, sz + 19);
	locateBlock(white, sx, sy + 11, sz + 20);
	locateBlock(white, sx, sy + 12, sz + 20);
	locateBlock(white, sx, sy + 13, sz + 20);
	locateBlock(white, sx, sy + 14, sz + 20);
	locateBlock(white, sx, sy + 15, sz + 20);

	locateBlock(white, sx + 34, sy + 11, sz + 14);
	locateBlock(white, sx + 34, sy + 12, sz + 14);
	locateBlock(white, sx + 34, sy + 13, sz + 14);
	locateBlock(white, sx + 34, sy + 14, sz + 14);
	locateBlock(white, sx + 34, sy + 15, sz + 14);
	locateBlock(white, sx + 34, sy + 11, sz + 15);
	locateBlock(white, sx + 34, sy + 13, sz + 15);
	locateBlock(white, sx + 34, sy + 14, sz + 15);
	locateBlock(orange, sx + 34, sy + 15, sz + 15);
	locateBlock(white, sx + 34, sy + 11, sz + 16);
	locateBlock(white, sx + 34, sy + 13, sz + 16);
	locateBlock(orange, sx + 34, sy + 14, sz + 16);
	locateBlock(orange, sx + 34, sy + 11, sz + 17);
	locateBlock(orange, sx + 34, sy + 13, sz + 17);
	locateBlock(white, sx + 34, sy + 14, sz + 17);
	locateBlock(white, sx + 34, sy + 11, sz + 18);
	locateBlock(white, sx + 34, sy + 13, sz + 18);
	locateBlock(white, sx + 34, sy + 14, sz + 18);
	locateBlock(white, sx + 34, sy + 11, sz + 19);
	locateBlock(white, sx + 34, sy + 13, sz + 19);
	locateBlock(white, sx + 34, sy + 14, sz + 19);
	locateBlock(white, sx + 34, sy + 11, sz + 20);
	locateBlock(white, sx + 34, sy + 12, sz + 20);
	locateBlock(white, sx + 34, sy + 13, sz + 20);
	locateBlock(white, sx + 34, sy + 14, sz + 20);
	locateBlock(white, sx + 34, sy + 15, sz + 20);


}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void make101(int sx, int sy, int sz) {
	BlockID c = createBlock(BLOCK_COBBLESTONE);
	BlockID grass = createBlock(BLOCK_EMERALD);
	BlockID wood = createBlock(BLOCK_GOLD);
	BlockID g = createBlock(BLOCK_GLASS);
	BlockID o = createBlock(BLOCK_OBSIDIAN);

	int x = sx-98, y = sy-4, z = sz-93;
	//공백 메꾸기
	locateBlock(g, 100 +x , 18+y, 100+z);
					      
	locateBlock(c, 100   +x , 19+y, 100+z);
	locateBlock(c, 101   +x , 19+y, 100+z);
	locateBlock(c, 102   +x , 19+y, 100+z);
	locateBlock(c, 103   +x , 19+y, 100+z);
	locateBlock(c, 104   +x , 19+y, 100+z);
	locateBlock(c, 105   +x , 19+y, 100+z);
	locateBlock(c, 106   +x , 19+y, 100+z);
	locateBlock(c, 107   +x , 19+y, 100+z);
					     			   
	locateBlock(c, 102   +x , 20+y, 100+z);
	locateBlock(c, 103   +x , 20+y, 100+z);
	locateBlock(c, 104   +x , 20+y, 100+z);
	locateBlock(c, 105   +x , 20+y, 100+z);
					     			   
	locateBlock(c, 142   +x , 19+y, 100+z);
	locateBlock(c, 143   +x , 19+y, 100+z);
	locateBlock(c, 144   +x , 19+y, 100+z);
	locateBlock(c, 145   +x , 19+y, 100+z);
	locateBlock(c, 146   +x , 19+y, 100+z);
	locateBlock(c, 147   +x , 19+y, 100+z);
	locateBlock(c, 148   +x , 19+y, 100+z);
	locateBlock(c, 149   +x , 19+y, 100+z);
					     			   
	locateBlock(c, 144   +x , 20+y, 100+z);
	locateBlock(c, 145   +x , 20+y, 100+z);
	locateBlock(c, 146   +x , 20+y, 100+z);
	locateBlock(c, 147   +x , 20+y, 100+z);
					     		
	locateBlock(c, 114   +x , 11+y, 97+z);
	locateBlock(c, 118   +x , 11+y, 97+z);
	locateBlock(c, 119   +x , 11+y, 97+z);
	locateBlock(c, 122   +x , 11+y, 97+z);
					     		
	locateBlock(c, 127   +x , 11+y, 97+z);
	locateBlock(c, 130   +x , 11+y, 97+z);
	locateBlock(c, 131   +x , 11+y, 97+z);
	locateBlock(c, 135   +x , 11+y, 97+z);

	//장식
	locateBlock(grass, 98 +x, 4+y, 102+z);
	locateBlock(grass, 99 +x, 4+y, 102+z);
	locateBlock(grass, 100+x, 4+y, 102+z);
	locateBlock(grass, 101+x, 4+y, 102+z);
	locateBlock(grass, 102+x, 4+y, 102+z);
	locateBlock(grass, 103+x, 4+y, 102+z);
	locateBlock(grass, 104+x, 4+y, 102+z);
	locateBlock(grass, 105+x, 4+y, 102+z);
	locateBlock(grass, 106+x, 4+y, 102+z);
	locateBlock(grass, 107+x, 4+y, 102+z);
	locateBlock(grass, 108+x, 4+y, 102+z);
	locateBlock(grass, 109+x, 4+y, 102+z);
						  	   		  
	locateBlock(grass, 140+x, 4+y, 102+z);
	locateBlock(grass, 141+x, 4+y, 102+z);
	locateBlock(grass, 142+x, 4+y, 102+z);
	locateBlock(grass, 143+x, 4+y, 102+z);
	locateBlock(grass, 144+x, 4+y, 102+z);
	locateBlock(grass, 145+x, 4+y, 102+z);
	locateBlock(grass, 146+x, 4+y, 102+z);
	locateBlock(grass, 147+x, 4+y, 102+z);
	locateBlock(grass, 148+x, 4+y, 102+z);
	locateBlock(grass, 149+x, 4+y, 102+z);
	locateBlock(grass, 150+x, 4+y, 102+z);
	locateBlock(grass, 151+x, 4+y, 102+z);
						  	   		  
	locateBlock(wood, 100 +x, 4+y, 104+z);
	locateBlock(wood, 100 +x, 5+y, 104+z);
	locateBlock(grass, 100+x, 6+y, 104+z);
						  	   		  
	locateBlock(wood, 107 +x, 4+y, 104+z);
	locateBlock(wood, 107 +x, 5+y, 104+z);
	locateBlock(grass, 107+x, 6+y, 104+z);
						  	   		  
	locateBlock(wood, 113 +x, 4+y, 100+z);
	locateBlock(wood, 113 +x, 5+y, 100+z);
	locateBlock(grass, 113+x, 6+y, 100+z);
						  	   		  
	locateBlock(wood, 120 +x, 4+y, 100+z);
	locateBlock(wood, 120 +x, 5+y, 100+z);
	locateBlock(grass, 120+x, 6+y, 100+z);
						  	   		  
	locateBlock(wood, 129 +x, 4+y, 100+z);
	locateBlock(wood, 129 +x, 5+y, 100+z);
	locateBlock(grass, 129+x, 6+y, 100+z);
						  	   		  
	locateBlock(wood, 136 +x, 4+y, 100+z);
	locateBlock(wood, 136 +x, 5+y, 100+z);
	locateBlock(grass, 136+x, 6+y, 100+z);
						  	   		  
	locateBlock(wood, 142 +x, 4+y, 104+z);
	locateBlock(wood, 142 +x, 5+y, 104+z);
	locateBlock(grass, 142+x, 6+y, 104+z);
						  	   		  
	locateBlock(wood, 149 +x, 4+y, 104+z);
	locateBlock(wood, 149 +x, 5+y, 104+z);
	locateBlock(grass, 149+x, 6+y, 104+z);
						  
	//지붕				
	locateBlock(o, 98     +x, 19+y, 93+z);
	locateBlock(o, 98     +x, 19+y, 94+z);
	locateBlock(o, 98     +x, 19+y, 95+z);
	locateBlock(o, 98     +x, 19+y, 96+z);
	locateBlock(o, 98     +x, 19+y, 97+z);
	locateBlock(o, 98     +x, 19+y, 98+z);
	locateBlock(o, 98     +x, 19+y, 99+z);
	locateBlock(o, 98     +x, 19+y, 100+z);
	locateBlock(o, 99     +x, 19+y, 93+z);
	locateBlock(o, 99     +x, 19+y, 94+z);
	locateBlock(o, 99     +x, 19+y, 95+z);
	locateBlock(o, 99     +x, 19+y, 96+z);
	locateBlock(o, 99     +x, 19+y, 97+z);
	locateBlock(o, 99     +x, 19+y, 98+z);
	locateBlock(o, 99     +x, 19+y, 99+z);
	locateBlock(o, 99     +x, 19+y, 100+z);
					      
					      
	locateBlock(o, 100+x, 19+y, 93+z);
	locateBlock(o, 101+x, 19+y, 93+z);
	locateBlock(o, 102+x, 19+y, 93+z);
	locateBlock(o, 103+x, 19+y, 93+z);
	locateBlock(o, 104+x, 19+y, 93+z);
	locateBlock(o, 105+x, 19+y, 93+z);
	locateBlock(o, 106+x, 19+y, 93+z);
	locateBlock(o, 107+x, 19+y, 93+z);
	locateBlock(o, 108+x, 19+y, 93+z);
	locateBlock(o, 109+x, 19+y, 93+z);
	locateBlock(o, 110+x, 19+y, 93+z);
	locateBlock(o, 111+x, 19+y, 93+z);
	locateBlock(o, 112+x, 19+y, 93+z);
	locateBlock(o, 113+x, 19+y, 93+z);
	locateBlock(o, 114+x, 19+y, 93+z);
	locateBlock(o, 115+x, 19+y, 93+z);
	locateBlock(o, 116+x, 19+y, 93+z);
	locateBlock(o, 117+x, 19+y, 93+z);
	locateBlock(o, 118+x, 19+y, 93+z);
	locateBlock(o, 119+x, 19+y, 93+z);
	locateBlock(o, 120+x, 19+y, 93+z);
	locateBlock(o, 121+x, 19+y, 93+z);
	locateBlock(o, 122+x, 19+y, 93+z);

	locateBlock(o, 127+x, 19+y, 93+z);
	locateBlock(o, 128+x, 19+y, 93+z);
	locateBlock(o, 129+x, 19+y, 93+z);
	locateBlock(o, 130+x, 19+y, 93+z);
	locateBlock(o, 131+x, 19+y, 93+z);
	locateBlock(o, 132+x, 19+y, 93+z);
	locateBlock(o, 133+x, 19+y, 93+z);
	locateBlock(o, 134+x, 19+y, 93+z);
	locateBlock(o, 135+x, 19+y, 93+z);
	locateBlock(o, 136+x, 19+y, 93+z);
	locateBlock(o, 137+x, 19+y, 93+z);
	locateBlock(o, 138+x, 19+y, 93+z);
	locateBlock(o, 139+x, 19+y, 93+z);
	locateBlock(o, 140+x, 19+y, 93+z);
	locateBlock(o, 141+x, 19+y, 93+z);
	locateBlock(o, 142+x, 19+y, 93+z);
	locateBlock(o, 143+x, 19+y, 93+z);
	locateBlock(o, 144+x, 19+y, 93+z);
	locateBlock(o, 145+x, 19+y, 93+z);
	locateBlock(o, 146+x, 19+y, 93+z);
	locateBlock(o, 147+x, 19+y, 93+z);
	locateBlock(o, 148+x, 19+y, 93+z);
	locateBlock(o, 149+x, 19+y, 93+z);

	locateBlock(o, 150+x, 19+y, 93+z);
	locateBlock(o, 150+x, 19+y, 94+z);
	locateBlock(o, 150+x, 19+y, 95+z);
	locateBlock(o, 150+x, 19+y, 96+z);
	locateBlock(o, 150+x, 19+y, 97+z);
	locateBlock(o, 150+x, 19+y, 98+z);
	locateBlock(o, 150+x, 19+y, 99+z);
	locateBlock(o, 150+x, 19+y, 100+z);
	locateBlock(o, 151+x, 19+y, 93+z);
	locateBlock(o, 151+x, 19+y, 94+z);
	locateBlock(o, 151+x, 19+y, 95+z);
	locateBlock(o, 151+x, 19+y, 96+z);
	locateBlock(o, 151+x, 19+y, 97+z);
	locateBlock(o, 151+x, 19+y, 98+z);
	locateBlock(o, 151+x, 19+y, 99+z);
	locateBlock(o, 151+x, 19+y, 100+z);

	locateBlock(o, 148+x, 20+y, 94+z);
	locateBlock(o, 148+x, 20+y, 95+z);
	locateBlock(o, 148+x, 20+y, 96+z);
	locateBlock(o, 148+x, 20+y, 97+z);
	locateBlock(o, 148+x, 20+y, 98+z);
	locateBlock(o, 148+x, 20+y, 99+z);
	locateBlock(o, 148+x, 20+y, 100+z);
	locateBlock(o, 149+x, 20+y, 93+z);
	locateBlock(o, 149+x, 20+y, 94+z);
	locateBlock(o, 149+x, 20+y, 95+z);
	locateBlock(o, 149+x, 20+y, 96+z);
	locateBlock(o, 149+x, 20+y, 97+z);
	locateBlock(o, 149+x, 20+y, 98+z);
	locateBlock(o, 149+x, 20+y, 99+z);
	locateBlock(o, 149+x, 20+y, 100+z);


	locateBlock(o, 100+x, 20+y, 94+z);
	locateBlock(o, 100+x, 20+y, 95+z);
	locateBlock(o, 100+x, 20+y, 96+z);
	locateBlock(o, 100+x, 20+y, 97+z);
	locateBlock(o, 100+x, 20+y, 98+z);
	locateBlock(o, 100+x, 20+y, 99+z);
	locateBlock(o, 100+x, 20+y, 100+z);
	locateBlock(o, 101+x, 20+y, 93+z);
	locateBlock(o, 101+x, 20+y, 94+z);
	locateBlock(o, 101+x, 20+y, 95+z);
	locateBlock(o, 101+x, 20+y, 96+z);
	locateBlock(o, 101+x, 20+y, 97+z);
	locateBlock(o, 101+x, 20+y, 98+z);
	locateBlock(o, 101+x, 20+y, 99+z);
	locateBlock(o, 101+x, 20+y, 100+z);

	locateBlock(o, 102+x, 20+y, 94+z);
	locateBlock(o, 103+x, 20+y, 94+z);
	locateBlock(o, 104+x, 20+y, 94+z);
	locateBlock(o, 105+x, 20+y, 94+z);
	locateBlock(o, 106+x, 20+y, 94+z);
	locateBlock(o, 107+x, 20+y, 94+z);
	locateBlock(o, 108+x, 20+y, 94+z);
	locateBlock(o, 109+x, 20+y, 94+z);
	locateBlock(o, 110+x, 20+y, 94+z);
	locateBlock(o, 111+x, 20+y, 94+z);
	locateBlock(o, 112+x, 20+y, 94+z);
	locateBlock(o, 113+x, 20+y, 94+z);
	locateBlock(o, 114+x, 20+y, 94+z);
	locateBlock(o, 115+x, 20+y, 94+z);
	locateBlock(o, 116+x, 20+y, 94+z);
	locateBlock(o, 117+x, 20+y, 94+z);
	locateBlock(o, 118+x, 20+y, 94+z);
	locateBlock(o, 119+x, 20+y, 94+z);
	locateBlock(o, 120+x, 20+y, 94+z);
	locateBlock(o, 121+x, 20+y, 94+z);
	locateBlock(o, 122+x, 20+y, 94+z);
	locateBlock(o, 123+x, 20+y, 94+z);
	locateBlock(o, 124+x, 20+y, 94+z);
	locateBlock(o, 125+x, 20+y, 94+z);
	locateBlock(o, 126+x, 20+y, 94+z);
	locateBlock(o, 127+x, 20+y, 94+z);
	locateBlock(o, 128+x, 20+y, 94+z);
	locateBlock(o, 129+x, 20+y, 94+z);
	locateBlock(o, 130+x, 20+y, 94+z);
	locateBlock(o, 131+x, 20+y, 94+z);
	locateBlock(o, 132+x, 20+y, 94+z);
	locateBlock(o, 133+x, 20+y, 94+z);
	locateBlock(o, 134+x, 20+y, 94+z);
	locateBlock(o, 135+x, 20+y, 94+z);
	locateBlock(o, 136+x, 20+y, 94+z);
	locateBlock(o, 137+x, 20+y, 94+z);
	locateBlock(o, 138+x, 20+y, 94+z);
	locateBlock(o, 139+x, 20+y, 94+z);
	locateBlock(o, 140+x, 20+y, 94+z);
	locateBlock(o, 141+x, 20+y, 94+z);
	locateBlock(o, 142+x, 20+y, 94+z);
	locateBlock(o, 143+x, 20+y, 94+z);
	locateBlock(o, 144+x, 20+y, 94+z);
	locateBlock(o, 145+x, 20+y, 94+z);
	locateBlock(o, 146+x, 20+y, 94+z);
	locateBlock(o, 147+x, 20+y, 94+z);

	locateBlock(o, 147+x, 21+y, 95+z);
	locateBlock(o, 147+x, 21+y, 96+z);
	locateBlock(o, 147+x, 21+y, 97+z);
	locateBlock(o, 147+x, 21+y, 98+z);
	locateBlock(o, 147+x, 21+y, 99+z);
	locateBlock(o, 147+x, 21+y, 100+z);

	locateBlock(o, 146+x, 21+y, 95+z);
	locateBlock(o, 146+x, 21+y, 96+z);
	locateBlock(o, 146+x, 21+y, 97+z);
	locateBlock(o, 146+x, 21+y, 98+z);
	locateBlock(o, 146+x, 21+y, 99+z);
	locateBlock(o, 146+x, 21+y, 100+z);

	locateBlock(o, 145+x, 21+y, 95+z);
	locateBlock(o, 145+x, 21+y, 96+z);
	locateBlock(o, 145+x, 21+y, 97+z);
	locateBlock(o, 145+x, 21+y, 98+z);
	locateBlock(o, 145+x, 21+y, 99+z);
	locateBlock(o, 145+x, 21+y, 100+z);

	locateBlock(o, 144+x, 21+y, 95+z);
	locateBlock(o, 144+x, 21+y, 96+z);
	locateBlock(o, 144+x, 21+y, 97+z);
	locateBlock(o, 144+x, 21+y, 98+z);
	locateBlock(o, 144+x, 21+y, 99+z);
	locateBlock(o, 144+x, 21+y, 100+z);

	locateBlock(o, 127+x, 21+y, 95+z);
	locateBlock(o, 128+x, 21+y, 95+z);
	locateBlock(o, 129+x, 21+y, 95+z);
	locateBlock(o, 130+x, 21+y, 95+z);
	locateBlock(o, 131+x, 21+y, 95+z);
	locateBlock(o, 132+x, 21+y, 95+z);
	locateBlock(o, 133+x, 21+y, 95+z);
	locateBlock(o, 134+x, 21+y, 95+z);
	locateBlock(o, 135+x, 21+y, 95+z);
	locateBlock(o, 136+x, 21+y, 95+z);
	locateBlock(o, 137+x, 21+y, 95+z);
	locateBlock(o, 138+x, 21+y, 95+z);
	locateBlock(o, 139+x, 21+y, 95+z);
	locateBlock(o, 140+x, 21+y, 95+z);
	locateBlock(o, 141+x, 21+y, 95+z);
	locateBlock(o, 142+x, 21+y, 95+z);
	locateBlock(o, 143+x, 21+y, 95+z);

	locateBlock(o, 106+x, 21+y, 95+z);
	locateBlock(o, 107+x, 21+y, 95+z);
	locateBlock(o, 108+x, 21+y, 95+z);
	locateBlock(o, 109+x, 21+y, 95+z);
	locateBlock(o, 110+x, 21+y, 95+z);
	locateBlock(o, 111+x, 21+y, 95+z);
	locateBlock(o, 112+x, 21+y, 95+z);
	locateBlock(o, 113+x, 21+y, 95+z);
	locateBlock(o, 114+x, 21+y, 95+z);
	locateBlock(o, 115+x, 21+y, 95+z);
	locateBlock(o, 116+x, 21+y, 95+z);
	locateBlock(o, 117+x, 21+y, 95+z);
	locateBlock(o, 118+x, 21+y, 95+z);
	locateBlock(o, 119+x, 21+y, 95+z);
	locateBlock(o, 120+x, 21+y, 95+z);
	locateBlock(o, 121+x, 21+y, 95+z);
	locateBlock(o, 122+x, 21+y, 95+z);

	locateBlock(o, 102+x, 21+y, 95+z);
	locateBlock(o, 102+x, 21+y, 96+z);
	locateBlock(o, 102+x, 21+y, 97+z);
	locateBlock(o, 102+x, 21+y, 98+z);
	locateBlock(o, 102+x, 21+y, 99+z);
	locateBlock(o, 102+x, 21+y, 100+z);

	locateBlock(o, 103+x, 21+y, 95+z);
	locateBlock(o, 103+x, 21+y, 96+z);
	locateBlock(o, 103+x, 21+y, 97+z);
	locateBlock(o, 103+x, 21+y, 98+z);
	locateBlock(o, 103+x, 21+y, 99+z);
	locateBlock(o, 103+x, 21+y, 100+z);

	locateBlock(o, 104+x, 21+y, 95+z);
	locateBlock(o, 104+x, 21+y, 96+z);
	locateBlock(o, 104+x, 21+y, 97+z);
	locateBlock(o, 104+x, 21+y, 98+z);
	locateBlock(o, 104+x, 21+y, 99+z);
	locateBlock(o, 104+x, 21+y, 100+z);

	locateBlock(o, 105+x, 21+y, z+95);
	locateBlock(o, 105+x, 21+y, z+96);
	locateBlock(o, 105+x, 21+y, z+97);
	locateBlock(o, 105+x, 21+y, z+98);
	locateBlock(o, 105+x, 21+y, z+99);
	locateBlock(o, 105+x, 21+y, z+100);

	locateBlock(o, 106+x, 20+y, z+100);
	locateBlock(o, 106+x, 20+y, z+99);
	locateBlock(o, 106+x, 20+y, z+98);
	locateBlock(o, 106+x, 20+y, z+97);
	locateBlock(o, 106+x, 20+y, z+96);

	locateBlock(o, 107+x, 20+y, z+100);
	locateBlock(o, 107+x, 20+y, z+99);
	locateBlock(o, 107+x, 20+y, z+98);
	locateBlock(o, 107+x, 20+y, z+97);
	locateBlock(o, 107+x, 20+y, z+96);

	locateBlock(o, 108+x, 20+y, z+96);
	locateBlock(o, 109+x, 20+y, z+96);
	locateBlock(o, 110+x, 20+y, z+96);
	locateBlock(o, 111+x, 20+y, z+96);
	locateBlock(o, 112+x, 20+y, z+96);
	locateBlock(o, 113+x, 20+y, z+96);
	locateBlock(o, 114+x, 20+y, z+96);
	locateBlock(o, 115+x, 20+y, z+96);
	locateBlock(o, 116+x, 20+y, z+96);
	locateBlock(o, 117+x, 20+y, z+96);
	locateBlock(o, 118+x, 20+y, z+96);
	locateBlock(o, 119+x, 20+y, z+96);
	locateBlock(o, 120+x, 20+y, z+96);
	locateBlock(o, 121+x, 20+y, z+96);
	locateBlock(o, 122+x, 20+y, z+96);

	locateBlock(o, 127+x, 20+y, z+96);
	locateBlock(o, 128+x, 20+y, z+96);
	locateBlock(o, 129+x, 20+y, z+96);
	locateBlock(o, 130+x, 20+y, z+96);
	locateBlock(o, 131+x, 20+y, z+96);
	locateBlock(o, 132+x, 20+y, z+96);
	locateBlock(o, 133+x, 20+y, z+96);
	locateBlock(o, 134+x, 20+y, z+96);
	locateBlock(o, 135+x, 20+y, z+96);
	locateBlock(o, 136+x, 20+y, z+96);
	locateBlock(o, 137+x, 20+y, z+96);
	locateBlock(o, 138+x, 20+y, z+96);
	locateBlock(o, 139+x, 20+y, z+96);
	locateBlock(o, 140+x, 20+y, z+96);
	locateBlock(o, 141+x, 20+y, z+96);

	//정면 가장 바깥쪽+x 중 왼쪽
	locateBlock(c, 110+x, y+4, z+97);
	locateBlock(c, 110+x, y+5, z+97);
	locateBlock(c, 110+x, y+6, z+97);
	locateBlock(c, 110+x, y+7, z+97);
	locateBlock(c, 110+x, y+8, z+97);
	locateBlock(c, 110+x, y+9, z+97);
	locateBlock(c, 110+x, y+10,z+ 97);
	locateBlock(c, 110+x, y+11,z+ 97);
	locateBlock(c, 110+x, y+12,z+ 97);
	locateBlock(c, 110+x, y+13,z+ 97);
	locateBlock(c, 110+x, y+14,z+ 97);
	locateBlock(c, 110+x, y+15,z+ 97);
	locateBlock(c, 110+x, y+16,z+ 97);
	locateBlock(c, 110+x, y+17,z+ 97);
	locateBlock(c, 110+x, y+18,z+ 97);

	locateBlock(c, 111+x, y+4, z+97);
	locateBlock(c, 111+x, y+5, z+97);
	locateBlock(c, 111+x, y+6, z+97);
	locateBlock(g, 111+x, y+7, z+97);
	locateBlock(g, 111+x, y+8, z+97);
	locateBlock(g, 111+x, y+9, z+97);
	locateBlock(g, 111+x, y+10,z+ 97);
	locateBlock(g, 111+x, y+11,z+ 97);
	locateBlock(g, 111+x, y+12,z+ 97);
	locateBlock(c, 111+x, y+13,z+ 97);
	locateBlock(c, 111+x, y+14,z+ 97);
	locateBlock(g, 111+x, y+15,z+ 97);
	locateBlock(g, 111+x, y+16,z+ 97);
	locateBlock(g, 111+x, y+17,z+ 97);
	locateBlock(c, 111+x, y+18,z+ 97);

	locateBlock(c, 112+x, y+4, z+97);
	locateBlock(c, 112+x, y+5, z+97);
	locateBlock(c, 112+x, y+6, z+97);
	locateBlock(g, 112+x, y+7, z+97);
	locateBlock(g, 112+x, y+8, z+97);
	locateBlock(g, 112+x, y+9, z+97);
	locateBlock(g, 112+x, y+10,z+ 97);
	locateBlock(g, 112+x, y+11,z+ 97);
	locateBlock(g, 112+x, y+12,z+ 97);
	locateBlock(c, 112+x, y+13,z+ 97);
	locateBlock(c, 112+x, y+14,z+ 97);
	locateBlock(g, 112+x, y+15,z+ 97);
	locateBlock(g, 112+x, y+16,z+ 97);
	locateBlock(g, 112+x, y+17,z+ 97);
	locateBlock(c, 112+x, y+18,z+ 97);

	locateBlock(c, 113+x, y+4, z+97);
	locateBlock(c, 113+x, y+5, z+97);
	locateBlock(c, 113+x, y+6, z+97);
	locateBlock(c, 113+x, y+7, z+97);
	locateBlock(c, 113+x, y+8, z+97);
	locateBlock(c, 113+x, y+9, z+97);
	locateBlock(c, 113+x, y+10,z+ 97);
	locateBlock(c, 113+x, y+11,z+ 97);
	locateBlock(c, 113+x, y+12,z+ 97);
	locateBlock(c, 113+x, y+13,z+ 97);
	locateBlock(c, 113+x, y+14,z+ 97);
	locateBlock(c, 113+x, y+15,z+ 97);
	locateBlock(c, 113+x, y+16,z+ 97);
	locateBlock(c, 113+x, y+17,z+ 97);
	locateBlock(c, 113+x, y+18,z+ 97);


	locateBlock(o, 143+x, y+20,z+ 100);
	locateBlock(o, 143+x, y+20,z+ 99);
	locateBlock(o, 143+x, y+20,z+ 98);
	locateBlock(o, 143+x, y+20,z+ 97);
	locateBlock(o, 143+x, y+20,z+ 96);

	locateBlock(o, 142+x, y+20,z+ 100);
	locateBlock(o, 142+x, y+20,z+ 99);
	locateBlock(o, 142+x, y+20,z+ 98);
	locateBlock(o, 142+x, y+20,z+ 97);
	locateBlock(o, 142+x, y+20,z+ 96);

	locateBlock(o, 141+x, y+19,z+ 100);
	locateBlock(o, 141+x, y+19,z+ 99);
	locateBlock(o, 141+x, y+19,z+ 98);
	locateBlock(o, 141+x, y+19,z+ 97);

	locateBlock(o, 140+x, y+19,z+ 100);
	locateBlock(o, 140+x, y+19,z+ 99);
	locateBlock(o, 140+x, y+19,z+ 98);
	locateBlock(o, 140+x, y+19,z+ 97);

	locateBlock(o, 139+x, y+19,z+ 97);
	locateBlock(o, 138+x, y+19,z+ 97);
	locateBlock(o, 137+x, y+19,z+ 97);
	locateBlock(o, 136+x, y+19,z+ 97);
	locateBlock(o, 135+x, y+19,z+ 97);
	locateBlock(o, 134+x, y+19,z+ 97);
	locateBlock(o, 139+x, y+19,z+ 97);
	locateBlock(o, 132+x, y+19,z+ 97);
	locateBlock(o, 131+x, y+19,z+ 97);
	locateBlock(o, 130+x, y+19,z+ 97);
	locateBlock(o, 129+x, y+19,z+ 97);
	locateBlock(o, 128+x, y+19,z+ 97);
	locateBlock(o, 127+x, y+19,z+ 97);

	locateBlock(o, 122+x, y+19,z+ 97);
	locateBlock(o, 121+x, y+19,z+ 97);
	locateBlock(o, 120+x, y+19,z+ 97);
	locateBlock(o, 119+x, y+19,z+ 97);
	locateBlock(o, 118+x, y+19,z+ 97);
	locateBlock(o, 117+x, y+19,z+ 97);
	locateBlock(o, 116+x, y+19,z+ 97);
	locateBlock(o, 115+x, y+19,z+ 97);
	locateBlock(o, 114+x, y+19,z+ 97);
	locateBlock(o, 113+x, y+19,z+ 97);
	locateBlock(o, 112+x, y+19,z+ 97);
	locateBlock(o, 111+x, y+19,z+ 97);
	locateBlock(o, 110+x, y+19,z+ 97);

	locateBlock(o, 109+x, y+19,z+ 100);
	locateBlock(o, 109+x, y+19,z+ 99);
	locateBlock(o, 109+x, y+19,z+ 98);
	locateBlock(o, 109+x, y+19,z+ 97);

	locateBlock(o, 108+x, y+19,z+ 100);
	locateBlock(o, 108+x, y+19,z+ 99);
	locateBlock(o, 108+x, y+19,z+ 98);
	locateBlock(o, 108+x, y+19,z+ 97);

	locateBlock(o, 123+x, y+23,z+ 97);
	locateBlock(o, 123+x, y+23,z+ 96);
	locateBlock(o, 123+x, y+23,z+ 95);
	locateBlock(o, 123+x, y+23,z+ 94);
	locateBlock(o, 123+x, y+23,z+ 93);

	locateBlock(o, 126+x, y+23,z+ 97);
	locateBlock(o, 126+x, y+23,z+ 96);
	locateBlock(o, 126+x, y+23,z+ 95);
	locateBlock(o, 126+x, y+23,z+ 94);
	locateBlock(o, 126+x, y+23,z+ 93);

	locateBlock(o, 124+x, y+24,z+ 97);
	locateBlock(o, 124+x, y+24,z+ 96);
	locateBlock(o, 124+x, y+24,z+ 95);
	locateBlock(o, 124+x, y+24,z+ 94);
	locateBlock(o, 124+x, y+24,z+ 93);

	locateBlock(o, 125+x, y+24,z+ 97);
	locateBlock(o, 125+x, y+24,z+ 96);
	locateBlock(o, 125+x, y+24,z+ 95);
	locateBlock(o, 125+x, y+24,z+ 94);
	locateBlock(o, 125+x, y+24,z+ 93);

	locateBlock(o, 123+x, y+21,z+ 96);
	locateBlock(o, 123+x, y+21,z+ 95);
	locateBlock(o, 123+x, y+21,z+ 94);
	locateBlock(o, 123+x, y+22,z+ 96);
	locateBlock(o, 123+x, y+22,z+ 95);
	locateBlock(o, 123+x, y+22,z+ 94);

	locateBlock(o, 126+x, y+21,z+ 96);
	locateBlock(o, 126+x, y+21,z+ 95);
	locateBlock(o, 126+x, y+21,z+ 94);
	locateBlock(o, 126+x, y+22,z+ 96);
	locateBlock(o, 126+x, y+22,z+ 95);
	locateBlock(o, 126+x, y+22,z+ 94);

	//정면 가장 바깥쪽+x 오+y른쪽
	locateBlock(c, 139+x, y+4, z+97);
	locateBlock(c, 139+x, y+5, z+97);
	locateBlock(c, 139+x, y+6, z+97);
	locateBlock(c, 139+x, y+7, z+97);
	locateBlock(c, 139+x, y+8, z+97);
	locateBlock(c, 139+x, y+9, z+97);
	locateBlock(c, 139+x, y+10,z+ 97);
	locateBlock(c, 139+x, y+11,z+ 97);
	locateBlock(c, 139+x, y+12,z+ 97);
	locateBlock(c, 139+x, y+13,z+ 97);
	locateBlock(c, 139+x, y+14,z+ 97);
	locateBlock(c, 139+x, y+15,z+ 97);
	locateBlock(c, 139+x, y+16,z+ 97);
	locateBlock(c, 139+x, y+17,z+ 97);
	locateBlock(c, 139+x, y+18,z+ 97);

	locateBlock(c, 138+x, y+4, z+97);
	locateBlock(c, 138+x, y+5, z+97);
	locateBlock(c, 138+x, y+6, z+97);
	locateBlock(g, 138+x, y+7, z+97);
	locateBlock(g, 138+x, y+8, z+97);
	locateBlock(g, 138+x, y+9, z+97);
	locateBlock(g, 138+x, y+10,z+ 97);
	locateBlock(g, 138+x, y+11,z+ 97);
	locateBlock(g, 138+x, y+12,z+ 97);
	locateBlock(c, 138+x, y+13,z+ 97);
	locateBlock(c, 138+x, y+14,z+ 97);
	locateBlock(g, 138+x, y+15,z+ 97);
	locateBlock(g, 138+x, y+16,z+ 97);
	locateBlock(g, 138+x, y+17,z+ 97);
	locateBlock(c, 138+x, y+18,z+ 97);

	locateBlock(c, 137+x, y+4, z+97);
	locateBlock(c, 137+x, y+5, z+97);
	locateBlock(c, 137+x, y+6, z+97);
	locateBlock(g, 137+x, y+7, z+97);
	locateBlock(g, 137+x, y+8, z+97);
	locateBlock(g, 137+x, y+9, z+97);
	locateBlock(g, 137+x, y+10,z+ 97);
	locateBlock(g, 137+x, y+11,z+ 97);
	locateBlock(g, 137+x, y+12,z+ 97);
	locateBlock(c, 137+x, y+13,z+ 97);
	locateBlock(c, 137+x, y+14,z+ 97);
	locateBlock(g, 137+x, y+15,z+ 97);
	locateBlock(g, 137+x, y+16,z+ 97);
	locateBlock(g, 137+x, y+17,z+ 97);
	locateBlock(c, 137+x, y+18,z+ 97);

	locateBlock(c, 136+x, y+4, z+97);
	locateBlock(c, 136+x, y+5, z+97);
	locateBlock(c, 136+x, y+6, z+97);
	locateBlock(c, 136+x, y+7, z+97);
	locateBlock(c, 136+x, y+8, z+97);
	locateBlock(c, 136+x, y+9, z+97);
	locateBlock(c, 136+x, y+10,z+ 97);
	locateBlock(c, 136+x, y+11,z+ 97);
	locateBlock(c, 136+x, y+12,z+ 97);
	locateBlock(c, 136+x, y+13,z+ 97);
	locateBlock(c, 136+x, y+14,z+ 97);
	locateBlock(c, 136+x, y+15,z+ 97);
	locateBlock(c, 136+x, y+16,z+ 97);
	locateBlock(c, 136+x, y+17,z+ 97);
	locateBlock(c, 136+x, y+18,z+ 97);

	//정면 두번째 바깥+x쪽y+ 왼z+쪽
	locateBlock(c, 114+x, y+4, z+97);
	locateBlock(c, 114+x, y+5, z+97);
	locateBlock(c, 114+x, y+6, z+97);
	locateBlock(c, 114+x, y+7, z+97);
	locateBlock(c, 114+x, y+8, z+97);
	locateBlock(c, 114+x, y+9, z+97);
	locateBlock(c, 114+x, y+10,z+ 97);
	locateBlock(c, 114+x, y+12,z+ 97);
	locateBlock(c, 114+x, y+13,z+ 97);
	locateBlock(c, 114+x, y+14,z+ 97);
	locateBlock(c, 114+x, y+15,z+ 97);
	locateBlock(c, 114+x, y+16,z+ 97);
	locateBlock(c, 114+x, y+17,z+ 97);
	locateBlock(c, 114+x, y+18,z+ 97);

	locateBlock(c, 115+x, y+4, z+97);
	locateBlock(g, 115+x, y+5, z+97);
	locateBlock(g, 115+x, y+6, z+97);
	locateBlock(g, 115+x, y+7, z+97);
	locateBlock(c, 115+x, y+8, z+97);
	locateBlock(c, 115+x, y+9, z+97);
	locateBlock(g, 115+x, y+10,z+ 97);
	locateBlock(g, 115+x, y+11,z+ 97);
	locateBlock(g, 115+x, y+12,z+ 97);
	locateBlock(c, 115+x, y+13,z+ 97);
	locateBlock(c, 115+x, y+14,z+ 97);
	locateBlock(g, 115+x, y+15,z+ 97);
	locateBlock(g, 115+x, y+16,z+ 97);
	locateBlock(g, 115+x, y+17,z+ 97);
	locateBlock(c, 115+x, y+18,z+ 97);

	locateBlock(c, 116+x, y+4, z+97);
	locateBlock(g, 116+x, y+5, z+97);
	locateBlock(g, 116+x, y+6, z+97);
	locateBlock(g, 116+x, y+7, z+97);
	locateBlock(c, 116+x, y+8, z+97);
	locateBlock(c, 116+x, y+9, z+97);
	locateBlock(g, 116+x, y+10,z+ 97);
	locateBlock(g, 116+x, y+11,z+ 97);
	locateBlock(g, 116+x, y+12,z+ 97);
	locateBlock(c, 116+x, y+13,z+ 97);
	locateBlock(c, 116+x, y+14,z+ 97);
	locateBlock(g, 116+x, y+15,z+ 97);
	locateBlock(g, 116+x, y+16,z+ 97);
	locateBlock(g, 116+x, y+17,z+ 97);
	locateBlock(c, 116+x, y+18,z+ 97);

	locateBlock(c, 117+x, y+4, z+97);
	locateBlock(g, 117+x, y+5, z+97);
	locateBlock(g, 117+x, y+6, z+97);
	locateBlock(g, 117+x, y+7, z+97);
	locateBlock(c, 117+x, y+8, z+97);
	locateBlock(c, 117+x, y+9, z+97);
	locateBlock(g, 117+x, y+10,z+ 97);
	locateBlock(g, 117+x, y+11,z+ 97);
	locateBlock(g, 117+x, y+12,z+ 97);
	locateBlock(c, 117+x, y+13,z+ 97);
	locateBlock(c, 117+x, y+14,z+ 97);
	locateBlock(g, 117+x, y+15,z+ 97);
	locateBlock(g, 117+x, y+16,z+ 97);
	locateBlock(g, 117+x, y+17,z+ 97);
	locateBlock(c, 117+x, y+18,z+ 97);

	locateBlock(c, 118+x, y+4, z+97);
	locateBlock(c, 118+x, y+5, z+97);
	locateBlock(c, 118+x, y+6, z+97);
	locateBlock(c, 118+x, y+7, z+97);
	locateBlock(c, 118+x, y+8, z+97);
	locateBlock(c, 118+x, y+9, z+97);
	locateBlock(c, 118+x, y+10,z+ 97);
	locateBlock(c, 118+x, y+12,z+ 97);
	locateBlock(c, 118+x, y+13,z+ 97);
	locateBlock(c, 118+x, y+14,z+ 97);
	locateBlock(c, 118+x, y+15,z+ 97);
	locateBlock(c, 118+x, y+16,z+ 97);
	locateBlock(c, 118+x, y+17,z+ 97);
	locateBlock(c, 118+x, y+18,z+ 97);

	//정면 두번째 바깥+x쪽y+ 오z+른쪽
	locateBlock(c, 131+x, y+4, z+97);
	locateBlock(c, 131+x, y+5, z+97);
	locateBlock(c, 131+x, y+6, z+97);
	locateBlock(c, 131+x, y+7, z+97);
	locateBlock(c, 131+x, y+8, z+97);
	locateBlock(c, 131+x, y+9, z+97);
	locateBlock(c, 131+x, y+10,z+ 97);
	locateBlock(c, 131+x, y+12,z+ 97);
	locateBlock(c, 131+x, y+13,z+ 97);
	locateBlock(c, 131+x, y+14,z+ 97);
	locateBlock(c, 131+x, y+15,z+ 97);
	locateBlock(c, 131+x, y+16,z+ 97);
	locateBlock(c, 131+x, y+17,z+ 97);
	locateBlock(c, 131+x, y+18,z+ 97);

	locateBlock(c, 132+x, y+4, z+97);
	locateBlock(g, 132+x, y+5, z+97);
	locateBlock(g, 132+x, y+6, z+97);
	locateBlock(g, 132+x, y+7, z+97);
	locateBlock(c, 132+x, y+8, z+97);
	locateBlock(c, 132+x, y+9, z+97);
	locateBlock(g, 132+x, y+10,z+ 97);
	locateBlock(g, 132+x, y+11,z+ 97);
	locateBlock(g, 132+x, y+12,z+ 97);
	locateBlock(c, 132+x, y+13,z+ 97);
	locateBlock(c, 132+x, y+14,z+ 97);
	locateBlock(g, 132+x, y+15,z+ 97);
	locateBlock(g, 132+x, y+16,z+ 97);
	locateBlock(g, 132+x, y+17,z+ 97);
	locateBlock(c, 132+x, y+18,z+ 97);

	locateBlock(c, 133+x, y+4, z+97);
	locateBlock(g, 133+x, y+5, z+97);
	locateBlock(g, 133+x, y+6, z+97);
	locateBlock(g, 133+x, y+7, z+97);
	locateBlock(c, 133+x, y+8, z+97);
	locateBlock(c, 133+x, y+9, z+97);
	locateBlock(g, 133+x, y+10,z+ 97);
	locateBlock(g, 133+x, y+11,z+ 97);
	locateBlock(g, 133+x, y+12,z+ 97);
	locateBlock(c, 133+x, y+13,z+ 97);
	locateBlock(c, 133+x, y+14,z+ 97);
	locateBlock(g, 133+x, y+15,z+ 97);
	locateBlock(g, 133+x, y+16,z+ 97);
	locateBlock(g, 133+x, y+17,z+ 97);
	locateBlock(c, 133+x, y+18,z+ 97);

	locateBlock(c, 134+x, y+4, z+97);
	locateBlock(g, 134+x, y+5, z+97);
	locateBlock(g, 134+x, y+6, z+97);
	locateBlock(g, 134+x, y+7, z+97);
	locateBlock(c, 134+x, y+8, z+97);
	locateBlock(c, 134+x, y+9, z+97);
	locateBlock(g, 134+x, y+10,z+ 97);
	locateBlock(g, 134+x, y+11,z+ 97);
	locateBlock(g, 134+x, y+12,z+ 97);
	locateBlock(c, 134+x, y+13,z+ 97);
	locateBlock(c, 134+x, y+14,z+ 97);
	locateBlock(g, 134+x, y+15,z+ 97);
	locateBlock(g, 134+x, y+16,z+ 97);
	locateBlock(g, 134+x, y+17,z+ 97);
	locateBlock(c, 134+x, y+18,z+ 97);

	locateBlock(c, 135+x, y+4, z+97);
	locateBlock(c, 135+x, y+5, z+97);
	locateBlock(c, 135+x, y+6, z+97);
	locateBlock(c, 135+x, y+7, z+97);
	locateBlock(c, 135+x, y+8, z+97);
	locateBlock(c, 135+x, y+9, z+97);
	locateBlock(c, 135+x, y+10,z+ 97);
	locateBlock(c, 135+x, y+12,z+ 97);
	locateBlock(c, 135+x, y+13,z+ 97);
	locateBlock(c, 135+x, y+14,z+ 97);
	locateBlock(c, 135+x, y+15,z+ 97);
	locateBlock(c, 135+x, y+16,z+ 97);
	locateBlock(c, 135+x, y+17,z+ 97);
	locateBlock(c, 135+x, y+18,z+ 97);

	//정면 두번째 안쪽+x 왼+y쪽z+

	locateBlock(c, 119+x, y+4, z+97);
	locateBlock(c, 119+x, y+5, z+97);
	locateBlock(c, 119+x, y+6, z+97);
	locateBlock(c, 119+x, y+7, z+97);
	locateBlock(c, 119+x, y+8, z+97);
	locateBlock(c, 119+x, y+9, z+97);
	locateBlock(c, 119+x, y+10,z+ 97);
	locateBlock(c, 119+x, y+12,z+ 97);
	locateBlock(c, 119+x, y+13,z+ 97);
	locateBlock(c, 119+x, y+14,z+ 97);
	locateBlock(c, 119+x, y+15,z+ 97);
	locateBlock(c, 119+x, y+16,z+ 97);
	locateBlock(c, 119+x, y+17,z+ 97);
	locateBlock(c, 119+x, y+18,z+ 97);

	locateBlock(c, 120+x, y+4, z+97);
	locateBlock(g, 120+x, y+5, z+97);
	locateBlock(g, 120+x, y+6, z+97);
	locateBlock(g, 120+x, y+7, z+97);
	locateBlock(c, 120+x, y+8, z+97);
	locateBlock(c, 120+x, y+9, z+97);
	locateBlock(g, 120+x, y+10,z+ 97);
	locateBlock(g, 120+x, y+11,z+ 97);
	locateBlock(g, 120+x, y+12,z+ 97);
	locateBlock(c, 120+x, y+13,z+ 97);
	locateBlock(c, 120+x, y+14,z+ 97);
	locateBlock(g, 120+x, y+15,z+ 97);
	locateBlock(g, 120+x, y+16,z+ 97);
	locateBlock(g, 120+x, y+17,z+ 97);
	locateBlock(c, 120+x, y+18,z+ 97);

	locateBlock(c, 121+x, y+4, z+97);
	locateBlock(g, 121+x, y+5, z+97);
	locateBlock(g, 121+x, y+6, z+97);
	locateBlock(g, 121+x, y+7, z+97);
	locateBlock(c, 121+x, y+8, z+97);
	locateBlock(c, 121+x, y+9, z+97);
	locateBlock(g, 121+x, y+10,z+ 97);
	locateBlock(g, 121+x, y+11,z+ 97);
	locateBlock(g, 121+x, y+12,z+ 97);
	locateBlock(c, 121+x, y+13,z+ 97);
	locateBlock(c, 121+x, y+14,z+ 97);
	locateBlock(g, 121+x, y+15,z+ 97);
	locateBlock(g, 121+x, y+16,z+ 97);
	locateBlock(g, 121+x, y+17,z+ 97);
	locateBlock(c, 121+x, y+18,z+ 97);

	locateBlock(c, 122+x, y+4, z+97);
	locateBlock(c, 122+x, y+5, z+97);
	locateBlock(c, 122+x, y+6, z+97);
	locateBlock(c, 122+x, y+7, z+97);
	locateBlock(c, 122+x, y+8, z+97);
	locateBlock(c, 122+x, y+9, z+97);
	locateBlock(c, 122+x, y+10,z+ 97);
	locateBlock(c, 122+x, y+12,z+ 97);
	locateBlock(c, 122+x, y+13,z+ 97);
	locateBlock(c, 122+x, y+14,z+ 97);
	locateBlock(c, 122+x, y+15,z+ 97);
	locateBlock(c, 122+x, y+16,z+ 97);
	locateBlock(c, 122+x, y+17,z+ 97);
	locateBlock(c, 122+x, y+18,z+ 97);


	//정면 두번째 안쪽+x 오+y른z+쪽
	locateBlock(c, 127+x, y+4, z+97);
	locateBlock(c, 127+x, y+5, z+97);
	locateBlock(c, 127+x, y+6, z+97);
	locateBlock(c, 127+x, y+7, z+97);
	locateBlock(c, 127+x, y+8, z+97);
	locateBlock(c, 127+x, y+9, z+97);
	locateBlock(c, 127+x, y+10,z+ 97);
	locateBlock(c, 127+x, y+12,z+ 97);
	locateBlock(c, 127+x, y+13,z+ 97);
	locateBlock(c, 127+x, y+14,z+ 97);
	locateBlock(c, 127+x, y+15,z+ 97);
	locateBlock(c, 127+x, y+16,z+ 97);
	locateBlock(c, 127+x, y+17,z+ 97);
	locateBlock(c, 127+x, y+18,z+ 97);

	locateBlock(c, 128+x, y+4, z+97);
	locateBlock(g, 128+x, y+5, z+97);
	locateBlock(g, 128+x, y+6, z+97);
	locateBlock(g, 128+x, y+7, z+97);
	locateBlock(c, 128+x, y+8, z+97);
	locateBlock(c, 128+x, y+9, z+97);
	locateBlock(g, 128+x, y+10,z+ 97);
	locateBlock(g, 128+x, y+11,z+ 97);
	locateBlock(g, 128+x, y+12,z+ 97);
	locateBlock(c, 128+x, y+13,z+ 97);
	locateBlock(c, 128+x, y+14,z+ 97);
	locateBlock(g, 128+x, y+15,z+ 97);
	locateBlock(g, 128+x, y+16,z+ 97);
	locateBlock(g, 128+x, y+17,z+ 97);
	locateBlock(c, 128+x, y+18,z+ 97);

	locateBlock(c, 129+x, y+4, z+97);
	locateBlock(g, 129+x, y+5, z+97);
	locateBlock(g, 129+x, y+6, z+97);
	locateBlock(g, 129+x, y+7, z+97);
	locateBlock(c, 129+x, y+8, z+97);
	locateBlock(c, 129+x, y+9, z+97);
	locateBlock(g, 129+x, y+10,z+ 97);
	locateBlock(g, 129+x, y+11,z+ 97);
	locateBlock(g, 129+x, y+12,z+ 97);
	locateBlock(c, 129+x, y+13,z+ 97);
	locateBlock(c, 129+x, y+14,z+ 97);
	locateBlock(g, 129+x, y+15,z+ 97);
	locateBlock(g, 129+x, y+16,z+ 97);
	locateBlock(g, 129+x, y+17,z+ 97);
	locateBlock(c, 129+x, y+18,z+ 97);

	locateBlock(c, 130+x, y+4, z+97);
	locateBlock(c, 130+x, y+5, z+97);
	locateBlock(c, 130+x, y+6, z+97);
	locateBlock(c, 130+x, y+7, z+97);
	locateBlock(c, 130+x, y+8, z+97);
	locateBlock(c, 130+x, y+9, z+97);
	locateBlock(c, 130+x, y+10,z+ 97);
	locateBlock(c, 130+x, y+12,z+ 97);
	locateBlock(c, 130+x, y+13,z+ 97);
	locateBlock(c, 130+x, y+14,z+ 97);
	locateBlock(c, 130+x, y+15,z+ 97);
	locateBlock(c, 130+x, y+16,z+ 97);
	locateBlock(c, 130+x, y+17,z+ 97);
	locateBlock(c, 130+x, y+18,z+ 97);

	//정면 가운데	 		+y z+
	locateBlock(c, 123+x, y+4, z+98);
	locateBlock(c, 123+x, y+5, z+98);
	locateBlock(c, 123+x, y+6, z+98);
	locateBlock(c, 123+x, y+7, z+98);
	locateBlock(c, 124+x, y+7, z+98);
	locateBlock(c, 125+x, y+7, z+98);
	locateBlock(c, 126+x, y+7, z+98);
	locateBlock(c, 126+x, y+6, z+98);
	locateBlock(c, 126+x, y+5, z+98);
	locateBlock(c, 126+x, y+4, z+98);

	locateBlock(c, 123+x, y+4, z+97);
	locateBlock(c, 123+x, y+5, z+97);
	locateBlock(c, 123+x, y+6, z+97);
	locateBlock(c, 123+x, y+7, z+97);
	locateBlock(c, 123+x, y+8, z+97);
	locateBlock(c, 123+x, y+9, z+97);
	locateBlock(c, 123+x, y+10,z+ 97);
	locateBlock(c, 123+x, y+11,z+ 97);
	locateBlock(c, 123+x, y+12,z+ 97);
	locateBlock(c, 123+x, y+13,z+ 97);
	locateBlock(c, 123+x, y+14,z+ 97);
	locateBlock(c, 123+x, y+15,z+ 97);
	locateBlock(c, 123+x, y+16,z+ 97);
	locateBlock(c, 123+x, y+17,z+ 97);
	locateBlock(c, 123+x, y+18,z+ 97);
	locateBlock(c, 123+x, y+19,z+ 97);
	locateBlock(c, 123+x, y+20,z+ 97);
	locateBlock(c, 123+x, y+21,z+ 97);
	locateBlock(c, 123+x, y+22,z+ 97);

	locateBlock(c, 124+x, y+7, z+97);
	locateBlock(c, 124+x, y+8, z+97);
	locateBlock(g, 124+x, y+9, z+97);
	locateBlock(c, 124+x, y+10,z+ 97);
	locateBlock(c, 124+x, y+11,z+ 97);
	locateBlock(c, 124+x, y+12,z+ 97);
	locateBlock(c, 124+x, y+13,z+ 97);
	locateBlock(c, 124+x, y+14,z+ 97);
	locateBlock(c, 124+x, y+15,z+ 97);
	locateBlock(c, 124+x, y+16,z+ 97);
	locateBlock(g, 124+x, y+17,z+ 97);
	locateBlock(c, 124+x, y+18,z+ 97);
	locateBlock(g, 124+x, y+19,z+ 97);
	locateBlock(g, 124+x, y+20,z+ 97);
	locateBlock(g, 124+x, y+21,z+ 97);
	locateBlock(c, 124+x, y+22,z+ 97);
	locateBlock(c, 124+x, y+23,z+ 97);

	locateBlock(c, 125+x, y+7, z+97);
	locateBlock(c, 125+x, y+8, z+97);
	locateBlock(g, 125+x, y+9, z+97);
	locateBlock(c, 125+x, y+10,z+ 97);
	locateBlock(c, 125+x, y+11,z+ 97);
	locateBlock(c, 125+x, y+12,z+ 97);
	locateBlock(c, 125+x, y+13,z+ 97);
	locateBlock(c, 125+x, y+14,z+ 97);
	locateBlock(c, 125+x, y+15,z+ 97);
	locateBlock(c, 125+x, y+16,z+ 97);
	locateBlock(g, 125+x, y+17,z+ 97);
	locateBlock(c, 125+x, y+18,z+ 97);
	locateBlock(g, 125+x, y+19,z+ 97);
	locateBlock(g, 125+x, y+20,z+ 97);
	locateBlock(g, 125+x, y+21,z+ 97);
	locateBlock(c, 125+x, y+22,z+ 97);
	locateBlock(c, 125+x, y+23,z+ 97);


	locateBlock(c, 126+x, y+4, z+97);
	locateBlock(c, 126+x, y+5, z+97);
	locateBlock(c, 126+x, y+6, z+97);
	locateBlock(c, 126+x, y+7, z+97);
	locateBlock(c, 126+x, y+8, z+97);
	locateBlock(c, 126+x, y+9, z+97);
	locateBlock(c, 126+x, y+10,z+ 97);
	locateBlock(c, 126+x, y+11,z+ 97);
	locateBlock(c, 126+x, y+12,z+ 97);
	locateBlock(c, 126+x, y+13,z+ 97);
	locateBlock(c, 126+x, y+14,z+ 97);
	locateBlock(c, 126+x, y+15,z+ 97);
	locateBlock(c, 126+x, y+16,z+ 97);
	locateBlock(c, 126+x, y+17,z+ 97);
	locateBlock(c, 126+x, y+18,z+ 97);
	locateBlock(c, 126+x, y+19,z+ 97);
	locateBlock(c, 126+x, y+20,z+ 97);
	locateBlock(c, 126+x, y+21,z+ 97);
	locateBlock(c, 126+x, y+22,z+ 97);




	//정면 안쪽 왼쪽		+y z+
	locateBlock(c, 109+x, y+4, z+97);
	locateBlock(c, 109+x, y+5, z+97);
	locateBlock(c, 109+x, y+6, z+97);
	locateBlock(c, 109+x, y+7, z+97);
	locateBlock(c, 109+x, y+8, z+97);
	locateBlock(c, 109+x, y+9, z+97);
	locateBlock(c, 109+x, y+10,z+ 97);
	locateBlock(c, 109+x, y+11,z+ 97);
	locateBlock(c, 109+x, y+12,z+ 97);
	locateBlock(c, 109+x, y+13,z+ 97);
	locateBlock(c, 109+x, y+14,z+ 97);
	locateBlock(c, 109+x, y+15,z+ 97);
	locateBlock(c, 109+x, y+16,z+ 97);
	locateBlock(c, 109+x, y+17,z+ 97);
	locateBlock(c, 109+x, y+18,z+ 97);

	locateBlock(c, 109+x, y+4, z+98);
	locateBlock(c, 109+x, y+5, z+98);
	locateBlock(c, 109+x, y+6, z+98);
	locateBlock(c, 109+x, y+7, z+98);
	locateBlock(c, 109+x, y+8, z+98);
	locateBlock(c, 109+x, y+9, z+98);
	locateBlock(c, 109+x, y+10,z+ 98);
	locateBlock(c, 109+x, y+11,z+ 98);
	locateBlock(c, 109+x, y+12,z+ 98);
	locateBlock(c, 109+x, y+13,z+ 98);
	locateBlock(c, 109+x, y+14,z+ 98);
	locateBlock(c, 109+x, y+15,z+ 98);
	locateBlock(c, 109+x, y+16,z+ 98);
	locateBlock(c, 109+x, y+17,z+ 98);
	locateBlock(c, 109+x, y+18,z+ 98);

	locateBlock(c, 109+x, y+4, z+99);
	locateBlock(c, 109+x, y+5, z+99);
	locateBlock(c, 109+x, y+6, z+99);
	locateBlock(c, 109+x, y+7, z+99);
	locateBlock(c, 109+x, y+8, z+99);
	locateBlock(c, 109+x, y+9, z+99);
	locateBlock(c, 109+x, y+10,z+ 99);
	locateBlock(c, 109+x, y+11,z+ 99);
	locateBlock(c, 109+x, y+12,z+ 99);
	locateBlock(c, 109+x, y+13,z+ 99);
	locateBlock(c, 109+x, y+14,z+ 99);
	locateBlock(c, 109+x, y+15,z+ 99);
	locateBlock(c, 109+x, y+16,z+ 99);
	locateBlock(c, 109+x, y+17,z+ 99);
	locateBlock(c, 109+x, y+18,z+ 99);

	//정면 오른쪽 안쪽		+y  +z
	locateBlock(c, 140+x, y+4, z+97);
	locateBlock(c, 140+x, y+5, z+97);
	locateBlock(c, 140+x, y+6, z+97);
	locateBlock(c, 140+x, y+7, z+97);
	locateBlock(c, 140+x, y+8, z+97);
	locateBlock(c, 140+x, y+9, z+97);
	locateBlock(c, 140+x, y+10,z+ 97);
	locateBlock(c, 140+x, y+11,z+ 97);
	locateBlock(c, 140+x, y+12,z+ 97);
	locateBlock(c, 140+x, y+13,z+ 97);
	locateBlock(c, 140+x, y+14,z+ 97);
	locateBlock(c, 140+x, y+15,z+ 97);
	locateBlock(c, 140+x, y+16,z+ 97);
	locateBlock(c, 140+x, y+17,z+ 97);
	locateBlock(c, 140+x, y+18,z+ 97);

	locateBlock(c, 140+x, y+4, z+98);
	locateBlock(c, 140+x, y+5, z+98);
	locateBlock(c, 140+x, y+6, z+98);
	locateBlock(c, 140+x, y+7, z+98);
	locateBlock(c, 140+x, y+8, z+98);
	locateBlock(c, 140+x, y+9, z+98);
	locateBlock(c, 140+x, y+10,z+ 98);
	locateBlock(c, 140+x, y+11,z+ 98);
	locateBlock(c, 140+x, y+12,z+ 98);
	locateBlock(c, 140+x, y+13,z+ 98);
	locateBlock(c, 140+x, y+14,z+ 98);
	locateBlock(c, 140+x, y+15,z+ 98);
	locateBlock(c, 140+x, y+16,z+ 98);
	locateBlock(c, 140+x, y+17,z+ 98);
	locateBlock(c, 140+x, y+18,z+ 98);

	locateBlock(c, 140+x, y+4, z+99);
	locateBlock(c, 140+x, y+5, z+99);
	locateBlock(c, 140+x, y+6, z+99);
	locateBlock(c, 140+x, y+7, z+99);
	locateBlock(c, 140+x, y+8, z+99);
	locateBlock(c, 140+x, y+9, z+99);
	locateBlock(c, 140+x, y+10,z+ 99);
	locateBlock(c, 140+x, y+11,z+ 99);
	locateBlock(c, 140+x, y+12,z+ 99);
	locateBlock(c, 140+x, y+13,z+ 99);
	locateBlock(c, 140+x, y+14,z+ 99);
	locateBlock(c, 140+x, y+15,z+ 99);
	locateBlock(c, 140+x, y+16,z+ 99);
	locateBlock(c, 140+x, y+17,z+ 99);
	locateBlock(c, 140+x, y+18,z+ 99);


	//정면 왼쪽
	locateBlock(c, x+98, y+4, z+100);
	locateBlock(c, x+99, y+4, z+100);
	locateBlock(c, x+100,y+ 4,z+ 100);
	locateBlock(c, x+101,y+ 4,z+ 100);
	locateBlock(c, x+102,y+ 4,z+ 100);
	locateBlock(c, x+103,y+ 4,z+ 100);
	locateBlock(c, x+104,y+ 4,z+ 100);
	locateBlock(c, x+105,y+ 4,z+ 100);
	locateBlock(c, x+106,y+ 4,z+ 100);
	locateBlock(c, x+107,y+ 4,z+ 100);
	locateBlock(c, x+108,y+ 4,z+ 100);
	locateBlock(c, x+109,y+ 4,z+ 100);

	locateBlock(c, x+98, y+5, z+100);
	locateBlock(c, x+99, y+5, z+100);
	locateBlock(g, x+100,y+ 5,z+ 100);
	locateBlock(g, x+101,y+ 5,z+ 100);
	locateBlock(c, x+102,y+ 5,z+ 100);
	locateBlock(g, x+103,y+ 5,z+ 100);
	locateBlock(g, x+104,y+ 5,z+ 100);
	locateBlock(c, x+105,y+ 5,z+ 100);
	locateBlock(g, x+106,y+ 5,z+ 100);
	locateBlock(g, x+107,y+ 5,z+ 100);
	locateBlock(c, x+108,y+ 5,z+ 100);
	locateBlock(c, x+109,y+ 5,z+ 100);

	locateBlock(c, x+98, y+6, z+100);
	locateBlock(c, x+99, y+6, z+100);
	locateBlock(g, x+100,y+ 6,z+ 100);
	locateBlock(g, x+101,y+ 6,z+ 100);
	locateBlock(c, x+102,y+ 6,z+ 100);
	locateBlock(g, x+103,y+ 6,z+ 100);
	locateBlock(g, x+104,y+ 6,z+ 100);
	locateBlock(c, x+105,y+ 6,z+ 100);
	locateBlock(g, x+106,y+ 6,z+ 100);
	locateBlock(g, x+107,y+ 6,z+ 100);
	locateBlock(c, x+108,y+ 6,z+ 100);
	locateBlock(c, x+109,y+ 6,z+ 100);

	locateBlock(c, x+98, y+7, z+100);
	locateBlock(c, x+99, y+7, z+100);
	locateBlock(g, x+100,y+ 7,z+ 100);
	locateBlock(g, x+101,y+ 7,z+ 100);
	locateBlock(c, x+102,y+ 7,z+ 100);
	locateBlock(g, x+103,y+ 7,z+ 100);
	locateBlock(g, x+104,y+ 7,z+ 100);
	locateBlock(c, x+105,y+ 7,z+ 100);
	locateBlock(g, x+106,y+ 7,z+ 100);
	locateBlock(g, x+107,y+ 7,z+ 100);
	locateBlock(c, x+108,y+ 7,z+ 100);
	locateBlock(c, x+109,y+ 7,z+ 100);

	locateBlock(c, x+98, y+8, z+100);
	locateBlock(c, x+99, y+8, z+100);
	locateBlock(g, x+100,y+ 8,z+ 100);
	locateBlock(g, x+101,y+ 8,z+ 100);
	locateBlock(c, x+102,y+ 8,z+ 100);
	locateBlock(g, x+103,y+ 8,z+ 100);
	locateBlock(g, x+104,y+ 8,z+ 100);
	locateBlock(c, x+105,y+ 8,z+ 100);
	locateBlock(g, x+106,y+ 8,z+ 100);
	locateBlock(g, x+107,y+ 8,z+ 100);
	locateBlock(c, x+108,y+ 8,z+ 100);
	locateBlock(c, x+109,y+ 8,z+ 100);

	//정면 왼쪽중 2x+번째y+ 반z+복
	locateBlock(c, x+98, y+9, z+100);
	locateBlock(c, x+99, y+9, z+100);
	locateBlock(c, x+100,y+ 9,z+ 100);
	locateBlock(c, x+101,y+ 9,z+ 100);
	locateBlock(c, x+102,y+ 9,z+ 100);
	locateBlock(c, x+103,y+ 9,z+ 100);
	locateBlock(c, x+104,y+ 9,z+ 100);
	locateBlock(c, x+105,y+ 9,z+ 100);
	locateBlock(c, x+106,y+ 9,z+ 100);
	locateBlock(c, x+107,y+ 9,z+ 100);
	locateBlock(c, x+108,y+ 9,z+ 100);
	locateBlock(c, x+109,y+ 9,z+ 100);

	locateBlock(c, x+98, y+10,z+ 100);
	locateBlock(c, x+99, y+10,z+ 100);
	locateBlock(g, x+100,y+ 10,z+ 100);
	locateBlock(g, x+101,y+ 10,z+ 100);
	locateBlock(c, x+102,y+ 10,z+ 100);
	locateBlock(g, x+103,y+ 10,z+ 100);
	locateBlock(g, x+104,y+ 10,z+ 100);
	locateBlock(c, x+105,y+ 10,z+ 100);
	locateBlock(g, x+106,y+ 10,z+ 100);
	locateBlock(g, x+107,y+ 10,z+ 100);
	locateBlock(c, x+108,y+ 10,z+ 100);
	locateBlock(c, x+109,y+ 10,z+ 100);

	locateBlock(c, x+98, y+11, z+100);
	locateBlock(c, x+99, y+11, z+100);
	locateBlock(g, x+100,y+ 11,z+ 100);
	locateBlock(g, x+101,y+ 11,z+ 100);
	locateBlock(c, x+102,y+ 11,z+ 100);
	locateBlock(g, x+103,y+ 11,z+ 100);
	locateBlock(g, x+104,y+ 11,z+ 100);
	locateBlock(c, x+105,y+ 11,z+ 100);
	locateBlock(g, x+106,y+ 11,z+ 100);
	locateBlock(g, x+107,y+ 11,z+ 100);
	locateBlock(c, x+108,y+ 11,z+ 100);
	locateBlock(c, x+109,y+ 11,z+ 100);

	locateBlock(c, x+98, y+12, z+100);
	locateBlock(c, x+99, y+12, z+100);
	locateBlock(g, x+100,y+ 12,z+ 100);
	locateBlock(g, x+101,y+ 12,z+ 100);
	locateBlock(c, x+102,y+ 12,z+ 100);
	locateBlock(g, x+103,y+ 12,z+ 100);
	locateBlock(g, x+104,y+ 12,z+ 100);
	locateBlock(c, x+105,y+ 12,z+ 100);
	locateBlock(g, x+106,y+ 12,z+ 100);
	locateBlock(g, x+107,y+ 12,z+ 100);
	locateBlock(c, x+108,y+ 12,z+ 100);
	locateBlock(c, x+109,y+ 12,z+ 100);

	locateBlock(c, x+98, y+13, z+100);
	locateBlock(c, x+99, y+13, z+100);
	locateBlock(g, x+100,y+ 13,z+ 100);
	locateBlock(g, x+101,y+ 13,z+ 100);
	locateBlock(c, x+102,y+ 13,z+ 100);
	locateBlock(g, x+103,y+ 13,z+ 100);
	locateBlock(g, x+104,y+ 13,z+ 100);
	locateBlock(c, x+105,y+ 13,z+ 100);
	locateBlock(g, x+106,y+ 13,z+ 100);
	locateBlock(g, x+107,y+ 13,z+ 100);
	locateBlock(c, x+108,y+ 13,z+ 100);
	locateBlock(c, x+109,y+ 13,z+ 100);

	//정면왼쪽중 3번+x째 y+반복z+
	locateBlock(c, x+98, y+14, z+100);
	locateBlock(c, x+99, y+14, z+100);
	locateBlock(c, x+100,y+ 14,z+ 100);
	locateBlock(c, x+101,y+ 14,z+ 100);
	locateBlock(c, x+102,y+ 14,z+ 100);
	locateBlock(c, x+103,y+ 14,z+ 100);
	locateBlock(c, x+104,y+ 14,z+ 100);
	locateBlock(c, x+105,y+ 14,z+ 100);
	locateBlock(c, x+106,y+ 14,z+ 100);
	locateBlock(c, x+107,y+ 14,z+ 100);
	locateBlock(c, x+108,y+ 14,z+ 100);
	locateBlock(c, x+109,y+ 14,z+ 100);

	locateBlock(c, x+98, y+15, z+100);
	locateBlock(c, x+99, y+15, z+100);
	locateBlock(g, x+100,y+ 15,z+ 100);
	locateBlock(g, x+101,y+ 15,z+ 100);
	locateBlock(c, x+102,y+ 15,z+ 100);
	locateBlock(g, x+103,y+ 15,z+ 100);
	locateBlock(g, x+104,y+ 15,z+ 100);
	locateBlock(c, x+105,y+ 15,z+ 100);
	locateBlock(g, x+106,y+ 15,z+ 100);
	locateBlock(g, x+107,y+ 15,z+ 100);
	locateBlock(c, x+108,y+ 15,z+ 100);
	locateBlock(c, x+109,y+ 15,z+ 100);

	locateBlock(c, x+98, y+16, z+100);
	locateBlock(c, x+99, y+16, z+100);
	locateBlock(g, x+100,y+ 16,z+ 100);
	locateBlock(g, x+101,y+ 16,z+ 100);
	locateBlock(c, x+102,y+ 16,z+ 100);
	locateBlock(g, x+103,y+ 16,z+ 100);
	locateBlock(g, x+104,y+ 16,z+ 100);
	locateBlock(c, x+105,y+ 16,z+ 100);
	locateBlock(g, x+106,y+ 16,z+ 100);
	locateBlock(g, x+107,y+ 16,z+ 100);
	locateBlock(c, x+108,y+ 16,z+ 100);
	locateBlock(c, x+109,y+ 16,z+ 100);

	locateBlock(c, x+98, y+17, z+100);
	locateBlock(c, x+99, y+17, z+100);
	locateBlock(g, x+100,y+ 17,z+ 100);
	locateBlock(g, x+101,y+ 17,z+ 100);
	locateBlock(c, x+102,y+ 17,z+ 100);
	locateBlock(g, x+103,y+ 17,z+ 100);
	locateBlock(g, x+104,y+ 17,z+ 100);
	locateBlock(c, x+105,y+ 17,z+ 100);
	locateBlock(g, x+106,y+ 17,z+ 100);
	locateBlock(g, x+107,y+ 17,z+ 100);
	locateBlock(c, x+108,y+ 17,z+ 100);
	locateBlock(c, x+109,y+ 17,z+ 100);

	locateBlock(c, x+98, y+18, z+100);
	locateBlock(c, x+99, y+18, z+100);
	locateBlock(g, x+100,y+ 8, z+100);
	locateBlock(g, x+101,y+ 18,z+ 100);
	locateBlock(c, x+102,y+ 18,z+ 100);
	locateBlock(g, x+103,y+ 18,z+ 100);
	locateBlock(g, x+104,y+ 18,z+ 100);
	locateBlock(c, x+105,y+ 18,z+ 100);
	locateBlock(g, x+106,y+ 18,z+ 100);
	locateBlock(g, x+107,y+ 18,z+ 100);
	locateBlock(c, x+108,y+ 18,z+ 100);
	locateBlock(c, x+109,y+ 18,z+ 100);
	//정면 오른쪽	+x	+y  z	+
	locateBlock(c, x+140,y+ 4, z+100);
	locateBlock(c, x+141,y+ 4, z+100);
	locateBlock(c, x+142,y+ 4, z+100);
	locateBlock(c, x+143,y+ 4, z+100);
	locateBlock(c, x+144,y+ 4, z+100);
	locateBlock(c, x+145,y+ 4, z+100);
	locateBlock(c, x+146,y+ 4, z+100);
	locateBlock(c, x+147,y+ 4, z+100);
	locateBlock(c, x+148,y+ 4, z+100);
	locateBlock(c, x+149,y+ 4, z+100);
	locateBlock(c, x+150,y+ 4, z+100);
	locateBlock(c, x+151,y+ 4, z+100);

	locateBlock(c, x+140,y+ 5, z+100);
	locateBlock(c, x+141,y+ 5, z+100);
	locateBlock(g, x+142,y+ 5, z+100);
	locateBlock(g, x+143,y+ 5, z+100);
	locateBlock(c, x+144,y+ 5, z+100);
	locateBlock(g, x+145,y+ 5, z+100);
	locateBlock(g, x+146,y+ 5, z+100);
	locateBlock(c, x+147,y+ 5, z+100);
	locateBlock(g, x+148,y+ 5, z+100);
	locateBlock(g, x+149,y+ 5, z+100);
	locateBlock(c, x+150,y+ 5, z+100);
	locateBlock(c, x+151,y+ 5, z+100);

	locateBlock(c, x+140,y+ 6, z+100);
	locateBlock(c, x+141,y+ 6, z+100);
	locateBlock(g, x+142,y+ 6, z+100);
	locateBlock(g, x+143,y+ 6, z+100);
	locateBlock(c, x+144,y+ 6, z+100);
	locateBlock(g, x+145,y+ 6, z+100);
	locateBlock(g, x+146,y+ 6, z+100);
	locateBlock(c, x+147,y+ 6, z+100);
	locateBlock(g, x+148,y+ 6, z+100);
	locateBlock(g, x+149,y+ 6, z+100);
	locateBlock(c, x+150,y+ 6, z+100);
	locateBlock(c, x+151,y+ 6, z+100);

	locateBlock(c, x+140,y+ 7, z+100);
	locateBlock(c, x+141,y+ 7, z+100);
	locateBlock(g, x+142,y+ 7, z+100);
	locateBlock(g, x+143,y+ 7, z+100);
	locateBlock(c, x+144,y+ 7, z+100);
	locateBlock(g, x+145,y+ 7, z+100);
	locateBlock(g, x+146,y+ 7, z+100);
	locateBlock(c, x+147,y+ 7, z+100);
	locateBlock(g, x+148,y+ 7, z+100);
	locateBlock(g, x+149,y+ 7, z+100);
	locateBlock(c, x+150,y+ 7, z+100);
	locateBlock(c, x+151,y+ 7, z+100);

	locateBlock(c, x+140,y+ 8, z+100);
	locateBlock(c, x+141,y+ 8, z+100);
	locateBlock(g, x+142,y+ 8, z+100);
	locateBlock(g, x+143,y+ 8, z+100);
	locateBlock(c, x+144,y+ 8, z+100);
	locateBlock(g, x+145,y+ 8, z+100);
	locateBlock(g, x+146,y+ 8, z+100);
	locateBlock(c, x+147,y+ 8, z+100);
	locateBlock(g, x+148,y+ 8, z+100);
	locateBlock(g, x+149,y+ 8, z+100);
	locateBlock(c, x+150,y+ 8, z+100);
	locateBlock(c, x+151,y+ 8, z+100);

	//정면 오른쪽 중+x 2번+y째 z+반복
	locateBlock(c, x+140,y+ 9, z+100);
	locateBlock(c, x+141,y+ 9, z+100);
	locateBlock(c, x+142,y+ 9, z+100);
	locateBlock(c, x+143,y+ 9, z+100);
	locateBlock(c, x+144,y+ 9, z+100);
	locateBlock(c, x+145,y+ 9, z+100);
	locateBlock(c, x+146,y+ 9, z+100);
	locateBlock(c, x+147,y+ 9, z+100);
	locateBlock(c, x+148,y+ 9, z+100);
	locateBlock(c, x+149,y+ 9, z+100);
	locateBlock(c, x+150,y+ 9, z+100);
	locateBlock(c, x+151,y+ 9, z+100);

	locateBlock(c, x+140,y+ 10,z+ 100);
	locateBlock(c, x+141,y+ 10,z+ 100);
	locateBlock(g, x+142,y+ 10,z+ 100);
	locateBlock(g, x+143,y+ 10,z+ 100);
	locateBlock(c, x+144,y+ 10,z+ 100);
	locateBlock(g, x+145,y+ 10,z+ 100);
	locateBlock(g, x+146,y+ 10,z+ 100);
	locateBlock(c, x+147,y+ 10,z+ 100);
	locateBlock(g, x+148,y+ 10,z+ 100);
	locateBlock(g, x+149,y+ 10,z+ 100);
	locateBlock(c, x+150,y+ 10,z+ 100);
	locateBlock(c, x+151,y+ 10,z+ 100);

	locateBlock(c, x+140,y+ 11,z+ 100);
	locateBlock(c, x+141,y+ 11,z+ 100);
	locateBlock(g, x+142,y+ 11,z+ 100);
	locateBlock(g, x+143,y+ 11,z+ 100);
	locateBlock(c, x+144,y+ 11,z+ 100);
	locateBlock(g, x+145,y+ 11,z+ 100);
	locateBlock(g, x+146,y+ 11,z+ 100);
	locateBlock(c, x+147,y+ 11,z+ 100);
	locateBlock(g, x+148,y+ 11,z+ 100);
	locateBlock(g, x+149,y+ 11,z+ 100);
	locateBlock(c, x+150,y+ 11,z+ 100);
	locateBlock(c, x+151,y+ 11,z+ 100);

	locateBlock(c, x+140,y+ 12,z+ 100);
	locateBlock(c, x+141,y+ 12,z+ 100);
	locateBlock(g, x+142,y+ 12,z+ 100);
	locateBlock(g, x+143,y+ 12,z+ 100);
	locateBlock(c, x+144,y+ 12,z+ 100);
	locateBlock(g, x+145,y+ 12,z+ 100);
	locateBlock(g, x+146,y+ 12,z+ 100);
	locateBlock(c, x+147,y+ 12,z+ 100);
	locateBlock(g, x+148,y+ 12,z+ 100);
	locateBlock(g, x+149,y+ 12,z+ 100);
	locateBlock(c, x+150,y+ 12,z+ 100);
	locateBlock(c, x+151,y+ 12,z+ 100);

	locateBlock(c, x+140,y+ 13,z+ 100);
	locateBlock(c, x+141,y+ 13,z+ 100);
	locateBlock(g, x+142,y+ 13,z+ 100);
	locateBlock(g, x+143,y+ 13,z+ 100);
	locateBlock(c, x+144,y+ 13,z+ 100);
	locateBlock(g, x+145,y+ 13,z+ 100);
	locateBlock(g, x+146,y+ 13,z+ 100);
	locateBlock(c, x+147,y+ 13,z+ 100);
	locateBlock(g, x+148,y+ 13,z+ 100);
	locateBlock(g, x+149,y+ 13,z+ 100);
	locateBlock(c, x+150,y+ 13,z+ 100);
	locateBlock(c, x+151,y+ 13,z+ 100);

	//정면 오른쪽 중+x 3번+y째 z+반복
	locateBlock(c, x+140,y+ 14,z+ 100);
	locateBlock(c, x+141,y+ 14,z+ 100);
	locateBlock(c, x+142,y+ 14,z+ 100);
	locateBlock(c, x+143,y+ 14,z+ 100);
	locateBlock(c, x+144,y+ 14,z+ 100);
	locateBlock(c, x+145,y+ 14,z+ 100);
	locateBlock(c, x+146,y+ 14,z+ 100);
	locateBlock(c, x+147,y+ 14,z+ 100);
	locateBlock(c, x+148,y+ 14,z+ 100);
	locateBlock(c, x+149,y+ 14,z+ 100);
	locateBlock(c, x+150,y+ 14,z+ 100);
	locateBlock(c, x+151,y+ 14,z+ 100);

	locateBlock(c, x+140,y+ 15,z+ 100);
	locateBlock(c, x+141,y+ 15,z+ 100);
	locateBlock(g, x+142,y+ 15,z+ 100);
	locateBlock(g, x+143,y+ 15,z+ 100);
	locateBlock(c, x+144,y+ 15,z+ 100);
	locateBlock(g, x+145,y+ 15,z+ 100);
	locateBlock(g, x+146,y+ 15,z+ 100);
	locateBlock(c, x+147,y+ 15,z+ 100);
	locateBlock(g, x+148,y+ 15,z+ 100);
	locateBlock(g, x+149,y+ 15,z+ 100);
	locateBlock(c, x+150,y+ 15,z+ 100);
	locateBlock(c, x+151,y+ 15,z+ 100);

	locateBlock(c, x+140,y+ 16,z+ 100);
	locateBlock(c, x+141,y+ 16,z+ 100);
	locateBlock(g, x+142,y+ 16,z+ 100);
	locateBlock(g, x+143,y+ 16,z+ 100);
	locateBlock(c, x+144,y+ 16,z+ 100);
	locateBlock(g, x+145,y+ 16,z+ 100);
	locateBlock(g, x+146,y+ 16,z+ 100);
	locateBlock(c, x+147,y+ 16,z+ 100);
	locateBlock(g, x+148,y+ 16,z+ 100);
	locateBlock(g, x+149,y+ 16,z+ 100);
	locateBlock(c, x+150,y+ 16,z+ 100);
	locateBlock(c, x+151,y+ 16,z+ 100);

	locateBlock(c, x+140,y+ 17,z+ 100);
	locateBlock(c, x+141,y+ 17,z+ 100);
	locateBlock(g, x+142,y+ 17,z+ 100);
	locateBlock(g, x+143,y+ 17,z+ 100);
	locateBlock(c, x+144,y+ 17,z+ 100);
	locateBlock(g, x+145,y+ 17,z+ 100);
	locateBlock(g, x+146,y+ 17,z+ 100);
	locateBlock(c, x+147,y+ 17,z+ 100);
	locateBlock(g, x+148,y+ 17,z+ 100);
	locateBlock(g, x+149,y+ 17,z+ 100);
	locateBlock(c, x+150,y+ 17,z+ 100);
	locateBlock(c, x+151,y+ 17,z+ 100);

	locateBlock(c, x+140,y+ 18,z+ 100);
	locateBlock(c, x+141,y+ 18,z+ 100);
	locateBlock(g, x+142,y+ 18,z+ 100);
	locateBlock(g, x+143,y+ 18,z+ 100);
	locateBlock(c, x+144,y+ 18,z+ 100);
	locateBlock(g, x+145,y+ 18,z+ 100);
	locateBlock(g, x+146,y+ 18,z+ 100);
	locateBlock(c, x+147,y+ 18,z+ 100);
	locateBlock(g, x+148,y+ 18,z+ 100);
	locateBlock(g, x+149,y+ 18,z+ 100);
	locateBlock(c, x+150,y+ 18,z+ 100);
	locateBlock(c, x+151,y+ 18,z+ 100);


	//왼쪽 벽		+x	+y

	locateBlock(c, x+98, y+4, z+93);
	locateBlock(c, x+98, y+4, z+94);
	locateBlock(c, x+98, y+4, z+95);
	locateBlock(c, x+98, y+4, z+96);
	locateBlock(c, x+98, y+4, z+97);
	locateBlock(c, x+98, y+4, z+98);
	locateBlock(c, x+98, y+4, z+99);

	locateBlock(c, x+98, y+5, z+93);
	locateBlock(c, x+98, y+5, z+94);
	locateBlock(c, x+98, y+5, z+95);
	locateBlock(c, x+98, y+5, z+96);
	locateBlock(c, x+98, y+5, z+97);
	locateBlock(c, x+98, y+5, z+98);
	locateBlock(c, x+98, y+5, z+99);

	locateBlock(c, x+98, y+6, z+93);
	locateBlock(c, x+98, y+6, z+94);
	locateBlock(c, x+98, y+6, z+95);
	locateBlock(c, x+98, y+6, z+96);
	locateBlock(c, x+98, y+6, z+97);
	locateBlock(c, x+98, y+6, z+98);
	locateBlock(c, x+98, y+6, z+99);

	locateBlock(c, x+98, y+7, z+93);
	locateBlock(c, x+98, y+7, z+94);
	locateBlock(c, x+98, y+7, z+95);
	locateBlock(c, x+98, y+7, z+96);
	locateBlock(c, x+98, y+7, z+97);
	locateBlock(c, x+98, y+7, z+98);
	locateBlock(c, x+98, y+7, z+99);

	locateBlock(c, x+98, y+8, z+93);
	locateBlock(c, x+98, y+8, z+94);
	locateBlock(c, x+98, y+8, z+95);
	locateBlock(c, x+98, y+8, z+96);
	locateBlock(c, x+98, y+8, z+97);
	locateBlock(c, x+98, y+8, z+98);
	locateBlock(c, x+98, y+8, z+99);

	locateBlock(c, x+98, y+9, z+93);
	locateBlock(c, x+98, y+9, z+94);
	locateBlock(c, x+98, y+9, z+95);
	locateBlock(c, x+98, y+9, z+96);
	locateBlock(c, x+98, y+9, z+97);
	locateBlock(c, x+98, y+9, z+98);
	locateBlock(c, x+98, y+9, z+99);

	locateBlock(c, x+98, y+10,z+ 93);
	locateBlock(c, x+98, y+10,z+ 94);
	locateBlock(c, x+98, y+10,z+ 95);
	locateBlock(c, x+98, y+10,z+ 96);
	locateBlock(c, x+98, y+10,z+ 97);
	locateBlock(c, x+98, y+10,z+ 98);
	locateBlock(c, x+98, y+10,z+ 99);

	locateBlock(c, x+98, y+11,z+ 93);
	locateBlock(c, x+98, y+11,z+ 94);
	locateBlock(c, x+98, y+11,z+ 95);
	locateBlock(c, x+98, y+11,z+ 96);
	locateBlock(c, x+98, y+11,z+ 97);
	locateBlock(c, x+98, y+11,z+ 98);
	locateBlock(c, x+98, y+11,z+ 99);

	locateBlock(c, x+98, y+12,z+ 93);
	locateBlock(c, x+98, y+12,z+ 94);
	locateBlock(c, x+98, y+12,z+ 95);
	locateBlock(c, x+98, y+12,z+ 96);
	locateBlock(c, x+98, y+12,z+ 97);
	locateBlock(c, x+98, y+12,z+ 98);
	locateBlock(c, x+98, y+12,z+ 99);

	locateBlock(c, x+98, y+13,z+ 93);
	locateBlock(c, x+98, y+13,z+ 94);
	locateBlock(c, x+98, y+13,z+ 95);
	locateBlock(c, x+98, y+13,z+ 96);
	locateBlock(c, x+98, y+13,z+ 97);
	locateBlock(c, x+98, y+13,z+ 98);
	locateBlock(c, x+98, y+13,z+ 99);

	locateBlock(c, x+98, y+14,z+ 93);
	locateBlock(c, x+98, y+14,z+ 94);
	locateBlock(c, x+98, y+14,z+ 95);
	locateBlock(c, x+98, y+14,z+ 96);
	locateBlock(c, x+98, y+14,z+ 97);
	locateBlock(c, x+98, y+14,z+ 98);
	locateBlock(c, x+98, y+14,z+ 99);

	locateBlock(c, x+98, y+15,z+ 93);
	locateBlock(c, x+98, y+15,z+ 94);
	locateBlock(c, x+98, y+15,z+ 95);
	locateBlock(c, x+98, y+15,z+ 96);
	locateBlock(c, x+98, y+15,z+ 97);
	locateBlock(c, x+98, y+15,z+ 98);
	locateBlock(c, x+98, y+15,z+ 99);

	locateBlock(c, x+98, y+16,z+ 93);
	locateBlock(c, x+98, y+16,z+ 94);
	locateBlock(c, x+98, y+16,z+ 95);
	locateBlock(c, x+98, y+16,z+ 96);
	locateBlock(c, x+98, y+16,z+ 97);
	locateBlock(c, x+98, y+16,z+ 98);
	locateBlock(c, x+98, y+16,z+ 99);

	locateBlock(c, x+98, y+17,z+ 93);
	locateBlock(c, x+98, y+17,z+ 94);
	locateBlock(c, x+98, y+17,z+ 95);
	locateBlock(c, x+98, y+17,z+ 96);
	locateBlock(c, x+98, y+17,z+ 97);
	locateBlock(c, x+98, y+17,z+ 98);
	locateBlock(c, x+98, y+17,z+ 99);

	locateBlock(c, x+98, y+18,z+ 93);
	locateBlock(c, x+98, y+18,z+ 94);
	locateBlock(c, x+98, y+18,z+ 95);
	locateBlock(c, x+98, y+18,z+ 96);
	locateBlock(c, x+98, y+18,z+ 97);
	locateBlock(c, x+98, y+18,z+ 98);
	locateBlock(c, x+98, y+18,z+ 99);

	//오른쪽 벽		+x	+y  z+

	locateBlock(c, x+151,y+ 4,z+ 93);
	locateBlock(c, x+151,y+ 4,z+ 94);
	locateBlock(c, x+151,y+ 4,z+ 95);
	locateBlock(c, x+151,y+ 4,z+ 96);
	locateBlock(c, x+151,y+ 4,z+ 97);
	locateBlock(c, x+151,y+ 4,z+ 98);
	locateBlock(c, x+151,y+ 4,z+ 99);

	locateBlock(c, x+151,y+ 5,z+ 93);
	locateBlock(c, x+151,y+ 5,z+ 94);
	locateBlock(c, x+151,y+ 5,z+ 95);
	locateBlock(c, x+151,y+ 5,z+ 96);
	locateBlock(c, x+151,y+ 5,z+ 97);
	locateBlock(c, x+151,y+ 5,z+ 98);
	locateBlock(c, x+151,y+ 5,z+ 99);

	locateBlock(c, x+151,y+ 6,z+ 93);
	locateBlock(c, x+151,y+ 6,z+ 94);
	locateBlock(c, x+151,y+ 6,z+ 95);
	locateBlock(c, x+151,y+ 6,z+ 96);
	locateBlock(c, x+151,y+ 6,z+ 97);
	locateBlock(c, x+151,y+ 6,z+ 98);
	locateBlock(c, x+151,y+ 6,z+ 99);

	locateBlock(c, x+151,y+ 7,z+ 93);
	locateBlock(c, x+151,y+ 7,z+ 94);
	locateBlock(c, x+151,y+ 7,z+ 95);
	locateBlock(c, x+151,y+ 7,z+ 96);
	locateBlock(c, x+151,y+ 7,z+ 97);
	locateBlock(c, x+151,y+ 7,z+ 98);
	locateBlock(c, x+151,y+ 7,z+ 99);

	locateBlock(c, x+151,y+ 8,z+ 93);
	locateBlock(c, x+151,y+ 8,z+ 94);
	locateBlock(c, x+151,y+ 8,z+ 95);
	locateBlock(c, x+151,y+ 8,z+ 96);
	locateBlock(c, x+151,y+ 8,z+ 97);
	locateBlock(c, x+151,y+ 8,z+ 98);
	locateBlock(c, x+151,y+ 8,z+ 99);

	locateBlock(c, x+151,y+ 9,z+ 93);
	locateBlock(c, x+151,y+ 9,z+ 94);
	locateBlock(c, x+151,y+ 9,z+ 95);
	locateBlock(c, x+151,y+ 9,z+ 96);
	locateBlock(c, x+151,y+ 9,z+ 97);
	locateBlock(c, x+151,y+ 9,z+ 98);
	locateBlock(c, x+151,y+ 9,z+ 99);

	locateBlock(c, x+151,y+ 10, z+93);
	locateBlock(c, x+151,y+ 10, z+94);
	locateBlock(c, x+151,y+ 10, z+95);
	locateBlock(c, x+151,y+ 10, z+96);
	locateBlock(c, x+151,y+ 10, z+97);
	locateBlock(c, x+151,y+ 10, z+98);
	locateBlock(c, x+151,y+ 10, z+99);

	locateBlock(c, x+151,y+ 11, +z+93);
	locateBlock(c, x+151,y+ 11, +z+94);
	locateBlock(c, x+151,y+ 11, +z+95);
	locateBlock(c, x+151,y+ 11, +z+96);
	locateBlock(c, x+151,y+ 11, +z+97);
	locateBlock(c, x+151,y+ 11, +z+98);
	locateBlock(c, x+151,y+ 11, +z+99);

	locateBlock(c, x+151,y+ 12, +z+93);
	locateBlock(c, x+151,y+ 12, +z+94);
	locateBlock(c, x+151,y+ 12, +z+95);
	locateBlock(c, x+151,y+ 12, +z+96);
	locateBlock(c, x+151,y+ 12, +z+97);
	locateBlock(c, x+151,y+ 12, +z+98);
	locateBlock(c, x+151,y+ 12, +z+99);

	locateBlock(c, x+151,y+ 13, +z+93);
	locateBlock(c, x+151,y+ 13, +z+94);
	locateBlock(c, x+151,y+ 13, +z+95);
	locateBlock(c, x+151,y+ 13, +z+96);
	locateBlock(c, x+151,y+ 13, +z+97);
	locateBlock(c, x+151,y+ 13, +z+98);
	locateBlock(c, x+151,y+ 13, +z+99);

	locateBlock(c, x+151,y+ 14, +z+93);
	locateBlock(c, x+151,y+ 14, +z+94);
	locateBlock(c, x+151,y+ 14, +z+95);
	locateBlock(c, x+151,y+ 14, +z+96);
	locateBlock(c, x+151,y+ 14, +z+97);
	locateBlock(c, x+151,y+ 14, +z+98);
	locateBlock(c, x+151,y+ 14, +z+99);

	locateBlock(c, x+151,y+ 15, +z+93);
	locateBlock(c, x+151,y+ 15, +z+94);
	locateBlock(c, x+151,y+ 15, +z+95);
	locateBlock(c, x+151,y+ 15, +z+96);
	locateBlock(c, x+151,y+ 15, +z+97);
	locateBlock(c, x+151,y+ 15, +z+98);
	locateBlock(c, x+151,y+ 15, +z+99);

	locateBlock(c, x+151,y+ 16, +z+93);
	locateBlock(c, x+151,y+ 16, +z+94);
	locateBlock(c, x+151,y+ 16, +z+95);
	locateBlock(c, x+151,y+ 16, +z+96);
	locateBlock(c, x+151,y+ 16, +z+97);
	locateBlock(c, x+151,y+ 16, +z+98);
	locateBlock(c, x+151,y+ 16, +z+99);

	locateBlock(c, x+151,y+ 17, +z+93);
	locateBlock(c, x+151,y+ 17, +z+94);
	locateBlock(c, x+151,y+ 17, +z+95);
	locateBlock(c, x+151,y+ 17, +z+96);
	locateBlock(c, x+151,y+ 17, +z+97);
	locateBlock(c, x+151,y+ 17, +z+98);
	locateBlock(c, x+151,y+ 17, +z+99);

	locateBlock(c, x+151,y+ 18, +z+93);
	locateBlock(c, x+151,y+ 18, +z+94);
	locateBlock(c, x+151,y+ 18, +z+95);
	locateBlock(c, x+151,y+ 18, +z+96);
	locateBlock(c, x+151,y+ 18, +z+97);
	locateBlock(c, x+151,y+ 18, +z+98);
	locateBlock(c, x+151,y+ 18, +z+99);

	//후면 벽		+x	+y
	locateBlock(c, x+99, y+4, z+93);
	locateBlock(c, x+101,y+ 4,z+ 93);
	locateBlock(c, x+102,y+ 4,z+ 93);
	locateBlock(c, x+103,y+ 4,z+ 93);
	locateBlock(c, x+104,y+ 4,z+ 93);
	locateBlock(c, x+105,y+ 4,z+ 93);
	locateBlock(c, x+106,y+ 4,z+ 93);
	locateBlock(c, x+107,y+ 4,z+ 93);
	locateBlock(c, x+108,y+ 4,z+ 93);
	locateBlock(c, x+109,y+ 4,z+ 93);
	locateBlock(c, x+110,y+ 4,z+ 93);
	locateBlock(c, x+111,y+ 4,z+ 93);
	locateBlock(c, x+112,y+ 4,z+ 93);
	locateBlock(c, x+113,y+ 4,z+ 93);
	locateBlock(c, x+114,y+ 4,z+ 93);
	locateBlock(c, x+115,y+ 4,z+ 93);
	locateBlock(c, x+116,y+ 4,z+ 93);
	locateBlock(c, x+117,y+ 4,z+ 93);
	locateBlock(c, x+118,y+ 4,z+ 93);
	locateBlock(c, x+119,y+ 4,z+ 93);
	locateBlock(c, x+120,y+ 4,z+ 93);
	locateBlock(c, x+121,y+ 4,z+ 93);
	locateBlock(c, x+122,y+ 4,z+ 93);
	locateBlock(c, x+123,y+ 4,z+ 93);
	locateBlock(c, x+124,y+ 4,z+ 93);
	locateBlock(c, x+125,y+ 4,z+ 93);
	locateBlock(c, x+126,y+ 4,z+ 93);
	locateBlock(c, x+127,y+ 4,z+ 93);
	locateBlock(c, x+128,y+ 4,z+ 93);
	locateBlock(c, x+129,y+ 4,z+ 93);
	locateBlock(c, x+130,y+ 4,z+ 93);
	locateBlock(c, x+131,y+ 4,z+ 93);
	locateBlock(c, x+132,y+ 4,z+ 93);
	locateBlock(c, x+133,y+ 4,z+ 93);
	locateBlock(c, x+134,y+ 4,z+ 93);
	locateBlock(c, x+135,y+ 4,z+ 93);
	locateBlock(c, x+136,y+ 4,z+ 93);
	locateBlock(c, x+137,y+ 4,z+ 93);
	locateBlock(c, x+138,y+ 4,z+ 93);
	locateBlock(c, x+139,y+ 4,z+ 93);
	locateBlock(c, x+140,y+ 4,z+ 93);
	locateBlock(c, x+141,y+ 4,z+ 93);
	locateBlock(c, x+142,y+ 4,z+ 93);
	locateBlock(c, x+143,y+ 4,z+ 93);
	locateBlock(c, x+144,y+ 4,z+ 93);
	locateBlock(c, x+145,y+ 4,z+ 93);
	locateBlock(c, x+146,y+ 4,z+ 93);
	locateBlock(c, x+147,y+ 4,z+ 93);
	locateBlock(c, x+148,y+ 4,z+ 93);
	locateBlock(c, x+149,y+ 4,z+ 93);
	locateBlock(c, x+150,y+ 4,z+ 93);

	locateBlock(c, x+99, y+5, z+93);
	locateBlock(c, x+101,y+ 5,z+ 93);
	locateBlock(c, x+102,y+ 5,z+ 93);
	locateBlock(c, x+103,y+ 5,z+ 93);
	locateBlock(c, x+104,y+ 5,z+ 93);
	locateBlock(c, x+105,y+ 5,z+ 93);
	locateBlock(c, x+106,y+ 5,z+ 93);
	locateBlock(c, x+107,y+ 5,z+ 93);
	locateBlock(c, x+108,y+ 5,z+ 93);
	locateBlock(c, x+109,y+ 5,z+ 93);
	locateBlock(c, x+110,y+ 5,z+ 93);
	locateBlock(c, x+111,y+ 5,z+ 93);
	locateBlock(c, x+112,y+ 5,z+ 93);
	locateBlock(c, x+113,y+ 5,z+ 93);
	locateBlock(c, x+114,y+ 5,z+ 93);
	locateBlock(c, x+115,y+ 5,z+ 93);
	locateBlock(c, x+116,y+ 5,z+ 93);
	locateBlock(c, x+117,y+ 5,z+ 93);
	locateBlock(c, x+118,y+ 5,z+ 93);
	locateBlock(c, x+119,y+ 5,z+ 93);
	locateBlock(c, x+120,y+ 5,z+ 93);
	locateBlock(c, x+121,y+ 5,z+ 93);
	locateBlock(c, x+122,y+ 5,z+ 93);
	locateBlock(c, x+123,y+ 5,z+ 93);
	locateBlock(c, x+124,y+ 5,z+ 93);
	locateBlock(c, x+125,y+ 5,z+ 93);
	locateBlock(c, x+126,y+ 5,z+ 93);
	locateBlock(c, x+127,y+ 5,z+ 93);
	locateBlock(c, x+128,y+ 5,z+ 93);
	locateBlock(c, x+129,y+ 5,z+ 93);
	locateBlock(c, x+130,y+ 5,z+ 93);
	locateBlock(c, x+131,y+ 5,z+ 93);
	locateBlock(c, x+132,y+ 5,z+ 93);
	locateBlock(c, x+133,y+ 5,z+ 93);
	locateBlock(c, x+134,y+ 5,z+ 93);
	locateBlock(c, x+135,y+ 5,z+ 93);
	locateBlock(c, x+136,y+ 5,z+ 93);
	locateBlock(c, x+137,y+ 5,z+ 93);
	locateBlock(c, x+138,y+ 5,z+ 93);
	locateBlock(c, x+139,y+ 5,z+ 93);
	locateBlock(c, x+140,y+ 5,z+ 93);
	locateBlock(c, x+141,y+ 5,z+ 93);
	locateBlock(c, x+142,y+ 5,z+ 93);
	locateBlock(c, x+143,y+ 5,z+ 93);
	locateBlock(c, x+144,y+ 5,z+ 93);
	locateBlock(c, x+145,y+ 5,z+ 93);
	locateBlock(c, x+146,y+ 5,z+ 93);
	locateBlock(c, x+147,y+ 5,z+ 93);
	locateBlock(c, x+148,y+ 5,z+ 93);
	locateBlock(c, x+149,y+ 5,z+ 93);
	locateBlock(c, x+150,y+ 5,z+ 93);

	locateBlock(c, x+99, y+6, z+93);
	locateBlock(c, x+101,y+ 6,z+ 93);
	locateBlock(c, x+102,y+ 6,z+ 93);
	locateBlock(c, x+103,y+ 6,z+ 93);
	locateBlock(c, x+104,y+ 6,z+ 93);
	locateBlock(c, x+105,y+ 6,z+ 93);
	locateBlock(c, x+106,y+ 6,z+ 93);
	locateBlock(c, x+107,y+ 6,z+ 93);
	locateBlock(c, x+108,y+ 6,z+ 93);
	locateBlock(c, x+109,y+ 6,z+ 93);
	locateBlock(c, x+110,y+ 6,z+ 93);
	locateBlock(c, x+111,y+ 6,z+ 93);
	locateBlock(c, x+112,y+ 6,z+ 93);
	locateBlock(c, x+113,y+ 6,z+ 93);
	locateBlock(c, x+114,y+ 6,z+ 93);
	locateBlock(c, x+115,y+ 6,z+ 93);
	locateBlock(c, x+116,y+ 6,z+ 93);
	locateBlock(c, x+117,y+ 6,z+ 93);
	locateBlock(c, x+118,y+ 6,z+ 93);
	locateBlock(c, x+119,y+ 6,z+ 93);
	locateBlock(c, x+120,y+ 6,z+ 93);
	locateBlock(c, x+121,y+ 6,z+ 93);
	locateBlock(c, x+122,y+ 6,z+ 93);
	locateBlock(c, x+123,y+ 6,z+ 93);
	locateBlock(c, x+124,y+ 6,z+ 93);
	locateBlock(c, x+125,y+ 6,z+ 93);
	locateBlock(c, x+126,y+ 6,z+ 93);
	locateBlock(c, x+127,y+ 6,z+ 93);
	locateBlock(c, x+128,y+ 6,z+ 93);
	locateBlock(c, x+129,y+ 6,z+ 93);
	locateBlock(c, x+130,y+ 6,z+ 93);
	locateBlock(c, x+131,y+ 6,z+ 93);
	locateBlock(c, x+132,y+ 6,z+ 93);
	locateBlock(c, x+133,y+ 6,z+ 93);
	locateBlock(c, x+134,y+ 6,z+ 93);
	locateBlock(c, x+135,y+ 6,z+ 93);
	locateBlock(c, x+136,y+ 6,z+ 93);
	locateBlock(c, x+137,y+ 6,z+ 93);
	locateBlock(c, x+138,y+ 6,z+ 93);
	locateBlock(c, x+139,y+ 6,z+ 93);
	locateBlock(c, x+140,y+ 6,z+ 93);
	locateBlock(c, x+141,y+ 6,z+ 93);
	locateBlock(c, x+142,y+ 6,z+ 93);
	locateBlock(c, x+143,y+ 6,z+ 93);
	locateBlock(c, x+144,y+ 6,z+ 93);
	locateBlock(c, x+145,y+ 6,z+ 93);
	locateBlock(c, x+146,y+ 6,z+ 93);
	locateBlock(c, x+147,y+ 6,z+ 93);
	locateBlock(c, x+148,y+ 6,z+ 93);
	locateBlock(c, x+149,y+ 6,z+ 93);
	locateBlock(c, x+150,y+ 6,z+ 93);

	locateBlock(c, x+99, y+7, z+93);
	locateBlock(c, x+101,y+ 7,z+ 93);
	locateBlock(c, x+102,y+ 7,z+ 93);
	locateBlock(c, x+103,y+ 7,z+ 93);
	locateBlock(c, x+104,y+ 7,z+ 93);
	locateBlock(c, x+105,y+ 7,z+ 93);
	locateBlock(c, x+106,y+ 7,z+ 93);
	locateBlock(c, x+107,y+ 7,z+ 93);
	locateBlock(c, x+108,y+ 7,z+ 93);
	locateBlock(c, x+109,y+ 7,z+ 93);
	locateBlock(c, x+110,y+ 7,z+ 93);
	locateBlock(c, x+111,y+ 7,z+ 93);
	locateBlock(c, x+112,y+ 7,z+ 93);
	locateBlock(c, x+113,y+ 7,z+ 93);
	locateBlock(c, x+114,y+ 7,z+ 93);
	locateBlock(c, x+115,y+ 7,z+ 93);
	locateBlock(c, x+116,y+ 7,z+ 93);
	locateBlock(c, x+117,y+ 7,z+ 93);
	locateBlock(c, x+118,y+ 7,z+ 93);
	locateBlock(c, x+119,y+ 7,z+ 93);
	locateBlock(c, x+120,y+ 7,z+ 93);
	locateBlock(c, x+121,y+ 7,z+ 93);
	locateBlock(c, x+122,y+ 7,z+ 93);
	locateBlock(c, x+123,y+ 7,z+ 93);
	locateBlock(c, x+124,y+ 7,z+ 93);
	locateBlock(c, x+125,y+ 7,z+ 93);
	locateBlock(c, x+126,y+ 7,z+ 93);
	locateBlock(c, x+127,y+ 7,z+ 93);
	locateBlock(c, x+128,y+ 7,z+ 93);
	locateBlock(c, x+129,y+ 7,z+ 93);
	locateBlock(c, x+130,y+ 7,z+ 93);
	locateBlock(c, x+131,y+ 7,z+ 93);
	locateBlock(c, x+132,y+ 7,z+ 93);
	locateBlock(c, x+133,y+ 7,z+ 93);
	locateBlock(c, x+134,y+ 7,z+ 93);
	locateBlock(c, x+135,y+ 7,z+ 93);
	locateBlock(c, x+136,y+ 7,z+ 93);
	locateBlock(c, x+137,y+ 7,z+ 93);
	locateBlock(c, x+138,y+ 7,z+ 93);
	locateBlock(c, x+139,y+ 7,z+ 93);
	locateBlock(c, x+140,y+ 7,z+ 93);
	locateBlock(c, x+141,y+ 7,z+ 93);
	locateBlock(c, x+142,y+ 7,z+ 93);
	locateBlock(c, x+143,y+ 7,z+ 93);
	locateBlock(c, x+144,y+ 7,z+ 93);
	locateBlock(c, x+145,y+ 7,z+ 93);
	locateBlock(c, x+146,y+ 7,z+ 93);
	locateBlock(c, x+147,y+ 7,z+ 93);
	locateBlock(c, x+148,y+ 7,z+ 93);
	locateBlock(c, x+149,y+ 7,z+ 93);
	locateBlock(c, x+150,y+ 7,z+ 93);

	locateBlock(c, x+99, y+8, z+93);
	locateBlock(c, x+101,y+ 8,z+ 93);
	locateBlock(c, x+102,y+ 8,z+ 93);
	locateBlock(c, x+103,y+ 8,z+ 93);
	locateBlock(c, x+104,y+ 8,z+ 93);
	locateBlock(c, x+105,y+ 8,z+ 93);
	locateBlock(c, x+106,y+ 8,z+ 93);
	locateBlock(c, x+107,y+ 8,z+ 93);
	locateBlock(c, x+108,y+ 8,z+ 93);
	locateBlock(c, x+109,y+ 8,z+ 93);
	locateBlock(c, x+110,y+ 8,z+ 93);
	locateBlock(c, x+111,y+ 8,z+ 93);
	locateBlock(c, x+112,y+ 8,z+ 93);
	locateBlock(c, x+113,y+ 8,z+ 93);
	locateBlock(c, x+114,y+ 8,z+ 93);
	locateBlock(c, x+115,y+ 8,z+ 93);
	locateBlock(c, x+116,y+ 8,z+ 93);
	locateBlock(c, x+117,y+ 8,z+ 93);
	locateBlock(c, x+118,y+ 8,z+ 93);
	locateBlock(c, x+119,y+ 8,z+ 93);
	locateBlock(c, x+120,y+ 8,z+ 93);
	locateBlock(c, x+121,y+ 8,z+ 93);
	locateBlock(c, x+122,y+ 8,z+ 93);
	locateBlock(c, x+123,y+ 8,z+ 93);
	locateBlock(c, x+124,y+ 8,z+ 93);
	locateBlock(c, x+125,y+ 8,z+ 93);
	locateBlock(c, x+126,y+ 8,z+ 93);
	locateBlock(c, x+127,y+ 8,z+ 93);
	locateBlock(c, x+128,y+ 8,z+ 93);
	locateBlock(c, x+129,y+ 8,z+ 93);
	locateBlock(c, x+130,y+ 8,z+ 93);
	locateBlock(c, x+131,y+ 8,z+ 93);
	locateBlock(c, x+132,y+ 8,z+ 93);
	locateBlock(c, x+133,y+ 8,z+ 93);
	locateBlock(c, x+134,y+ 8,z+ 93);
	locateBlock(c, x+135,y+ 8,z+ 93);
	locateBlock(c, x+136,y+ 8,z+ 93);
	locateBlock(c, x+137,y+ 8,z+ 93);
	locateBlock(c, x+138,y+ 8,z+ 93);
	locateBlock(c, x+139,y+ 8,z+ 93);
	locateBlock(c, x+140,y+ 8,z+ 93);
	locateBlock(c, x+141,y+ 8,z+ 93);
	locateBlock(c, x+142,y+ 8,z+ 93);
	locateBlock(c, x+143,y+ 8,z+ 93);
	locateBlock(c, x+144,y+ 8,z+ 93);
	locateBlock(c, x+145,y+ 8,z+ 93);
	locateBlock(c, x+146,y+ 8,z+ 93);
	locateBlock(c, x+147,y+ 8,z+ 93);
	locateBlock(c, x+148,y+ 8,z+ 93);
	locateBlock(c, x+149,y+ 8,z+ 93);
	locateBlock(c, x+150,y+ 8,z+ 93);

	locateBlock(c, x+99, y+9, z+93);
	locateBlock(c, x+101,y+ 9,z+ 93);
	locateBlock(c, x+102,y+ 9,z+ 93);
	locateBlock(c, x+103,y+ 9,z+ 93);
	locateBlock(c, x+104,y+ 9,z+ 93);
	locateBlock(c, x+105,y+ 9,z+ 93);
	locateBlock(c, x+106,y+ 9,z+ 93);
	locateBlock(c, x+107,y+ 9,z+ 93);
	locateBlock(c, x+108,y+ 9,z+ 93);
	locateBlock(c, x+109,y+ 9,z+ 93);
	locateBlock(c, x+110,y+ 9,z+ 93);
	locateBlock(c, x+111,y+ 9,z+ 93);
	locateBlock(c, x+112,y+ 9,z+ 93);
	locateBlock(c, x+113,y+ 9,z+ 93);
	locateBlock(c, x+114,y+ 9,z+ 93);
	locateBlock(c, x+115,y+ 9,z+ 93);
	locateBlock(c, x+116,y+ 9,z+ 93);
	locateBlock(c, x+117,y+ 9,z+ 93);
	locateBlock(c, x+118,y+ 9,z+ 93);
	locateBlock(c, x+119,y+ 9,z+ 93);
	locateBlock(c, x+120,y+ 9,z+ 93);
	locateBlock(c, x+121,y+ 9,z+ 93);
	locateBlock(c, x+122,y+ 9,z+ 93);
	locateBlock(c, x+123,y+ 9,z+ 93);
	locateBlock(c, x+124,y+ 9,z+ 93);
	locateBlock(c, x+125,y+ 9,z+ 93);
	locateBlock(c, x+126,y+ 9,z+ 93);
	locateBlock(c, x+127,y+ 9,z+ 93);
	locateBlock(c, x+128,y+ 9,z+ 93);
	locateBlock(c, x+129,y+ 9,z+ 93);
	locateBlock(c, x+130,y+ 9,z+ 93);
	locateBlock(c, x+131,y+ 9,z+ 93);
	locateBlock(c, x+132,y+ 9,z+ 93);
	locateBlock(c, x+133,y+ 9,z+ 93);
	locateBlock(c, x+134,y+ 9,z+ 93);
	locateBlock(c, x+135,y+ 9,z+ 93);
	locateBlock(c, x+136,y+ 9,z+ 93);
	locateBlock(c, x+137,y+ 9,z+ 93);
	locateBlock(c, x+138,y+ 9,z+ 93);
	locateBlock(c, x+139,y+ 9,z+ 93);
	locateBlock(c, x+140,y+ 9,z+ 93);
	locateBlock(c, x+141,y+ 9,z+ 93);
	locateBlock(c, x+142,y+ 9,z+ 93);
	locateBlock(c, x+143,y+ 9,z+ 93);
	locateBlock(c, x+144,y+ 9,z+ 93);
	locateBlock(c, x+145,y+ 9,z+ 93);
	locateBlock(c, x+146,y+ 9,z+ 93);
	locateBlock(c, x+147,y+ 9,z+ 93);
	locateBlock(c, x+148,y+ 9,z+ 93);
	locateBlock(c, x+149,y+ 9,z+ 93);
	locateBlock(c, x+150,y+ 9,z+ 93);

	locateBlock(c, x+99, y+10, z+93);
	locateBlock(c, x+101,y+ 10,z+ 93);
	locateBlock(c, x+102,y+ 10,z+ 93);
	locateBlock(c, x+103,y+ 10,z+ 93);
	locateBlock(c, x+104,y+ 10,z+ 93);
	locateBlock(c, x+105,y+ 10,z+ 93);
	locateBlock(c, x+106,y+ 10,z+ 93);
	locateBlock(c, x+107,y+ 10,z+ 93);
	locateBlock(c, x+108,y+ 10,z+ 93);
	locateBlock(c, x+109,y+ 10,z+ 93);
	locateBlock(c, x+110,y+ 10,z+ 93);
	locateBlock(c, x+111,y+ 10,z+ 93);
	locateBlock(c, x+112,y+ 10,z+ 93);
	locateBlock(c, x+113,y+ 10,z+ 93);
	locateBlock(c, x+114,y+ 10,z+ 93);
	locateBlock(c, x+115,y+ 10,z+ 93);
	locateBlock(c, x+116,y+ 10,z+ 93);
	locateBlock(c, x+117,y+ 10,z+ 93);
	locateBlock(c, x+118,y+ 10,z+ 93);
	locateBlock(c, x+119,y+ 10,z+ 93);
	locateBlock(c, x+120,y+ 10,z+ 93);
	locateBlock(c, x+121,y+ 10,z+ 93);
	locateBlock(c, x+122,y+ 10,z+ 93);
	locateBlock(c, x+123,y+ 10,z+ 93);
	locateBlock(c, x+124,y+ 10,z+ 93);
	locateBlock(c, x+125,y+ 10,z+ 93);
	locateBlock(c, x+126,y+ 10,z+ 93);
	locateBlock(c, x+127,y+ 10,z+ 93);
	locateBlock(c, x+128,y+ 10,z+ 93);
	locateBlock(c, x+129,y+ 10,z+ 93);
	locateBlock(c, x+130,y+ 10,z+ 93);
	locateBlock(c, x+131,y+ 10,z+ 93);
	locateBlock(c, x+132,y+ 10,z+ 93);
	locateBlock(c, x+133,y+ 10,z+ 93);
	locateBlock(c, x+134,y+ 10,z+ 93);
	locateBlock(c, x+135,y+ 10,z+ 93);
	locateBlock(c, x+136,y+ 10,z+ 93);
	locateBlock(c, x+137,y+ 10,z+ 93);
	locateBlock(c, x+138,y+ 10,z+ 93);
	locateBlock(c, x+139,y+ 10,z+ 93);
	locateBlock(c, x+140,y+ 10,z+ 93);
	locateBlock(c, x+141,y+ 10,z+ 93);
	locateBlock(c, x+142,y+ 10,z+ 93);
	locateBlock(c, x+143,y+ 10,z+ 93);
	locateBlock(c, x+144,y+ 10,z+ 93);
	locateBlock(c, x+145,y+ 10,z+ 93);
	locateBlock(c, x+146,y+ 10,z+ 93);
	locateBlock(c, x+147,y+ 10,z+ 93);
	locateBlock(c, x+148,y+ 10,z+ 93);
	locateBlock(c, x+149,y+ 10,z+ 93);
	locateBlock(c, x+150,y+ 10,z+ 93);

	locateBlock(c, x+99, y+11, z+93);
	locateBlock(c, x+101,y+ 11,z+ 93);
	locateBlock(c, x+102,y+ 11,z+ 93);
	locateBlock(c, x+103,y+ 11,z+ 93);
	locateBlock(c, x+104,y+ 11,z+ 93);
	locateBlock(c, x+105,y+ 11,z+ 93);
	locateBlock(c, x+106,y+ 11,z+ 93);
	locateBlock(c, x+107,y+ 11,z+ 93);
	locateBlock(c, x+108,y+ 11,z+ 93);
	locateBlock(c, x+109,y+ 11,z+ 93);
	locateBlock(c, x+110,y+ 11,z+ 93);
	locateBlock(c, x+111,y+ 11,z+ 93);
	locateBlock(c, x+112,y+ 11,z+ 93);
	locateBlock(c, x+113,y+ 11,z+ 93);
	locateBlock(c, x+114,y+ 11,z+ 93);
	locateBlock(c, x+115,y+ 11,z+ 93);
	locateBlock(c, x+116,y+ 11,z+ 93);
	locateBlock(c, x+117,y+ 11,z+ 93);
	locateBlock(c, x+118,y+ 11,z+ 93);
	locateBlock(c, x+119,y+ 11,z+ 93);
	locateBlock(c, x+120,y+ 11,z+ 93);
	locateBlock(c, x+121,y+ 11,z+ 93);
	locateBlock(c, x+122,y+ 11,z+ 93);
	locateBlock(c, x+123,y+ 11,z+ 93);
	locateBlock(c, x+124,y+ 11,z+ 93);
	locateBlock(c, x+125,y+ 11,z+ 93);
	locateBlock(c, x+126,y+ 11,z+ 93);
	locateBlock(c, x+127,y+ 11,z+ 93);
	locateBlock(c, x+128,y+ 11,z+ 93);
	locateBlock(c, x+129,y+ 11,z+ 93);
	locateBlock(c, x+130,y+ 11,z+ 93);
	locateBlock(c, x+131,y+ 11,z+ 93);
	locateBlock(c, x+132,y+ 11,z+ 93);
	locateBlock(c, x+133,y+ 11,z+ 93);
	locateBlock(c, x+134,y+ 11,z+ 93);
	locateBlock(c, x+135,y+ 11,z+ 93);
	locateBlock(c, x+136,y+ 11,z+ 93);
	locateBlock(c, x+137,y+ 11,z+ 93);
	locateBlock(c, x+138,y+ 11,z+ 93);
	locateBlock(c, x+139,y+ 11,z+ 93);
	locateBlock(c, x+140,y+ 11,z+ 93);
	locateBlock(c, x+141,y+ 11,z+ 93);
	locateBlock(c, x+142,y+ 11,z+ 93);
	locateBlock(c, x+143,y+ 11,z+ 93);
	locateBlock(c, x+144,y+ 11,z+ 93);
	locateBlock(c, x+145,y+ 11,z+ 93);
	locateBlock(c, x+146,y+ 11,z+ 93);
	locateBlock(c, x+147,y+ 11,z+ 93);
	locateBlock(c, x+148,y+ 11,z+ 93);
	locateBlock(c, x+149,y+ 11,z+ 93);
	locateBlock(c, x+150,y+ 11,z+ 93);

	locateBlock(c, x+99, y+12, z+93);
	locateBlock(c, x+101,y+ 12,z+ 93);
	locateBlock(c, x+102,y+ 12,z+ 93);
	locateBlock(c, x+103,y+ 12,z+ 93);
	locateBlock(c, x+104,y+ 12,z+ 93);
	locateBlock(c, x+105,y+ 12,z+ 93);
	locateBlock(c, x+106,y+ 12,z+ 93);
	locateBlock(c, x+107,y+ 12,z+ 93);
	locateBlock(c, x+108,y+ 12,z+ 93);
	locateBlock(c, x+109,y+ 12,z+ 93);
	locateBlock(c, x+110,y+ 12,z+ 93);
	locateBlock(c, x+111,y+ 12,z+ 93);
	locateBlock(c, x+112,y+ 12,z+ 93);
	locateBlock(c, x+113,y+ 12,z+ 93);
	locateBlock(c, x+114,y+ 12,z+ 93);
	locateBlock(c, x+115,y+ 12,z+ 93);
	locateBlock(c, x+116,y+ 12,z+ 93);
	locateBlock(c, x+117,y+ 12,z+ 93);
	locateBlock(c, x+118,y+ 12,z+ 93);
	locateBlock(c, x+119,y+ 12,z+ 93);
	locateBlock(c, x+120,y+ 12,z+ 93);
	locateBlock(c, x+121,y+ 12,z+ 93);
	locateBlock(c, x+122,y+ 12,z+ 93);
	locateBlock(c, x+123,y+ 12,z+ 93);
	locateBlock(c, x+124,y+ 12,z+ 93);
	locateBlock(c, x+125,y+ 12,z+ 93);
	locateBlock(c, x+126,y+ 12,z+ 93);
	locateBlock(c, x+127,y+ 12,z+ 93);
	locateBlock(c, x+128,y+ 12,z+ 93);
	locateBlock(c, x+129,y+ 12,z+ 93);
	locateBlock(c, x+130,y+ 12,z+ 93);
	locateBlock(c, x+131,y+ 12,z+ 93);
	locateBlock(c, x+132,y+ 12,z+ 93);
	locateBlock(c, x+133,y+ 12,z+ 93);
	locateBlock(c, x+134,y+ 12,z+ 93);
	locateBlock(c, x+135,y+ 12,z+ 93);
	locateBlock(c, x+136,y+ 12,z+ 93);
	locateBlock(c, x+137,y+ 12,z+ 93);
	locateBlock(c, x+138,y+ 12,z+ 93);
	locateBlock(c, x+139,y+ 12,z+ 93);
	locateBlock(c, x+140,y+ 12,z+ 93);
	locateBlock(c, x+141,y+ 12,z+ 93);
	locateBlock(c, x+142,y+ 12,z+ 93);
	locateBlock(c, x+143,y+ 12,z+ 93);
	locateBlock(c, x+144,y+ 12,z+ 93);
	locateBlock(c, x+145,y+ 12,z+ 93);
	locateBlock(c, x+146,y+ 12,z+ 93);
	locateBlock(c, x+147,y+ 12,z+ 93);
	locateBlock(c, x+148,y+ 12,z+ 93);
	locateBlock(c, x+149,y+ 12,z+ 93);
	locateBlock(c, x+150,y+ 12,z+ 93);

	locateBlock(c, x+99, y+13, z+93);
	locateBlock(c, x+101,y+ 13,z+ 93);
	locateBlock(c, x+102,y+ 13,z+ 93);
	locateBlock(c, x+103,y+ 13,z+ 93);
	locateBlock(c, x+104,y+ 13,z+ 93);
	locateBlock(c, x+105,y+ 13,z+ 93);
	locateBlock(c, x+106,y+ 13,z+ 93);
	locateBlock(c, x+107,y+ 13,z+ 93);
	locateBlock(c, x+108,y+ 13,z+ 93);
	locateBlock(c, x+109,y+ 13,z+ 93);
	locateBlock(c, x+110,y+ 13,z+ 93);
	locateBlock(c, x+111,y+ 13,z+ 93);
	locateBlock(c, x+112,y+ 13,z+ 93);
	locateBlock(c, x+113,y+ 13,z+ 93);
	locateBlock(c, x+114,y+ 13,z+ 93);
	locateBlock(c, x+115,y+ 13,z+ 93);
	locateBlock(c, x+116,y+ 13,z+ 93);
	locateBlock(c, x+117,y+ 13,z+ 93);
	locateBlock(c, x+118,y+ 13,z+ 93);
	locateBlock(c, x+119,y+ 13,z+ 93);
	locateBlock(c, x+120,y+ 13,z+ 93);
	locateBlock(c, x+121,y+ 13,z+ 93);
	locateBlock(c, x+122,y+ 13,z+ 93);
	locateBlock(c, x+123,y+ 13,z+ 93);
	locateBlock(c, x+124,y+ 13,z+ 93);
	locateBlock(c, x+125,y+ 13,z+ 93);
	locateBlock(c, x+126,y+ 13,z+ 93);
	locateBlock(c, x+127,y+ 13,z+ 93);
	locateBlock(c, x+128,y+ 13,z+ 93);
	locateBlock(c, x+129,y+ 13,z+ 93);
	locateBlock(c, x+130,y+ 13,z+ 93);
	locateBlock(c, x+131,y+ 13,z+ 93);
	locateBlock(c, x+132,y+ 13,z+ 93);
	locateBlock(c, x+133,y+ 13,z+ 93);
	locateBlock(c, x+134,y+ 13,z+ 93);
	locateBlock(c, x+135,y+ 13,z+ 93);
	locateBlock(c, x+136,y+ 13,z+ 93);
	locateBlock(c, x+137,y+ 13,z+ 93);
	locateBlock(c, x+138,y+ 13,z+ 93);
	locateBlock(c, x+139,y+ 13,z+ 93);
	locateBlock(c, x+140,y+ 13,z+ 93);
	locateBlock(c, x+141,y+ 13,z+ 93);
	locateBlock(c, x+142,y+ 13,z+ 93);
	locateBlock(c, x+143,y+ 13,z+ 93);
	locateBlock(c, x+144,y+ 13,z+ 93);
	locateBlock(c, x+145,y+ 13,z+ 93);
	locateBlock(c, x+146,y+ 13,z+ 93);
	locateBlock(c, x+147,y+ 13,z+ 93);
	locateBlock(c, x+148,y+ 13,z+ 93);
	locateBlock(c, x+149,y+ 13,z+ 93);
	locateBlock(c, x+150,y+ 13,z+ 93);

	locateBlock(c, x+99, y+14, z+93);
	locateBlock(c, x+101,y+ 14,z+ 93);
	locateBlock(c, x+102,y+ 14,z+ 93);
	locateBlock(c, x+103,y+ 14,z+ 93);
	locateBlock(c, x+104,y+ 14,z+ 93);
	locateBlock(c, x+105,y+ 14,z+ 93);
	locateBlock(c, x+106,y+ 14,z+ 93);
	locateBlock(c, x+107,y+ 14,z+ 93);
	locateBlock(c, x+108,y+ 14,z+ 93);
	locateBlock(c, x+109,y+ 14,z+ 93);
	locateBlock(c, x+110,y+ 14,z+ 93);
	locateBlock(c, x+111,y+ 14,z+ 93);
	locateBlock(c, x+112,y+ 14,z+ 93);
	locateBlock(c, x+113,y+ 14,z+ 93);
	locateBlock(c, x+114,y+ 14,z+ 93);
	locateBlock(c, x+115,y+ 14,z+ 93);
	locateBlock(c, x+116,y+ 14,z+ 93);
	locateBlock(c, x+117,y+ 14,z+ 93);
	locateBlock(c, x+118,y+ 14,z+ 93);
	locateBlock(c, x+119,y+ 14,z+ 93);
	locateBlock(c, x+120,y+ 14,z+ 93);
	locateBlock(c, x+121,y+ 14,z+ 93);
	locateBlock(c, x+122,y+ 14,z+ 93);
	locateBlock(c, x+123,y+ 14,z+ 93);
	locateBlock(c, x+124,y+ 14,z+ 93);
	locateBlock(c, x+125,y+ 14,z+ 93);
	locateBlock(c, x+126,y+ 14,z+ 93);
	locateBlock(c, x+127,y+ 14,z+ 93);
	locateBlock(c, x+128,y+ 14,z+ 93);
	locateBlock(c, x+129,y+ 14,z+ 93);
	locateBlock(c, x+130,y+ 14,z+ 93);
	locateBlock(c, x+131,y+ 14,z+ 93);
	locateBlock(c, x+132,y+ 14,z+ 93);
	locateBlock(c, x+133,y+ 14,z+ 93);
	locateBlock(c, x+134,y+ 14,z+ 93);
	locateBlock(c, x+135,y+ 14,z+ 93);
	locateBlock(c, x+136,y+ 14,z+ 93);
	locateBlock(c, x+137,y+ 14,z+ 93);
	locateBlock(c, x+138,y+ 14,z+ 93);
	locateBlock(c, x+139,y+ 14,z+ 93);
	locateBlock(c, x+140,y+ 14,z+ 93);
	locateBlock(c, x+141,y+ 14,z+ 93);
	locateBlock(c, x+142,y+ 14,z+ 93);
	locateBlock(c, x+143,y+ 14,z+ 93);
	locateBlock(c, x+144,y+ 14,z+ 93);
	locateBlock(c, x+145,y+ 14,z+ 93);
	locateBlock(c, x+146,y+ 14,z+ 93);
	locateBlock(c, x+147,y+ 14,z+ 93);
	locateBlock(c, x+148,y+ 14,z+ 93);
	locateBlock(c, x+149,y+ 14,z+ 93);
	locateBlock(c, x+150,y+ 14,z+ 93);

	locateBlock(c, x+99, y+15, z+93);
	locateBlock(c, x+101,y+ 15,z+ 93);
	locateBlock(c, x+102,y+ 15,z+ 93);
	locateBlock(c, x+103,y+ 15,z+ 93);
	locateBlock(c, x+104,y+ 15,z+ 93);
	locateBlock(c, x+105,y+ 15,z+ 93);
	locateBlock(c, x+106,y+ 15,z+ 93);
	locateBlock(c, x+107,y+ 15,z+ 93);
	locateBlock(c, x+108,y+ 15,z+ 93);
	locateBlock(c, x+109,y+ 15,z+ 93);
	locateBlock(c, x+110,y+ 15,z+ 93);
	locateBlock(c, x+111,y+ 15,z+ 93);
	locateBlock(c, x+112,y+ 15,z+ 93);
	locateBlock(c, x+113,y+ 15,z+ 93);
	locateBlock(c, x+114,y+ 15,z+ 93);
	locateBlock(c, x+115,y+ 15,z+ 93);
	locateBlock(c, x+116,y+ 15,z+ 93);
	locateBlock(c, x+117,y+ 15,z+ 93);
	locateBlock(c, x+118,y+ 15,z+ 93);
	locateBlock(c, x+119,y+ 15,z+ 93);
	locateBlock(c, x+120,y+ 15,z+ 93);
	locateBlock(c, x+121,y+ 15,z+ 93);
	locateBlock(c, x+122,y+ 15,z+ 93);
	locateBlock(c, x+123,y+ 15,z+ 93);
	locateBlock(c, x+124,y+ 15,z+ 93);
	locateBlock(c, x+125,y+ 15,z+ 93);
	locateBlock(c, x+126,y+ 15,z+ 93);
	locateBlock(c, x+127,y+ 15,z+ 93);
	locateBlock(c, x+128,y+ 15,z+ 93);
	locateBlock(c, x+129,y+ 15,z+ 93);
	locateBlock(c, x+130,y+ 15,z+ 93);
	locateBlock(c, x+131,y+ 15,z+ 93);
	locateBlock(c, x+132,y+ 15,z+ 93);
	locateBlock(c, x+133,y+ 15,z+ 93);
	locateBlock(c, x+134,y+ 15,z+ 93);
	locateBlock(c, x+135,y+ 15,z+ 93);
	locateBlock(c, x+136,y+ 15,z+ 93);
	locateBlock(c, x+137,y+ 15,z+ 93);
	locateBlock(c, x+138,y+ 15,z+ 93);
	locateBlock(c, x+139,y+ 15,z+ 93);
	locateBlock(c, x+140,y+ 15,z+ 93);
	locateBlock(c, x+141,y+ 15,z+ 93);
	locateBlock(c, x+142,y+ 15,z+ 93);
	locateBlock(c, x+143,y+ 15,z+ 93);
	locateBlock(c, x+144,y+ 15,z+ 93);
	locateBlock(c, x+145,y+ 15,z+ 93);
	locateBlock(c, x+146,y+ 15,z+ 93);
	locateBlock(c, x+147,y+ 15,z+ 93);
	locateBlock(c, x+148,y+ 15,z+ 93);
	locateBlock(c, x+149,y+ 15,z+ 93);
	locateBlock(c, x+150,y+ 15,z+ 93);

	locateBlock(c, x+99, y+16, z+93);
	locateBlock(c, x+101, y+16,z+ 93);
	locateBlock(c, x+102, y+16,z+ 93);
	locateBlock(c, x+103, y+16,z+ 93);
	locateBlock(c, x+104, y+16,z+ 93);
	locateBlock(c, x+105, y+16,z+ 93);
	locateBlock(c, x+106, y+16,z+ 93);
	locateBlock(c, x+107, y+16,z+ 93);
	locateBlock(c, x+108, y+16,z+ 93);
	locateBlock(c, x+109, y+16,z+ 93);
	locateBlock(c, x+110, y+16,z+ 93);
	locateBlock(c, x+111, y+16,z+ 93);
	locateBlock(c, x+112, y+16,z+ 93);
	locateBlock(c, x+113, y+16,z+ 93);
	locateBlock(c, x+114, y+16,z+ 93);
	locateBlock(c, x+115, y+16,z+ 93);
	locateBlock(c, x+116, y+16,z+ 93);
	locateBlock(c, x+117, y+16,z+ 93);
	locateBlock(c, x+118, y+16,z+ 93);
	locateBlock(c, x+119, y+16,z+ 93);
	locateBlock(c, x+120, y+16,z+ 93);
	locateBlock(c, x+121, y+16,z+ 93);
	locateBlock(c, x+122, y+16,z+ 93);
	locateBlock(c, x+123, y+16,z+ 93);
	locateBlock(c, x+124, y+16,z+ 93);
	locateBlock(c, x+125, y+16,z+ 93);
	locateBlock(c, x+126, y+16,z+ 93);
	locateBlock(c, x+127, y+16,z+ 93);
	locateBlock(c, x+128, y+16,z+ 93);
	locateBlock(c, x+129, y+16,z+ 93);
	locateBlock(c, x+130, y+16,z+ 93);
	locateBlock(c, x+131, y+16,z+ 93);
	locateBlock(c, x+132, y+16,z+ 93);
	locateBlock(c, x+133, y+16,z+ 93);
	locateBlock(c, x+134, y+16,z+ 93);
	locateBlock(c, x+135, y+16,z+ 93);
	locateBlock(c, x+136, y+16,z+ 93);
	locateBlock(c, x+137, y+16,z+ 93);
	locateBlock(c, x+138, y+16,z+ 93);
	locateBlock(c, x+139, y+16,z+ 93);
	locateBlock(c, x+140, y+16,z+ 93);
	locateBlock(c, x+141, y+16,z+ 93);
	locateBlock(c, x+142, y+16,z+ 93);
	locateBlock(c, x+143, y+16,z+ 93);
	locateBlock(c, x+144, y+16,z+ 93);
	locateBlock(c, x+145, y+16,z+ 93);
	locateBlock(c, x+146, y+16,z+ 93);
	locateBlock(c, x+147, y+16,z+ 93);
	locateBlock(c, x+148, y+16,z+ 93);
	locateBlock(c, x+149, y+16,z+ 93);
	locateBlock(c, x+150, y+16,z+ 93);

	locateBlock(c, x+99, y+17, z+93);
	locateBlock(c, x+101, y+17,z+ 93);
	locateBlock(c, x+102, y+17,z+ 93);
	locateBlock(c, x+103, y+17,z+ 93);
	locateBlock(c, x+104, y+17,z+ 93);
	locateBlock(c, x+105, y+17,z+ 93);
	locateBlock(c, x+106, y+17,z+ 93);
	locateBlock(c, x+107, y+17,z+ 93);
	locateBlock(c, x+108, y+17,z+ 93);
	locateBlock(c, x+109, y+17,z+ 93);
	locateBlock(c, x+110, y+17,z+ 93);
	locateBlock(c, x+111, y+17,z+ 93);
	locateBlock(c, x+112, y+17,z+ 93);
	locateBlock(c, x+113, y+17,z+ 93);
	locateBlock(c, x+114, y+17,z+ 93);
	locateBlock(c, x+115, y+17,z+ 93);
	locateBlock(c, x+116, y+17,z+ 93);
	locateBlock(c, x+117, y+17,z+ 93);
	locateBlock(c, x+118, y+17,z+ 93);
	locateBlock(c, x+119, y+17,z+ 93);
	locateBlock(c, x+120, y+17,z+ 93);
	locateBlock(c, x+121, y+17,z+ 93);
	locateBlock(c, x+122, y+17,z+ 93);
	locateBlock(c, x+123, y+17,z+ 93);
	locateBlock(c, x+124, y+17,z+ 93);
	locateBlock(c, x+125, y+17,z+ 93);
	locateBlock(c, x+126, y+17,z+ 93);
	locateBlock(c, x+127, y+17,z+ 93);
	locateBlock(c, x+128, y+17,z+ 93);
	locateBlock(c, x+129, y+17,z+ 93);
	locateBlock(c, x+130, y+17,z+ 93);
	locateBlock(c, x+131, y+17,z+ 93);
	locateBlock(c, x+132, y+17,z+ 93);
	locateBlock(c, x+133, y+17,z+ 93);
	locateBlock(c, x+134, y+17,z+ 93);
	locateBlock(c, x+135, y+17,z+ 93);
	locateBlock(c, x+136, y+17,z+ 93);
	locateBlock(c, x+137, y+17,z+ 93);
	locateBlock(c, x+138, y+17,z+ 93);
	locateBlock(c, x+139, y+17,z+ 93);
	locateBlock(c, x+140, y+17,z+ 93);
	locateBlock(c, x+141, y+17,z+ 93);
	locateBlock(c, x+142, y+17,z+ 93);
	locateBlock(c, x+143, y+17,z+ 93);
	locateBlock(c, x+144, y+17,z+ 93);
	locateBlock(c, x+145, y+17,z+ 93);
	locateBlock(c, x+146, y+17,z+ 93);
	locateBlock(c, x+147, y+17,z+ 93);
	locateBlock(c, x+148, y+17,z+ 93);
	locateBlock(c, x+149, y+17,z+ 93);
	locateBlock(c, x+150, y+17,z+ 93);

	locateBlock(c, x+99, y+18, z+93);
	locateBlock(c, x+101, y+18,z+ 93);
	locateBlock(c, x+102, y+18,z+ 93);
	locateBlock(c, x+103, y+18,z+ 93);
	locateBlock(c, x+104, y+18,z+ 93);
	locateBlock(c, x+105, y+18,z+ 93);
	locateBlock(c, x+106, y+18,z+ 93);
	locateBlock(c, x+107, y+18,z+ 93);
	locateBlock(c, x+108, y+18,z+ 93);
	locateBlock(c, x+109, y+18,z+ 93);
	locateBlock(c, x+110, y+18,z+ 93);
	locateBlock(c, x+111, y+18,z+ 93);
	locateBlock(c, x+112, y+18,z+ 93);
	locateBlock(c, x+113, y+18,z+ 93);
	locateBlock(c, x+114, y+18,z+ 93);
	locateBlock(c, x+115, y+18,z+ 93);
	locateBlock(c, x+116, y+18,z+ 93);
	locateBlock(c, x+117, y+18,z+ 93);
	locateBlock(c, x+118, y+18,z+ 93);
	locateBlock(c, x+119, y+18,z+ 93);
	locateBlock(c, x+120, y+18,z+ 93);
	locateBlock(c, x+121, y+18,z+ 93);
	locateBlock(c, x+122, y+18,z+ 93);
	locateBlock(c, x+123, y+18,z+ 93);
	locateBlock(c, x+124, y+18,z+ 93);
	locateBlock(c, x+125, y+18,z+ 93);
	locateBlock(c, x+126, y+18,z+ 93);
	locateBlock(c, x+127, y+18,z+ 93);
	locateBlock(c, x+128, y+18,z+ 93);
	locateBlock(c, x+129, y+18,z+ 93);
	locateBlock(c, x+130, y+18,z+ 93);
	locateBlock(c, x+131, y+18,z+ 93);
	locateBlock(c, x+132, y+18,z+ 93);
	locateBlock(c, x+133, y+18,z+ 93);
	locateBlock(c, x+134, y+18,z+ 93);
	locateBlock(c, x+135, y+18,z+ 93);
	locateBlock(c, x+136, y+18,z+ 93);
	locateBlock(c, x+137, y+18,z+ 93);
	locateBlock(c, x+138, y+18,z+ 93);
	locateBlock(c, x+139, y+18,z+ 93);
	locateBlock(c, x+140, y+18,z+ 93);
	locateBlock(c, x+141, y+18,z+ 93);
	locateBlock(c, x+142, y+18,z+ 93);
	locateBlock(c, x+143, y+18,z+ 93);
	locateBlock(c, x+144, y+18,z+ 93);
	locateBlock(c, x+145, y+18,z+ 93);
	locateBlock(c, x+146, y+18,z+ 93);
	locateBlock(c, x+147, y+18,z+ 93);
	locateBlock(c, x+148, y+18,z+ 93);
	locateBlock(c, x+149, y+18,z+ 93);
	locateBlock(c, x+150, y+18,z+ 93);

	//후면 중 x100 x+z93부y+분+z+ 공백임을 알게됨
	locateBlock(c, x+100, y+4, z+93);
	locateBlock(c, x+100, y+5, z+93);
	locateBlock(c, x+100, y+6, z+93);
	locateBlock(c, x+100, y+7, z+93);
	locateBlock(c, x+100, y+8, z+93);
	locateBlock(c, x+100, y+9, z+93);
	locateBlock(c, x+100, y+10,z+ 93);
	locateBlock(c, x+100, y+11,z+ 93);
	locateBlock(c, x+100, y+12,z+ 93);
	locateBlock(c, x+100, y+13,z+ 93);
	locateBlock(c, x+100, y+14,z+ 93);
	locateBlock(c, x+100, y+15,z+ 93);
	locateBlock(c, x+100, y+16,z+ 93);
	locateBlock(c, x+100, y+17,z+ 93);
	locateBlock(c, x+100, y+18,z+ 93);

	//마무리 안된 뒷+x부분y+   z+
	locateBlock(c, x+123, y+19,z+ 93);
	locateBlock(c, x+123, y+20,z+ 93);
	locateBlock(c, x+123, y+21,z+ 93);
	locateBlock(c, x+123, y+22,z+ 93);

	locateBlock(c, x+124, y+19,z+ 93);
	locateBlock(c, x+124, y+20,z+ 93);
	locateBlock(c, x+124, y+21,z+ 93);
	locateBlock(c, x+124, y+22,z+ 93);
	locateBlock(c, x+124, y+23,z+ 93);

	locateBlock(c, x+125, y+19,z+ 93);
	locateBlock(c, x+125, y+20,z+ 93);
	locateBlock(c, x+125, y+21,z+ 93);
	locateBlock(c, x+125, y+22,z+ 93);
	locateBlock(c, x+125, y+23,z+ 93);

	locateBlock(c, x+126, y+19,z+ 93);
	locateBlock(c, x+126, y+20,z+ 93);
	locateBlock(c, x+126, y+21,z+ 93);
	locateBlock(c, x+126, y+22,z+ 93);
}

void makepond(int ex, int ey, int ez) {
	BlockID empty = createBlock(BLOCK_AIR);
	BlockID grs = createBlock(BLOCK_GRASS);
	WaterID water = createWater(true); //물. 흐름.
	SlabID darkoaksb = createSlab(SLAB_DARK_OAK, SLAB_LOWER);
	StairsID bench = createStairs(STAIRS_OAK, false); //참나무 계단
	FlowerID wtulip = createFlower(FLOWER_WHITE_TULIP); //흰 튤립.
	BlockID cobble = createBlock(BLOCK_COBBLESTONE);  //발광석, 돌, 공기(empty), 석영, 유리, 잔디, 조약돌
	BlockID gls = createBlock(BLOCK_GLOWSTONE);
	BricksID brickstone = createBricks(BRICKS_STONE); //돌 벽돌
	SlabID sbrickstone = createSlab(SLAB_STONE_BRICK, SLAB_LOWER);
	SlabID slabcobbleup = createSlab(SLAB_COBBLESTONE, SLAB_UPPER);
	SlabID slabcobbledown = createSlab(SLAB_COBBLESTONE, SLAB_LOWER); // spruce 윗반블럭. 석영 반블럭 위아래로 하나씩. 짙은 참나무 반블럭. 돌 벽돌 반블럭 아래쪽. 조약돌 반블럭 위아래로 하나씩.
	TerracottaID cyant = createTerracotta(TERRACOTTA, COLOR_CYAN); //cyan 테라코타



	for (int i = 0; i <= 3; i++) //땅파기
	{
		crtrect(empty, ex, ey - i, ez, ex + 52, ez + 54);
	}

	crtrect(grs, ex, ey - 4, ez, ex + 52, ez + 54); //녹지화

	crtrect(water, ex + 15, ey - 4, ez + 24, ex + 37, ez + 35); //물 1차->직사각형

	for (int i = 0; i <= 5; i++) //물 2차->팔각형화
	{
		crtrect(water, ex + 21 - i, ey - 4, ez + 18 + i, ex + 31 + i, ez + 18 + i);
		crtrect(water, ex + 21 - i, ey - 4, ez + 41 - i, ex + 31 + i, ez + 41 - i);
	}

	crtrect(darkoaksb, ex + 38, ey - 3, ez + 24, ex + 41, ez + 35);
	crtrect(darkoaksb, ex + 40, ey - 3, ez + 20, ex + 41, ez + 39); //어두운 나무판

	crtrect(cobble, ex + 13, ey - 4, ez + 15, ex + 43, ez + 15);
	crtrect(cobble, ex + 13, ey - 4, ez + 15, ex + 13, ez + 44);
	crtrect(cobble, ex + 43, ey - 4, ez + 15, ex + 43, ez + 44);
	crtrect(cobble, ex + 13, ey - 4, ez + 44, ex + 43, ez + 44);  //조약돌길

	crtrect(cobble, ex + 44, ey - 4, ez + 24, ex + 45, ez + 35); //조약돌길 옆에 조약돌 그거

	installStairs(bench, ex + 24, ey - 3, ez + 13, FACING_NORTH);
	installStairs(bench, ex + 25, ey - 3, ez + 13, FACING_NORTH);
	installStairs(bench, ex + 26, ey - 3, ez + 13, FACING_NORTH); //북쪽벤치

	installStairs(bench, ex + 45, ey - 3, ez + 15, FACING_EAST);
	installStairs(bench, ex + 45, ey - 3, ez + 16, FACING_EAST);
	installStairs(bench, ex + 45, ey - 3, ez + 17, FACING_EAST); //동쪽벤치, 위쪽


	installStairs(bench, ex + 45, ey - 3, ez + 39, FACING_EAST);
	installStairs(bench, ex + 45, ey - 3, ez + 40, FACING_EAST);
	installStairs(bench, ex + 45, ey - 3, ez + 41, FACING_EAST); //동쪽벤치, 아래쪽

	installStairs(bench, ex + 12, ey - 3, ez + 23, FACING_WEST);
	installStairs(bench, ex + 12, ey - 3, ez + 24, FACING_WEST);
	installStairs(bench, ex + 12, ey - 3, ez + 25, FACING_WEST); //서쪽벤치, 위쪽

	installStairs(bench, ex + 12, ey - 3, ez + 31, FACING_WEST);
	installStairs(bench, ex + 12, ey - 3, ez + 32, FACING_WEST);
	installStairs(bench, ex + 12, ey - 3, ez + 33, FACING_WEST); //서쪽벤치, 아래쪽

	installStairs(bench, ex + 30, ey - 3, ez + 46, FACING_SOUTH);
	installStairs(bench, ex + 31, ey - 3, ez + 46, FACING_SOUTH);
	installStairs(bench, ex + 32, ey - 3, ez + 46, FACING_SOUTH);//남쪽벤치

	locateFlower(wtulip, ex + 20, ey - 3, ez + 16);
	locateFlower(wtulip, ex + 21, ey - 3, ez + 16);
	locateFlower(wtulip, ex + 22, ey - 3, ez + 16);
	locateFlower(wtulip, ex + 29, ey - 3, ez + 16);
	locateFlower(wtulip, ex + 31, ey - 3, ez + 16);
	locateFlower(wtulip, ex + 19, ey - 3, ez + 17);
	locateFlower(wtulip, ex + 26, ey - 3, ez + 17);
	locateFlower(wtulip, ex + 30, ey - 3, ez + 17);
	locateFlower(wtulip, ex + 33, ey - 3, ez + 17);
	locateFlower(wtulip, ex + 35, ey - 3, ez + 17);
	locateFlower(wtulip, ex + 16, ey - 3, ez + 19);
	locateFlower(wtulip, ex + 17, ey - 3, ez + 19);
	locateFlower(wtulip, ex + 35, ey - 3, ez + 19);
	locateFlower(wtulip, ex + 16, ey - 3, ez + 20);
	locateFlower(wtulip, ex + 37, ey - 3, ez + 20);
	locateFlower(wtulip, ex + 18, ey - 3, ez + 20);
	locateFlower(wtulip, ex + 14, ey - 3, ez + 22);
	locateFlower(wtulip, ex + 38, ey - 3, ez + 22);
	locateFlower(wtulip, ex + 38, ey - 3, ez + 23);
	locateFlower(wtulip, ex + 38, ey - 3, ez + 23);
	locateFlower(wtulip, ex + 14, ey - 3, ez + 27);
	locateFlower(wtulip, ex + 14, ey - 3, ez + 28);
	locateFlower(wtulip, ex + 14, ey - 3, ez + 29);
	locateFlower(wtulip, ex + 14, ey - 3, ez + 32);
	locateFlower(wtulip, ex + 14, ey - 3, ez + 33);
	locateFlower(wtulip, ex + 14, ey - 3, ez + 35);
	locateFlower(wtulip, ex + 14, ey - 3, ez + 37);
	locateFlower(wtulip, ex + 16, ey - 3, ez + 39);
	locateFlower(wtulip, ex + 16, ey - 3, ez + 40);
	locateFlower(wtulip, ex + 17, ey - 3, ez + 40);
	locateFlower(wtulip, ex + 17, ey - 3, ez + 42);
	locateFlower(wtulip, ex + 19, ey - 3, ez + 42);
	locateFlower(wtulip, ex + 28, ey - 3, ez + 42);
	locateFlower(wtulip, ex + 36, ey - 3, ez + 42);
	locateFlower(wtulip, ex + 26, ey - 3, ez + 43);
	locateFlower(wtulip, ex + 29, ey - 3, ez + 43);
	locateFlower(wtulip, ex + 30, ey - 3, ez + 43);
	locateFlower(wtulip, ex + 32, ey - 3, ez + 43);
	locateFlower(wtulip, ex + 38, ey - 3, ez + 37);
	locateFlower(wtulip, ex + 37, ey - 3, ez + 38);
	locateFlower(wtulip, ex + 38, ey - 3, ez + 38);
	locateFlower(wtulip, ex + 35, ey - 3, ez + 39);
	locateFlower(wtulip, ex + 34, ey - 3, ez + 40); //꽃 배치

	crtrect(brickstone, ex + 47, ey - 3, ez + 26, ex + 52, ez + 26);
	crtrect(brickstone, ex + 49, ey - 2, ez + 26, ex + 52, ez + 26);
	crtrect(brickstone, ex + 51, ey - 1, ez + 26, ex + 52, ez + 26);

	locateSlab(sbrickstone, ex + 48, ey - 2, ez + 26);
	locateSlab(sbrickstone, ex + 50, ey - 1, ez + 26);
	locateSlab(sbrickstone, ex + 52, ey - 0, ez + 26);
	locateBlock(brickstone, ex + 53, ey, ez + 26);


	crtrect(brickstone, ex + 47, ey - 3, ez + 33, ex + 52, ez + 33);
	crtrect(brickstone, ex + 49, ey - 2, ez + 33, ex + 52, ez + 33);
	crtrect(brickstone, ex + 51, ey - 1, ez + 33, ex + 52, ez + 33);

	locateSlab(sbrickstone, ex + 48, ey - 2, ez + 33);
	locateSlab(sbrickstone, ex + 50, ey - 1, ez + 33);
	locateSlab(sbrickstone, ex + 52, ey - 0, ez + 33);
	locateBlock(brickstone, ex + 53, ey, ez + 33);


	crtrect(cobble, ex + 48, ey - 3, ez + 27, ex + 49, ez + 32);
	crtrect(cobble, ex + 50, ey - 2, ez + 27, ex + 51, ez + 32);
	crtrect(cobble, ex + 52, ey - 1, ez + 27, ex + 53, ez + 32);
	crtrect(empty, ex + 52, ey, ez + 27, ex + 53, ez + 32);


	locateSlab(slabcobbledown, ex + 47, ey - 3, ez + 27);
	locateSlab(slabcobbledown, ex + 47, ey - 3, ez + 28);
	locateSlab(slabcobbledown, ex + 47, ey - 3, ez + 29);
	locateSlab(slabcobbledown, ex + 47, ey - 3, ez + 30);
	locateSlab(slabcobbledown, ex + 47, ey - 3, ez + 31);
	locateSlab(slabcobbledown, ex + 47, ey - 3, ez + 32);

	locateSlab(slabcobbledown, ex + 49, ey - 2, ez + 27);
	locateSlab(slabcobbledown, ex + 49, ey - 2, ez + 28);
	locateSlab(slabcobbledown, ex + 49, ey - 2, ez + 29);
	locateSlab(slabcobbledown, ex + 49, ey - 2, ez + 30);
	locateSlab(slabcobbledown, ex + 49, ey - 2, ez + 31);
	locateSlab(slabcobbledown, ex + 49, ey - 2, ez + 32);

	locateSlab(slabcobbledown, ex + 51, ey - 1, ez + 27);
	locateSlab(slabcobbledown, ex + 51, ey - 1, ez + 28);
	locateSlab(slabcobbledown, ex + 51, ey - 1, ez + 29);
	locateSlab(slabcobbledown, ex + 51, ey - 1, ez + 30);
	locateSlab(slabcobbledown, ex + 51, ey - 1, ez + 31);
	locateSlab(slabcobbledown, ex + 51, ey - 1, ez + 32);

	locateSlab(slabcobbledown, ex + 53, ey - 0, ez + 27);
	locateSlab(slabcobbledown, ex + 53, ey - 0, ez + 28);
	locateSlab(slabcobbledown, ex + 53, ey - 0, ez + 29);
	locateSlab(slabcobbledown, ex + 53, ey - 0, ez + 30);
	locateSlab(slabcobbledown, ex + 53, ey - 0, ez + 31);
	locateSlab(slabcobbledown, ex + 53, ey - 0, ez + 32); //계단

	crtstree(ex + 5, ey - 3, ez + 5);
	crtstree(ex + 10, ey - 3, ez + 4);
	crtstree(ex + 12, ey - 3, ez + 7);
	crtstree(ex + 15, ey - 3, ez + 10);
	crtstree(ex + 20, ey - 3, ez + 8);
	crtstree(ex + 22, ey - 3, ez + 7);
	crtstree(ex + 25, ey - 3, ez + 9);
	crtstree(ex + 30, ey - 3, ez + 10);
	crtstree(ex + 32, ey - 3, ez + 3);
	crtstree(ex + 34, ey - 3, ez + 4);
	crtstree(ex + 38, ey - 3, ez + 5);
	crtstree(ex + 40, ey - 3, ez + 4);
	crtstree(ex + 45, ey - 3, ez + 7);
	crtstree(ex + 48, ey - 3, ez + 10);
	crtstree(ex + 43, ey - 3, ez + 9); //북쪽 숲



	crtstree(ex + 3, ey - 3, ez + 8);
	crtstree(ex + 4, ey - 3, ez + 11);
	crtstree(ex + 5, ey - 3, ez + 15);
	crtstree(ex + 8, ey - 3, ez + 20);
	crtstree(ex + 5, ey - 3, ez + 17);
	crtstree(ex + 3, ey - 3, ez + 25);
	crtstree(ex + 4, ey - 3, ez + 28);
	crtstree(ex + 8, ey - 3, ez + 30);
	crtstree(ex + 7, ey - 3, ez + 34);
	crtstree(ex + 5, ey - 3, ez + 36);
	crtstree(ex + 8, ey - 3, ez + 40);
	crtstree(ex + 4, ey - 3, ez + 43);
	crtstree(ex + 6, ey - 3, ez + 47); //서쪽 숲


	crtstree(ex + 4, ey - 3, ez + 46);
	crtstree(ex + 9, ey - 3, ez + 48);
	crtstree(ex + 14, ey - 3, ez + 50);
	crtstree(ex + 18, ey - 3, ez + 49);
	crtstree(ex + 21, ey - 3, ez + 47);
	crtstree(ex + 24, ey - 3, ez + 50);
	crtstree(ex + 28, ey - 3, ez + 48);
	crtstree(ex + 30, ey - 3, ez + 50);
	crtstree(ex + 33, ey - 3, ez + 47);
	crtstree(ex + 37, ey - 3, ez + 51);
	crtstree(ex + 40, ey - 3, ez + 49);
	crtstree(ex + 43, ey - 3, ez + 50);
	crtstree(ex + 45, ey - 3, ez + 47);
	crtstree(ex + 48, ey - 3, ez + 50);
	crtstree(ex + 49, ey - 3, ez + 48); //남쪽 숲


	crtstree(ex + 49, ey - 3, ez + 15);
	crtstree(ex + 47, ey - 3, ez + 23);
	crtstree(ex + 48, ey - 3, ez + 40); //동쪽 숲


	crtrect(cyant, ex + 24, ey - 3, ez + 28, ex + 28, ez + 32);
	locateBlock(empty, ex + 24, ey - 3, ez + 28);
	locateBlock(empty, ex + 28, ey - 3, ez + 28);
	locateBlock(empty, ex + 24, ey - 3, ez + 32);
	locateBlock(empty, ex + 28, ey - 3, ez + 32); // 조형물 1층

	crtrect(cyant, ex + 23, ey - 2, ez + 27, ex + 29, ez + 33); //2층 조형물 기본틀

	locateBlock(empty, ex + 23, ey - 2, ez + 27);
	locateBlock(empty, ex + 24, ey - 2, ez + 27);
	locateBlock(empty, ex + 23, ey - 2, ez + 28);    // 좌측 상단 빈부분

	locateBlock(empty, ex + 28, ey - 2, ez + 27);
	locateBlock(empty, ex + 29, ey - 2, ez + 27);
	locateBlock(empty, ex + 29, ey - 2, ez + 28); //우측 상단 빈부분

	locateBlock(empty, ex + 28, ey - 2, ez + 33);
	locateBlock(empty, ex + 29, ey - 2, ez + 32);
	locateBlock(empty, ex + 29, ey - 2, ez + 33); //우측 하단 빈부분

	locateBlock(empty, ex + 23, ey - 2, ez + 33);
	locateBlock(empty, ex + 23, ey - 2, ez + 32);
	locateBlock(empty, ex + 24, ey - 2, ez + 33); //좌측 하단 빈부분. 2층 끝

	crtrect(cyant, ex + 24, ey - 1, ez + 28, ex + 28, ez + 32); //3층은 1층과 구조적으로 동일하나 발광석이 끼어 있음.
	locateBlock(gls, ex + 26, ey - 1, ez + 28);
	locateBlock(gls, ex + 24, ey - 1, ez + 30);
	locateBlock(gls, ex + 28, ey - 1, ez + 30);
	locateBlock(gls, ex + 26, ey - 1, ez + 32); //발광석 배치
	locateBlock(empty, ex + 24, ey - 1, ez + 28);
	locateBlock(empty, ex + 28, ey - 1, ez + 28);
	locateBlock(empty, ex + 24, ey - 1, ez + 32);
	locateBlock(empty, ex + 28, ey - 1, ez + 32); //빈 부분 만들기. 3층 끝

	crtrect(cyant, ex + 25, ey, ez + 29, ex + 27, ez + 31); // 꼭대기 마무리. 조형물 끝


	crtslight(ex + 38, ey - 3, ez + 13);
	crtslight(ex + 19, ey - 3, ez + 13); //북쪽 등

	crtslight(ex + 11, ey - 3, ez + 17);
	crtslight(ex + 11, ey - 3, ez + 34); //서쪽 등

	crtslight(ex + 45, ey - 3, ez + 19);
	crtslight(ex + 45, ey - 3, ez + 37); //동쪽 등

	crtslight(ex + 11, ey - 3, ez + 46);
	crtslight(ex + 24, ey - 3, ez + 46);
	crtslight(ex + 42, ey - 3, ez + 46); //남쪽 등

}
void crtrect(BlockID block, int ex, int ey, int ez, int sx, int sz) //높이 1 직사각형 생성 함수, 매개변수는 좌표 2개
{
	if (ex > sx)
		SWAP(ex, sx);
	if (ez > sz)
		SWAP(ez, sz);

	for (int i2 = 0; ez + i2 <= sz; i2++)
	{
		for (int i = 0; ex + i <= sx; i++)
		{
			locateBlock(block, ex + i, ey, ez + i2);
		}
	}
}
void crtstree(int ex, int ey, int ez) //나무 만드는 함수. 나무 밑동이 기준점임
{
	WoodID wd = createWood(WOOD_OAK, STRIP_UP_DOWN);
	PlantID leaf = createPlant(PLANT_OAK_LEAVES);
	BlockID empty = createBlock(BLOCK_AIR);

	crtrect(leaf, ex - 2, ey + 2, ez - 2, ex + 2, ez + 2);
	crtrect(leaf, ex - 2, ey + 3, ez - 2, ex + 2, ez + 2);
	locateBlock(empty, ex - 2, ey + 3, ez - 2);
	crtrect(leaf, ex - 1, ey + 4, ez - 1, ex + 1, ez + 1);
	locateBlock(leaf, ex - 1, ey + 5, ez);
	locateBlock(leaf, ex, ey + 5, ez);
	locateBlock(leaf, ex + 1, ey + 5, ez);
	locateBlock(leaf, ex, ey + 5, ez - 1);
	locateBlock(leaf, ex, ey + 5, ez + 1);
	stackblock(wd, ex, ey, ez, 5);

}
void crtslight(int ex, int ey, int ez) //등불. 울타리 + 발광석
{
	BlockID gls = createBlock(BLOCK_GLOWSTONE);
	FenceID ofc = createFence(FENCE_OAK);

	locateBlock(ofc, ex, ey, ez);
	locateBlock(gls, ex, ey + 1, ez);
}

void stackblock(BlockID block, int ex, int ey, int ez, int height) //수직으로 블록 쌓는 함수, 매개변수는 좌표1개랑 높이(int)
{
	for (int i = 0; i <= height - 1; i++)
	{
		locateBlock(block, ex, ey + i, ez);
	}
}

void make_kim_riceandpotato(int sx, int sy, int sz) {
	BlockID stone = createBlock(BLOCK_STONE);
	WoolID orange = createWool(COLOR_ORANGE);
	WoolID red = createWool(COLOR_RED);
	WoolID yellow = createWool(COLOR_YELLOW);
	WoolID white = createWool(COLOR_WHITE);

	for (int i = sx; i <= sx + 34; i++) {
		for (int j = sz; j <= sz + 34; j++) {
			for (int k = 4; k <= 13; k++) {
				locateBlock(stone, i, k, j);
			}
		}
	}
	for (int i = sx; i <= sx + 34; i++) {
		for (int j = sz; j <= sz + 34; j++) {
			locateBlock(stone, i, sy + 10, j);
			locateBlock(red, i, sy + 11, j);
			locateBlock(yellow, i, sy + 12, j);
			locateBlock(yellow, i, sy + 13, j);
			locateBlock(yellow, i, sy + 14, j);
			locateBlock(yellow, i, sy + 15, j);
			locateBlock(yellow, i, sy + 16, j);
			locateBlock(yellow, i, sy + 17, j);
		}
	}

	locateBlock(white, sx, sy + 14, sz);
	locateBlock(white, sx, sy + 14, sz + 1);
	locateBlock(white, sx, sy + 14, sz + 3);
	locateBlock(white, sx, sy + 14, sz + 9);
	locateBlock(white, sx, sy + 14, sz + 13);
	locateBlock(white, sx, sy + 14, sz + 18);
	locateBlock(white, sx, sy + 13, sz);
	locateBlock(white, sx, sy + 13, sz + 6);
	locateBlock(white, sx, sy + 13, sz + 8);
	locateBlock(white, sx, sy + 13, sz + 10);
	locateBlock(white, sx, sy + 13, sz + 12);
	locateBlock(white, sx, sy + 13, sz + 14);
	locateBlock(white, sx, sy + 13, sz + 17);
	locateBlock(white, sx, sy + 13, sz + 19);
	locateBlock(white, sx, sy + 13, sz + 24);
	locateBlock(white, sx, sy + 13, sz + 30);
	locateBlock(white, sx, sy + 12, sz);
	locateBlock(white, sx, sy + 12, sz + 3);
	locateBlock(white, sx, sy + 12, sz + 5);
	locateBlock(white, sx, sy + 12, sz + 8);
	locateBlock(white, sx, sy + 12, sz + 9);
	locateBlock(white, sx, sy + 12, sz + 13);
	locateBlock(white, sx, sy + 12, sz + 17);
	locateBlock(white, sx, sy + 12, sz + 18);
	locateBlock(white, sx, sy + 12, sz + 21);
	locateBlock(white, sx, sy + 12, sz + 23);
	locateBlock(white, sx, sy + 12, sz + 24);
	locateBlock(white, sx, sy + 12, sz + 25);
	locateBlock(white, sx, sy + 12, sz + 27);
	locateBlock(white, sx, sy + 12, sz + 29);
	locateBlock(white, sx, sy + 12, sz + 30);
	locateBlock(white, sx, sy + 12, sz + 31);
	locateBlock(white, sx, sy + 12, sz + 33);
	locateBlock(white, sx, sy + 11, sz + 3);
	locateBlock(white, sx, sy + 11, sz + 6);
	locateBlock(white, sx, sy + 11, sz + 8);
	locateBlock(white, sx, sy + 11, sz + 12);
	locateBlock(white, sx, sy + 11, sz + 14);
	locateBlock(white, sx, sy + 11, sz + 15);
	locateBlock(white, sx, sy + 11, sz + 17);
	locateBlock(white, sx, sy + 11, sz + 20);
	locateBlock(white, sx, sy + 11, sz + 22);
	locateBlock(white, sx, sy + 11, sz + 24);
	locateBlock(white, sx, sy + 11, sz + 26);
	locateBlock(white, sx, sy + 11, sz + 28);
	locateBlock(white, sx, sy + 11, sz + 30);
	locateBlock(white, sx, sy + 11, sz + 32);
	locateBlock(white, sx, sy + 11, sz + 34);
	locateBlock(white, sx, sy + 10, sz + 9);
	locateBlock(white, sx, sy + 10, sz + 10);
	locateBlock(white, sx, sy + 10, sz + 13);
	locateBlock(white, sx, sy + 10, sz + 14);
	locateBlock(white, sx, sy + 10, sz + 17);
	locateBlock(white, sx, sy + 10, sz + 21);
	locateBlock(white, sx, sy + 10, sz + 24);
	locateBlock(white, sx, sy + 10, sz + 25);
	locateBlock(white, sx, sy + 10, sz + 27);
	locateBlock(white, sx, sy + 10, sz + 28);
	locateBlock(white, sx, sy + 10, sz + 29);
	locateBlock(white, sx, sy + 10, sz + 30);
	locateBlock(white, sx, sy + 10, sz + 31);
	locateBlock(white, sx, sy + 10, sz + 33);

	locateBlock(white, 34+sx, sy + 14, sz);
	locateBlock(white, 34+sx, sy + 14, sz + 1);
	locateBlock(white, 34+sx, sy + 14, sz + 3);
	locateBlock(white, 34+sx, sy + 14, sz + 9);
	locateBlock(white, 34+sx, sy + 14, sz + 13);
	locateBlock(white, 34+sx, sy + 14, sz + 18);
	locateBlock(white, 34+sx, sy + 13, sz);
	locateBlock(white, 34+sx, sy + 13, sz + 6);
	locateBlock(white, 34+sx, sy + 13, sz + 8);
	locateBlock(white, 34+sx, sy + 13, sz + 10);
	locateBlock(white, 34+sx, sy + 13, sz + 12);
	locateBlock(white, 34+sx, sy + 13, sz + 14);
	locateBlock(white, 34+sx, sy + 13, sz + 17);
	locateBlock(white, 34+sx, sy + 13, sz + 19);
	locateBlock(white, 34+sx, sy + 13, sz + 24);
	locateBlock(white, 34+sx, sy + 13, sz + 30);
	locateBlock(white, 34+sx, sy + 12, sz);
	locateBlock(white, 34+sx, sy + 12, sz + 3);
	locateBlock(white, 34+sx, sy + 12, sz + 5);
	locateBlock(white, 34+sx, sy + 12, sz + 8);
	locateBlock(white, 34+sx, sy + 12, sz + 9);
	locateBlock(white, 34+sx, sy + 12, sz + 13);
	locateBlock(white, 34+sx, sy + 12, sz + 17);
	locateBlock(white, 34+sx, sy + 12, sz + 18);
	locateBlock(white, 34+sx, sy + 12, sz + 21);
	locateBlock(white, 34+sx, sy + 12, sz + 23);
	locateBlock(white, 34+sx, sy + 12, sz + 24);
	locateBlock(white, 34+sx, sy + 12, sz + 25);
	locateBlock(white, 34+sx, sy + 12, sz + 27);
	locateBlock(white, 34+sx, sy + 12, sz + 29);
	locateBlock(white, 34+sx, sy + 12, sz + 30);
	locateBlock(white, 34+sx, sy + 12, sz + 31);
	locateBlock(white, 34+sx, sy + 12, sz + 33);
	locateBlock(white, 34+sx, sy + 11, sz + 3);
	locateBlock(white, 34+sx, sy + 11, sz + 6);
	locateBlock(white, 34+sx, sy + 11, sz + 8);
	locateBlock(white, 34+sx, sy + 11, sz + 12);
	locateBlock(white, 34+sx, sy + 11, sz + 14);
	locateBlock(white, 34+sx, sy + 11, sz + 15);
	locateBlock(white, 34+sx, sy + 11, sz + 17);
	locateBlock(white, 34+sx, sy + 11, sz + 20);
	locateBlock(white, 34+sx, sy + 11, sz + 22);
	locateBlock(white, 34+sx, sy + 11, sz + 24);
	locateBlock(white, 34+sx, sy + 11, sz + 26);
	locateBlock(white, 34+sx, sy + 11, sz + 28);
	locateBlock(white, 34+sx, sy + 11, sz + 30);
	locateBlock(white, 34+sx, sy + 11, sz + 32);
	locateBlock(white, 34+sx, sy + 11, sz + 34);
	locateBlock(white, 34+sx, sy + 10, sz + 9);
	locateBlock(white, 34+sx, sy + 10, sz + 10);
	locateBlock(white, 34+sx, sy + 10, sz + 13);
	locateBlock(white, 34+sx, sy + 10, sz + 14);
	locateBlock(white, 34+sx, sy + 10, sz + 17);
	locateBlock(white, 34+sx, sy + 10, sz + 21);
	locateBlock(white, 34+sx, sy + 10, sz + 24);
	locateBlock(white, 34+sx, sy + 10, sz + 25);
	locateBlock(white, 34+sx, sy + 10, sz + 27);
	locateBlock(white, 34+sx, sy + 10, sz + 28);
	locateBlock(white, 34+sx, sy + 10, sz + 29);
	locateBlock(white, 34+sx, sy + 10, sz + 30);
	locateBlock(white, 34+sx, sy + 10, sz + 31);
	locateBlock(white, 34+sx, sy + 10, sz + 33);
}
