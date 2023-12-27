//This header file contains the class for the merge sort algorithm
#include "APVECTOR.H"

//class used for merge sort
class MERGESORT{
private:
    apvector <int> mergeList;
    void recursiveSort(apvector <int> &v, int i1, int i2, ALLEGRO_FONT *font, ALLEGRO_FONT *font2, int &comparisons, int &moves);
    void Merge(apvector <int> &v, int i1, int m, int i2, ALLEGRO_FONT *font, ALLEGRO_FONT *font2, int &comparisons, int &moves);
public:
    MERGESORT();
    ~MERGESORT(){}
    void Sort(apvector<int> &v, ALLEGRO_FONT *font, ALLEGRO_FONT *font2, int &comparisons, int &moves);
};
