# team_task_Minecraft
Making Chung-Ang-University at Minecraft with C.


1) 과제의 GitHub 링크를 제출한다. GitHub 링크에는 다음 내용이 포함되어야 한다.

- Visual C++ 프로젝트 및 소스 코드 (빌드 가능)

       소스수정20190607.cpp 문서파일을 확인바랍니다.

- 과제를 설명하는 README.md

      여기서 설명합니다.

. 과제에서 만들고자 한 마인크래프트 월드 소개
      
      중앙대학교를 대표하는 건물입니다. 만든 건물은 다음과 같습니다
      	1.310관
	2.208관
	3.운동장
	4.주차장
	5.화단
	12.101관

	13.청룡연못

	6.등
	7.도로 교차로
	8.x축방향 도로
	9.z축방향 도로
	14.라이스앤포테이토
	
	10.카우버거
	11.편의점
	
위와 같이 우리 대학의 상징물을 마인크래프트에서 구현하였습니다.
	
      
. 이에 사용된 함수에 대한 설명

    사용된 함수가 많아서 가독성이 떨어질 것을 우려하여, 함수들의 반환형태, 이름, 입력값, 주석부분만 가져와서 설명합니다. 그리고 입력형태와 어떤 기능을 하는지 설명하고, 기본함수와 기본함수를 사용하는 함수에 대해서만 간략히 설명합니다. 만약 주석에서의 설명이 부족하다면, cangogi1@naver.com 로 메일을하거나 소스수정20190607.cpp 문서파일을 확인해 주시기 바랍니다.
    void swap(int* array_x1, int* array_x2); //주소값을 받아와 포인터로 그 값을 변경해 줄 때 사용합니다.
    void makefloor(int array_x1, int array_z1, int array_x2, int array_z2); //처음 마을의 크기를 입력받고 그 크기에 맞는 바닥을 만들어주는 함수 입니다.

    void process310(int x, int y, int z, int(*array)[100], double size_darray_x, double size_darray_z, int array_x1, int array_z1); //310관 건물을 만들 때, 제일 먼저 실행됩니다. 이 함수를 통해서, make310을 실행시켜 310관 건물을 마인크래프트상에서 구현하고, arraymark를 실행시켜 cmd에 나타낼때 사용하는 2차원 배열값을 변경합니다.
    void process208(int x, int y, int z, int(*array)[100], double size_darray_x, double size_darray_z, int array_x1, int array_z1); //208관 건물을 만들 때, 제일 먼저 실행됩니다. 이 함수를 통해서, make208을 실행시켜 208관 건물을 마인크래프트상에서 구현하고, arraymark를 실행시켜 cmd에 나타낼때 사용하는 2차원 배열값을 변경합니다.
    void processground(int x, int y, int z, int(*array)[100], double size_darray_x, double size_darray_z, int array_x1, int array_z1); //운동장을 만들 때, 제일 먼저 실행됩니다. 이 함수를 통해서, makeground을 실행시켜 운동장을 마인크래프트상에서 구현하고, arraymark를 실행시켜 cmd에 나타낼때 사용하는 2차원 배열값을 변경합니다.
    void processparkingplace(int x, int y, int z, int(*array)[100], double size_darray_x, double size_darray_z, int array_x1, int array_z1); //주차장을 만들 때, 제일 먼저 실행됩니다. 이 함수를 통해서, makeparkingplace을 실행시켜 208관 건물을 마인크래프트상에서 구현하고, arraymark를 실행시켜 cmd에 나타낼때 사용하는 2차원 배열값을 변경합니다.
    void processflower(int x, int y, int z, int(*array)[100], double size_darray_x, double size_darray_z, int array_x1, int array_z1); //화단을 만들 때, 제일 먼저 실행됩니다. 이 함수를 통해서, makeflower을 실행시켜 화단을 마인크래프트상에서 구현하고, arraymark를 실행시켜 cmd에 나타낼때 사용하는 2차원 배열값을 변경합니다.
    void process_kim_lamp(int x, int y, int z, int(*array)[100], double size_darray_x, double size_darray_z, int array_x1, int array_z1); //등을 만들 때, 제일 먼저 실행됩니다. 이 함수를 통해서, make_kim_lamp을 실행시켜 등을 마인크래프트상에서 구현하고, arraymark를 실행시켜 cmd에 나타낼때 사용하는 2차원 배열값을 변경합니다.
    void process_kim_road_mid(int x, int y, int z, int(*array)[100], double size_darray_x, double size_darray_z, int array_x1, int array_z1); //교차로를 만들 때, 제일 먼저 실행됩니다. 이 함수를 통해서, make_kim_road_mid을 실행시켜 교차로를 마인크래프트상에서 구현하고, arraymark를 실행시켜 cmd에 나타낼때 사용하는 2차원 배열값을 변경합니다.
    void process_kim_road_garo(int x, int y, int z, int(*array)[100], double size_darray_x, double size_darray_z, int array_x1, int  array_z1); //x축 방향의 도로을 만들 때, 제일 먼저 실행됩니다. 이 함수를 통해서, make_kim_road_garo을 실행시켜 x축 방향의 도로를 마인크래프트상에서 구현하고, arraymark를 실행시켜 cmd에 나타낼때 사용하는 2차원 배열값을 변경합니다.
    void process_kim_road_sero(int x, int y, int z, int(*array)[100], double size_darray_x, double size_darray_z, int array_x1, int array_z1); //z축 방향의 도로을 만들 때, 제일 먼저 실행됩니다. 이 함수를 통해서, make_kim_road_sero을 실행시켜 z축 방향의 도로을 마인크래프트상에서 구현하고, arraymark를 실행시켜 cmd에 나타낼때 사용하는 2차원 배열값을 변경합니다.
    void process_hong_cauburger(int x, int y, int z, int(*array)[100], double size_darray_x, double size_darray_z, int array_x1, int array_z1); //카우버거 건물을 만들 때, 제일 먼저 실행됩니다. 이 함수를 통해서, make_hong_cauburger을 실행시켜 카우버거 건물을 마인크래프트상에서 구현하고, arraymark를 실행시켜 cmd에 나타낼때 사용하는 2차원 배열값을 변경합니다.
    void process_hong_seven(int x, int y, int z, int(*array)[100], double size_darray_x, double size_darray_z, int array_x1, int array_z1); //편의점을 만들 때, 제일 먼저 실행됩니다. 이 함수를 통해서, make_hong_seven을 실행시켜 편의점 건물을 마인크래프트상에서 구현하고, arraymark를 실행시켜 cmd에 나타낼때 사용하는 2차원 배열값을 변경합니다.
    void process101(int x, int y, int z, int(*array)[100], double size_darray_x, double size_darray_z, int array_x1, int array_z1); //101관 건물을 만들 때, 제일 먼저 실행됩니다. 이 함수를 통해서, make101을 실행시켜 101관 건물을 마인크래프트상에서 구현하고, arraymark를 실행시켜 cmd에 나타낼때 사용하는 2차원 배열값을 변경합니다.
    void processpond(int x, int y, int z, int(*array)[100], double size_darray_x, double size_darray_z, int array_x1, int array_z1); //청령 연못을 만들 때, 제일 먼저 실행됩니다. 이 함수를 통해서, make_pond을 실행시켜 청룡연못을 마인크래프트상에서 구현하고, arraymark를 실행시켜 cmd에 나타낼때 사용하는 2차원 배열값을 변경합니다.
    void process_kim_riceandpotato(int x, int y, int z, int(*array)[100], double size_darray_x, double size_darray_z, int array_x1, int array_z1); //라이스앤 포테이토 건물을 만들 때, 제일 먼저 실행됩니다. 이 함수를 통해서, make_kim_riceandpotato을 실행시켜 라이스앤 포테이토 건물을 마인크래프트상에서 구현하고, arraymark를 실행시켜 cmd에 나타낼때 사용하는 2차원 배열값을 변경합니다.

    void arrayprintf(int(*array)[100]); //2차원 배열을 출력해주는 함수 입니다.
    void arraymark(int(*array)[100], int a, int b, int c, int d); //2차원 배열에 저장된 값을 수정해주는 함수입니다. (사용예: x,z 시작 좌표가 3,3을 입력한다. 그리고 x좌표의 양의 방향으로 길이와, z좌표의 양의 방향으로 길이를 입력한다.) 예시 arraymark(array, (int)(134 / size_darray_x), (int)(60 / size_darray_z), -(int)(array_z1 / size_darray_z) + (int)(z / size_darray_z), -(int)(array_x1 / size_darray_x) + (int)(x / size_darray_x)); 134는 x의 양의 방향으로의 길이이다. 60는 z의 양의 방향으로의 길이이다. 나머지 쓰여져 있는 수식은 2차원 배열을 array[100][50]으로 선언했기 때문에, x축의 길이를 100에 맞게, z축의 길이를 50에 맞게 맞추는 연산과정이다. size_darray_x는 cmd ui에서 100칸으로 나타는 칸 중 한 칸이 마인크래프트 상에서의 실제 길이를 말한다. 그리고 그것으로 실제 길이 134를 나누면 cmd에서 ui에서 나타내는 칸 길이를 정할 수 있다. + (int)(z / size_darray_z)와 같은 식들은 마을의 시작좌표가 0,0이 아닐 때를 고려하여 쓴 것이으로, 비슷한 과정이다.

    void make310(int x, int y, int z); //process310이 호출하면 실행되는 함수이고, 310관을 만들어준다. (규모가 크기 때문에 다른 기본함수들로 구성되어있다.)
    void make310_body(int x, int y, int z); // make310이 호출하는 기본함수이며, 310관의 몸체를 만들어준다.
    void make310_decorating(int x, int y, int z); // make310이 호출하는 기본함수이며, 310관에 기본적인 장식을 달아준다.
    void make310_window(int x, int y, int z); // make310이 호출하는 기본함수이며, 310관에 유리를 달아준다.
    void make310_eliminating(int x, int y, int z); // make310이 호출하는 기본함수이며, 310관의 모습에 맞게 몸체를 깎는다. 기둥이 지나가는 부분과, 310관이 마름모꼴을 만들어준다.


    void make208(int x, int y, int z); //process208이 호출하면 실행되는 함수이고, 208관을 만들어준다. (규모가 크기 때문에 다른 기본함수들로 구성되어있다.)
    void make208_body(int x, int y, int z); // make208이 호출하는 기본함수이며, 208관의 몸체를 만들어준다.
    void make208_decorating(int x, int y, int z); // make208이 호출하는 기본함수이며, 208관의 몸체를 만들어준다.

    void makeground(int x, int y, int z); //processground이 호출하면 실행되는 기본함수이고, 운동장을 만들어준다.

    void makeparkingplace(int x, int y, int z); //processparkingplace이 호출하면 실행되는 함수이고, 주차장을 만들어준다. 

    void makeflower(int x, int y, int z); //processflower이 호출하면 실행되는 함수이고, 화단을 만들어준다. 

    void make_kim_lamp(int x, int y, int z); //process_kim_lamp이 호출하면 실행되는 함수이고, 등을 만들어준다. 

    void make_kim_road_mid(int x, int y, int z); //process_kim_road_mid이 호출하면 실행되는 함수이고, 교차로를 만들어준다. 
    void make_kim_road_garo(int x, int y, int z); //process_kim_road_garo이 호출하면 실행되는 함수이고, x축 방향의 도로를 만들어준다. 
    void make_kim_road_sero(int x, int y, int z); //process_kim_road_sero이 호출하면 실행되는 함수이고, z축 방향의 도로를 만들어준다. 

    void make_hong_cauburger(int x, int y, int z); //process_hong_cauburger이 호출하면 실행되는 함수이고, 카우버거 건물을 만들어준다. 
    void make_hong_seven(int x, int y, int z); //process_hong_seven이 호출하면 실행되는 함수이고, 카우버거를 만들어준다. 

    void make101(int x, int y, int z); //process101이 호출하면 실행되는 함수이고, 영신관을 만들어준다. 

    void makepond(int x, int y, int z); //processpond이 호출하면 실행되는 함수이고, 청령연못을 만들어준다. 
    void crtrect(BlockID block, int ex, int ey, int ez, int sx, int sz); //높이 1 직사각형 생성 함수, 매개변수는 좌표 2개
    #define SWAP(x, y) { int t = x; x = y; y=t; } // 중간고사 문제에 나왔던 코드
    void crtstree(int ex, int ey, int ez); //나무 만드는 함수. 나무 밑동이 기준점임
    void crtslight(int ex, int ey, int ez); //등불. 울타리 + 발광석
    void stackblock(BlockID block, int ex, int ey, int ez, int height); //수직으로 블록 쌓는 함수, 매개변수는 좌표1개랑 높이(int)

    void make_kim_riceandpotato(int x, int y, int z);

