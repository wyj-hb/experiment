//#define _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//#include<vector>
//using namespace std;
//
//const int MAXJOB = 50;//最大作业数是50
////定义结构体作业job
//typedef struct node
//{
//	int number; // 作业号
//	int reach_time;// 作业抵达时间
//	int need_time;// 作业的执行时间
//	int privilege;// 作业优先权
//	float excellent;// 响应比
//	int start_time;// 作业开始时间
//	int wait_time;// 等待时间
//	int visited;// 作业是否被访问过
//	bool isreached;// 作业是否已经抵达
//}job;
//job jobs[MAXJOB];//作业序列,最多有50个
//int quantity;//作业数量,当前数量
//void initial_jobs()//作业的初始化
//{
//	int i;
//	for (i = 0;i < MAXJOB;i++)
//	{
//		jobs[i].number = 0;
//		jobs[i].reach_time = 0;
//		jobs[i].privilege = 0;
//		jobs[i].excellent = 0;
//		jobs[i].start_time = 0;
//		jobs[i].wait_time = 0;
//		jobs[i].visited = 0;
//		jobs[i].isreached = false;
//	}
//	quantity = 0;
//}
////重置全部作业信息
//void reset_jinfo()
//{
//	int i;
//	for (i = 0;i < MAXJOB;i++)
//	{
//		jobs[i].start_time = 0;//作业开始时间
//		jobs[i].wait_time = 0;//作业等待时间
//		jobs[i].visited = 0;//作业是否被访问过
//		jobs[i].isreached = false;
//	}
//}
////查找当前current_time已到达未执行的最短作业,若无返回-1
//int findminjob(job jobs[], int count)
//{
//	int minjob = -1;//=jobs[0].need_time;
//	int minloc = -1;
//	for (int i = 0;i < count;i++)
//	{
//		if (minloc == -1)
//		{//首先将第一个判断的作业假设为已到达最短未执行作业
//			if (jobs[i].isreached == true && jobs[i].visited == 0)
//			{//如果作业已经到达并且作业并未被访问过
//				minjob = jobs[i].need_time;//记录时间
//				minloc = i;
//			}
//		}
//		else if (minjob > jobs[i].need_time && jobs[i].visited == 0 && jobs[i].isreached == true)
//		{
//			//更新最短到达未执行
//			minjob = jobs[i].need_time;
//			minloc = i;
//		}
//	}
//	return minloc;//返回其所处的下标
//}
//void jieshuyidaoda(job jobs[], int nowtime, int count)
//{
//	int i = 0;
//	for (int i = 0;i < count;i++)
//	{
//		if (jobs[i].reach_time <= nowtime)
//		{
//			jobs[i].isreached = true;
//		}
//	}
//}
////查找最早到达作业，若全部到达返回-1.
//int findrearlyjob(job jobs[], int count)
//{
//	int rearlyloc = -1;
//	int rearlyjob = -1;
//	for (int i = 0;i < count;i++)
//	{
//		if (rearlyloc == -1) {
//			if (jobs[i].visited == 0)
//			{//访问的过的并不考虑
//				rearlyloc = i;
//				rearlyjob = jobs[i].reach_time;
//			}
//		}
//		else if (rearlyjob > jobs[i].reach_time && jobs[i].visited == 0)
//		{
//			rearlyjob = jobs[i].reach_time;
//			rearlyloc = i;
//		}
//	}
//	return rearlyloc;
//}
//int findgaoxiangyingjob(job jobs[], int count,int nowtime)
//{
//	double minjob = -1;//=jobs[0].need_time;
//	int minloc = -1;
//	int i = 0;
//	for (int i = 0;i < count;i++)
//	{
//		//高响应比:(等待时间加所需时间)/所需时间
//		if (jobs[i].isreached == true && jobs[i].visited == 0)
//		{
//			double wait = nowtime - jobs[i].reach_time;
//			double gao = wait + jobs[i].need_time;
//			double gaoxiangyin = gao / jobs[i].need_time;
//			if (minloc == -1)
//			{
//				//已经到达
//				minjob = gaoxiangyin;
//				minloc = i;
//			}
//			else
//			{
//
//				if (minjob < gaoxiangyin)
//				{
//					minjob = gaoxiangyin;
//					minloc = i;
//				}
//			}
//		}
//	}
//	return minloc;
//}
//bool panduan(job jobs[], int count) //判断当前是否有队列存在
//{
//	for (int i = 0;i < count;i++)
//	{
//		if (jobs[i].isreached == true && jobs[i].visited == 0)
//		{
//			return true;
//		}
//	}
//	return false;
//}
////读取作业数据
//void readJobdata()
//{
//	FILE* fp;
//	char fname[20];
//	int i;
//	//输入测试文件文件名
//	printf("please input job data file name\n");
//	scanf("%s", fname);
//	if ((fp = fopen(fname, "r")) == NULL)//文件打开失败
//	{
//		printf("error, open file failed, please check filename:\n");
//	}
//	else
//	{
//		//依次读取作业信息
//		while (!feof(fp))//feof函数检查流上的文件结束标志，如果结束返回1，否则返回0
//		{
//			if (fscanf(fp, "%d %d %d %d", &jobs[quantity].number, &jobs[quantity].reach_time, &jobs[quantity].need_time, &jobs[quantity].privilege) == 4)
//				quantity++;//读取成功数量加1
//		}
//		//打印作业信息
//		printf("output the origin job data\n");
//		printf("---------------------------------------------------------------------\n");
//		printf("\tjobID\treachtime\tneedtime\tprivilege\n");
//		for (i = 0;i < quantity;i++)
//		{
//			printf("\t%-8d\t%-8d\t%-8d\t%-8d\n", jobs[i].number, jobs[i].reach_time, jobs[i].need_time, jobs[i].privilege);
//		}
//	}
//}
////FCFS 先来先服务原则
//void FCFS()
//{
//	int i;
//	int current_time = 0;
//	int loc;
//	int total_waitime = 0;
//	int total_roundtime = 0;
//	//获取最近到达的作业
//	loc = findrearlyjob(jobs, quantity);
//	//输出作业流
//	printf("\n\nFCFS算法作业流\n");
//	printf("------------------------------------------------------------------------\n");
//	printf("\tjobID\treachtime\tstarttime\twaittime\troundtime\n");
//	current_time = jobs[loc].reach_time;
//	//每次循环找出最先到达的作业并打印相关信息
//	for (i = 0;i < quantity;i++)
//	{
//		//分为两种情况
//		//1.作业先到达，但是并未执行，那么现在的时间就是作业的开始执行时间，作业的等待时间就等于当前时间减去到达时间
//		//2.作业在当前时间后到达，那么应该把当前时间调整到作业到达的时间(在这期间无作业执行，无意义)，作业的开始执行时间便是作业的到达时间,作业的等待时间仍可以使用当前时间减去到达时间
//		if (jobs[loc].reach_time > current_time)
//		{
//			jobs[loc].start_time = jobs[loc].reach_time;//到达时间即为开始时间，因为是最先到达的
//			current_time = jobs[loc].reach_time;
//		}
//		else
//		{
//			jobs[loc].start_time = current_time;
//		}
//		jobs[loc].wait_time = current_time - jobs[loc].reach_time;//等待时间,作业的等待时间就等于当前时间减去到达时间
//		printf("\t%-8d\t%-8d\t%-8d\t%-8d\t%-8d\n", loc + 1, jobs[loc].reach_time, jobs[loc].start_time, jobs[loc].wait_time,
//			jobs[loc].wait_time + jobs[loc].need_time);//编号、作业到达时间、启动时间、等待时间和作业从到达到执行完成所需时间
//		jobs[loc].visited = 1;//已经被访问
//		current_time += jobs[loc].need_time;//当前时间更新
//		total_waitime += jobs[loc].wait_time;//总共等待时间更新
//		total_roundtime = total_roundtime + jobs[loc].wait_time + jobs[loc].need_time;//总共周转时间
//		//获取剩余作业中最近到达作业
//		loc = findrearlyjob(jobs, quantity);
//	}
//	printf("总等待时间:%-8d 总周转时间:%-8d\n", total_waitime, total_roundtime);
//	printf("平均等待时间: %4.2f 平均周转时间: %4.2f\n", (float)total_waitime / (quantity), (float)total_roundtime / (quantity));
//}
////短作业优先作业调度
//void SFJschdulejob(job jobs[], int count)
//{
//	int i;
//	int current_time = 0;
//	int loc;
//	loc = findrearlyjob(jobs, quantity);
//	current_time = jobs[loc].reach_time;
//	int total_waitime = 0;
//	int total_roundtime = 0;
//	//输出作业流
//	printf("\n\nSJF算法作业流\n");
//	printf("------------------------------------------------------------------------\n");
//	printf("\tjobID\treachtime\tstarttime\twaittime\troundtime\n");
//	//每次循环找出已经到达的最短作业并打印相关信息
//	for (i = 0;i < quantity;i++)
//	{
//		//分为两种情况
//		//1.作业执行完成，但此时后备队列里没有可调用的作业，此时应该等待, 选择接下来最先到达的队列 
//		//2.作业执行完成，此时后备队列又可以调用的作业，选择作业所需时间最小的作业调入 
//		if (i > 0)
//		{
//			if (panduan(jobs, quantity))
//			{
//				//此时队列中已有作业，调入最小即可。 
//				loc = findminjob(jobs, quantity);
//				jobs[loc].start_time = current_time;
//			}
//			else
//			{
//				//此时应选择最先到达的作业
//				loc = findrearlyjob(jobs, quantity);
//				jobs[loc].start_time = jobs[loc].reach_time;
//				current_time = jobs[loc].reach_time;
//			}
//		}
//		jobs[loc].wait_time = current_time - jobs[loc].reach_time;//等待时间,作业的等待时间就等于当前时间减去到达时间
//		printf("\t%-8d\t%-8d\t%-8d\t%-8d\t%-8d\n", loc + 1, jobs[loc].reach_time, jobs[loc].start_time, jobs[loc].wait_time,
//			jobs[loc].wait_time + jobs[loc].need_time);//编号、作业到达时间、启动时间、等待时间和作业从到达到执行完成所需时间
//		jobs[loc].visited = 1;//已经被访问
//		current_time += jobs[loc].need_time;//当前时间更新
//		total_waitime += jobs[loc].wait_time;//总共等待时间更新
//		total_roundtime = total_roundtime + jobs[loc].wait_time + jobs[loc].need_time;//总共周转时间
//		//获取剩余作业中最近到达作业
//		jieshuyidaoda(jobs, current_time, quantity);
//	}
//	printf("总等待时间:%-8d 总周转时间:%-8d\n", total_waitime, total_roundtime);
//	printf("平均等待时间: %4.2f 平均周转时间: %4.2f\n", (float)total_waitime / (quantity), (float)total_roundtime / (quantity));
//}
//
////高响应比调度算法
//void HRRFschdulejob()
//{
//	int i;
//	int current_time = 0;
//	int loc;
//	loc = findrearlyjob(jobs, quantity);
//	current_time = jobs[loc].reach_time;
//	int total_waitime = 0;
//	int total_roundtime = 0;
//	//输出作业流
//	printf("\n\nHRRF算法作业流\n");
//	printf("------------------------------------------------------------------------\n");
//	printf("\tjobID\treachtime\tstarttime\twaittime\troundtime\n");
//	//每次循环找出相应比最高的并打印相关信息
//	for (i = 0;i < quantity;i++)
//	{
//		//分为两种情况
//		//1.作业执行完成，但此时后备队列里没有可调用的作业，此时应该等待, 选择接下来最先到达的队列 
//		//2.作业执行完成，此时后备队列又可以调用的作业，选择作业高响应比最高的作业调入 
//		if (i > 0)
//		{
//			if (panduan(jobs, quantity))
//			{
//				//此时队列中已有作业，调入最小即可。 
//				loc = findgaoxiangyingjob(jobs, quantity,current_time);
//				jobs[loc].start_time = current_time;
//			}
//			else
//			{
//				//此时应选择最先到达的作业
//				loc = findrearlyjob(jobs, quantity);
//				jobs[loc].start_time = jobs[loc].reach_time;
//				current_time = jobs[loc].reach_time;
//			}
//		}
//		jobs[loc].wait_time = current_time - jobs[loc].reach_time;//等待时间,作业的等待时间就等于当前时间减去到达时间
//		printf("\t%-8d\t%-8d\t%-8d\t%-8d\t%-8d\n", loc + 1, jobs[loc].reach_time, jobs[loc].start_time, jobs[loc].wait_time,
//			jobs[loc].wait_time + jobs[loc].need_time);//编号、作业到达时间、启动时间、等待时间和作业从到达到执行完成所需时间
//		jobs[loc].visited = 1;//已经被访问
//		current_time += jobs[loc].need_time;//当前时间更新
//		total_waitime += jobs[loc].wait_time;//总共等待时间更新
//		total_roundtime = total_roundtime + jobs[loc].wait_time + jobs[loc].need_time;//总共周转时间
//		//获取剩余作业中最近到达作业
//		jieshuyidaoda(jobs, current_time, quantity);
//	}
//	printf("总等待时间:%-8d 总周转时间:%-8d\n", total_waitime, total_roundtime);
//	printf("平均等待时间: %4.2f 平均周转时间: %4.2f\n", (float)total_waitime / (quantity), (float)total_roundtime / (quantity));
//}
//int fangaoyouxianquan(job jobs[], int count, int nowtime)
//{
//	double minjob = -1;//=jobs[0].need_time;
//	int minloc = -1;
//	int i = 0;
//	for (int i = 0;i < count;i++)
//	{
//		//比较优先权
//		if (jobs[i].isreached == true && jobs[i].visited == 0)
//		{
//			if (minloc == -1)
//			{
//				//已经到达
//				minjob = jobs[i].privilege;
//				minloc = i;
//			}
//			else
//			{
//
//				if (minjob < jobs[i].privilege)
//				{
//					minjob = jobs[i].privilege;
//					minloc = i;
//				}
//			}
//		}
//	}
//	return minloc;
//}
////优先权高者优先调度算法
//void HPF(job jobs[])
//{
//	int i;
//	int current_time = 0;
//	int loc;
//	loc = findrearlyjob(jobs, quantity);
//	current_time = jobs[loc].reach_time;
//	int total_waitime = 0;
//	int total_roundtime = 0;
//	//输出作业流
//	printf("\n\nHPF算法作业流\n");
//	printf("------------------------------------------------------------------------\n");
//	printf("\tjobID\treachtime\tstarttime\twaittime\troundtime\n");
//	//每次循环找出相应比最高的并打印相关信息
//	for (i = 0;i < quantity;i++)
//	{
//		//分为两种情况
//		//1.作业执行完成，但此时后备队列里没有可调用的作业，此时应该等待, 选择接下来最先到达的队列 
//		//2.作业执行完成，此时后备队列又可以调用的作业，选择优先权最高的作业进行调度 
//		if (i > 0)
//		{
//			if (panduan(jobs, quantity))
//			{
//				loc = fangaoyouxianquan(jobs, quantity, current_time);
//				jobs[loc].start_time = current_time;
//			}
//			else
//			{
//				//此时应选择最先到达的作业
//				loc = findrearlyjob(jobs, quantity);
//				jobs[loc].start_time = jobs[loc].reach_time;
//				current_time = jobs[loc].reach_time;
//			}
//		}
//		jobs[loc].wait_time = current_time - jobs[loc].reach_time;//等待时间,作业的等待时间就等于当前时间减去到达时间
//		printf("\t%-8d\t%-8d\t%-8d\t%-8d\t%-8d\n", loc + 1, jobs[loc].reach_time, jobs[loc].start_time, jobs[loc].wait_time,
//			jobs[loc].wait_time + jobs[loc].need_time);//编号、作业到达时间、启动时间、等待时间和作业从到达到执行完成所需时间
//		jobs[loc].visited = 1;//已经被访问
//		current_time += jobs[loc].need_time;//当前时间更新
//		total_waitime += jobs[loc].wait_time;//总共等待时间更新
//		total_roundtime = total_roundtime + jobs[loc].wait_time + jobs[loc].need_time;//总共周转时间
//		//获取剩余作业中最近到达作业
//		jieshuyidaoda(jobs, current_time, quantity);
//	}
//	printf("总等待时间:%-8d 总周转时间:%-8d\n", total_waitime, total_roundtime);
//	printf("平均等待时间: %4.2f 平均周转时间: %4.2f\n", (float)total_waitime / (quantity), (float)total_roundtime / (quantity));
//}
//int main()
//{
//	initial_jobs();
//	readJobdata();
//	FCFS();
//	reset_jinfo();
//	SFJschdulejob(jobs, quantity);
//	reset_jinfo();
//	HRRFschdulejob();
//	reset_jinfo();
//	HPF(jobs);
//	system("pause");
//	return 0;
//}