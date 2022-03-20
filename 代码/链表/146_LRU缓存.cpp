//���ǰ�����ʹ�õļ�ֵ�Է��ڵ�������ͷ�� 
//�������²����(put)��get���������ͷ��
//�����Ļ�һ����������,ֱ��ɾ��β���ļ�ֵ��
//����ʹ������unordered_map,�����Զ����� 
//�÷����޷�ʵ�ֵĹؼ�����unordered_mapԪ���޷���ȡ����β��Ԫ�� 
class LRUCache{
private:
	unordered_map<int,int> myMap;
	int cap;
public:
	LRUCache(int capacity):cap(capacity){}
	
	int get(int key)
	{
		unordered_map<int,int>::iterator it=myMap.find(key);
		int result= it->second; //resultΪ�ҵ���ֵ 
		myMap.erase(key); //ɾ����ֵ�Ժ��ٲ����ײ� 
		myMap.insert(pair<int,int>(key,result)); //���°������ֵ�Բ���ͷ�� 
		return result;
	}
	
	void put(int key,int value)
	{
		if(myMap.size()>cap)//�����������
		{
			//vectorʹ��back()������ȡ���һ��Ԫ��
			//mapʹ��rebgin()������ȡ���һ��Ԫ�� 
			//unordered_map�޷���O(1)��ʱ�临�ӶȻ�ȡ���һ��Ԫ��,ֻ�ܴ�ǰ�������
			unordered_map<int,int>::iterator it=myMap.begin();
			int cnt=0;
			for(;it!=myMap.end();++it)cnt++;
			for(int i=1;i<cnt;i++)
			{
				it++;
			}
			myMap.erase(it); //ɾ��β��Ԫ��xxxxx 
		} 
		myMap.insert(pair<int,int>(key,value));//���¼�ֵ�Բ���ͷ�� 
	}
};


//����һ:��������д˫������,����˫������list
//����ʹ�ù�ϣ��ump���ж�λ���ҳ���������˫������cache�е�λ��,������ƶ���˫�������ͷ���� 
//list����
//unordered_map���� 
//�㷨:���շ��ʵļ�ֵ��ɾ��������ײ�,��β��������ɵļ�ֵ��,ɾ��Ҳ��ɾ�������ֵ�� 
//֪ʶ��:unordered_map����(count��erase��back�Ⱥ���)
//list����(push_front��pop_back�Ⱥ���) 
class LRUCache{
private:
	//listΪ˫������,ά�����˳�� 
	list<pair<int,int> > cache; //list��ά����һ������capacity��Ҫɾ���Ľ��˳�� 
	//ump�ĵ�һ�����ݱ�ʾ��key,�ڶ������ݱ�ʾָ��cache�м�Ϊkey�����ݶ�pair�ĵ����� 
	unordered_map<int,list<pair<int,int> >::iterator> hash; //unordered_map�Ĵ���������O(1)�Ĳ���
	int cap; //cache���������

public:
	LRUCache(int capacity):cap(capacity){}
	
	//��ȡ��key��Ӧ��valֵ 
	int get(int key)
	{
		if(hash.find(key)==hash.end()) //��������ڼ�key
		{
			return -1;
		} 
		//������ڼ�key
		auto key_value=*hash[key]; //���ؼ�key��Ӧ�ļ�ֵ�� 
		int result=key_value.second; //result��ʾ��key��Ӧ��valֵ 
		
		cache.erase(hash[key]); //����ֵ��keyɾ��
		cache.push_front(key_value); //�ٽ�����շ��ʵļ�ֵ�Է��������ײ�
		hash[key]=cache.begin(); //����hash�ĵ�����
		
		return result; 
	}
	