-->
프로그램 동작시
마을크기 입력받는다.
swap(&array_x1, &array_x2);를 이용하여 숫자를 잘이용할 수 있게 한다.

크기에 맞게 바닥을 생성한다. //makefloor(array_x1, array_z1, array_x2, array_z2);
14개의 건물 중 한 건물을 선택한다.
만약 1번 건물인 310관을 입력하면
process310(x, y, z, array, size_darray_x, size_darray_z, array_x1, array_z1);이 실행된다.

이 함수는 다른 함수를 호출하는데 순서는 아래와 같다.(310관 만들 때)
process310(x, y, z, array, size_darray_x, size_darray_z, array_x1, array_z1);
       
       -make310(x, y, z);
              -make310_body(x, y, z);
              -make310_decorating(x, y, z);
              -make310_window(x, y, z);
              -make310_eliminating(x, y, z);
              - 그 외 처리

       -arraymark(array, (int)(134 / size_darray_x), (int)(60 / size_darray_z), -(int)(array_z1 / size_darray_z) + (int)(z / size_darray_z), -(int)(array_x1 / size_darray_x) + (int)(x / size_darray_x));

(208관 만들 때)
process208(x, y, z, array, size_darray_x, size_darray_z, array_x1, array_z1);

       -make208(x, y, z);
       	-make208_body(x, y, z);
       	-make208_decorating(x, y, z);

	-arraymark(array, (int)(118 / size_darray_x), (int)(15 / size_darray_z), -(int)(array_z1 / size_darray_z) + (int)(z / size_darray_z), -(int)(array_x1 / size_darray_x) + (int)(x / size_darray_x));

