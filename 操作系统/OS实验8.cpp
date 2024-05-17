//#include<iostream>
//#include<vector>
//using namespace std;
//#define VM_PAGE 7      //页面最大为7
//#define PM_PAGE 4         //分配给作业的内存块数为4,表示可以同时驻留在内存中的物理块最多有4个
//#define TOTAL_INSERT 18  //页面访问串大小为18
//typedef struct
//{
//	int vmn;//页号
//	int pmn;//物理块号
//	int exist;//是否在内存中
//	int time;//不同的算法含义不同.
//	//在opt中无实际意义，在LRU中time为最近访问的时间。该虚页每访问一次，time置为当前访问时刻，淘汰页面时，淘汰time值最小的，即最久没有被使用的。
//	//在FIFO算法中，time为该虚页进入内存的时间。只有当该虚页从外存进入内存时，才置该标志。淘汰页面时，淘汰time值最小的，即最早进入内存的虚页，也就是驻留时间最长的
//}vpage_item;//页表的一项数据，包括
//vpage_item page_table[VM_PAGE];
//vpage_item* ppage_bitmap[PM_PAGE];//该处的值为NULL，代表物理页并未被占用，否则表示正在占用该物理页的虚页
//int vpage_arr[TOTAL_INSERT] = { 1,2,3,4,2,6,2,1,2,3,7,6,3,2,1,2,3,6 };//页面访问串
//int arr[7][1];
//void init_data() //数据初始化
//{
//	for (int i = 0; i < VM_PAGE; i++)
//	{
//		page_table[i].vmn = i + 1;  //虚页号
//		page_table[i].pmn = -1;    //实页号
//		page_table[i].exist = 0;
//		page_table[i].time = -1;
//	}
//	for (int i = 0; i < PM_PAGE; i++) /*最初4个物理块为空*/
//	{
//		ppage_bitmap[i] = NULL;
//	}
//}
////FIFO置换算法
////算法思想:总是先淘汰那些驻留在内存时间最长的页面
//void FIFO()
//{
//	int k = 0;//当前已经使用了的物理块数
//	int i;
//	int sum = 0;//表示已经访问过的过的串数，初始值为0
//	int missing_page_count = 0;//缺页数
//	int current_time = 0;//当前时间设置为0
//	bool isleft = true;   /*当前物理块中是否有剩余*/
//	while (sum < TOTAL_INSERT)
//	{
//		if (page_table[vpage_arr[sum] - 1].exist == 0)//如果当前要调用的页面并不在内存中的话
//		//减一是因为为虚页号与i的差值为1
//		{
//			missing_page_count++;//缺页数加1
//			if (k < 4)//此时不需要替换，有空闲的物理块
//			{
//				if (ppage_bitmap[k] == NULL) /*找到一个空闲物理块*/
//				{
//					ppage_bitmap[k] = &page_table[vpage_arr[sum] - 1];//调入内存
//					ppage_bitmap[k]->exist = 1;//存在
//					ppage_bitmap[k]->pmn = k;
//					ppage_bitmap[k]->time = current_time;//时间记录为当前时间
//					k++;
//				}
//			}
//			else
//			{
//				//此时需要调用算法调出当前时间最小的页面
//				int temp = ppage_bitmap[0]->time;	/*记录物理块中作业最早到达时间*/
//				int j = 0;                 /*记录应当被替换的物理块号*/
//				for (i = 0; i < PM_PAGE; i++)//遍历当前的所有物理块
//				{
//					if (ppage_bitmap[i]->time < temp)
//					{
//						temp = ppage_bitmap[i]->time;
//						j = i;
//					}
//				}
//				ppage_bitmap[j]->exist = 0;
//				ppage_bitmap[j] = &page_table[vpage_arr[sum] - 1];      /*更新页表项*/
//				ppage_bitmap[j]->exist = 1;
//				ppage_bitmap[j]->pmn = j;//物理块号为
//				ppage_bitmap[j]->time = current_time;
//			}
//		}
//		current_time++;//时间+1
//		sum++;//处理的页面数加1
//	}
//	printf("FIFO算法缺页次数为:%d\t缺页率为:%f\t置换次数为:%d\t置换率为:%f", missing_page_count, missing_page_count / (float)TOTAL_INSERT, missing_page_count - 4, (missing_page_count - 4) / (float)TOTAL_INSERT);
//}
////LRU算法
////最近最久未使用的页面（最近一段时间内，最少被访问的页面）予以淘汰。
//void LRU()
//{
//	int k = 0;//当前已经使用了的物理块数
//	int i;
//	int sum = 0;//表示已经访问过的过的串数，初始值为0
//	int missing_page_count = 0;//缺页数
//	int current_time = 0;//当前时间设置为0
//	bool isleft = true;   /*当前物理块中是否有剩余*/
//	while (sum < TOTAL_INSERT)
//	{
//		if (page_table[vpage_arr[sum] - 1].exist == 0)//如果当前要调用的页面并不在内存中的话
//		//减一是因为为虚页号与i的差值为1
//		{
//			missing_page_count++;//缺页数加1
//			if (k < 4)//此时不需要替换，有空闲的物理块
//			{
//				if (ppage_bitmap[k] == NULL) /*找到一个空闲物理块*/
//				{
//					ppage_bitmap[k] = &page_table[vpage_arr[sum] - 1];//调入内存
//					ppage_bitmap[k]->exist = 1;//存在
//					ppage_bitmap[k]->pmn = k;
//					ppage_bitmap[k]->time = current_time;//时间记录为当前时间
//					k++;
//					arr[vpage_arr[sum] - 1][0] == current_time;
//				}
//			}
//			else
//			{
//				//此时选择出最近最久未使用的页面予以淘汰
//				int temp = arr[ppage_bitmap[0]->vmn-1][0];	/*记录物理块中作业最久未使用的块号*/
//				int j = 0;                 /*记录应当被替换的物理块号*/
//				for (i = 0; i < PM_PAGE; i++)//遍历当前的所有物理块
//				{
//					if (arr[ppage_bitmap[i]->vmn][0] < temp)
//					{
//						temp = arr[ppage_bitmap[i]->vmn-1][0];
//						j = i;
//					}
//				}
//				ppage_bitmap[j]->exist = 0;
//				ppage_bitmap[j] = &page_table[vpage_arr[sum] - 1];      /*更新页表项*/
//				ppage_bitmap[j]->exist = 1;
//				ppage_bitmap[j]->pmn = j;//物理块号为
//				ppage_bitmap[j]->time = current_time;
//				arr[vpage_arr[sum] - 1][0] == current_time;
//			}
//		}
//		else
//		{
//			arr[vpage_arr[sum] - 1][0] == current_time;
//		}
//		current_time++;//时间+1
//		sum++;//处理的页面数加1
//	}
//	printf("LRU算法缺页次数为:%d\t缺页率为:%f\t置换次数为:%d\t置换率为:%f", missing_page_count, missing_page_count / 
//		(float)TOTAL_INSERT, missing_page_count - 4, (missing_page_count - 4) / (float)TOTAL_INSERT);
//}
//int weizhi(int i,int x)
//{
//	//i是当前位置
//	int weizhi = 18;
//	for (int j = i + 1;j < 18;j++)
//	{
//		if (vpage_arr[j] == x)
//		{
//			return j;
//		}
//	}
//	return weizhi;
//}
////最佳置换算法，其所选择的被淘汰页面将是以后永不使用的，或是在将来很长时间内不再被访问的页面
//void OPT()
//{
//	int k = 0;//当前已经使用了的物理块数
//	int i;
//	int sum = 0;//表示已经访问过的过的串数，初始值为0
//	int missing_page_count = 0;//缺页数
//	int current_time = 0;//当前时间设置为0
//	bool isleft = true;   /*当前物理块中是否有剩余*/
//	while (sum < TOTAL_INSERT)
//	{
//		if (page_table[vpage_arr[sum] - 1].exist == 0)//如果当前要调用的页面并不在内存中的话
//		//减一是因为为虚页号与i的差值为1
//		{
//			missing_page_count++;//缺页数加1
//			if (k < 4)//此时不需要替换，有空闲的物理块
//			{
//				if (ppage_bitmap[k] == NULL) /*找到一个空闲物理块*/
//				{
//					ppage_bitmap[k] = &page_table[vpage_arr[sum] - 1];//调入内存
//					ppage_bitmap[k]->exist = 1;//存在
//					ppage_bitmap[k]->pmn = k;
//					ppage_bitmap[k]->time = current_time;//时间记录为当前时间
//					k++;
//					arr[vpage_arr[sum] - 1][0] == current_time;
//				}
//			}
//			else
//			{
//				//此时选择出最久不再使用或者永不使用的
//				int temp = weizhi(sum, vpage_arr[sum]);
//				int j = 0;                 /*记录应当被替换的物理块号*/
//				for (i = 0; i < PM_PAGE; i++)//遍历当前的所有物理块
//				{
//					int a = weizhi(sum, ppage_bitmap[i]->vmn);
//					if (a > temp)
//					{
//						temp = a;
//						j = i;
//					}
//				}
//				ppage_bitmap[j]->exist = 0;
//				ppage_bitmap[j] = &page_table[vpage_arr[sum] - 1];      /*更新页表项*/
//				ppage_bitmap[j]->exist = 1;
//				ppage_bitmap[j]->pmn = j;//物理块号为
//				ppage_bitmap[j]->time = current_time;
//			}
//		}
//		current_time++;//时间+1
//		sum++;//处理的页面数加1
//	}
//	printf("OPT算法缺页次数为:%d\t缺页率为:%f\t置换次数为:%d\t置换率为:%f", missing_page_count, missing_page_count /
//		(float)TOTAL_INSERT, missing_page_count - 4, (missing_page_count - 4) / (float)TOTAL_INSERT);
//}
//int main()
//{
//	int a;
//	for (int i = 0;i < 7;i++)//初始化
//	{
//		arr[i][0] = INT_MAX;
//	}
//	char ch;
//FLAG2:
//	printf("请输入需要选择的页面置换算法：1.FIFO\t2.LRU\t3.OPT\t输入0结束\n");
//	do
//	{
//		scanf_s("%d", &a);
//		switch (a)
//		{
//		case 1:
//		
//			init_data();
//			FIFO();
//			break;
//		case 2:
//			init_data();
//			LRU();
//			break;
//		case 3:
//			init_data();
//			OPT();
//			break;
//		}
//	} while (a != 0);
//	cout << "是否继续(Y or N)" << endl;
//	cin >> ch;
//	if (ch == 'Y' || ch == 'y')
//	{
//		goto FLAG2;
//	}
//	return 0;
//}