#ifndef SORTTABLE_H_
#define SORTTABLE_H_
#include "TScanTable.h"

enum TSortMethod { INSERT_SORT, MERGE_SORT, QUIQ_SORT };
class  TSortTable : public TScanTable {
protected:
	TSortMethod SortMethod; // ����� ����������
	void SortData(void);   // ���������� ������
	void InsertSort(PTTabRecord *pMem, int DataCount); // ����� �������
	void MergeSort(PTTabRecord *pMem, int DataCount);  // ����� �������
	void MergeSorter(PTTabRecord * &pData, PTTabRecord * &pBuff, int Size);
	void MergeData(PTTabRecord *&pData, PTTabRecord *&pBuff, int n1, int n2);
	void QuiqSort(PTTabRecord *pMem, int DataCount); // ������� ����������
	void QuiqSplit(PTTabRecord *pData, int Size, int &Pivot);
public:
	TSortTable(int Size = TabMaxSize) : TScanTable(Size) { SortMethod = TSortMethod::QUIQ_SORT; };// �����������
	TSortTable(const TScanTable &tab); // �� ��������������� �������
	TSortTable & operator=(const TScanTable &tab); // ������������
	TSortMethod GetSortMethod(void);    // �������� ����� ����������
	void SetSortMethod(TSortMethod sm);// ���������� ����� ����������
									   // �������� ������
	virtual PTDatValue FindRecord(TKey k); // ����� ������
	virtual void InsRecord(TKey k, PTDatValue pVal); // ��������
	virtual void DelRecord(TKey k);        // ������� ������
};

#endif // SORTTABLE_H_