(운동장 만들 때)
processground(x, y, z, array, size_darray_x, size_darray_z, array_x1, array_z1);

       -makeground(x, y, z);
       
       -arraymark(array, (int)(75 / size_darray_x), (int)(50 / size_darray_z), -(int)(array_z1 / size_darray_z) + (int)(z / size_darray_z), -(int)(array_x1 / size_darray_x) + (int)(x / size_darray_x));

(기숙사 앞 주차장 만들 때)
processparkingplace(x, y, z, array, size_darray_x, size_darray_z, array_x1, array_z1);

	-makeparkingplace(x, y, z);
       
	-arraymark(array, (int)(20 / size_darray_x), (int)(50 / size_darray_z), -(int)(array_z1 / size_darray_z) + (int)(z / size_darray_z), -(int)(array_x1 / size_darray_x) + (int)(x / size_darray_x));

(운동장 앞 화단을 만들 때)
processflower(x, y, z, array, size_darray_x, size_darray_z, array_x1, array_z1);

	-makeflower(x, y, z);
	-arraymark(array, (int)(5 / size_darray_x), (int)(30 / size_darray_z), -(int)(array_z1 / size_darray_z) + (int)(z / size_darray_z), -(int)(array_x1 / size_darray_x) + (int)(x / size_darray_x));

