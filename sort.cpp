#include <iostream>
#include <string> // The string class: pg 131
#include <vector> // The vector class: pg 1012

#include "sort.hpp"

using std::string;
using std::vector;


template <typename T> void sort(T *a, T *aux, int lo, int hi);
template <typename T> void sort(vector<T> &a, T *aux, int lo, int hi);

template <typename T> void merge(T *a, T *aux, int lo, int mid, int hi);
template <typename T> void merge(vector<T> &a, T* aux, int lo, int mid, int hi);

//Recursive Mergesort
//Pointer
template <typename T>
void recursive_mergesort(T *a, long int n)
{
    T *aux = (T*) std::malloc(n*sizeof(T));
    if(aux == NULL){
        //UH OH MALLOC FAILED
    }
    else{
        if (n<=42){
            insertion_sort(a,n);
        }
        else{
            sort(a, aux, 0, n-1);
        }
    }
}
//Vector
template <typename T>
void recursive_mergesort(vector<T> &a)
{
    T *aux = (T*) std::malloc(a.size()*sizeof(T));
    if(aux == NULL){
        //UH OH MALLOC FAILED
    }
    else{
        if (a.size()<=42){
            insertion_sort(a);
        }
        else{
            sort(a, aux, 0, a.size()-1);
        }
    }
}

//Sort helper function for Recursive Mergesort
//Pointer version
template <typename T> // template, typename: pg 419
void sort(T *a, T *aux, int lo, int hi)
{
	if (hi<= lo){
        return;
    }
	int mid = lo + (hi-lo) / 2;
	sort(a, aux, lo, mid);
	sort(a, aux, mid+1, hi);
	merge(a, aux, lo, mid, hi);
}

//Vector Version
template <typename T> // template, typename: pg 419
void sort(vector<T> &a, T *aux, int lo, int hi)
{
	if (hi<= lo){
        return;
    }
	int mid = lo + (hi-lo) / 2;
	sort(a, aux, lo, mid);
	sort(a, aux, mid+1, hi);
	merge(a, aux, lo, mid, hi);
}


//Iterative Mergesort - pointer version
template <typename T>
void iterative_mergesort(T *a, long int n)
{
    if (n<=0){
        return;
    }
    
    T *aux = (T*) std::malloc(n*sizeof(T));

    if (n<=0){
        return;
    }
    
    if(aux == NULL){
        //UH OH MALLOC FAILED
    }
    else{
        
    for (int sz = 1; sz <n; sz = sz+sz){
        for (int lo = 0; lo < n-sz; lo+=(sz+sz)){
            if ((lo+sz+sz-1)<=(n-1)){
                int hi = (lo+sz+sz-1);
                merge(a, aux, lo, lo+sz-1, hi);
            }
            else{
                int hi = n-1;
                merge(a, aux, lo, lo+sz-1, hi);
            }
        }
    }
    }
}

//Vector Version
template <typename T>
void iterative_mergesort(vector<T> &a)
{
    
    T *aux = (T*) std::malloc(a.size()*sizeof(T));
    
    if(aux == NULL){
        //UH OH MALLOC FAILED
    }
    else{

    for (int sz = 1; sz <a.size(); sz = sz+sz){
        for (int lo = 0; lo < a.size()-sz; lo+=(sz+sz)){
            if ((lo+sz+sz-1)<=(a.size()-1)){
                int hi = (lo+sz+sz-1);
                merge(a, aux, lo, lo+sz-1, hi);
            }
            else{
                int hi = a.size()-1;
                merge(a, aux, lo, lo+sz-1, hi);
            }
        }
    }
    }
}


//Merge Helper function
//Pointer version
template <typename T>
void merge(T *a, T *aux, int lo, int mid, int hi){
    int i = lo, j = mid+1;

    for (int k = lo; k <= hi; k++){
        aux[k] = a[k];
    }
    for (int k = lo; k <= hi; k++){
        if (i > mid){
            a[k] = aux[j++];
        }
        else if(j>hi){
            a[k] = aux[i++];
        }
        else if(aux[j] < aux[i]){
            a[k] = aux[j++];
        }
        else{
            a[k] = aux[i++];
        }
        
    }

}
//Vector Version
template <typename T>
void merge(vector<T> &a, T *aux, int lo, int mid, int hi){
    int i = lo, j = mid+1;
    for (int k = lo; k <= hi; k++){
        aux[k] = a[k];
    }
    for (int k = lo; k <= hi; k++){
        if (i > mid){
            a[k] = aux[j++];
        }
        else if(j>hi){
            a[k] = aux[i++];
        }
        else if(aux[j] < aux[i]){
            a[k] = aux[j++];
        }
        else{
            a[k] = aux[i++];
        }
        
    }
}


//Instantiations

template void merge<double>(double*, double*, int, int, int);
template void merge<double>(vector<double>&, double *, int, int, int);
template void merge<string>(vector<string>&, string *, int, int, int);

template void iterative_mergesort<double>(double*, long int);
template void iterative_mergesort<double>(vector<double>&);
template void iterative_mergesort<string>(vector<string>&);

template void recursive_mergesort<double>(double*, long int);
template void recursive_mergesort<double>(vector<double>&);
template void recursive_mergesort<string>(vector<string>&);

template void sort<double>(double*, double*, int, int);
template void sort<double>(vector<double>&, double*, int, int);
template void sort<string>(vector<string>&, string*, int, int);