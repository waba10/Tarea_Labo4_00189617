/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: HP PC
 *
 * Created on 17 de septiembre de 2019, 08:26 PM
 */

#include <cstdlib>
#include <bits/stdc++.h>
using namespace std;

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition (int arr[], int low, int high)
{
    int pivot = arr[high]; // pivote
    int i = (low - 1); // posición del primer elemento
    for (int j = low; j <= high - 1; j++)
    {
// Si el el elemento actual es menor que el pivote
        if (arr[j] < pivot)
        {
        i++; // incrementar el index del menor elemento
        swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
    /*pi es la partición del índice, arr[p] está en el lugar correcto */
    int pi = partition(arr, low, high);
    // Ordenando separadamente los elementos antes y después de la
    // partición
    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
    }
}

void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    cout << arr[i] << endl;
    
}

int missingNumber(int arr[],int size){
    int i, cont=1;
    for (i = 0; i <= size; i++){
        if(arr[i]>=(2*cont)){
            arr[i]=2*cont;
            cont++;
            
        }
    
    }
    return 2*cont;
}

/*
 * 
 */
int main(int argc, char** argv) {
    
    int t, aux=0;
    cin >> t;
    int arr[t];
    while(aux<t){
        int n;
        cin >> n;
        int A[n];
        for (int i=0;i<n;i++)
            cin >> A[i];
        quickSort(A, 0, n );
        int j, cont=1;
        for (j = 0; j < n; j++){
            if(A[j]>=(cont*2)){
                
                cont+=1;
            
            }
        }
        arr[aux]=(cont*2);
        aux+=1;
   
    } 
    printArray(arr, t);
    
    /*int arr[] = {1,3,3,3,6,7};
    //Descomenta la linea de abajo para probar con el otro arreglo
    //int arr[] = {3,0,2};
    int n = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, n - 1);
    cout << "Sorted array: \n";
    printArray(arr, n);
    int num=missingNumber(arr, n-1);
    cout << "El resultado es: "<< num ;*/
    
    


    return 0;
}