(등을 만들 때)
process_kim_lamp(x, y, z, array, size_darray_x, size_darray_z, array_x1, array_z1);

	-make_kim_lamp(x, y, z);
	-arraymark(array, (int)(3 / size_darray_x), (int)(3 / size_darray_z), -(int)(array_z1 / size_darray_z) + (int)(z / size_darray_z), -(int)(array_x1 / size_darray_x) + (int)(x / size_darray_x));

(교차로를 만들 때)
process_kim_road_mid(x, y, z, array, size_darray_x, size_darray_z, array_x1, array_z1);

	-make_kim_road_mid(x, y, z);
	-arraymark(array, (int)(10 / size_darray_x), (int)(10 / size_darray_z), -(int)(array_z1 / size_darray_z) + (int)(z / size_darray_z), -(int)(array_x1 / size_darray_x) + (int)(x / size_darray_x));

(x축 방향 도로를 만들 때)
process_kim_road_garo(x, y, z, array, size_darray_x, size_darray_z, array_x1, array_z1);

	-make_kim_road_garo(x, y, z);
	-arraymark(array, (int)(60 / size_darray_x), (int)(10 / size_darray_z), -(int)(array_z1 / size_darray_z) + (int)(z / size_darray_z), -(int)(array_x1 / size_darray_x) + (int)(x / size_darray_x));

