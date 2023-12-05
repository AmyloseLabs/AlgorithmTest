/********************************************************
 ** @file : RangeSum.hpp
 ** @author : Amylose <amyloselabs@naver.com>
 ** @date : 2023-12-05
 ** @version : 1.0.0
********************************************************/
#ifndef RANGESUM_H
#define RANGESUM_H

//////////////////////////////////////////////////////////
//// SECTION : Standard Header Includes
//////////////////////////////////////////////////////////
#include <vector>

//////////////////////////////////////////////////////////
//// SECTION : User Defined Header Includes
//////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////
//// SECTION : Class/Structure Forward Declarations
//////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////
//// SECTION : Enumurate Class Defines
//////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////
//// SECTION : Class Defines
//////////////////////////////////////////////////////////
class RangeSum {
//////////////////////////////////////////////////////////
//// SECTION : Class Public Method Declarations
////////////////////////////////////////////////////////// 
public:
    //! Method Only Class
    


/********************************************************/
/*             Method for 1D Array/Vector               */
/********************************************************/
    /**
     * @brief Create a Sum Array 1D object
     * 
     * @tparam Typ_ Type template
     * @param a_arrSum[out] : (Typ_[]) array object to store sum data.
     * @param a_szArrSum[in] : (size_t) array size to store sum data.
     * @param a_arrOri[in] : (const Typ_[]) data array object.
     * @param a_szArrOri[in] : (const size_t) data array object size.
     */
    template<typename Typ_>
    static void createSumArray1D(Typ_ a_arrSum[], size_t a_szArrSum, const Typ_ a_arrOri[], const size_t a_szArrOri)
    {
        if ((a_arrSum != 0u) and (a_szArrSum == a_szArrOri)) {
            a_arrSum[0] = a_arrOri[0];
            for(auto idx = 1u; idx < a_szArrSum; ++idx) {
                a_arrSum[idx] = a_arrSum[idx - 1u] + a_arrOri[idx];
            }
        }
    }

    /**
     * @brief Create a Sum Array 1D object (overload)
     * 
     * @tparam Typ_ Type template
     * @param a_vSum[out] : (std::vector<Typ_> &) vector object to store sum data.
     * @param a_vData[in] : (const std::vector<Typ_> &) data vector object.
     */
    template<typename Typ_>
    static void createSumArray1D(std::vector<Typ_> &a_vSum, const std::vector<Typ_> &a_vData)
    {
        a_vSum.clear();
        auto szData = a_vData.size();
        if (!a_vData.empty()) {
            a_vSum.emplace_back(a_vData[0]);
            if (szData > 1u) {
                for (auto idx = 1u; idx < szData; ++idx) {
                    auto sums = a_vSum[idx - 1u] + a_vData[idx];
                    a_vSum.emplace_back(sums);
                }
            }
        }
    }

    /**
     * @brief Get the sum result from 1D Array object and range
     * 
     * @tparam Typ_ Type template
     * @param a_arrSum[in] : (const Typ_[]) array object to store sum data.
     * @param a_szArrSum[in] : (const size_t) array size to store sum data.
     * @param a_begin[in] : (size_t) Array address start location to obtain a sum result
     * @param a_end[in] (size_t) The end position of the array address to obtain the sum result
     * @return (Typ_) the sum result for the range
     */
    template<typename Typ_>
    static Typ_ getRangeSum1D(const Typ_ a_arrSum[], const size_t a_szArrSum, size_t a_begin, size_t a_end)
    {
        Typ_ sumValue = 0;
        if ((a_szArrSum != 0u) and (a_szArrSum > a_end) and (a_end >= a_begin))
        {
            if (a_begin == 0u)
            {
                sumValue = a_arrSum[a_end];
            }
            else
            {
                sumValue = a_arrSum[a_end] - a_arrSum[a_begin - 1u];
            }
        }

        return sumValue;
    }


    /**
     * @brief Get the sum result from 1D Array object and range (overload)
     * 
     * @tparam Typ_  Type template
     * @param a_vSum : (const std::vector<Typ_> &) vector object that stored sum data.
     * @param a_begin[in] : (size_t) The start position of the array address to obtain a sum result
     * @param a_end[in] : (size_t) The end position of the array address to obtain the sum result
     * @return (Typ_) the sum result for the range
     */
    template<typename Typ_>
    static Typ_ getRangeSum1D(const std::vector<Typ_> &a_vSum, size_t a_begin, size_t a_end)
    {
        Typ_ sumValue = 0;
        auto szSumArr = a_vSum.size();
        if ((szSumArr != 0u) and (szSumArr > a_end) and (a_end >= a_begin))
        {
            if (a_begin == 0u)
            {
                sumValue = a_vSum[a_end];
            }
            else
            {
                sumValue = a_vSum[a_end] - a_vSum[a_begin - 1u];
            }
        }
        return sumValue;
    }

/********************************************************/
/*             Method for 2D Vector Only                */
/********************************************************/
    
