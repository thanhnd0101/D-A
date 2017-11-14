

typedef struct Header* HeaderRef;
struct Header
{
	int rowIndex;
	int colIndex;
	int value;
	HeaderRef right;
	HeaderRef down;
};


struct SparseTable
{
	HeaderRef row_col_List;
	int row, col;
};

HeaderRef findLastRow(SparseTable& table, int row);
HeaderRef findLastDownHeader(SparseTable& table);
HeaderRef findRightHeader(HeaderRef table, int col);
HeaderRef findDownHeader(HeaderRef table, int row);


HeaderRef getHeader(int rowIndex, int colIndex, int value);

void InitSparseTable(SparseTable& table);
void InitHeader(HeaderRef head);
void store(SparseTable& table);
void deleteSparseTable(SparseTable& table);