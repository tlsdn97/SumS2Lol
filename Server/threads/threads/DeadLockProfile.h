#pragma once
class DeadLockProfile
{
public:
	void PushLock(const char* name);
	void PopLock(const char* name);
	void CheckCycle();
	void DFS(int32 here);

private:
	Mutex _lock;

	unordered_map<const char*, int32> _nameToID;
	unordered_map<int32, const char*> _idToName;

	stack<int32> _lockStack;
	map<int32, set<int32 >> _lockHistory;

	// DFS
	vector<int> _discoveredOrder;
	int32 _discoveredCount = 0; 
	vector<bool> _finished;
	vector<int32> _parent;
};

