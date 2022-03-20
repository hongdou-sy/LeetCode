//我们把最新使用的键值对放在迭代器的头部 
//无论是新插入的(put)、get都将其放在头部
//这样的话一旦超过容量,直接删除尾部的键值对
//可以使用容器unordered_map,不会自动排序 
//该方法无法实现的关键在于unordered_map元素无法获取它的尾部元素 
class LRUCache{
private:
	unordered_map<int,int> myMap;
	int cap;
public:
	LRUCache(int capacity):cap(capacity){}
	
	int get(int key)
	{
		unordered_map<int,int>::iterator it=myMap.find(key);
		int result= it->second; //result为找到的值 
		myMap.erase(key); //删除键值对后再插入首部 
		myMap.insert(pair<int,int>(key,result)); //重新把这个键值对插入头部 
		return result;
	}
	
	void put(int key,int value)
	{
		if(myMap.size()>cap)//如果容量超了
		{
			//vector使用back()函数获取最后一个元素
			//map使用rebgin()函数获取最后一个元素 
			//unordered_map无法以O(1)的时间复杂度获取最后一个元素,只能从前往后遍历
			unordered_map<int,int>::iterator it=myMap.begin();
			int cnt=0;
			for(;it!=myMap.end();++it)cnt++;
			for(int i=1;i<cnt;i++)
			{
				it++;
			}
			myMap.erase(it); //删除尾部元素xxxxx 
		} 
		myMap.insert(pair<int,int>(key,value));//将新键值对插入头部 
	}
};


//方法一:不用亲自写双向链表,利用双向链表list
//首先使用哈希表ump进行定位，找出缓存项在双向链表cache中的位置,随后将其移动到双向链表的头部。 
//list容器
//unordered_map容器 
//算法:将刚访问的键值对删除后放在首部,则尾部就是最旧的键值对,删除也是删的这个键值对 
//知识点:unordered_map容器(count、erase、back等函数)
//list容器(push_front、pop_back等函数) 
class LRUCache{
private:
	//list为双向链表,维护结点顺序 
	list<pair<int,int> > cache; //list中维护了一个超过capacity需要删除的结点顺序 
	//ump的第一个数据表示键key,第二个数据表示指向cache中键为key的数据对pair的迭代器 
	unordered_map<int,list<pair<int,int> >::iterator> hash; //unordered_map的存在满足了O(1)的查找
	int cap; //cache的最大容量

public:
	LRUCache(int capacity):cap(capacity){}
	
	//获取键key对应的val值 
	int get(int key)
	{
		if(hash.find(key)==hash.end()) //如果不存在键key
		{
			return -1;
		} 
		//如果存在键key
		auto key_value=*hash[key]; //返回键key对应的键值对 
		int result=key_value.second; //result表示键key对应的val值 
		
		cache.erase(hash[key]); //将键值对key删除
		cache.push_front(key_value); //再将这个刚访问的键值对放入容器首部
		hash[key]=cache.begin(); //更新hash的迭代器
		
		return result; 
	}
	
	void put(int key,int val)
	{
		pair<int,int> newPair=make_pair(key,val); //创建键值对 
		if(hash.count(key))//如果该结点已经存在,则删除旧结点
		{
			cache.erase(hash[key]);
		} 
		else
		{
			if(cache.size()==cap) //如果cache已满
			{
				//删除长期不用的键值对(cache的最后一个键值对) 
				//先删hash中的键值对
				//cache.back()表示链表的最后一个结点对对应的迭代器 
				//cache.back().first表示链表的最后一个结点对的键值key 
				hash.erase(cache.back().first); //hash.erase(key)删除键为key的键值对 
				cache.pop_back(); //再删链表cache中的键值对 
			} 
		}
		
		//将新结点插入cache的头部
		cache.push_front(newPair);
		hash[key]=cache.begin(); //新建映射 
	} 
};



//方法二:手写双向链表
//双向链表知识点 
struct DLinkedNode{
	int key,value;
	DLinkedNode* prev; //前驱指针域
	DLinkedNode* next; //后继指针域
	DLinkedNode():key(0),value(0),prev(NULL),next(NULL){}
	DLinkedNode(int _key,int _value):key(_key),value(_value),prev(NULL),next(NULL){} 
};

class LRUCache{
private:
	//注意:这里的哈希表存储的值是双向链表的结点,而非指向结点的迭代器 
	unordered_map<int,DLinkedNode*> hash; //哈希表,键为双向链表的键,值为相应的双向链表结点的迭代器
	DLinkedNode* head; //双向链表的伪头部 
	DLinkedNode* tail; //双向链表的伪尾部(伪头部和伪尾部的目的是方便进行删除) 
	int size; //实际结点数 
	int capacity; //容量 
	
public:
	LRUCache(int _capacity):capacity(_capacity),size(0){
		//初始化伪头部和伪尾部
		head=new DLinkedNode();
		tail=new DLinkedNode();
		head->next=tail;
		tail->prev=head; 
	}
	
	int get(int key)
	{
		if(hash.count(key)==0) //如果不存在该键值对 
		{
			return -1;
		}
		//如果key存在,先通过哈希表hash进行定位,获取双向链表中的相应结点,再移到头部
		DLinkedNode* node=hash[key];
		moveToHead(node); 
		return node->value;
	}
	
	void put(int key,int value)
	{
		if(hash.count(key)==0) //如果key不存在,创建一个新的结点 
		{
			DLinkedNode* newNode=new DLinkedNode(key,value);
			//将这个结点添加进双向链表的头部
			addToHead(newNode);
			//将该项添加入哈希表
			hash[key]=newNode;
			size++; //实际结点数+1
			if(size>capacity)
			{
				//如果超出容量,删除双向链表的尾部结点
				DLinkedNode* removed=removeTail(); //删除尾部结点的同时获取该结点 
				//同时删除哈希表中对应的项
				hash.erase(removed->key); //根据删除结点的键值删除哈希表中对应的项
				//手动删除,防止内存泄露 
				delete removed;
				size--; 
			} 
		}
		else //如果key存在,先通过哈希表定位,再修改value,并移动到头部 
		{
			DLinkedNode* node=hash[key];
			node->value=value;
			moveToHead(node);
		}
	}
	
	//添加新结点node到双向链表头部 
	void addToHead(DLinkedNode* node)
	{
		node->prev=head;
		node->next=head->next;
		head->next->prev=node;
		head->next=node;
	}
	
	//删除结点node
	void removeNode(DLinkedNode* node)
	{
		node->prev->next=node->next;
		node->next->prev=node->prev;
	} 
	
	//移动结点node到双向头部
	 void moveToHead(DLinkedNode* node)
	 {
		removeNode(node);
		addToHead(node);
	 }
	 
	 //删除尾部结点 
	 DLinkedNode* removeTail()
	 {
		DLinkedNode* node=tail->prev;
		removeNode(node);
		return node;
	 }
};
