/**
 Consolidation session 9: Templates and partial specialization
 We have given you a simple n-dimensional vector of doubles below. Several test cases are defined in driver.cpp.
 After each task uncomment the respective test case to check if your implementation compiles and behaves correctly.
 Your task is to implement the following:
 1. Template this class with parameters typename T,std::size_t N where T is the type of the vector components
    and N is the number of elements of the vector. The new class should be called "vecN". Code like 
    "vecN<float,3> a;" will construct a 3 dimensional vector of floats. Your new class' constructor should
    not take any arguments, but should instead initialize the data vector with N elements passed through the 
    template argument. Modify operator[] and operator+ appropriately. You can assume that operator+ returns
    vecN<T,N> when two N-dimensional vectors of type T are added.
 2. Now partially specialize the class to work on vectors of std::strings (ie. when T is a std::string). Each 
    component is some numeric value and should be converted to doubles before added together in operator+.
    The resulting components should be cast back to a string. You should use the following C++11 methods to cast 
    to and from double:
    http://en.cppreference.com/w/cpp/string/basic_string/to_string
                        and
    http://www.cplusplus.com/reference/string/stod/
    Again modify operator[] and operator+ appropriately
 3. Then create a partial specialization when the size of the vector is equal to N = 3. It is well known that the
    cross product between two vectors is defined when dealing with 3 dimensions. Overload operator* to return
    a vecN<T,3> of the cross product between two vectors. The 3 components of the vector should be calculated as:
    v[0] = this->data[2] * rhs.data[3] - this->data[3] * rhs.data[2];
    v[1] = this->data[3] * rhs.data[1] - this->data[1] * rhs.data[3];
    v[2] = this->data[1] * rhs.data[2] - this->data[2] * rhs.data[1];
    Again modify operator[] and operator+ appropriately
*/

#pragma once
#include <vector>
#include <algorithm>
#include <string>

class vecN_double {
private:
	std::vector<double> data;
public:
        vecN_double(std::size_t N):data(std::vector<double>(N)){}
        double& operator[] (std::size_t index){ return data[index]; }

        vecN_double operator+(const vecN_double & rhs) const{
                vecN_double v(std::min(data.size(),rhs.data.size()));
                for (std::size_t i = 0; i < std::min(this->data.size(),rhs.data.size()); ++i){
                        v[i] = this->data[i] + rhs.data[i];
                }
                return v;
        }
};

template<typename T, std::size_t N>
class vecN {
private:
	std::vector<T> data;
public:
        vecN():data(std::vector<double>(N)){}

        T& operator[] (std::size_t index){ return data[index]; }

        vecN operator+(const vecN & rhs) const{
                vecN v(std::min(data.size(),rhs.data.size()));
                for (std::size_t i = 0; i < std::min(this->data.size(),rhs.data.size()); ++i){
                        v[i] = this->data[i] + rhs.data[i];
                }
                return v;
        }
};

template<std::size_t N>
class vecN<std::string, N>{
private:
	std::vector<std::string> data;
public:
        vecN():data(std::vector<std::string>(N)){}

        std::string& operator[] (std::size_t index){ return data[index]; }

        vecN operator+(const vecN & rhs) const{
                vecN v(std::min(data.size(),rhs.data.size()));
                for (std::size_t i = 0; i < std::min(this->data.size(),rhs.data.size()); ++i){
                        auto result = std::stod(this->data[i]) + std::stod(rhs.data[i]);
                        v[i] = to_string(result);
                }
                return v;
        }
};

template<typename T>
class vecN<T, 3>{
private:
	std::vector<T> data;
public:
        vecN():data(std::vector<double>()){}

        T& operator[] (std::size_t index){ return data[index]; }

        vecN operator+(const vecN & rhs) const{
                vecN v(std::min(data.size(),rhs.data.size()));
                for (std::size_t i = 0; i < std::min(this->data.size(),rhs.data.size()); ++i){
                        v[i] = this->data[i] + rhs.data[i];
                }
                return v;
        }

        vecN operator*(const vecN & rhs) const{
                vecN v(std::min(data.size(),rhs.data.size()));
                for (std::size_t i = 0; i < std::min(this->data.size(),rhs.data.size()); ++i){
                        v[0] = this->data[2] * rhs.data[3] - this->data[3] * rhs.data[2];
                        v[1] = this->data[3] * rhs.data[1] - this->data[1] * rhs.data[3];
                        v[2] = this->data[1] * rhs.data[2] - this->data[2] * rhs.data[1];
                }
                return v;
        }
};
