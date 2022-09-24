#include<iostream>
using namespace std;

void qsortRecursive(int *arr, int size) {
    //Указатели в начало и в конец массива
    int i = 0;
    int j = size - 1;

    //Центральный элемент массива
    int mid = arr[size / 2];

    //Делим массив
    do {
        //Пробегаем элементы, ищем те, которые нужно перекинуть в другую часть
        //В левой части массива пропускаем(оставляем на месте) элементы, которые меньше центрального
        while(arr[i] < mid) 
            i++;
        
        //В правой части пропускаем элементы, которые больше центрального
        while(arr[j] > mid) 
            j--;
        
        //Меняем элементы местами
        if (i <= j) {
            int t = arr[i];
            arr[i] = arr[j];
            arr[j] = t;

            i++;
            j--;
        }
    } while (i < j);

    //Рекурсивные вызовы, если осталось, что сортировать
    if(j > 0) {
        //"Левый кусок"
        qsortRecursive(arr, j + 1);
    }
    if (i < size) {
        //"Првый кусок"
        qsortRecursive(&arr[i], size - i);
    }
}

int main(){
    int arr[]={14, 25, 7, 54, 6, 100, 82};
    qsortRecursive(arr, 7);
    for(int i=0; i<7; i++)
        cout<<arr[i]<<" ";
    return 0;
}
