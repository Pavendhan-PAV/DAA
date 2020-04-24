class sort

{
	private:
    public:
	void bubblesort(int a[],int size);
	void insertsort(int a[],int size);
	void merge2(int a[],int start,int mid,int end,int size);
	void merge3(int a[],int start,int mid1,int mid2,int end,int size);
	void mergesort2(int a[],int start,int end,int size);
	void mergesort3(int a[],int start,int end,int size);
	void selectsort(int a[],int size);
	int swap(int *p,int *q);
	void quicksort(int a[],int start,int end);
	int qsindex(int a[],int start,int end);


};
