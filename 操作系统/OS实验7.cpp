//#include<iostream>
//#include<vector>
//using namespace std;
//#define FREE 0
//#define  BUSY 1
//#define  MAX_length 640
//int alloc(int tag);//�ڴ����
//int free(int ID);//�ڴ����
//int first_fit(int ID, int size);//�״���Ӧ�㷨
//int best_fit(int ID, int size);//�����Ӧ�㷨
//void show();//�鿴����
//void init();//��ʼ��
//typedef struct freeArea//���ȶ���������ֱ�ṹ
//{
//	int flag;//ռ�� or free
//	int size;//������ռ�Ĵ�С
//	int ID;//����ID
//	int address;//��������ʵ��ַ
//}Elemtype;
//typedef struct Free_Node
//{
//	Elemtype date;
//	struct Free_Node* front;//ָ��ǰһ������
//	struct Free_Node* next;//ָ���һ������
//}Free_Node, *FNodeList;
//FNodeList block_first;
//FNodeList block_last;
//void init()//�Կ��з���������г�ʼ��
//{
//	block_first = new Free_Node;
//	block_last = new Free_Node;
//	block_first->front = NULL;//��һ��λ����ǰ����
//	block_first->next = block_last;
//	block_last->date.size = 0;
//	block_last->front = block_first;
//	block_last->next = NULL;//���һ��λ���޺����
//	block_last->date.address = 0;//��ʼ�����������ַΪ0
//	block_last->date.flag = FREE;
//	block_last->date.ID = FREE;
//	block_last->date.size = MAX_length;//��ʼʱ���СΪ���ֵ
//}
////ʵ���ڴ����
//int alloc(int tag,int ID,int size1)
//{
//	if (ID <= 0 || size1 <= 0)
//	{
//		cout << "���������������ȷ��ID�������С��" << endl;
//		return 0;
//	}
//	if (tag == 1)//�����״���Ӧ�㷨
//	{
//		if (first_fit(ID, size1))
//		{
//			cout << "����ɹ���" << endl;
//		}
//		else cout << "����ʧ�ܣ�" << endl;
//		return 1;
//	}
//	else
//	{
//		if (best_fit(ID, size1))
//		{
//			cout << "����ɹ���" << endl;
//		}
//		else cout << "����ʧ�ܣ�" << endl;
//		return 1;
//	}
//}
//int first_fit(int ID, int size)//�״���Ӧ�㷨
//{
//	FNodeList temp = (FNodeList)malloc(sizeof(Free_Node));//������һ��ָ��,��ָ��ָ��һ��free_node���
//	Free_Node* p = block_first->next;//ÿ�δ�ͷ��ʼ����ɨ��
//	temp->date.ID = ID;//��temp��ָ��Ľ������Խ��и�ֵ
//	temp->date.size = size;
//	temp->date.flag = BUSY;
//	while (p)
//	{
//		if (p->date.flag == FREE && p->date.size == size)//�����С�պ�����
//		{
//			p->date.flag = BUSY;
//			p->date.ID = ID;
//			show();
//			return 1;//����ɹ�
//			break;
//		}
//		if (p->date.flag == FREE && p->date.size > size)//˵�����������Ŀ�������
//		{
//			temp->next = p;
//			temp->front = p->front;
//			temp->date.address = p->date.address;//temp��ָ����ʼ��ַ����ԭp��ָ����ʼ��ַ
//			p->front->next = temp;
//			p->front = temp;
//			p->date.address = temp->date.address + temp->date.size;
//			p->date.size -= size;
//			show();
//			return 1;
//			break;
//		}
//		p = p->next;//�Ҳ������ʴ�С�������ķ�������p=p->next��������Ѱ��ֱ��ΪNULL��
//	}
//	show();
//	return 0;
//}
//void show()//չʾ�ڴ�������
//{
//	cout << "*******�ڴ�������*******" << endl;
//	Free_Node* p = block_first->next;//��ͷ��ʼ
//	while (p)
//	{
//		cout << "�����ţ�";
//		if (p->date.ID == FREE)
//			cout << "FREE" << endl;
//		else cout << p->date.ID << endl;
//		cout << "��ʼ��ַ��" << p->date.address << endl;
//		cout << "�ڴ��С��" << p->date.size << endl;
//		cout << "����״̬��";
//		if (p->date.flag == FREE)
//			cout << "����" << endl;
//		else
//			cout << "�ѷ���" << endl;
//		cout << "**************************" << endl;
//		p = p->next;
//	}
//}
//int free(int ID)//�ڴ����
//{
//	Free_Node* p = block_first->next;
//	while (p)
//	{
//		if (p->date.ID == ID)//�ҵ�Ҫ���յ�ID����
//		{
//			p->date.flag = FREE;
//			p->date.ID = FREE;
//			//�ж�P��ǰ�������ϵ,���ǰ����ߺ���Ϊfree������ǰ������кϲ�
//			if (p->front->date.flag == FREE && p->next->date.flag != FREE)
//			{
//				p->front->date.size += p->date.size;
//				p->front->next = p->next;
//				p->next->front = p->front;
//			}
//			if (p->front->date.flag != FREE && p->next->date.flag == FREE)
//			{
//				p->date.size += p->next->date.size;
//				if (p->next->next)//����ýڵ�����½ڵ���Ȼ����
//				{
//					p->next->next->front = p;
//					p->next = p->next->next;
//				}
//				else p->next = p->next->next;
//			}
//			if (p->front->date.flag == FREE && p->next->date.flag == FREE)
//			{
//				p->front->date.size += p->date.size + p->next->date.size;
//				if (p->next->next)
//				{
//					p->next->next->front = p->front;
//					p->front->next = p->next->next;
//				}
//				else p->front->next = p->next->next;
//			}
//			show();
//			break;
//		}
//		p = p->next;//δ�ҵ������ɨ�������һ��
//	}
//	cout << "���ճɹ���" << endl;
//	return 1;
//}
//int best_fit(int ID, int size)//�����Ӧ�㷨
////������Ŀ��з������մ�С�����˳��������򣬽����������ڴ�Ĵ�С���бȽϣ��ҵ���һ����������С���ڴ��
//{
//	int surplus;//��¼�����ڴ��������ڴ�Ĳ�ֵ
//	FNodeList temp = (FNodeList)malloc(sizeof(Free_Node));
//	Free_Node* p = block_first->next;
//	temp->date.ID = ID;
//	temp->date.size = size;
//	temp->date.flag = BUSY;
//	Free_Node* q = NULL;//��¼���λ��
//	while (p)//���������ҵ���һ�����õĿ������佫�丳ֵ��q
//	{
//		if (p->date.flag == FREE && p->date.size >= size)
//		{
//			q = p;
//			surplus = p->date.size - size;//����֮��Ĳ�ֵ
//			break;
//		}
//		p = p->next;//����ô����������������������һ��λ��
//	}
//	while (p)//�����������ҵ����Ӻ��ʵ�λ��
//	{
//		if (p->date.flag == FREE && p->date.size == size)
//		{
//			//����ҵ���С��������ģ�������ԥֱ�Ӹ�ֵ��break��
//			p->date.flag = BUSY;
//			p->date.ID = ID;
//			show();
//			return 1;
//			break;
//		}
//		if (p->date.flag == FREE && p->date.size > size)
//		{
//			//������бȽϣ��ҵ���ֵ��С��
//			if (surplus > p->date.size - size)
//			{
//				surplus = p->date.size - size;
//				q = p;
//			}
//		}
//		p = p->next;
//	}
//	if (q == NULL)//���û���ҵ�λ��
//	{
//		return 0;
//	}
//	else//�ҵ������λ��
//	{
//		//���������ǡ����������Ҫ���ÿ������ֳ����飬һ��ָ���ҵ��һ�����Ϊ��Ƭ������Ϊfree
//		temp->next = q;
//		temp->front = q->front;
//		temp->date.address = q->date.address;
//		q->front->next = temp;
//		q->front = temp;
//		q->date.size = surplus;
//		q->date.address += size;
//		show();
//		return 1;
//	}
//}
//int main()
//{
//	cout << "\t��̬������ʽ��ģ��\t" << endl;
//	init();
//	while (1)
//	{
//		int n;
//		bool exit = false;
//		cout << "********��ѡ��Ҫ���еĲ���*******" << endl;
//		cout << "\t1:�״���Ӧ�㷨\t" << endl;
//		cout << "\t2:�����Ӧ�㷨\t" << endl;
//		cout << "\t3:�ڴ����\t" << endl;
//		//cout << "\t4:��ʾ�ڴ�״��\t" << endl;
//		cout << "\t4:�˳�\t" << endl;
//		cin >> n;
//		int zuoyehao;
//		int daxiao;
//		char ch;
//		switch (n)
//		{
//		case 1:
//		FLAG:
//			cout << "��������ҵ��" << endl;
//			cin >> zuoyehao;
//			cout << "�������ڴ��С" << endl;
//			cin >> daxiao;
//			alloc(1, zuoyehao, daxiao);
//			cout << "�Ƿ����(Y or N)" << endl;
//			cin >> ch;
//			if (ch == 'N' || ch == 'n')
//			{
//				break;
//			}
//			else
//			{
//				goto FLAG;
//			}
//		case 2:
//		FLAG2:
//			cout << "��������ҵ��" << endl;
//			cin >> zuoyehao;
//			cout << "�������ڴ��С" << endl;
//			cin >> daxiao;
//			alloc(2, zuoyehao, daxiao);
//			cout << "�Ƿ����(Y or N)" << endl;
//			cin >> ch;
//			if (ch == 'N' || ch == 'n')
//			{
//				break;
//			}
//			else
//			{
//				goto FLAG2;
//			}
//			break;
//		case 3:
//		FLAG1:
//			cout << "������Ҫɾ����ҵ��ID" << endl;
//			int ID;
//			cin >> ID;
//			free(ID);
//			cout << "�Ƿ����(Y or N)" << endl;
//			cin >> ch;
//			if (ch == 'N' || ch == 'n')
//			{
//				break;
//			}
//			else
//			{
//				goto FLAG1;
//			}
//			break;
//		case 4:
//			exit = true;
//			break;
//		}
//		if (exit == true)
//		{
//			break;
//		}
//	}
//	return 0;
//}
