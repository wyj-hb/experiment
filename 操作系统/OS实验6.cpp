//#define _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//#include<vector>
//using namespace std;
//
//const int MAXJOB = 50;//�����ҵ����50
////����ṹ����ҵjob
//typedef struct node
//{
//	int number; // ��ҵ��
//	int reach_time;// ��ҵ�ִ�ʱ��
//	int need_time;// ��ҵ��ִ��ʱ��
//	int privilege;// ��ҵ����Ȩ
//	float excellent;// ��Ӧ��
//	int start_time;// ��ҵ��ʼʱ��
//	int wait_time;// �ȴ�ʱ��
//	int visited;// ��ҵ�Ƿ񱻷��ʹ�
//	bool isreached;// ��ҵ�Ƿ��Ѿ��ִ�
//}job;
//job jobs[MAXJOB];//��ҵ����,�����50��
//int quantity;//��ҵ����,��ǰ����
//void initial_jobs()//��ҵ�ĳ�ʼ��
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
////����ȫ����ҵ��Ϣ
//void reset_jinfo()
//{
//	int i;
//	for (i = 0;i < MAXJOB;i++)
//	{
//		jobs[i].start_time = 0;//��ҵ��ʼʱ��
//		jobs[i].wait_time = 0;//��ҵ�ȴ�ʱ��
//		jobs[i].visited = 0;//��ҵ�Ƿ񱻷��ʹ�
//		jobs[i].isreached = false;
//	}
//}
////���ҵ�ǰcurrent_time�ѵ���δִ�е������ҵ,���޷���-1
//int findminjob(job jobs[], int count)
//{
//	int minjob = -1;//=jobs[0].need_time;
//	int minloc = -1;
//	for (int i = 0;i < count;i++)
//	{
//		if (minloc == -1)
//		{//���Ƚ���һ���жϵ���ҵ����Ϊ�ѵ������δִ����ҵ
//			if (jobs[i].isreached == true && jobs[i].visited == 0)
//			{//�����ҵ�Ѿ����ﲢ����ҵ��δ�����ʹ�
//				minjob = jobs[i].need_time;//��¼ʱ��
//				minloc = i;
//			}
//		}
//		else if (minjob > jobs[i].need_time && jobs[i].visited == 0 && jobs[i].isreached == true)
//		{
//			//������̵���δִ��
//			minjob = jobs[i].need_time;
//			minloc = i;
//		}
//	}
//	return minloc;//�������������±�
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
////�������絽����ҵ����ȫ�����ﷵ��-1.
//int findrearlyjob(job jobs[], int count)
//{
//	int rearlyloc = -1;
//	int rearlyjob = -1;
//	for (int i = 0;i < count;i++)
//	{
//		if (rearlyloc == -1) {
//			if (jobs[i].visited == 0)
//			{//���ʵĹ��Ĳ�������
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
//		//����Ӧ��:(�ȴ�ʱ�������ʱ��)/����ʱ��
//		if (jobs[i].isreached == true && jobs[i].visited == 0)
//		{
//			double wait = nowtime - jobs[i].reach_time;
//			double gao = wait + jobs[i].need_time;
//			double gaoxiangyin = gao / jobs[i].need_time;
//			if (minloc == -1)
//			{
//				//�Ѿ�����
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
//bool panduan(job jobs[], int count) //�жϵ�ǰ�Ƿ��ж��д���
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
////��ȡ��ҵ����
//void readJobdata()
//{
//	FILE* fp;
//	char fname[20];
//	int i;
//	//��������ļ��ļ���
//	printf("please input job data file name\n");
//	scanf("%s", fname);
//	if ((fp = fopen(fname, "r")) == NULL)//�ļ���ʧ��
//	{
//		printf("error, open file failed, please check filename:\n");
//	}
//	else
//	{
//		//���ζ�ȡ��ҵ��Ϣ
//		while (!feof(fp))//feof����������ϵ��ļ�������־�������������1�����򷵻�0
//		{
//			if (fscanf(fp, "%d %d %d %d", &jobs[quantity].number, &jobs[quantity].reach_time, &jobs[quantity].need_time, &jobs[quantity].privilege) == 4)
//				quantity++;//��ȡ�ɹ�������1
//		}
//		//��ӡ��ҵ��Ϣ
//		printf("output the origin job data\n");
//		printf("---------------------------------------------------------------------\n");
//		printf("\tjobID\treachtime\tneedtime\tprivilege\n");
//		for (i = 0;i < quantity;i++)
//		{
//			printf("\t%-8d\t%-8d\t%-8d\t%-8d\n", jobs[i].number, jobs[i].reach_time, jobs[i].need_time, jobs[i].privilege);
//		}
//	}
//}
////FCFS �����ȷ���ԭ��
//void FCFS()
//{
//	int i;
//	int current_time = 0;
//	int loc;
//	int total_waitime = 0;
//	int total_roundtime = 0;
//	//��ȡ����������ҵ
//	loc = findrearlyjob(jobs, quantity);
//	//�����ҵ��
//	printf("\n\nFCFS�㷨��ҵ��\n");
//	printf("------------------------------------------------------------------------\n");
//	printf("\tjobID\treachtime\tstarttime\twaittime\troundtime\n");
//	current_time = jobs[loc].reach_time;
//	//ÿ��ѭ���ҳ����ȵ������ҵ����ӡ�����Ϣ
//	for (i = 0;i < quantity;i++)
//	{
//		//��Ϊ�������
//		//1.��ҵ�ȵ�����ǲ�δִ�У���ô���ڵ�ʱ�������ҵ�Ŀ�ʼִ��ʱ�䣬��ҵ�ĵȴ�ʱ��͵��ڵ�ǰʱ���ȥ����ʱ��
//		//2.��ҵ�ڵ�ǰʱ��󵽴��ôӦ�ðѵ�ǰʱ���������ҵ�����ʱ��(�����ڼ�����ҵִ�У�������)����ҵ�Ŀ�ʼִ��ʱ�������ҵ�ĵ���ʱ��,��ҵ�ĵȴ�ʱ���Կ���ʹ�õ�ǰʱ���ȥ����ʱ��
//		if (jobs[loc].reach_time > current_time)
//		{
//			jobs[loc].start_time = jobs[loc].reach_time;//����ʱ�伴Ϊ��ʼʱ�䣬��Ϊ�����ȵ����
//			current_time = jobs[loc].reach_time;
//		}
//		else
//		{
//			jobs[loc].start_time = current_time;
//		}
//		jobs[loc].wait_time = current_time - jobs[loc].reach_time;//�ȴ�ʱ��,��ҵ�ĵȴ�ʱ��͵��ڵ�ǰʱ���ȥ����ʱ��
//		printf("\t%-8d\t%-8d\t%-8d\t%-8d\t%-8d\n", loc + 1, jobs[loc].reach_time, jobs[loc].start_time, jobs[loc].wait_time,
//			jobs[loc].wait_time + jobs[loc].need_time);//��š���ҵ����ʱ�䡢����ʱ�䡢�ȴ�ʱ�����ҵ�ӵ��ﵽִ���������ʱ��
//		jobs[loc].visited = 1;//�Ѿ�������
//		current_time += jobs[loc].need_time;//��ǰʱ�����
//		total_waitime += jobs[loc].wait_time;//�ܹ��ȴ�ʱ�����
//		total_roundtime = total_roundtime + jobs[loc].wait_time + jobs[loc].need_time;//�ܹ���תʱ��
//		//��ȡʣ����ҵ�����������ҵ
//		loc = findrearlyjob(jobs, quantity);
//	}
//	printf("�ܵȴ�ʱ��:%-8d ����תʱ��:%-8d\n", total_waitime, total_roundtime);
//	printf("ƽ���ȴ�ʱ��: %4.2f ƽ����תʱ��: %4.2f\n", (float)total_waitime / (quantity), (float)total_roundtime / (quantity));
//}
////����ҵ������ҵ����
//void SFJschdulejob(job jobs[], int count)
//{
//	int i;
//	int current_time = 0;
//	int loc;
//	loc = findrearlyjob(jobs, quantity);
//	current_time = jobs[loc].reach_time;
//	int total_waitime = 0;
//	int total_roundtime = 0;
//	//�����ҵ��
//	printf("\n\nSJF�㷨��ҵ��\n");
//	printf("------------------------------------------------------------------------\n");
//	printf("\tjobID\treachtime\tstarttime\twaittime\troundtime\n");
//	//ÿ��ѭ���ҳ��Ѿ�����������ҵ����ӡ�����Ϣ
//	for (i = 0;i < quantity;i++)
//	{
//		//��Ϊ�������
//		//1.��ҵִ����ɣ�����ʱ�󱸶�����û�пɵ��õ���ҵ����ʱӦ�õȴ�, ѡ����������ȵ���Ķ��� 
//		//2.��ҵִ����ɣ���ʱ�󱸶����ֿ��Ե��õ���ҵ��ѡ����ҵ����ʱ����С����ҵ���� 
//		if (i > 0)
//		{
//			if (panduan(jobs, quantity))
//			{
//				//��ʱ������������ҵ��������С���ɡ� 
//				loc = findminjob(jobs, quantity);
//				jobs[loc].start_time = current_time;
//			}
//			else
//			{
//				//��ʱӦѡ�����ȵ������ҵ
//				loc = findrearlyjob(jobs, quantity);
//				jobs[loc].start_time = jobs[loc].reach_time;
//				current_time = jobs[loc].reach_time;
//			}
//		}
//		jobs[loc].wait_time = current_time - jobs[loc].reach_time;//�ȴ�ʱ��,��ҵ�ĵȴ�ʱ��͵��ڵ�ǰʱ���ȥ����ʱ��
//		printf("\t%-8d\t%-8d\t%-8d\t%-8d\t%-8d\n", loc + 1, jobs[loc].reach_time, jobs[loc].start_time, jobs[loc].wait_time,
//			jobs[loc].wait_time + jobs[loc].need_time);//��š���ҵ����ʱ�䡢����ʱ�䡢�ȴ�ʱ�����ҵ�ӵ��ﵽִ���������ʱ��
//		jobs[loc].visited = 1;//�Ѿ�������
//		current_time += jobs[loc].need_time;//��ǰʱ�����
//		total_waitime += jobs[loc].wait_time;//�ܹ��ȴ�ʱ�����
//		total_roundtime = total_roundtime + jobs[loc].wait_time + jobs[loc].need_time;//�ܹ���תʱ��
//		//��ȡʣ����ҵ�����������ҵ
//		jieshuyidaoda(jobs, current_time, quantity);
//	}
//	printf("�ܵȴ�ʱ��:%-8d ����תʱ��:%-8d\n", total_waitime, total_roundtime);
//	printf("ƽ���ȴ�ʱ��: %4.2f ƽ����תʱ��: %4.2f\n", (float)total_waitime / (quantity), (float)total_roundtime / (quantity));
//}
//
////����Ӧ�ȵ����㷨
//void HRRFschdulejob()
//{
//	int i;
//	int current_time = 0;
//	int loc;
//	loc = findrearlyjob(jobs, quantity);
//	current_time = jobs[loc].reach_time;
//	int total_waitime = 0;
//	int total_roundtime = 0;
//	//�����ҵ��
//	printf("\n\nHRRF�㷨��ҵ��\n");
//	printf("------------------------------------------------------------------------\n");
//	printf("\tjobID\treachtime\tstarttime\twaittime\troundtime\n");
//	//ÿ��ѭ���ҳ���Ӧ����ߵĲ���ӡ�����Ϣ
//	for (i = 0;i < quantity;i++)
//	{
//		//��Ϊ�������
//		//1.��ҵִ����ɣ�����ʱ�󱸶�����û�пɵ��õ���ҵ����ʱӦ�õȴ�, ѡ����������ȵ���Ķ��� 
//		//2.��ҵִ����ɣ���ʱ�󱸶����ֿ��Ե��õ���ҵ��ѡ����ҵ����Ӧ����ߵ���ҵ���� 
//		if (i > 0)
//		{
//			if (panduan(jobs, quantity))
//			{
//				//��ʱ������������ҵ��������С���ɡ� 
//				loc = findgaoxiangyingjob(jobs, quantity,current_time);
//				jobs[loc].start_time = current_time;
//			}
//			else
//			{
//				//��ʱӦѡ�����ȵ������ҵ
//				loc = findrearlyjob(jobs, quantity);
//				jobs[loc].start_time = jobs[loc].reach_time;
//				current_time = jobs[loc].reach_time;
//			}
//		}
//		jobs[loc].wait_time = current_time - jobs[loc].reach_time;//�ȴ�ʱ��,��ҵ�ĵȴ�ʱ��͵��ڵ�ǰʱ���ȥ����ʱ��
//		printf("\t%-8d\t%-8d\t%-8d\t%-8d\t%-8d\n", loc + 1, jobs[loc].reach_time, jobs[loc].start_time, jobs[loc].wait_time,
//			jobs[loc].wait_time + jobs[loc].need_time);//��š���ҵ����ʱ�䡢����ʱ�䡢�ȴ�ʱ�����ҵ�ӵ��ﵽִ���������ʱ��
//		jobs[loc].visited = 1;//�Ѿ�������
//		current_time += jobs[loc].need_time;//��ǰʱ�����
//		total_waitime += jobs[loc].wait_time;//�ܹ��ȴ�ʱ�����
//		total_roundtime = total_roundtime + jobs[loc].wait_time + jobs[loc].need_time;//�ܹ���תʱ��
//		//��ȡʣ����ҵ�����������ҵ
//		jieshuyidaoda(jobs, current_time, quantity);
//	}
//	printf("�ܵȴ�ʱ��:%-8d ����תʱ��:%-8d\n", total_waitime, total_roundtime);
//	printf("ƽ���ȴ�ʱ��: %4.2f ƽ����תʱ��: %4.2f\n", (float)total_waitime / (quantity), (float)total_roundtime / (quantity));
//}
//int fangaoyouxianquan(job jobs[], int count, int nowtime)
//{
//	double minjob = -1;//=jobs[0].need_time;
//	int minloc = -1;
//	int i = 0;
//	for (int i = 0;i < count;i++)
//	{
//		//�Ƚ�����Ȩ
//		if (jobs[i].isreached == true && jobs[i].visited == 0)
//		{
//			if (minloc == -1)
//			{
//				//�Ѿ�����
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
////����Ȩ�������ȵ����㷨
//void HPF(job jobs[])
//{
//	int i;
//	int current_time = 0;
//	int loc;
//	loc = findrearlyjob(jobs, quantity);
//	current_time = jobs[loc].reach_time;
//	int total_waitime = 0;
//	int total_roundtime = 0;
//	//�����ҵ��
//	printf("\n\nHPF�㷨��ҵ��\n");
//	printf("------------------------------------------------------------------------\n");
//	printf("\tjobID\treachtime\tstarttime\twaittime\troundtime\n");
//	//ÿ��ѭ���ҳ���Ӧ����ߵĲ���ӡ�����Ϣ
//	for (i = 0;i < quantity;i++)
//	{
//		//��Ϊ�������
//		//1.��ҵִ����ɣ�����ʱ�󱸶�����û�пɵ��õ���ҵ����ʱӦ�õȴ�, ѡ����������ȵ���Ķ��� 
//		//2.��ҵִ����ɣ���ʱ�󱸶����ֿ��Ե��õ���ҵ��ѡ������Ȩ��ߵ���ҵ���е��� 
//		if (i > 0)
//		{
//			if (panduan(jobs, quantity))
//			{
//				loc = fangaoyouxianquan(jobs, quantity, current_time);
//				jobs[loc].start_time = current_time;
//			}
//			else
//			{
//				//��ʱӦѡ�����ȵ������ҵ
//				loc = findrearlyjob(jobs, quantity);
//				jobs[loc].start_time = jobs[loc].reach_time;
//				current_time = jobs[loc].reach_time;
//			}
//		}
//		jobs[loc].wait_time = current_time - jobs[loc].reach_time;//�ȴ�ʱ��,��ҵ�ĵȴ�ʱ��͵��ڵ�ǰʱ���ȥ����ʱ��
//		printf("\t%-8d\t%-8d\t%-8d\t%-8d\t%-8d\n", loc + 1, jobs[loc].reach_time, jobs[loc].start_time, jobs[loc].wait_time,
//			jobs[loc].wait_time + jobs[loc].need_time);//��š���ҵ����ʱ�䡢����ʱ�䡢�ȴ�ʱ�����ҵ�ӵ��ﵽִ���������ʱ��
//		jobs[loc].visited = 1;//�Ѿ�������
//		current_time += jobs[loc].need_time;//��ǰʱ�����
//		total_waitime += jobs[loc].wait_time;//�ܹ��ȴ�ʱ�����
//		total_roundtime = total_roundtime + jobs[loc].wait_time + jobs[loc].need_time;//�ܹ���תʱ��
//		//��ȡʣ����ҵ�����������ҵ
//		jieshuyidaoda(jobs, current_time, quantity);
//	}
//	printf("�ܵȴ�ʱ��:%-8d ����תʱ��:%-8d\n", total_waitime, total_roundtime);
//	printf("ƽ���ȴ�ʱ��: %4.2f ƽ����תʱ��: %4.2f\n", (float)total_waitime / (quantity), (float)total_roundtime / (quantity));
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