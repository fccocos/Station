#include <graphics.h>//eayx库的绘图头文件
#include <conio.h>//控制台输入输出头文件，_getch在该库中
#include <cstdlib>

#define LEN 10000

int main()
{
	//初始化绘图界面

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