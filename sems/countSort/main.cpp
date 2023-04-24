#include <iostream>
#include <random>

// int maxValue30(int array[]){
//     int size0 = sizeof(array);
//     int size1 = sizeof(array[0]);
//     int arraySize = size0/size1;

//     int maxValue = array[0];

//     for (int i = 1; i != arraySize; ++i)
//         if (array[i] > maxValue)
//             maxValue = array[i];

//     return maxValue;
// }

// void doCountingSort(int array[], int maxValue){
//     int counts[maxValue];

//     for (int i = 0; i != maxValue; i++)
//         counts[i] = 0;

//     for (int i = 0; i != 30; ++i){
//         counts[array[i]] = counts[array[i]] + 1;
//     }

//     int index = 0;
//     for (int i = 0; i != maxValue; ++i){
//         for (int j = 1; j != counts[i]; ++j){
//             array[index] = i;
//             ++index;
//         }
//     }
// }

void countingSort(int array[], int arraySize, int range){
    int sortedArray[] = {0};  // creating new "sorted" 0-array
    int tempArray[range+1];  // creating new temporary array with size of initial [range + 1]

    for (int i = 0; i <= range; ++i)  // initializing temporary array of the size [range + 1] with zeroes
        tempArray[i] = 0;

    for (int i = 0; i < arraySize; ++i)  // ???
        ++tempArray[array[i]];

    for (int i = 1; i <= range; ++i)  // 
        tempArray[i] += tempArray[i-1];

    for (int i = arraySize-1; i >= 0; --i){
        sortedArray[tempArray[array[i]]-1] = array[i];
        --tempArray[array[i]];
    }

    for (int i = 0; i != arraySize; ++i){
        array[i] = sortedArray[i];
    }        
}

int main(){
    std::random_device randDevice;
    std::mt19937 mt(randDevice());
    std::uniform_int_distribution<std::mt19937::result_type> dist1K(0, 1000);

    int array[30];
    for (int i = 0; i != 30; ++i){
        array[i] = dist1K(mt);
    }

    // doCountingSort(array, maxValue30(array));
    countingSort(array, 30, 1000);

    for (int i = 0; i != 30; ++i){
        std::cout << array[i] << ", ";
    }

    return 0;
}
