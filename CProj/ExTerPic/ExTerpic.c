#include <stdio.h>
#include <stdlib.h>

int main(int agrc, char* argv[])
{
	FILE* fp;
	char buf[1024];
	char* pstr;
	memset(buf,0, sizeof(buf));
	const char* settingJsonPath = "/mnt/c/Users/Administrator/AppData/Local/Packages/Microsoft.WindowsTerminal_8wekyb3d8bbwe/LocalState/setting.json";
	printf("%s\n", settingJsonPath);
	
	//打开文件
	fp = fopen(settingJsonPath,"rw");

	if(!fp) 
	{
		perror("打开文件失败!\n");
		return -1;
	}

	//按行读取setting.json
	pstr = fgets(buf,sizeof(buf), fp);
	printf("%s\n",buf);
	while(pstr!=NULL)
	{
		pstr = fgets(buf,sizeof(buf),fp);
		printf("%s\n",buf);
	}

	fclose(fp);



//	fp = fopen(	
// 文件路径 "mnt/c/Users/Administrator/AppData/LocalPackagesMicrosoft\.WindowsTerminal_8wekyb3d8bbwe/LocalState/setting.json"
}