    /**
     * @brief Create a Sum Vector Array 2D object
     * 
     * @tparam Typ_ Type template
     * @param a_vSum[out] : (std::vector<std::vector<Typ_>> &) vector object to store sum data.
     * @param a_vData[in] : (const std::vector<std::vector<Typ_>> &) data vector object.
     * @warning This method assumes that the number of elements in all j directions is the same.
     */
    template<typename Typ_>
    static void createSumArray2D(std::vector<std::vector<Typ_>> &a_vSum,
                                 const std::vector<std::vector<Typ_>> &a_vData)
    {
        if ( (!a_vData.empty()) and (!a_vData[0u].empty())) {
            auto szDataArrDir_I = a_vData.size();
            auto szDataArrDir_J = a_vData[0].size();

            a_vSum.resize(szDataArrDir_I);
            for (auto &vSumDir_I : a_vSum) {
                vSumDir_I.resize(szDataArrDir_J);
            }

            a_vSum[0][0] = a_vData[0][0];

            for (auto dir_i = 1u; dir_i < szDataArrDir_I; ++dir_i) {
                a_vSum[dir_i][0] = a_vSum[dir_i - 1u][0] + a_vData[dir_i][0];
            }

            for (auto dir_j = 1u; dir_j < szDataArrDir_J; ++dir_j) {
                a_vSum[0][dir_j] = a_vSum[0][dir_j - 1u] + a_vData[0][dir_j];
            }

            for (auto idx_i = 1u; idx_i < szDataArrDir_I; ++idx_i) {
                for (auto idx_j = 1u; idx_j < szDataArrDir_J; ++idx_j) {
                    a_vSum[idx_i][idx_j] = a_vSum[idx_i - 1u][idx_j]
                                         + a_vSum[idx_i][idx_j - 1u]
                                         - a_vSum[idx_i - 1u][idx_j - 1u]
                                         + a_vData[idx_i][idx_j];
                }
            }
        }
    }


    /**
     * @brief Get the sum result from 2D Array object and range
     * 
     * @tparam Typ_ Typ_ Type template
     * @param a_vSum[in] : (const std::vector<std::vector<Typ_>> &) vector object that stored sum data.
     * @param a_beginI[in] : (size_t) The "I-Dir" start position of the array address to obtain a sum result 
     * @param a_beginJ[in] : (size_t) The "J-Dir" start position of the array address to obtain a sum result 
     * @param a_endI[in] : (size_t) The "I-Dir" end position of the array address to obtain the sum result
     * @param a_endJ[in] : (size_t) The "J-Dir" end position of the array address to obtain the sum result
     * @return (Typ_) the sum result for the range
     * @warning This method assumes that the number of elements in all j directions is the same.
     */
    template<typename Typ_>
    static Typ_ getRangeSum2D(const std::vector<std::vector<Typ_>> &a_vSum,
                              size_t a_beginI, size_t a_beginJ,
                              size_t a_endI, size_t a_endJ)
    {
        Typ_ sumValue = 0;
        Typ_ dupl_i0 = 0;
        Typ_ dupl_j0 = 0;
        Typ_ dupl_ij0 = 0;

        if ((a_beginI != 0u) and (a_beginJ != 0))
        {
            dupl_i0 = a_vSum[a_beginI - 1u][a_endJ];
            dupl_j0 = a_vSum[a_endI][a_beginJ - 1u];
            dupl_ij0 = a_vSum[a_beginI - 1u][a_beginJ - 1u];

            
        }
        else
        {
            dupl_ij0 = 0;
            if (a_beginI == 0) {
                dupl_i0 = 0;
            }
            else {
                dupl_j0 = 0;
            }
        }
        sumValue = a_vSum[a_endI][a_endJ] - dupl_i0 - dupl_j0 + dupl_ij0;
        return sumValue;
    }

//////////////////////////////////////////////////////////
//// SECTION : Class Private Method Declarations
////////////////////////////////////////////////////////// 
private:

//////////////////////////////////////////////////////////
//// SECTION : Class Private Variables Decl
//////////////////////////////////////////////////////////
private:

};

#endif