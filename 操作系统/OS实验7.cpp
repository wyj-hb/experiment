//#include<iostream>
//#include<vector>
//using namespace std;
//#define FREE 0
//#define  BUSY 1
//#define  MAX_length 640
//int alloc(int tag);//内存分配
//int free(int ID);//内存回收
//int first_fit(int ID, int size);//首次适应算法
//int best_fit(int ID, int size);//最佳适应算法
//void show();//查看分配
//void init();//初始化
//typedef struct freeArea//首先定义空闲区分表结构
//{
//	int flag;//占用 or free
//	int size;//分区所占的大小
//	int ID;//分区ID
//	int address;//分区的其实地址
//}Elemtype;
//typedef struct Free_Node
//{
//	Elemtype date;
//	struct Free_Node* front;//指向前一个分区
//	struct Free_Node* next;//指向后一个分区
//}Free_Node, *FNodeList;
//FNodeList block_first;
//FNodeList block_last;
//void init()//对空闲分区链表进行初始化
//{
//	block_first = new Free_Node;
//	block_last = new Free_Node;
//	block_first->front = NULL;//第一个位置无前分区
//	block_first->next = block_last;
//	block_last->date.size = 0;
//	block_last->front = block_first;
//	block_last->next = NULL;//最后一个位置无后分区
//	block_last->date.address = 0;//初始化令其分区地址为0
//	block_last->date.flag = FREE;
//	block_last->date.ID = FREE;
//	block_last->date.size = MAX_length;//初始时其大小为最大值
//}
////实现内存分配
//int alloc(int tag,int ID,int size1)
//{
//	if (ID <= 0 || size1 <= 0)
//	{
//		cout << "输入错误！请输入正确的ID和请求大小：" << endl;
//		return 0;
//	}
//	if (tag == 1)//采用首次适应算法
//	{
//		if (first_fit(ID, size1))
//		{
//			cout << "分配成功！" << endl;
//		}
//		else cout << "分配失败！" << endl;
//		return 1;
//	}
//	else
//	{
//		if (best_fit(ID, size1))
//		{
//			cout << "分配成功！" << endl;
//		}
//		else cout << "分配失败！" << endl;
//		return 1;
//	}
//}
//int first_fit(int ID, int size)//首次适应算法
//{
//	FNodeList temp = (FNodeList)malloc(sizeof(Free_Node));//定义了一个指针,该指针指向一个free_node结点
//	Free_Node* p = block_first->next;//每次从头开始进行扫描
//	temp->date.ID = ID;//对temp所指向的结点的属性进行赋值
//	temp->date.size = size;
//	temp->date.flag = BUSY;
//	while (p)
//	{
//		if (p->date.flag == FREE && p->date.size == size)//请求大小刚好满足
//		{
//			p->date.flag = BUSY;
//			p->date.ID = ID;
//			show();
//			return 1;//分配成功
//			break;
//		}
//		if (p->date.flag == FREE && p->date.size > size)//说明还有其他的空闲区间
//		{
//			temp->next = p;
//			temp->front = p->front;
//			temp->date.address = p->date.address;//temp所指的起始地址等于原p所指的起始地址
//			p->front->next = temp;
//			p->front = temp;
//			p->date.address = temp->date.address + temp->date.size;
//			p->date.size -= size;
//			show();
//			return 1;
//			break;
//		}
//		p = p->next;//找不到合适大小或条件的分区，令p=p->next，继续搜寻，直到为NULL。
//	}
//	show();
//	return 0;
//}
//void show()//展示内存分区情况
//{
//	cout << "*******内存分配情况*******" << endl;
//	Free_Node* p = block_first->next;//从头开始
//	while (p)
//	{
//		cout << "分区号：";
//		if (p->date.ID == FREE)
//			cout << "FREE" << endl;
//		else cout << p->date.ID << endl;
//		cout << "起始地址：" << p->date.address << endl;
//		cout << "内存大小：" << p->date.size << endl;
//		cout << "分区状态：";
//		if (p->date.flag == FREE)
//			cout << "空闲" << endl;
//		else
//			cout << "已分配" << endl;
//		cout << "**************************" << endl;
//		p = p->next;
//	}
//}
//int free(int ID)//内存回收
//{
//	Free_Node* p = block_first->next;
//	while (p)
//	{
//		if (p->date.ID == ID)//找到要回收的ID区域
//		{
//			p->date.flag = FREE;
//			p->date.ID = FREE;
//			//判断P与前后区域关系,如果前域或者后域为free则将其与前后域进行合并
//			if (p->front->date.flag == FREE && p->next->date.flag != FREE)
//			{
//				p->front->date.size += p->date.size;
//				p->front->next = p->next;
//				p->next->front = p->front;
//			}
//			if (p->front->date.flag != FREE && p->next->date.flag == FREE)
//			{
//				p->date.size += p->next->date.size;
//				if (p->next->next)//如果该节点的下下节点依然存在
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
//		p = p->next;//未找到则继续扫描查找下一块
//	}
//	cout << "回收成功！" << endl;
//	return 1;
//}
//int best_fit(int ID, int size)//最佳适应算法
////将链表的空闲分区按照从小到大的顺序进行排序，接着与所需内存的大小进行比较，找到第一个满足分配大小的内存块
//{
//	int surplus;//记录可用内存与需求内存的差值
//	FNodeList temp = (FNodeList)malloc(sizeof(Free_Node));
//	Free_Node* p = block_first->next;
//	temp->date.ID = ID;
//	temp->date.size = size;
//	temp->date.flag = BUSY;
//	Free_Node* q = NULL;//记录最佳位置
//	while (p)//遍历链表，找到第一个可用的空闲区间将其赋值给q
//	{
//		if (p->date.flag == FREE && p->date.size >= size)
//		{
//			q = p;
//			surplus = p->date.size - size;//二者之间的差值
//			break;
//		}
//		p = p->next;//如果该处不满足条件则查找它的下一处位置
//	}
//	while (p)//继续遍历，找到更加合适的位置
//	{
//		if (p->date.flag == FREE && p->date.size == size)
//		{
//			//如果找到大小正好满足的，不用犹豫直接赋值，break。
//			p->date.flag = BUSY;
//			p->date.ID = ID;
//			show();
//			return 1;
//			break;
//		}
//		if (p->date.flag == FREE && p->date.size > size)
//		{
//			//否则进行比较，找到差值较小的
//			if (surplus > p->date.size - size)
//			{
//				surplus = p->date.size - size;
//				q = p;
//			}
//		}
//		p = p->next;
//	}
//	if (q == NULL)//如果没有找到位置
//	{
//		return 0;
//	}
//	else//找到了最佳位置
//	{
//		//如果并不是恰好满足则需要将该空闲区分成两块，一块分给作业另一块则成为碎片，并且为free
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
//	cout << "\t动态分区方式的模拟\t" << endl;
//	init();
//	while (1)
//	{
//		int n;
//		bool exit = false;
//		cout << "********请选择要进行的操作*******" << endl;
//		cout << "\t1:首次适应算法\t" << endl;
//		cout << "\t2:最佳适应算法\t" << endl;
//		cout << "\t3:内存回收\t" << endl;
//		//cout << "\t4:显示内存状况\t" << endl;
//		cout << "\t4:退出\t" << endl;
//		cin >> n;
//		int zuoyehao;
//		int daxiao;
//		char ch;
//		switch (n)
//		{
//		case 1:
//		FLAG:
//			cout << "请输入作业号" << endl;
//			cin >> zuoyehao;
//			cout << "请输入内存大小" << endl;
//			cin >> daxiao;
//			alloc(1, zuoyehao, daxiao);
//			cout << "是否继续(Y or N)" << endl;
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
//			cout << "请输入作业号" << endl;
//			cin >> zuoyehao;
//			cout << "请输入内存大小" << endl;
//			cin >> daxiao;
//			alloc(2, zuoyehao, daxiao);
//			cout << "是否继续(Y or N)" << endl;
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
//			cout << "请输入要删除作业的ID" << endl;
//			int ID;
//			cin >> ID;
//			free(ID);
//			cout << "是否继续(Y or N)" << endl;
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
