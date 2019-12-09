#ifndef MATRIX_H
#define MATRIX_H
#include<iostream>
#include<ostream>
#include<istream>
using namespace std;
template<typename T>
class Matrix
{
	int rows, cols;
	T**data;
public:
	Matrix()
	{
		rows = 0;
		cols = 0;
		data = nullptr;
	}
	Matrix(int r, int c)
	{
		rows = r;
		cols = c;
		data = new T*[rows];
		for (int i = 0; i < rows; i = i + 1)
		{
			data[i] = new T[cols];
		}
	}
	Matrix(const Matrix & ref)
	{
		if (!ref.data)
		{
			data = nullptr;
			rows = 0;
			cols = 0;
		}
		cols = ref.cols;
		rows = ref.rows;
		data = new T*[rows];
		for (int i = 0; i < rows; i = i + 1)
		{
			data[i] = new T[cols];
		}
		for (int i = 0; i < rows; i = i + 1)
		{
			for (int j = 0; j < cols; j = j + 1)
			{
				data[i][j] = ref.data[i][j];
			}
		}
	}

	Matrix&operator=(const Matrix & ref)
	{
		if (this == &ref)
		{
			return *this;
		}
		this->~Matrix();
		if (!ref.data)
		{
			data = nullptr;
			rows = 0;
			cols = 0;
			return *this;
		}
		cols = ref.cols;
		rows = ref.rows;
		data = new T*[rows];
		for (int i = 0; i < rows; i = i + 1)
		{
			data[i] = new T[cols];
			for (int j = 0; j < cols; j = j + 1)
			{
				data[i][j] = ref.data[i][j];
			}
		}
		return *this;
	}

	~Matrix()
	{
		rows = 0;
		cols = 0;
		if (!data)
		{
			return;
		}
		for (int i = 0; i < rows; i = i + 1)
		{
			delete[]data[i];
		}
		delete[]data;
		data = nullptr;
	}
	T& at(int r, int c)
	{
		if (r >= 0 && r < rows && c >= 0 && c < cols)
		{
			return data[r][c];
		}
		exit(0);
	}

	const T&at(int r, int c)const
	{
		if (r >= 0 && r < rows && c >= 0 && c < cols)
		{
			return data[r][c];
		}
		exit(0);
	}

	T& operator()(int r, int c)
	{
		if (r >= 0 && r < rows && c >= 0 && c < cols)
		{
			return data[r][c];
		}
		exit(0);
	}
	int getRows()const
	{
		return rows;
	}
	int getColumns()const
	{
		return cols;
	}
	void display()const
	{
		int i, j;
		for (i = 0; i < rows; i = i + 1)
		{
			for (j = 0; j < cols; j = j + 1)
			{
				cout << data[i][j] << " ";
			}
			cout << '\n';
		}
	}

	void input()
	{
		for (int i = 0; i < rows; i = i + 1)
		{
			for (int j = 0; j < cols; j = j + 1)
			{
				cin >> this->at(i, j);
			}
		}
	}

	Matrix Transpose()const
	{
		Matrix tr(cols, rows);
		for (int i = 0; i < rows; i = i + 1)
		{
			for (int j = 0; j < cols; j = j + 1)
			{
				tr.data[j][i] = data[i][j];
			}
		}
		return tr;
	}
	Matrix add(const Matrix & b)const
	{
		Matrix add1(rows, cols);
		if (b.rows != rows || b.cols != cols)
		{
			exit(0);
		}
		for (int i = 0; i < rows; i = i + 1)
		{
			for (int j = 0; j < cols; j = j + 1)
			{
				add1.data[i][j] = data[i][j] + b.data[i][j];
			}
		}
		add1.display();
		return add1;
	}
	Matrix operator+(const Matrix & b)const
	{
		Matrix add1(rows, cols);
		if (b.rows != rows || b.cols != cols)
		{
			exit(0);
		}
		for (int i = 0; i < rows; i = i + 1)
		{
			for (int j = 0; j < cols; j = j + 1)
			{
				add1.data[i][j] = data[i][j] + b.data[i][j];
			}
		}
		return add1;
	}

	Matrix multiply(const Matrix & b)const
	{
		if (cols != b.rows)
		{
			exit(0);
		}
		Matrix multi(rows, b.cols);
		for (int i = 0; i < multi.rows; i = i + 1)
		{
			for (int j = 0; j < multi.cols; j = j + 1)
			{
				multi.data[i][j] = 0;
				for (int k = 0; k < cols; k = k + 1)
				{
					multi.data[i][j] = multi.data[i][j] + (data[i][k] * b.data[k][j]);
				}
			}
		}
		return multi;
	}
	void reSize(int newRow, int newCol)
	{
		Matrix*p =new Matrix(newRow, newCol);
		int tempRow, tempCol;
		if (newRow <= rows)
		{
			tempRow = newRow;
		}
		else
		{
			tempRow = rows;
		}
		if (newCol <= cols)
		{
			tempCol = newCol;
		}
		else
		{
			tempCol = cols;
		}
		for (int i = 0; i < tempRow; i = i + 1)
		{
			for (int j = 0; j < tempCol; j = j + 1)
			{
				p->data[i][j] = data[i][j];
			}
		}
		this->~Matrix();
		rows = newRow;
		cols = newCol;
		data = p->data;
	}
	template<typename T>
	friend ostream& operator<<(ostream&, const Matrix<T>&ref);
	template<typename T>
	friend istream& operator>>(istream&, Matrix<T>&ref);
};

template<typename T>
 ostream& operator<<(ostream&c, const Matrix<T>&ref)
{
	ref.display();
	return c;
}

template<typename T>
istream& operator>>(istream&c, Matrix<T>&ref)
{
	ref.input();
	return c;
}

#endif



