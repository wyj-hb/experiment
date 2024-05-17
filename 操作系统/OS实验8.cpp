//#include<iostream>
//#include<vector>
//using namespace std;
//#define VM_PAGE 7      //ҳ�����Ϊ7
//#define PM_PAGE 4         //�������ҵ���ڴ����Ϊ4,��ʾ����ͬʱפ�����ڴ��е�����������4��
//#define TOTAL_INSERT 18  //ҳ����ʴ���СΪ18
//typedef struct
//{
//	int vmn;//ҳ��
//	int pmn;//������
//	int exist;//�Ƿ����ڴ���
//	int time;//��ͬ���㷨���岻ͬ.
//	//��opt����ʵ�����壬��LRU��timeΪ������ʵ�ʱ�䡣����ҳÿ����һ�Σ�time��Ϊ��ǰ����ʱ�̣���̭ҳ��ʱ����̭timeֵ��С�ģ������û�б�ʹ�õġ�
//	//��FIFO�㷨�У�timeΪ����ҳ�����ڴ��ʱ�䡣ֻ�е�����ҳ���������ڴ�ʱ�����øñ�־����̭ҳ��ʱ����̭timeֵ��С�ģ�����������ڴ����ҳ��Ҳ����פ��ʱ�����
//}vpage_item;//ҳ���һ�����ݣ�����
//vpage_item page_table[VM_PAGE];
//vpage_item* ppage_bitmap[PM_PAGE];//�ô���ֵΪNULL����������ҳ��δ��ռ�ã������ʾ����ռ�ø�����ҳ����ҳ
//int vpage_arr[TOTAL_INSERT] = { 1,2,3,4,2,6,2,1,2,3,7,6,3,2,1,2,3,6 };//ҳ����ʴ�
//int arr[7][1];
//void init_data() //���ݳ�ʼ��
//{
//	for (int i = 0; i < VM_PAGE; i++)
//	{
//		page_table[i].vmn = i + 1;  //��ҳ��
//		page_table[i].pmn = -1;    //ʵҳ��
//		page_table[i].exist = 0;
//		page_table[i].time = -1;
//	}
//	for (int i = 0; i < PM_PAGE; i++) /*���4�������Ϊ��*/
//	{
//		ppage_bitmap[i] = NULL;
//	}
//}
////FIFO�û��㷨
////�㷨˼��:��������̭��Щפ�����ڴ�ʱ�����ҳ��
//void FIFO()
//{
//	int k = 0;//��ǰ�Ѿ�ʹ���˵��������
//	int i;
//	int sum = 0;//��ʾ�Ѿ����ʹ��Ĺ��Ĵ�������ʼֵΪ0
//	int missing_page_count = 0;//ȱҳ��
//	int current_time = 0;//��ǰʱ������Ϊ0
//	bool isleft = true;   /*��ǰ��������Ƿ���ʣ��*/
//	while (sum < TOTAL_INSERT)
//	{
//		if (page_table[vpage_arr[sum] - 1].exist == 0)//�����ǰҪ���õ�ҳ�沢�����ڴ��еĻ�
//		//��һ����ΪΪ��ҳ����i�Ĳ�ֵΪ1
//		{
//			missing_page_count++;//ȱҳ����1
//			if (k < 4)//��ʱ����Ҫ�滻���п��е������
//			{
//				if (ppage_bitmap[k] == NULL) /*�ҵ�һ�����������*/
//				{
//					ppage_bitmap[k] = &page_table[vpage_arr[sum] - 1];//�����ڴ�
//					ppage_bitmap[k]->exist = 1;//����
//					ppage_bitmap[k]->pmn = k;
//					ppage_bitmap[k]->time = current_time;//ʱ���¼Ϊ��ǰʱ��
//					k++;
//				}
//			}
//			else
//			{
//				//��ʱ��Ҫ�����㷨������ǰʱ����С��ҳ��
//				int temp = ppage_bitmap[0]->time;	/*��¼���������ҵ���絽��ʱ��*/
//				int j = 0;                 /*��¼Ӧ�����滻��������*/
//				for (i = 0; i < PM_PAGE; i++)//������ǰ�����������
//				{
//					if (ppage_bitmap[i]->time < temp)
//					{
//						temp = ppage_bitmap[i]->time;
//						j = i;
//					}
//				}
//				ppage_bitmap[j]->exist = 0;
//				ppage_bitmap[j] = &page_table[vpage_arr[sum] - 1];      /*����ҳ����*/
//				ppage_bitmap[j]->exist = 1;
//				ppage_bitmap[j]->pmn = j;//������Ϊ
//				ppage_bitmap[j]->time = current_time;
//			}
//		}
//		current_time++;//ʱ��+1
//		sum++;//�����ҳ������1
//	}
//	printf("FIFO�㷨ȱҳ����Ϊ:%d\tȱҳ��Ϊ:%f\t�û�����Ϊ:%d\t�û���Ϊ:%f", missing_page_count, missing_page_count / (float)TOTAL_INSERT, missing_page_count - 4, (missing_page_count - 4) / (float)TOTAL_INSERT);
//}
////LRU�㷨
////������δʹ�õ�ҳ�棨���һ��ʱ���ڣ����ٱ����ʵ�ҳ�棩������̭��
//void LRU()
//{
//	int k = 0;//��ǰ�Ѿ�ʹ���˵��������
//	int i;
//	int sum = 0;//��ʾ�Ѿ����ʹ��Ĺ��Ĵ�������ʼֵΪ0
//	int missing_page_count = 0;//ȱҳ��
//	int current_time = 0;//��ǰʱ������Ϊ0
//	bool isleft = true;   /*��ǰ��������Ƿ���ʣ��*/
//	while (sum < TOTAL_INSERT)
//	{
//		if (page_table[vpage_arr[sum] - 1].exist == 0)//�����ǰҪ���õ�ҳ�沢�����ڴ��еĻ�
//		//��һ����ΪΪ��ҳ����i�Ĳ�ֵΪ1
//		{
//			missing_page_count++;//ȱҳ����1
//			if (k < 4)//��ʱ����Ҫ�滻���п��е������
//			{
//				if (ppage_bitmap[k] == NULL) /*�ҵ�һ�����������*/
//				{
//					ppage_bitmap[k] = &page_table[vpage_arr[sum] - 1];//�����ڴ�
//					ppage_bitmap[k]->exist = 1;//����
//					ppage_bitmap[k]->pmn = k;
//					ppage_bitmap[k]->time = current_time;//ʱ���¼Ϊ��ǰʱ��
//					k++;
//					arr[vpage_arr[sum] - 1][0] == current_time;
//				}
//			}
//			else
//			{
//				//��ʱѡ���������δʹ�õ�ҳ��������̭
//				int temp = arr[ppage_bitmap[0]->vmn-1][0];	/*��¼���������ҵ���δʹ�õĿ��*/
//				int j = 0;                 /*��¼Ӧ�����滻��������*/
//				for (i = 0; i < PM_PAGE; i++)//������ǰ�����������
//				{
//					if (arr[ppage_bitmap[i]->vmn][0] < temp)
//					{
//						temp = arr[ppage_bitmap[i]->vmn-1][0];
//						j = i;
//					}
//				}
//				ppage_bitmap[j]->exist = 0;
//				ppage_bitmap[j] = &page_table[vpage_arr[sum] - 1];      /*����ҳ����*/
//				ppage_bitmap[j]->exist = 1;
//				ppage_bitmap[j]->pmn = j;//������Ϊ
//				ppage_bitmap[j]->time = current_time;
//				arr[vpage_arr[sum] - 1][0] == current_time;
//			}
//		}
//		else
//		{
//			arr[vpage_arr[sum] - 1][0] == current_time;
//		}
//		current_time++;//ʱ��+1
//		sum++;//�����ҳ������1
//	}
//	printf("LRU�㷨ȱҳ����Ϊ:%d\tȱҳ��Ϊ:%f\t�û�����Ϊ:%d\t�û���Ϊ:%f", missing_page_count, missing_page_count / 
//		(float)TOTAL_INSERT, missing_page_count - 4, (missing_page_count - 4) / (float)TOTAL_INSERT);
//}
//int weizhi(int i,int x)
//{
//	//i�ǵ�ǰλ��
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
////����û��㷨������ѡ��ı���̭ҳ�潫���Ժ�����ʹ�õģ������ڽ����ܳ�ʱ���ڲ��ٱ����ʵ�ҳ��
//void OPT()
//{
//	int k = 0;//��ǰ�Ѿ�ʹ���˵��������
//	int i;
//	int sum = 0;//��ʾ�Ѿ����ʹ��Ĺ��Ĵ�������ʼֵΪ0
//	int missing_page_count = 0;//ȱҳ��
//	int current_time = 0;//��ǰʱ������Ϊ0
//	bool isleft = true;   /*��ǰ��������Ƿ���ʣ��*/
//	while (sum < TOTAL_INSERT)
//	{
//		if (page_table[vpage_arr[sum] - 1].exist == 0)//�����ǰҪ���õ�ҳ�沢�����ڴ��еĻ�
//		//��һ����ΪΪ��ҳ����i�Ĳ�ֵΪ1
//		{
//			missing_page_count++;//ȱҳ����1
//			if (k < 4)//��ʱ����Ҫ�滻���п��е������
//			{
//				if (ppage_bitmap[k] == NULL) /*�ҵ�һ�����������*/
//				{
//					ppage_bitmap[k] = &page_table[vpage_arr[sum] - 1];//�����ڴ�
//					ppage_bitmap[k]->exist = 1;//����
//					ppage_bitmap[k]->pmn = k;
//					ppage_bitmap[k]->time = current_time;//ʱ���¼Ϊ��ǰʱ��
//					k++;
//					arr[vpage_arr[sum] - 1][0] == current_time;
//				}
//			}
//			else
//			{
//				//��ʱѡ�����ò���ʹ�û�������ʹ�õ�
//				int temp = weizhi(sum, vpage_arr[sum]);
//				int j = 0;                 /*��¼Ӧ�����滻��������*/
//				for (i = 0; i < PM_PAGE; i++)//������ǰ�����������
//				{
//					int a = weizhi(sum, ppage_bitmap[i]->vmn);
//					if (a > temp)
//					{
//						temp = a;
//						j = i;
//					}
//				}
//				ppage_bitmap[j]->exist = 0;
//				ppage_bitmap[j] = &page_table[vpage_arr[sum] - 1];      /*����ҳ����*/
//				ppage_bitmap[j]->exist = 1;
//				ppage_bitmap[j]->pmn = j;//������Ϊ
//				ppage_bitmap[j]->time = current_time;
//			}
//		}
//		current_time++;//ʱ��+1
//		sum++;//�����ҳ������1
//	}
//	printf("OPT�㷨ȱҳ����Ϊ:%d\tȱҳ��Ϊ:%f\t�û�����Ϊ:%d\t�û���Ϊ:%f", missing_page_count, missing_page_count /
//		(float)TOTAL_INSERT, missing_page_count - 4, (missing_page_count - 4) / (float)TOTAL_INSERT);
//}
//int main()
//{
//	int a;
//	for (int i = 0;i < 7;i++)//��ʼ��
//	{
//		arr[i][0] = INT_MAX;
//	}
//	char ch;
//FLAG2:
//	printf("��������Ҫѡ���ҳ���û��㷨��1.FIFO\t2.LRU\t3.OPT\t����0����\n");
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
//	cout << "�Ƿ����(Y or N)" << endl;
//	cin >> ch;
//	if (ch == 'Y' || ch == 'y')
//	{
//		goto FLAG2;
//	}
//	return 0;
//}