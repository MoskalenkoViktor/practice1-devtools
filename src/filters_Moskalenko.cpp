#include "filters.hpp"

#include <assert.h>

class FiltersMoskalenko : public Filters
{
public:
   virtual void boxFilter(const Matrix &src, Matrix& dst, const int kSize = 3)
   {
	   for (int i = 0; i < src.rows(); i++){
		   for (int j = 0 ; j < src.cols(); j++){
			   int sum = 0;
			   for (int k = (-kSize/2 + i); k <= (kSize/2 + i); k++)
			   {
				   for (int l = (-kSize/2 + j); l <= (kSize/2 + j); l++)
				   {
					   int a = k, b = l;
					   if (a < 0) { a = -a; } ;
					   if (a >src.rows()-1) { a =2 * (src.rows()-1) - a; };
					   if (b < 0) { b = -b; } ;
					   if (b >src.cols()-1) { b =2 * (src.cols()-1) - b; };
					   assert(a >= 0);
					   assert(a < src.rows);
					   assert(b >= 0);
					   assert(b < src.cols);
					   sum += src[a][b];
				   }
			   }
			   dst[i][j] = sum/(kSize*kSize);
		   }
	   }
   }
   virtual void filter2d(const Matrix &src, Matrix& dst, const Matrix &kernel)
   { }
   virtual void median(const Matrix &src, Matrix &dst, const int kSize = 3)
   { }
   virtual void SobelOx(const Matrix &src, Matrix &dst)
   { }
};


Filters* createFiltersMoskalenko()
{
   Filters* filters = new FiltersMoskalenko();
   return filters;
}