	void put(int key,int val)
	{
		pair<int,int> newPair=make_pair(key,val); //������ֵ�� 
		if(hash.count(key))//����ý���Ѿ�����,��ɾ���ɽ��
		{
			cache.erase(hash[key]);
		} 
		else
		{
			if(cache.size()==cap) //���cache����
			{
				//ɾ�����ڲ��õļ�ֵ��(cache�����һ����ֵ��) 
				//��ɾhash�еļ�ֵ��
				//cache.back()��ʾ��������һ�����Զ�Ӧ�ĵ����� 
				//cache.back().first��ʾ��������һ�����Եļ�ֵkey 
				hash.erase(cache.back().first); //hash.erase(key)ɾ����Ϊkey�ļ�ֵ�� 
				cache.pop_back(); //��ɾ����cache�еļ�ֵ�� 
			} 
		}
		
		//���½�����cache��ͷ��
		cache.push_front(newPair);
		hash[key]=cache.begin(); //�½�ӳ�� 
	} 
};



//������:��д˫������
//˫������֪ʶ�� 
struct DLinkedNode{
	int key,value;
	DLinkedNode* prev; //ǰ��ָ����
	DLinkedNode* next; //���ָ����
	DLinkedNode():key(0),value(0),prev(NULL),next(NULL){}
	DLinkedNode(int _key,int _value):key(_key),value(_value),prev(NULL),next(NULL){} 
};

class LRUCache{
private:
	//ע��:����Ĺ�ϣ��洢��ֵ��˫������Ľ��,����ָ����ĵ����� 
	unordered_map<int,DLinkedNode*> hash; //��ϣ��,��Ϊ˫������ļ�,ֵΪ��Ӧ��˫��������ĵ�����
	DLinkedNode* head; //˫�������αͷ�� 
	DLinkedNode* tail; //˫�������αβ��(αͷ����αβ����Ŀ���Ƿ������ɾ��) 
	int size; //ʵ�ʽ���� 
	int capacity; //���� 
	
public:
	LRUCache(int _capacity):capacity(_capacity),size(0){
		//��ʼ��αͷ����αβ��
		head=new DLinkedNode();
		tail=new DLinkedNode();
		head->next=tail;
		tail->prev=head; 
	}
	
	int get(int key)
	{
		if(hash.count(key)==0) //��������ڸü�ֵ�� 
		{
			return -1;
		}
		//���key����,��ͨ����ϣ��hash���ж�λ,��ȡ˫�������е���Ӧ���,���Ƶ�ͷ��
		DLinkedNode* node=hash[key];
		moveToHead(node); 
		return node->value;
	}
	
	void put(int key,int value)
	{
		if(hash.count(key)==0) //���key������,����һ���µĽ�� 
		{
			DLinkedNode* newNode=new DLinkedNode(key,value);
			//����������ӽ�˫�������ͷ��
			addToHead(newNode);
			//������������ϣ��
			hash[key]=newNode;
			size++; //ʵ�ʽ����+1
			if(size>capacity)
			{
				//�����������,ɾ��˫�������β�����
				DLinkedNode* removed=removeTail(); //ɾ��β������ͬʱ��ȡ�ý�� 
				//ͬʱɾ����ϣ���ж�Ӧ����
				hash.erase(removed->key); //����ɾ�����ļ�ֵɾ����ϣ���ж�Ӧ����
				//�ֶ�ɾ��,��ֹ�ڴ�й¶ 
				delete removed;
				size--; 
			} 
		}
		else //���key����,��ͨ����ϣ��λ,���޸�value,���ƶ���ͷ�� 
		{
			DLinkedNode* node=hash[key];
			node->value=value;
			moveToHead(node);
		}
	}
	
	//����½��node��˫������ͷ�� 
	void addToHead(DLinkedNode* node)
	{
		node->prev=head;
		node->next=head->next;
		head->next->prev=node;
		head->next=node;
	}
	
	//ɾ�����node
	void removeNode(DLinkedNode* node)
	{
		node->prev->next=node->next;
		node->next->prev=node->prev;
	} 
	
	//�ƶ����node��˫��ͷ��
	 void moveToHead(DLinkedNode* node)
	 {
		removeNode(node);
		addToHead(node);
	 }
	 
	 //ɾ��β����� 
	 DLinkedNode* removeTail()
	 {
		DLinkedNode* node=tail->prev;
		removeNode(node);
		return node;
	 }
};
