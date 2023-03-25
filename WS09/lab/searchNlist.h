#ifndef SDDS_SEARCHNLIST_H_
#define SDDS_SEARCHNLIST_H_
namespace sdds {
    //search
    template<typename vr, typename nzr>
    bool search(Collection<vr>& C,
                vr* A, int size, nzr key)
                {
        bool res = false;
        for (int n = 0; n < size; n++)
        {
            if (A[n] == key)
            {
                C.add(A[n]);
                res = true;
            }
        }
        return res;
    }
    //listArrayElements
    template<typename tl>
    void listArrayElements(const char* Title, tl* A,
                           int size)
                           {
        std::cout << Title << std::endl;
        for (int n = 0; n < size; n++)

        {
            std::cout << n + 1 << ": " << A[n] << std::endl;
        }
    }
}
#endif