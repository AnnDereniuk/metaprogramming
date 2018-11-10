
#include <iostream> 
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;

template <int N, int I> class Exponenta {
public:
	static inline float exponenta()
	{
		return ExpSum<N, I, 38, 1>::sum();
	}
};

template<int N, int I, int J, int K>
class ExpSum {
public:
	enum { go = (K + 1 != J) };
	static inline float sum() {
		return 1 + ((float)I / N) / K*ExpSum<N*go, I*go, J*go, (K + 1)*go>::sum();
	}
};

template <> class ExpSum<0, 0, 0, 0>
{
public:
	static inline float sum() {
		return 0;
	}
};

template <int N, int I>  class ArcCos {
public:
	static inline float acos()
	{
		float x = Exponenta<N, I>::exponenta();
		return (M_PI / 2. - x*ArcCosSum<N, I, 38, 0>::sum());
	}
};

template <int N, int I, int J, int K> class ArcCosSum {
public:
	enum { go = (K + 2 != 2 * J) };
	static inline float sum() {
		float x = Exponenta<N, I>::exponenta();
		return ((float)1 / (K + 1) - x*x*(K + 1) / (K + 2)*ArcCosSum < N*go, I*go, J*go, (K + 2)*go>::sum());
	}
};

template <> class ArcCosSum <0, 0, 0, 0> {
public:
	static inline float sum()
	{
		return 0;
	}
};


template <int N, int I>  class Sin {
public:
	static inline double sin()
	{
		float x = ArcCos<N, I>::acos();
		return (x*SineSum<N, I, 38, 0>::sum());
	}
};

template <int N, int I, int J, int K> class SineSum {
public:
	enum { go = (K + 1 != J) };
	static inline double sum() {
		float x = ArcCos<N, I>::acos();
		return 1 - x*x / (2 * K + 2) / (2 * K + 3)*SineSum < N*go, I*go, J*go, (K + 1)*go>::sum();
	}
};

template <> class SineSum <0, 0, 0, 0> {
public:
	static inline double sum()
	{
		return 1;
	}
};


template <int N, int I>  class Cos {
public:
	static inline double cos()
	{

		return CosineSum<N, I, 38, 0>::sum();
	}
};

template <int N, int I, int J, int K> class CosineSum {
public:
	enum { go = (K + 1 != J) };
	static inline double sum() {
		float x = Sin<N, I>::sin();
		return 1 - x*x / (2 * K + 1) / (2 * K + 2)*CosineSum < N*go, I*go, J*go, (K + 1)*go>::sum();
	}
};

template <> class CosineSum <0, 0, 0, 0> {
public:
	static inline double sum()
	{
		return 1;
	}
};



template <int N, int I>  class Logarithm {
public:
	static inline double ln()
	{
		float x = Cos<N, I>::cos() - 1;
		return (x*LogarithmSum<N, I, 38, 1>::sum());
	}
};

template <int N, int I, int J, int K> class LogarithmSum {
public:
	enum { go = (K != J + 1) };
	static inline float sum() {
		float x = Cos<N, I>::cos() - 1;
		return ((float)1 * go / K - x*LogarithmSum < N*go, I*go, J*go, (K + 1)*go>::sum());
	}
};

template <> class LogarithmSum <0, 0, 0, 0> {
public:
	static inline float sum()
	{
		return 0;
	}
};


int main()
{
	float a = Logarithm<-2, 1>::ln();
	cout << "Metaprogram:      "<< a << endl;
	float b = log(cos(sin(acos(exp(-0.5)))));
	cout << "Standard program: "<< b << endl;
	cout << "Error:             "<<abs(a-b)<<endl;
	system("pause");
	return 0;
}

