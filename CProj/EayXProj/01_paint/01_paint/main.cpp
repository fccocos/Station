#include <graphics.h>//eayx��Ļ�ͼͷ�ļ�
#include <conio.h>//����̨�������ͷ�ļ���_getch�ڸÿ���
#include <cstdlib>

#define LEN 10000

int main()
{
	//��ʼ����ͼ����

	initgraph(640, 480, 0);
	line(50, 50, 150, 50);
	line(50, 150, 150, 150);
	line(50, 50, 50, 150);
	line(150, 50, 150, 150);

	setlinecolor(RGB(200, 0, 0));

	line(100, 50, 150, 100);
	line(150, 100,100, 150);
	line(100, 150, 50, 100);
	line(50, 100, 100, 50);

	for (int i = 320; i < 420; i += 10)
		for (int j = 240; j < 340; j += 10)
			if ((i-320) * ((i-320) + (j-240) * (j-240)) <= 10000)
			{
				line(320, 240, i, j);
				Sleep(500);
			}
				
	_getch();
	closegraph();
	return 0;
	
}