(z축 방향 도로를 만들 때)
process_kim_road_sero(x, y, z, array, size_darray_x, size_darray_z, array_x1, array_z1);

	-make_kim_road_sero(x, y, z);
	-arraymark(array, (int)(10 / size_darray_x), (int)(60 / size_darray_z), -(int)(array_z1 / size_darray_z) + (int)(z / size_darray_z), -(int)(array_x1 / size_darray_x) + (int)(x / size_darray_x));

(카우버거를 만들 때)
process_hong_cauburger(x, y, z, array, size_darray_x, size_darray_z, array_x1, array_z1);

	-make_hong_cauburger(x, y, z);
	-arraymark(array, (int)(30 / size_darray_x), (int)(30 / size_darray_z), -(int)(array_z1 / size_darray_z) + (int)(z / size_darray_z), -(int)(array_x1 / size_darray_x) + (int)(x / size_darray_x));

(편의점을 만들 때)
process_hong_seven(x, y, z, array, size_darray_x, size_darray_z, array_x1, array_z1);

	-make_hong_seven(x, y, z);
	-arraymark(array, (int)(35 / size_darray_x), (int)(35 / size_darray_z), -(int)(array_z1 / size_darray_z) + (int)(z / size_darray_z), -(int)(array_x1 / size_darray_x) + (int)(x / size_darray_x));

(101관을 만들 때)
process101(x, y, z, array, size_darray_x, size_darray_z, array_x1, array_z1);

	-make101(x, y, z);
	-arraymark(array, (int)(54 / size_darray_x), (int)(12 / size_darray_z), -(int)(array_z1 / size_darray_z) + (int)(z / size_darray_z), -(int)(array_x1 / size_darray_x) + (int)(x / size_darray_x));

(청룡 연못을 만들 때)
processpond(x, y, z, array, size_darray_x, size_darray_z, array_x1, array_z1);

	-makepond(x, y, z);
              -crtrect(empty, ex, ey - i, ez, ex + 52, ez + 54);
	       -installStairs(bench, ex + 24, ey - 3, ez + 13, FACING_NORTH);
	       -crtstree(ex + 40, ey - 3, ez + 4);
	       -crtslight(ex + 38, ey - 3, ez + 13);
              - 

	-arraymark(array, (int)(64 / size_darray_x), (int)(55 / size_darray_z), -(int)(array_z1 / size_darray_z) + (int)(z / size_darray_z), -(int)(array_x1 / size_darray_x) + (int)(x / size_darray_x));



(라이스앤포테이토 만들때)
process_kim_riceandpotato(x, y, z, array, size_darray_x, size_darray_z, array_x1, array_z1);

	-make_kim_riceandpotato(x, y, z);
	-arraymark(array, (int)(35 / size_darray_x), (int)(35 / size_darray_z), -(int)(array_z1 / size_darray_z) + (int)(z / size_darray_z), -(int)(array_x1 / size_darray_x) + (int)(x / size_darray_x));

매 실행마다 arrayprintf(array);가 실행되도록 한다.

이렇게 하여 기본함수의 개수는 23개
기본함수를 활용하는 함수는 14개
기본함수를 활용하는 함수를 활용하는 함수는 3개이다.


. 과제를 설명하는 유투브 동영상

       https://www.youtube.com/watch?v=iQiAbWClRdo&t=1s


