

class UF {
public:
	UF(int N) {
		count = N;
		id = new int[N];
		weight = new int[N];
		for (int i = 0; i < N; i++) {
			id[i] = i;
			weight[i] = 0;
		}
	}
	~UF() {
		delete []id;
		delete []weight;
	}
	void unionP(int p, int q) {
		int i = root(p);
		int j = root(q);
		if (i == j) {
			return;
		}
		if (weight[i] < weight[j]) {
			id[i] = j;
		}
		else if (weight[i] > weight[j]) {
			id[j] = i;
		}
		else {
			id[i] = j;
			weight[j]++;
		}
		count--;
	}
	bool connected(int p, int q) {
		return root(p) == root(q);
	}
	int getCount() {
		return count;
	}
private:
	int *id;
	int *weight;
	int count;
	int root(int i) {
		while (i != id[i]) {
			id[i] = id[id[i]];
			i = id[i];
		}
		return i;
	}
};

class QuickFindUF {
private:
	int *id;
	int size;
public:
	QuickFindUF(int N) : size(N) {
		id = new int[N];
		for (int i = 0; i < N; i++) {
			id[i] = i;
		}
	}
	bool connected(int p, int q) {
		return id[p] == id[q];
	}
	void unionP(int p, int q) {
		int pid = id[p];
		int qid = id[q];
		for (int i = 0; i < size; i++) {
			if (id[i] == pid) {
				id[i] = qid;
			}
		}
	}
};

class QuickUnionUF {
public:
	QuickUnionUF(int N) : size(N) {
		id = new int[size];
		for (int i = 0; i < size; i++) {
			id[i] = i;
		}
	}
	bool connected(int p, int q) {
		return root(p) == root(q);
	}
	void unionP(int p, int q) {
		int i = root(p);
		int j = root(q);
		id[i] = j;
	}
private:
	int root(int i) {
		while (i != id[i]) {
			i = id[i];
		}
		return i;
	}

	int *id;
	int size;
};

class WeightedQuickUnionUF {
public:
	WeightedQuickUnionUF(int N) {
		id = new int[N];
		weight = new int[N];
		for (int i = 0; i < N; i++) {
			id[i] = i;
			weight[i] = 1;
		}
	}
	bool connected(int p, int q) {
		return root(p) == root(q);
	}
	void unionP(int p, int q) {
		int i = root(p);
		int j = root(q);
		if (i == j) {
			return;
		}
		if (weight[i] < weight[j]) {
			id[i] = j;
			weight[j] += weight[i];
		}
		else {
			id[j] = id[i];
			weight[i] += weight[j];
		}
	}
private:
	int root(int i) {
		while (i != id[i]) {
			i = id[i];
		}
		return i;
	}

	int *id;
	int *weight;
};

class WeightedQuickUnionUFWithPathCompression {
public:
	WeightedQuickUnionUFWithPathCompression(int N) {
		id = new int[N];
		weight = new int[N];
		for (int i = 0; i < N; i++) {
			id[i] = i;
			weight[i] = 1;
		}
	}
	bool connected(int p, int q) {
		return root(p) == root(q);
	}
	void unionP(int p, int q) {
		int i = root(p);
		int j = root(q);
		if (i == j) {
			return;
		}
		if (weight[i] < weight[j]) {
			id[i] = j;
			weight[j] += weight[i];
		}
		else {
			id[j] = id[i];
			weight[i] += weight[j];
		}
	}
private:
	int root(int i) {
		while (i != id[i]) {
			id[i] = id[id[i]];
			i = id[i];
		}
		return i;
	}

	int *id;
	int *weight;
};